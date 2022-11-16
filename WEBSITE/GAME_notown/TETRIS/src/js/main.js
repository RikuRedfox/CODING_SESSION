// Tetris Game Layout Update
var blockW, blockH;

function setEnvironment(){
	blockW = 22;
	blockH = 24;
}
document.querySelector("body").onresize = function(){
	setEnvironment();
}

// Setting Up Tetris Game
var tetris = [];
function setTetris(){
	var output = "";
	for(var i = 0; i < 20; i++){
		output += "\t<div class='row'>\n";
		tetris.push([]);
		for (var j = 0; j < 10; j++){
			output += "\t\t<div class='block'></div>\n";
			tetris[i].push(0);
		}
		output += "\t</div>\n";
	}
	document.querySelector(".area").innerHTML = output;
	isPlaying = true;
	bgm.mute = false;
	bgm.play();
}

// GAME
var bgm = new Audio("https://fi.zophar.net/soundfiles/gameboy-advance-gsf/mega-man-battle-network-2/30%20Virus%20Busting.mp3");
bgm.mute = true;
bgm.loop = true;
var isPlaying = false;
var score = 0;
var lvl = 1;
var timer = 1000; // Timer
var fallFunc;
var inputs = { // User Input
	left: false,
	up: false,
	right: false,
	down: false
}
var color = { // Colors
	0: "",
	1: "lime",
	2: "cyan",
	3: "orange",
	4: "blue",
	5: "red",
	6: "yellow",
	7: "magenta"
}

// Piece
var piece = {
	x: 4,
	y: 0,
	current: "",
	piece: Math.floor(Math.random()*blocks.length),
	next: Math.floor(Math.random()*blocks.length),
	currentRotation: 0,
	maxRotation: 0,
	update: false,
	falling: false,
	placed: true,
	inputReleased: true
}
var pieces = [];

