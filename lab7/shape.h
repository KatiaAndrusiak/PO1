#ifndef shape_h
#define shape_h
#include <iostream>
#include <vector>
class Shape{
  public:
    Shape( std::string _name, std::vector<double> _param): name(_name), param(_param){}
    virtual double area() const=0;
    virtual double circumference() const=0;
    virtual ~Shape()=default;
    friend std::ostream & operator<<(std::ostream& out, const Shape& shape);
    protected:
  std::string name;
  std::vector<double> param;
  
};

class Circle: public Shape{
    public:
        using Shape::Shape;
        inline double area() const override {     return 3.14*param[0]*param[0]; }
        inline double circumference() const override { return 2*3.15*param[0]; }
};

class Rectangle: public Shape{
  public:
    using Shape::Shape;
    inline double area() const override {     return param[0]*param[1]; }
    inline double circumference()const override { return 2*(param[0]+param[1]); }
};

std::ostream & operator<<(std::ostream& out, const Shape& shape){
     out<<shape.name;
     return out;
 }

#endif