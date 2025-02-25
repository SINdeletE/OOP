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
    else if (error == ERR_POINTS_INVALID_ALLOC)
        QMessageBox::critical(NULL, "Ошибка", "Недостаточно памяти для дальнейшего выполнения программы");
    else
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка");
}
