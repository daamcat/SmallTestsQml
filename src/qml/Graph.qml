import QtQuick 2.9
import QtQuick.Window 2.2
import QtCharts 2.3
import NamespaceDiagramDataProvider 1.0

Window
{
    id: idWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Graph")

    ChartView
    {
        id: chart
        title: "Chart"
        anchors.fill: parent
        antialiasing: true

        TypeDiagramDataProvider
        {
            id: diagramDataProvider
        }
        ValueAxis
        {
            id:xAxis
            min: diagramDataProvider.getMinX();
            max: diagramDataProvider.getMaxX();
        }

        ValueAxis
        {
            id:yAxis
            min: diagramDataProvider.getMinY();
            max: diagramDataProvider.getMaxX();
        }
        Component.onCompleted:
            // This is an "attached signal handler". This handler is called as ChartView is created.
        {
            var lineSeries = chart.createSeries(ChartView.SeriesTypeLine,"A sample chart",xAxis,yAxis);
            var nRows = diagramDataProvider.getNumberOfRows();
            for (var i=0;i<nRows;i++)
            {
                lineSeries.append(diagramDataProvider.getX(i),diagramDataProvider.getY(i));
            }

        }
    }
}
