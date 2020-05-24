#include "DiagramDataProvider.h"

DiagramDataProvider::DiagramDataProvider()
{
    m_xData<<-1.2<<3.1<<4.2<<6<<7.5;
    m_yData<<-5.1<<3.7<<-4.2<<6<<-7.5;

    m_xMin = m_xData.at(0);
    m_xMax = m_xData.at(0);
    m_yMin = m_yData.at(0);
    m_yMax = m_yData.at(0);

    for (int i = 0; i<m_xData.size();i++)
    {
        m_data.push_back(QPointF(m_xData.at(i),m_yData.at(i)));
        if (m_xData.at(i) < m_xMin)
        {
            m_xMin = m_xData.at(i);
        }
        if (m_xData.at(i) > m_xMax)
        {
            m_xMax = m_xData.at(i);
        }

        if (m_yData.at(i) < m_yMin)
        {
            m_yMin = m_yData.at(i);
        }
        if (m_yData.at(i) > m_yMax)
        {
            m_yMax = m_yData.at(i);
        }
    }
}

QVector<QPointF> DiagramDataProvider::getData()
{
    return m_data;
}

double DiagramDataProvider::getX(int rowNumber)
{
    return m_data.at(rowNumber).x();
}

double DiagramDataProvider::getY(int rowNumber)
{
    return m_data.at(rowNumber).y();
}

int DiagramDataProvider::getNumberOfRows()
{
    return m_data.size();
}

double DiagramDataProvider::getMinX()
{
    return m_xMin;
}
double DiagramDataProvider::getMinY()
{
    return m_yMin;
}
double DiagramDataProvider::getMaxX()
{
    return m_xMax;
}
double DiagramDataProvider::getMaxY()
{
    return m_xMax;
}
QVector<double> DiagramDataProvider::getXData()
{
    return m_xData;
}
QVector<double> DiagramDataProvider::getYData()
{
    return m_yData;
}
