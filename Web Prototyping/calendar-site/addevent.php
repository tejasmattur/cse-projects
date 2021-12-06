<?php
    ini_set("session.cookie_httponly", 1);
    session_start();
    $previous_ua = @$_SESSION['useragent'];
    $current_ua = $_SERVER['HTTP_USER_AGENT'];
    if(isset($_SESSION['useragent']) && $previous_ua !== $current_ua){
	    die("Session hijack detected");
    }
    else{
	    $_SESSION['useragent'] = $current_ua;
    }
    header("Content-Type: application/json");
    $json_str = file_get_contents('php://input');
    // $json_obj = json_decode($json_str, true);
    // $token = $json_obj['token'];
    // if(!hash_equals($_SESSION['token'], $token)) {
	//     die("Request forgery detected");
    // }
    $json_obj = json_decode($json_str, true);
    require "database.php";
    //This will store the data into an associative array
    $event_month = $json_obj['event_month'];
    $event_year = $json_obj['event_year'];
    $event_date = $json_obj['event_date'];
    $event_name = $json_obj['event_name'];
    $event_time = $json_obj['event_time'];
    $username = $_SESSION['username'];
    $share_username = $json_obj['share_username'];
    $tag = $json_obj['event_tag'];
    $statement = $mysqli->prepare("insert into events (username, event_name, event_date, event_month, event_year, event_time, event_tag) values (?, ?, ?, ?, ?, ?, ?)");
    if(!$statement){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $statement->bind_param('ssiiiis', $username, $event_name, $event_date, $event_month, $event_year, $event_time, $tag);
    $statement->execute();
    $statement->close();
    if ($share_username != "xxx") {
        $statement2 = $mysqli->prepare("insert into events (username, event_name, event_date, event_month, event_year, event_time, event_tag) values (?, ?, ?, ?, ?, ?, ?)");
    if(!$statement2){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $event_name_share = "Shared by " + $username + ": " + $event_name;
    $statement2->bind_param('ssiiiis', $share_username, $event_name_share, $event_date, $event_month, $event_year, $event_time, $tag);
    $statement2->execute();
    $statement2->close();
    }
    // if (count($event_) < 1){
    //     echo json_encode(array(
    //         "success" => false,
    //         "message" => "Events not added!"
    //     ));
    //     exit;
    // }

    // else {
    echo json_encode(array(
        "success" => true,
        "message" => "Event added!"
        ));
    // }

?>