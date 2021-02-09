<?php
// Content of database.php

$mysqli = new mysqli('localhost', 'USERNAME', 'PASSWORD', 'news_site');

if($mysqli->connect_errno) {
	printf("Connection Failed: %s\n", $mysqli->connect_error);
	exit;
}
?>
