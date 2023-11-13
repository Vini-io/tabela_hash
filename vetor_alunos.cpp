#include "vetor_alunos.h"
#include <QMessageBox>

VN::Vetor_alunos::Vetor_alunos() : alunoVetor(nullptr), QAlunos(0)
{
    try {
        alunoVetor = new lista[337];
    } catch (std::bad_alloc &err) {
        throw QString("Erro na alocação de memória ");
    }

}

bool VN::Vetor_alunos::insertion(int pos, QString aluno)
{
    if(alunoVetor[pos % 337].tam > 0 && alunoVetor[pos % 337].repeatAlun(pos)) return false;

    VN::Aluno *objAluno = new Aluno();
    objAluno->createAluno(pos, aluno);

    node* NodeAluno = node::montaNode(*objAluno);

    if(NodeAluno){
        if(alunoVetor[pos % 337].tam < 3){
            return alunoVetor[pos % 337].InsertNext(NodeAluno);
        }
    }
    return false;
}

bool VN::Vetor_alunos::alteracao(int pos, QString newNome)
{
    if(alunoVetor[pos % 337].tam == 0) return false;
    while(alunoVetor[pos % 337].it->aluno.matricula != pos && alunoVetor[pos % 337].it->next != alunoVetor[pos % 337].head){
        alunoVetor[pos% 337].itPP();
    }

    if(alunoVetor[pos % 337].it->aluno.matricula == pos){
        alunoVetor[pos % 337].it->aluno.nome = newNome;
        alunoVetor[pos % 337].itHead();
        return true;
    }


        alunoVetor[pos % 337].itHead();
        return false;
}
