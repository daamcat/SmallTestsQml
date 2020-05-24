#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "TableItem.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& = QModelIndex()) const override;
    Q_INVOKABLE int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex& index , int role) const override;
    QHash<int,QByteArray> roleNames() const override;


    Q_INVOKABLE QString getRole(int columnNumber);

private:
    void setUpModelData(const QStringList& stringList, TableItem* rootItem);
    void readRoles(const QString& firstLine);
    TableItem* m_rootItem;
    QHash<int,QByteArray> m_roles;

};

#endif // TABLEMODEL_H
