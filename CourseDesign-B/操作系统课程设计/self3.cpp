#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h>

int physic[100];    //�ļ���ַ������
int style=1;     //�ļ�������
char cur_dir[10]="root";  //��ǰĿ¼  
   
typedef struct operate  //ָ�� 
{
 	char com[10];
}Operate;
//����ط��������� 
Operate cmd[12];

struct block
{
	int n;      //���е��̿�ĸ���
	int free[50];    //��ſ����̿�ĵ�ַ
	int a;      //ģ���̿��Ƿ�ռ��
}memory[20449];

struct Sblock
{
	int n;      //���е��̿�ĸ���
	int free[50];    //��Ž���ջ�еĿ��п�
	int stack[50];    //�����һ������̿�ĵ�ַ
}Sblock;

struct node      //i�����Ϣ
{
	int Fstyle;    //i��� �ļ�����
	int Fsize;   //i��� �ļ�����
	int Faddress[100];  //i��� �ļ��������ַ
} i_node[640];

struct dir      //Ŀ¼����Ϣ
{
	char file_name[10];   //�ļ���
	int  i_num;     //�ļ��Ľ���
	char dir_name[10];   //�ļ����ڵ�Ŀ¼
} root[640];

char UserName[8][8]={
						{'j','a','b','c','d','e','f','g'},
						{'1','a','b','c','d','e','f','g'},
						{'2','a','b','c','d','e','f','g'},
						{'3','a','b','c','d','e','f','g'},
						
						{'4','a','b','c','d','e','f','g'},
						{'5','a','b','c','d','e','f','g'},
						{'6','a','b','c','d','e','f','g'},
						{'7','a','b','c','d','e','f','g'}
					};

char PassWord[8][8]={
						{'0','1','2','3','4','5','6','7'},
						{'a','1','2','3','4','5','6','7'},
						{'b','1','2','3','4','5','6','7'},
						{'c','1','2','3','4','5','6','7'},
	
						{'d','1','2','3','4','5','6','7'},
						{'e','1','2','3','4','5','6','7'},
						{'f','1','2','3','4','5','6','7'},
						{'g','1','2','3','4','5','6','7'}
					};

void format()     //��ʽ��
{
	int i,j,k;
	Sblock.n=50;
	for(i=0;i<50;i++)     //�������ʼ��
	{ 
		 Sblock.free[i]=i;   //��Ž���ջ�еĿ��п�
		 Sblock.stack[i]=50+i;  //�����һ����̿�
	}
	for(i=0;i<640;i++)     //i�����Ϣ��ʼ��
	{
		for(j=0;j<100;j++)
		{
			i_node[i].Faddress[j]=-1;//�ļ���ַ
		}
		i_node[i].Fsize=-1;  //�ļ�����
		i_node[i].Fstyle=-1;  //�ļ�����
	}
	for(i=0;i<640;i++)     //��Ŀ¼����Ϣ��ʼ��
	{
		strcpy(root[i].file_name,"");
		root[i].i_num=-1;
		strcpy(root[i].dir_name,"");
	} 
	for(i=0;i<20449;i++)     //�洢�ռ��ʼ��  
	{
		memory[i].n=0;      //���������
		memory[i].a=0;      
		for(j=0;j<50;j++)
		{
		  	memory[i].free[j]=-1;
		}
	}
	for(i=0;i<20449;i++)    //�����п����Ϣ�ó������ӵķ���д��ÿ������һ������
	{         //�洢�ռ��ʼ��
		if((i+1)%50==0)
		{
			k=i+1;
		   	for(j=0;j<50;j++)
		   	{
		    	if(k<20450)
		    	{
		    		memory[i].free[j]=k;//��һ����е�ַ
		     		memory[i].n++;  //��һ����и���   ע����memory[i].n++֮ǰҪ���丳��ֵ
		     		k++;
		    	}
		    	else
		    	{
		     		memory[i].free[j]=-1;
		    	}
		   	}
		   	memory[i].a=0;    //���Ϊû��ʹ��
		   	continue;     //���������ڴ洢��һ���̿���Ϣ�������̿����������ѭ��
		}
		for(j=0;j<50;j++)
		{
		  	memory[i].free[j]=-1;
		}
		memory[i].n=0;  
	}
	printf("��ʼ�����\n");
	printf("����UNIX�ļ�ģ��~ ~ ~\n\n");
}
	 
