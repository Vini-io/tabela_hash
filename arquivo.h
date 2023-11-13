#ifndef ARQUIVO_H
#define ARQUIVO_H


#include "vetor_alunos.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>

namespace VN {
class arquivo{
public:
    void createVetorAluno(Vetor_alunos &vetor_alunos);
};
}
#endif // ARQUIVO_H
