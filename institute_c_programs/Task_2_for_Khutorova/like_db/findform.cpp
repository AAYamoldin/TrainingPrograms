#include "findform.h"
#include "ui_findform.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include "mainwindow.h"

findForm::findForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findForm)
{
    ui->setupUi(this);
    ui->tableView->hide();

}

findForm::~findForm()
{
    delete ui;
}

QString PHOTO;

void findForm::on_find_find_clicked()
{
    ui->tableView->show();
    QString author_ui, personages_ui, date_ui;
    author_ui = ui->find_text->text();
    personages_ui = ui->find_personages->text();
    date_ui = ui->lineEdit_date->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( "photobank" );
     if( !db.open() ) {
         qDebug() << "DB is not created!";
           return ;
     }

     QSqlQuery query;
     QString sql_request;
    if (!author_ui.isEmpty() && personages_ui.isEmpty() && date_ui.isEmpty())
    {
        sql_request = "SELECT * FROM Photos WHERE author in('" + author_ui + "')";
        qDebug() << "известен автор";
        query.exec(sql_request);
        //qDebug() << query.next();
        if(!query.next())
        {
            qDebug() << "Автор не найден!";
            ui->status_find->setText("Фото данного автора не найдено.\nВведите другое имя.");
            ui->find_text->setText("");
            ui->find_personages->setText("");
            ui->lineEdit_date->setText("");
            //qDebug() << "такого автора не существует" << author_ui;
        }
        } else if  (!author_ui.isEmpty() && !personages_ui.isEmpty() && date_ui.isEmpty())
        {
            qDebug() << "известен автор и дата";
            sql_request = "SELECT * FROM Photos WHERE author in('" + author_ui + "') and personages in ('" + personages_ui + "')";
            query.exec(sql_request);
           if(!query.next())
            {
                ui->status_find->setText("Фото этого автора с такими персонажами не найдено.\nВведите другое имя.");
                ui->find_text->setText("");
                ui->find_personages->setText("");
                ui->lineEdit_date->setText("");
                //qDebug() << "такого автора не существует" << author_ui;
            }
        } else if  (!author_ui.isEmpty() && !personages_ui.isEmpty() && !date_ui.isEmpty())
        {
             sql_request = "SELECT * FROM Photos WHERE author in('" + author_ui +
                     "') and personages in ('" + personages_ui + "') and date in ('" +
                     date_ui + "')";
             query.exec(sql_request);
             if(!query.next())
             {
                 ui->status_find->setText("Фото этого автора с такими персонажами на эту дату не найдено.\nВведите другие значения.");
                 ui->find_text->setText("");
                 ui->find_personages->setText("");
                 ui->lineEdit_date->setText("");
                 //qDebug() << "такого автора не существует" << author_ui;
             }
        } else if  (author_ui.isEmpty() && !personages_ui.isEmpty() && date_ui.isEmpty())
        {
            sql_request = "SELECT * FROM Photos WHERE personages in ('" + personages_ui + "')";
            query.exec(sql_request);
           if(!query.next())
            {
                ui->status_find->setText("Фото с такими персонажами не найдено.\nВведите других персонажев.");
                ui->find_text->setText("");
                ui->find_personages->setText("");
                ui->lineEdit_date->setText("");
                //qDebug() << "такого автора не существует" << author_ui;
            }

        } else if  (author_ui.isEmpty() && !personages_ui.isEmpty() && !date_ui.isEmpty())
        {
            sql_request = "SELECT * FROM Photos WHERE personages in ('" + personages_ui + "') and date in ('" +
                    date_ui + "')";
            query.exec(sql_request);
            if(!query.next())
            {
                ui->status_find->setText("Фото с такими персонажами на эту дату не найдено.\nВведите другие значения.");
                ui->find_text->setText("");
                ui->find_personages->setText("");
                ui->lineEdit_date->setText("");
                //qDebug() << "такого автора не существует" << author_ui;
            }

        } else if  (author_ui.isEmpty() && personages_ui.isEmpty() && !date_ui.isEmpty())
        {
            sql_request = "SELECT * FROM Photos WHERE date in ('" +
                    date_ui + "')";
            query.exec(sql_request);
            if(!query.next())
            {
                ui->status_find->setText("Фото на эту дату не найдено.\nВведите другие значения.");
                ui->find_text->setText("");
                ui->find_personages->setText("");
                ui->lineEdit_date->setText("");
                //qDebug() << "такого автора не существует" << author_ui;
            }
        } else if  (!author_ui.isEmpty() && personages_ui.isEmpty() && !date_ui.isEmpty())
        {
            sql_request = "SELECT * FROM Photos WHERE author in('" + author_ui +
                    "') and date in ('" +
                    date_ui + "')";
            query.exec(sql_request);
            if(!query.next())
            {
                ui->status_find->setText("Фото этого автора на эту дату не найдено.\nВведите другие значения.");
                ui->find_text->setText("");
                ui->find_personages->setText("");
                ui->lineEdit_date->setText("");
//                qDebug() << "такого автора не существует" << author_ui;
            }
        }else if  (author_ui.isEmpty() && personages_ui.isEmpty() && date_ui.isEmpty())
        {
            ui->status_find->setText("Должно быт заполнено хотя бы одно поле.\nВведите корректные значения.");
            ui->find_text->setText("");
            ui->find_personages->setText("");
            ui->lineEdit_date->setText("");
        }

    QSqlRecord rec = query.record();
    QString path;
    query.exec(sql_request);
    QFile file("result.txt");
    //вызываем функцию ореn() для открытия файла для записи данных
    if (!file.open(QIODevice::WriteOnly)) {
    }
    QTextStream out (&file);
    while (query.next())
    {
        path = query.value(rec.indexOf("path")).toString();
        QDesktopServices::openUrl(path);
        QString author = query.value(rec.indexOf("author")).toString();
        QString pers = query.value(rec.indexOf("personages")).toString();
        QString date = query.value(rec.indexOf("date")).toString();
        QString total = path + "\t" + author + "\t" + pers + "\t" + date + "\n";
        out << path.leftJustified(100)  << author.leftJustified(20)  << pers.leftJustified(20)  << date.leftJustified(20) << endl ;

    }
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(sql_request);
    ui->tableView->setModel(modal);
}

void findForm::on_find_close_clicked()
{
    findForm::hide();
}

