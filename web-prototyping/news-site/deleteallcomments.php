<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel = "stylesheet" href = "stylesheet.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Delete all comments</title>
</head>
<body>
<?php
session_start();
require 'database.php';
$user = $_SESSION['user'];
$stmtComment = $mysqli->prepare("Delete from comments where username = ?");
if(!$stmtComment){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmtComment->bind_param('s', $user);
$stmtComment->execute();
$stmtComment->close();
echo "Comments Deleted!"
?>
        <form action = "user.php" method = post>
        <input type = "submit" id = "btn" value="Return to User Profile">
        </form>  
</body>
</html>