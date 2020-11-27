#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <algorithm>
#include <QTextStream>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    QString array = "1,3,4,5,6,75,2,54,4,1,23,4,5,6,5,3,2,"
                            "1,3,4,56,7,86,5,4,2,-123,32,432,4,23,4,4,5,43,33,1,4,4,5,64,1,1";


    // Создаем объект класса QFile и связываем его с указанным именем файла
     QString filename = "example.txt";
     QFile file(filename);
     if (file.open(QIODevice::WriteOnly))
     {
         QTextStream out (&file);
         out << array << endl;//записали в файл example.txt
         file.close();
     }

     // С помощью метода open() открываем файл в режиме чтения
     if (!file.open(QIODevice::ReadOnly)) {
       qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
       return 1;
     }

     // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
     QTextStream in(&file);

     // Считываем файл строка за строкой
     QString line;
     while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
       line = in.readLine(); // метод readLine() считывает одну строку из потока
       //out << line << endl;
     }
     // Закрываем файл
     file.close();
     QStringList list2 = line.split((','));
     QList<int> arr;
     for (int i=0; i < list2.size(); ++i) {
          arr.append(list2.at(i).toInt()); // метод at() возвращает элемент с указанным индексом
     }

     std::sort(arr.begin(), arr.end());

     int sym = 0;
     for (int i = 0; i < 3; i++)
     {
         sym = sym + arr.last();
         arr.pop_back();
     }

     QString s = QString::number(sym);
     QString result = "The sym last of 3 is " + s;

     if (file.open(QIODevice::Append)) {
        QTextStream out (&file);
        out << result << endl;
     }
     file.close();
    return a.exec();
}
