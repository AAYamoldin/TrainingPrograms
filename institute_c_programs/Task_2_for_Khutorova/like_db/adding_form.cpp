#include "adding_form.h"
#include "ui_adding_form.h"
#include "mainwindow.h"
#include "createconnection.h"
adding_form::adding_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adding_form)
{
    ui->setupUi(this);
}

adding_form::~adding_form()
{
    delete ui;
}

void adding_form::on_finish_cancel_clicked()
{
    adding_form::hide();
}

void adding_form::on_finish_add_clicked()
{
   QString author, path, personages, date;
   author = ui->txtFIO->text();
   path = ui->photo_path->text();
   personages = ui->personages->text();
   date = ui->date->text();
   // Создаем объект класса QFile и связываем его с указанным именем файла
   if (author.isEmpty() || path.isEmpty()
           || personages.isEmpty() || date.isEmpty()){
       ui->status_label->setText("Все поля должны быть заполнены!");
   } else {
       //добавляем данные в таблицу sql
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName( "photobank" );
        if( !db.open() ) {
            qDebug() << "DB is not created!";
              return ;
         }
       QSqlQuery query( db );
       if( !query.exec(
                   "CREATE TABLE Photos("
                   "   path TEXT NOT NULL,"
                   "   author TEXT NOT NULL,"
                   "   personages TEXT NOT NULL,"
                   "   date TEXT NOT NULL"
                   ")"
       ))
    {
           qDebug() << "Не получается создать базу данных или она уже создана!";
    }
       query.prepare(
                   "INSERT INTO Photos (path, author, personages, date) "
                   "    VALUES (:path, :author, :personages, :date)"
                   );
       query.bindValue(":path", path);
       query.bindValue(":author", author);
       query.bindValue(":personages", personages);
       query.bindValue(":date", date);
       if( !query.exec() ) {
           qDebug() << "Данные в таблицу не вставились";
           return;
       }
       ui->txtFIO->setText("");
       ui->date->setText("");
       ui->personages->setText("");
       ui->photo_path->setText("");
       ui->status_label->setText("Фото успешно добавлено!");
       QSqlDatabase::removeDatabase("photobank");
}

}
void adding_form::on_photo_path_buton_clicked()
{
    QString photo_path = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../photos",
                "Файлы изображений (*.png *.jpg *.bmp)"
                );
    ui->photo_path->setText(photo_path);
}
