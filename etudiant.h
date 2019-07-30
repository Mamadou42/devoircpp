#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <string>
#include <QString>
#include "dbconnexion.h"

using namespace std;

class Etudiant : DbConnexion
{
public:
    Etudiant();
    QString Getprenom() {return this->prenom; }
    void Setprenom(QString val) {this->prenom = val;}
    QString Getnom() {return this->nom; }
    void Setnom(QString val) {this->nom = val;}
    QString Getemail() {return this->email; }
    void Setemail(QString val) {this->email = val;}
    QString Gettelephone() {return this->telephone; }
    void Settelephone(QString val) {this->telephone = val;}
    QString Getmatricule() {return this->matricule; }
    void Setmatricule(QString val) {this->matricule = val;}
    QString GetdateNaissance() {return this->dateNaissance; }
    void SetdateNaissance(QString val) {this->dateNaissance = val;}
    QString Getadresse() {return this->adresse; }
    void Setadresse(QString val) {this->adresse = val;}
    QString GettypeEtudiant() {return this->typeEtudiant; }
    void SettypeEtudiant(QString val) {this->typeEtudiant = val;}
    QString Getbourse() {return this->bourse; }
    void Setbourse(QString val) {this->bourse = val;}
    QString Getbatiment() {return this->batiment; }
    void Setbatiment(QString val) {this->batiment = val;}
    QString Getchambre() {return this->chambre; }
    void Setchambre(QString val) {this->chambre = val;}




private:
    unsigned int id;
    QString prenom;
    QString nom;
    QString email;
    QString telephone;
    QString matricule;
    QString dateNaissance;
    QString adresse;
    QString typeEtudiant;
    QString bourse;
    QString batiment;
    QString chambre;
};

#endif // ETUDIANT_H
