#include "mainwindow.h"
#include "login.h"
#include "formetudiants.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    l.show();
    return a.exec();
}
