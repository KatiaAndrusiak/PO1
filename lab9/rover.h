#ifndef rover_h
#define rover_h
#include <iostream>
#include <functional>
#include "utils.h"
const double PI=3.14;
const double R_M=3396200;

double operator"" _km ( long double km ){
    double distance = km*1000;
    return (distance / R_M) * (180/PI);
}

typedef std::vector<double> vec;

typedef std::vector< std::function< std::vector<double>() > > Program;

namespace MarsRoutes{
    Program route1() {
       return { [](){return std::vector<double>{1.0,-1.0};},
        [](){return std::vector<double>{1.0,0.0};},
        [](){return std::vector<double>{1.0,-1.0};},
       };      
    }
    Program go_to(Coordinates coor1, Coordinates coor2){
        return {[&coor1, &coor2](){return coor2-coor1;}};
    }    
} 

class Rover{
 public:
    Rover(): name(""), coordinates{0,0}{}
    Rover(std::string _name): name(_name), coordinates{0,0}{}
    
    virtual void execute( const std::function<void()> & f){
        if(online) f();
        else 
            std::cout<<"ERROR: Rover not linked to an interface."<<std::endl;
    }
    
    Coordinates get_coordinates() const{ return coordinates; }
    
    std::string get_name() const { return name; }
    
    
    virtual void drive(const Program& progr_) {
        if(online){
            for(auto f:progr_){
                coordinates += f();
                std::cout<<"Arriving at"<<coordinates;  
            }
        }
    }
    
    
    friend class RoverIface;
 protected:
    std::string name;
    Coordinates coordinates;
    bool online=false;
};

#endif