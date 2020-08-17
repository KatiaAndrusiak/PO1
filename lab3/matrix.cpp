#include "matrix.h"
#include <utility>

int max(int a, int b){
    if(a>b) return a;
    return b;
}
namespace MyStuff{

    ///konstruktor kopiujacy
    matrix::matrix(const matrix& matri): N(matri.N), M(matri.M), matr(new vector *[M])
    {
        for(int i = 0; i < M; i++)
            matr[i] = new vector(N);//wypelniam zerami
        for(int i = 0; i < M; i++)
            matr[i][0] = matri.matr[i][0]; //kopiuje
    }

////////////////////////////////////////////////////////////////////////////////////////

    ///konstruktor przenoszacy
    matrix::matrix(matrix&& matri):  N(std::exchange(matri.N, 0)),  M(std::exchange(matri.M, 0)),
     matr(std::exchange(matri.matr, nullptr)){ }

/////////////////////////////////////////////////////////////////////////////////////////
    
    //operator przypisania kopiujacy
    matrix& matrix::operator=(const matrix& matri)
    {
        if(this==&matri) return *this;

        //usuwam macierz
        if(matr){
            for(int i = 0; i < M; i++){
                delete matr[i];
            } 
            delete [] matr;
        }

        N=matri.N;
        M=matri.M;
        
        //alokuje pamiec dla nowej macierzy
        matr = new vector * [M]; 
        for(int i = 0; i < M; i++)
            matr[i] = new vector(N);

        for(int i = 0; i < M; i++){
            matr[i][0] = matri.matr[i][0]; //kopiuje
        }
        return *this;
    }

/////////////////////////////////////////////////////////////////

    ///operator przypisania przenoszacy
    matrix& matrix::operator=(matrix&& matri)
    {
        if(this==&matri) return *this;
        if(matr){
            for(int i = 0; i < M; i++){
                delete matr[i];
            } 
            delete [] matr;
        }
        N=std::exchange(matri.N, 0);
        M=std::exchange(matri.M, 0);
        matr=std::exchange(matri.matr, nullptr);
        return *this;
    }

////////////////////////////////////////////////////////////////////////

    ///operator[], zwraca vektor(wiersz) macierzy
    vector& matrix::operator[](int n)
    {
        return matr[n][0];
    }

////////////////////////////////////////////////////////////////

    ///metoda fill , wypelnia macierz vektorami
    void matrix::fill(vector *vect, int m)
    {
        for(int i=0; i<m; i++)
            matr[i][0]=vect[i]; //uzywam oper= klasy vector
    }

//////////////////////////////////////////////////////////

    
    matrix matrix::operator+(matrix matri)
    {
        matrix tmp(max(N,matri.N) ,max(M,matri.M)); //tworze macierz wupelniona zerami o max rozmiarach
    
        if(M>=matri.M)
        {
            for(int i=0; i<matri.M; i++)
                tmp[i]= tmp[i]+(*this)[i] + matri[i]; //korystam z oper[], oper= oraz oper+ klasy vector
            for(int i=matri.M; i<M; i++)
                tmp[i]=tmp[i]+(*this)[i];
        }
        else if(M<matri.M)
        {
            for(int i=0; i<M; i++)
                tmp[i]=tmp[i]+ (*this)[i] + matri[i];
            for(int i=M; i<matri.M; i++)
                tmp[i]=tmp[i]+matri[i];
        }
        
        return tmp;
    }

/////////////////////////////////////////////////////////////////

    matrix matrix::operator*(matrix matri)
    {
        matrix tmp;
        if(N==matri.M) //sprawdzam, czy jest mozliwe mnozenie
        {
            matrix t(matri.N, M);//tworze macierz 
            tmp=t;
        
            int s;
            for(int i=0; i<M; i++)
                for(int j=0; j<matri.N; j++)
                {
                    s=0;
                    for(int k=0; k<N; k++) 
                        s += (*this)[i][k] * matri[k][j];//korystam z oper[] klas matrix i vector
                    tmp [i][j] = s;
                }
        }
    return tmp;
    }

////////////////////////////////////////////////////////////

    std::ostream & operator<<(std::ostream &out, const MyStuff::matrix & matr)
    {
        for(int i=0; i<matr.M; i++)
        {
                out<<matr.matr[i][0]<<" ";//uzywam operatora << klasy vector
            out<<"\n";
        }
        out<<"\n";
        return out;
    }



}//koniec namespace