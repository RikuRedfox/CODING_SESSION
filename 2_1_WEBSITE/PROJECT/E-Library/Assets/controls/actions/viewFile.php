<?php
	require_once("../connection.php");
	session_start();

	/*
		msg1 = Find Success
		msg2 = No File Found 
	*/

	if (isset($_POST['ID'])){
		$id = $_POST['ID'];
		$selectFile = mysqli_query($con, "SELECT * FROM tb_files WHERE fileID = $id");

		if (mysqli_num_rows($selectFile) === 1){
			$_SESSION['fileID'] = $id;
			$data['msg'] = 1;
		}
		else{
			$data['msg'] = 2;
		}

	}
	echo json_encode($data);