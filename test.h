#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QtSql>
#include <QString>
#include <QDebug>

namespace Ui {
class Test;
}

class Test : public QDialog
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    void loadEtudiants();
    ~Test();

private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Test *ui;
    QSqlDatabase* db;
};

#endif // TEST_H
