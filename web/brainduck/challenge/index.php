<?php
  require 'app.php';

  $user = App::getLoggedInUser();
  if ($user === null) {
    App::redirectTo('/login.php');
  }

  $output = null;
  $method = $_SERVER['REQUEST_METHOD'];
  if ($method === 'GET') {
    if (isset($_GET['id'])) {
      $file = App::getFile($user['id'], $_GET['id']);
      if ($file) {
        try {
          require 'brainduck.php';
          $brainduck = new Brainduck(file_get_contents($file['path']), 'Dummy input', true);
          $output = $brainduck->run(true);
        } catch (Exception $e) {
          $output = null;
          $_SESSION['error'] = 'Error saat menjalankan brainduck';
        }
      }
    }
  } else if ($method === 'POST') {
    if (App::processUpload($user['id'])) {
      $_SESSION['success'] = 'File sukses terupload';
    };
  }

  $files = App::getFiles($user['id']);
  $error = App::getLastError();
  $success = App::getLastSuccess();
?>

<!DOCTYPE html>
<html lang="en">

  <head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Brainduck</title>

    <!-- Bootstrap core CSS-->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom fonts for this template-->
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">

    <!-- Custom styles for this template-->
    <link href="css/sb-admin.css" rel="stylesheet">

  </head>

  <body id="page-top">

    <nav class="navbar navbar-expand navbar-dark bg-dark static-top">

      <a class="navbar-brand mr-1" href="/">Brainduck</a>
      <div class="ml-auto"></div>
      <!-- Navbar -->
      <ul class="navbar-nav ml-auto ml-md-0">
        <li class="nav-item dropdown no-arrow">
          <a class="nav-link dropdown-toggle" href="#" id="userDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            <i class="fas fa-user-circle fa-fw"></i>
          </a>
          <div class="dropdown-menu dropdown-menu-right" aria-labelledby="userDropdown">
            <a class="dropdown-item" href="#" data-toggle="modal" data-target="#logoutModal">Logout</a>
          </div>
        </li>
      </ul>

    </nav>

    <div id="wrapper">

      <div id="content-wrapper">

        <div class="container-fluid">

<?php if($error): ?>
          <div class="alert alert-danger">
            <?php echo htmlspecialchars($error); ?>
          </div>
<?php elseif($success): ?>
          <div class="alert alert-success">
            <?php echo htmlspecialchars($success); ?>
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

<?php if($files): ?>
          <div class="card mb-3">
            <div class="card-header">
              Files
            </div>
            <div class="card-body">
              <div class="table-responsive">
                <table class="table table-bordered" id="dataTable" width="100%" cellspacing="0">
                  <thead>
                  <tr>
                      <th>No.</th>
                      <th>Jalankan</th>
                      <th>Download</th>
                    </tr>
                  </thead>
                  <tbody>
<?php foreach($files as $key => $file): ?>
                    <tr>
                      <td><?php echo $key+1; ?></td>
                      <td><a href="?id=<?php echo $file['id']; ?>">Jalankan</a></td>
                      <td><a href="<?php echo htmlspecialchars($file['path']); ?>">Download</a></td>
<?php endforeach; ?>
                    </tr>
                  </tbody>
                </table>
              </div>
            </div>
          </div>
<?php endif; ?>

        </div>
        <!-- /.container-fluid -->

        <!-- Sticky Footer -->
        <footer class="sticky-footer">
          <div class="container my-auto">
            <div class="copyright text-center my-auto">
              <span>Copyright © V 2018</span>
            </div>
          </div>
        </footer>

      </div>
      <!-- /.content-wrapper -->

    </div>
    <!-- /#wrapper -->

    <!-- Logout Modal-->
    <div class="modal fade" id="logoutModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
      <div class="modal-dialog" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title" id="exampleModalLabel">Logout</h5>
            <button class="close" type="button" data-dismiss="modal" aria-label="Close">
              <span aria-hidden="true">×</span>
            </button>
          </div>
          <div class="modal-body">Yakin ingin logout?</div>
          <div class="modal-footer">
            <button class="btn btn-secondary" type="button" data-dismiss="modal">Cancel</button>
            <a class="btn btn-primary" href="logout.php">Logout</a>
          </div>
        </div>
      </div>
    </div>

    <!-- Bootstrap core JavaScript-->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
  </body>

</html>
