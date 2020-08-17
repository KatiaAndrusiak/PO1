// Tutaj należy wpisać rozwiązanie
#ifndef myclass_h
#define myclass_h
#include <iostream>
#include "weapon.h"
#include "terrorist.h"

//klasa pochodna klasy Terrorist, sructur Knife araz Rifle 
class Terrorist1: public Terrorist, public Knife, public Rifle{
 public:
    //korzystam z konstruktora klasy Terrorist
    using Terrorist::Terrorist;
    
    void what() const override{
        //korzystam z metody klasy Terrorist , podaje bronie
        print(weapons({Knife::name, Rifle::name}));
    }
    void attack() const override{
        //korzystam z metod struktury Weapon , dostaje sie do nich za pomoca operatora zakresu
        Knife::cut(); 
        Rifle::shoot(); 
    }
 
    
};
//klasa pochodna klasy Terrorist, sructur Axe oraz Bomb 
class Terrorist2: public Terrorist, public Axe, public Bomb{
public:
    using Terrorist::Terrorist;
    void what() const override{
        //korzystam z metody print() klasy Terrorist , podaje bronie
        print(weapons({Axe::name, Bomb::name}));
    }
    void attack() const override{
        Axe::chop();
        Bomb::explode();
    }
};


class Safety: public Terrorist{
  public:
    Safety( Terrorist * t): ptr(t){}
    Safety( std::unique_ptr<Terrorist> & t): ptr(t.get()){}
    void what() const override{
        ptr->what();
    }
    void attack() const override{
        if(attackk)
         ptr->attack();
    }
    void apply_safety_measures(){
        attackk=false;
    }
    protected:
     Terrorist *ptr;
     bool attackk=true;
    
};


#endif