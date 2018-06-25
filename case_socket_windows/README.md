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

## 三、环境搭建

### 1、Windows系统环境使用说明

+ 环境搭建方式一(MinGW)：
    * step1：下载mingw-get-0.6.2-mingw32-beta-20131004-1-bin.zip：https://sourceforge.net/projects/mingw/?source=typ_redirect
    * step2：解压到c:\mingw,
    * step3：cmd输入： cd c:\mingw\bin
    * step4：更新，输入： mingw-get upgrade
    * step5：安装gcc g++， 输入：mingw-get install gcc g++
    * step6：添加环境变量，
        + 1. 解压MinGW至目标目录，本次安装的解压目录为C:\MinGW
        + 2. 设置环境变量。右击我的电脑，属性-->高级-->环境变量。
              * 1) 在系统环境变量PATH里添加C:\MinGW\bin（如果里面还有其他的变量，记得添加英文分号;）
              * 2) 新建LIBRARY_PATH变量，在值中加入C:\MinGW\lib。（标准库位置）
              * 3) 新建C_INCLUDEDE_PATH变量，值设为C:\MinGW\include。
              * PS：
                  + 以上环境变量中的具体路径请根据本人实际的MinGW安装路径进行设置
                  + 之后在cmd输入g++ -v检查添加是否成功


### 2、Linux系统环境使用说明


## 四、开发日志


## 五、参考资料

+ [用C语言实现的Socket通信](https://blog.csdn.net/a1028203709/article/details/78235416)
+ [c语言中undefined reference to ""怎么解决](https://zhidao.baidu.com/question/2053866215470727467.html)
+ [c 网络与套接字socket](https://www.cnblogs.com/machao/p/5654661.html)
+ [MinGW WinSockets 编程](https://blog.csdn.net/zhangxiao93/article/details/47291783)
+ [Sublime Text 3调试运行 CC++ 程序 教程，原创。](https://tieba.baidu.com/p/3481924547?red_tag=3421180941)