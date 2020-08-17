#ifndef shape_ptr_h
#define shape_ptr_h
#include "shape.h"
#include <utility>

class Shape_ptr{
public:
    Shape_ptr():ptr(nullptr){}
    Shape_ptr(Shape *_ptr): ptr(_ptr){}
    ~Shape_ptr(){ if(ptr) delete ptr; }
    Shape& operator*(){ return *ptr; }
    Shape_ptr & operator=( Shape_ptr& _ptr){
        if(this==&_ptr) return *this;
        if(ptr) delete ptr;
        std::swap(ptr,_ptr.ptr);
        return *this;
    }

    Shape_ptr & operator=(Shape_ptr&& _ptr){
        if(this==&_ptr) return *this;
        if(ptr) delete ptr;
        ptr=std::exchange(_ptr.ptr, nullptr);
                return *this;
    }
    
   Shape_ptr & operator=(Shape* &_ptr){
        ptr=std::exchange(_ptr, nullptr);
        return *this;
    }

    operator bool(){
        if(ptr) return true; 
        else return false;
    }
private:
    Shape *ptr;
    
};
#endif