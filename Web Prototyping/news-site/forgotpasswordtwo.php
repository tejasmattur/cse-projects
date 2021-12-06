<?php
session_start();
require 'database.php';
$security_answer = $_POST['security_answer'];
$user = $_POST['user'];
$newpassword = $_POST['newpassword'];

$stmt = $mysqli->prepare("SELECT security_answer from users where username = '$user' ");


if(password_verify($security_answer, $security_hash)){
    $_SESSION['user'] = $username;
    $_SESSION['token'] = bin2hex(openssl_random_pseudo_bytes(32));
    // Redirect to your target page
    header('Location: dashboard.php');
} 



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
