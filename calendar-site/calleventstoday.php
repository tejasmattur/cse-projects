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
    $month = $json_obj['event_month'];
    $year = $json_obj['event_year'];
    $date = $json_obj['event_date'];
    $username = $_SESSION['username'];
    $statement = $mysqli->prepare("select event_name, event_time, event_id, event_tag from events where event_date = ? and event_month = ? and event_year = ? and username = ?");
    $statement->bind_param('iiis', $date, $month, $year, $username);
    $statement->execute();
    $statement->bind_result($event_name, $event_time, $event_id, $event_tag);

    $event_names = array();
    $event_times = array();
    $event_ids = array();
    $event_tags = array();
    while($statement->fetch()){
        $event_names[] = htmlentities($event_name);
        $event_times[] = htmlentities($event_time);
        $event_ids[] = htmlentities($event_id);
        $event_tags[] = htmlentities($event_tag);
    }

    
    /* while($row = $result->fetch_assoc()){
        $return[] = $row['username'];
        $return[] = $row['event_name'];
        $return[] = $row['event_date'];
        $re
        $return[] = $row['event_time'];
        $return[] = $row['event_id'];
    } */
    $statement->close();

    if (count($event_ids) < 1){
        echo json_encode(array(
            "success" => false,
            "message" => "No Events!"
        ));
        exit;
    }

    else {
    echo json_encode(array(
        "success" => true,
        "event_names" => $event_names,
        "event_times" => $event_times,
        "event_ids" => $event_ids,
        "event_tags" => $event_tags,
        ));
    }
?>