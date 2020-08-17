#ifndef utils_h
#define utils_h

#include <iostream>
#include <vector>

class Coordinates{
public:
    Coordinates(double _x, double _y): coord{_x, _y} {}
    Coordinates(const std::vector<double> _coord): coord(_coord) {}
   
     Coordinates & operator -=(const Coordinates & coor){
          coord[0]=coord[0]-coor.coord[0];
         coord[1]=coord[1]-coor.coord[1];
         return *this;
     }
     Coordinates & operator +=(const Coordinates & coor){
         coord[0]+=coor.coord[0];
         coord[1]+=coor.coord[1];
         return *this;
     }

    std::vector<double> operator-(const Coordinates &coor) const{ 
       std::vector<double> tmp = coord;
       tmp[0] -= coor.coord[0];
       tmp[1] -= coor.coord[1];
       return tmp;    
    }
    friend std::ostream & operator<<(std::ostream & out, const Coordinates & coord){
        out<<"("<<coord.coord[0]<<", "<<coord.coord[1]<<")"<<std::endl;
        return out;
    }
    friend class Rover;
private:
    std::vector<double> coord;
};

#endif