#ifndef DBCONNEXION_H
#define DBCONNEXION_H

#include <QtSql>
#include <QString>
#include <QDebug>


class DbConnexion
{
public:
    DbConnexion();
    QSqlDatabase* getConnexion();
    bool executeQuery(QSqlQuery* query);
    bool executeUpdate(QSqlQuery* query);

private:
    QSqlDatabase* db;
};

#endif // DBCONNEXION_H
