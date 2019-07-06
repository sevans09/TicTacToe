#include <iostream>

using namespace std;

const int BOARD_SIZE = 3;


void playGame(string board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(string board[BOARD_SIZE][BOARD_SIZE]);
int getMove(string board[BOARD_SIZE][BOARD_SIZE], string turn);
void updateBoard(string board[BOARD_SIZE][BOARD_SIZE], int position, string turn);
bool gameOver(string board[BOARD_SIZE][BOARD_SIZE]);


int main()
{
  string board[BOARD_SIZE][BOARD_SIZE] = {{"0", "1", "2"},
					  {"3", "4", "5"},
					  {"6", "7", "8"}};

  playGame(board);
  return 0;
}

/*
 * Runs the game in a loop that continues until the game is over.
 * Input: Game board.
 */
void playGame(string board[BOARD_SIZE][BOARD_SIZE])
{
  string turn = "X";
  while(not gameOver(board))
    {
      printBoard(board);
      int position = getMove(board, turn);
      updateBoard(board, position, turn);
      
      // Below, we switch whose turn it is.
      if (turn == "X"){
	turn = "O";
      }
      else {
	turn = "X";
      }
    }

  printBoard(board);
  cout << "The game is over!" << endl;
}

/*
 * Prints tic tac toe board.
 * Should print two spaces before/after each number.
 * Input: 2d array representing board to print.
 */
void printBoard(string board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
	  for (int j = 0; j < BOARD_SIZE; j++) {
		 cout << board[i][j] << "  ";
	  }
	  cout << endl;
     }
} 


/*
 * Prompts the user for a move (int 0-9), checks if that is a valid move, and returns the move.
 *
 * A move is invalid if: (1) it is less than 0 or greater than or equal to 9,
 * or (2) if that position on the board is already taken.
 *
 * Function assumes that user does indeed provide an integer.
 *
 * Input: Game board, and string ("X" or "O") naming whose turn it is.
 * Output: Integer move (0-9) given by user. 
 */
int getMove(string board[BOARD_SIZE][BOARD_SIZE], string turn)
{
  int move;
  cout << "Enter your move (0-9) and hit enter." << endl;
  cin >> move;
  
  int i = move / 3;
  int j = move % 3;
	
  while (move > 8 || move < 0 || board[i][j] == "X" || board[i][j] == "O") {
	  cout << "Invalid move. Please try again." << endl;
	  cin >> move;
  }
  return move;
}


/*
 * Updates board with an X or O (depending on turn) in given position.
 * Inputs: Game board, position as integer, string turn (X or O).
 */
void updateBoard(string board[BOARD_SIZE][BOARD_SIZE], int position, string turn)
{
  int i = position / 3;
  int j = position % 3;

  board[i][j] = turn;
}

/*
 * Checks whether game is over,
 *  i.e., whether someone has won or the game is a draw.
 * Input: Game board.
 * Output: Boolean indicating whether game is over.
 */
bool gameOver(string board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++) {
	  if (board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X") {
		  cout << "X is the winner." << endl;
		  return true;
	  }
	  else if (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O") {
		  cout << "O is the winner." << endl;
		  return true;
	  }
   }
	
   for (int i = 0; i < BOARD_SIZE; i++) {
	  if (board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X") {
		  cout << "X is the winner." << endl;
		  return true;
	  }
	  else if (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O") {
		  cout << "O is the winner." << endl;
		  return true;
	  }
   }

   if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") {
	  cout << "X is the winner." << endl;
	  return true;	   
   }
   if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") {
	  cout << "O is the winner." << endl;
	  return true;	   
   }
   if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") {
	  cout << "X is the winner." << endl;
	  return true;	
   }
   if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O") {
	  cout << "O is the winner." << endl;
	  return true;	
   }	

   for (int i = 0; i < BOARD_SIZE; i++) {
	   for (int j = 0; j < BOARD_SIZE; j++) {
		   if (board[i][j] != "X" || board[i][j] != "O") 
			   return false;
	   }
    }
	  
  return false;
}
