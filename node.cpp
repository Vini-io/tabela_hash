#include "node.h"

VN::node *VN::node::montaNode(Aluno T){
    node* P = new node;
    if(P){
        P->next = 0;
        P->aluno = T;
    }
    return P;
}

void VN::node::desmontaNode(node *nd){
    delete nd;
}
