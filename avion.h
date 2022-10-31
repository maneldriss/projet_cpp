#ifndef AVION_H
#define AVION_H
#include<QString>
#include<QSqlQueryModel>

class Avion
{
public:
    Avion();
    Avion(int,QString,QString,int);
    int getid();
    QString getmarque();
    QString getmodele();
    int getkil();
    void setid(int);
    void setmarque(QString);
    void setmodele(QString);
    void setkil(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
  private:
    int id;
   QString marque,modele;
   int kil;

};

#endif // AVION_H
