#ifndef user_h
#define user_h

#include <iostream>
#include <memory>
#include <string>
#include <vector>
class User{
 public:
    //konstruktor domniemany
    User(): name(""){}
    //konstruktor glosny
    User(const std:: string & nm): name(nm){
        std::cout<<"Creating User "<<name<<"\n";
    }
    //metoda jaka wyrzuca wyjatek
    void authorize(bool b){
        if (!b) throw std::string("Authorisation for User John Shaft was not granted."); 
    }
    //getter name
    std:: string get_name() const{
        return name;
    }
    //destruktor glosny
    ~User(){
        std::cout<<"Deleting User "<<name<<"\n";
    }
 
 protected:
    std:: string name;
};


class UserArray{
 public:
    //konstruktor tworzacy tablice wskaznikow
    UserArray(const int _n) : n(_n){
        user= new User *[n];
    }
    
    //metoda sluzy do wypelniania tablicy userow, wyrzuca wyjatek
    void set(int i, User* us){
        if(i!=n || i<n){
            user[i]=us;
        }
        else{
            delete us;
            //tworze unique_ptr ktoremu przekazuje referencje do naszego obiektu
            //dzieki czemu nasz obiekt samousuwa sie 
            std::unique_ptr<UserArray> ptr(&*this); 
            throw ptr;
        }
    }
    
    //zwraca usera
    User * get(int l) const{
        return user[l];
    }
    
    //destruktor usuwajcy tablice wskaznikow
    ~UserArray(){
        if( user){
            for(int i=0; i<n; i++){
                delete user[i];
            }
            delete [] user;
        }
    }
    
 protected:
    int n;
    User** user;
};


#endif