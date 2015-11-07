#include "pixelepsy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixelepsy w;
    w.show();

    return a.exec();
}
