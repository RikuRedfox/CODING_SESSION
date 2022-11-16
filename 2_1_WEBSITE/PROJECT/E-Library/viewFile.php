<?php 
	require_once("Assets/controls/connection.php");
	session_start();

	if(!isset($_SESSION['userID']) || !isset($_SESSION['fileID'])){
		header("location: session.php");
	}

	$myID = $_SESSION['userID'];

	$fileID = $_SESSION['fileID'];
	$selectDetails = mysqli_query($con, "SELECT * FROM tb_files WHERE fileID = $fileID");
	$row = mysqli_fetch_assoc($selectDetails);
	$fileTitle = $row['fileTitle'];
	$fileName = $row['fileName'];
	$datePublished = date("Y-m-d",strtotime($row['published']));
	$userID = $row['userID'];
	$fileContributors = $row['fileContributors'];
	$str = $fileContributors;
	$arr = explode("*", $str);
	$res = "";

	for ($i = 0; $i < count($arr); $i++){
		if (count($arr) == 1){
			$res .= $arr[$i].".";
		}
		else if ($i == count($arr)-1){
			$res .= " and ".$arr[$i].".";
		}
		else $res .= $arr[$i].", ";
	}
	$Contributors = $res;


	$authID = $row['userID'];
	$selectAuthor = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $authID");
	$userRow = mysqli_fetch_assoc($selectAuthor);
	$fileAuthor = $userRow['fullname'];

	$selectUser = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $myID");
	$userPow = mysqli_fetch_assoc($selectUser)['pow'];

?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
	<title>Easy Research</title>

	<!-- Embedded CDN's -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
	<link
      rel="stylesheet"
      href="https://use.fontawesome.com/releases/v5.7.2/css/all.css"
      integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr"
      crossorigin="anonymous"
    />

	<!-- External CSS -->
	<link rel="stylesheet" type="text/css" href="Assets/css/variables.css">
	<link rel="stylesheet" type="text/css" href="Assets/css/main.css">
</head>
<body>

	<!-- Intro -->
	<div class="bg-pink intro">
		<div class="txtContainer">
			<h1 class="d-3 text-white introTxt">Easy Research</h1>
		</div>
	</div>

	<!-- Nav -->
	<?php
		include_once("Assets/controls/parts/nav.php");
	?>

	<div class="jumbotron header" style="background: transparent;">
		<div class="headerBg">
			
		</div>
		<div class="container">
			<h3 class="d-3 text-center text-white fileTitle headerTxt"><?php echo $fileTitle ?></h3>
			<p class="lead text-center text-white fileAuthor headerTxt"><?php echo $fileAuthor ?></p>
		</div>
	</div>

	<div class="container">
		<div class="fileInfo">
			<div class="myBox">
				<div class="myBoxHeader">
					<!-- Title -->
					<h2 class="d-3">Title: <span class="fileTitle"><?php echo $fileTitle ?></span></h2>
					<!-- Author -->
					<p class="lead "><b>Author:</b> <span class="fileAuthor"><?php echo $fileAuthor ?></span><br>
									<b>Contributors:</b> <span class="fileContributors"><?php echo $Contributors ?></span><br>
									<b>Published:</b> <span class="filePublished"><?php echo $datePublished ?></span></p>
				</div>
				<div class="myBoxBody">
					<!-- Actions -->
					<div class="btnGroup my-4">
						<button class="btn btn-primary download" onclick="downloadFile('<?php echo $fileName; ?>', '<?php echo $fileTitle; ?>')">Download File</button>
						<?php 
						if ($userPow == 1){ ?>
							<button class="btn btn-danger" onclick="deleteFile(<?php echo $fileID ?>)">Delete File</button>
						<?php	
						} 
						else if ($myID != $authID){ ?>
							<button class="btn btn-warning" onclick="reportFile(<?php echo $fileID ?>)">Report File</button>
						<?php
						} else {?>
							<button class="btn btn-danger" onclick="deleteFile(<?php echo $fileID ?>)">Delete File</button>
						<?php
						} ?>
					</div>

					<!-- File Viewer -->
					<div class="container my-4 w-100">
						<div class="top-bar">
					      	<button class="btn btn-primary" id="prev-page">
					        	<i class="fas fa-arrow-circle-left"></i>
					      	</button>
					      	<button class="btn btn-primary" id="next-page">
					        	<i class="fas fa-arrow-circle-right"></i>
					      	</button>
					      	<span class="page-info">
					        	Page <span id="page-num"></span> of <span id="page-count"></span>
					      	</span>
					    </div>

					    <canvas id="pdf-render"></canvas>
					</div>
				</div>
			</div>
		</div>
	</div>


<!-- Embedded CDN's -->
<!-- JQuery -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
<!-- Bootstrap -->
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
<script src="//cdn.jsdelivr.net/npm/sweetalert2@11"></script>
<script src="https://mozilla.github.io/pdf.js/build/pdf.js"></script>

<!-- External JS -->
<script type="text/javascript" src="Assets/js/main.js"></script>
<script type="text/javascript" src="Assets/js/action.js"></script>
<script type="text/javascript">
	window.onbeforeunload = function () {
	  <?php unset($_SESSION["fileID"]) ?>
	}

	pdfjsLib.GlobalWorkerOptions.workerSrc = '//mozilla.github.io/pdf.js/build/pdf.worker.js';
	var fileInfo = "<?php echo $fileName ?>";
	const url = 'Assets/Uploads/pdfFiles/'+fileInfo;
</script>
<script type="text/javascript" src="Assets/js/fileViewer.js"></script>
</body>
</html>