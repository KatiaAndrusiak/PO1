// Tutaj należy pisać program
#ifndef bhcat_h
#define bhcat_h

#include <map>
#include <algorithm>
#include<iostream>
#include <initializer_list>
#include <functional>
#include "blackhole.h"
double operator"" _pc ( long double pc ){
    return pc*3.1e13;
}
class BHCatalogue{
  public:
    //konstruktor defoltowy , inicjalizuje std::map num
    BHCatalogue(){
        num[1]="I.";
        num[2]="II.";
        num[3]="III.";
        num[4]="IV.";
        num[5]="V.";
    }
    
    //metoda dodajaca BlackHole do catalodu, jako argument pobiera liste inacializacyjna 
    void add(std::initializer_list<BlackHole> bh){
        for(auto n: bh){
            if(i<=max_size-1)//ograniczam ilosc dziur w katolodu
            { 
                //dostaje sie do miejsca w katalogu za pomoca num i jego klucza
                catalogue[num[++i]]=n; 
            }else
            std::cout<<">> Catalogue full."<<"\""<<n.get_name()<<"\""<<" not added."<<"\n";
        }
        
    }
    
    //metoda dodajaca pojedynczy Blackhole do katalogu
     void add(const BlackHole & bh){
         if(i<=max_size-1)//ograniczam ilosc dziur w katolodu
         { 
                catalogue[num[++i]]=bh;
            }else
            std::cout<<">> Catalogue full."<<"\""<<bh.get_name()<<"\""<<" not added."<<"\n";
    }
    

    std::vector<BlackHole> get_custom(const std::function<bool(const BlackHole&)> & f ){
        std::vector<BlackHole> tmp;
        for( auto n:catalogue){
            if(f(n.second)){
                tmp.push_back(n.second);
            }
        } 
        return tmp;       
    }
    //getter zwracajacy blackhole w zaleznosci od klucza
    BlackHole get(const std::string & numb){
        return catalogue[numb];
    }
    
    //gettew zwracajcy std::map- catalogue
    std::map<std::string,BlackHole> get_map(){
        return catalogue;
    }
    
    //metoda sluzy do sortowania wzgledem masy
    std::vector<BlackHole> get_ordered_by_mass(){
        std::vector<BlackHole> vec;
        for(auto n: catalogue){
            vec.push_back(n.second);//dodaje blackhole
        }
        std::sort(vec.begin(), vec.end());
        return vec;
    }
    
  protected:
    std::map<std::string,BlackHole> catalogue;
    std::map<int, std::string> num;
    int i=0;//indeks
    int max_size=5;
};
#endif