using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <istream>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include "GameBase.h"
#include "Gomoku.h"
#include "TicTacToe.h"
#include "Main.h"


int GameBase::prompt(unsigned int& x, unsigned int& y) {
    string in;
    bool commafound = false;
    string intakemsg = "Please input a valid coordinate of the type 'x,y' to make a move or input 'quit' to end the game";
    cout << intakemsg << endl;
    getline(cin, in);
    unsigned int num = 2 * numdig + 1;
    if (in == "quit") { //check if user inputs "quit"
        return quit;
    }
    else if (in.length() >= 3 && in.length() <= num){ //check if input length is valid (should be minimum length 3 and maximum length num)
        for (int i = 0; i < in.length(); i++) {
            if (i >= 1 && in[i] == ',' && commafound == false && i < in.length() - 1) { //check if comma is present in innput
                in[i] = ' ';
                commafound = true; 
            }
        }
        if (!commafound) { //if no comma format is ivalid
            return invalidmove; 
        }
        stringstream extract(in);
        if (extract >> x >> y) { //extract input if valid
            if (x > unsigned(0) && x < unsigned(width - 1) && y > unsigned(0) && y < unsigned(height - 1)) {
                unsigned int formula = width * y + x;

                if (board[formula] == " ") { //check inputted coordinate space is empty
                    return success; 
                }

                else { //if space is not empty, move is invalid
                    cout << "This square is already taken!" << endl;
                    return invalidmove;
                }
            }
        }
        else { //input cannot be extracted
            return invalidmove;
        }
    }
    return invalidmove;

}

int GameBase::play() {
    print(); //print game board
    bool run = true;
    string turnName;
    while (run) { //play until done() or draw() return true
        if (turn() == success) {
            if (done()) { //check is player has won
                if (whoseturn % 2 == 0) { //flipped because turn just incremented whoseturn
                    turnName = "2";
                }
                else {
                    turnName = "1";
                }
                cout << "Player " << turnName << " Won!" << endl;
                run = false;
                return success;
            }
            if (draw()) { //check if players tied
                cout << "The match was a tie!" << endl;
                cout << to_string(moveCounter) << " moves were played." << endl;
                run = false;
                return tie;
            }
        }
        else { //stop if "quit" is entered
            run = false;
            cout << "You quit." << endl;
            cout << to_string(moveCounter) << " moves were played." << endl;
            return quit;
        }
    }
    return warningcatch;

}

GameBase* GameBase::test(int n, char* c[]) {
    GameBase* g = nullptr;
    string gamename = c[gameName];

    if (n != correctNumCommands) { //ensure correct command line arguments
        if (gamename != "Gomoku") { //check if input is "Gomoku", if not return null
            return g;
        }
        else { //if input is "Gomoku", check extra arguments
            if (n == correctNumCommands + 1) { //get board size

                istringstream iss(c[n - 1]);
                unsigned int size;
                iss >> size;

                if (size < 3) { //check if invalid size

                    if (size <= 0) {
                        cout << "Size must be positive!" << endl;
                    }

                    return g;
                }
                return new Gomoku(size, 5);
            }
            if (n == correctNumCommands + 2) { //get board size and winCondition

                istringstream iss(c[n - 2]);
                unsigned int size;

                iss >> size;
                istringstream iss2(c[n - 1]);
                unsigned int winCondition;
                iss2 >> winCondition;

                if (size < 3 || winCondition > size) { //check if invalid size/winCondition
                    return g;
                }
                return new Gomoku(size, winCondition);
            }
            return g;
        }
        if (gamename != "TicTacToe") {
            return g;
        }
    }

    else if (n == correctNumCommands && gamename == "TicTacToe") { //return new TicTacToe game
        return new TicTacToe;
    }
    
    else if (n == correctNumCommands && gamename == "Gomoku") { //return new Gomoku game
        return new Gomoku;

    }
    return g;
}


