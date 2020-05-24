#include "TableItem.h"

TableItem::TableItem(QVector<QVariant> data, TableItem* parent) :
    m_itemData(data),
    m_parentItem(parent)
{

}

TableItem::~TableItem()
{

}

QVariant TableItem::data(int columnNumber) const
{
    return (columnNumber < columnCount()) ? m_itemData.at(columnNumber) : QVariant();
}

int TableItem::columnCount() const
{
    return m_itemData.size();
}
int TableItem::row()const
{
    if (!m_parentItem)
        // If the item has no parent, it is root item, and its row is zero. Model will never ask for this!
    {
        return 0;
    }
    return this->getParentItem()->getChildren().indexOf(const_cast<TableItem*>(this));
}
TableItem* TableItem::getParentItem() const
{
    return m_parentItem;
}
void TableItem::setData(QVector<QVariant> data)
{
    m_itemData = data;
}
void TableItem::appendChild(TableItem *child)
{
    m_children.push_back(child);
}
TableItem* TableItem::getChildItem(int row)
{
    if (row>=0 && row<childCount())
    {
        return m_children.at(row);
    }
    return nullptr;
}

QVector<TableItem*> TableItem::getChildren()
{
    return m_children;
}

int TableItem::childCount() const
{
    return m_children.size();
}


