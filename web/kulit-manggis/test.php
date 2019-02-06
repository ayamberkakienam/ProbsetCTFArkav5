<?php
  include 'flag.php';
  session_start();

  if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    extract($_POST);
    echo $_SESSION['number'];
    if($number == $_SESSION['number']){
      $correct = 1;
    }else{
      $correct = 0;
    }
  } else {
    header('Location: index.php');
  }

?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Kulit Manggis</title>

    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" rel="stylesheet">
  </head>

  <body>
    <div class="container-fluid">

      <?php if($correct): ?>
        <div class="card mt-3">
          <div class="card-header alert alert-success">
            Congrats!
          </div>
          <div class="card-body">
            Flag: <code><?php echo $flag ?></code>
          </div>
        </div>
      <?php else: ?>
        <div class="card-header alert alert-danger mt-3">
          Maaf, Anda kurang beruntung :( <br />
          Lucky number: <?php echo $_SESSION['number'] ?>
        </div>
      <?php endif; ?>

    </div>
  </body>
</html>