#include "findform.h"
#include "ui_findform.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>

findForm::findForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findForm)
{
    ui->setupUi(this);
    ui->see_photo->hide();
}

findForm::~findForm()
{
    delete ui;
}

QString PHOTO;

void findForm::on_find_find_clicked()
{
    QString Username;
    Username = ui->find_text->text();
    QString filename = Username+".txt";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        ui->status_find->setText("Автор с таким именем не найден.\nВведите другое имя.");
        ui->find_text->setText("");
    }
    else {
         QString text;
         text = "Фото автора: " +  Username + " вы можете найти по ссылке\n";
         ui->status_find->setText(text);
         ui->see_photo->show();
    }
}

void findForm::on_find_close_clicked()
{
    findForm::hide();
}


void findForm::on_see_photo_clicked()
{
    QString Username;
    Username = ui->find_text->text();
    QString filename = Username+".txt";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
      line = in.readLine(); // метод readLine() считывает одну строку из потока
      QDesktopServices::openUrl(line);
      //QDesktopServices::openUrl(text);
      //out << line << endl;
    }
    // Закрываем файл
    file.close();
}
