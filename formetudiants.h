#ifndef FORMETUDIANTS_H
#define FORMETUDIANTS_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QString>
#include <QDebug>

namespace Ui {
class FormEtudiants;
}

class FormEtudiants : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormEtudiants(QWidget *parent = nullptr);
    void loadEtudiants();
    void showAndDisplay();
    void getSelectedBatiment();
    void loadBatiments();
    ~FormEtudiants();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_btnAjout_clicked();

    void on_btnModify_clicked();

    void on_btnDelete_clicked();

    void on_cb_batiment_currentTextChanged(const QString &arg1);

    void on_cb_type_currentTextChanged(const QString &arg1);

    void on_actiongestion_etudiant_triggered();

    void on_actiongestion_utilisateur_triggered();

private:
    Ui::FormEtudiants *ui;
    QSqlDatabase* db;
};

#endif // FORMETUDIANTS_H
