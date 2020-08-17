#ifndef matrix_h
#define matrix_h
#include "vector.h"
#include <iostream>

 namespace MyStuff{

class matrix{
public:
    matrix(): N(0), M(0), matr(nullptr){}

    matrix(int n, int m): N(n), M(m), matr(new vector *[M]){
        for(int i=0; i<M; i++)
            matr[i]=new vector(N);// alokuje i wypelniam zerami
    }

    matrix(const matrix& matri);
    matrix(matrix&& matri);
    
    matrix& operator=(const matrix& matri);
    matrix& operator=(matrix&& matri);

    matrix operator+(matrix matri);
    matrix operator*(matrix matri);

    vector& operator[](int n);

    ~matrix(){
        if(matr){
        for(int i = 0; i < M; i++)  delete matr[i];
            delete [] matr;
        }
    }

    void fill(vector *vect, int m);
    friend std::ostream & operator<<(std::ostream &out, const MyStuff::matrix & matr);


private:
   int N;//liczba kolumn
   int M;//liczba wierszy
   MyStuff::vector **matr;
};

}
#endif