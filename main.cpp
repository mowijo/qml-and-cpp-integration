#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "myobject.h"
#include "model.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AnimalModel model;
    model.addAnimal(Animal("Wolf", "Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));


    qmlRegisterType<NameCounter>("dk.winkler.qml.NameCounter", 1, 0, "NameCounter");

    QQmlApplicationEngine engine;
    NameCounter morten("Morten");

    engine.rootContext()->setContextProperty("morten", &morten);
    engine.rootContext()->setContextProperty("myModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
