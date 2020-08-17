#ifndef sapper_h
#define sapper_h
#include"game.h"
#include "board.h"
#include <iostream>
class Sapper: public Game{
public:
    Sapper(): Game() {}
    void new_board(const Board& board)
    {
        //tworzenie planszy (chyba mam pomieszane x i y :( )
        MyStuff::matrix m(board.get_geometry(0), board.get_geometry(1));
        plansza=m;
        
        //obliczenie ilosci pol bez min
        clean_fields=board.get_geometry(0)*board.get_geometry(1) - board.get_geometry(2);
        int x,y;

        //wypelnienie pola minami
        for(int i=0; i<board.get_geometry(2); i++)
        {
            x=0+rand()%board.get_geometry(1);
            y=0+rand()%board.get_geometry(0);
            if(plansza[x][y]!=-200) plansza[x][y]=-200;
            else i--;
        }

        //polam bez min przypisuje wartosc -100
        for(int i=0; i<board.get_geometry(1); i++)
        {
            for(int j=0; j<board.get_geometry(0); j++){
                if(plansza[i][j]!=-200) plansza[i][j]=-100;
            }
        }

        //obliczenie ilosci min wokol kazdego pola    
         for(int i=0; i<board.get_geometry(1); i++)
        {
            for(int j=0; j<board.get_geometry(0); j++)
            {
                if(plansza[i][j]==-100)
                {
                    if(i==0) //w przypadku gdy pole jest na brzegu
                    { 
                        if(i==0 && j==0) //w lewym rogu
                        {
                                if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j+1]==-200) plansza[i][j]+=1;
                        }
                       else if(i==0 && j==board.get_geometry(0)-1) // w prawym rogu
                        {
                            
                                if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j-1]==-200) plansza[i][j]+=1;
                            
                        }
                        else { 
                                if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j-1]==-200) plansza[i][j]+=1;
                                if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                                if(plansza[i+1][j+1]==-200) plansza[i][j]+=1;
                        }
                    }
                    else if(i==board.get_geometry(1)-1)///w przypadku gdy pole jest na dolnym brzegu
                    {
                        if(i== board.get_geometry(1)-1 && j==0){ //w lewym dolnym rogu
                                if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                                if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                                if(plansza[i-1][j+1]==-200) plansza[i][j]+=1;                      
                        }
                        else if(i== board.get_geometry(1)-1 && j==board.get_geometry(0)-1)//w prawym dolnym rogu
                        {
                                if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                                if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                                if(plansza[i-1][j-1]==-200) plansza[i][j]+=1;
                            
                        } 
                        else
                        {
                            if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                            if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                            if(plansza[i-1][j-1]==-200) plansza[i][j]+=1;
                            if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                            if(plansza[i-1][j+1]==-200) plansza[i][j]+=1;

                        }
                    }else if(j==0) ///w przypadku gdy pole jest na lewym brzegu
                    {
                        if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                        if(plansza[i-1][j+1]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j+1]==-200) plansza[i][j]+=1;
                    }else if(j==board.get_geometry(0)-1) ///w przypadku gdy pole jest na prawym brzegu
                    {
                        if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                        if(plansza[i-1][j-1]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j-1]==-200) plansza[i][j]+=1;
                    }else{ //w srodku
                        if(plansza[i-1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i][j+1]==-200) plansza[i][j]+=1;
                        if(plansza[i-1][j+1]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j+1]==-200) plansza[i][j]+=1;
                        if(plansza[i][j-1]==-200) plansza[i][j]+=1;
                        if(plansza[i-1][j-1]==-200) plansza[i][j]+=1;
                        if(plansza[i+1][j-1]==-200) plansza[i][j]+=1;
                    }    
                }   
          }
        }

    }

    void print_board()
    {
       
        for(int i=0; i<plansza.get_M(); i++){
            for(int j=0; j<plansza.get_N(); j++)
            {
                //gdy pola jest ujemne wypisz gwiazdke
                if(plansza[i][j]<0)    std::cout<<"*" <<"   ";
                //w innym przypadku wypisz zawartosc pola
                else  std::cout<<plansza[i][j]<<"   ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
        /* for(int i=0; i<plansza.get_M(); i++){
            for(int j=0; j<plansza.get_N(); j++){
                if(plansza[i][j]!=-200){
                    if(plansza[i][j]<0){
                        std::cout<<plansza[i][j]+100<<"     ";
                    }else
                    {
                        std::cout<<plansza[i][j]<<"     ";
                    }
                }
                else
                {
                    std::cout<<"*"<<"     ";
                }
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
        std::cout<<clean_fields<<"\n";
        */
    }



    bool operator()(int x, int y){
        
        if(x<plansza.get_M()&& y<plansza.get_N() && x>=0 && y>=0) //warunek dla out of range
        {
            if(plansza[x][y]!=-200 ) //warunek potrzebny dla boom!!
            {
                if(plansza[x][y]<0) //dodajemy  100 jak jest ujemne, w innym przypadku pole jest juz otwarte
                {
                    if(clean_fields!=1) //warunek sprawdza czy jeszcze nie wygralismy
                    {
                        plansza[x][y]+=100;
                        clean_fields--;
                        return true;
                    }
                    else//wygralismy!!
                    {
                        plansza[x][y]+=100; //
                        std::cout<<"Good job! You survived!"<<std::endl;
                        return false;
                    } 
                }
                else//pole juz otwarte
                { 
                    std::cout<<"is open ..."<<std::endl;
                    return true;
                }
            }
            else if(plansza[x][y]==-200) //trafilismy na mine
            {
                std::cout<<"!!!   BOOOOM    !!!"<<"\n"<<"     Game Over     "<<std:: endl;
               return false;
            }
        }
        else //wybralismy wartosc poza polem
        {
            std::cout<<"out of range..."<<std::endl;
            return true;
        }
    }



protected:
    int clean_fields; //liczba pol bez min
};


#endif