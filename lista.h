#ifndef LISTA_H
#define LISTA_H

#include <node.h>

namespace VN{

template<class T>
class lista{

    public:
        Node<T>* head;
        Node<T>* it;
        int tam;

        lista(): head(nullptr), it(nullptr), tam(0) {}


        bool InsertNext(T dado){

            Node<T>* newNode = new Node<T>(dado);

            if(!head){
                newNode->prev = newNode->next = head = newNode;
                tam++;
                it = newNode;
                return true;
            }else{
                newNode->next = it->next;
                newNode->prev = it;
                it->next->prev = newNode;
                it->next = newNode;
                tam++;
                it = newNode;
                return true;
            }
            return false;
        }


        bool Erase(){
            if(tam == 0) return false;
            if(head){
                Node<T>* itAux = it;

                if(it == head){
                    (it->prev)->next = it->next;
                    (it->next)->prev = it->prev;
                    head = it->next;
                }else{
                    (it->prev)->next = it->next;
                    (it->next)->prev = it->prev;
                }
                delete itAux;
                it = it->next;
                tam--;
                return true;
            }
            return false;
        }


        bool itPP(){
            if(!it || !it->next) return false;

            it = it->next;
            return true;
        }


        void itHead(){
            it = head;
        }


        bool repeatAlun(int matric){

            while(it->dado.matricula != matric && it->next != head){
                itPP();
            }

            if(it->dado.matricula == matric){
                itHead();
                return true;
            }

            itHead();
            return false;
        }
    };
}
#endif // LISTA_H
