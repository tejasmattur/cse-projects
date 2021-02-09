<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <link rel = "stylesheet" href = "stylesheet.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Edit</title>
</head>
<body>
<?php

session_start();
require 'database.php';
$user = $_SESSION['user'];
$post_id = $_POST['postid'];
$postedit = $_POST['postedit'];

// $comment_id = $_POST['commentid'];
// $stmt = $mysqli->prepare("SELECT username from comments where");

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

    $stmt2 = $mysqli->prepare("update posts set brief = ? where post_id = ?");
    if (!$stmt2) {
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
      }

    
    $stmt2->bind_param('si', $postedit, $post_id);
    $stmt2->execute();
    $stmt2->close();

    echo "Successful Edit!";
    }
?>
    <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form>
</body>
</html>