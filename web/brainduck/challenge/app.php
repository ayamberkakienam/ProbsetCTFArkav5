<?php
  session_start();

  require 'config.php';
  ini_set('display_errors', $PROD ? 0 : 1);
  ini_set('log_errors', 1);

  set_exception_handler(function($e) {
    error_log($e->getMessage());
  });

class App {
  private static $db = null;

  private function __construct() {
  }

  private function __destruct() {
    self::$db = null;
  }

  private static function database() {
    if (self::$db === null) {
      require 'config.php';
      $dbOptions = [
        PDO::ATTR_EMULATE_PREPARES   => false,
        PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
      ];
      self::$db = new PDO($DB_ENGINE.':host='.$DB_HOST.';dbname='.$DB_NAME.';charset=utf8mb4', $DB_USER, $DB_PASS, $dbOptions);
    }
    return self::$db;
  }

  public static function redirectTo($location) {
    header("Location: $location", true, 302);
    die();
  }

  public static function refreshPage() {
    $location = $_SERVER['REQUEST_URI'];
    header("Location: $location", true, 302);
    die();
  }

  public static function notFound() {
    http_response_code(404);
    die();
  }

  public static function getLastError() {
    $error = null;
    if (isset($_SESSION['error'])) {
      $error = $_SESSION['error'];
      unset($_SESSION['error']);
    }
    return $error;
  }

  public static function getLastSuccess() {
    $success = null;
    if (isset($_SESSION['success'])) {
      $success = $_SESSION['success'];
      unset($_SESSION['success']);
    }
    return $success;
  }

  public static function register($username, $password) {
    if (!preg_match('/^[A-Za-z0-9]{6,20}$/', $username)) {
      $_SESSION['error'] = 'Username harus alfanumerik dan 6-20 karakter';
      return false;
    }

    if (!preg_match('/^.{6,}$/', $password)) {
      $_SESSION['error'] = 'Password minimal 6 karakter';
      return false;
    }

    $statement = self::database()->prepare('SELECT id FROM users WHERE username = ?');
    $statement->execute([$username]);
    if ($statement->rowCount() !== 0) {
      $_SESSION['error'] = 'Username telah terdaftar';
      return false;
    }

    $password = password_hash($password, PASSWORD_DEFAULT);
    $statement = self::database()->prepare('INSERT INTO users (username, password) VALUES (?, ?)');
    $statement->execute([$username, $password]);
    if ($statement->rowCount() !== 1) {
      $_SESSION['error'] = 'Gagal mendaftarkan akun';
      return false;
    }
    $_SESSION['success'] = 'Sukses mendaftarkan akun';
    return true;
  }

  public static function login($username, $password) {
    $statement = self::database()->prepare('SELECT id, password FROM users WHERE username = ?');
    $statement->execute([$username]);
    if ($statement->rowCount() !== 1) {
      $_SESSION['error'] = 'Username atau password salah';
      return false;
    }

    $user = $statement->fetch();
    if (!password_verify($password, $user['password'])) {
      $_SESSION['error'] = 'Username atau password salah';
      return false;
    }

    $_SESSION['user_id'] = $user['id'];
    return true;
  }

  public static function logout() {
    if (isset($_COOKIE[session_name()])) {
      setcookie(session_name(), '', time()-3600, '/');
    }
    $_SESSION = array();
    session_destroy();
  }

  public static function getUser($user_id) {
    $statement = self::database()->prepare('SELECT * FROM users WHERE id = ?');
    $statement->execute([$user_id]);
    if ($statement->rowCount() !== 1) {
      return null;
    }
    return $statement->fetch();
  }

  public static function getLoggedInUser() {
    if (!isset($_SESSION['user_id'])) {
      return null;
    }
    return self::getUser($_SESSION['user_id']);
  }

  public static function getFiles($user_id) {
    $statement = self::database()->prepare('SELECT * FROM files WHERE user_id = ?');
    $statement->execute([$user_id]);
    return $statement->fetchAll();
  }

  public static function getFile($user_id, $file_id) {
    $statement = self::database()->prepare('SELECT * FROM files WHERE id = ? AND user_id = ?');
    $statement->execute([$file_id, $user_id]);
    return $statement->fetch();
  }

  public static function addFile($user_id, $path) {
    $statement = self::database()->prepare('INSERT INTO files (user_id, path) VALUES (?, ?)');
    $statement->execute([$user_id, $path]);
    if ($statement->rowCount() !== 1) {
      $_SESSION['error'] = 'Gagal menambahkan file';
      return false;
    }
    return true;
  }

  public static function processUpload($user_id) {
    if (!is_uploaded_file($_FILES['file']['tmp_name'])) {
      $_SESSION['error'] = 'Gagal upload file';
      return false;
    }

    if ($_FILES['file']['size'] > 500) {
      $_SESSION['error'] = 'Ukuran file tidak boleh melebihi 500 bytes';
      return false;
    }

    // harusnya cuma boleh ><+-[].,
    // tapi ya sudah lah ¯\_(ツ)_/¯
    $content = file_get_contents($_FILES['file']['tmp_name']);
    if (!ctype_punct(preg_replace('/\s+/', '', $content))) {
      $_SESSION['error'] = 'Isi file hanya boleh ada karakter tanda baca dan whitespace';
      return false;
    }

    $name = $_FILES['file']['name'];
    $name = substr($name, 0, 50);
    $name = preg_replace('/[^a-zA-Z0-9_\.]/', '', $name);

    // bibit unggul dilarang ngehack
    $blacklist = array('.php', '.php3', '.php4', '.php5', '.php7');
    $name = str_ireplace($blacklist, '', $name);

    $rand = bin2hex(random_bytes(20));
    $file = "uploads/$rand-$name";
    if (!move_uploaded_file($_FILES['file']['tmp_name'], $file)) {
      $_SESSION['error'] = 'Gagal upload file';
      return false;
    }
    return self::addFile($user_id, $file);
  }
}

?>