#ifndef vector_h
#define vector_h
#include <iostream>

 namespace MyStuff{

class vector{
public:
    ///konstruktor domniemany
    vector(): tab(nullptr), _size(0) {};
    
    ///konstruktor tworzacy wektor o n elementach wypełniony zerami
    vector(int n): tab(new int[n]{0}), _size(n) {}
    
    ///konstruktor kopijacy
    vector(const vector &vect);
    vector(vector&& vect);
    
    ///destruktor
    ~vector(){ if(tab) delete [] tab; }
    
    vector operator=(const vector& vect);
    vector operator=(vector&& vect);
    
    vector operator+(const vector& vect);
    
    int & operator[](int i);
    
    ///metoda size() zwracającą wymiar wektora
    int size() const { return _size; }
    
    void push_back(int m);
    void pop_back();
   
    friend std::ostream & operator<<(std::ostream & out, const MyStuff::vector &vect);
    
private:
    int *tab;
    int _size;

};

}

#endif