void write_file(FILE *fp)    //����Ϣ����ϵͳ�ļ���
{
	int i;
	fp=fopen("system","wb");
	for(i=0;i<20449;i++)
	{
  		fwrite(&memory[i],sizeof(struct block),1,fp);
	}
 	fwrite(&Sblock,sizeof(struct Sblock),1,fp); 
	for(i=0;i<640;i++)
	{
		fwrite(&i_node[i],sizeof(struct node),1,fp);
	}
	for(i=0;i<640;i++)
	{
		fwrite(&root[i],sizeof(struct dir),1,fp);
	}
	fclose(fp);
}

void read_file(FILE *fp)   //����ϵͳ�ļ�����Ϣ
{
	int i;
	fp=fopen("system","rb");
	for(i=0;i<20449;i++)
	{
		fread(&memory[i],sizeof(struct block),1,fp);
	}
	fread(&Sblock,sizeof(struct Sblock),1,fp);
	for(i=0;i<640;i++)
	{
		fread(&i_node[i],sizeof(struct node),1,fp);
	}
	for(i=0;i<640;i++)
	{
		fread(&root[i],sizeof(struct dir),1,fp);
	}
	fclose(fp);
}

void callback(int length)    //���մ��̿ռ�
{
	int i,j,k,m,q=0;
	for(i=length-1;i>=0;i--)
	{
		k=physic[i];     //��Ҫ�ṩҪ���յ��ļ��ĵ�ַ
		m=49-Sblock.n;    //���յ�ջ�е��ĸ�λ��
		if(Sblock.n==50)   //ע�� ��Sblock.n==50ʱ m=-1;��ֵ
		{        //Sblock.n==50��ʱ��ջ���ˣ�Ҫ�����ջ�е����е�ַ��Ϣд����һ����ַ��
			for(j=0;j<50;j++)
			{
				memory[k].free[j]=Sblock.free[j];
			}
			Sblock.n=0; 
			memory[k].n=50;
		}
		memory[k].a=0; 
		if(m==-1)
		{
			m=49;      //����һ���ļ���ַ�е��̿�Ż��յ�ջ���У������ַ�д���Ÿղ���ջ�ĵ�ַ����Ϣ 
		}
		Sblock.free[m]=physic[i]; //����һ���ļ���ַ�е��̿�Ż��յ�ջ��
		Sblock.n++;
	}
}

void allot(int length)     //����ռ�
{
	int i,j,k,m,p;
	for(i=0;i<length;i++)
	{
		k=50-Sblock.n;    //�������б�ʾ���п��ָ��
		m=Sblock.free[k];   //ջ�е���Ӧ�̿�ĵ�ַ
		p=Sblock.free[49];   //ջ�е����һ���̿�ָ��ĵ�ַ
		if(m==-1||memory[p].a==1)  //����Ƿ�����һ���̿�
		{
			printf("�ڴ治��,���ܹ�����ռ�\n");
			callback(length);
			break;
		}
		if(Sblock.n==1)
		{  
			memory[m].a=1;    //�����һ���̿�����
			physic[i]=m;
			Sblock.n=0;   
			for(j=0;j<memory[m].n;j++) //�����һ���̿���ȡ����һ���̿��д��ջ��
			{ 
				Sblock.free[j]=memory[m].free[j];
				Sblock.n++;
			}
			continue;     //Ҫ�������ѭ��������������IF���Ѿ�ִ�й�
		}
		physic[i]=m;     //ջ�е���Ӧ�̿�ĵ�ַд�� �ļ���ַ������
		memory[m].a=1;  
		Sblock.n--;
	}
}

