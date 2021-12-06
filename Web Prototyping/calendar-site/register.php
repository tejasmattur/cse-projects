<?php
    header("Content-Type: application/json"); 
    $json_str = file_get_contents('php://input');
    $json_obj = json_decode($json_str, true);
    $new_user = $json_obj['new_username'];
    $new_password = $json_obj['new_password'];
    require 'database.php';
    $pwd_hash = password_hash($new_password, PASSWORD_BCRYPT);
    $statement = $mysqli->prepare("insert into users (username, password) values (?, ?)");
    if(!$statement){
      printf("Query Prep Failed: %s\n", $mysqli->error);
      exit;
    }
    $statement->bind_param('ss', $new_user, $pwd_hash);
    $statement->execute();
    $statement->close();
    echo json_encode(array(
      "success" => true,
    ));
    exit;
?>