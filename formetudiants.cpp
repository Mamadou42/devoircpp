#include "formetudiants.h"
#include "ui_formetudiants.h"
#include "login.h"
#include "mainwindow.h"
#include "dbconnexion.h"
#include "etudiant.h"
#include "declaration.h"
#include <QDate>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include "formutilisateur.h"

FormEtudiants::FormEtudiants(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormEtudiants)
{
    ui->setupUi(this);
}

FormEtudiants::~FormEtudiants()
{
    delete ui;
}

void FormEtudiants::on_tableView_activated(const QModelIndex &index)
{
    if(!db->isOpen())
        db = DbConnexion().getConnexion();

    QString val = ui->tableView->model()->data(index).toString();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from etudiants where id='"+val+"' or prenom='"+val+"' or email='"+val+"' or telephone='"+val+"' or matricule='"+val+"' or datenaissance='"+val+"' or adresse='"+val+"' or typeetudiant='"+val+"' or bourse='"+val+"'");

    if(query->exec()) {
        while(query->next()) {
            ui->le_matricule->setText(query->value(5).toString());
            ui->le_prenom->setText(query->value(1).toString());
            ui->le_nom->setText(query->value(2).toString());
            ui->le_email->setText(query->value(3).toString());
            ui->le_telephone->setText(query->value(4).toString());
            ui->le_adresse->setText(query->value(7).toString());
            ui->le_id->setText(query->value(0).toString());
            QString dte = query->value(6).toString();
            QDate date = QDate::fromString(dte,"dd/MM/yyyy");
            ui->cb_type->setItemText(query->value(0).toInt(), query->value(8).toString());
            ui->de_dateNaissance->setDate(date);
        }
        //db->close();
    } else {
        QMessageBox::critical(this, tr("error::"), query->lastError().text());
    }

}

void FormEtudiants::loadEtudiants()
{
    db = DbConnexion().getConnexion();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from etudiants");

    QSqlQuery* query2 = new QSqlQuery();
    query2->prepare("select nom from batiment");

    query->exec();
    query2->exec();
    modal->setQuery(*query);
    modal2->setQuery(*query2);
    ui->tableView->setModel(modal);
    ui->cb_batiment->setModel(modal2);

    ui->le_id->hide();

    db->close();
}

void FormEtudiants::loadBatiments()
{
    db = DbConnexion().getConnexion();
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select nom from batiment");

    query->exec();
    modal->setQuery(*query);
    ui->cb_batiment->setModel(modal);

    db->close();
}

void FormEtudiants::showAndDisplay(){
    QString type = ui->cb_type->currentText();
    if(type == "non boursier") {
        ui->cb_bourse->hide();
        ui->label_8->hide();
        ui->cb_batiment->hide();
        ui->cb_chambre->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_9->show();
        ui->le_adresse->show();
    }
    else if(type == "boursier") {
        ui->label_8->show();
        ui->cb_bourse->show();
        ui->cb_batiment->hide();
        ui->label_11->hide();
        ui->label_10->hide();
        ui->cb_chambre->hide();
        ui->label_9->show();
        ui->le_adresse->show();
    }
    else {
        ui->label_8->show();
        ui->cb_bourse->show();
        ui->cb_batiment->show();
        ui->cb_chambre->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_9->hide();
        ui->le_adresse->hide();
    }
}

void FormEtudiants::on_btnAjout_clicked()
{
    if(!db->open())
        db = DbConnexion().getConnexion();

    Etudiant *etudiant = new Etudiant();
    etudiant->Setprenom(ui->le_prenom->text());
    etudiant->Setnom(ui->le_nom->text());
    etudiant->Setemail(ui->le_email->text());
    etudiant->Settelephone(ui->le_telephone->text());
    etudiant->SetdateNaissance(ui->de_dateNaissance->text());
    etudiant->Setadresse(ui->le_adresse->text());
    etudiant->Setmatricule(ui->le_matricule->text());
    etudiant->SettypeEtudiant(ui->cb_type->currentText());
    if(ui->cb_type->currentText() == "boursier" || ui->cb_type->currentText() == "non boursier"){
        etudiant->Setchambre("");
        etudiant->Setbatiment("");
    }
    if(ui->cb_type->currentText() == "non boursier"){
        etudiant->Setbourse("");
    }
    else if(ui->cb_type->currentText() == "boursier" || ui->cb_type->currentText() == "boursier & logé"){
        etudiant->Setbourse(ui->cb_bourse->currentText());
    }

    addEtudiant(etudiant);

    FormEtudiants::loadEtudiants();
}

void FormEtudiants::on_btnModify_clicked()
{
    if(!db->open())
        db = DbConnexion().getConnexion();

    Etudiant *etudiant = new Etudiant();
    etudiant->Setprenom(ui->le_prenom->text());
    etudiant->Setnom(ui->le_nom->text());
    etudiant->Setemail(ui->le_email->text());
    qDebug() << etudiant->Getemail();
    etudiant->Settelephone(ui->le_telephone->text());
    etudiant->SetdateNaissance(ui->de_dateNaissance->text());
    etudiant->Setadresse(ui->le_adresse->text());
    etudiant->Setmatricule(ui->le_matricule->text());
    etudiant->SettypeEtudiant(ui->cb_type->currentText());
    if(ui->cb_type->currentText() == "boursier" || ui->cb_type->currentText() == "non boursier"){
        etudiant->Setchambre("");
        etudiant->Setbatiment("");
    }
    if(ui->cb_type->currentText() == "non boursier"){
        etudiant->Setbourse("");
    }
    else if(ui->cb_type->currentText() == "boursier" || ui->cb_type->currentText() == "boursier & logé"){
        etudiant->Setbourse(ui->cb_bourse->currentText());
    }
    updateEtudiant(etudiant);

    FormEtudiants::loadEtudiants();
}

void FormEtudiants::on_btnDelete_clicked()
{
    if(!db->isOpen())
        db = DbConnexion().getConnexion();
    QSqlQuery *query = new QSqlQuery();
    QString id = ui->le_id->text();
    query->prepare("Delete from etudiants WHERE id = '"+id+"'");
    if(query->exec()){
        QMessageBox::critical(this,tr("Delete"), tr("Supprime avec success!"));
        FormEtudiants::loadEtudiants();
        //db->close();
    }
    else {
        QMessageBox::critical(this,tr("Error"), query->lastError().text());
    }
}

void FormEtudiants::on_cb_batiment_currentTextChanged(const QString &arg1)
{
    getSelectedBatiment();
}

void FormEtudiants::getSelectedBatiment() {

    if(!db->open())
        db = DbConnexion().getConnexion();

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery();
    QString bat = ui->cb_batiment->currentText();
    query->prepare("select c.numero from chambre c, batiment b where c.batiment_id = b.id and b.nom = '"+bat+"'");

    query->exec();
    modal->setQuery(*query);
    ui->cb_chambre->setModel(modal);

    //db->close();
}

void FormEtudiants::on_cb_type_currentTextChanged(const QString &arg1)
{
    showAndDisplay();
}

void FormEtudiants::on_actiongestion_etudiant_triggered()
{
    this->close();
    FormEtudiants *fe = new FormEtudiants();
    fe->loadEtudiants();
    fe->showAndDisplay();
    fe->getSelectedBatiment();
    fe->show();
}

void FormEtudiants::on_actiongestion_utilisateur_triggered()
{
    this->close();
    FormUtilisateur *fu = new FormUtilisateur();
    fu->loadUtilisateur();
    fu->show();
}
