/// Notes: 
// Max size is 18x18 per object

// PLAYER
const pacman = {
	spawnX: 0,
	spawnY: 0,
	x: 0,
	y: 0,
	dir: "right",
	speed: 18/3,
	face: 0, //L0 D90 R180 U270
	scale: 1,
	isDying: false
}

// ROOM
var game = document.getElementById("game");
const level = [
	[ 
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
		[1, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 1], 
		[1, 1, 5, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 5, 1, 1], 
		[1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1], 
		[1, 2, 2, 1, 0, 0, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 0, 0, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 0, 0, 1, 2, 2, 1], 
		[1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0, 5, 5, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1], 
		[1, 2, 2, 1, 0, 0, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 0, 0, 0, 5, 5, 0, 0, 0, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 0, 0, 1, 2, 2, 1], 
		[1, 2, 2, 1, 0, 0, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 0, 0, 1, 2, 2, 1], 
		[1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1, 2, 2, 4, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1], 
		[1, 1, 5, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 5, 1, 1], 
		[1, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 1], 
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	],
	[
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
		[1, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 1], 
		[1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1], 
		[1, 2, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2, 2, 2, 1], 
		[1, 2, 1, 0, 1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1, 0, 0, 2, 2, 1], 
		[1, 2, 1, 0, 1, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 2, 1], 
		[1, 2, 1, 0, 1, 0, 2, 2, 2, 2, 0, 0, 2, 2, 1, 0, 0, 0, 2, 1], 
		[1, 2, 1, 0, 1, 0, 1, 2, 0, 1, 1, 0, 0, 2, 2, 0, 0, 0, 2, 1], 
		[1, 2, 1, 1, 1, 0, 1, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 2, 1], 
		[1, 2, 0, 0, 0, 0, 1, 2, 1, 2, 2, 1, 0, 2, 0, 0, 0, 0, 2, 1], 
		[1, 2, 0, 0, 0, 0, 2, 0, 1, 2, 2, 1, 2, 1, 0, 0, 0, 0, 2, 1], 
		[1, 2, 0, 0, 0, 2, 2, 0, 0, 4, 2, 0, 0, 1, 0, 1, 1, 1, 2, 1], 
		[1, 2, 0, 0, 0, 2, 2, 0, 0, 1, 1, 0, 2, 1, 0, 1, 0, 1, 2, 1], 
		[1, 2, 0, 0, 0, 1, 2, 2, 0, 0, 2, 2, 2, 2, 0, 1, 0, 1, 2, 1], 
		[1, 2, 0, 0, 0, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 1, 0, 1, 2, 1], 
		[1, 2, 2, 0, 0, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1, 0, 1, 2, 1], 
		[1, 2, 2, 2, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 2, 1], 
		[1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 1], 
		[1, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 1], 
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	],
	[
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 5, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 1, 1, 3, 1, 1, 2, 1, 1, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 1, 1, 1, 1, 1, 1, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 5, 1], 
		[1, 1, 1, 1, 2, 2, 1, 1, 1, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 1, 1, 1, 1, 1, 1, 3, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 1, 1, 1, 2, 2, 1, 1, 1, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 3, 1, 1, 1, 1, 1, 1, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 1, 1, 1, 2, 2, 1, 1, 1, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 1, 1, 1, 1, 1, 1, 3, 1], 
		[1, 2, 2, 2, 2, 4, 2, 2, 2, 1], 
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	],
	[
		[1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], 
		[1, 5, 2, 2, 2, 2, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 2, 2, 1], 
		[1, 5, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1], 
		[1, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1], 
		[1, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 4, 1], 
		[1, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1], 
		[1, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1], 
		[1, 5, 2, 2, 2, 2, 2, 1, 2, 2, 2, 3, 2, 2, 2, 1, 2, 2, 2, 1], 
		[1, 5, 2, 2, 2, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1], 
		[1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
	],
	[
		[1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1], 
		[1, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 1], 
		[1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1], 
		[1, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
		[1, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 1], 
		[1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1], 
		[1, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 1], 
		[1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1]
	]
];
var objSize = 18;
var ghosts = [];
var isStart = false;
var pendingDir = "right";
var movePacman = null;
var score = 0;
var world = level[Math.floor(Math.random()*level.length)];
var gameWidth = 0;
var gameHeight = 0;
var gameCoins = 0;

function displayWorld(){
	var output =   `<div class="displayScreen">
						<div class="score">
							<h3>SCORE: <span id="score"></span></h3>
						</div>
					</div>\n`;

	// Generate Map/Level
	for (var i = 0; i < world.length; i++){
		output += "\t<div class='row'>\n";
		for (var j = 0; j < world[i].length; j++){
			if (world[i][j] == 4) {pacman.x = j; pacman.y = i; pacman.spawnX = j; pacman.spawnY = i;}
			else if (world[i][j] == 5){
				var obj = {}
				obj.prevX= j;
				obj.prevY = i;
				obj.x = j;
				obj.y = i;
				obj.dir = "right";
				obj.speed = 18;
				obj.scale = 1;
				ghosts.push(obj);
			}
			else if (world[i][j] == 2){gameCoins++}
			else if (world[i][j] == 3){gameCoins+=20}
			output += "\t\t<div class='obj"+world[i][j]+"' id='obji"+i+"j"+j+"'></div>\n";
		}
		output += "\t</div>\n";
	}
	
	// Append the level on the game
	gameWidth = (world[0].length)-1;
	gameHeight = (world.length)-1;
	game.style.width = (world[0].length)*18+"px";
	game.style.height = ((world.length)*18)+(18*2)+"px";
	game.innerHTML = output;
}

function loadGame(){
	document.querySelector(".menu").className = "menu start";
	setTimeout(()=>{
		displayWorld();
		startGame();
		console.log(`X: ${pacman.x}, Y: ${pacman.y}`);

	}, 1000);
}

function startGame(){
	spawnPlayer();
	spawnGhosts();
}

function spawnGhosts(){
	for (var i = 0; i < ghosts.length; i++){
		var spawn = `<div id='ghost' class='ghost${i}' style='left:${ghosts[i].x*18}px; top:${ghosts[i].y*18}px;'></div>`;
		var count = 0;
		game.innerHTML += spawn;
	}

	setTimeout(()=>{
		document.querySelectorAll("#ghost").forEach((x)=>{
			var id = parseInt(x.className.replace("ghost", ""));
			var maxRadius = 5;
			var dir = "up";
			var prevDir = dir;
			var pendingDir = [];
			var isRandom = true;

			var moveGhost = setInterval(()=>{
				// IF GHOSTS TOUCH PACMAN
				if (pacman.x == ghosts[id].x && pacman.y == ghosts[id].y){
					clearInterval(moveGhost);
					pacman.isDying = true;
					console.log("called");

					document.querySelectorAll("#ghost").forEach((y)=>{
						y.remove();
					})
					document.getElementById("pacman").style.opacity = "0";
					document.getElementById("pacman").addEventListener("transitionend", ()=>{
						document.getElementById("pacman").remove();
					});

					alert("You died!");
					location.reload();
				}
				else if (!pacman.isDying){
					var left = parseInt(x.style.left.replace("px", ""));
					var top = parseInt(x.style.top.replace("px", ""));

					// CHECK RANGE FROM PLAYER
					for (var i = 0; i < maxRadius; i++){
						// Up
						if (ghosts[id].y-i%(gameHeight+1) == pacman.y && ghosts[id].x == pacman.x && world[ghosts[id].y-1][ghosts[id].x] != 1 && ghosts[id].y != 1){ // Chase 
							if (world[ghosts[id].y-i%(gameHeight+1)][ghosts[id].x] == 1) return;
							isRandom = false;
							dir = "up";
							break;
						}
						else{
							if (ghosts[id].y != 1 && world[ghosts[id].y-1][ghosts[id].x] != 1){
								isRandom = true;
								pendingDir.push("up");
							}
						}

						// Down
						if (ghosts[id].y+i%(gameHeight+1) == pacman.y && ghosts[id].x == pacman.x && world[ghosts[id].y+1][ghosts[id].x] != 1 && ghosts[id].y != gameHeight){ // Chase 
							if (world[ghosts[id].y+i%(gameHeight+1)][ghosts[id].x] == 1) return;
							isRandom = false;
							dir = "down";
							break;
						}
						else{
							if (ghosts[id].y != gameHeight && world[ghosts[id].y+1][ghosts[id].x] != 1){
								isRandom = true;
								pendingDir.push("down");
							}
						}

						// left
						if (ghosts[id].x-i%(gameWidth+1) == pacman.x && ghosts[id].y == pacman.y && world[ghosts[id].y][ghosts[id].x-1] != 1 && ghosts[id].x != 1){ // Chase 
							if (world[ghosts[id].y][ghosts[id].x-i%(gameWidth+1)] == 1) return;
							isRandom = false;
							dir = "left";
							break;
						}
						else{
							if (ghosts[id].x != 1 && world[ghosts[id].y][ghosts[id].x-1] != 1){
								isRandom = true;
								pendingDir.push("left");
							}
						}

						// Right
						if (ghosts[id].x+i%(gameWidth+1) == pacman.x && ghosts[id].y == pacman.y && world[ghosts[id].y][ghosts[id].x+1] != 1 && ghosts[id].x != gameWidth){ // Chase 
							if (world[ghosts[id].y][ghosts[id].x+i%(gameWidth+1)] == 1) break;
							isRandom = false;
							dir = "right";
							break;
						}
						else{
							if (ghosts[id].x != gameWidth && world[ghosts[id].y][ghosts[id].x+1] != 1){
								isRandom = true;
								pendingDir.push("right");
							}
						}
					}
					
					if (isRandom){
						dir = pendingDir[Math.floor(Math.random()*pendingDir.length)];
					}

					switch(dir){
						case "up":
							x.style.top = (top-ghosts[id].speed)+"px";
							ghosts[id].y -= 1;
							pendingDir = [];
							isRandom = false;
							dir = "";
						break;
						case "down":
							x.style.top = (top+ghosts[id].speed)+"px";
							ghosts[id].y += 1;
							pendingDir = [];
							isRandom = false;
							dir = "";
						break;
						case "left":
							x.style.left = (left-ghosts[id].speed)+"px";
							x.style.transform = "scaleX(-1)";
							ghosts[id].scale = -1;
							ghosts[id].x -= 1;
							pendingDir = [];
							isRandom = false;
							dir = "";
						break;
						case "right":
							x.style.left = (left+ghosts[id].speed)+"px";
							x.style.transform = "scaleX(1)";
							ghosts[id].scale = 1;
							ghosts[id].x += 1;
							pendingDir = [];
							isRandom = false;
							pendingDir = [];
							isRandom = false;
							dir = "";
						break;
					}
				}
			}, 320);
		});
	}, 100);
}

function checkCoin(){
	if (gameCoins == score){
		alert("Congrats! You won!");
		location.reload();
	}
}

function spawnPlayer(){
	pacman.isDying = false;
	var spawn = `<div id='pacman' style='left:${pacman.x*18}px; top:${pacman.y*18}px;'></div>`;
	game.innerHTML += spawn;
	var count = 0;

	var movePacman = setInterval(()=>{

		if (pacman.isDying){
			pacman.speed = 0;
			return;
		}

		var top = parseInt((document.querySelector("#pacman").style.top).replace("px", ""));
		var left = parseInt((document.querySelector("#pacman").style.left).replace("px", ""));
		count++;

		switch(pacman.dir){
			case "up":
				try{
					if(world[pacman.y-1][pacman.x] != 1){
						document.querySelector("#pacman").style.top = (top-pacman.speed)+"px";
						if (count == 3){
							pacman.y -= 1;
						}
					}
				}
				catch(err){
					pacman.y = gameHeight;
					document.querySelector("#pacman").style.top = pacman.y*18+"px";
					count = 0;
				}
			break;
			case "down":
				try{
					if(world[pacman.y+1][pacman.x] != 1){
						document.querySelector("#pacman").style.top = (top+pacman.speed)+"px";
						if (count == 3){
							pacman.y += 1;
						}
					}
				}
				catch(err){
					pacman.y = 0;
					document.querySelector("#pacman").style.top = pacman.y*18+"px";
					count = 0;
				}
			break;
			case "left":
				try{
					if(world[pacman.y][pacman.x-1] != 1){
						document.querySelector("#pacman").style.left = (left-pacman.speed)+"px";
						if (count == 3){
							pacman.x -= 1;
						}
					}
					else if (world[pacman.y][pacman.x-1] === undefined){
						throw "test";
					}
				}
				catch(err){
					pacman.x = gameWidth;
					document.querySelector("#pacman").style.left = pacman.x*18+"px";
					count = 0;
				}
			break;
			case "right":
				try{
					if(world[pacman.y][pacman.x+1] != 1){
						document.querySelector("#pacman").style.left = (left+pacman.speed)+"px";
						if (count == 3){
							pacman.x += 1;
						}
					}
					else if (world[pacman.y][pacman.x+1] === undefined){
						throw "test";
					}
				}
				catch(err){
					pacman.x = 0;
					document.querySelector("#pacman").style.left = pacman.x*18+"px";
					count = 0;
				}
			break;
		}

		if (count == 3){
			count = 0;
			updatePacman();
			pacman.dir = pendingDir;

			// Collectibles
			if (world[pacman.y][pacman.x] == 2){
				world[pacman.y][pacman.x] = 0;
				document.querySelector(`#obji${pacman.y}j${pacman.x}`).className = "obj0";
				score++;
				updateScore();
				checkCoin();
			}
			if (world[pacman.y][pacman.x] == 3){
				world[pacman.y][pacman.x] = 0;
				document.querySelector(`#obji${pacman.y}j${pacman.x}`).className = "obj0";
				score+=20;
				updateScore();
				checkCoin();
			}
		}
	}, 100);
}

function updatePacman(){
	// console.log(pacman.face, pacman.scale);
	document.getElementById("pacman").style.transform = "rotate("+pacman.face+"deg) scaleX("+pacman.scale+")";
}

function updateScore(){
	document.querySelector("#score").innerText = score;
}

// KEY EVENTS 
document.onkeydown = function (e){
	if (e.keyCode == 37 ) {
		pacman.face = 0;
		pendingDir = "left";
		pacman.scale = -1;
	}
	else if (e.keyCode == 38) {
		pacman.face = 90;
		pendingDir = "up";
		pacman.scale = -1;
	}
	else if (e.keyCode == 39) {
		pacman.face = 0;
		pendingDir = "right";
		pacman.scale = 1;
	}
	else if (e.keyCode == 40) {
		pacman.face = 90;
		pendingDir = "down";
		pacman.scale = 1;
	}

	// if (!isStart) return;
}