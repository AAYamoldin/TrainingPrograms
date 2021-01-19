#include "mainwindow.h"
#include <QApplication>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("photobank");
    QSqlQuery query( db );
    if( !query.exec(
                "CREATE TABLE photos("
                "   path TEXT NOT NULL,"
                "   author TEXT NOT NULL,"
                "   personages TEXT NOT NULL,"
                "   date TEXT NOT NULL"
                ")"
    ))
    {
        qDebug() << "Не получается создать базу данных!";
         qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //createConnection();
    MainWindow w;
    w.show();
    return a.exec();
}
