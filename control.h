#ifndef ChatBase_H
#define ChatBase_H

#include "header.h"
class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(QWidget *parent = 0);
public:
    QGridLayout * layout_pc;
    QLabel * lab_light;
    QLabel * lab_curtain;
    QLabel * lab_ip;
    QPushButton * btn_light;
    QPushButton * btn_curtain;
    QPushButton * btn_close;
    QPushButton * btn_clear;
    QTextEdit * text_show_msg;
    qint8 changColor;
    QMap<Command,QString> context;
public:
    /**
     * @brief newUI
     * new 新控件
     */
    void newComponent();
    /**
     * @brief setUI
     * 设置UI
     */
    void setComponent();
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
    QTcpSocket * tcpSocket;
    /**
     * @brief sendData
     * 保存发送的数据
     */
    QString sendData;
    /**
     * @brief recvData
     * 保存接收到的数据
     */
    QByteArray recvData;

    QString getLocalIP();
    void pcLayout();
    void sendMessage(QString str);
    
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
    void onUpdataConnectStatus();
};

#endif // ChatBase_H
