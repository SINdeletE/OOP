#include <cstddef>
#include <QObject>
#include <QMessageBox>

#include "error.h"

void error_msg(err_t error)
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
        case ERR_LINKS_INVALID_ALLOC:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти под: связи");

            break;
        case ERR_LINKS_SAME_LINKS:
            QMessageBox::critical(NULL, "Ошибка", "Имеются одинаковые связи");

            break;
        case ERR_LINKS_INVALID_LINK:
            QMessageBox::critical(NULL, "Ошибка", "Предоставленные связи некорректны");

            break;
        case ERR_POINTS_INVALID_ALLOC:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти под: точки");

            break;
        case ERR_POINTS_SAME_POINTS:
            QMessageBox::critical(NULL, "Ошибка", "Имеются одинаковые точки");

            break;
        case ERR_MODEL_IS_EMPTY:
            QMessageBox::critical(NULL, "Ошибка", "Модель пуста");

            break;
        case ERR_ACTION_NO_MODEL:
            QMessageBox::critical(NULL, "Ошибка", "Нет модели для выполнения преобразований");

            break;
        case ERR_ACTION_INVALID_ENTERED_DATA:
            QMessageBox::critical(NULL, "Ошибка", "Неверные входные данные");

            break;
        default:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка");
    }
}
