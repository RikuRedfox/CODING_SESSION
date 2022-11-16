<?php
	require_once("../connection.php");
	session_start();

	/*
		msg0 = Delete Success
		msg1 = File doesnt exist
		msg2 = Delete from database Failed
	*/

	if (isset($_POST['ID'])){
		$data['msg'] = "ID of the file is: ".$_POST['ID'];
		$id = $_POST['ID'];
		$selectFile = mysqli_query($con, "SELECT * FROM tb_reports WHERE fileID = $id");

		if (mysqli_num_rows($selectFile) === 1){
			if ($deleteData = mysqli_query($con, "DELETE FROM tb_reports WHERE fileID = $id")){
				$data['msg'] = 0;
			}
			else{
				$data['msg'] = 2;
			}
				
		}
		else{
			$data['msg'] = 1;
		}

	}
	echo json_encode($data);