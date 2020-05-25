#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <iostream>

#include "DiagramDataProvider.h"
#include "TableModel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qmlRegisterType<DiagramDataProvider>("NamespaceDiagramDataProvider",1,0,"TypeDiagramDataProvider");
    qmlRegisterType<TableModel>("NamespaceTableModel",1,0,"TableModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    std::cout<<SOURCE_DIR<<std::endl;
    qDebug() << QString(SOURCE_DIR);

    return app.exec();
}
