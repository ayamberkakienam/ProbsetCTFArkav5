<?php

  if (isset($_GET["debug"])) {
    highlight_file(__FILE__);
    die();
  }

  function processUpload() {
    if (!is_uploaded_file($_FILES['file']['tmp_name'])) {
      throw new Exception('Bukan file terupload');
    }

    if ($_FILES['file']['size'] > 500) {
      throw new Exception('Ukuran file tidak boleh melebihi 500 bytes');
    }

    // harusnya cuma boleh ><+-[].,
    // tapi ya sudah lah ¯\_(ツ)_/¯
    $content = file_get_contents($_FILES['file']['tmp_name']);
    if (!ctype_punct(preg_replace('/\s+/', '', $content))) {
      throw new Exception('Isi file hanya boleh ada karakter tanda baca dan whitespace');
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
      throw new Exception('Gagal upload file');
    }
    return $file;
  }

  $file = null;
  $output = null;
  $error = null;

  if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // https://github.com/dotzero/brainfuck-php/blob/master/src/Brainfuck.php
    require 'brainduck.php';
    try {
      $file = processUpload();
      $brainduck = new Brainduck(file_get_contents($file), 'Brainduck', true);
      $output = $brainduck->run(true);
    } catch (Exception $e) {
      $error = $e->getMessage();
    }
  }
?>
<!-- /?debug=V -->
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Brainduck</title>

    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">
  </head>

  <body>
    <div class="container-fluid">

<?php if($error): ?>
      <div class="alert alert-danger">
        <?php echo htmlspecialchars($error); ?>
      </div>
<?php elseif($file): ?>
      <div class="alert alert-success">
        File sukses terupload. <a href="<?php echo htmlspecialchars($file); ?>">Download</a>
      </div>
<?php endif; ?>

<?php if($output !== null): ?>
<?php if($output === ""): ?>
        <div class="card-header alert alert-danger">
          Tidak ada output atau terjadi error
        </div>
<?php else: ?>
      <div class="card mb-3">
        <div class="card-header alert alert-success">
          Output
        </div>
        <div class="card-body">
          <code><?php echo htmlspecialchars($output); ?></code>
        </div>
      </div>
<?php endif; ?>
<?php endif; ?>

      <div class="card mb-3">
        <div class="card-header">
          Upload file Brainduck
        </div>
        <div class="card-body">
          Contoh:
          <ul>
            <li><a href="examples/hello_world.bf">Hello World!</a></li>
            <li><a href="examples/squares.bf">Bilangan Kuadrat</a></li>
          </ul>
          <form method="POST" enctype="multipart/form-data">
            <input type="file" name="file" required>
            <button type="submit" class="btn btn-primary">Upload</button>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>
