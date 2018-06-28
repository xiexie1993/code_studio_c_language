#include <stdio.h>  
#include <winsock2.h>  
#include <windows.h>
#include "include/mysql.h"  

int c_mysql_first(void);

int main()
{  
    MYSQL mysql;  

    int ret = 2;

    printf("\n Press any key to start. \n");

    getchar(); // 等待输入
    // if(!mysql_real_connect(&mysql, "localhost", "root", "root", "bangbangmusic", 3306, NULL, 0))  
    // {  
    //     printf("\nconnect error!");  
    // }  
    // else  
    // {  
    //     printf("\nconnect success!\n");  
    // }  

    // mysql_close(&mysql);  

    //测试查询
    
    printf("\n Start TEST connect mysql ... \n ");

    ret = c_mysql_first();

    printf ( "\n %d  \n",ret);


    printf("\n Press any key to stop. \n");
    
    getchar(); // 等待输入

    getchar(); // 等待输入

    return 0;  
}

int c_mysql_first(void)
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
        if(!conn_ptr)
        {
                fprintf(stderr, "init mysql failed\n");
                return(-1);
        }

        conn_ptr = mysql_real_connect(conn_ptr, host, user, password, db, port, unix_socket, client_flag);

        if(conn_ptr)
        {
                printf("\n Connection success......\n");
        }
        else
        {
                fprintf(stderr, "\n Connection failed......%d:%s\n", errno, strerror(errno));
        }

        if( mysql_query(conn_ptr, "\n select host,user from user"))
        {
                fprintf(stderr, "call mysql_query failed......%d:%s\n",errno, strerror(errno));
        }

        res = mysql_use_result(conn_ptr);

        fprintf(stdout, "\n SQL: select host, user from user talbe :\n");

        while((row = mysql_fetch_row(res)))
        {
                fprintf(stdout, "%s\t%s\n", row[0], row[1]);
        }

        mysql_free_result(res);
        mysql_close(conn_ptr);
        return 0;
}