#include "lista.h"
#include "qmessagebox.h"

VN::lista::lista()
{
    head = it = 0;
    tam = 0;
}

bool VN::lista::InsertNext(node* P)
{

    if(!head){
        P->prev = P->next = head = P;
        tam++;
        it = P;
        return true;
    }else{
        P->next = it->next;
        P->prev = it;
        it->next->prev = P;
        it->next = P;
        tam++;
        it = P;
        return true;
    }
    return false;
}

bool VN::lista::Erase()
{
    if(tam == 0) return false;
    if(head){
        node* itAux = it;

        if(it == head){
            (it->prev)->next = it->next;
            (it->next)->prev = it->prev;
            head = it->next;
            node::desmontaNode(itAux);
        }else{
            (it->prev)->next = it->next;
            (it->next)->prev = it->prev;
            node::desmontaNode(itAux);
        }
        it = it->next;
        tam--;
        return true;
    }
    return false;
}

bool VN::lista::itPP()
{
    if(!it || !it->next) return false;

    it = it->next;
    return true;
}

void VN::lista::itHead()
{
    it = head;
}

bool VN::lista::repeatAlun(int matric)
{

    while(it->aluno.matricula != matric && it->next != head){
        itPP();
    }

    if(it->aluno.matricula == matric){
        itHead();
        return true;
    }

    itHead();
    return false;
}
