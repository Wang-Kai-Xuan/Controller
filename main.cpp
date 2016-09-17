#include "control.h"
#include <QApplication>
#include <Python.h>
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

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    if(Py_IsInitialized())
    {
        qDebug()<<"init succeessful!";
    }else
    {
        qDebug()<<"init failure!";
    }
    PyObject* pModule = PyImport_ImportModule("voice");
    if (!pModule) {
        printf("Cant open python file!\n");
        return -1;
      }
    PyObject* pFunc= PyObject_GetAttrString(pModule,"hello");
    if(!pFunc){
      qDebug()<<"Get function hello failed";
    }
    PyObject_CallFunction(pFunc,NULL);
    Py_DECREF(pFunc);
    qDebug()<<"Wangkaixuan";
    Py_Finalize();
    w.show();

    return a.exec();
}
