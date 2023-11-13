#include "mainwindow.h"
#include "ui_mainwindow.h"

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

        if(vetor_alunos.alunoVetor[i].tam > 0){


            for(int j = 0; j < vetor_alunos.alunoVetor[i].tam; j++){

                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(i));
                root->setText(1, QString::number(vetor_alunos.alunoVetor[i].it->aluno.matricula));
                root->setText(2, vetor_alunos.alunoVetor[i].it->aluno.nome);
                ui->treeWidget->addTopLevelItem(root);
                vetor_alunos.alunoVetor[i].itPP();
            }
            vetor_alunos.alunoVetor[i].itHead();
        }else{
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
            root->setText(0, QString::number(i));
            ui->treeWidget->addTopLevelItem(root);
        }

    }

}

void MainWindow::displayTree()
{
    vetor_alunos = VN::Vetor_alunos();
    VN::arquivo arq;
    arq.createVetorAluno(vetor_alunos);
    ui->treeWidget->setColumnCount(2);
    QStringList lables;
    lables <<"Posição"<<"Matricula" <<"Nome";
    ui->treeWidget->setHeaderLabels(lables);

    for(size_t i = 0; i < 337 ; i++){

        if(vetor_alunos.alunoVetor[i].tam > 0){


            for(int j = 0; j < vetor_alunos.alunoVetor[i].tam; j++){

                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(i));
                root->setText(1, QString::number(vetor_alunos.alunoVetor[i].it->aluno.matricula));
                root->setText(2, vetor_alunos.alunoVetor[i].it->aluno.nome);
                ui->treeWidget->addTopLevelItem(root);
                vetor_alunos.alunoVetor[i].itPP();
            }
            vetor_alunos.alunoVetor[i].itHead();
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

    if((matr < 1000 && matr > -1) && (vetor_alunos.alunoVetor[matr % 337].tam != 0)){



            while(vetor_alunos.alunoVetor[matr % 337].it->aluno.matricula != matr && vetor_alunos.alunoVetor[matr % 337].it->next != vetor_alunos.alunoVetor[matr % 337].head){
            vetor_alunos.alunoVetor[matr % 337].itPP();
            }


            if(vetor_alunos.alunoVetor[matr % 337].it->aluno.matricula == matr){
                ui->treeWidget->clear();
                QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
                root->setText(0, QString::number(matr % 337));
                root->setText(1, QString::number(vetor_alunos.alunoVetor[matr % 337].it->aluno.matricula));
                root->setText(2, vetor_alunos.alunoVetor[matr % 337].it->aluno.nome);
                ui->treeWidget->addTopLevelItem(root);

            }else{
                QMessageBox messageBox;
                messageBox.setText("aluno não encontrado!");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
            }


            vetor_alunos.alunoVetor[matr % 337].itHead();


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

    if(vetor_alunos.insertion(matricula, nome)){
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


    if(vetor_alunos.alteracao(matricula, Novo_nome)){
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

    while(vetor_alunos.alunoVetor[matricula % 337].it->aluno.matricula != matricula && vetor_alunos.alunoVetor[matricula % 337].it->next != vetor_alunos.alunoVetor[matricula % 337].head){
            vetor_alunos.alunoVetor[matricula % 337].itPP();
    }

    if(vetor_alunos.alunoVetor[matricula % 337].it->aluno.matricula == matricula){
        if(vetor_alunos.alunoVetor[matricula % 337].Erase()){
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
    }else{
                QMessageBox messageBox;
                messageBox.setText("Aluno não encontrado!");
                messageBox.setIcon(QMessageBox::Critical);
                messageBox.exec();
        }
    vetor_alunos.alunoVetor[matricula % 337].itHead();

        on_pushButton_clicked();
    }



