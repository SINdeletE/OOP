//
// Created by nuelex on 22/05/25.
//

#ifndef TABLE_HPP
#define TABLE_HPP
#include <QGraphicsScene>
#include <QTableWidget>


class Table
{
public:
    Table() = default;
    explicit Table(QTableWidget *table) { this->setTable(table); }
    ~Table() = default;

    void setTable(QTableWidget *table);

    void pushItem(const QString& object_name);
    void removeItem(const size_t id);

    int selectedItem() const { return _table->currentRow(); }
    QSet<int> selectedItems() const;

private:
    QTableWidget *_table{nullptr};
};



#endif //TABLE_HPP
