#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "database.h"
#include "listmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Подключаемся к базе данных
    DataBase database;
    database.connectToDataBase();

    // Объявляем и инициализируем модель данных
    ListModel *model = new ListModel();

    // Обеспечиваем доступ к модели и классу для работы с базой данных из QML
    engine.rootContext()->setContextProperty("myModel", model);
    engine.rootContext()->setContextProperty("database", &database);

    engine.load(QUrl(QStringLiteral("../QML/main.qml")));

    return app.exec();
}
