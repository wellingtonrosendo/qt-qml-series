#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SeriesSearch.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

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
