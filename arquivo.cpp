#include "arquivo.h"

namespace VN {
void arquivo::createVetorAluno(Vetor_alunos &vetor_alunos)
{
    std::ifstream arquivo;

    arquivo.open("C:/Users/vini/Desktop/atividades/ED2_13/13/DadosDosAlunos_Matricula_Nome.csv");

    std::string attr, attr2;

    if(arquivo.is_open()){

        while(std::getline(arquivo, attr)){

            std::stringstream attrString(attr);
            attr2 = "";
            int n = 1;
            std::string M_A[2]; // matricula é nome

            while(std::getline(attrString, attr2, ';')){
                n = (n + 1) % 2;
                if(n == 0 ) M_A[n] = attr2;
                else M_A[n] = attr2;
            }


            if(vetor_alunos.insertion(std::stoi(M_A[0]), QString::fromStdString(M_A[1]))){
                vetor_alunos.QAlunos++;
            }else{
                QMessageBox messageBox;
                messageBox.setText("erro em alocar aluno no vetor");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
            }
        }

        arquivo.close();

    }else{
        QMessageBox messageBox;
        messageBox.setText("ERRO ARQUIVO");
        messageBox.setIcon(QMessageBox::Critical);
        messageBox.exec();
    }


}
}
