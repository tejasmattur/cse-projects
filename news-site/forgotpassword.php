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
$user = $_POST['user'];

$stmt = $mysqli->prepare("SELECT security_question from users where username = '$user' ");
if(!$stmt){
  printf("Query Prep Failed: %s\n", $mysqli->error);
  exit;
}
$stmt->execute();
$stmt->bind_result($security_question);
echo "<ul>\n";
while($stmt->fetch()){ 
    printf("<br>");
    printf("%s\n", "Security Question: " . htmlspecialchars($security_question));
}
echo "</ul>\n";
$stmt->close();
?>
   <form action = "forgotpasswordtwo.php" method = post>
    <label for="user">Security Answer:</label>
    <input type = "text" id = "user" name ="user">
    </br>
    <label for="user">Confirm Username:</label>
    <input type = "text" id = "user" name ="user">
    <label for="newpassword">New Password:</label>
    <input type = "password" id = "newpassword" name ="newpassword">
    </br>
    <input type = "submit" id = "btn" value="Enter!">
    </form>
    
</body>
</html>