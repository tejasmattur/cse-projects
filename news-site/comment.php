<!DOCTYPE html>
<html lang="en">
<head>
<link rel = "stylesheet" href = "stylesheet.css">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    

<?php

session_start();
require 'database.php';
$user = $_SESSION['user'];
$comment = $_POST['comment'];
$postid = (int) $_POST['postid'];

$stmt = $mysqli->prepare("SELECT COUNT(*) from posts where post_id = ?");
if(!$stmt){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmt->bind_param('s', $postid);
$stmt->execute();
$stmt->bind_result($count);
$stmt->fetch();
$stmt->close();

if ($count == 0){
  echo "That post does not exist. You cannot post this comment.";
}
else {
  $statement = $mysqli->prepare("insert into comments(username, comment, post_id) values (?, ?, ?)");
  if(!$statement){
    printf("Query Prep Failed: %s\n", $mysqli->error);
    exit;
  }
  $statement->bind_param('ssi', $user, $comment, $postid);
  $statement->execute();
  $statement->close();
  echo "Comment Posted!";
}

?>
    <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form>
</body>
</html>
