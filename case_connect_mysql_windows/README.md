# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 连接mysql数据库，执行SQL命令


## 二、代码说明

### 1、 目录结构

~~~

./                                          当前目录 
├─ example1                                 例子1
├─ example2                                 研究了在gcc如何引用mysql官方的的连接库
└─ README.md                  当前自述文件

~~~



> 注:
+ 例子1是较早之前的学习时遗留的，那是没养成记录的习惯，后来整理时，想不出来完整的配置过程，只好先保存完整代码,后来版本研究出配置记录去除

+ 例子2，研究本记录gcc引用第三方库时的编译命令用法

+ 此git在gitignore设置了文件过滤，没有提交dll，.a,.exe等，请到 src资源包里或自行下载完整的包


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


### 2、Linux系统环境使用说明


## 四、开发日志


## 五、参考资料



