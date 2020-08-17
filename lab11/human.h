// Tutaj należy wpisać kod
#ifndef human_h
#define human_h

#include <tuple>
#include <iostream>
#include <string>
//typedef
typedef std::tuple<int,int,int,int,int> human_readable;

const int d=365;
const int h=24;
const int m=60;
const int s=60;

std::ostream & operator<<(std::ostream & out, const human_readable & tmp)
{
   out<<std::get<0>(tmp)<<"y:"<<std::get<1>(tmp)<<"d:"<<std::get<2>(tmp)
   <<"h:"<<std::get<3>(tmp)<<"m:"<<std::get<4>(tmp)<<"s";
   return out;
    
}

human_readable operator+(const human_readable & a, const human_readable & b){
    
    return std::make_tuple(std::get<0>(a)+std::get<0>(b), std::get<1>(a)+std::get<1>(b), 
    std::get<2>(a)+std::get<2>(b), std::get<3>(a)+std::get<3>(b),std::get<4>(a)+std::get<4>(b));
    
}


human_readable operator"" _sec ( unsigned long long int sec){
    
    long int years=sec/(d*h*m*s);
    sec -= years*(d*h*m*s);
     long int days=sec/(h*m*s);
    sec -= days*(h*m*s);
    long int hours=sec/(m*s);
    sec-=hours*(m*s);
    long int minutes=sec/s;
    sec-=minutes*s;
    return std::make_tuple(years, days,hours,minutes,sec);
}

human_readable operator"" _yrs ( unsigned long long int yrs){
     return std::make_tuple(yrs, 0,0,0,0);
}

human_readable from_sec (  unsigned long long int sec){
    
    long int years=sec/(d*h*m*s);
    sec -= years*(d*h*m*s);
     long int days=sec/(h*m*s);
    sec -= days*(h*m*s);
    long int hours=sec/(m*s);
    sec-=hours*(m*s);
    long int minutes=sec/s;
    sec-=minutes*s;
    return std::make_tuple(years, days,hours,minutes,sec);
}

 unsigned long long int to_sec (const  human_readable& yrs) {
     return std::get<0>(yrs)*d*h*m*s+std::get<1>(yrs)*h*m*s+std::get<2>(yrs)*m*s+std::get<3>(yrs)*s+ std::get<4>(yrs);
}

class Human{
public:
    Human(): lastname(""), age(0,0,0,0,0){}
    Human(const std::string & ln, human_readable t): lastname(ln), age(t){}
    std::string get_name() const{
        return lastname;
    }
    human_readable get_age() const{
        return age;
    }
    
    void update_time(const human_readable & a){
        age= age+a;
    }

    friend class Spacecraft;
protected:
    std::string lastname;
    human_readable age;
    static int n;
};


class Clone: public Human{
public:
    Clone(const Human & hum){
        hum.n++;
        lastname=hum.get_name()+"_"+std::to_string(hum.n);
        age=hum.get_age();
        if(n==2) n=0;
    }
    
protected:
    
   
};

int Human::n=0;


#endif