void create_file(char filename[],int length) //�����ļ�
{
	int i,j;
	for(i=0;i<640;i++)
	{
		if(strcmp(filename,root[i].file_name)==0)
		{
			printf("�ļ��Ѿ����ڣ����������������ļ�\n");
			return;
		}
	}
	for(i=0;i<640;i++)
	{
		if(root[i].i_num==-1)
		{
			root[i].i_num=i;
			strcpy(root[i].file_name,filename);
			strcpy(root[i].dir_name,cur_dir);  //�ѵ�ǰĿ¼�� ���½������ļ�
			i_node[i].Fstyle=style;
			i_node[i].Fsize=length;
			allot(length);
			for(j=0;j<length;j++)
			{
				i_node[i].Faddress[j]=physic[j];
			}
			break;
		}
	}
}

void create_dir(char filename[])    //����Ŀ¼
{
	style=0;         //0�����ļ�������Ŀ¼�ļ�
	create_file(filename,4);
	style=1;         //����ָ���ֵ����Ϊȫ�ֱ���������
}

void del_file(char filename[])     //ɾ���ļ�
{
	int i,j,k;
	for(i=0;i<640;i++)
	{
		if(strcmp(filename,root[i].file_name)==0)   
		{ 
			k=root[i].i_num;
			for(j=0;j<i_node[k].Fsize;j++)
			{
				physic[j]=i_node[k].Faddress[j];
			}
			callback(i_node[k].Fsize); //���� ���պ���
			for(j=0;j<100;j++)     //ɾ���ļ���Ҫ���ļ����Ժ�Ŀ¼��ĸ���ֵ�ָ���ֵ
			{
				i_node[k].Faddress[j]=-1; //��ַ�ָ���ֵ
			}
			strcpy(root[i].file_name,"");  //�ļ����ָ���ֵ
			root[i].i_num=-1;     //Ŀ¼���I�����Ϣ�ָ���ֵ
			strcpy(root[i].dir_name,"");  //Ŀ¼����ļ�Ŀ¼��Ϣ�ָ���ֵ
			i_node[k].Fsize=-1;   //�ļ����Ȼָ�
			i_node[k].Fstyle=-1;   //�ļ����ͻָ���ֵ
			break;
		} 
	}
	if(i==640)
	{
		 printf("����������ļ�\n");
	} 
}

void del_dir(char filename[])     //ɾ��Ŀ¼   ��Ҫ�ж�Ŀ¼��ʱ��Ϊ��,��Ϊ�վͲ�ɾ��
{
	int i,j,k;
	for(i=0;i<640;i++)       //��Ҫ�������ж�Ҫɾ����Ŀ¼�ǲ��ǵ�ǰĿ¼
	{
		k=root[i].i_num;      //�ҵ�Ŀ¼����
		if( strcmp(root[i].file_name,filename)==0 && strcmp(cur_dir,filename)!=0 && (i_node[k].Fstyle)==0 ) 
		{
			for(j=0;j<640;j++)
			{
				if(strcmp(filename,root[j].dir_name)==0)
					{
						printf("Ŀ¼��Ϊ�ղ���ֱ��ɾ��\n");
						break;
					}
			}
			if(j==640)
			{
				del_file(filename);
				break;
			}
   
			break;
		}
	}
	if(i==640)
	{
		printf("�������Ŀ¼�ļ� ���߲��������Ŀ¼\n");
	} 
 
}

