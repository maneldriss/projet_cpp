#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QRegExpValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999999, this));
    ui->lineEdit_supp->setValidator(new QIntValidator(0, 999999999, this));
    ui->lineEdit_6->setValidator(new QIntValidator(0, 999999999, this));
    ui->tab_e->setModel(e.afficher());

    QRegExp rx("[a-zA-Z]");
    QValidator *validator = new QRegExpValidator(rx, this);

    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);
    ui->lineEdit_8->setValidator(validator);
    ui->lineEdit_9->setValidator(validator);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int cin=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_4->text();
    QString metier=ui->lineEdit_8->text();
    QString mail=ui->lineEdit_7->text();
    Employe E(cin,nom,prenom,metier,mail);
    bool test=E.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."));
         ui->tab_e->setModel((e.afficher()));
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supp_clicked()
{ QSqlQuery query;
    Employe e1;
    e1.setcin(ui->lineEdit_supp->text().toInt());
    bool test=e1.supprimer(e1.getcin());

        if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."));

        ui->tab_e->setModel((e1.afficher()));}

    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_3_clicked()
{
    int cin=ui->lineEdit_6->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_4->text();
    QString metier=ui->lineEdit_9->text();
    QString mail=ui->lineEdit_7->text();

    Employe E(cin,nom,prenom,metier,mail);
    bool test=E.modifier(cin);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectuée\n"
                                             "Click Cancel to exit."));
         ui->tab_e->setModel((e.afficher()));
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);

}

