#ifndef TABLEITEM_H
#define TABLEITEM_H

#include<QVector>
#include<QVariant>

class TableItem
{
public:
    explicit TableItem(QVector<QVariant> data, TableItem *parent = nullptr);
    // Keyword "explicit" to avoid unwanted conversion.
    // Each TableItem has a parent item, which itself is another TableItem.

    // Destructor declaration:
    ~TableItem();

    QVariant data(int columnNumber) const;
    // The "const" at the end of function member declaration? We get compiler error if we later try to change the value returned by these functions.
    // The idea behind "const" function members is not to allow the function members to modify the objects on which they are called.
    // Example: Inside these "const" functions, you can't call m_childItems.clear();

    int columnCount() const;
    int row()const;
    TableItem* getParentItem() const; // Each TreeItem has a parent TreeItem, except the root item.
    void setData(QVector<QVariant> data);
    void appendChild(TableItem *child);
    TableItem* getChildItem(int row);
    int childCount() const;
    QVector<TableItem*> getChildren();

private:
    QVector<QVariant> m_itemData;
    TableItem* m_parentItem;
    QVector<TableItem*> m_children;

};

#endif // TABLEITEM_H
