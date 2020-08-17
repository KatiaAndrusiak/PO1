#include "gene_sequence.h"

std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_){
    for(int n:seq_.chain)
        out<<(char)n<<" ";

    out<<"\n";
return out;
}