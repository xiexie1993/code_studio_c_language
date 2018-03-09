# C语言学习与练习记录项目

## 一、本例子说明

### 本例子代码功能说明

+ 打开本地文件写入文字


## 二、代码说明

### 1、 目录结构

<pre><code>

./                            当前目录( case_write_log_file )
├─ compile_start.bat          windows环境编译脚本
├─ makefile                   linux环境编译脚本
├─ main.c                     主函数代码
├─ subfunction.h              头文件
├─ subfunction.c              头文件对应的函数原型
├─ log_xxxx-xx-xx.txt         根据当前日期生成文本文件
├─ write_log_file.exe         编译后生成的可执行文件（windows）
└─ README.md                  当前自述文件

</code></pre>

### 2、 使用说明

#### 2.1、 步骤总纲

+ 1、 编译生成可执行文件
+ 2、 运行可执行文件

#### 2.2 详细步骤

+ 1、 编译生成可执行文件
    + 方法a：打开命令窗口，切换到当前目录, 按顺序执行以下命令 
        + gcc  -c  main.c
        + gcc  -c  subfunction.c
        + gcc main.o  subfunction.o -o write_log_file
        + 注：执行完会先生成 main.o、subfunction.o 在生成 write_log_file.exe

    + 方法b：
       + 执行写好的编译脚本 compile_start.bat（windows）
       + 执行写好的编译脚本 （linux）

+ 2、 运行可执行文件
    + windows系统： 打开命令窗口，切换到当前目录, 执行 write_log_file.exe 则会生成log_xxxx-xx-xx.txt 并且往里面写入字符串
    + linux系统：   打开命令窗口，切换到当前目录, 执行 ./write_log_file 

## 三、环境搭建

### 1、Windows系统环境使用说明


### 2、Linux系统环境使用说明


## 四、开发日志

---
>  时间： 2018-03-08 22:58:56
>> 创建第一版


