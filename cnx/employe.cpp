#include "employe.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlRecord>
Employe::Employe()
{
cin=0;
nom="";
prenom="";
metier="";
mail="";
}
Employe::Employe(int cin,QString nom,QString prenom,QString metier ,QString mail){
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->metier=metier;
    this->mail=mail;

}
int Employe::getcin(){
return cin;

}
QString Employe::getnom(){
    return nom;

}
QString Employe::getprenom(){
   return prenom;

}
QString Employe::getmetier(){
    return metier;

}
QString Employe::getmail(){
    return mail;

}
void Employe::setcin(int cin){
    this->cin=cin;


}
void Employe::setnom(QString nom){
    this->nom=nom;

}
void Employe::setprenom(QString prenom){
    this->prenom=prenom;


}
void Employe::setmetier(QString metier){
    this->metier=metier;
}
void Employe::setmail(QString mail){
    this->mail=mail;

}
bool Employe::ajouter(){

    QSqlQuery query;
    QString cin_string=QString::number(cin);
          query.prepare("INSERT INTO employe (cin, prenom, nom,mail,metier) "
                        "VALUES (:cin, :prenom, :nom, :mail, :metier)");
          query.bindValue(":cin", cin_string);
          query.bindValue(":prenom", prenom);
          query.bindValue(":nom", nom);
          query.bindValue(":mail", mail);
          query.bindValue(":metier", metier);
          return query.exec();



}
bool Employe::supprimer(int cin){
    QSqlQuery query;
    /*query.prepare("SELECT from employe where cin=:cin");
    query.bindValue(0, cin);*/
          query.prepare("Delete from employe where cin=:cin");
          query.bindValue(0, cin);
            return query.exec();
}


QSqlQueryModel* Employe::afficher(){
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM employe");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("metier"));




     return model;
}
bool Employe::modifier(int cin){
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    query.prepare("UPDATE employe SET metier=:metier WHERE cin=:cin");
    query.bindValue(":cin", cin_string);
    query.bindValue(":metier", metier);

    return query.exec();
}