void display_curdir()         //��ʾ��ǰĿ¼�µ��ļ��б�
{
	int i,k;
	printf("\t\t�ļ�����  �ļ�����  �ļ�����  ����Ŀ¼\n");
	for(i=0;i<640;i++)
	{
		if(strcmp(cur_dir,root[i].dir_name)==0)   //��ѯ�ļ��� ����Ŀ¼��Ϣ�͵�ǰĿ¼��Ϣ��ͬ������
		{
			k=root[i].i_num;
			//printf("\t\t  %s\t",root[i].file_name);  //�ļ���
			printf("\t\t%s\t",root[i].file_name);  //�ļ���
			printf("\t%d\t",i_node[k].Fstyle);  //�ļ�������
			printf("%d\t",i_node[k].Fsize);  //�ļ��ĳ���
			printf("%s\n",root[i].dir_name);   //�ļ����ڵ�Ŀ¼
		}
	}
}

void display_dir(char filename[])     //����ָ����Ŀ¼  
{
	int i,k;  
	for(i=0;i<640;i++)
	{
		k=root[i].i_num;       //�ж��ļ������ǲ���Ŀ¼����
		if((strcmp(filename,root[i].file_name)==0) && (i_node[k].Fstyle==0))    
		{
			strcpy(cur_dir,filename);    //��Ҫ�����ָ��Ŀ¼����Ϊ��ǰĿ¼  ��ֵ��Ҫ����strcpy(Ŀ�ģ�Դ)
			break;
		}
	}
	if(i==640)
	{
		printf("û�����Ŀ¼\n");
	}
}

void open_file(char filename[])        //���ļ�
{
	int i,j,k;
	printf("\t\t�ļ�����  �ļ�����  �ļ�����  ����Ŀ¼\n");
	for(i=0;i<640;i++)
	{
		k=root[i].i_num;
		if(strcmp(filename,root[i].file_name)==0 && (i_node[k].Fstyle==1))
		{
			printf("\t\t%s\t",root[i].file_name);   //�ļ���
			printf("\t%d\t",i_node[k].Fstyle);   //�ļ�������
			printf("%d\t",i_node[k].Fsize);   //�ļ��ĳ���
			printf("%s\n",root[i].dir_name);    //�ļ����ڵ�Ŀ¼
			printf("\t\t�ļ�ռ�õ������ַ\n");
			for(j=0;j<i_node[k].Fsize;j++)   //��ʾ�����ַ
			{  
				printf("%d  ",i_node[k].Faddress[j]); //�ļ�����ռ�õ��̿��
			}
			printf("\n");
			break;
		} 
	}
	if(i==640)
	{
		printf("û������ļ� ��������ļ����������ļ�\n");
	}; 
}

void back_dir()         //������һ��Ŀ¼
{
	int  i,k;
	for(i=0;i<640;i++)       //��ѯ�͵�ǰĿ¼����ͬ��Ŀ¼�ļ���
	{
		k=root[i].i_num;
		if(strcmp(cur_dir,root[i].file_name)==0 && (i_node[k].Fstyle==0))  
		{
			strcpy(cur_dir,root[i].dir_name); //����ѯ����Ŀ¼�ļ���  ���ڵ�Ŀ¼��ֵ����ǰĿ¼
		}
	}
}

void display_sys()        //��ʾϵͳ��Ϣ������ʹ�������
{
	int i,m,k=0;
	for(i=0;i<20449;i++)
	{
		if(memory[i].a==0)
		 k++;
	}
	m=20449-k;
	printf("���е��̿����ǣ�\t");
	printf("%d\n",k);
	printf("ʹ�õ��̿����ǣ�\t");
	printf("%d\n",m);
}

void logout()  //�˳�
{
	printf("�Ƴ�ϵͳ��¼......\n");
	system("cls");
}

int cmpstr(char *a,char *b,int size)
{
	int flag=1;
	for(int i=0;i<size;i++)
		if(a[i]!=b[i])
		{
			flag=0;
			break;
		}
	if(flag)
		return 1;
	return 0;
}

