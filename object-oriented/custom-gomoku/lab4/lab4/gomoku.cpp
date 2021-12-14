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
#include "Gomoku.h"


Gomoku::Gomoku() { //constructor for default gomoku
    height = 21;
    width = 21;
    moveCounter = 0;
    whoseturn = 0;
    longeststring = 1;
    board = initBoard();
    wincond = 5;
    numdig = initNumDig();
}

Gomoku::Gomoku(unsigned int size, unsigned int _winCondition) { //constructor for game of variable size/win condition
    height = size + 2;
    width = size + 2;
    moveCounter = 0;
    whoseturn = 0;
    longeststring = 1;
    board = initBoard();
    wincond = _winCondition;
    numdig = initNumDig();
}


bool Gomoku::done() {
    unsigned int p1count = 0;
    unsigned int p2count = 0;
    unsigned int row = 1;
    unsigned int col = 1;
    int diagrun = 1;
    string p1name = "B";
    string p2name = "W";

    //horizontal check
    while (row <= height - 2) { // loops 3 times
        unsigned int formula = width * row + col;
        if (p1count == wincond || p2count == wincond) { 
            return true;
        }
        if (board[formula] == p1name && p2count == 0) { //increment counter and check next column
            p1count++;
            col++;
        }
        else if (board[formula] == p2name && p1count == 0) { //increment counter and check next column
            p2count++;
            col++;
        }
        else {
            p1count = 0;
            p2count = 0;
            if (board[formula] == p2name) { //increment respective player counter if sequential pieces match
                p2count++;
            }
            else if (board[formula] == p1name) { //increment respective player counter if sequential pieces match
                p1count++;
            }
            col++;
            if (col > width - wincond) { //go next row
                p1count = 0;
                p2count = 0;
                col = 1;
                row++;
            }
        }
    }
    p1count = 0;
    p2count = 0;
    col = 1;
    row = 1;
    //vertical checkf
    while (col <= width - 2) { // loops 3 times
        unsigned int formula = width * row + col;
        if (p1count == wincond || p2count == wincond) { //win condition is met
            return true;
        }
        if (board[formula] == p1name && p2count == 0) { //same as above, increment counter and check next row
            p1count++;
            row++;
        }
        else if (board[formula] == p2name && p1count == 0) {
            p2count++;
            row++;
        }
        else {
            p1count = 0;
            p2count = 0;
            if (board[formula] == p2name) { //same as above, increments respective player counters
                p2count++;
            }
            else if (board[formula] == p1name) {
                p1count++;
            }
            row++;
            if (row > height - wincond) {
                p1count = 0;
                p2count = 0;
                row = 1;
                col++;
            }
        }
    }
    p1count = 0;
    p2count = 0;
    row = 1;
    col = 1;
    unsigned int colit = 0;
    unsigned int rowit = 0;
    bool runcol = true;
    bool runrow = false;
    //diagonal check
    while (diagrun <= diagonalLim) { // loops 2 times
        unsigned int formula = width * row + col;
        if (diagrun == LRdiag) {

            if (p1count == wincond || p2count == wincond) {
                return true;
            }
            if (board[formula] == p1name && p2count == 0) { 
                p1count++;
                col++;
                row++;
            }
            else if (board[formula] == p2name && p1count == 0) {
                p2count++;
                col++;
                row++;
            }
            else {
                p1count = 0;
                p2count = 0;
                if (board[formula] == p2name) {
                    p2count++;
                }
                else if (board[formula] == p1name) {
                    p1count++;
                }
                if (runcol) { 
                    row++;
                    col++; 
                    if (col > width - wincond) { 
                        row = 1;
                        colit++;
                        col = colit;
                        p1count = 0;
                        p2count = 0;
                    }
                    if (colit > width - wincond - 2) {
                        runcol = false;
                        runrow = true;
                    }
                }
                else if (runrow) { 
                    col++;
                    row++;
                    if (row > height - wincond) {
                        p1count = 0;
                        p2count = 0;
                        col = 1;
                        rowit++;
                        row = rowit;
                    }
                    if (rowit > height - wincond - 2) {
                        runrow = false;
                    }
                }
                else if (colit > width - wincond - 2 && rowit > height - wincond - 2) {
                    row = height - 2;
                    col = 1;
                    colit = 0;
                    rowit = height - 2;
                    runcol = true;
                    runrow = false;
                    diagrun++;
                }
                else {
                    row++;
                    col++;
                }
            }
        }
        else if (diagrun == RLdiag) {

            if (p1count == wincond || p2count == wincond) {
                return true;
            }
            if (board[formula] == p1name && p2count == 0) {
                p1count++;
                col++;
                row--;
            }
            else if (board[formula] == p2name && p1count == 0) {
                p2count++;
                col++;
                row--;
            }
            else {
                p1count = 0;
                p2count = 0;
                if (board[formula] == p2name) {
                    p2count++;
                }
                else if (board[formula] == p1name) {
                    p1count++;
                }
                if (runcol) {

                    row--;
                    col++;

                    if (col > width - wincond) {
                        p1count = 0;
                        p2count = 0;
                        row = height - 2;
                        colit++;
                        col = colit;
                    }
                    if (colit > width - wincond) {
                        runcol = false;
                        runrow = true;
                        col = 1;
                        row = height - 2;
                    }
                }
                else if (runrow) {
                    row--;
                    col++;

                    if (row < wincond) {
                        p1count = 0;
                        p2count = 0;
                        col = 1;
                        rowit--;
                        row = rowit;
                    }

                    if (rowit < wincond) {
                        runrow = false;
                        //row++;
                    }

                }

                else if (colit > width - wincond && rowit < wincond) {
                    diagrun++;
                }

                else {
                    row++;
                    col++;
                }
            }
        }
    }
    return false;

}

