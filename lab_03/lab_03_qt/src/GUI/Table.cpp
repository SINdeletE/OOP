//
// Created by nuelex on 22/05/25.
//

#include "Table.hpp"

#include "../Exceptions/GUI/TableException.hpp"

void Table::addItem(size_t id, const QString &object_name)
{
    if (_table == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTable_no_table(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    QTableWidgetItem *item = new QTableWidgetItem("");
    if (item == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTable_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

Table::Table(QTableWidget* table)
{
    if (table == nullptr)
}


