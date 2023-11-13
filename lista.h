#ifndef LISTA_H
#define LISTA_H
#include "node.h"


namespace VN{
class lista
{
public:
    node* head;
    node* it;
    int tam;
    lista();
    bool InsertNext(node* P);
    bool Erase();
    bool itPP();
    void itHead();
    bool repeatAlun(int matric);
};
}
#endif // LISTA_H
