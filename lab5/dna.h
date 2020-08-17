#ifndef dna_h
#define dna_h

class DNA: public GeneSeq{
 friend std::ostream& operator<<( std::ostream& out, const DNA& seq_);
 public:
 DNA(const GeneSeq & s1, const GeneSeq & s2): GeneSeq(s1.get_sequence()), chain2(s2.get_sequence()){}
 
 protected:
 std::vector< Nucleotide > chain2;
};

std::ostream& operator<<( std::ostream& out, const DNA& seq_){
    
    for(int n:seq_.chain)
        out<<(char)n<<" ";

    out<<"\n";
    for(int i=0; i<seq_.chain.size(); i++)
        out<<"| ";
        
    out<<"\n";
    for(int n:seq_.chain2)
        out<<(char)n<<" ";
    out<<"\n";
    return out;
}



#endif 