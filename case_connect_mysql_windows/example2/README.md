# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 连接mysql数据库，执行SQL命令


## 二、代码说明

### 1、 目录结构

~~~

./                                              当前目录( case_hello_world )
├─ compile_start.bat                            windows环境编译脚本
├─ vendor                                       需要包含的第三方库
│  ├─ mysql-connector-c-noinstall-6.0.2-win32
│  └─ ...
├─ connect_mysql.c                              主函数代码
├─ connect_mysql.exe                            编译后生成的可执行文件（windows）
├─ write_log.c                                  自己编写的程序运行日志记录函数
├─ write_log.h                                  自己编写的程序运行日志记录函数头文件
└─ README.md                                    当前自述文件

~~~



### 2、 使用说明

#### 2.1、 步骤

+ 0、安装环境MinGW工具包，下载地址是http://prdownloads.sourceforge.net/mingw/mingw-utils-0.2.tar.gz?download
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

+ 1、到mysql官网下载 C的mysql库http://dev.mysql.com/downloads/connector/c/6.0.html 下载Connector/C

+ 2、本次下载 [mysql-connector-c-noinstall-6.0.2-win32](https://dev.mysql.com/downloads/file/?id=377978)（注：64位老编译不过去，这个问题暂放，按网上说的改下了32位的）

+ 3、用MinGW GCC编译运行一个连接MySQL数据库的程序时遇到错误：undefined reference to 之类的错误，需要先执行一些操作

    + a、在解压后mysql-connector-c-noinstall-6.0.2-win32开发包的lib目录下，即libmysql.lib和libmysql.dll的所在目录，命令行运行 reimp -d libmysql.lib  ,会得到导出文件LIBMYSQL.def

    + b、然后，再在此目录还是命令行运行MinGW GCC本身自带的命令 dlltool -k -d libmysql.def -l libmysql.a , 得到我们最后需要链接的库文件libmysql.a。
    
    + c、在项目更目录下新建vendor目录用来存放第三方包，将上一步的完成后的整个文件夹mysql-connector-c-noinstall-6.0.2-win32 移动到新建的vendor目录里，再在vendor同级目录新建我们的测试文件connect_mysql.c write_log.c write_log.h：

      + d、再在源文件所在路径运行编译命令：gcc  -c  write_log.c 和 gcc write_log.o connect_mysql.c   -o connect_mysql  -L ./vendor/mysql-connector-c-noinstall-6.0.2-win32/lib -l ./vendor/mysql-connector-c-noinstall-6.0.2-win32/lib/libmysql ,生成可执行文件

      + e、将lib目录下的libmysql.dll拷贝一份到vendor 同级目录下( 不然编译完，运行connect_mysql.exe时会提示找不到dll)

> 注：此git在gitignore设置了文件过滤，没有提交dll，.a,.exe等，请到 src资源包里或自行下载完整的包


#### 2.2 详细步骤

+ 1、 编译生成可执行文件
    + 方法a：打开命令窗口，切换到当前目录, 执行 gcc -Iinclude -L ./vendor/mysql-connector-c-noinstall-6.0.2-win32/lib write_log.o connect_mysql.c -l ./mysql-connector-c-noinstall-6.0.2-win32/lib/libmysql  -o connect_mysql

    + 方法b：执行写好的编译脚本 compile_start.bat（windows）


+ 2、 运行可执行文件
    + windows系统： 打开命令窗口，切换到当前目录, 执行 connect_mysql.exe



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

> 参考资料：[Sublime Text 3调试运行 CC++ 程序 教程，原创。](https://tieba.baidu.com/p/3481924547?red_tag=3421180941)

+ GCC编译器命令说明
    + -I   (注意是大写的i)
        * 要利用-I来显式指定头文件的所在地，  -I就是用来干这个的：告诉gcc去哪里找头文件。

    + -L(注意是大写的L)
        * 是用来告诉gcc去哪里找库文件

    + -l （注意是小写的L）
        * -l的作用就是用来指定具体的静态库、动态库是哪个


### 2、Linux系统环境使用说明


## 四、开发日志


## 五、参考资料

+ [[转]Windows下用GCC连接MySQL数据库](http://www.cnblogs.com/yizhe/articles/3825877.html)
+ [mysql-connector-c-noinstall-6.0.2-win32](https://dev.mysql.com/downloads/file/?id=377978)

+ [GCC编译器中的-I -L -l 选项。](https://blog.csdn.net/qq_32790673/article/details/52873496)