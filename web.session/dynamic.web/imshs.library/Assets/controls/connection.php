<?php
	$db_hostname = "localhost";
	$db_username = "root";
	$db_password = "";
	$db_name = "db_easyresearch";

	$con = mysqli_connect($db_hostname, $db_username, $db_password, $db_name);

	if($con){
		$msg = "Connected";
	}
	else{
		$msg = "Problem.";
	}