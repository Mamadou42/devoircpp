#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QString>
#include <QDebug>
#include "dbconnexion.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnConnexion_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase* db;
};

#endif // LOGIN_H
