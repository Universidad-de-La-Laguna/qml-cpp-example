#include "qmlmosaicengine.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<QmlMosaicEngine>("MosaicEngine", 1, 0, "MosaicEngine");
    qmlRegisterType<QmlMosaicStatus>("MosaicEngine", 1, 0, "MosaicStatus");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
