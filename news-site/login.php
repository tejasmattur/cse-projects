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
    $stmt = $mysqli->prepare("SELECT COUNT(*), username, password FROM users WHERE username=?");
    if(!$stmt){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $user = $_POST['user'];
    $stmt->bind_param('s', $user);
    $stmt->execute();
    $stmt->bind_result($cnt, $username, $pwd_hash);
    $stmt->fetch();
    $pwd_guess = $_POST['password'];
    if($cnt == 1 && password_verify($pwd_guess, $pwd_hash)){
        $_SESSION['user'] = $username;
        $_SESSION['token'] = bin2hex(openssl_random_pseudo_bytes(32));
        // Redirect to your target page
        header('Location: dashboard.php');
    } 
    else{
        session_destroy();
        echo "Incorrect password! Try again.";
    }
?>
     <form action = "login.html" method = post>
        <input type = "submit" id = "btn" value="Return to Login">
        </form>
</body>
</html>