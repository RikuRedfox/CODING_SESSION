<?php
	require_once("../connection.php");
	session_start();

	/*
		msg0 = Delete Success
		msg1 = Query Failed Error
		msg2 = Unlink Failed
		msg3 = Delete from database Failed
	*/

	if (isset($_POST['ID'])){
		$data['msg'] = "ID of the file is: ".$_POST['ID'];
		$id = $_POST['ID'];
		$selectFile = mysqli_query($con, "SELECT * FROM tb_files WHERE fileID = $id");

		if (mysqli_num_rows($selectFile) === 1){
			$row = mysqli_fetch_assoc($selectFile);
			$fileName = $row['fileName'];
			$filePath = "../../Uploads/pdfFiles/";
			
			if ($deleteData = mysqli_query($con, "DELETE FROM tb_files WHERE fileID = $id")){
				if (unlink($filePath.$fileName)){
					$data['msg'] = 0;
				}
				else{
					$data['msg'] = 2;
				}
			}
			else{
				$data['msg'] = 3;
			}
				
		}
		else{
			$data['msg'] = 1;
		}

	}
	echo json_encode($data);