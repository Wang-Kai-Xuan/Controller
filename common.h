#ifndef COMMON
#define COMMON  

#define iport 8080
/**
 * @brief The COMMAND enum
 * 用作发送接收数据类的标识
 */
enum COMMAND{
    COMMAND_NULL = '0',LIGHT_OPEN,LIGHT_CLOSE,CURTAIN_OPEN,CURTAIN_CLOSE
};

#endif // COMMON
