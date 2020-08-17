#ifndef game_h
#define game_h
#include <iostream>
#include "matrix.h"
#include"board.h"
class Game{
public: 
    Game(): name(" "){ 
        plansza=MyStuff::matrix();
    }
    void new_player(std::string n){ name=n; }
    virtual void new_board(const Board& board)=0;
    virtual void print_board()=0;
    virtual bool operator()(int x, int y)=0;
    virtual ~Game(){}
protected:
    std::string name;
    MyStuff::matrix plansza;
    
};

#endif