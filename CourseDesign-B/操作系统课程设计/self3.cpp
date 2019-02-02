#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 
#include <string.h>

int physic[100];    //文件地址缓冲区
int style=1;     //文件的类型
char cur_dir[10]="root";  //当前目录  
   
typedef struct operate  //指令 
{
 	char com[10];
}Operate;
//这个地方这样更好 
Operate cmd[12];

struct block
{
	int n;      //空闲的盘快的个数
	int free[50];    //存放空闲盘快的地址
	int a;      //模拟盘快是否被占用
}memory[20449];

struct Sblock
{
	int n;      //空闲的盘快的个数
	int free[50];    //存放进入栈中的空闲块
	int stack[50];    //存放下一组空闲盘快的地址
}Sblock;

struct node      //i结点信息
{
	int Fstyle;    //i结点 文件类型
	int Fsize;   //i结点 文件长度
	int Faddress[100];  //i结点 文件的物理地址
} i_node[640];

struct dir      //目录项信息
{
	char file_name[10];   //文件名
	int  i_num;     //文件的结点号
	char dir_name[10];   //文件所在的目录
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

void format()     //格式化
{
	int i,j,k;
	Sblock.n=50;
	for(i=0;i<50;i++)     //超级块初始化
	{ 
		 Sblock.free[i]=i;   //存放进入栈中的空闲块
		 Sblock.stack[i]=50+i;  //存放下一组的盘块
	}
	for(i=0;i<640;i++)     //i结点信息初始化
	{
		for(j=0;j<100;j++)
		{
			i_node[i].Faddress[j]=-1;//文件地址
		}
		i_node[i].Fsize=-1;  //文件长度
		i_node[i].Fstyle=-1;  //文件类型
	}
	for(i=0;i<640;i++)     //根目录区信息初始化
	{
		strcpy(root[i].file_name,"");
		root[i].i_num=-1;
		strcpy(root[i].dir_name,"");
	} 
	for(i=0;i<20449;i++)     //存储空间初始化  
	{
		memory[i].n=0;      //必须有这个
		memory[i].a=0;      
		for(j=0;j<50;j++)
		{
		  	memory[i].free[j]=-1;
		}
	}
	for(i=0;i<20449;i++)    //将空闲块的信息用成组链接的方法写进每组的最后一个块中
	{         //存储空间初始化
		if((i+1)%50==0)
		{
			k=i+1;
		   	for(j=0;j<50;j++)
		   	{
		    	if(k<20450)
		    	{
		    		memory[i].free[j]=k;//下一组空闲地址
		     		memory[i].n++;  //下一组空闲个数   注意在memory[i].n++之前要给其赋初值
		     		k++;
		    	}
		    	else
		    	{
		     		memory[i].free[j]=-1;
		    	}
		   	}
		   	memory[i].a=0;    //标记为没有使用
		   	continue;     //处理完用于存储下一组盘块信息的特殊盘块后，跳过本次循环
		}
		for(j=0;j<50;j++)
		{
		  	memory[i].free[j]=-1;
		}
		memory[i].n=0;  
	}
	printf("初始化完毕\n");
	printf("进入UNIX文件模拟~ ~ ~\n\n");
}
	 
void write_file(FILE *fp)    //将信息读入系统文件中
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

void read_file(FILE *fp)   //读出系统文件的信息
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

void callback(int length)    //回收磁盘空间
{
	int i,j,k,m,q=0;
	for(i=length-1;i>=0;i--)
	{
		k=physic[i];     //需要提供要回收的文件的地址
		m=49-Sblock.n;    //回收到栈中的哪个位置
		if(Sblock.n==50)   //注意 当Sblock.n==50时 m=-1;的值
		{        //Sblock.n==50的时候栈满了，要将这个栈中的所有地址信息写进下一个地址中
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
			m=49;      //将下一个文件地址中的盘块号回收到栈底中，这个地址中存放着刚才满栈的地址的信息 
		}
		Sblock.free[m]=physic[i]; //将下一个文件地址中的盘块号回收到栈中
		Sblock.n++;
	}
}

void allot(int length)     //分配空间
{
	int i,j,k,m,p;
	for(i=0;i<length;i++)
	{
		k=50-Sblock.n;    //超级块中表示空闲块的指针
		m=Sblock.free[k];   //栈中的相应盘块的地址
		p=Sblock.free[49];   //栈中的最后一个盘块指向的地址
		if(m==-1||memory[p].a==1)  //检测是否还有下一组盘块
		{
			printf("内存不足,不能够分配空间\n");
			callback(length);
			break;
		}
		if(Sblock.n==1)
		{  
			memory[m].a=1;    //将最后一个盘块分配掉
			physic[i]=m;
			Sblock.n=0;   
			for(j=0;j<memory[m].n;j++) //从最后一个盘块中取出下一组盘块号写入栈中
			{ 
				Sblock.free[j]=memory[m].free[j];
				Sblock.n++;
			}
			continue;     //要跳过这次循环，下面的语句在IF中已经执行过
		}
		physic[i]=m;     //栈中的相应盘块的地址写进 文件地址缓冲区
		memory[m].a=1;  
		Sblock.n--;
	}
}

void create_file(char filename[],int length) //创建文件
{
	int i,j;
	for(i=0;i<640;i++)
	{
		if(strcmp(filename,root[i].file_name)==0)
		{
			printf("文件已经存在，不允许建立重名的文件\n");
			return;
		}
	}
	for(i=0;i<640;i++)
	{
		if(root[i].i_num==-1)
		{
			root[i].i_num=i;
			strcpy(root[i].file_name,filename);
			strcpy(root[i].dir_name,cur_dir);  //把当前目录名 给新建立的文件
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

void create_dir(char filename[])    //创建目录
{
	style=0;         //0代表文件类型是目录文件
	create_file(filename,4);
	style=1;         //用完恢复初值，因为全局变量，否则
}

void del_file(char filename[])     //删除文件
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
			callback(i_node[k].Fsize); //调用 回收函数
			for(j=0;j<100;j++)     //删除文件后要将文件属性和目录项的各个值恢复初值
			{
				i_node[k].Faddress[j]=-1; //地址恢复初值
			}
			strcpy(root[i].file_name,"");  //文件名恢复初值
			root[i].i_num=-1;     //目录项的I结点信息恢复初值
			strcpy(root[i].dir_name,"");  //目录项的文件目录信息恢复初值
			i_node[k].Fsize=-1;   //文件长度恢复
			i_node[k].Fstyle=-1;   //文件类型恢复初值
			break;
		} 
	}
	if(i==640)
	{
		 printf("不存在这个文件\n");
	} 
}

void del_dir(char filename[])     //删除目录   需要判断目录下时候为空,不为空就不删除
{
	int i,j,k;
	for(i=0;i<640;i++)       //还要加条件判断要删除的目录是不是当前目录
	{
		k=root[i].i_num;      //找到目录名字
		if( strcmp(root[i].file_name,filename)==0 && strcmp(cur_dir,filename)!=0 && (i_node[k].Fstyle)==0 ) 
		{
			for(j=0;j<640;j++)
			{
				if(strcmp(filename,root[j].dir_name)==0)
					{
						printf("目录不为空不能直接删除\n");
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
		printf("这个不是目录文件 或者不存在这个目录\n");
	} 
 
}

void display_curdir()         //显示当前目录下的文件列表
{
	int i,k;
	printf("\t\t文件名字  文件类型  文件长度  所属目录\n");
	for(i=0;i<640;i++)
	{
		if(strcmp(cur_dir,root[i].dir_name)==0)   //查询文件中 所在目录信息和当前目录信息相同的数据
		{
			k=root[i].i_num;
			//printf("\t\t  %s\t",root[i].file_name);  //文件名
			printf("\t\t%s\t",root[i].file_name);  //文件名
			printf("\t%d\t",i_node[k].Fstyle);  //文件的类型
			printf("%d\t",i_node[k].Fsize);  //文件的长度
			printf("%s\n",root[i].dir_name);   //文件所在的目录
		}
	}
}

void display_dir(char filename[])     //进入指定的目录  
{
	int i,k;  
	for(i=0;i<640;i++)
	{
		k=root[i].i_num;       //判断文件类型是不是目录类型
		if((strcmp(filename,root[i].file_name)==0) && (i_node[k].Fstyle==0))    
		{
			strcpy(cur_dir,filename);    //将要进入的指定目录设置为当前目录  赋值不要反了strcpy(目的，源)
			break;
		}
	}
	if(i==640)
	{
		printf("没有这个目录\n");
	}
}

void open_file(char filename[])        //打开文件
{
	int i,j,k;
	printf("\t\t文件名字  文件类型  文件长度  所属目录\n");
	for(i=0;i<640;i++)
	{
		k=root[i].i_num;
		if(strcmp(filename,root[i].file_name)==0 && (i_node[k].Fstyle==1))
		{
			printf("\t\t%s\t",root[i].file_name);   //文件名
			printf("\t%d\t",i_node[k].Fstyle);   //文件的类型
			printf("%d\t",i_node[k].Fsize);   //文件的长度
			printf("%s\n",root[i].dir_name);    //文件所在的目录
			printf("\t\t文件占用的物理地址\n");
			for(j=0;j<i_node[k].Fsize;j++)   //显示物理地址
			{  
				printf("%d  ",i_node[k].Faddress[j]); //文件具体占用的盘块号
			}
			printf("\n");
			break;
		} 
	}
	if(i==640)
	{
		printf("没有这个文件 或者这个文件不是正规文件\n");
	}; 
}

void back_dir()         //返回上一级目录
{
	int  i,k;
	for(i=0;i<640;i++)       //查询和当前目录名相同的目录文件名
	{
		k=root[i].i_num;
		if(strcmp(cur_dir,root[i].file_name)==0 && (i_node[k].Fstyle==0))  
		{
			strcpy(cur_dir,root[i].dir_name); //将查询到的目录文件名  所在的目录赋值给当前目录
		}
	}
}

void display_sys()        //显示系统信息（磁盘使用情况）
{
	int i,m,k=0;
	for(i=0;i<20449;i++)
	{
		if(memory[i].a==0)
		 k++;
	}
	m=20449-k;
	printf("空闲的盘块数是：\t");
	printf("%d\n",k);
	printf("使用的盘块数是：\t");
	printf("%d\n",m);
}

void logout()  //退出
{
	printf("推出系统登录......\n");
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
		printf("\t\t*……UNIX多用户系统，请先登录……*\n");
		
		printf("\t\tusername:");
		//在这个地方需要是八位的用户名和密码 ，只能多不能少 
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
			printf("登录成功!\n");
			*OK=1;
			times=0;
		}
		else
		{
			printf("密码或用户名错误,请重新输入!\n");
			times--;
			printf("您还有%d次机会!\n",times);
			if(times==0)
			{
				printf("谢谢使用!\n");
				exit(0);
			}
		}
	}	
}
/*
bool login(bool OK)   //登陆
{

	printf("\t\t*……UNIX多用户系统，请先登录……*\n");
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
				printf("\t\t登录成功！\n");
				break;
			}
		}

		if(i==8)
		{	
			rest--;
			printf("用户名或密码错误，请重新登录");
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
		printf(" 登录尝试三次，登录失败");
		system("cls");
		logout();
	}
	return OK;
}
*/


void help()          //显示帮助信息
{
	printf("\t\t\tUNIX文件管理系统\n\n");
	printf("\t\t0.磁盘初始化---------------------format\n");
	printf("\t\t1.创建文件-----------------------vi+文件名+文件长度\n");
	printf("\t\t2.查看文件-----------------------cat+文件名\n");
	printf("\t\t3.删除文件-----------------------del+文件名\n");
	printf("\t\t4.创建目录-----------------------md+目录名 \n");
	printf("\t\t5.查看当前目录文件列表-----------dir\n");
	printf("\t\t6.删除目录-----------------------del+目录名\n");
	printf("\t\t7.进入当前目录下的指定目录-------cd+目录名\n");
	printf("\t\t8.返回上一级目录-----------------cd..  \n");
	printf("\t\t9.查看系统信息-------------------ls    \n");
	printf("\t\t10.显示帮助命令------------------help  \n");
	printf("\t\t11.退出文件模拟------------------quit  \n");
	printf("\t\t注意：创建的文件长度 < 100\n\n"); //说明文件
}

int main()          //主函数
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
	//if(OK=1)注意是两个等号
	if(*OK==1) 
	{
		help();
		strcpy(cmd[0].com,"format");    //将各个命令存进命令表
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
	
		if((fp=fopen("system","rb"))==NULL)   //判断系统文件是否存在
		{
			printf("硬盘当前无文件，不可直接打开文件\n");
			printf("选择是否初始化硬盘  Y / N \n");
			scanf("%c",&k);
			if(k=='y')
				format(); 
		}
		else
		{
			read_file(fp);       //读取系统文件的内容
		}
 
		while(1)
		{
			j=0;         //必须 重新给恢复0否则出错
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
			scanf("%s",com);       //输入命令并且查找命令的相关操作
			for(i=0;i<12;i++)       
			{
				if(strcmp(com,cmd[i].com)==0)
				{
					p=i;
					break;
				}
			}
			if(i==12)         //如果没有这个语句以后输入的命令都和第一次输入的效果一样
			{
				p=13; //随便的一个值
			}
			switch(p)
			{
				case 0: format();       //初始化
					break;
				case 1: display_curdir();     //查看当前目录下的文件列表      
					break;
				case 2: scanf("%s",tmp);     //查看文件 
					open_file(tmp);  
					break;
				case 3: display_sys();      //查看系统信息
					break;
				case 4:scanf("%s",tmp);      //创建目录    
					create_dir(tmp);  
					break;
				case 5: scanf("%s",tmp);     //创建文件 
					scanf("%d",&len);
					create_file(tmp,len);  
					break;
				case 6: scanf("%s",tmp);     //删除文件
					for(i=0;i<640;i++)     //判断文件是不是正规文件
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
						printf("这个不是正规文件文件\n");
					}
					break;
				case 7: 
					scanf("%s",tmp);	//删除目录
					del_dir(tmp);	
					break;
				case 8: scanf("%s",tmp1); //进入当前目录下的指定目录   相当于进入目录  cd  +  目录名
					display_dir(tmp1);
					break;
				case 9: back_dir(); //返回上一级目录
					break;
				case 10:help();
					break;
				case 11:system("cls");//write_file(fp); //将磁盘利用信息写进系统文件，退出
					break;
				default:printf("指令出现错误，请重新输入\n");
					break;
			}
		}
	}
	return 0;
}
