<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<h1>
        USER PROFILE
        
</h1>
    <img src = "balconymonky.gif" alt = "something went wrong">
<h2>
        Posts
</h2>
<?php
        session_start();
        require 'database.php';
        $user = $_SESSION['user'];
        $stmt = $mysqli->prepare("SELECT post_id, link, username, brief, title from posts where username = ? order by post_id");
        if(!$stmt) {
            printf("Query Prep Failed: %s\n", $mysqli->error);
            exit;
        }
        $stmt->bind_param('s', $user);
        $stmt->execute();
        $stmt->bind_result($post_id, $link, $username, $brief, $title);
        while($stmt->fetch()){
            echo '<br><div class="title">'.htmlentities($title).'</div>';
            echo '<div class="sub">'.htmlentities("Brief: " . $brief).'</div>';
            echo '<div class="sub">'.htmlentities("Post ID: " . $post_id)." | ".htmlentities("Link: " . $link).'</div>';
        }
        $stmt->close();        
    ?>
<h2>
        Comments
</h2>
<?php
        $user = $_SESSION['user'];
        $stmt = $mysqli->prepare("SELECT post_id, comment_id, username, comment from comments where username = ? order by post_id");
        if(!$stmt) {
            printf("Query Prep Failed: %s\n", $mysqli->error);
            exit;
        }
        $stmt->bind_param('s', $user);
        $stmt->execute();
        $stmt->bind_result($post_id, $comment_id, $username, $comment);
        while($stmt->fetch()){
            echo '<br><div class="title">'.htmlentities("Comment: " . $comment).'</div>';
            echo '<div class="sub">'.htmlentities("Post ID: " . $post_id)." | ".htmlentities("Comment ID: " . $comment_id).'</div>';
        }
        $stmt->close();        
    ?>

    <br>
    <br>
    <form action = "deleteallcomments.php" method = post>
        <input type = "submit" id = "btn" value="Delete all user comments!">
        </form>
        <br>
        <br> 
        <form action = "dashboard.php" method = post>
        <input type = "submit" id = "btn" value="Return to Dashboard">
        </form> 
</body>
</html>