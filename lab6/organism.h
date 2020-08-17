#ifndef organizm_h
#define organizm_h
#include <iostream>

class Organism{
public:
    Organism(std::string name,const DNA &tmp): organism_name(name), dna(tmp){}
    virtual Organism* reproduce(Organism* organism=nullptr)=0;
    DNA get_dna() const{ return dna;}
    std::string get_name() const { return organism_name;}

    void operator <<(const Virus& vir){
       int l=0;//rand()%2; ///не рандомить як він хоче

       std::vector<Nucleotide> ch(dna[l]);
       int vec_size= ch.size();
       int s = rand()%vec_size;
       
       int vir_size = vir.get_RNA()->get_sequence().size();

       if(vir_size+s<=vec_size){
            int virus_i=0;
            for(int i=s; i< s+vir_size; i++){
                ch[i]=vir.get_RNA()->get_sequence()[virus_i];
                virus_i++;
            }
       }
       else 
       {
           int count=0;
           int virus_i=0;
           
            for(int i=s; i<vec_size; i++){
                ch[i]=vir.get_RNA()->get_sequence()[virus_i];
                count++;
                virus_i++;
            }

            for(int i=0; i<vir_size-count; i++){
                ch[i]=vir.get_RNA()->get_sequence()[virus_i];
                virus_i++;
            }
        }
        
        if(l==0)    dna=DNA(ch,dna[1]);
        if(l==1)    dna=DNA(dna[0],ch);
        
    }


    virtual ~Organism(){}

protected:
   std::string organism_name;
   DNA dna;
};

#endif