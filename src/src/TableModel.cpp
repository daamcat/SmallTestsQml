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
    // The first line of the file is headers/roles. We read them:
    readRoles(dataSplitted.at(0));
    // We remove the headers. The rest is just data:
    dataSplitted.removeFirst();
    setUpModelData(dataSplitted);
}


int TableModel::rowCount(const QModelIndex& modelIndex) const
{
    // In table model, all rows are direct children of root item:
    return m_rootItem->childCount();
}
int TableModel::columnCount(const QModelIndex& modelIndex) const
{
    // In table model, all items have same number of columns:
    return m_rootItem->columnCount();
}
QString TableModel::getRole(int columnNumber)
{
    return QString::fromUtf8(m_roles[columnToRoleNumber(columnNumber)]);
}
QVariant TableModel::data(const QModelIndex& index , int role) const
{
    if (role > Qt::UserRole)
    {
        TableItem *item = m_rootItem->getChildItem(index.row());
        if (item)
        {
            // Retrieve column index from role:
            int columnIndex = roleNumberToColumn(role);
            return item->data(columnIndex);
        }
    }

    return QVariant();
}

QHash<int,QByteArray> TableModel::roleNames() const
{
    return m_roles;
}

void TableModel::setUpModelData(const QStringList& stringList)
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
int TableModel::columnToRoleNumber(int columnNumber) const
{
    return Qt::UserRole + columnNumber + 1;
}
int TableModel::roleNumberToColumn(const int role) const
{
    return role - Qt::ItemDataRole::UserRole - 1;
}
