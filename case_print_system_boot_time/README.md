# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 打印系统开机时间


## 二、代码说明

### 1、 目录结构

<pre><code>

./                            当前目录( case_print_system_boot_time )
├─ compile_start.bat               windows环境编译脚本
├─ makefile                        Linux环境编译脚本
├─ main_linux.c                    linux主函数代码
├─ main_windos.c                   windows主函数代码
├─ print_system_boot_time          编译后生成的可执行文件（ linux ）
├─ print_system_boot_time.exe      编译后生成的可执行文件（ windos ）
└─ README.md                       当前自述文件

</code></pre>

### 2、 使用说明

#### 2.1、 步骤总纲

+ 1、 编译生成可执行文件
+ 2、 运行可执行文件

#### 2.2 详细步骤

+ 1、 编译生成可执行文件（ windows ）
    + 方法a：打开命令窗口，切换到当前目录, 执行 gcc main_windows.c -o print_system_boot_time
    + 方法b：执行写好的编译脚本 compile_start.bat（windows）

+ 2、 编译生成可执行文件（ Linux ）
    + 方法A：打开命令窗口，切换到当前目录, 执行 gcc main_linux.c -o print_system_boot_time
    + 方法B：执行写好的编译脚本 makefile（ Linux ） 注：设置可执行 sudo chmod 755 ./makefile


+ 3、 运行可执行文件
    + windows系统： 打开命令窗口，切换到当前目录, 执行 .\print_system_boot_time.exe 
    + linux系统：   打开命令窗口，切换到当前目录, 执行 ./print_system_boot_time 

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

---
>  时间： 2018-03-08 22:58:56
>> 创建第一版


