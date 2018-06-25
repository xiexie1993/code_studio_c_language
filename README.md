# C语言学习与练习记录项目

## 一、概述



###  1.1、 项目阐述

+ 学习C语言的代码记录
+ 积累代码实例

###  1.1 编写目的

+ 为项目的开发设计的依据与指导
+ 为参与该项目的编程人员提供依据
+ 为修改、维护提供条件
+ 好记性不如烂笔头

#### 1.1.2 读者对象

+ 项目开发人员，特别是编程人员
+ 软件维护人员
+ 技术管理人员
+ 开发者

####  1.1.3 注意事项

+ 该文档采用 markdown 编写规范，建议使用markdownPad查看和修改

## 二、项目说明

### 1、目录概述

~~~

./                            根目录
├─ src                                  第三方包/库
│  ├─ ...
│  └─ README.md                         当前目录的自述文件
├─ case_xxx1                            实例1：xxx
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件
├─ case_xxx1                            实例1：xxx
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件
├─ ...                                  更多例子(欢迎创建)
└─ README.md                            自述文件

~~~

### 2、详细目录

~~~

./                            根目录
├─ src                                  第三方包/库
│  ├─ ...                               
│  ├─ installation_package              搭建环境的安装包（与项目运行时无关，可删除）
│  └─ README.md                         当前目录的自述文件
├─ case_hello_world                     实例1：打印hello，world（用来测试环境）
│  ├─ ...
│  └─ README.md                         当前实例的自述文件
├─ case_print_now_time                  实例2：打印本地当前时间
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件
├─ case_write_log_file                  实例3：打开本地文件写入文字
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件  
├─ case_print_system_boot_time          实例3：打印系统开机时间
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件 
├─ case_socket_windows                  实例4：c语言socket例子（windows）
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件 
├─ case_game_snake                      实例5：c语言贪吃蛇小游戏例子
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件 
├─ case_pthread                         实例6：c语言线程例子
│  ├─ ...                               实例代码
│  └─ README.md                         当前实例的自述文件 
├─ ...                                  更多例子(欢迎创建)
└─ README.md                            自述文件

~~~


### 3、开发规范

+ 由于Windows不区分大小写,而linux区分大小写，编写时请注意大小写统一


## 三、环境搭建

### 1、Windows系统C编程环境

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

### 2、Linux系统C编程环境



## 四、技巧与工具

### 1、 cmake环境搭建

### （一）、windows系统下cmake环境

+ 1、安装Cmake
    * 下载资源包，地址：https://cmake.org/download/ （以下方式选择其中一种安装即可）
    * a、安装包安装安装
          + step1：下载“ .msi ”文件。链接：https://cmake.org/download/
    * b、二进制包安装
          + step1：下载“.zip”文件。链接：https://cmake.org/download/
          + step2：解压zip文件。
          + step3：在解压后的文件中找到bin->cmake.exe,例如：它的路径为：“C:\Software\cmake-3.12.0-rc1-win64-x64\bin”。
          + step4：给cmake.exe添加环境变量。
                * (a) 右键“我的电脑”，选择“属性”，进入高级系统设置。
                * (b) 点击“环境变量”。
                * (c) 在“系统变量”下选择“path”进入“编辑”，然后选择“新建”，添加step4中的路径即可。

+ 2、安装Visual Studio

+ 2、导入项目
    a、将项目导入Visual Studio
        * step1、使用cmd进入项目目录
        * step2、执行 cmake CMakeLists.txt,等待生成相关文件 XXX.sln 等文件
        * step3、打开 Visual Studio 菜单栏--> 文件 --> 打开 --> 项目/解决方案(Ctrl+Shift+O),选择第二步生成的文件

+ 3、编译生成可执行文件
        

+ 本部分参考资料：
    * [CMakeLists入门学习笔记](https://blog.csdn.net/lee_j_r/article/details/60873672)
    * [CMakeLists 的使用，大型工程使用cmake 的构件过程](https://blog.csdn.net/xuheazx/article/details/51980651)
    * [转:CMake安装和使用](https://www.cnblogs.com/skyofbitbit/p/3699968.html)
    * [windows下使用cmake（转）](https://blog.csdn.net/sunyuhua_keyboard/article/details/78716831)
    * [windows 下cmake的安装+使用 教程](https://blog.csdn.net/liyuebit/article/details/77092723)
    * [基于windows下使用CMake和VS2013编译OpenCV的环境搭建](https://blog.csdn.net/jxqjxz/article/details/50678355)
    * [在Windows下使用CMake+MinGW搭建C/C++编译环境](https://blog.csdn.net/jxqjxz/article/details/50678355)
    * [使用CMake生成sln项目和VS工程遇到的问题](https://blog.csdn.net/zyh821351004/article/details/44061647)


> + 本部分问题及解决记录

---
问题：'nmake' 不是内部或外部命令，
    描述：使用的cmd是普通的cmd！
    解决：
      方式一：使用Visual Studio自带的cmd。
      方式一：将Visual Studio的命令执行文件目录加入系统环境变量的配置（使得普通的cmd也能使用）。
              例：在"我的电脑"－>右键属性—>高级－>环境变量－>PATH，添加 C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin

---
问题：程序无法启动ALL_BUILD 拒绝访问
    描述：在Visual Studio中执行
    解决办法：
        方式一：移除项目中的ALL_BUILD（）

    本部分参考资料：
    +[程序无法启动ALL_BUILD 拒绝访问](https://blog.csdn.net/jyl1999xxxx/article/details/50627600)



## 四、开发日志

>时间：2018-03-08 22:03:11
>>创建项目模板
---
>
>>





## 五、参考资料

