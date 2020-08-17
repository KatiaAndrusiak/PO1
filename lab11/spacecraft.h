#ifndef spacecraft_h
#define spacecraft_h
#include "human.h"
#include <vector>
#include <functional>

class Spacecraft{
 public:
    Spacecraft(const std::vector< Human *> & h): hum(h){}
    
    void update_time(std::function<const human_readable(const human_readable &)> f  ,const human_readable & t){
        for(auto &n:hum)
            n->update_time( f(t));
        
    }
    Human  operator[](const std::string &name){
        
        Human * h;
        for(auto n: hum){
            if(n->get_name()==name){
                h= n;
            }
        }
        return *h;
    }

 protected:
    std::vector< Human *> hum;
};




#endif