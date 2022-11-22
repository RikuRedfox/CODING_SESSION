<?php
	require_once("../connection.php");
	session_start();

	/*
		msg['created'] = Created table col
		msg['updated'] = Updated table col
		msg1 = Delete Failed (Query for inserting datas)
		msg2 = Query No File found
		msg3 = Update Failed
	*/

	if (isset($_POST['ID']) && isset($_POST['Reason'])){
		$fileid = $_POST['ID'];
		$checkExist = mysqli_query($con, "SELECT * FROM tb_reports WHERE fileID = $fileid");

		if (mysqli_num_rows($checkExist) === 1){
			// This is for Updating
			$id = $_POST['ID'];
			$selectReport = mysqli_query($con, "SELECT * FROM tb_reports WHERE fileID = $id");

			if (mysqli_num_rows($selectReport) === 1){
				$row = mysqli_fetch_assoc($selectReport);
				$fileReason = $row['fileReason'];
				$count = $row['fileReportCount']+1;
				$time = date("Y-m-d h:i:s");
				$fileReason = $row['fileReason'];
				$thisReason = $_POST['Reason'];

				// Condition if Reason Exists
				if (str_contains($fileReason, $thisReason)){
					$newReason = $fileReason;
					$updateReport = mysqli_query($con, "UPDATE tb_reports SET fileReportCount = $count, fileTime = '$time', fileReason = '$newReason'");

					if ($updateReport){
						$data['msg'] = "updated";
					}
					else{
						$data['msg'] = 3;
					}
				}
				else{
					$newReason = $fileReason."*".$thisReason;
					$updateReport = mysqli_query($con, "UPDATE tb_reports SET fileReportCount = $count, fileTime = '$time', fileReason = '$newReason'");

					if ($updateReport){
						$data['msg'] = "updated";
					}
					else{
						$data['msg'] = 3;
					}
				}

			}
			else{
				$data['msg'] = 2;
			}
		}
		else{
			// This is for Creating another
			$id = $_POST['ID'];
			$selectFile = mysqli_query($con, "SELECT * FROM tb_files WHERE fileID = $id");

			if (mysqli_num_rows($selectFile) === 1){
				$row = mysqli_fetch_assoc($selectFile);

				$fileID = $row['fileID'];
				$fileName = $row['fileTitle'];
				$uID = $row['userID'];
				$reportCount = 1;
				$reportTime = date("Y-m-d h:i:s");
				$reason = $_POST['Reason'];

				$createReport = mysqli_query($con, "INSERT INTO tb_reports (fileID, fileName, userID, fileReportCount, fileTime, fileReason)
																	VALUES ($fileID, '$fileName', $uID, $reportCount, '$reportTime', '$reason')");
				if ($createReport){
					$data['msg'] = "created";
				}
				else{
					$data['msg'] = 1;
				}
			}
			else{
				$data['msg'] = 2;
			}
		}

			

	}
	echo json_encode($data);