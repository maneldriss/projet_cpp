#include "user_interface.h"
#include "ui_user_interface.h"
#include "avion.h"
#include "vool.h"
#include "billet.h"

#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QDate>
#include "contrat.h"

#include <QMessageBox>
user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);
    ui->tab_avion->setModel(tmpavion.afficher());
    ui->list->setModel(tmpavion.afficher());
    ui->comboBox->setModel(tmpavion.afficher());
    ui->tableView->setModel(tmpavion.statistic());
    ui->tabproduit_2->setModel(tmpvol.afficher());
    ui->tableView1->setModel(tmpemploye.afficher());
    ui->tableView2->setModel(tmpdep.afficher());
    ui->tabvoyageur->setModel(tmpvoy.afficher());
    ui->tabbillet->setModel(tmpbillet.afficher());
    ui->tab_contrat->setModel(tmpcont.afficher());
    ui->list_cont->setModel(tmpcont.afficher());
    ui->listcontrat->setModel(tmpcont.afficher());





}

user_interface::~user_interface()
{
    delete ui;
}


void user_interface::on_g_vol_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);



}



void user_interface::on_g_agence_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);


}
void user_interface::on_g_emp_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);

}
void user_interface::on_g_dep_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);

}
void user_interface::on_g_bag_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);

}
void user_interface::on_g_coli_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);


}
void user_interface::on_g_voy_clicked()
{

    ui->stackedWidget->setCurrentIndex(7);

}
void user_interface::on_g_billet_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);


}void user_interface::on_g_avion_clicked()
{

   ui->stackedWidget->setCurrentIndex(9);



}
void user_interface::on_g_contrat_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);



}
void user_interface::on_ajout_avion_clicked()
{
    QString mat,comp,model;
      mat=ui->matricule->text();
      comp=ui->compagne->text();
      model=ui->model->text();
      if(mat=="" || comp=="" || model=="")
      {
          QMessageBox::critical(nullptr, QObject::tr("vide"),
                      QObject::tr("veuillez saisir tous les champs.\n"), QMessageBox::Cancel);

      }
      else
      {
      avion a(mat,comp,model);

       a.ajouter();
       ui->tab_avion->setModel(a.afficher());
       ui->list->setModel(a.afficher());
       ui->tableView->setModel(tmpavion.statistic());
       ui->comboBox->setModel(tmpavion.afficher());

      }


}
void user_interface::on_supprimer_avion_clicked()
{

    QString mat=ui->list->currentText();
        tmpavion.supprimer(mat);
        ui->tab_avion->setModel(tmpavion.afficher());
        ui->list->setModel(tmpavion.afficher());
        ui->comboBox->setModel(tmpavion.afficher());
        ui->tableView->setModel(tmpavion.statistic());


}


void user_interface::on_modifier_avion_clicked()
{


    QString mat,comp,model,mat_modif;
    mat=ui->matricule_2->text();
    comp=ui->compagne_2->text();
    model=ui->model_2->text();
    mat_modif=ui->comboBox->currentText();
    avion a;
   a.modifier(mat,comp,model,mat_modif);
   ui->tab_avion->setModel(a.afficher());
   ui->list->setModel(a.afficher());
   ui->comboBox->setModel(a.afficher());
   ui->tableView->setModel(tmpavion.statistic());


}
void user_interface::on_actualiser_clicked()
{

QString crit=ui->comboBox_2->currentText();
if(crit=="REGISTRATION")

    ui->tab_avion->setModel(tmpavion.trier());
else
    ui->tab_avion->setModel(tmpavion.afficher());


}



void user_interface::on_ajouter_vol_clicked()
{
    int nbv = ui->nbv_e->text().toInt();
    QString date= ui->date_vol_e->text();
    QString destination= ui->destination_e->text();
    int reference= ui->reference_e->text().toInt();
  VOOL p(reference,date,destination,nbv);
 p.ajouter();
 ui->tabproduit_2->setModel(p.afficher());//refresh


}

void user_interface::on_radioButton_clicked(bool checked)
{
    if(checked)
        ui->tabproduit_2->setModel(tmpvol.afficher());
}

