#include "GUI/gamewindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    GameWindow w;
    w.show();
    w.UpdateView();
    return a.exec();
}
