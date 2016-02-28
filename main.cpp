#include "control.h"
#include <QApplication>
#include <QStyleFactory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Control w;
    w.setStyle(QStyleFactory::create("fusion"));
    w.show();

    return a.exec();
}
