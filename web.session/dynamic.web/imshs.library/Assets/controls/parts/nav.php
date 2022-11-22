<!-- Nav -->
	<nav class="navbar navbar-expand-md navbar-dark sticky-top bg-pink">
	  	<a class="navbar-brand d-3" href="#"><img src="Assets/img/nav/logo.svg" alt="logo" width="35px" height="35px"></img>EASY RESEARCH</a>
	  	<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar" aria-controls="navbar" aria-expanded="false" aria-label="Toggle navigation">
	    	<span class="navbar-toggler-icon"></span>
	  	</button>

	  	<div class="collapse navbar-collapse" id="navbar">
	    	<ul class="navbar-nav ml-auto text-center">
	      		<li class="nav-item">
	        		<a class="nav-link mx-3" href="#">Feedback</a>
		      	</li>
			    <li class="nav-item">
			        <a class="nav-link mx-3" href="#">About</a>
			    </li>
			    <?php
			    if (isset($_SESSION['fileID'])){
			    	echo 
			    	'<li class="nav-item">
			        	<a class="nav-link mx-3 active" href="index.php">Go Back</a>
			    	</li>';
			    }
			    ?>
	    	</ul>
	  	</div>
	</nav>