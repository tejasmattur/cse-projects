#pragma once
enum {
    success = 0,
    LRdiag = 1,
    RLdiag = 2,
    diagonalLim = 2,
    horizontalLim = 3,
    verticalLim = 3,
    invalidmove = 4,
    tie = 5,
    quit = 6,
    notint = 7,
    warningcatch = 8,
};

class GameBase {
protected:
    vector<string> board;
    string p1moves;
    string p2moves;
    unsigned int height;
    unsigned int width;
    unsigned int wincond;
    int moveCounter;
    int longeststring;
    int numdig;
    int whoseturn; //x will always start, x is even, y is odd, whoseturn will be determined in turn() w/ %2 

public:
    virtual bool done() = 0;
    virtual bool draw() = 0;
    virtual int turn() = 0;
    virtual int play();
    virtual void print() = 0;
    int prompt(unsigned int& x, unsigned int& y);
    static GameBase* test(int n, char* c[]);
};

