#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "formetudiants.h"
#include "dbconnexion.h"
#include "test.h"

#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnConnexion_clicked()
{
    db = DbConnexion().getConnexion();
    QString username, password;
    username = ui->le_username->text();
    password = ui->le_password->text();
    if(!db->isOpen()) {
        qDebug() << "Failed to open the database";
        return;
    }
    QSqlQuery query;
    if(query.exec("select * from utilisateurs where username='"+username+"' and password='"+password+"'"))
    {
        int count = 0;
        while (query.next()) {
            count++;
        }
        if(count == 1)
        {
            this->hide();
            FormEtudiants *fe = new FormEtudiants();
            fe->loadEtudiants();
            fe->showAndDisplay();
            fe->getSelectedBatiment();
            fe->show();
        }
        if(count > 1)
            ui->label->setText("Duplicate username and password");
        if(count < 1)
            ui->label->setText("username and password is not correct");
    }
}
