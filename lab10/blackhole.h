#ifndef blackhole_h
#define blackhole_h
#include <iostream>
#include <string>

const double G= 6.67e-11;
const double M=2e+30;
const double c=3e+8;

class BlackHole{
  public:
    //konstruktor domniemany
    BlackHole(){};
    //konstruktor inicializujacy
    BlackHole(std::string nm, double ms, double dis): name(nm), masa(ms), dist(dis), Rh((2*G*M*masa)/(1000*c*c)){}
    
    //operator wypisywania dla BlackHole
    friend std::ostream & operator<<(std::ostream & out, const BlackHole & bh){
        out<<bh.name<<" : M="<<bh.masa<<" solar mass,  Rh="<<bh.Rh<<" km, dist="<<bh.dist<<" pc"<<"\n";
        return out;
    }
    //getter dla name
    std::string get_name() const{
        return name;
    }
    //getter dla masy
     double get_mass() const{
        return masa;
    }

    double get_Rh() const{
      return Rh;
    }
    
    //operator porownania(dla sort)
    friend bool operator<(const BlackHole &bh1, const BlackHole &bh2){
        return bh1.get_mass()< bh2.get_mass();
    }
    
  protected:
    std::string name;
    double masa;
    double dist;
    double Rh;
    
};

#endif
/* *** Spodziewane wyjście ***

Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
>> Catalogue full. "Gargantua" not added. 
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc

GRO J1655-40 : M=5.31 solar mass, Rh=15.7412 km, dist=3700 pc
V404 Cygni : M=9 solar mass, Rh=26.68 km, dist=2390 pc
Cygnus X-1 : M=15 solar mass, Rh=44.4667 km, dist=1900 pc
Sagittarius A* : M=4.1e+06 solar mass, Rh=1.21542e+07 km, dist=8178 pc
M87* : M=6.5e+09 solar mass, Rh=1.92689e+10 km, dist=1.64e+09 pc

*/