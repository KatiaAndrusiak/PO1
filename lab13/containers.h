#ifndef containers_h
#define containers_h
#include <map>
#include <vector>
#include <string>
#include <type_traits>

class WaterContainer{
  public:
  
  //konstruktor 
    WaterContainer(double V): max_size(V), actual_amount(0) {}
    
    void put(double V){
        if(V>max_size){
            throw std::string("Error: Container too small.");
        }   
        else{
            actual_amount=V;
        }
    }
    
    double get(){
        return actual_amount;
    }
    
    void clean(){
        actual_amount=0;
    }
    
    double operator+=(const WaterContainer & w){
        double tmp=actual_amount;
        tmp+=w.actual_amount;
        return tmp;
    }
    
  protected:
    double max_size;
    double actual_amount;
};

enum Bill{Ten_PLN, Twenty_PLN, Fifty_PLN,  Hundred_PLN};

class Wallet{
  public:
    Wallet(int a): max_size(a){
        txt[Ten_PLN]="Ten";
        txt[Twenty_PLN]="Twenty";
        txt[Fifty_PLN]="Fifty";
        txt[Hundred_PLN]="Hundred";
    }
    
    void put( std::vector<Bill> bill){
        int size=bill.size();
        if(size>max_size){
            throw std::string("Error: Wallet too small.");
        }
        else{
            wallet=bill;
        }
    }
    
    void clean(){
        wallet.clear();
    }
    
    std::string get(){
        std::string tmp;
        
        if(wallet.size()==0){
            tmp="No bills.";
        }
        else{
          for(auto n: wallet){
            tmp+=txt[n] + " ";
        }  
        }
        return tmp;
    }
    
    std::vector<Bill> operator+=(const Wallet & w){
        std::vector<Bill> tmp;
        for(auto n: wallet){
            tmp.push_back(n);
        }
         for(auto n: w.wallet){
            tmp.push_back(n);
        }
        return tmp;
    }
  
  protected:
    int max_size;
    std::vector<Bill> wallet;
    std::map<Bill, std::string> txt;
    
};

template <typename T>
void move_to_container( T & a,  T & b){
    try {
		a.put(a+=b);
        b.clean(); }
	catch (const std::string& info) {
		std::cout << ">> " << info << std::endl; }
}

template <int a, typename T>
std::vector<T> replicate_container(const T & b){
    std::vector<T> tmp;
    for( int i=0; i<a; i++){
        tmp.push_back(b);
    }
    return tmp;
}


template < typename T1, typename T2 >
void compare_container_type(const T1 & a, const T2 &b){
    if(std::is_same<T1,T2>::value){
        std::cout<<"The containers are of same type."<<std:: endl;
    }
    else{
        std::cout<<"The containers are of different type."<<std:: endl;
    }
}




#endif