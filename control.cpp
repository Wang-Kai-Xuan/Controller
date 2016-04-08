#include "control.h"
#include <QTextCodec>
void Control::newUI()
{
    main_glay = new QGridLayout;
    light_btn = new QPushButton(tr("打开(&L)"));
    curtain_btn = new QPushButton(tr("打开(&C)"));
    close_btn = new QPushButton(tr("退出(&E)"));
    light_lab = new ILabel;
    curtain_lab = new ILabel;
    udpSocket = new QUdpSocket;
}

void Control::setUI()
{
    light_lab->setText(tr("电灯开关:"));
    curtain_lab->setText(tr("窗帘开关:"));

    /*这些配置在Android上显示不完美*/
//    light_btn->setFixedSize(120,40);
//    light_lab->setFixedSize(120,40);
//    curtain_btn->setFixedSize(120,40);
//    curtain_lab->setFixedSize(120,40);
//    close_btn->setFixedSize(120,40);

    main_glay->addWidget(light_lab,0,0,1,1);
    main_glay->addWidget(light_btn,0,1,1,1);
    main_glay->addWidget(curtain_lab,1,0,1,1);
    main_glay->addWidget(curtain_btn,1,1,1,1);
    main_glay->addWidget(close_btn,2,0,1,1);

    this->setLayout(main_glay);
    this->setWindowIcon(QIcon(":/new/pic/pic/control.png"));
    this->resize(300,400);
    this->setWindowTitle(tr("控制台"));
}

void Control::setConnect()
{
    connect(close_btn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(light_btn,SIGNAL(clicked(bool)),this,SLOT(onControlLight()));
    connect(curtain_btn,SIGNAL(clicked(bool)),this,SLOT(onControlCurtain()));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onReadMessage()));
}

void Control::init()
{
    if(!udpSocket->bind(iport,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint)){
        qDebug()<<"绑定端口失败";
    }
}

void Control::onControlLight()
{
    sendData.clear();
    if(light_btn->text() == tr("打开(&L)")){
        light_btn->setText(tr("关闭(&L)"));
        sendData.append(LIGHT_OPEN);
        sendData.append(COMMAND_NULL);
    }else{
        light_btn->setText(tr("打开(&L)"));
        sendData.append(LIGHT_CLOSE);
        sendData.append(COMMAND_NULL);
    }
    udpSocket->writeDatagram(sendData.data(),sendData.size(),QHostAddress::Broadcast,iport);
    qDebug()<<"sendData="<<sendData;
}

void Control::onControlCurtain()
{
    sendData.clear();
    if(curtain_btn->text() == tr("打开(&C)")){
        curtain_btn->setText(tr("关闭(&C)"));
        sendData.append(CURTAIN_OPEN);
        sendData.append(COMMAND_NULL);

    }else{
        curtain_btn->setText(tr("打开(&C)"));
        sendData.append(CURTAIN_CLOSE);
        sendData.append(COMMAND_NULL);
    }
    udpSocket->writeDatagram(sendData.data(),sendData.size(),QHostAddress::Broadcast,iport);
    qDebug()<<"sendData="<<sendData;
}

void Control::onReadMessage()
{
    recvData.clear();
    while(udpSocket->hasPendingDatagrams()){
        recvData.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(recvData.data(),recvData.size());
    }
    qDebug()<<"recvData="<<recvData;
}

Control::Control(QWidget *parent) : QWidget(parent)
{
    newUI();
    setUI();
    setConnect();
    init();
}
