<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel = "stylesheet" href = "stylesheet.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard</title>
</head>
<body>

    <h1>
        NEWS SITE
    </h1> 

<br>
<form action = "createpost.html" method = post>
    <input type = "submit" id = "btn" value = "Create Post!"/>
    </form>

    <br>    
<form action = "comment.php" method = post>
    <label for = "postid"> Post ID: </label>
    <input type = "int" id = "postid" name = "postid" placeholder = "Post ID to comment on. Post ID can be found under title of post."/>
    <input type = "text" id = "comment" name = "comment" placeholder = "Write your comment here!"/>
    <input type = "submit" id = "btn" value = "Post comment!"/>
</form>

<form action = "editpost.php" method = post>
    <label for = "postid"> Post ID: </label>
    <input type = "int" id = "postid" name = "postid" placeholder = "Post ID to edit"/>
    <label for = "postedit"> Edit brief of post: </label>
    <input type = "text" id = "postedit" name = "postedit" placeholder = "Edit your post!"/>
    <input type = "submit" id = "btn" value = "Edit Post!"/>
    </form>

<form action = "editcomment.php" method = post>
    <label for = "commentid"> Comment ID: </label>
    <input type = "int" id = "commentid" name = "commentid" placeholder = "Comment ID"/>
    <label for = "commentedit"> Edit Comment Here: </label>
    <input type = "text" id = "commentedit" name = "commentedit" placeholder = "Edit comment here!"/>
    <input type = "submit" id = "btn" value = "Edit comment!"/>
    </form>

    
<br>
<form action = "deletepost.php" method = post> 
    <label for = "postid"> Post ID: </label>
    <input type = "int" id = "postid" name = "postid" placeholder = "Post ID to delete. Post ID can be found under title of post."/>
    <input type = "submit" id = "btn" value = "Delete Post!"/>
</form>



<form action = "deletecomment.php" method = post> 
    <label for = "commentid"> Comment ID: </label>
    <input type = "int" id = "commentid" name = "commentid" placeholder = "Comment ID to delete. Comment ID can be found under title of post."/>
    <input type = "submit" id = "btn" value = "Delete Comment!"/>
</form>


<br>
<br>
<br>

<form action = "user.php" method = post>
    <input type = "submit" id = "btn" value = "View User Profile"/>
</form>

<form action = "deleteaccountcheck.html" method = get>
    <input type = "submit" id = "btn" value = "Delete Account"/>

</form>
<?php
//display data in posts
    session_start();
    require 'database.php';
    $stmt = $mysqli->prepare("SELECT posts.username, posts.title, posts.link, posts.brief, posts.post_id, comments.comment, comments.comment_id, comments.username from posts left join comments on (posts.post_id = comments.post_id) order by posts.post_id");
    if(!$stmt){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
      }
    $stmt->execute();
    $stmt->bind_result($postuser, $title, $link, $brief, $post_id, $comment, $comment_id, $commentuser);
echo "<ul>\n";
$post = null;
    while($stmt->fetch()){

        if($post != $post_id) {
            printf("<br>");
            printf("%s\n", "Post ID: " . htmlspecialchars($post_id));
            printf("<br>");
            printf("%s\n", "Title: " . htmlspecialchars($title));
            printf("<br>");
            printf("<a href='$link'>$link</a>");
            printf("<br>");
            printf("%s\n", "Brief: " . htmlspecialchars($brief));
            printf("<br>");
            printf("%s\n", "User: ". htmlspecialchars($postuser));

            printf("<br>");
        }
        printf("<br>");
        $post = $post_id;
        if ($post = $post_id) {
            if ($comment != null) {
                printf("%s\n", "Comment: ". htmlspecialchars($comment));
                printf("<br>");
                printf("%s\n", "Comment ID: ". htmlspecialchars($comment_id));
                printf("%s\n", "| User: ". htmlspecialchars($commentuser));
            }
        }
        printf("<br>");
        printf("<br>");
        printf("<br>");
}
echo "</ul>\n";
$stmt->close();
?>

 <br> 
 <form action = "logout.php" method = get>
    <input type = "submit" id = "btn" value="Logout"/>
</form>

<img src = "groupmonky.gif" alt = "something went wrong">

</body>
</html>