function drawPiece(){
	// Place a piece
	if(!piece.falling){
		// Check if row is full
		for (var i = 0; i < tetris[0].length; i++){
			if (tetris[0][4] != 0 & tetris[0][5] != 0){
				isPlaying = false;
				bgm.volume = 0;
				new Audio("http://www.bndclan.com/Bend3r/Bend3r/hl-content/cstrike/sound/tetris/selection.wav").play();
				alert("Game Over!");
				location.reload();
				break;
			}
		}

		// Add Fall
		console.log("Added");
		piece.current = blocks[piece.piece][piece.currentRotation];

		// Display Next
		switch(piece.next){
			case 0: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat 0 -271px`;
				document.querySelector(".nextImg").style.width = "133px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
			case 1: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat -215px -22px`;
				document.querySelector(".nextImg").style.width = "134px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
			case 2: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat -876px -22px`;
				document.querySelector(".nextImg").style.width = "134px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
			case 3: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat -22px -22px`;
				document.querySelector(".nextImg").style.width = "89px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
			case 4: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat -231px -1012px`;
				document.querySelector(".nextImg").style.width = "138px";
				document.querySelector(".nextImg").style.transform = "scale(0.2);";
			break;
			case 5: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat 0 -490px`;
				document.querySelector(".nextImg").style.width = "133px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
			case 6: 
				document.querySelector(".nextImg").style.background = `url("./src/img/block.png") no-repeat 0 -740px`;
				document.querySelector(".nextImg").style.width = "133px";
				document.querySelector(".nextImg").style.transform = "scale(1);";
			break;
		}

		// Create pieces blocks and append // Draw blocks
		var output = "\t<div class='objPiece'>\n";
		var iterator = 0;

		for (var i = 0; i < piece.current.length; i++){
			output += "\t\t<div class='row'>\n"
			for (var j = 0; j < piece.current[i].length; j++){
				// Push Piece blocks
				pieces.push({
					x: 4+j,
					y: i,
					isBlock: (piece.current[i][j] == (piece.piece+1)) ? true : false
				});

				// Append position
				output += `\t\t\t<div class='block ${(pieces[iterator].isBlock == true) ? color[(piece.piece+1)] : '0'}' style='position: absolute; width: ${blockW}px; height: ${blockH}px; top: ${pieces[iterator].y*blockH}px; left: ${pieces[iterator].x*blockW}px;'></div>\n`;
				iterator++;
			}
			output += "\t\t</div>\n";
		}

		output += "\t</div>\n";

		document.querySelector(".obj").innerHTML = output;
		piece.maxRotation = blocks[piece.piece].length;
		piece.falling = true;
	}
	else {
		var output = "\t<div class='objPiece'>\n";
		var iterator = 0;

		for (var i = 0; i < piece.current.length; i++){
			output += "\t\t<div class='row'>\n"
			for (var j = 0; j < piece.current[i].length; j++){
				// Append position
				output += `\t\t\t<div class='block ${(pieces[iterator].isBlock == true) ? color[(piece.piece+1)] : '0'}' style='position: absolute; width: ${blockW}px; height: ${blockH}px; top: ${pieces[iterator].y*blockH}px; left: ${pieces[iterator].x*blockW}px;'></div>\n`;
				iterator++;
			}
			output += "\t\t</div>\n";
		}

		output += "\t</div>\n";

		document.querySelector(".obj").innerHTML = output;
	}
}
function fallDownPiece(){
	// Check placements
	for (var i = 0; i < pieces.length; i++){
		// Check if reached the bottom 
		if (pieces[i].y == 19 && pieces[i].isBlock){
			console.log("End");

			for (var j = 0; j < pieces.length; j++){
				if (pieces[j].isBlock){
					tetris[pieces[j].y][pieces[j].x] = piece.piece+1;
				}
			}

			pieces.length = 0;
			piece.piece = piece.next;
			piece.currentRotation = 0;
			piece.x = 4; piece.y = 0;
			piece.x = 4; piece.y = 0;
			piece.falling = false;
			clearInterval(fallFunc);
			fallFunc = setInterval(fallDownPiece, timer);
			new Audio("http://www.bndclan.com/Bend3r/Bend3r/hl-content/cstrike/sound/tetris/fall.wav").play();
			piece.next = Math.floor(Math.random()*blocks.length);

			break;
			return;
		}
		else if (pieces[i].isBlock){
			if (tetris[(pieces[i].y+1)][pieces[i].x] != 0) {
				console.log("Block");
				for (var j = 0; j < pieces.length; j++){
					if (pieces[j].isBlock){
						tetris[pieces[j].y][pieces[j].x] = piece.piece+1;
					}
				}

				pieces.length = 0;
				piece.piece = piece.next;
				piece.currentRotation = 0;
				piece.x = 4; piece.y = 0;
				piece.x = 4; piece.y = 0;
				piece.falling = false;
				clearInterval(fallFunc);
				fallFunc = setInterval(fallDownPiece, timer);
				new Audio("http://www.bndclan.com/Bend3r/Bend3r/hl-content/cstrike/sound/tetris/fall.wav").play();
				piece.next = Math.floor(Math.random()*blocks.length);

				break;
				return;
			}
		}
	}

	// Fall Down
	for (var i = 0; i < pieces.length; i++){
		pieces[i].y++;
	}

	piece.update = true;
	piece.y++;
}
function stepPiece(){
	// Fall down piece
	if (piece.placed){
		piece.placed = false;

		fallFunc = setInterval(fallDownPiece, timer);
	}

	// Move Left, Right, Rotate, Speed up
	if (inputs.left && piece.inputReleased){
		// Check for collisions
		for (var i = 0; i < pieces.length; i++){
			if (pieces[i].isBlock){
				if (pieces[i].x == 0){ return }
				if (tetris[pieces[i].y][pieces[i].x-1] != 0){ return }
			}
		}
		// Move everyone
		for (var i = 0; i < pieces.length; i++){
			pieces[i].x--;
		}
		piece.x--;
		piece.update = true;
		piece.inputReleased = false;
	}
	else if (inputs.right && piece.inputReleased){
		// Check for collisions
		for (var i = 0; i < pieces.length; i++){
			if (pieces[i].isBlock){
				if (pieces[i].x == 9){ return }
				if (tetris[pieces[i].y][pieces[i].x+1] != 0){ return }
			}
		}
		// Move everyone
		for (var i = 0; i < pieces.length; i++){
			pieces[i].x++;
		}
		piece.x++;
		piece.update = true;
		piece.inputReleased = false;
	}
	else if (inputs.up && piece.inputReleased){
		piece.currentRotation = (piece.currentRotation+1) % piece.maxRotation;
		piece.current = blocks[piece.piece][piece.currentRotation];
		pieces.length = 0;

		// Create pieces blocks and append // Draw blocks
		var output = "\t<div class='objPiece'>\n";
		var iterator = 0;

		for (var i = 0; i < piece.current.length; i++){
			output += "\t\t<div class='row'>\n"
			for (var j = 0; j < piece.current[i].length; j++){
				// Push Piece blocks
				pieces.push({
					x: piece.x+j,
					y: (piece.y+i),
					isBlock: (piece.current[i][j] == (piece.piece+1)) ? true : false
				});

				// Append position
				output += `\t\t\t<div class='block ${(pieces[iterator].isBlock == true) ? color[(piece.piece+1)] : '0'}' style='position: absolute; width: ${blockW}px; height: ${blockH}px; top: ${pieces[iterator].y*blockH}px; left: ${pieces[iterator].x*blockW}px;'></div>\n`;
				iterator++;
			}
			output += "\t\t</div>\n";
		}

		output += "\t</div>\n";
		document.querySelector(".obj").innerHTML = output;
		piece.inputReleased = false;
	}
	else if (inputs.down && piece.inputReleased){
		// Fall Down
		piece.inputReleased = false;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, 150);
	}
	else if (inputs.space && piece.inputReleased){
		piece.inputReleased = false;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, 0);
	}
}

