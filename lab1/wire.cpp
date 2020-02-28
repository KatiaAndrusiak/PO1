#include "wire.h"
#include <utility>
#include <iostream>


QuantumWire::QuantumWire(const QuantumWire &wire)
{
    dlugosc=wire.dlugosc;
    liczbakw=wire.liczbakw;
    czastki=new bool[liczbakw];
    for(int i=0; i<liczbakw; i++){
    czastki[i]=wire.czastki[i];
    }
}


 QuantumWire::QuantumWire(QuantumWire &&wire)
 {
    dlugosc=wire.dlugosc;
    wire.dlugosc=0;
    liczbakw=wire.liczbakw;
    wire.liczbakw=0;
    czastki=std::move(wire.czastki);
    wire.czastki=nullptr;  
 }
 
 std::ostream & operator<<(std::ostream & out, const QuantumWire & wire)
 {
    out<<"length: "<<wire.dlugosc<<", quanta: ";
    for(int i=0; i<wire.liczbakw; i++){
        out<<wire.czastki[i]<<" ";
    }
    return out;
 }
 
    QuantumWire & QuantumWire::operator=(const QuantumWire &wire)
    {
        if(this==&wire) return *this;
        
        delete [] czastki;
        
        dlugosc=wire.dlugosc;
        liczbakw=wire.liczbakw;
        czastki=new bool[liczbakw];
        
        for(int i=0; i<liczbakw; i++)
            czastki[i]=wire.czastki[i];
        return *this;
    }
    
    
    
    
    QuantumWire & QuantumWire::operator=(QuantumWire &&wire)
    {
       if(this==&wire) return *this;
        
        delete [] czastki;
        
        dlugosc=wire.dlugosc;
        wire.dlugosc=0;
        liczbakw=wire.liczbakw;
        wire.liczbakw=0;
        czastki=std::move(wire.czastki);
        wire.czastki=nullptr;  
        
        return *this;
    }
    
    
    QuantumWire operator*(double x, const QuantumWire & wire)
    {
       QuantumWire tmp(wire);
       tmp.dlugosc=x*wire.dlugosc;
       return tmp;  
    }

    QuantumWire QuantumWire::operator*=(double x)
    {
        dlugosc*=x;
        return *this;
    }

     QuantumWire QuantumWire::operator*(double x)
    {
        QuantumWire tmp(*this);
        tmp.dlugosc*=x;
        return tmp;
    }


    QuantumWire QuantumWire::operator!()
    {
        QuantumWire tmp(*this);
        for(int i=0 ; i<liczbakw; i++){
            tmp.czastki[i]=!czastki[i];
        }
    return tmp;
    }

    
    const bool & QuantumWire::operator[](unsigned k) const{
        return czastki[k];
    }


    bool QuantumWire::operator()(const QuantumWire &w1, const QuantumWire & w2){
        return w1.dlugosc>w2.dlugosc;
    }

    
