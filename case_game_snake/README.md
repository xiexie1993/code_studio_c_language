# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 贪吃蛇小游戏

## 二、代码说明

### 1、 目录结构

<pre><code>

./                                        当前目录( case_game_snake )
├─ compile_start.bat                      windows环境编译脚本
├─ snake_windows.c                        windows版贪吃蛇代码
├─ intelligent_snake_windows.c            windows版智能贪吃蛇代码
└─ README.md                              当前自述文件

</code></pre>

### 2、 使用说明

#### 2.1、 步骤总纲

+ 1、 编译生成可执行文件
+ 2、 运行可执行文件

#### 2.2 详细步骤

+ 1、 编译生成可执行文件
    + 方法a：打开命令窗口，切换到当前目录, 按顺序执行以下命令 
        + 贪吃蛇代码
            + gcc -c  snake_windows.c
            + gcc snake_windows.o  -o snake
        + 智能贪吃蛇
            + gcc -c  intelligent_snake_windows.c
            + gcc intelligent_snake_windows.o  -o intelligent_snake
        + 注：windows下执行完会先生成 snake_windows.o 、intelligent_snake_windows.o， 再生成 snake.exe、intelligent_snake.exe

    + 方法b：
       + 执行写好的编译脚本 compile_start.bat（windows）
       + 执行写好的编译脚本 （linux）

+ 2、 运行可执行文件
    + windows系统： 打开命令窗口，切换到当前目录, 执行 snake.exe 或 intelligent_snake_windows.exe 
    + linux系统：   打开命令窗口，切换到当前目录, 执行 

>

#### 编译时遇到问题及解决方法记录
snake_linux.c:4:21: 致命错误：windows.h：没有那个文件或目录
解决办法：安装对应缺少的库
+ Ubuntu： sudo apt-get install libncurses5 libncurses5-dev 
+ CentOS： sudo yum install ncurses-devel

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



## 参考资料

+ [贪吃蛇C语言代码](https://blog.csdn.net/sgafpzys/article/details/51180061)
+ [关于centos 5.5 程序中编译出现curses.h不存在问题](https://blog.csdn.net/xumaojun/article/details/6229789)
+ [[错误] curses.h：没有那个文件或目录 编译中断](https://blog.csdn.net/woyaozuo2012/article/details/12208095)
+ [Linux 环境下C语言编译实现贪吃蛇游戏](https://www.linuxidc.com/Linux/2011-08/41375.htm)