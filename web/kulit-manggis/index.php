<?php
  session_start();
  $_SESSION['number'] = rand();

  if (isset($_GET["debug"])) {
    if (isset($_GET["superdebug"])) {
      highlight_file('test.php');
    } else {
      highlight_file(__FILE__);
    }
    die();
  }

?>

<!-- ?debug=um -->
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
      <div class="card mb-3 mt-3">
        <div class="card-header">
          Kulit Manggis Lottery
        </div>
        <div class="card-body">
          Test your lucky number here!
          <form method="POST" class="form-inline mt-2" action="test.php">
            <input class="form-control mr-3" type="text" name="number" required>
            <button type="submit" class="btn btn-primary">submit</button>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>