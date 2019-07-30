#ifndef FORMUTILISATEUR_H
#define FORMUTILISATEUR_H

#include <QMainWindow>
#include <QtSql>
#include <QString>
#include <QDebug>

namespace Ui {
class FormUtilisateur;
}

class FormUtilisateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormUtilisateur(QWidget *parent = nullptr);
    void loadUtilisateur();
    ~FormUtilisateur();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_btnAdd_clicked();

    void on_btnModify_clicked();

    void on_actiongestion_etudiant_triggered();

    void on_actiongestion_utilisateur_triggered();

private:
    Ui::FormUtilisateur *ui;
    QSqlDatabase* db;
};

#endif // FORMUTILISATEUR_H
