#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <sstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->treeWidget->setColumnCount(2);
    QStringList lables;
    lables <<"Posição"<<"Matricula" <<"Nome";
    ui->treeWidget->setHeaderLabels(lables);
    ui->treeWidget->clear();

    for(size_t i = 0; i < 337 ; i++){

        if(tabela.VetorTabela[i].tam > 0){

            for(int j = 0; j < tabela.VetorTabela[i].tam; j++){

                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(i)); //vetor_alunos.alunoVetor[i].it->aluno.matricula
                root->setText(1, QString::number(tabela.VetorTabela[i].it->dado.matricula));
                root->setText(2, tabela.VetorTabela[i].it->dado.nome);
                ui->treeWidget->addTopLevelItem(root);
                tabela.VetorTabela[i].itPP();
            }
            tabela.VetorTabela[i].itHead();
        }else{
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
            root->setText(0, QString::number(i));
            ui->treeWidget->addTopLevelItem(root);
        }

    }

}

void MainWindow::displayTree()
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


            if(tabela.insertion(std::stoi(M_A[0]), QString::fromStdString(M_A[1]))){
                tabela.QAlunos++;
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

    ui->treeWidget->setColumnCount(2);
    QStringList lables;
    lables <<"Posição"<<"Matricula" <<"Nome";
    ui->treeWidget->setHeaderLabels(lables);

    for(size_t i = 0; i < 337 ; i++){

        if(tabela.VetorTabela[i].tam > 0){


            for(int j = 0; j < tabela.VetorTabela[i].tam; j++){

                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(i));
                root->setText(1, QString::number(tabela.VetorTabela[i].it->dado.matricula));
                root->setText(2, tabela.VetorTabela[i].it->dado.nome);
                ui->treeWidget->addTopLevelItem(root);
                tabela.VetorTabela[i].itPP();
            }
            tabela.VetorTabela[i].itHead();
        }else{
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
            root->setText(0, QString::number(i));
            ui->treeWidget->addTopLevelItem(root);
        }
    }
}

void MainWindow::on_btn_consultar_clicked()
{

    ui->treeWidget->setColumnCount(2);
    QStringList lables;
    lables <<"Posição"<<"Matricula" <<"Nome";
    ui->treeWidget->setHeaderLabels(lables);
    int matr = ui->entrada_consulta->text().toInt();

    if((matr < 1000 && matr > -1) && (tabela.VetorTabela[matr % 337].tam != 0)){



            while(tabela.VetorTabela[matr % 337].it->dado.matricula != matr && tabela.VetorTabela[matr % 337].it->next != tabela.VetorTabela[matr % 337].head){
            tabela.VetorTabela[matr % 337].itPP();
            }


            if(tabela.VetorTabela[matr % 337].it->dado.matricula == matr){
                ui->treeWidget->clear();
                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(matr % 337));
                root->setText(1, QString::number(tabela.VetorTabela[matr % 337].it->dado.matricula));
                root->setText(2, tabela.VetorTabela[matr % 337].it->dado.nome);
                ui->treeWidget->addTopLevelItem(root);

            }else{
                QMessageBox messageBox;
                messageBox.setText("aluno não encontrado!");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
            }


            tabela.VetorTabela[matr % 337].itHead();


        }else{
            QMessageBox messageBox;
            messageBox.setText("aluno não encontrado");
            messageBox.setIcon(QMessageBox::Critical);
            messageBox.exec();
        }

}


void MainWindow::on_btn_Inserir_clicked(){

    int matricula = ui->entrada_matricula->text().toInt();
    QString nome = ui->entrada_nome->text();

    if(tabela.insertion(matricula, nome)){
            on_pushButton_clicked();
            QMessageBox messageBox;
            messageBox.setText("aluno inserido!");
            messageBox.setIcon(QMessageBox::Information);
            messageBox.exec();
    }else{
            QMessageBox messageBox;
            messageBox.setText("Matricula invalida!");
            messageBox.setIcon(QMessageBox::Critical);
            messageBox.exec();
    }

}


void MainWindow::on_pushButton_2_clicked()
{

    int matricula = ui->entrada_alteracao->text().toInt();
    QString Novo_nome = ui->nova_nome->text();
    if(tabela.alteracao(matricula, Novo_nome)){
            on_pushButton_clicked();
            QMessageBox messageBox;
            messageBox.setText("aluno alterado!");
            messageBox.setIcon(QMessageBox::Information);
            messageBox.exec();
    }else{
            QMessageBox messageBox;
            messageBox.setText("alteração invalida!");
            messageBox.setIcon(QMessageBox::Critical);
            messageBox.exec();
    }
}

void MainWindow::on_btn_remover_clicked()
{
    int matricula = ui->entrada_remover->text().toInt();

    if(tabela.VetorTabela[matricula % 337].tam != 0 && matricula > -1 && matricula < 1000){

            while(tabela.VetorTabela[matricula % 337].it->dado.matricula != matricula && tabela.VetorTabela[matricula % 337].it->next != tabela.VetorTabela[matricula % 337].head){
                tabela.VetorTabela[matricula % 337].itPP();
            }
    if(tabela.VetorTabela[matricula % 337].it->dado.matricula == matricula){

        if(tabela.VetorTabela[matricula % 337].Erase()){
                QMessageBox messageBox;
                messageBox.setText("aluno removido!");
                messageBox.setIcon(QMessageBox::Information);
                messageBox.exec();
        }else{
                QMessageBox messageBox;
                messageBox.setText("remoção invalida!");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
        }
    }
    else{
                QMessageBox messageBox;
                messageBox.setText("Aluno não encontrado!");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
        }
    tabela.VetorTabela[matricula % 337].itHead();
    on_pushButton_clicked();
    }else{
    QMessageBox messageBox;
    messageBox.setText("Aluno não encontrado!");
    messageBox.setIcon(QMessageBox::Critical);
    messageBox.exec();
    }
    }