void login(int *OK)
{
	int times=3;
	char temp_user[8],temp_pass[8];
	while(times>0)
	{
		printf("\t\t*����UNIX���û�ϵͳ�����ȵ�¼����*\n");
		
		printf("\t\tusername:");
		//������ط���Ҫ�ǰ�λ���û��������� ��ֻ�ܶ಻���� 
		for(int i=0;i<8;i++)
			scanf("%c",&temp_user[i]);
		getchar();
	
		
		printf("\t\tpassword:");
	
		for(int i=0;i<8;i++)
			scanf("%c",&temp_pass[i]);
	
		
		int flag=0;

	
		for(int i=0;i<8;i++)
			if(cmpstr(temp_user,UserName[i],8)==1&&cmpstr(temp_pass,PassWord[i],8)==1)
			{
				flag=1;
				
				break;
			}

		if(flag)
		{
			printf("��¼�ɹ�!\n");
			*OK=1;
			times=0;
		}
		else
		{
			printf("������û�������,����������!\n");
			times--;
			printf("������%d�λ���!\n",times);
			if(times==0)
			{
				printf("ллʹ��!\n");
				exit(0);
			}
		}
	}	
}
/*
bool login(bool OK)   //��½
{

	printf("\t\t*����UNIX���û�ϵͳ�����ȵ�¼����*\n");
	//char User,PassW;
	char User[8],PassW[8];
	printf("\t\tusername:");
	//scanf("%c",User);
	scanf("%s",User);
	printf("\t\tpassword:");
	scanf("%s",PassW);
	//scanf("%c",PassW);

	int i = 0;
	int rest = 3;

	while((OK==0) && (rest != 1))
	{
		for(; i < 8; i++)
		{
			//if((User=UserName[i]) &&(PassW=PassWord[i]))
			if((User[i]=UserName[i]) &&(PassW[i]=PassWord[i]))
			{
				OK =1;
				printf("\t\t��¼�ɹ���\n");
				break;
			}
		}

		if(i==8)
		{	
			rest--;
			printf("�û�����������������µ�¼");
			system("cls");
			printf("\t\t UserName: \n");
			scanf("%c",User);
			printf("\n");
			printf("\t\t PassWord:\n ");
			scanf("%c",PassW);
			i = 0;
		}
	}

	if((OK ==0) && (rest == 1))
	{
		printf(" ��¼�������Σ���¼ʧ��");
		system("cls");
		logout();
	}
	return OK;
}
*/


void help()          //��ʾ������Ϣ
{
	printf("\t\t\tUNIX�ļ�����ϵͳ\n\n");
	printf("\t\t0.���̳�ʼ��---------------------format\n");
	printf("\t\t1.�����ļ�-----------------------vi+�ļ���+�ļ�����\n");
	printf("\t\t2.�鿴�ļ�-----------------------cat+�ļ���\n");
	printf("\t\t3.ɾ���ļ�-----------------------del+�ļ���\n");
	printf("\t\t4.����Ŀ¼-----------------------md+Ŀ¼�� \n");
	printf("\t\t5.�鿴��ǰĿ¼�ļ��б�-----------dir\n");
	printf("\t\t6.ɾ��Ŀ¼-----------------------del+Ŀ¼��\n");
	printf("\t\t7.���뵱ǰĿ¼�µ�ָ��Ŀ¼-------cd+Ŀ¼��\n");
	printf("\t\t8.������һ��Ŀ¼-----------------cd..  \n");
	printf("\t\t9.�鿴ϵͳ��Ϣ-------------------ls    \n");
	printf("\t\t10.��ʾ��������------------------help  \n");
	printf("\t\t11.�˳��ļ�ģ��------------------quit  \n");
	printf("\t\tע�⣺�������ļ����� < 100\n\n"); //˵���ļ�
}

