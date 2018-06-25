// #include <stdio.h>  
// #include <pthread.h>  
// #include <assert.h>  
  
// // #pragma comment(lib,"x86/pthreadVC2.lib")  
  
// void* Function_t(void* Param)  
// {  
//     printf("我是线程！ ");  
//     pthread_t myid = pthread_self();  
//     printf("线程ID=%d ", myid);  
//     return NULL;  
// }  
  
// int main()  
// {  
//     pthread_t pid;  
//     pthread_attr_t attr;  
//     pthread_attr_init(&attr);  
//     pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);  
//     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);  
//     pthread_create(&pid, &attr, Function_t, NULL);  
//     printf("======================================== ");  
//     getchar();  
//     pthread_attr_destroy(&attr);  
//     return 0;  
// }  

#include<stdio.h>
#include<pthread.h>
#include <windows.h> //win头文件 sleep(2);
#define NUM 6
int main()
{
    void print_msg(void*);
   
    pthread_t t1,t2;
    pthread_create(&t1,NULL,print_msg,(void *)"hello,");
    pthread_create(&t2,NULL,print_msg,(void *)"world!\n");
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);  
    getchar();
}
void print_msg(void* m)
{
    char *cp=(char*)m;
    int i;
    for(i=0;i<NUM;i++)
    {
        printf("%s",m);
        fflush(stdout);
        sleep(2);
    }
}