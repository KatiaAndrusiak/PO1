#include "vector.h"

namespace MyStuff{

    ///konstruktor kopijacy
    vector::vector(const vector &vect){
        tab=new int[vect._size];
        for(int i=0; i<vect._size; i++)
            tab[i]=vect.tab[i];
        _size=vect._size;
    }
    
    
    ///operator przypisania =
    vector vector::operator=(const vector& vect){
        if(this==&vect) return *this;
        
        delete [] tab;
        
        tab=new int[vect._size];
        _size=vect._size;
        for(int i=0; i<_size; i++){
            tab[i]=vect.tab[i];
        }
        return *this;
    }
    
    
    
    ///operator [] pozwalający na nadanie wartości oraz odczyt i-tego elementu
     int  & vector::operator[](int i){
            return tab[i];
     }
     
     
    
      ///metoda push_back umieszczającą liczbę m na końcu wektora
      void vector::push_back(int m){
         
            int *tmp=new int[_size+1];
            
            for(int i=0; i<_size; i++){
                tmp[i]=tab[i];
            }
            delete [] tab;
            tmp[_size]=m;
            _size+=1;
            tab=tmp;
        }
        
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
 
 
        ///operator drukowania <<
      std::ostream & operator<<(std::ostream & out, const vector &vect){
            for(int i=0; i<vect._size; i++)
                out<<vect.tab[i]<<" ";
            return out;  
          }
          
        }   
      
