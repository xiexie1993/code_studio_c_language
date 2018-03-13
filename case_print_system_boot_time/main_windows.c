
/**
 * 函数名: _strtime
 * 头文件: time.h
 * 函数原型: char * _strtime(char *)
 * 功能: 获取当前系统时间(不包括日期),函数以字符指针形式为返回.
 * 此形式一般用于理解
 */
/*

#include<time.h>
#include<string.h>
#include<stdio.h>
#include <conio.h>
void main()
{
char Now_time[30];
char *t;
t=Now_time;
strcpy(Now_time,_strtime(t));   
printf("%s",Now_time);
getch();
}

*/

/**
 * 运行结果将打印出当前时间
 * 一般实用性的使用方法:
 * 
 */
/*

#include<time.h>
#include<stdio.h>
#include <conio.h>
void main()
{
char Now_time[30];
printf("%s",_strtime(Now_time));
getch();
}

*/

/**
 * 获取开机时间的具体案例
 * 这个函数并非实时发送，而是由系统每18ms发送一次，因此其最小精度为18ms。当需要有小于18ms的精度计算时，应使用StopWatch方法进行。
 */


#include <time.h>  
#include<windows.h>  
#include <stdio.h>  

void sleep( long wait );
void gettime();

int main( void )
{
    int flag=1;  
    char time[128];  
    _strtime(time);  
    printf( "OS time:%s\n",time);  
    //printf( "Delay for one seconds\n" );  
    printf("boot time：\n");  
    do  
    {  
        gettime();  
        sleep( 1000 );  //每间隔1000毫秒，也就是1秒刷新一次时间  
    }while(flag);  
    return 0;  
}

void sleep( long wait )  
{  
    long goal;
    goal = wait + clock();
    while( goal > clock() );
}


void gettime()  
{
    int i=GetTickCount();
    int h=(i/1000)/3600;
    int m=(i/1000)/60-h*60;
    int s=(i/1000)-h*3600-m*60;
      
    printf("%d h %d m %d s\n",h,m,s);  
}




/**
 * 参考资料：
 * C语言 windows下如何获取开机时间
 * http://blog.csdn.net/icebergkevin/article/details/19051041
 */