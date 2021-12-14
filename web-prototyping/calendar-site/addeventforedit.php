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
    $json_obj = json_decode($json_str, true);
    require "database.php";
    $json_str = file_get_contents('php://input');
    //This will store the data into an associative array
    $json_obj = json_decode($json_str, true);
    $event_month = $json_obj['event_month'];
    $event_year = $json_obj['event_year'];
    $event_date = $json_obj['event_date'];
    $event_name = $json_obj['event_name'];
    $event_time = $json_obj['event_time'];
    $event_id = $json_obj['event_id'];
    $username = $_SESSION['username'];
    $event_tag = $json_obj['event_tag'];
    $statement = $mysqli->prepare("insert into events (username, event_name, event_date, event_month, event_year, event_time, event_id, event_tag) values (?, ?, ?, ?, ?, ?, ?, ?)");
    if(!$statement){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $statement->bind_param('ssiiiiis', $username, $event_name, $event_date, $event_month, $event_year, $event_time, $event_id, $event_tag);
    $statement->execute();
    $statement->close();
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
        "message" => "Event edited!"
        ));
    // }

?>