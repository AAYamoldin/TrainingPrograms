#include "adding_form.h"
#include "ui_adding_form.h"
#include <QtDebug>
#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <algorithm>
#include <QTextStream>
#include <QFile>
#include <QThread>

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
   QString Username, links;
   Username = ui->txtFIO->text();
   links = ui->txtLink->text();
   // Создаем объект класса QFile и связываем его с указанным именем файла
   QString filename =  Username+".txt";
   if(QFile::exists(filename) && (!links.isEmpty()))
   {
       QFile file(filename);
       if (file.open(QIODevice::Append)) {
          QTextStream out (&file);
          out << links << endl;

       ui->status_label->setText("Такой автор уже существует. Фото успешно добавлено.");
       file.close();
       }
       else {
           ui->status_label->setText("Поле фото должно быть заполнено!");
           file.close();
       }
   }
   else {
       if (Username.isEmpty() || links.isEmpty())
       {
         ui->status_label->setText("При создании нового автора все поля должны быть заполнены!");
       }
       else {
       QFile file(filename);
       if (file.open(QIODevice::WriteOnly))
       {
          QTextStream out (&file);
          out << links << endl;//записали в файл example.txt
          ui->status_label->setText("У нас появился новый автор! Фото успешно добавлены!");
          file.close();
       }
       else
           ui->status_label->setText("Не удалось создать нового автора и добавить фото:(");
   }
   }
   ui->txtFIO->setText("");
   ui->txtLink->setText("");
}
