#ifndef virus_h
#define virus_h
#include <iostream>
#include <utility>
#include "gene_sequence.h"
class Virus{
public:
    Virus(): _name(" "), RNA(nullptr), wiek(0){};
    Virus(std::string name): _name(name), RNA(nullptr), wiek(0){};

    Virus(Virus &vir): _name(vir._name), wiek(0)
    {
        if(vir.RNA)   RNA=new GeneSeq(vir.RNA->get_sequence()); 
        vir.wiek++;
    }

    Virus(Virus &&vir): _name(std::exchange(vir._name,"")), RNA(std::exchange(vir.RNA, nullptr)),
                        wiek(std::exchange(vir.wiek,0)) {}

    Virus & operator=( Virus &vir){
        if(this== &vir) return *this;

        delete RNA;
        
        RNA=new GeneSeq(vir.RNA->get_sequence());
        _name=vir._name;
        wiek = vir.wiek;
        return *this;
    }

     Virus & operator=(Virus &&vir){
        if(this== &vir) return *this;
       
        RNA=std::exchange(vir.RNA, nullptr);
        _name=std::exchange(vir._name, "");
        wiek=std::exchange(vir.wiek,0);
        return *this;
    }
    
    std::string get_name() const{    return _name; }

    int get_age() const { return wiek; }

    GeneSeq * get_RNA() const{ return RNA; }

    void set_RNA(const std::vector<Nucleotide> vect){    RNA=new GeneSeq(vect); }

    ~Virus() {   if(RNA)  delete RNA;}
private:
    std::string _name;
    GeneSeq *RNA;
    int wiek;
};


#endif 