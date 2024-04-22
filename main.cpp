#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SeriesSearch.h"
// #include "model.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // AnimalModel model;
    // model.addAnimal(Animal("Wolf", "Medium"));
    // model.addAnimal(Animal("Polar bear", "Large"));
    // model.addAnimal(Animal("Quoll", "Small"));

    // QQuickView view;
    // view.setResizeMode(QQuickView::SizeRootObjectToView);
    // view.setInitialProperties({{"model", QVariant::fromValue(&model)}});
    // //![0]
    // view.setSource(QUrl("qrc:/qt-qml-series/view.qml"));
    // view.show();

    // return app.exec();

    QQmlApplicationEngine engine;

    SeriesSearch *seriesSearch = new SeriesSearch(&app);
    qmlRegisterSingletonInstance("SeriesSearch",1,0,"SeriesSearch", seriesSearch);

    const QUrl url(QStringLiteral("qrc:/qt-qml-series/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
