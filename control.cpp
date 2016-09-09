#include "control.h"
void Control::newComponent()
{
    layout_pc = new QGridLayout;
    btn_light = new QPushButton(tr("打开(&L)"));
    btn_curtain = new QPushButton(tr("打开(&C)"));
    btn_close = new QPushButton(tr("退出(&E)"));
    btn_clear = new QPushButton(tr("清除(&F)"));
    lab_light = new QLabel("电灯开关:");
    lab_ip = new QLabel;
    lab_curtain = new QLabel("窗帘开关:");
    tcpSocket = new QTcpSocket;
    text_show_msg = new QTextEdit;
}

void Control::pcLayout()
{
    layout_pc->addWidget(lab_ip,0,0,1,1);
    layout_pc->addWidget(btn_close,1,0,1,1);
    layout_pc->addWidget(btn_clear,1,1,1,1);
    layout_pc->addWidget(lab_light,2,0,1,1);
    layout_pc->addWidget(btn_light,2,1,1,1);
    layout_pc->addWidget(lab_curtain,3,0,1,1);
    layout_pc->addWidget(btn_curtain,3,1,1,1);
    layout_pc->addWidget(text_show_msg,4,0,1,2);
}

void Control::setComponent(){
    pcLayout();
    this->setLayout(layout_pc);
    this->setWindowIcon(QIcon(":/new/pic/pic/control.png"));
    this->resize(300,400);
    this->setWindowTitle(tr("控制台"));
}

void Control::setConnect()
{
    connect(btn_close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(btn_light,SIGNAL(clicked(bool)),this,SLOT(onControlLight()));
    connect(btn_clear,SIGNAL(clicked(bool)),this,SLOT(onClearMessage()));
    connect(btn_curtain,SIGNAL(clicked(bool)),this,SLOT(onControlCurtain()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadMessage()));
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(onUpdataConnectStatus()));
}

void Control::init(){
    tcpSocket->connectToHost(ip_test,iport);
    lab_ip->setText(QString("网络地址:")+getLocalIP());
    context.insert(LIGHT_OPEN, QString("电灯打开"));
    context.insert(LIGHT_CLOSE, QString("电灯关闭"));
    context.insert(CURTAIN_OPEN, QString("窗帘打开"));
    context.insert(CURTAIN_CLOSE, QString("窗帘关闭"));
}

void Control::onControlLight()
{
    sendData.clear();
    if(btn_light->text() == tr("打开(&L)")){
        btn_light->setText(tr("关闭(&L)"));
        sendData.append(LIGHT_OPEN);
    }else{
        btn_light->setText(tr("打开(&L)"));
        sendData.append(LIGHT_CLOSE);
    }
    sendMessage(sendData);
}

void Control::onControlCurtain()
{
    sendData.clear();
    if(btn_curtain->text() == tr("打开(&C)")){
        btn_curtain->setText(tr("关闭(&C)"));
        sendData.append(CURTAIN_OPEN);

    }else{
        btn_curtain->setText(tr("打开(&C)"));
        sendData.append(CURTAIN_CLOSE);
    }
    sendMessage(sendData);
}
void Control::onClearMessage()
{
    text_show_msg->clear();
    QByteArray str = "this is a test string";
    sendMessage(str);
}

void Control::onUpdataConnectStatus()
{
    text_show_msg->setText("connected!");
}

void Control::onReadMessage()
{
    changColor++;
    recvData.clear();

    text_show_msg->append(context[recvData.toInt()+'0']);
    if(changColor%2)
        text_show_msg->setTextColor("red");
    else
        text_show_msg->setTextColor("black");
}

void Control::sendMessage(QString str)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion (QDataStream::Qt_4_7);
    out << (quint16) 0;
    out << str;
    out.device ()->seek (0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

Control::Control(QWidget *parent) : QWidget(parent)
{
    newComponent();
    init();
    setComponent();
    setConnect();
}

QString Control::getLocalIP()
{
    QList<QHostAddress> ipList = QNetworkInterface::allAddresses();
    foreach(QHostAddress ipItem, ipList)
    {
        //只显示以192开头的IP地址
        if(ipItem.protocol()==QAbstractSocket::IPv4Protocol&&ipItem!=QHostAddress::Null
                &&ipItem!=QHostAddress::LocalHost&&ipItem.toString().left(3)=="192")
        {
            return ipItem.toString();
        }
    }
    return 0;
}
