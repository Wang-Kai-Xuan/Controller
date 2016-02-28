#ifndef ChatBase_H
#define ChatBase_H

#include "ilabel.h"
#include <QWidget>
#include <QAbstractSocket>
#include <QGridLayout>
#include <QByteArray>
#include <QPushButton>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include "common.h"
class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(QWidget *parent = 0);
public:
    QGridLayout * main_glay;
    ILabel * light_lab;
    ILabel * curtain_lab;
    QPushButton * light_btn;
    QPushButton * curtain_btn;
    QPushButton * close_btn;
public:
    void newUI();
    void setUI();
    void setConnect();
    void init();
public:
    QUdpSocket * udpSocket;
    QByteArray sendData;
    QByteArray recvData;
signals:

public slots:
    void onControlLight(void);
    void onControlCurtain(void);
    void onReadMessage(void);
};

#endif // ChatBase_H
