#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adding_form.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_find_main_clicked()
{
    findform = new findForm(this);
    findform->show();
}

void MainWindow::on_adding_main_clicked()
{
    addingform = new adding_form(this);
    addingform->show();
}