bool Gomoku::draw() {

    unsigned int p1count = 0;
    unsigned int p2count = 0;

    unsigned int spacecount = 0;
    unsigned int row = 1;
    unsigned int col = 1;
    int diagrun = 1;
    unsigned int colit = 0;
    unsigned int rowit = 0;

    bool runcol = true;
    bool runrow = false;

    string p1name = "B";
    string p2name = "W";
    string space = " ";

    //horizontal check
    while (row <= height - 2) { // loops 3 times
        unsigned int formula = width * row + col;
        if (p1count + spacecount == wincond + 1 || p2count + spacecount == wincond + 1) {
            return false;
        }
        if (board[formula] == p1name && p2count == 0) {
            p1count++;
            col++;
        }
        else if (board[formula] == p2name && p1count == 0) {
            p2count++;
            col++;
        }
        else if (board[formula] == space) {
            spacecount++;
            col++;
        }
        else {
            p1count = 0;
            p2count = 0;
            spacecount = 0;
            if (board[formula] == p2name) {
                p2count++;
            }
            else if (board[formula] == p1name) {
                p1count++;
            }
            else if (board[formula] == space) {
                spacecount++;
            }
            col++;
            if (col >= width - wincond) {
                p1count = 0;
                p2count = 0;
                spacecount = 0;
                col = 1;
                row++;
            }
        }
    }
    p1count = 0;
    p2count = 0;
    spacecount = 0;
    col = 1;
    row = 1;
    //vertical check
    while (col <= width - 2) { // loops 3 times
        unsigned int formula = width * row + col;
        if (p1count + spacecount == wincond + 1 || p2count + spacecount == wincond + 1) {
            return false;
        }
        if (board[formula] == p1name && p2count == 0) {
            p1count++;
            row++;
        }
        else if (board[formula] == p2name && p1count == 0) {
            p2count++;
            row++;
        }
        else if (board[formula] == space) {
            spacecount++;
            row++;
        }
        else {
            p1count = 0;
            p2count = 0;
            spacecount = 0;
            if (board[formula] == p2name) {
                p2count++;
            }
            else if (board[formula] == p1name) {
                p1count++;
            }
            else if (board[formula] == space) {
                spacecount++;
            }
            row++;
            if (row >= height - wincond) {
                p1count = 0;
                p2count = 0;
                spacecount = 0;
                row = 1;
                col++;
            }
        }
    }
    p1count = 0;
    p2count = 0;
    spacecount = 0;
    row = 1;
    col = 1;
    //diagonal check
    while (diagrun <= diagonalLim) { // loops 2 times
        if (diagrun == LRdiag) {
            unsigned int formula = width * row + col;
            if (p1count + spacecount == wincond + 1 || p2count + spacecount == wincond + 1) {
                return false;
            }
            if (board[formula] == p1name && p2count == 0) {
                p1count++;
                col++;
                row++;
            }
            else if (board[formula] == p2name && p1count == 0) {
                p2count++;
                col++;
                row++;
            }
            else if (board[formula] == space) {
                spacecount++;
                col++;
                row++;
            }
            else {
                p1count = 0;
                p2count = 0;
                spacecount = 0;
                if (board[formula] == p2name) {
                    p2count++;
                }
                else if (board[formula] == p1name) {
                    p1count++;
                }
                else if (board[formula] == space) {
                    spacecount++;
                }
                if (runcol) {
                    row++;
                    col++;
                    if (col >= width - wincond) {
                        p1count = 0;
                        p2count = 0;
                        spacecount = 0;
                        row = 1;
                        colit++;
                        col = colit;
                    }
                    if (colit > width - wincond - 2) {
                        runcol = false;
                        runrow = true;
                    }
                }
                else if (runrow) {
                    col++;
                    row++;
                    if (row >= height - wincond) {
                        p1count = 0;
                        p2count = 0;
                        spacecount = 0;
                        col = 1;
                        rowit++;
                        row = rowit;
                    }
                    if (rowit > height - wincond - 2) {
                        runrow = false;
                    }
                }
                else if (colit > width - wincond - 2 && rowit > height - wincond - 2) {
                    row = height - 2;
                    col = 1;
                    colit = 0;
                    rowit = height - 2;
                    runcol = true;
                    runrow = false;
                    diagrun++;
                }
                else {
                    row++;
                    col++;
                }
            }
        }
        else if (diagrun == RLdiag) {
            unsigned int formula = width * row + col;
            if (p1count + spacecount == wincond + 1|| p2count + spacecount == wincond + 1) {
                return false;
            }
            if (board[formula] == p1name && p2count == 0) {
                p1count++;
                col++;
                row--;
            }
            else if (board[formula] == p2name && p1count == 0) {
                p2count++;
                col++;
                row--;
            }
            else if (board[formula] == space) {
                spacecount++;
                col++;
                row--;
            }
            else {
                p1count = 0;
                p2count = 0;
                spacecount = 0;
                if (board[formula] == p2name) {
                    p2count++;
                }
                else if (board[formula] == p1name) {
                    p1count++;
                }
                else if (board[formula] == space) {
                    spacecount++;
                }
                if (runcol) {
                    row--;
                    col++;
                    if (col >= width - wincond) {
                        p1count = 0;
                        p2count = 0;
                        spacecount = 0;
                        row = height - 2;
                        colit++;
                        col = colit;
                    }
                    if (colit > width - wincond) {
                        runcol = false;
                        runrow = true;
                        col = 1;
                        row = height - 2;
                    }
                }
                else if (runrow) {
                    row--;
                    col++;
                    if (row <= wincond) {
                        p1count = 0;
                        p2count = 0;
                        spacecount = 0;
                        col = 1;
                        rowit--;
                        row = rowit;
                    }
                    if (rowit < wincond) {
                        runrow = false;
                    }
                }
                else if (colit > width - wincond && rowit < wincond) {
                    diagrun++;
                }
                else {
                    row++;
                    col++;
                }
            }
        }
    }
    return true;

}

