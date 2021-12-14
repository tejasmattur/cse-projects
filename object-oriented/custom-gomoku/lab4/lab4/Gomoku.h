#pragma once

#include "GameBase.h"
class Gomoku : public GameBase {

public:
    Gomoku();
    Gomoku(unsigned int size, unsigned int _winCondition);
    friend ostream& operator << (ostream& out, const Gomoku& game);
    virtual vector<string> initBoard();
    virtual bool done();
    virtual bool draw();
    virtual int turn();
    virtual void print();
    virtual int initNumDig();
};