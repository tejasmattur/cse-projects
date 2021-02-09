<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <link rel = "stylesheet" href = "stylesheet.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>
<body>
<?php

session_start();
require 'database.php';
$user = $_SESSION['user'];
$link = (string) $_POST['postlink'];
$title = $_POST['title'];
$brief = $_POST['brief'];
$post_exists = '1';
$statement = $mysqli->prepare("insert into posts(link, title, brief, username) values (?, ?, ?, ?)");
if(!$statement){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$statement->bind_param('ssss', $link, $title, $brief, $user);
$statement->execute();
$statement->close();
echo "Post Created!"
?>
    <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form>

  
</body>
</html>