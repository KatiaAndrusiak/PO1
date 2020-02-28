#ifndef wire_h
#define wire_h

#include<iostream>

class QuantumWire{
public:
    QuantumWire(): dlugosc(0), czastki(nullptr), liczbakw(0){}
    QuantumWire(double dlug, int liczba): dlugosc(dlug),czastki(new bool[liczba]), liczbakw(liczba) 
    {
        for(int i=0; i<liczbakw; i++)
            czastki[i]=rand()%2;
    }
    QuantumWire(const QuantumWire &wire);
    QuantumWire(QuantumWire &&wire);
    ~QuantumWire(){ if(czastki) delete [] czastki; }
    QuantumWire & operator=(const QuantumWire &wire);
    QuantumWire & operator=(QuantumWire &&wire);
    QuantumWire operator*=(double x);
    QuantumWire operator*(double x);
    QuantumWire operator!();
    operator int() const{ return liczbakw; }
    const bool &operator[](unsigned k) const;
    bool operator()(const QuantumWire &w1, const QuantumWire & w2);
    friend std::ostream & operator<<(std::ostream & out, const QuantumWire & wire);
    friend QuantumWire operator*(double x, const QuantumWire & wire);
private:
    double dlugosc;
    bool* czastki;
    int liczbakw;
};

#endif

