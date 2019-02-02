#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{

    pid_t pid;
    int status = 0; //没有初始化时 ，status为随机值

    pid =fork();//创建子进程 --- pc 程序计数器 
                   // 创建子进程时，子进程也拷贝了父进程的pc值
                   // 指向了fork之后的下一条语句
                   // 此处 fork 之后的下一句为
                   // 赋值语句
                  //  将:fork的返回值赋值给pid变量 

    if(pid < 0)//如果pid小与0表示创建子进程失败

    {
        perror("fork fail");
        exit(EXIT_FAILURE);
    }
   
    if(pid > 0) //父进程
    {

       while(1)
       {
           printf("father pid = %d\n",getpid());
           sleep(1);

           //wait(&status); //收尸 ---回收资源的同时，可以接收子进程的退出状态值
           waitpid(-1,&status,WNOHANG|WUNTRACED|WCONTINUED);
           if(WIFEXITED(status))
               printf("status = %d\n",WEXITSTATUS(status));
           if(WIFSIGNALED(status)) //如果子进程是被信号结束了 ，则为真
               printf("signal status = %d\n",WTERMSIG(status));
           //R->T
           if(WIFSTOPPED(status))
               printf("stop sig num = %d\n",WSTOPSIG(status));
           //T->R
           if(WIFCONTINUED(status))
               printf("continue......\n");
       }
    }else if(pid == 0)//子进程
    {
        while(1)
        {
            printf("child exit...\n");
            sleep(1);
           
       //     exit(89); //退出时 给父进程 返回一个 退出状态值 
        }
    }
    return 0;
}
