# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 


## 二、代码说明

### 1、 目录结构

~~~

./                            当前目录( case_socket_windows )
├─ compile_start.bat          windows环境编译脚本
├─ makefile                   linux环境编译脚本
├─ tcp_server1.c              tcp socket 服务端代码例子1
├─ tcp_client1.c              tcp socket 与服务端代码例子1对应的客户端代码例子1
└─ README.md                  当前自述文件

~~~

+ 使用说明：
    * 先执行compile_start.bat，编译生成tcp_server1.exe、tcp_client1.exe
    * 再点击执行tcp_server1.exe，启动服务端监听
    * 最后再打开另外的cmd窗口执行tcp_client1.exe，可看到，服务端接收到消息并打印，客户端窗口也打印了服务端发送来的消息。

## 三、开发日志

## 四、参考资料

+ [用C语言实现的Socket通信](https://blog.csdn.net/a1028203709/article/details/78235416)
+ [c语言中undefined reference to ""怎么解决](https://zhidao.baidu.com/question/2053866215470727467.html)
+ [c 网络与套接字socket](https://www.cnblogs.com/machao/p/5654661.html)
+ [MinGW WinSockets 编程](https://blog.csdn.net/zhangxiao93/article/details/47291783)
+ [Sublime Text 3调试运行 CC++ 程序 教程，原创。](https://tieba.baidu.com/p/3481924547?red_tag=3421180941)