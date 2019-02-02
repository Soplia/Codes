#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{

    pid_t pid;
    int status = 0; //û�г�ʼ��ʱ ��statusΪ���ֵ

    pid =fork();//�����ӽ��� --- pc ��������� 
                   // �����ӽ���ʱ���ӽ���Ҳ�����˸����̵�pcֵ
                   // ָ����fork֮�����һ�����
                   // �˴� fork ֮�����һ��Ϊ
                   // ��ֵ���
                  //  ��:fork�ķ���ֵ��ֵ��pid���� 

    if(pid < 0)//���pidС��0��ʾ�����ӽ���ʧ��

    {
        perror("fork fail");
        exit(EXIT_FAILURE);
    }
   
    if(pid > 0) //������
    {

       while(1)
       {
           printf("father pid = %d\n",getpid());
           sleep(1);

           //wait(&status); //��ʬ ---������Դ��ͬʱ�����Խ����ӽ��̵��˳�״ֵ̬
           waitpid(-1,&status,WNOHANG|WUNTRACED|WCONTINUED);
           if(WIFEXITED(status))
               printf("status = %d\n",WEXITSTATUS(status));
           if(WIFSIGNALED(status)) //����ӽ����Ǳ��źŽ����� ����Ϊ��
               printf("signal status = %d\n",WTERMSIG(status));
           //R->T
           if(WIFSTOPPED(status))
               printf("stop sig num = %d\n",WSTOPSIG(status));
           //T->R
           if(WIFCONTINUED(status))
               printf("continue......\n");
       }
    }else if(pid == 0)//�ӽ���
    {
        while(1)
        {
            printf("child exit...\n");
            sleep(1);
           
       //     exit(89); //�˳�ʱ �������� ����һ�� �˳�״ֵ̬ 
        }
    }
    return 0;
}
