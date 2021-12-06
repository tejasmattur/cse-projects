<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
    session_start();
    require 'database.php';
    $user = $_POST['user'];
    $password = $_POST['password'];
    $security_question = $_POST['securityquestion'];
    $security_answer = $_POST['securityanswer'];
    $pwd_hash = password_hash($password, PASSWORD_DEFAULT);
    $security_hash = password_hash($security_answer, PASSWORD_DEFAULT);
    $statement = $mysqli->prepare("insert into users (username, password, security_question, security_answer) values (?, ?, ?, ?)");
    if(!$statement){
      printf("Query Prep Failed: %s\n", $mysqli->error);
      exit;
    }
    $statement->bind_param('ssss', $user, $pwd_hash, $security_question, $security_hash);
    $statement->execute();
    $statement->close();
    echo "You have successfully registered!"
?>
    <form action = "login.html" method = post>
        <input type = "submit" id = "btn" value="Return to Login">
        </form>
    </body>
</body>
</html>
