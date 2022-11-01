#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getmetier();
    QString getmail();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setmetier(QString);
    void setmail(QString);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();

private:
    int cin;
    QString nom;
    QString prenom;
    QString metier;
    QString mail;


};

#endif // EMPLOYE_H
