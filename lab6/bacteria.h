#ifndef bacteria_h
#define bacteria_h
#include <iostream>
#include"gene_utils.h"

class Bacteria : public Organism{
public:
    using Organism::Organism;
    //Bacteria(std::string name,const DNA &tmp): Organism(name,tmp) {}
    Organism* reproduce(Organism* tmp){
       
        Bacteria* organ= new Bacteria(organism_name, mutation(dna));
        return organ;
    }


};

#endif