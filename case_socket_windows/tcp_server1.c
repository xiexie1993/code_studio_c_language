#include <stdio.h>
#include <winsock2.h>



/**
 * socket服务端，等待客户端来连接
 * 
 */
int main(void)
{
        int len = 0;
        WSADATA         wd;
        int ret = 0;
        SOCKET s,c;
        char sendBuf[1000]="", recvBuf[1000]="";
        SOCKADDR_IN saddr, caddr;
        ret = WSAStartup(MAKEWORD(2,2),&wd);  /*1.初始化操作*/
        
        if(ret != 0)
        {
                return 0;
        }
        if(HIBYTE(wd.wVersion)!=2 || LOBYTE(wd.wVersion)!=2)
        {
                // printf("初始化失败");
                printf("\n Initialization failed ! \n");
                WSACleanup();
                return 1;
        }
        else
        {
                // printf("初始化成功");
                printf("\n Initialization successful ! \n");
        }
        
        /*2.创建服务端socket*/
        s = socket(AF_INET, SOCK_STREAM, 0);
        
        /*3.设置服务端信息*/
        saddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
        saddr.sin_family = AF_INET; /*协议类型*/
        saddr.sin_port = htons(8888);
        
        printf("\n socket port : 8888 ! \n");

        /*4.绑定在本地端口*/
        bind(s, (SOCKADDR *)&saddr, sizeof(SOCKADDR));
        
        /*5.监听端口*/
        listen(s,5);
        
        len = sizeof(SOCKADDR);
        
        while(1)
        {
                /*6.等待客户端连接，会阻塞在此处，直到有客户端连接到来。*/
                c = accept(s, (SOCKADDR*)&caddr, &len);
                
                // sprintf(sendBuf, "这是服务端 ，您的IP 地址为：%s\n", inet_ntoa(caddr.sin_addr));
                sprintf(sendBuf, "\n This is server , Your IP is : %s\n", inet_ntoa(caddr.sin_addr));
                
                /*7.发送数据到客户端*/
                send(c, sendBuf, strlen(sendBuf)+1, 0);
                
                /*8.接受客户端的返回*/
                recv(c, recvBuf, 1000, 0);
                
                /*9.打印出客户端发送来的数据*/
                printf("%s\n", recvBuf);
                
                /*10.如果不再跟这个客户端联系，就关闭它*/
                closesocket(c);
        }
        /*如果有退出循环的条件，这里还需要清除对socket库的使用*/
        /* WSACleanup();*/
        return 0;
}