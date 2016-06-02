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
#include <QTextEdit>
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
    ILabel * lab_ip;
    QPushButton * light_btn;
    QPushButton * curtain_btn;
    QPushButton * close_btn;
    QPushButton * clear_msg;
    QTextEdit * show_msg;
public:
    /**
     * @brief newUI
     * new 新控件
     */
    void newUI();
    /**
     * @brief setUI
     * 设置UI
     */
    void setUI();
    /**
     * @brief setConnect
     * 连接信号和槽
     */
    void setConnect();
    /**
     * @brief init
     * 初始化
     */
    void init();
public:
    QUdpSocket * udpSocket;
    /**
     * @brief sendData
     * 保存发送的数据
     */
    QByteArray sendData;
    /**
     * @brief recvData
     * 保存接收到的数据
     */
    QByteArray recvData;
    QString getLocalIP();
signals:

public slots:
    /**
     * @brief onControlLight
     * 控制电灯的开关
     */
    void onControlLight(void);
    /**
     * @brief onControlCurtain
     * 控制窗帘的拉开、合上
     */
    void onControlCurtain(void);
    /**
     * @brief onReadMessage
     * 读取消息
     */
    void onReadMessage(void);
    void onClearMessage();
};

#endif // ChatBase_H
