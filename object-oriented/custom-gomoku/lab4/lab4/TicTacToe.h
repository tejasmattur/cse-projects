#pragma once

#include "GameBase.h"

class TicTacToe : public GameBase {


public:
    TicTacToe();
    friend ostream& operator << (ostream& out, const TicTacToe& game);
    virtual vector<string> initBoard();
    virtual bool done();
    virtual bool draw();
    virtual int turn();
    virtual void print();
    virtual int initNumDig();
};