int Gomoku::turn() {

    string turnName;
    unsigned int x;
    unsigned int y;
    int promptret;

    if (whoseturn % 2 == 0) { //switch between player turns. Even is player 1 (B), odd is player 2 (W)
        turnName = "B";
    }
    else {
        turnName = "W";
    }
    cout << "It is player " << turnName << "'s turn." << endl; //print whose turn it is
    promptret = prompt(x, y); //prompt players

    while (promptret == invalidmove) { promptret = prompt(x, y); } //continue prompting if invalid input

    if (promptret == quit) { return quit; } //quit if "quit" is entered

    unsigned int formula = width * y + x;

    board[formula] = turnName; //load piece into respective board index corresponding to inputted coordinates

    longeststring = int(board[formula].length()); //update longest string

    print(); //print game board

    string xst = to_string(x);
    string yst = to_string(y);
    string add = xst + ", " + yst + "; "; //most recent move

    if (turnName == "B") {
        p1moves.append(add); //add most recent player move
        cout << "B's moves: " << p1moves << endl; //show all of player B's moves
    }
    else {
        p2moves.append(add); //add most recent player move
        cout << "W's moves: " << p2moves << endl; //show all pplayer W's moves
    }
    moveCounter++;
    whoseturn++;
    return success;
}

void Gomoku::print() { //print game board
    cout << *this;
}

vector<string> Gomoku::initBoard() { //initialize game board
    int rowprint = 1;
    int colprint = 1;
    for (unsigned int i = 0; i <= height*width; i++) { //init empty vect
        board.push_back(" ");
    }
    for (unsigned int coord = 0; coord < width - 1; coord++) { //init row/col labels
        unsigned int index = width * coord;
        board[index] = to_string(coord);
        board[coord] = to_string(coord);
    }
    return board;
}

int Gomoku::initNumDig() {
    bool runDigCount = true;
    int numdig = 1;
    int mod = 10;
    //move this later to constructor
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

//new ostream
ostream& operator << (ostream& out, const Gomoku& game) {
    
    for (int i = (game.height - 1); i >= 0; i--) { //descending rows
        for (unsigned int j = 0; j < game.width; j++) { //ascending L->R
            string h = to_string(i);
            string w = to_string(j);
            unsigned int formula = game.width * i + j;

            out << game.board[formula] << "  ";

            if (h.length() > 1 && j == 0) { //for multi-digit row labels decrease spacing to make board appearance consistent
                out << setw(game.longeststring);
            }

            else {
                unsigned int test = game.longeststring + 1;
                out << setw(test);
            }
           
        }
        out << "\n";
        out << endl; // print return at the end of cols for board spacing
    }
    return out;
}