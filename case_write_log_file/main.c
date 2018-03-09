#include "subfunction.h"  // 自定义的头文件，

/**
 *  主函数
 */

int main()
{
    printf("Write content to file. Start ...  \n");            //屏幕输出
    // getchar();                                 //获取键盘输入
    
    char content[100] = "这是写入文件内容，write content！";  //文件内容
    /* 我的第一个 C 程序 */
    // getchar();                                     //获取键盘输入
    // printf("Hello, World! \n");                    //屏幕输出Hello, World!并换行

    WriteLog(content);                                //调用WriteLog()函数

    printf("Complete! \n");                           //屏幕输出 Complete! 并换行
    // getchar();                                     //获取键盘输入
    
    return 0;
}

