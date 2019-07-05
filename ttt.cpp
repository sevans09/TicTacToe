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
  // STUB
  // Put code which prints board here.
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
  // STUB
  // Remove the line below, then implement this function.
  return 0;
}


/*
 * Updates board with an X or O (depending on turn) in given position.
 * Inputs: Game board, position as integer, string turn (X or O).
 */
void updateBoard(string board[BOARD_SIZE][BOARD_SIZE], int position, string turn)
{
  // STUB
  // You must implement this function
}

/*
 * Checks whether game is over,
 *  i.e., whether someone has won or the game is a draw.
 * Input: Game board.
 * Output: Boolean indicating whether game is over.
 */
bool gameOver(string board[BOARD_SIZE][BOARD_SIZE])
{
  // STUB
  // Remove the line below, then implement this function.
  return false;
}
