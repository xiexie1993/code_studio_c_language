#include <stdio.h>  
#include <winsock2.h>  
#include <windows.h>

#include "vendor/mysql-connector-c-noinstall-6.0.2-win32/include/mysql.h"  // mysql连接库头文件，这样写了相对地址，再编译时就可不需要使用 -I 来指定 头文件位置

#include "write_log.h"  // 自定义的写日志头文件，


/**
 * 函数原型
 * 
 */


int test_mysql_connect(void);

/**
 *  主函数
 */

int main()
{


    char getstr;
    char content[100] ;  // 声明变量
    
    sprintf(content, "\n Press any key to start. \n"); //屏幕输出
    printf("\n %s \n",content);
    WriteLog(content);                                //调用WriteLog()函数

    // getstr = getchar();                                     //获取键盘输入

    char temp[10];//定义1个变量，并且初始化
    // scanf("%d",&temp);//读入
    gets(temp);

    printf("\n %s \n",temp);
    WriteLog(temp);                                //调用WriteLog()函数
    
    test_mysql_connect();

    // printf("Complete! \n");                           //屏幕输出 Complete! 并换行
    sprintf(content, "\n Complete! \n");
    WriteLog(content);
    printf("\n %s \n",content);

    // getstr = getchar();                                     //获取键盘输入
    // scanf("%d",&temp);//读入
    gets(temp);

    printf("\n %s \n",temp);
    WriteLog(temp);                                //调用WriteLog()函数
    
    // getstr = getchar();                                     //获取键盘输入

    // scanf("%d",&temp);//读入
    gets(temp);
    
    printf("\n %s \n",temp);
    WriteLog(temp);                                //调用WriteLog()函数
    
    return 0;
}


// int c_mysql_first(void)
// {
//     MYSQL mysql;    //一个数据库结构体
//     MYSQL_RES* res; //一个结果集结构体
//     MYSQL_ROW row;  //char** 二维数组，存放一条条记录
//     //初始化数据库
//     mysql_init(&mysql);
//     //设置编码方式
//     mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
//     //连接数据库
//     mysql_real_connect(&mysql, "localhost", "root", "root", "bangbangmusic", 3306, NULL, 0);
//     //查询数据
//     // mysql_query(&mysql, "select * from city where 书名 like '%C%'");
//     mysql_query(&mysql, "select * from city ");
//     //获取结果集
//     res = mysql_store_result(&mysql);
//     //显示数据
//     // printf("ID  书名              作者          出版社     出版时间       售价\n");
//     while (row = mysql_fetch_row(res))
//     {
//         printf("%s  ", row[0]);
//         printf("%s  ", row[1]);
//         printf("%s  ", row[2]);
//         printf("%s  ", row[3]);
//         printf("%s  ", row[4]);
//         printf("%s  \n", row[5]);
//     }

//     //释放结果集
//     mysql_free_result(res);
//     //关闭数据库
//     mysql_close(&mysql);
//     return 0;
// }



int test_mysql_connect(void)
{
        MYSQL *conn_ptr;
        MYSQL_RES *res;
        MYSQL_ROW row;

        char *host = "127.0.0.1";
        char *user = "root";
        char *password = "root";
        char *db = "mysql";
        unsigned int port = 0;
        char *unix_socket = NULL;
        unsigned long client_flag = 0;

        conn_ptr = mysql_init(NULL);

        char content[100];

        if(!conn_ptr)
        {
                // fprintf(stderr, "init mysql failed\n");
                sprintf(content, "init mysql failed \n");
                WriteLog(content);
                printf("\n %s \n",content);

                return(-1);
        }

        conn_ptr = mysql_real_connect(conn_ptr, host, user, password, db, port, unix_socket, client_flag);

        if(conn_ptr)
        {
                // printf("\n Connection success......\n");
                sprintf(content, "\n Connection success......\n");
                WriteLog(content);
                printf("\n %s \n",content);
                
        }
        else
        {
                // fprintf(stderr, "\n Connection failed......%d:%s\n", errno, strerror(errno));
                sprintf(content, "\n Connection failed......%d:%s\n", errno, strerror(errno));
                WriteLog(content);
                printf("\n %s \n",content);
        }

        if( mysql_query(conn_ptr, "\n select host,user from user"))
        {
                // fprintf(stderr, "call mysql_query failed......%d:%s\n",errno, strerror(errno));
                sprintf(content, "call mysql_query failed......%d:%s\n",errno, strerror(errno));
                WriteLog(content);
                printf("\n %s \n",content);
        }

        res = mysql_use_result(conn_ptr);

        // fprintf(stdout, "\n SQL: select host, user from user  \n");
        sprintf(content, "\n SQL: select host, user from user :\n");
        WriteLog(content);
        printf("\n %s \n",content);

        while((row = mysql_fetch_row(res)))
        {
                // fprintf(stdout, "%s\t%s\n", row[0], row[1]);
                sprintf(content, "%s\t%s\n", row[0], row[1]);
                WriteLog(content);
                printf("\n %s \n",content);
        }

        mysql_free_result(res);
        mysql_close(conn_ptr);
        return 0;
}