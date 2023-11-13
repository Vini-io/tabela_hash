#ifndef NODE_H
#define NODE_H
#include "aluno.h"


namespace VN{
class node{
public:
    node* next;
    node* prev;
    Aluno aluno;

    static node* montaNode(Aluno T);
    static void desmontaNode(node* nd);
};
}
#endif // NODE_H
