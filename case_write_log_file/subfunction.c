#include <stdio.h>  //C标准库-stdio .h 头文件定义了三个变量类型、一些宏和各种函数来执行输入和输出。
#include <time.h>   //C标准库-time.h 头文件定义了四个变量类型、两个宏和各种操作日期和时间的函数。
#include <string.h> //C标准库-string.h 头文件定义了一个变量类型、一个宏和各种操作字符数组的函数。
#include <stdlib.h> //stdlib .h 头文件定义了四个变量类型、一些宏和各种通用工具函数。

void WriteLog();
char *join1(char *, char*);

/*============================================================================*/
/**
 * 函数原型的 源代码
 * 
 */
void WriteLog(char *content)
{
    // char file_name[20] = "./Log_2017-08-31.txt";  //文件名
    // char now_time_str;                 //当前时间字符串
    char file_path[3] ="./";              //文件路径
    char file_prefix[5]="log_";           //文件名前缀 
    
    // char file_time[11] = "2017-08-31"; //文件名中的时间
    char file_time[11];                   // 文件名中的时间
    char file_type[5] = ".txt";           // 文件扩展名
    char *file_name;                      // 文件名指针
    FILE *fp = NULL;                      // 文件指针句柄
    
    // 写入文件的内容： INFO 2017-08-31  内容
    char *text_content;                   // 写入文件内容指针
    char detailed_time[21]; //详细时间
    char content_prefix[6]="INFO:";           //文件名前缀 
    //注：定义时要多留一位 存放结束符号（不然拼接时会拼接两次）
    
    time_t t;
    struct tm * lt;
    time (&t);                          //获取Unix时间戳。
    lt = localtime (&t);                //转为时间结构。
    
    // printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
    //注释：换算出来的月份值少一，需要+1
    //拼接日期
    sprintf(file_time, "%d-%d-%d", lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
    // printf(" \nfile_path %s",file_path);     //屏幕换行,再输出字符型的变量 file_path 的数据
    // printf(" \nfile_prefix %s",file_prefix); // 屏幕换行,再输出字符型的变量 file_prefix 的数据
    // printf(" \nfile_time %s",file_time);     //屏幕换行,再输出字符型的变量 file_time 的数据
    // printf(" \nfile_type %s",file_type);     //屏幕换行,再输出字符型的变量 file_type 的数据
    
    file_name = join1(file_path,file_prefix);   //拼接文件路径和文件名前缀
    file_name = join1(file_name,file_time);     //拼接文件名中的时间
    file_name = join1(file_name,file_type);     //拼接文件名文件扩展名
    // printf(" \nfile_name %s",file_name);     //屏幕换行,再输出字符型的变量 file_name 的数据
    
    // 拼接最后写入文件的内容
    sprintf(detailed_time,"%d/%d/%d-%d:%d:%d : ",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour, lt->tm_min, lt->tm_sec);
    // printf(" \n detailed_time %s",detailed_time);      //屏幕换行,再输出字符型的变量 detailed_time 的数据
    // printf(" \n text_content %s",text_content);      //屏幕换行,再输出字符型的变量 text_content 的数据

    text_content = join1(content_prefix,detailed_time);   //内容前缀和详细时间
    // printf(" \n text_content %s",text_content);      //屏幕换行,再输出字符型的变量 text_content 的数据

    text_content = join1(text_content,content);           //内容前缀和具体内容
    // printf(" \n text_content %s",text_content);      //屏幕换行,再输出字符型的变量 text_content 的数据
    text_content = join1(text_content,"\n");
    // printf(" \n text_content %s",text_content);      //屏幕换行,再输出字符型的变量 text_content 的数据

    fp = fopen(file_name, "a+");
    fputs(text_content, fp);
    if(text_content != NULL) {free(text_content);text_content=NULL;}  //释放
    if(file_name != NULL) {free(file_name);file_name=NULL;}  //释放
    fclose(fp);
    
    // return 0;
}

/*方法一，不改变字符串a,b, 通过malloc，生成第三个字符串c, 返回局部指针变量*/  
char *join1(char *a, char *b) 
{
    char *c = (char *) malloc(strlen(a) + strlen(b) + 1); //局部变量，用malloc申请内存  
    if (c == NULL) exit (1);  
    char *tempc = c; //把首地址存下来  
    while (*a != '\0') {  
        *c++ = *a++;  
    }  
    while ((*c++ = *b++) != '\0') {  
        ;  
    }  
    //注意，此时指针c已经指向拼接之后的字符串的结尾'\0' !  
    return tempc;//返回值是局部malloc申请的指针变量，需在函数调用结束后free之  
} 
