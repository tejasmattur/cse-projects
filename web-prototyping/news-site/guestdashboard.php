<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel = "stylesheet" href = "stylesheet.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Guest Dashboard</title>
</head>
<body>

    <h1>
        NEWS SITE
    </h1> 
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
    #might need to nest a loop for subcategories of comments where post_id is lined up because
    #right now I'm not sure if it will be limited to one comment or anything about how this is going to display. Also 
    #we may want to figure out how to reconvert link into url as we cast it to string earlier.
echo "<ul>\n";
$post = null;
    while($stmt->fetch()){

        //printf("\t<li>%s %s</li>\n",
        //Fuck i really thought the "%s\n" would work... not sure how to linebreak + label each output. Plus, the post needs to post w/o
        //any comments as well (this only posts when there is a comment w the post id to match to post id.) We could trivially
        //auto comment some bullshit to fulfill that requirement. Test this theory by having multiple posts each with comments assigned.
        //I really think we need a nested loop for posts and comments queries, shouldn't be too hard. -justin
        if($post != $post_id) {
            printf("<br>");
            echo '<br><div class="title">'.htmlspecialchars($title).'</div>';
            printf("<br>");
            printf("<a href='$link'>$link</a>");
            printf("<br>");
            printf("%s\n", "Brief: " . htmlspecialchars($brief));
            printf("<br>");
            printf("%s\n", "Post ID: " . htmlspecialchars($post_id));
            printf("%s\n", "| User: ". htmlspecialchars($postuser));
            // if ($comment_id == null) {
            //     printf(htmlspecialchars($user));
            // }
            printf("<br>");
            // printf("%s\n", "Comment ID: ". htmlspecialchars($comment_id));
            // printf("%s\n", "User: ". htmlspecialchars($user));
            // printf("%s\n", "Comment: ". htmlspecialchars($comment));
            // printf("<br>");
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
}
echo "</ul>\n";
$stmt->close();
?>
 <form action = "login.html" method = get>
    <input type = "submit" id = "btn" value="Return to Login!"/>
</form>
</body>
</html>