int main()          //������
{
	char tmp[10],com[10],tmp1[10],k;
	Operate tmp2[10];
	int i, j=0,p,len=0;
	//bool OK=0;
	int flag=0;
	int *OK=&flag;
	FILE *fp;
	//login(OK);
	login(OK);
	//if(OK=1)ע���������Ⱥ�
	if(*OK==1) 
	{
		help();
		strcpy(cmd[0].com,"format");    //�����������������
		strcpy(cmd[1].com,"dir");
		strcpy(cmd[2].com,"cat");
		strcpy(cmd[3].com,"ls");
		strcpy(cmd[4].com,"md");
		strcpy(cmd[5].com,"vi");
		strcpy(cmd[6].com,"del");
		strcpy(cmd[7].com,"deldir");
		strcpy(cmd[8].com,"cd");
		strcpy(cmd[9].com,"cd..");
		strcpy(cmd[10].com,"help");
		strcpy(cmd[11].com,"quit");
	
		if((fp=fopen("system","rb"))==NULL)   //�ж�ϵͳ�ļ��Ƿ����
		{
			printf("Ӳ�̵�ǰ���ļ�������ֱ�Ӵ��ļ�\n");
			printf("ѡ���Ƿ��ʼ��Ӳ��  Y / N \n");
			scanf("%c",&k);
			if(k=='y')
				format(); 
		}
		else
		{
			read_file(fp);       //��ȡϵͳ�ļ�������
		}
 
		while(1)
		{
			j=0;         //���� ���¸��ָ�0�������
			strcpy(tmp,cur_dir);
			while(strcmp(tmp,"root")!=0)
			{
				for(i=0;i<640;i++)
				{
					p=root[i].i_num;
					if(strcmp(tmp,root[i].file_name)==0 && (i_node[p].Fstyle==0))
					{
						strcpy(tmp2[j].com,tmp);
						j++;
						strcpy(tmp,root[i].dir_name);
					}
				}
			}
  
			strcpy(tmp2[j].com,tmp);
			for(i=j;i>=0;i--)
			{
				printf("%s/",tmp2[i].com); 
			}
			scanf("%s",com);       //��������Ҳ����������ز���
			for(i=0;i<12;i++)       
			{
				if(strcmp(com,cmd[i].com)==0)
				{
					p=i;
					break;
				}
			}
			if(i==12)         //���û���������Ժ����������͵�һ�������Ч��һ��
			{
				p=13; //����һ��ֵ
			}
			switch(p)
			{
				case 0: format();       //��ʼ��
					break;
				case 1: display_curdir();     //�鿴��ǰĿ¼�µ��ļ��б�      
					break;
				case 2: scanf("%s",tmp);     //�鿴�ļ� 
					open_file(tmp);  
					break;
				case 3: display_sys();      //�鿴ϵͳ��Ϣ
					break;
				case 4:scanf("%s",tmp);      //����Ŀ¼    
					create_dir(tmp);  
					break;
				case 5: scanf("%s",tmp);     //�����ļ� 
					scanf("%d",&len);
					create_file(tmp,len);  
					break;
				case 6: scanf("%s",tmp);     //ɾ���ļ�
					for(i=0;i<640;i++)     //�ж��ļ��ǲ��������ļ�
					{
						j=root[i].i_num;
						if(strcmp(tmp,root[i].file_name)==0 && (i_node[j].Fstyle)==1)
						{
							del_file(tmp);
							break;
						}
					}
					if(i==640)
					{
						printf("������������ļ��ļ�\n");
					}
					break;
				case 7: 
					scanf("%s",tmp);	//ɾ��Ŀ¼
					del_dir(tmp);	
					break;
				case 8: scanf("%s",tmp1); //���뵱ǰĿ¼�µ�ָ��Ŀ¼   �൱�ڽ���Ŀ¼  cd  +  Ŀ¼��
					display_dir(tmp1);
					break;
				case 9: back_dir(); //������һ��Ŀ¼
					break;
				case 10:help();
					break;
				case 11:system("cls");//write_file(fp); //������������Ϣд��ϵͳ�ļ����˳�
					break;
				default:printf("ָ����ִ�������������\n");
					break;
			}
		}
	}
	return 0;
}
