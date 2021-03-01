<?php
    header("Content-Type: application/json");
    $json_str = file_get_contents('php://input');
    $json_obj = json_decode($json_str, true);
    $username = $json_obj['username'];
    $pwd_guess = $json_obj['password'];
    require 'database.php';
    $stmt = $mysqli->prepare("SELECT COUNT(*), username, password FROM users WHERE username=?");
    if(!$stmt){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $stmt->bind_param('s', $username);
    $stmt->execute();
    $stmt->bind_result($cnt, $user, $pwd_hash);
    $stmt->fetch();
    if($cnt == 1 && password_verify($pwd_guess, $pwd_hash)){
        ini_set("session.cookie_httponly", 1);
        session_start();
        $_SESSION['username'] = $username;
        $_SESSION['token'] = bin2hex(openssl_random_pseudo_bytes(32));
        echo json_encode(array(
            "success" => true
        ));
        exit;
    } 
    else{
        echo json_encode(array(
            "success" => false,
            "message" => "Incorrect Username or Password"
        ));
        exit;
    }
?>