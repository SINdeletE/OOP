//
// Created by nuelex on 22/05/25.
//

#ifndef TABLE_HPP
#define TABLE_HPP
#include <QTableWidget>


class Table
{
public:
    explicit Table(QTableWidget *table);
    ~Table() = default;

    void setTable(QTableWidget *table) : _table(table) {}
    void addItem(size_t id, const QString& object_name);

private:
    QTableWidget *_table{nullptr};
};



#endif //TABLE_HPP
