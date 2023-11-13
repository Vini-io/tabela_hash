#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
namespace VN{
//template <typename TEM_ALUNO>
class Aluno{
public:
    int matricula;
    QString nome;

    Aluno();
    void createAluno(int matriculaP, QString nomeP);
};
}

#endif // ALUNO_H
