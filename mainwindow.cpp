#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"avion.h"
#include<QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_avion->setModel(a.afficher());
  ui->le_id->setValidator  (new QIntValidator(100,999999,this));
  ui->la_marque->setMaxLength(8);
  ui->le_modele->setMaxLength(10);
  ui->le_kil->setValidator  (new QIntValidator(001,9999999,this));
    ui->le_id_supp->setValidator  (new QIntValidator(100,999999,this));
      ui->mod_id->setValidator  (new QIntValidator(100,999,this));
        ui->mod_marque->setMaxLength(8);
        ui->mod_modele->setMaxLength(10);
          ui->mod_kil->setValidator  (new QIntValidator(001,9999999,this));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString marque=ui->la_marque->text();
    QString modele=ui->le_modele->text();
    int kil=ui->le_kil->text().toInt();
    Avion a(id,marque,modele,kil);
    bool test;
    test=a.ajouter();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("ajout avec succes");
    ui->tab_avion->setModel(a.afficher()); }
    else msgBox.setText("Echec d'ajout");
    msgBox.exec();

}
void MainWindow::on_pb_modifier_clicked(){
    //recuperation des informlation
    int id=ui->mod_id->text().toInt();
    QString marque=ui->mod_marque->text();
    QString modele=ui->mod_modele->text();
   int kilometrage=ui->mod_kil->text().toInt();

    Avion a(id,marque,modele,kilometrage);

    bool test=a.modifier(id);
        if(test)
        {
            //refrech
             ui->tab_mod->setModel(a.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

void MainWindow::on_pb_afficher_clicked()
{
     bool test;
     test=a.afficher();
    if(test)
    {
        //refrech
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("affichage avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    ui->tab_avion->setModel(a.afficher()); }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("affichage echoue.\n" "Click Close to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_supprimer_clicked()
{
    Avion a; a.setid(ui->le_id_supp->text().toInt());
    bool test;
    test=a.supprimer(a.getid());
    QMessageBox msgBox;
    if(test)
    {msgBox.setText("suppression avec succes");
     ui->tab_sup->setModel(a.afficher());}
    else msgBox.setText("Echec de suppression");
    msgBox.exec();

}
