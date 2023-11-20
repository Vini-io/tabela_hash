#ifndef TABELA_HASH_H
#define TABELA_HASH_H


#include "lista.h"
#include <QString>
#include "aluno.h"

namespace VN {
template <class T>
class Tabela_hash{
public:
    VN::lista<T> *VetorTabela;
    int QAlunos;

    Tabela_hash(){
        try {
            VetorTabela = new lista<T>[337];
        } catch (std::bad_alloc &err) {
            throw QString("Erro na alocação de memória ");
        }

    }


    bool insertion(int pos, QString aluno)
    {
        if(VetorTabela[pos % 337].tam > 0 && VetorTabela[pos % 337].repeatAlun(pos)) return false;

        VN::Aluno *objAluno = new Aluno();
        objAluno->createAluno(pos, aluno);

        if(VetorTabela[pos % 337].tam < 3){
            return VetorTabela[pos % 337].InsertNext(*objAluno);
        }

        return false;
    }



    bool alteracao(int pos, QString newNome){
        if(VetorTabela[pos % 337].tam == 0) return false;
        while(VetorTabela[pos % 337].it->dado.matricula != pos && VetorTabela[pos % 337].it->next != VetorTabela[pos % 337].head){
            VetorTabela[pos% 337].itPP();
        }

        if(VetorTabela[pos % 337].it->dado.matricula == pos){
            VetorTabela[pos % 337].it->dado.nome = newNome;
            VetorTabela[pos % 337].itHead();
            return true;
        }

        VetorTabela[pos % 337].itHead();
        return false;
    }




};
}


#endif // TABELA_HASH_H

