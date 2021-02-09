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
$post_id = $_POST['postid'];

$stmt = $mysqli->prepare("SELECT COUNT(*) from posts where username = ? and post_id = ?");
if(!$stmt){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmt->bind_param('si', $user, $post_id);
$stmt->execute();
$stmt->bind_result($count);
$stmt->fetch();
$stmt->close();

if ($count == 0){
  echo "That post either does not exist or was not posted by this user. You cannot delete.";
}

else {

$stmt2 = $mysqli->prepare("delete from comments where post_id = ?");

$stmt2->bind_param('i', $post_id);
$stmt2->execute();
$stmt2->close();

$stmt3 = $mysqli->prepare("delete from posts where post_id = ?");
if(!$stmt3){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmt3->bind_param('i', $post_id);
$stmt3->execute();
$stmt3->close();
echo "Post Deleted!";
}
?>
    <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form>
</body>
</html>