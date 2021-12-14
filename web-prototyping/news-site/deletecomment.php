<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <link rel = "stylesheet" href = "stylesheet.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Delete</title>
</head>
<body>
<?php

session_start();
require 'database.php';
$user = $_SESSION['user'];
$comment_id = $_POST['commentid'];

$stmt = $mysqli->prepare("SELECT COUNT(*) from comments where username = ? and comment_id = ?");
if(!$stmt){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmt->bind_param('si', $user, $comment_id);
$stmt->execute();
$stmt->bind_result($count);
$stmt->fetch();
$stmt->close();

if ($count == 0){
  echo "That comment either does not exist or was not posted by this user. You cannot delete.";
}

else {
  $statement = $mysqli->prepare("delete from comments where comment_id = ? and username=? ");
  if(!$statement){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
  } 
  $statement->bind_param('is', $comment_id, $user);
  $statement->execute();
  $statement->close();

echo "Comment Deleted!";
}

?>
    <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form>
</body>
</html>