#ifndef DIAGRAMDATAPROVIDER_H
#define DIAGRAMDATAPROVIDER_H

#include <QObject>
#include <QPointF>

class DiagramDataProvider : public QObject
{
    Q_OBJECT
public:
    DiagramDataProvider();

    // Q_INVOKABLE makes the method available for Qt-Meta-Object system and hence for QML.
    // Another way would be to define the method as public slot.
    Q_INVOKABLE QVector<QPointF> getData();
    Q_INVOKABLE double getX(int rowNumber);
    Q_INVOKABLE double getY(int rowNumber);
    Q_INVOKABLE double getMinX();
    Q_INVOKABLE double getMinY();
    Q_INVOKABLE double getMaxX();
    Q_INVOKABLE double getMaxY();
    Q_INVOKABLE int getNumberOfRows();
    Q_INVOKABLE QVector<double> getXData();
    Q_INVOKABLE QVector<double> getYData();

public slots:

private:
    QVector<QPointF> m_data;
    QVector<double> m_xData;
    QVector<double> m_yData;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;

};

#endif // DIAGRAMDATAPROVIDER_H
