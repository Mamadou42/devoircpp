#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <QString>

class Utilisateur
{
public:
    Utilisateur();
    QString Getid() {return this->id; }
    void Setid(QString val) {this->id = val;}
    QString Getprenom() {return this->prenom; }
    void Setprenom(QString val) {this->prenom = val;}
    QString Getnom() {return this->nom; }
    void Setnom(QString val) {this->nom = val;}
    QString Getlogin() {return this->login; }
    void Setlogin(QString val) {this->login = val;}
    QString Getpassword() {return this->password; }
    void Setpassword(QString val) {this->password = val;}

private:
    QString id;
    QString prenom;
    QString nom;
    QString login;
    QString password;
};

#endif // UTILISATEUR_H
