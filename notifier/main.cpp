#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "client.h"
#include "subject.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //----------------------------------------------------------------------------

    Subject *server1 = new Subject();
    server1->setName("Server1");
    server1->setIpAddress("localhost");
    server1->setPort(6547);
    server1->setTryTimeout(5000); // после этого создать инцидент

    server1->tryToConnect();

    return app.exec();
}
