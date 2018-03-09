#include <stdio.h> //C标准库-定义了三个变量类型、一些宏和各种函数来执行输入和输出。
#include <time.h>  //C标准库-定义了四个变量类型、两个宏和各种操作日期和时间的函数。

/**
 * [ 主函数：获取当前系统时间/打印当前时间 ]
 * 
 * @return [ 屏幕打印本地当前时间 ]
 */
int main()
{

    time_t t;
    struct tm * lt;
    //getchar();                                     //获取键盘输入
    time (&t);                                       //获取Unix时间戳。
    lt = localtime (&t);                             //转为时间结构。
    printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
    // getchar();                                    //获取键盘输入
    return 0;
}