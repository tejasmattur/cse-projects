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
    require "database.php";
    $json_str = file_get_contents('php://input');
    //This will store the data into an associative array
    $json_obj = json_decode($json_str, true);
    // $token = (string) $json_obj['token'];
    // $check = (string) $_SESSION['token'];
    // if(!hash_equals($check, $token)) {
	//     die("Request forgery detected");
    // }
    $event_id = $json_obj['event_id'];
    $username = $_SESSION['username'];
    $statement = $mysqli->prepare("delete from events where username = ? and event_id = ?");
    if(!$statement){
        printf("Query Prep Failed: %s\n", $mysqli->error);
        exit;
    }
    $statement->bind_param('si', $username, $event_id);
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


    /** NOTE: NEED TO HAVE A STATEMENT THAT ALERTS USER IF NO EVENT WAS DELETED BECAUSE EVENT_ID NOT VALID 
     * THE SYSTEM ALREADY CHECKS AND WILL NOT DELETE AN EVENT ID IF USER IS NOT ASSOC WITH IT
     * BUT SHOULD TELL USER THIS
    */
    echo json_encode(array(
        "success" => true,
        "message" => "Event deleted!"
        ));
    // }

?>