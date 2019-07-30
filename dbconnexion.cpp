#include "dbconnexion.h"

DbConnexion::DbConnexion()
{

}

QSqlDatabase* DbConnexion::getConnexion()
{
    const char* driver = "QPSQL";
    db = new QSqlDatabase( QSqlDatabase::addDatabase(driver) );
    db->setConnectOptions();
    db->setHostName("localhost");
    db->setDatabaseName("gesEtudiant");
    db->setUserName("coly");
    db->setPassword("passer");

    if(db->open()) {
        return db;
    }
    else {
        return NULL;
    }
}

bool DbConnexion::executeQuery(QSqlQuery* query) {
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}

bool DbConnexion::executeUpdate(QSqlQuery* query) {
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}
