#include "declaration.h"
#include "etudiant.h"
#include <QString>
#include <QDebug>

void addEtudiant(Etudiant *etudiant) {
    DbConnexion().getConnexion();
    QSqlQuery query;
    query.prepare("insert into etudiants(prenom, nom, email, telephone, matricule, dateNaissance, adresse, typeetudiant, bourse, batiment, chambre)values"
                  "('"+etudiant->Getprenom()+"', '"+etudiant->Getnom()+"', '"+etudiant->Getemail()+"', '"+etudiant->Gettelephone()+"', '"+etudiant->Getmatricule()+"', '"+etudiant->GetdateNaissance()+"', '"+etudiant->Getadresse()+"', '"+etudiant->GettypeEtudiant()+"', '"+etudiant->Getbourse()+"', '"+etudiant->Getbatiment()+"', '"+etudiant->Getchambre()+"')");
    if(query.exec())
    {
        qDebug() << "etudiant enregistre avec success!!";
    }
    else {
        qDebug() << "echec ajout etudiant!!!";
    }
}

void updateEtudiant(Etudiant *etudiant){
    DbConnexion().getConnexion();
    QSqlQuery query;
    query.prepare("update etudiants set prenom='"+etudiant->Getprenom()+"',nom='"+etudiant->Getnom()+"',email='"+etudiant->Getemail()+"',telephone='"+etudiant->Gettelephone()+"',matricule='"+etudiant->Getmatricule()+"',datenaissance='"+etudiant->GetdateNaissance()+"',adresse='"+etudiant->Getchambre()+"',typeetudiant='"+etudiant->GettypeEtudiant()+"',bourse='"+etudiant->Getbourse()+"',batiment='"+etudiant->Getbatiment()+"',chambre='"+etudiant->Getchambre()+"'");
    if(query.exec())
    {
        qDebug() << "etudiant modifié avec success!!";
    }
    else {
        qDebug() << "echec modication etudiant!!!";
    }
}

void addUtilisateur(Utilisateur *utilisateur){
    DbConnexion().getConnexion();

    QSqlQuery query;
    query.prepare(" insert into utilisateurs (prenom, nom, username, password) values ('"+utilisateur->Getprenom()+"', '"+utilisateur->Getnom()+"', '"+utilisateur->Getlogin()+"', '"+utilisateur->Getpassword()+"' )");
    query.exec();
    if(query.exec())
    {
        qDebug() << "utilisateur enregistre avec success!!";
    }
    else {
        qDebug() << "echec ajout utilisateur!!!";
    }

}

void updateUtilisateur(Utilisateur *utilisateur){
    DbConnexion().getConnexion();
    QSqlQuery query;
    query.prepare("update utilisateurs set prenom='"+utilisateur->Getprenom()+"',nom='"+utilisateur->Getnom()+"',username='"+utilisateur->Getlogin()+"',password='"+utilisateur->Getpassword()+"' where id = '"+utilisateur->Getid()+"'");
    if(query.exec())
    {
        qDebug() << "utilisateur modifié avec success!!";
    }
    else {
        qDebug() << "echec modication utilisateur!!!";
    }
}

QSqlQueryModel *loadEtudiant() {
    DbConnexion().getConnexion();

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from etudiants");

    query->exec();
    modal->setQuery(*query);

    return modal;
}
