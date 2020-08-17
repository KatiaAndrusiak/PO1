#ifndef math_h
#define math_h
#include <cmath>
#include <vector>
#include <map>

template <const int n, const double* x1, const double* x2>
class IntegralXn{
public:
       static constexpr double value = (n<0)  ? 0.0: (n*pow(*x2, n-1) - n*pow(*x1, n-1));     
};

template< typename T>
class GroupZn{
public:
    GroupZn( std::vector< T>  tmp){
            vec[tmp[0]]=1;
        for( int i=1; i<tmp.size(); i++){
            vec[tmp[i]]=2*i;
        }
    }
    T operator()(T a, T b){
        return vec[a]*vec[b];
    }

    std::map<T,int> vec; 
    std::map<   
};

#endif