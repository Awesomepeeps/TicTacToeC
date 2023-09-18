// Author: Nikaansh S.
// Last Editied: 9/18/23
// This is a program where you can play tic tac toe!

#include <cstring>
#include <iostream>

using namespace std;

struct gameTracker { // Structure declaration
  int board[3][3];
  int x_win; // Member (int variable)
  int o_win; // Member (int variable)
  int tie;   // Member (int variable)
};

void clearBoard(gameTracker &gameOne);
void printBoard(gameTracker &gameTwo);
bool checkWin(gameTracker &gameThree, int player);
void playGame(gameTracker &gameFour);

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;

// This is where the first game starts, and contains the code for the player
// wanting to play again or not
int main() {
  gameTracker mainGame;
  mainGame.x_win = 0;
  mainGame.o_win = 0;
  mainGame.tie = 0;
  clearBoard(mainGame);
  char yn = '\0';
  bool playAgain = true;
  while (playAgain == true) {
    cout << "This is Tic-Tac-Toe" << endl;
    playGame(mainGame);
    cout << "Play again (y or n)?" << endl;
    for (int i = 0; i < 1; i++) {
      cin >> yn;
      if (yn != 'n' && yn != 'y') {
        cout << "Was not a 'n' or a 'y'" << endl;
        i--;
      }
    }
    if (yn == 'n') {
      playAgain = false;
      cout << "Thanks for playing!" << endl;
    } else {
      playAgain = true;
    }
    clearBoard(mainGame);
  }
}

// Takes in a input by reference and clears all spaces in the board (2
// dimensional array)
void clearBoard(gameTracker &gameOne) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      gameOne.board[i][j] = BLANK;
    }
  }
}

// Goes through each space in the board and prints either a X, O, or blank based
// on what is contained
void printBoard(gameTracker &gameTwo) {
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a' + row) << '\t';
    for (int column = 0; column < 3; column++) {
      if (gameTwo.board[row][column] == BLANK) {
        cout << " \t";
      } else if (gameTwo.board[row][column] == X_MOVE) {
        cout << "X\t";
      } else if (gameTwo.board[row][column] == O_MOVE) {
        cout << "O\t";
      }
    }
    cout << endl;
  }
}

// Takes in a board and a player and goes through each possible win senario to
// check if they have won
bool checkWin(gameTracker &gameThree, int player) {
  for (int i = 0; i < 3; i++) {
    if (gameThree.board[i][0] == player && gameThree.board[i][1] == player &&
        gameThree.board[i][2] == player) {
      return true;
    }
    if (gameThree.board[0][i] == player && gameThree.board[1][i] == player &&
        gameThree.board[2][i] == player) {
      return true;
    }
  }
  if (gameThree.board[0][0] == player && gameThree.board[1][1] == player &&
      gameThree.board[2][2] == player) {
    return true;
  }
  if (gameThree.board[0][2] == player && gameThree.board[1][1] == player &&
      gameThree.board[2][0] == player) {
    return true;
  }
  return false;
}

// This contains the code the tic tac toe game
void playGame(gameTracker &gameFour) {
  printBoard(gameFour);
  bool cwin = false;
  char row = '\0';
  int column = 0;
  for (int i = 0; i < 9;
       i++) { // Goes through 9 times for the spaces on the tic tac toe grid
    cout << "Row? " << endl;
    cin >> row;
    if (row != 'a' && row != 'b' &&
        row != 'c') { // Makes sure the row was a valid input
      i--;
      cout << "Row must be an 'a', 'b', or a 'c'" << endl;
      continue;
    }
    cout << "Column? " << endl;
    cin >> column;
    if (column != 1 && column != 2 &&
        column != 3) { // Makes sure the column was a valid input
      i--;
      cout << "Column must be an 1, 2, or a 3" << endl;
      continue;
    } else {
      int rowNum = row - 97;
      if (gameFour.board[rowNum][column - 1] ==
          BLANK) {        // Makes sure space is blank
        if (i % 2 == 0) { // If X move
          cout << "x move" << endl;
          gameFour.board[rowNum][column - 1] = X_MOVE;
        } else if (i % 2 == 1) { // If O move
          gameFour.board[rowNum][column - 1] = O_MOVE;
          cout << "0 move" << O_MOVE << endl;
        }
      } else {
        cout << "There is already a move there!" << endl;
        i--;
      }
    }
    printBoard(gameFour);
    if (checkWin(gameFour, X_MOVE) == true) { // Checks X win
      cout << "X wins!" << endl;
      gameFour.x_win++;
      i = 9;
      cwin = true;
      cout << "X Wins: " << gameFour.x_win << ", O Wins: " << gameFour.o_win
           << ", Ties: " << gameFour.tie << endl;
    } else if (checkWin(gameFour, O_MOVE) == true) { // Checks O win
      cout << "O wins!" << endl;
      gameFour.o_win++;
      i = 9;
      cwin = true;
      cout << "X Wins: " << gameFour.x_win << ", O Wins: " << gameFour.o_win
           << ", Ties: " << gameFour.tie << endl;
    }
  }
  if (cwin == false) { // If all 9 iterations have passed and no one has won, it
                       // is a tie
    gameFour.tie++;
    cout << gameFour.tie << endl;
    cout << "X Wins: " << gameFour.x_win << ", O Wins: " << gameFour.o_win
         << ", Ties: " << gameFour.tie << endl;
  }
}
