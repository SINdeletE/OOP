#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}
