#include "aluno.h"

namespace VN {
Aluno::Aluno(){
    matricula = -1;
    nome = "";
}

void Aluno::createAluno(int matriculaP, QString nomeP)
{
    nome = nomeP;
    matricula = matriculaP;
}
}
