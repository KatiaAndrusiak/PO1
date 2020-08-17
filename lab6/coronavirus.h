#ifndef coronavirus_h
#define coronavirus_h
#include <iostream>
#include <utility>
#include "virus.h"
class CoronaVirus: public Virus{
public:
    CoronaVirus(): Virus(), _animal(" "){}
    CoronaVirus(std::string name,std::string anname, const std::vector<Nucleotide> vect ): Virus(name), _animal(anname){
        set_RNA(vect);
    }
    CoronaVirus(CoronaVirus &vir):Virus(vir), _animal(vir._animal){}
    
    CoronaVirus(CoronaVirus &&vir):Virus(std::move(vir)), _animal(vir._animal){
        vir._animal="";
    }
    
    CoronaVirus &operator=(CoronaVirus &vir){
        (*this).Virus::operator=(vir);
        _animal=vir._animal;
        return *this;
    }
    
    CoronaVirus &operator=(CoronaVirus &&vir){
        (*this).Virus::operator=(std::move(vir));
        _animal=std::exchange(vir._animal, "");
        return *this;
    }
   std::string get_animal_host() const {
       return _animal;
   }
    
protected:
    std::string _animal;
    
};


#endif 