void user_interface::on_supprimer_clicked()
{
    int reference_ch = ui->reference_sup_e->text().toInt();
    bool test=tmpvol.supprimer(reference_ch);
    if(test)
    {ui->tabproduit_2->setModel(tmpvol.afficher());//refresh
        //QString okd="";
             //notification ok;
             //ok.notification_supprimer(okd);
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("PRODUIT supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void user_interface::on_checkBox_clicked(bool checked)
{
    if(checked){etat=1;}
    else if(checked!=1){
        etat=0;}
}
void user_interface::on_radioButton_2_clicked(bool checked)
{

    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_ref_asc());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_ref());}
}

void user_interface::on_radioButton_3_clicked(bool checked)
{

    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_destination_asc());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_destination_asc());}
}

void user_interface::on_radioButton_4_clicked(bool checked)
{
    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_nb_voyageurs());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_nb_voyageurs_asc());}
}

void user_interface::on_pushButton_2_clicked()
{

         QString destination= ui->destination_e_2->text();
         //QString date_exp= ui->date_exp_m->text();
         QString date= ui->date_vol_e_2->text();
         int ref= ui->reference_e_3->text().toInt();
        // int qt_stock= ui->quantite_m->text().toInt();
         int nbv= ui->nbv_e_2->text().toInt();
      /*   int refrayon=0;
         int qt_rayon=0;
         float prix = ui->prix_m->text().toFloat();
         float solde = ui->solde_m->text().toFloat(); */
           VOOL p;
            if(p.rech(ref)){
                bool test = p.modifier(ref,destination,date,nbv);
                if(test){
                    QString okd="";
                         //notification ok;
                         //ok.notification_modifier(okd);
                    ui->tabproduit_2->setModel(tmpvol.afficher());
                    //ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
                    QMessageBox::information(nullptr,QObject::tr("Produit modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
                }
            }

}
void user_interface::on_ajouterEmp_clicked()
{


    int cin,age,tel;
    QString nom,prenom,adresse,departement;
    cin=ui->lineEdit_Cin->text().toInt();
    tel=ui->lineEdit_tel->text().toInt();
    age=ui->lineEdit_age->text().toInt();
    nom=ui->lineEdit_nom->text();
    prenom=ui->lineEdit_prenom->text();
    departement=ui->lineEdit_depart->text();
    adresse=ui->lineEdit_adresse->text();

    Employes e(cin,nom,prenom,age,tel,adresse,departement);
    e.ajouter();
    ui->tableView1->setModel(tmpemploye.afficher());


}

void user_interface::on_modifier_emp_clicked()
{
    int cin,age,tel;

    QString nom,prenom,adresse,departement;
    cin=ui->lineEditModif->text().toInt();
    nom=ui->lineEdit_2Modif->text();
    prenom=ui->lineEdit_3Modif->text();
    age=ui->lineEdit_4Modif->text().toInt();
    tel=ui->lineEdit_5Modif->text().toInt();
    adresse=ui->lineEdit_6Modif->text();
    departement=ui->lineEdit_7Modif->text();

    Employes e;
    e.modifier(cin,nom,prenom,age,tel,adresse,departement);
    ui->tableView1->setModel(tmpemploye.afficher());




}


void user_interface::on_supprimer_emp_clicked()
{
    int cin=ui->lineEdit_cinSuppr->text().toInt();
    tmpemploye.supprimer(cin);
    ui->tableView1->setModel(tmpemploye.afficher());




}
void user_interface::on_AjouterDepart_clicked()
{
    int id,numEmp;
    QString nom,chef;

    id=ui->lineEdit_id->text().toInt();
    numEmp=ui->lineEdit_numemp->text().toInt();
    nom=ui->lineEdit_nom_2->text();
    chef=ui->lineEdit_chef->text();
    Departement d(id, nom, chef,numEmp);
    d.ajouter();
    ui->tableView2->setModel(tmpdep.afficher());


}


void user_interface::on_modifierDepart_clicked()
{
    int id,numEmp;
    QString nom,chef;

    id=ui->lineEdit_idModif->text().toInt();
    numEmp=ui->lineEdit_numModif->text().toInt();
    nom=ui->lineEdit_nomModif->text();
    chef=ui->lineEdit_chefModif->text();
    tmpdep.modifier(id,nom,chef,numEmp);
    ui->tableView2->setModel(tmpdep.afficher());


}
void user_interface::on_SupprDepart_clicked()
{
    int cin=ui->lineEdit_idSuppr->text().toInt();
    tmpdep.supprimer(cin);
    ui->tableView2->setModel(tmpdep.afficher());

}
void user_interface::on_ajoutervoyageur_clicked()
{

    QString cin, tel,nom,prenom;
      cin=ui->le_cin1->text();
      tel=ui->le_telephone->text();
      nom=ui->le_nom->text();
     prenom=ui->le_prenom->text();
     voyageur v(cin,tel,nom,prenom);
     v.ajouter();
     ui->tabvoyageur->setModel(tmpvoy.afficher());




}
void user_interface::on_supprimervoyageur_clicked()
{
   QString cin=ui->le_cin_5->text();
    tmpvoy.supprimer(cin);
    ui->tabvoyageur->setModel(tmpvoy.afficher());

}
void user_interface::on_modif_voy_clicked()
{
    QString cin, tel,nom,prenom;
      cin=ui->le_cin_3->text();
      tel=ui->le_telephone_2->text();
      nom=ui->le_nom_2->text();
     prenom=ui->le_prenom_2->text();
     tmpvoy.modifier(cin,tel,nom,prenom);
     ui->tabvoyageur->setModel(tmpvoy.afficher());

}

void user_interface::on_ajouterbillet_clicked()
{
    int code;
       QString date;
       QString destination;
    code=ui->le_code_billet->text().toInt();
    date=ui->le_date_billet->text();
    destination=ui->le_destination_billet->text();
    billet b(code,date,destination);
    b.ajouter();
   ui->tabbillet->setModel(tmpbillet.afficher());




}



void user_interface::on_modifierbillet_clicked()
{
    int code;
       QString date;
       QString destination;
    code=ui->le_code->text().toInt();
    date=ui->la_date->text();
    destination=ui->la_des->text();
    tmpbillet.modifier(code,date,destination);
   ui->tabbillet->setModel(tmpbillet.afficher());



}

void user_interface::on_supprimerbillet_clicked()
{
    int cin=ui->le_code_->text().toInt();
    tmpbillet.supprimer(cin);
    ui->tabbillet->setModel(tmpbillet.afficher());


}

void user_interface::on_ajout_contrat_clicked()
{
    int id;
    QString nom_societe,matricule;
    id=ui->idcontrat->text().toInt();
    nom_societe=ui->nomsociete->text();
    matricule=ui->matcontrat->text();
    Contrat c(id,nom_societe,matricule);
    c.ajouter();
    ui->tab_contrat->setModel(c.afficher());
    ui->list_cont->setModel(tmpcont.afficher());
    ui->listcontrat->setModel(tmpcont.afficher());


}

void user_interface::on_confirmmodif_clicked()
{
       int code,codemodif;
       QString  nom_societe,destination;
       code=ui->identifiantmodif->text().toInt();
       codemodif=ui->listcontrat->currentText().toInt();
       nom_societe=ui->nomsocietemodif->text();
       destination=ui->matriculemodif->text();
       tmpcont.modifier(code,nom_societe,destination,codemodif);
       ui->tab_contrat->setModel(tmpcont.afficher());
       ui->list_cont->setModel(tmpcont.afficher());
       ui->listcontrat->setModel(tmpcont.afficher());



}

void user_interface::on_suppcontrat_clicked()
{
   int code=ui->list_cont->currentText().toInt();
   tmpcont.supprimer(code);
   ui->tab_contrat->setModel(tmpcont.afficher());
   ui->list_cont->setModel(tmpcont.afficher());
   ui->listcontrat->setModel(tmpcont.afficher());


}

void user_interface::on_actualiser_2_clicked()
{
    QString crit=ui->critcontrat->currentText();
    if(crit=="ID")

        ui->tab_contrat->setModel(tmpcont.trier());
    else
        ui->tab_contrat->setModel(tmpcont.afficher());

}
