#include "formutilisateur.h"
#include "ui_formutilisateur.h"
#include "dbconnexion.h"
#include "utilisateur.h"

#include "login.h"
#include "mainwindow.h"
#include "dbconnexion.h"
#include "declaration.h"
#include "formetudiants.h"

#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>

FormUtilisateur::FormUtilisateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormUtilisateur)
{
    ui->setupUi(this);
}

FormUtilisateur::~FormUtilisateur()
{
    delete ui;
}

void FormUtilisateur::on_tableView_activated(const QModelIndex &index)
{
    if(!db->open())
        db = DbConnexion().getConnexion();

    QString val = ui->tableView->model()->data(index).toString();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from utilisateurs where id='"+val+"'");

    if(query->exec()) {
        while(query->next()) {
            ui->txtnom->setText(query->value(1).toString());
            ui->txtprenom->setText(query->value(2).toString());
            ui->txtlogin->setText(query->value(3).toString());
            ui->txtpassword->setText(query->value(4).toString());
            ui->le_id->setText(query->value(0).toString());
        }
        db->close();
    } else {
        QMessageBox::critical(this, tr("error::"), query->lastError().text());
    }
}

void FormUtilisateur::on_btnAdd_clicked()
{
        if(!db->open())
            db = DbConnexion().getConnexion();

        Utilisateur *utilisateur = new Utilisateur();

        utilisateur->Setlogin(ui->txtlogin->text());
        utilisateur->Setpassword(ui->txtpassword->text());
        utilisateur->Setnom(ui->txtnom->text());
        utilisateur->Setprenom(ui->txtprenom->text());
        utilisateur->Setid(ui->le_id->text());

        addUtilisateur(utilisateur);
        loadUtilisateur();
}

void FormUtilisateur::loadUtilisateur()
{

    db = DbConnexion().getConnexion();
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from utilisateurs");

    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);

    ui->le_id->hide();

    //db->close();
}

void FormUtilisateur::on_btnModify_clicked()
{
    if(!db->open())
        db = DbConnexion().getConnexion();

    Utilisateur *utilisateur = new Utilisateur();
    utilisateur->Setprenom(ui->txtprenom->text());
    utilisateur->Setnom(ui->txtnom->text());
    utilisateur->Setlogin(ui->txtlogin->text());
    utilisateur->Setpassword(ui->txtpassword->text());
    utilisateur->Setid(ui->le_id->text());

    updateUtilisateur(utilisateur);

    FormUtilisateur::loadUtilisateur();
}

void FormUtilisateur::on_actiongestion_etudiant_triggered()
{
    this->close();
    FormEtudiants *fe = new FormEtudiants();
    fe->loadEtudiants();
    fe->showAndDisplay();
    fe->getSelectedBatiment();
    fe->show();
}

void FormUtilisateur::on_actiongestion_utilisateur_triggered()
{
    this->close();
    FormUtilisateur *fu = new FormUtilisateur();
    fu->loadUtilisateur();
    fu->show();
}
