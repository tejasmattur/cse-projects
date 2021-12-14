using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <istream>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include "TicTacToe.h"

TicTacToe::TicTacToe() { //constructor
    height = 5;
    width = 5;
    moveCounter = 0;
    whoseturn = 0;
    longeststring = 1;
    board = initBoard();
    numdig = initNumDig();
}

bool TicTacToe::done() {
    int xcount = 0;
    int ocount = 0;
    unsigned int row = 1;
    unsigned int col = 1;
    int diagrun = 1;
    //horizontal check
    while (row <= horizontalLim) { // loops 3 times
        unsigned int formula = width * row + col; 
        if (xcount == 3 || ocount == 3) { //3 in a row
            return true;
        }
        if (board[formula] == "X" && ocount == 0) { //increment xcount for each consecutive x in board
            xcount++;
            col++;
        }
        else if (board[formula] == "O" && xcount == 0) { //increment ocount for each consecutive o in board 
            ocount++;
            col++;
        }
        else {
            xcount = 0;
            ocount = 0;
            col = 1;
            row++;
        }
    }
    xcount = 0;
    ocount = 0;
    col = 1;
    row = 1;
    //vertical check
    while (col <= verticalLim) { // loops 3 times
        unsigned int formula = width * row + col;
        if (xcount == 3 || ocount == 3) { //3 in a row
            return true;
        }
        if (board[formula] == "X" && ocount == 0) {  //increment xcount for each consecutive x in board
            xcount++;
            row++;
        }
        else if (board[formula] == "O" && xcount == 0) { //increment ocount for each consecutive o in board
            ocount++;
            row++;
        }
        else {
            xcount = 0;
            ocount = 0;
            row = 1;
            col++;
        }
    }
    xcount = 0;
    ocount = 0;
    row = 1;
    col = 1;
    //diagonal check
    while (diagrun <= diagonalLim) { // loops 2 times
        unsigned int formula = width * row + col;
        if (diagrun == LRdiag) {
            if (xcount == 3 || ocount == 3) { //3 in a row
                return true;
            }
            if (board[formula] == "X" && ocount == 0) {  //increment xcount for each consecutive x in board
                xcount++;
                col++;
                row++;
            }
            else if (board[formula] == "O" && xcount == 0) {  //increment ocount for each consecutive o in board
                ocount++;
                col++;
                row++;
            }
            else {
                xcount = 0;
                ocount = 0;
                row = 3;
                col = 1;
                diagrun++;
            }
        }
        else if (diagrun == RLdiag) {
            if (xcount == 3 || ocount == 3) { //3 in a row
                return true;
            }
            if (board[formula] == "X" && ocount == 0) {  //increment xcount for each consecutive x in board
                xcount++;
                col++;
                row--;
            }
            else if (board[formula] == "O" && xcount == 0) {  //increment ocount for each consecutive o in board
                ocount++;
                col++;
                row--;
            }
            else {
                diagrun++;
            }
        }
    }
    return false;

}

bool TicTacToe::draw() { 
    if (moveCounter == 9 && !done()) { //If 9 moves have been made and nobody has won then the game is by default a draw
        return true;
    }
    return false;
}

int TicTacToe::turn() {
    string turnName;
    unsigned int x;
    unsigned int y;
    int promptret;

    if (whoseturn % 2 == 0) { //switch between player X and player O
        turnName = "X";
    }
    else {
        turnName = "O";
    }

    cout << "It is player " << turnName << "'s turn." << endl; //print which player's turn it is

    promptret = prompt(x, y); //prompt user

    while (promptret == invalidmove) { promptret = prompt(x, y); } //continue prompting until input coordinates are valid

    if (promptret == quit) { return quit; } //quit if "quit" is entered

    unsigned int formula = width * y + x;
    board[formula] = turnName;
    longeststring = int(board[formula].length()); //update longest string to longest piece in board.

    print();

    string xst = to_string(x);
    string yst = to_string(y);
    string add = xst + ", " + yst + "; "; //track player moves

    if (turnName == "X") {

        p1moves.append(add); //add most recent move
        cout << "X's moves: " << p1moves << endl; //display all of X's previous moves

    }
    else {

        p2moves.append(add); //add most recent move
        cout << "O's moves: " << p2moves << endl; //display all of O's previous moves

    }

    moveCounter++;
    whoseturn++;
    return success;

}

void TicTacToe::print() { //print game board
    cout << *this;
}

vector<string> TicTacToe::initBoard() {
    int rowprint = 1;
    int colprint = 1;
    for (unsigned int i = 0; i < height*width; i++) { //init empty vect
        board.push_back(" ");
    }

    for (unsigned int coord = 0; coord < width; coord++) { //init row/col labels
        unsigned int formula = width * int(coord);
        board[formula] = to_string(coord);
        board[coord] = to_string(coord);
    }
    return board;
}

int TicTacToe::initNumDig() {
    bool runDigCount = true;
    int numdig = 1;
    int mod = 10;
    //move this to constructor later
    while (runDigCount) {
        if (height != height % mod) {
            numdig++;
            mod = mod * 10;
        }
        else {
            runDigCount = false;
        }
    }
    return numdig;
}


ostream& operator << (ostream& out, const TicTacToe& game) {

    for (int i = (game.height - 1); i >= 0; i--) { //descending rows ERROR WITH UNSIGNED
        for (unsigned int j = 0; j < game.width; j++) { //ascending L->R
            unsigned int formula = game.width * i + j;
            unsigned int test = game.longeststring + 1;
            out << game.board[formula] << " " << setw(test);
        }
        out << "\n";
        out << endl; // print return at the end of cols for board spacing
    }
    return out;
}