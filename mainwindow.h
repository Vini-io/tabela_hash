#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aluno.h"
#include "tabela_hash.h"
#include <lista.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_consultar_clicked();
    void on_btn_Inserir_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_btn_remover_clicked();

private:
    void displayTree();

    Ui::MainWindow *ui;
    VN::Aluno *objAluno;
    VN::Tabela_hash<VN::Aluno> tabela;

};
#endif // MAINWINDOW_H
