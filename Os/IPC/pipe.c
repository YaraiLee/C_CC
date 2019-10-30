/**
 * 
 * 父子进程使用管道通信，父写入字符串，子进程读出并打印到屏幕
 * 
 * 1. 父进程调用pipe函数创建管道，得到两个文件描述符fd[0]、fd[1]指向管道的读端和写端。
 * 2. 父进程调用fork创建子进程，那么子进程也有两个文件描述符指向同一管道。
 * 3. 父进程关闭管道读端，子进程关闭管道写端。父进程可以向管道中写入数据，子进程将管道中的数据读出。由于管道是利用环形队列实现的，数据从写端流入管道，从读端流出，这样就实现了进程间通信。
 * 
 * */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
 
void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
 
int main(void)
{
    pid_t pid;
    char buf[1024];
    int fd[2];
    char *p = "test for pipe\n";
    
   if (pipe(fd) == -1) 
       sys_err("pipe");
 
   pid = fork();
   if (pid < 0) {
       sys_err("fork err");
   } else if (pid == 0) {   //子进程
        close(fd[1]);
        int len = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        close(fd[0]);
   } else {     //父进程
       close(fd[0]);
       write(fd[1], p, strlen(p));
       wait(NULL);
       close(fd[1]);
   }
    
    return 0;
}