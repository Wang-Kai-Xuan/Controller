#ifndef COMMON
#define COMMON  

#include <QWidget>
#include <QAbstractSocket>
#include <QGridLayout>
#include <QByteArray>
#include <QPushButton>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTextEdit>
#include <QLabel>
#include <QMap>

#define iport 11080
#define ip "192.168.0.99"
#define ip_test "127.0.0.1"

/**
 * @brief The COMMAND enum
 * 用作发送接收数据类的标识
 */
enum Command{
    COMMAND_NULL = '0',LIGHT_OPEN,LIGHT_CLOSE,CURTAIN_OPEN,CURTAIN_CLOSE
};

#endif // COMMON
