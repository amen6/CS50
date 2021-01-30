var origBoard;
const player1 = 'O' ;
const player2 = 'X' ;
isPlayer1Turn = true
var player1Score = 0;
var player2Score = 0;
const winCombos = [
[0, 1, 2],
[3, 4, 5],
[6, 7, 8],
[0, 3, 6],
[1, 4, 7],
[2, 5, 8],
[0, 4, 8],
[6, 4, 2]
]
const cells = document.querySelectorAll('.cell');
startGame();
function startGame() {
	document.querySelector('.endgame').style.display = 'none' 
origBoard = Array.from(Array(9).keys());
for (var i = 0; i <cells.length; i++ ){
cells[i].innerText = '' ;
cells[i].style.removeProperty('background-color');
cells[i].addEventListener('click', turnClick, false);
 }
}

function turnClick(square) {
	if (typeof origBoard[square.target.id] == 'number') {
		let current_player = (isPlayer1Turn) ? player1 : player2
		turn(square.target.id, current_player)
		isPlayer1Turn = !isPlayer1Turn
	}
}

function turn(squareId, player) {
	origBoard[squareId] = player;
	document.getElementById(squareId).innerText = player;
	let gameWon = checkWin(origBoard, player)
	if (gameWon) gameOver(gameWon) 
	else checkTie()
}
function checkWin (board, player) { 
	let plays = board.reduce((a, e, i) =>
	(e === player) ? a.concat(i) : a, [] );
	let gameWon = null;
	for (let [index, win] of winCombos.entries()) {
		if (win.every(elem => plays.indexOf(elem) > -1)) {
			gameWon = {index: index, player: player};
			break;
		}

	}
	return gameWon; 
}

function gameOver(gameWon) {
	for (let index of winCombos [gameWon.index]) {
		document.getElementById(index).style.backgroundColor=
		gameWon.player == player1 ? "blue" : "red"; /*ternary operator*/
	}
	for (var i = 0; i < cells.length; i++) {
		cells[i].removeEventListener('click', turnClick, false)
	}
	declareWinner(gameWon.player == player1 ? "Player 1 Win!" : "Player 2 Win!") 
}

function declareWinner(who) {
	document.querySelector(".endgame").style.display = "block";
	document.querySelector(".endgame .text").innerText = who;

}

function emptySquares() {
	return origBoard.filter(s => typeof s == 'number')
}


function checkTie() {
	if(emptySquares().length === 0) {
		for (var i =0; i < cells.length; i++) {
		cells[i].style.backgroundColor = "green";
		cells[i].removeEventListener('click', turnClick, false);		
		}
		declareWinner("Tie Game")
		return true;
	}
	return false;
}
