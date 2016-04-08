#ifndef COMMON
#define COMMON  

#define iport 12060
/**
 * @brief The COMMAND enum
 * 用作发送接收数据类的标识
 */
enum COMMAND{
    COMMAND_NULL,LIGHT_OPEN,LIGHT_CLOSE,CURTAIN_OPEN,CURTAIN_CLOSE
};

#endif // COMMON
