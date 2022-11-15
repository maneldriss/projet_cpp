#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QMainWindow>
#include <avion.h>
#include <vool.h>
#include <employes.h>
#include <departement.h>
#include <voyageur.h>
#include <billet.h>
#include <contrat.h>

namespace Ui {
class user_interface;
}

class user_interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_interface(QWidget *parent = nullptr);
    ~user_interface();
private slots:


    void on_g_avion_clicked();
    void on_g_contrat_clicked();
    void on_g_vol_clicked();
    void on_g_agence_clicked();
    void on_g_emp_clicked();
    void on_g_dep_clicked();
    void on_g_bag_clicked();
    void on_g_coli_clicked();
    void on_g_voy_clicked();
    void on_g_billet_clicked();
    void on_ajout_avion_clicked();
    void on_supprimer_avion_clicked();
    void on_modifier_avion_clicked();
    void on_actualiser_clicked();
    void on_ajouterEmp_clicked();
    void on_modifier_emp_clicked();

    void on_supprimer_emp_clicked();

    //  void on_g_compte_clicked();








    void on_ajouter_vol_clicked();

    void on_radioButton_clicked(bool checked);

    void on_supprimer_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);
    void on_modifierbillet_clicked();
    void on_supprimerbillet_clicked();

    void on_checkBox_clicked(bool checked);
    void on_modifierDepart_clicked();
    void on_SupprDepart_clicked();
     void on_ajoutervoyageur_clicked();
    void on_pushButton_2_clicked();
    void on_AjouterDepart_clicked();
    void on_supprimervoyageur_clicked();
    void on_modif_voy_clicked();
    void on_ajouterbillet_clicked();
    //void sendMail();

    //void mailSent(QString);

    //void on_statbtn_clicked();

    void on_ajout_contrat_clicked();

    void on_confirmmodif_clicked();

    void on_suppcontrat_clicked();

    void on_actualiser_2_clicked();

private:
    Ui::user_interface *ui;
    avion tmpavion;
    VOOL tmpvol;
    Employes tmpemploye;
    Departement tmpdep;
    voyageur tmpvoy;
    billet tmpbillet;
    Contrat tmpcont;
    int etat;

};

#endif // USER_INTERFACE_H
