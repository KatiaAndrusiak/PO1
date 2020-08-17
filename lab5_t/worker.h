#ifndef worker_h
#define worker_h

#include <iostream>

class Worker{
 public:
    Worker(std::string name): _name(name) { }
    friend std::ostream& operator<<(std::ostream & out, const Worker& worker);
 private:
    std::string _name;
};

std::ostream& operator<<(std::ostream & out, const Worker& worker)
{
    out<<worker._name;
    return out;
}

#endif 