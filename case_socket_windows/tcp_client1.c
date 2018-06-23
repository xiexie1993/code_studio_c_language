#include <stdio.h>
#include <winsock2.h>

/**
 * socket客户端，连接服务端，发送条消息，接收消息
 * 
 */
int main(void)
{
        WSADATA         wd;
        int ret = 0;
        SOCKET c;
        char recvBuf[1000]="", sendBuf[1000]="";
        SOCKADDR_IN saddr;
        ret = WSAStartup(MAKEWORD(2,2),&wd);  /*1.初始化操作*/
        
        if(ret != 0)
        {
                return 0;
        }
        
        if(HIBYTE(wd.wVersion)!=2 || LOBYTE(wd.wVersion)!=2)
        {
                // printf("初始化失败");
                printf("Initialization failed !");
                WSACleanup();
                return 1;
        }
        else
        {
                // printf("初始化成功");
                printf("Initialization successful !");
        }
        
        /*2.创建客户端socket*/
        c = socket(AF_INET, SOCK_STREAM, 0);
        
        /*3.定义要连接的服务端信息*/
        saddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(8888);
        
        /*4.连接服务端*/
        connect(c, (SOCKADDR*)&saddr, sizeof(SOCKADDR));
        recv(c, recvBuf, 1000, 0);

        printf("\n MSG from the Server : %s\n", recvBuf);
        
        printf("\n Information sent to the  Server :");

        sprintf(sendBuf, "\n  Hello. I'm a client !");

        printf("\n %s \n",sendBuf);

        send(c, sendBuf, strlen(sendBuf)+1, 0);
        
        closesocket(c);
        WSACleanup();
        
        return 0;
}