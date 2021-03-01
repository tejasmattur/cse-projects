<?php

$mysqli = new mysqli('localhost', 'USERNAME', 'PASSWORD', 'calendar');

if($mysqli->connect_errno) {
	printf("Connection Failed: %s\n", $mysqli->connect_error);
	exit;
}
?>