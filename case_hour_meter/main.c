#include <stdio.h>  //C标准库-stdio .h 头文件定义了三个变量类型、一些宏和各种函数来执行输入和输出。

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
//#include <time.h>


// 自定义信号处理函数

void fa(int signo)
{
    printf("捕获到信号%d\n", signo);
}

/**
 * [ 主函数：计时器 ]
 * 
 * @return [  ]
 */
int main(void)
{

    /* 我的第一个 C 程序 : 打印 hello,world! */
    // getchar();                 //获取键盘输入
    printf("Hour Meter! \n");   //屏幕输出Hello, World!并换行
    // getchar();                 //获取键盘输入
    int SIGALRM
    // 使用signal函数设置对信号SIGALRM自定义
    signal(SIGALRM,fa); //linux下的应用代码，在linux系统下可以编译通过，windows不支持这个定时信号和报警函数
    // 使用结构体变量并初始化
    struct itimerval timer;
    // 设置计时器的间隔时间
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec   = 230000;
    // 设置计时器的启动时间
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    // setitimer函数设置计时器
    int res = setitimer(ITIMER_REAL,&timer,NULL);
    if(-1 == res)
    {
        perror("setitimer"),exit(-1);
    }
    printf("关闭计时器成功\n");
    getchar();
    return 0;
}