function updatePiece(){
	drawPiece();
	stepPiece();
}

function checkScore(){
	if (score >= 10000 && lvl != 4){
		// lvl 4
		lvl = 4;
		document.querySelector(".spdLvl").innerText = "4";
		timer = 50;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, timer);
	}
	else if (score >= 5000 && score < 10000 && lvl != 3){
		// lvl 3
		lvl = 3;
		document.querySelector(".spdLvl").innerText = "3";
		timer = 100;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, timer);
	}
	else if (score >= 1000 && score < 5000 && lvl != 2){
		// lvl 2
		lvl = 2;
		document.querySelector(".spdLvl").innerText = "2";
		timer = 400;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, timer);
	}
}

function updateTetris(){
	var output = "";
	for (var i = 0; i < tetris.length; i++){
		output += "\t<div class='row'>";
		for (var j = 0; j < tetris[i].length; j++){
			output += `\t\t<div class='block ${color[tetris[i][j]]}'></div>`;
		}
		output += "\t</div>";
	}
	document.querySelector(".area").innerHTML = output;
}


function checkTetris(){
	// Check if piece is out of bounds
	for (var i = 0; i < pieces.length; i++){
		// left
		if (pieces[i].x < 0 && pieces[i].isBlock){
			for (var j = 0; j < pieces.length; j++){
				pieces[j].x++;
			}
			piece.update = true;
			break;
		}
		// right
		if (pieces[i].x > 9 && pieces[i].isBlock){
			for (var j = 0; j < pieces.length; j++){
				pieces[j].x--;
			}
			break;
			piece.update = true;
		}
	}

	// Check for rows if a row is filled
	var counter = 0;
	for (var i = tetris.length-1; i > 0; i--){
		counter = 0;
		for (var j = 0; j < tetris[i].length; j++){
			if (tetris[i][j] == 0) { break; }
			else {counter++}

			if (counter == 10){
				tetris[i] = tetris[tetris.length-1];
				tetris.pop();
				tetris.unshift([0,0,0,0,0,0,0,0,0,0]);
				score += 100;
				document.querySelector(".score").innerText = score;
				new Audio("http://www.bndclan.com/Bend3r/Bend3r/hl-content/cstrike/sound/tetris/line.wav").play();
			}
		}
	}
}

function gameLoop(){
	updateTetris();

	if (isPlaying){
		setEnvironment();
		updatePiece();
		checkTetris();
		checkScore();
	}
}
setInterval(gameLoop, 20);

// Inputs
document.onkeydown = function(e){
	if (e.keyCode == 37){ // left
		inputs.left = true;
	}
	else if (e.keyCode == 38){ // up
		inputs.up = true;
	}
	else if (e.keyCode == 39){ // right
		inputs.right = true;
	}
	else if (e.keyCode == 40){ // down
		inputs.down = true;
	}
	else if (e.keyCode == 32){ // Space
		inputs.space = true;
	}
}
document.onkeyup = function(e){
	if (e.keyCode == 37){ // left
		inputs.left = false;
		piece.inputReleased = true;
	}
	else if (e.keyCode == 38){ // up
		inputs.up = false;
		piece.inputReleased = true;
	}
	else if (e.keyCode == 39){ // right
		inputs.right = false;
		piece.inputReleased = true;
	}
	else if (e.keyCode == 40){ // down
		inputs.down = false;
		piece.inputReleased = true;
		clearInterval(fallFunc);
		fallFunc = setInterval(fallDownPiece, timer);
	}
	else if (e.keyCode == 32){ // Space
		inputs.space = false;
		piece.inputReleased = true;
	}
}