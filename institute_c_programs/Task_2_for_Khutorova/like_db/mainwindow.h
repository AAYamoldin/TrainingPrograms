#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adding_form.h"
#include "findform.h"
#include <QDebug>
#include <QtSql>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QtDebug>
#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <algorithm>
#include <QTextStream>
#include <QFile>
#include <QThread>
#include <QFileDialog>
#include <QDebug>
#include <QtSql>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_find_main_clicked();

    void on_adding_main_clicked();

private:
    Ui::MainWindow *ui;
    adding_form *addingform;
    findForm *findform;
};
#endif // MAINWINDOW_H
