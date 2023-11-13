#ifndef VETOR_ALUNOS_H
#define VETOR_ALUNOS_H
//#include "aluno.h"
#include "lista.h"


namespace VN {
class Vetor_alunos{
public:
    lista *alunoVetor;
    int QAlunos;

    Vetor_alunos();
    bool alteracao(int pos, QString newNome);
    bool insertion(int pos, QString aluno);
};
}


#endif // VETOR_ALUNOS_H
