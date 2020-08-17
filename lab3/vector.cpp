#include "vector.h"
#include <utility>

namespace MyStuff{

    ///konstruktor kopijacy
    vector::vector(const vector &vect): tab(new int[vect._size]), _size(vect._size){
        for(int i=0; i<vect._size; i++)
            tab[i] = vect.tab[i];
    }

////////////////////////////////////////////////////////////////////////////////////////////

    ///konstruktor przenoszacy
    vector::vector(vector&& vect): _size(std::exchange(vect._size,0)){
        std::swap(tab, vect.tab);
    }

///////////////////////////////////////////////////////////////////////////////////////////////    
    
    ///operator przypisania = kopiujacy
    vector vector::operator=(const vector& vect){
        if(this == &vect) return *this;
        
        if(tab) delete [] tab;
        
        tab = new int[vect._size];
        _size = vect._size;
        for(int i=0; i < _size; i++){
            tab[i] = vect.tab[i];
        }
        return *this;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////

    ///operator przypisania = przenoszacy
    vector vector::operator=(vector&& vect)
    {
        if(this == &vect) return *this;

        //if(tab) delete [] tab; /// nie wiem dlaczego, ale ta linijka powodowala u mnie segfault :(, stracilam na to 2 godziny :))
            
        _size=std::exchange(vect._size, 0);
        std::swap(tab, vect.tab);
        return *this;
    }

////////////////////////////////////////////////////////////////////////////////////////////////

        //operator + dowanie wektorow
        vector vector::operator+(const vector& vect)
        {
            vector temp;
            if(_size<=vect._size)
            {
                vector tmp(vect); //kopiuje wiekszy wektor 
                for(int i=0; i<_size; i++)
                    tmp[i]+=tab[i]; //uzywam oper[] zeby dostac sie do wartosci i-tego elementu
                 temp=tmp;  
            }
            else if(_size>vect._size) 
            {
                vector tmp(*this);
                for(int i=0; i<vect._size; i++)
                    tmp[i]+=vect.tab[i];
                temp=tmp;
            }
            return temp;
        }

//////////////////////////////////////////////////////////////////////////////////////////////
    
    ///operator [] pozwalający na nadanie wartości oraz odczyt i-tego elementu
     int  & vector::operator[](int i){
            return tab[i];
     }
     
//////////////////////////////////////////////////////////////////////////////////////////////////
    
      ///metoda push_back umieszczającą liczbę m na końcu wektora
      void vector::push_back(int m)
      {
         
            int *tmp=new int[_size+1];
            
            for(int i=0; i<_size; i++){
                tmp[i]=tab[i];
            }
            delete [] tab;
            tmp[_size]=m;
            _size+=1;
            tab=tmp;
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///metoda pop_back usuwającą ostatni element wektora
         void vector::pop_back()
         {
            _size = _size - 1;
            int * tmp = new int[_size];
            
            for(int i = 0; i <  _size; i++)
                tmp[i] = tab[i];
                
            delete [] tab;
            tab = tmp;
         }

//////////////////////////////////////////////////////////////////////////////////////////////////////////
  
        ///operator drukowania << , nie udalo sie mi zrobic tego poza namespace :((
      std::ostream & operator<<(std::ostream & out, const vector &vect)
      {
            for(int i=0; i<vect._size; i++)
                out<<vect.tab[i]<<" ";
            return out;  
          }
          
        }   
      
