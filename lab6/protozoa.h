#ifndef protozoa_h
#define protozoa_h
#include "gene_utils.h"

class Protozoa : public Organism{
public:
    using Organism::Organism;
    //Protozoa(std::string name,const DNA &tmp): Organism(name,tmp) {}
    Organism* reproduce(Organism* tmp)
    {
        if(tmp->get_name()!=this->get_name()){
            return nullptr;
        }
        Protozoa* organ = new Protozoa(organism_name, mutation( DNA(this->dna[0], tmp->get_dna()[1])));
        return organ;
    }

};

#endif