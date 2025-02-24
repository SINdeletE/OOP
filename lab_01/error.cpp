#include <cstddef>
#include <QObject>
#include <QMessageBox>

#include "error.h"

void error_msg(error_t error)
{
    switch (error)
    {
    case ERR_FILE_NOT_FOUND:
        QMessageBox::critical(NULL, "Ошибка", "Такого файла не существует");

        break;
    case ERR_FILE_INVALID_STRUCTURE:
        QMessageBox::critical(NULL, "Ошибка", "Файл имеет неправильную структуру");

        break;
    case ERR_FILE_INVALID_DATA:
        QMessageBox::critical(NULL, "Ошибка", "Файл содержит некорретные данные");

        break;
    case ERR_POINTS_INVALID_ALLOC:
        QMessageBox::critical(NULL, "Ошибка", "Недостаточно памяти для дальнейшего выполнения программы");

        break;
    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка");

        break;
    }
}
