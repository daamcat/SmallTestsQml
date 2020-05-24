#include "TableModel.h"

#include <QFile>
#include <QDebug>


TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    QString fileName = "C:/Projects/SmallTestsQml/SmallTestsQml/trunk/src/testData/sampleTable.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QStringList dataSplitted = QString(file.readAll()).split("\n");
    file.close();
    readRoles(dataSplitted.at(0));
    dataSplitted.removeFirst();
    setUpModelData(dataSplitted, m_rootItem);
}


int TableModel::rowCount(const QModelIndex& modelIndex) const
{
    return m_rootItem->childCount();
}
int TableModel::columnCount(const QModelIndex& modelIndex) const
{
    return m_rootItem->columnCount();
}
QString TableModel::getRole(int columnNumber)
{
    return QString::fromUtf8(m_roles[Qt::UserRole + columnNumber + 1]);
}

QVariant TableModel::data(const QModelIndex& index , int role) const
{
    if (role > Qt::UserRole)
    {
        // Retrieve column index from role:
        int columnIndex = role - Qt::ItemDataRole::UserRole - 1;

        TableItem *item = m_rootItem->getChildItem(index.row());
        if (item)
        {
            return item->data(columnIndex);
        }
    }

    return QVariant();
}
QHash<int,QByteArray> TableModel::roleNames() const
{
    return m_roles;

    return { {Qt::ItemDataRole::DisplayRole, "Tag"}};
    return { {Qt::ItemDataRole::DisplayRole, "display2"}};
}

void TableModel::setUpModelData(const QStringList& stringList, TableItem* rootItem)
{
    for (int i=0; i<stringList.size(); i++)
    {
        QStringList lineContents = stringList.at(i).simplified().split(';');

        QVector<QVariant> data;
        for (QString s : lineContents)
        {
            data<<s;
        }
        TableItem* item = new TableItem(data,m_rootItem);
        m_rootItem->appendChild(item);
    }
}

void TableModel::readRoles(const QString& firstLine)
{
    // The first line is header. Read it to root item:
    QStringList headers = firstLine.simplified().split(';');

    QVector<QVariant> data;
    for (int i = 0; i<headers.size();i++)
    {
        m_roles[Qt::UserRole + i +1] = headers.at(i).toUtf8();
        data<<headers.at(i);
    }
    m_rootItem = new TableItem(data);

}
