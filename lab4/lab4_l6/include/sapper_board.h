#ifndef sapper_board_h
#define sapper_board_h
#include "board.h"
#include "sapper.h"


class SapperBoard : public Board {
public:
    SapperBoard(int x, int y, int n)
    {
        if(x<5)         param[0]=5;
        else if(x>20)   param[0]=20;
        else            param[0]=x;

        if(y<5)         param[1]=5;
        else if(y>20)   param[1]=20;
        else            param[1]=y;

        int s=param[0]*param[1];
        if(n<2)         param[2]=2;
        else if(n>s/3)  param[2]=s/3;
        else            param[2]=n;
    
    }

     int get_geometry(int k) const{
         return param[k];
     }
     double get_params(int k) const{
         return 0;
     }

private:
    int param[3];

};

#endif