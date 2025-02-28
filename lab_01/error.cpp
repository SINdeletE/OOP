#include <cstddef>
#include <QObject>
#include <QMessageBox>

#include "error.h"

void error_msg(err_t error)
{
    if (error == ERR_FILE_NOT_FOUND)
        QMessageBox::critical(NULL, "Ошибка", "Такого файла не существует");
    else if (error == ERR_FILE_INVALID_STRUCTURE)
        QMessageBox::critical(NULL, "Ошибка", "Файл имеет неправильную структуру");
    else if (error == ERR_FILE_INVALID_DATA)
        QMessageBox::critical(NULL, "Ошибка", "Файл содержит некорретные данные");
    else if (error == ERR_LINKS_INVALID_ALLOC)
        QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти под: связи");
    else if (error == ERR_LINKS_SAME_LINKS)
        QMessageBox::critical(NULL, "Ошибка", "Имеются одинаковые связи");
    else if (error == ERR_LINKS_INVALID_LINK)
        QMessageBox::critical(NULL, "Ошибка", "Предоставленные связи некорректны");
    else if (error == ERR_POINTS_INVALID_ALLOC)
        QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти под: точки");
    else if (error == ERR_POINTS_SAME_POINTS)
        QMessageBox::critical(NULL, "Ошибка", "Имеются одинаковые точки");
    else if (error == ERR_MODEL_IS_EMPTY)
        QMessageBox::critical(NULL, "Ошибка", "Модель пуста");
    else if (error == ERR_ACTION_NO_MODEL)
        QMessageBox::critical(NULL, "Ошибка", "Недостаточно памяти для дальнейшего выполнения программы");
    else if (error == ERR_ACTION_INVALID_ENTERED_DATA)
        QMessageBox::critical(NULL, "Ошибка", "Неверные входные данные");
    else
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка");
}

// {
//     ERR_NONE = 0,

//     ERR_FILE_NOT_FOUND,
//     ERR_FILE_INVALID_STRUCTURE,
//     ERR_FILE_INVALID_DATA,

//     ERR_LINKS_INVALID_ALLOC,
//     ERR_LINKS_SAME_LINKS,
//     ERR_LINKS_INVALID_LINK,

//     ERR_POINTS_INVALID_ALLOC,
//     ERR_POINTS_SAME_POINTS,

//     ERR_MODEL_IS_EMPTY,

//     ERR_ACTION_NO_MODEL
// };
