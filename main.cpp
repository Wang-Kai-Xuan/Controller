#include "control.h"
#include <QApplication>
#include <QStyleFactory>
/**
 * @brief main  程序的人口
 * @param argc
 * @param argv
 * @return
 *
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Control w;
    w.setStyle(QStyleFactory::create("fusion"));
    w.show();

    return a.exec();
}
