#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体类型的定义

//日期类型
typedef struct date									
{
	int year;										//年
	int month;									//月
	int day;										//日
}SDATE;

//药品类型
typedef struct medicine								
{
	//这里不需要数组的 
	//char ISBN [20];	
	//这里不需要数组的										
    //char quantity[20];								
    //这里不需要数组的
	//char price[20];								
	//这里不需要数组的
	//char iprice[20];	
								
	int ISBN;//药品编号
	char medicinename[40];//药品名称
	char manu[40];//药品厂家(manufacturers)
	float price;//药品销售价格
	float iprice;//药品进货价格
    int quantity;//药品库存数量
	SDATE produce_time;//药品生产日期(date of manufacture)	
}SMEDICINE;
SMEDICINE medicine[1000];
//SMEDICINE_LEN为药品类型占用存储空间的大小
#define SMEDICINE_LEN sizeof(SMEDICINE)				
#define SDATE_LEN sizeof(SDATE)						

//用户登录模块的函数声明
void managerlogin(int *pbn,int *psn);					//用户登录函数 



//药品信息管理模块的函数声明
void inputonemedicine(int i);							//输入一种药品信息的函数
int loadmedicines(void);								//从文件载入全部药品信息的函数
void saveonemedicine(int i);							//保存一种药品信息的函数
void saveallmedicines(int bn);							//保存全部药品信息的函数
int originalmedicine(void);								//药品信息初始化的函数
void modifymedicine(int bn);							//修改药品信息的函数
int addmedicine(int bn);								//添加药品信息的函数
int delmedicine(int bn);								//删除药品信息的函数
void outputonemedicine(int i);							//输出一种药品信息的函数
void outputallmedicines(int bn);						//输出全部药品详细信息的函数
void outputbrief(int bn);								//输出全部药品简要信息的函数

//药品查询模块的函数声明//
void searchmenu(int bn);								//药品查询函数
void SearchISBN(int bn);								//按编号查询函数
void searchmedicinename(int bn);						//按药名查询函数
void searchmamu(int bn);								//按厂家查询函数
						
//药品销售模块的函数声明//
void salemedicine(int bn);						//药品销售函数

int main()
{
	int select,bn,sn=0;
	//调用loadmedicines(),返回值为药品数量，将其赋值给bn;
	bn=loadmedicines();								
	if(bn==0)
		printf("药品信息为空!\n\n");
	while(1)
	{
		printf("\n");
		printf("\t----------------------------------------------\n");
		printf("\t*                                            *\n");
		printf("\t*            药品管理系统                    *\n");
		//这个地方你没有显示相应的选择项，那么用户如何知道该输入什么东西呢?
		printf("\t*1.用户登录               0.用户退出该系统   *\n");
		printf("\t*                                            *\n");
		printf("\t----------------------------------------------\n");
		//这个地方需要打印一个提示 
		printf("\n请选择要进行的操作:\n");
	    scanf("%d",&select);
	    
		switch(select)
		{
			//能告诉我sn的值是什么吗? 这个地方sn的值都不知道是什么，为什么要用sn啊？ 
			case 1:managerlogin(&bn,&sn);break;	
			case 0:printf("谢谢使用!再见\n");exit(1);break;//end while
	        default:printf("\n按键错误，请重新选择!\n");break;
		}											
	}	
	return 0;											
}

//用户登录模块的函数定义
//============================================================================//
//功能:实现管理员登录，显示管理员用户的菜单，进行功能选择
//参数:pbn,psn分别为main函数中变量bn,sn的地址
//返回值:无
//主要思路:用strcmp函数实现密码验证，用switch结构实现菜单功能选择
//============================================================================//
void managerlogin(int *pbn,int *spn)
{
	//这个地方需要空读因为没有空读就会让密码配对出现错误。 
	getchar();									//空读
	int select,flag=0;
	char password[11];								//密码最多为10位
	printf("\n 请输入密码: \n");
	gets(password);
	//这里需要空读 
	getchar();
	if(strcmp(password,"123")!=0)					//密码需要事先设置好，这里假设为"123"
	{
		printf("\n密码错误,请重新输入:\n");
		return ;								
	}
	printf("\n");
	printf("管理员，您好!\n");
	while(1)
	{
		printf("------------------------------------------------------\n");
		printf("	1. 药品信息初始化		5. 输出药品信息\n");
	    printf("	2. 修改药品信息			6. 药品信息查询\n");
		printf("	3. 增加药品信息			7. 药品销售管理\n");
		printf("	4. 删除药品信息			0. 返回主菜单\n");
		printf("------------------------------------------------------\n");
		printf("请选择您需要的服务(0-7): ");
		scanf("%d",&select);
		getchar();
		switch(select)
		{
			case 1:*pbn=originalmedicine();break;	
			case 2:modifymedicine(*pbn);break;	
			case 3:*pbn=addmedicine(*pbn);break;	
			case 4:*pbn=delmedicine(*pbn);break;	
			case 5:
			{
				printf("输出详细信息按'1',输出简要信息请按'2': ");
				scanf("%d",&flag);
				getchar();
				if(flag==1)
					outputallmedicines(*pbn);
				if(flag==2)	
					outputbrief(*pbn);
			}break;	
			case 6:searchmenu(*pbn);break;
			//case 7:*pbn=salemedicine(bn);break;	
			//case 7:*pbn=salemedicine(int bn,int m);break;
			case 0:return;
			default:printf("\n按键错误，请重新选择！\n");
		}																//end switch
	}																	//end while
}

//药品信息管理模块的函数定义
//===================================================================================//
//功能：从键盘输入一种药品的全部信息
//参数：i表示对第i种药品的进行输入操作
//返回：无
//主要思路：按提示信息用scanf输入药品的各项信息，存放到数组medicine中
//====================================================================================//
void inputonemedicine(int i)
{
	printf("编号: ");
	//gets(medicine[i].ISBN);
	scanf("%d",&medicine[i].ISBN);
	//这个地方需要使用空读来消除回车的影响 
	getchar();
	printf("名称: ");
	gets(medicine[i].medicinename);
	printf("库存数量:");
	//gets(medicine[i].quantity);
	scanf("%d",&medicine[i].quantity);
	printf("价格: ");
	//gets(medicine[i].sprice);
	scanf("%f",&medicine[i].price);
	//这个地方需要用空读来消除回车的影响 
	getchar();
	printf("药品厂家: ");
	gets(medicine[i].manu);
	printf("生产日期(年.月): ");
    scanf("%d.%d",&medicine[i].produce_time.year,&medicine[i].produce_time.month);
	medicine[i].produce_time.day=0;
	getchar();
}

//=====================================================================================//
//功能:从文件msdicine.dat中载入全部药品信息
//参数:无
//返回:返回文件中药品的数量
//主要思路:用while循环从文件读取药品信息到数组medicine，同时统计药品数量
//=====================================================================================//
//函数如果没有形参的话，不需要使用void来标注 
//int loadmedicines(void)
int loadmedicines()
{
	FILE *fb;
	int bn=0;											//变量bn用来记录药品的数量
	if((fb=fopen("medicine.dat","rb+"))==NULL)			//以二进制读、写方式打开文件
    {
		printf("cant open file medicine.dat\n");
		return(bn);										//文件打开失败时，返回值为0								
	}
	while(!feof(fb))									//文件没有结束时进行读数据操作
		if(fread(&medicine[bn],SMEDICINE_LEN,1,fb))
			bn++;										//从文件中每读一种药品，药品数量加1
	fclose(fb);										    //关闭文件
	return(bn);									        //返回图书数量，即bn的值
}

//====================================================================================//
//功能:将一种药品的信息保存到文件medicine.dat中
//参数:i将表示第i种药品的信息保存到文件中
//返回:无
//主要思路:先用fseek函数定位，再用fwrite函数写入第i种药品的信息
//====================================================================================//
void saveonemedicine(int i)
{
	FILE *fb;
	//if((fb=fopen("book.dat","rb+"))==NULL)				//以二进制读、写的方式打开文件
	if((fb==fopen("medicine.dat","rb+"))==NULL)
	{
		printf("can't open file medicine.dat\n");
		exit(1);
	}
	fseek(fb,SMEDICINE_LEN*i,0);						//文件指针定位到第i种药品
	//fwrite(&book[i],SMEDICINE_LEN,1,fb);				//将第i种药品的信息写入文件
	fwrite(&medicine[i],SMEDICINE_LEN,1,fb);
	fclose(fb);
}

//====================================================================================//
//功能:将全部药品的信息保存到文件medicine.dat中
//参数:bn表示图书的数量
//返回:无
//主要思路:用fwrite函数将数组medicine中的数据一次性写入文件
//====================================================================================//
void saveallmedicines(int bn)
{
	//file*b;
	FILE *fb;
	if((fb=fopen("medicine.dat","wb"))==NULL)					//以二进制写方式打开文件
	{
		printf("can't open file medicine.dat\n ");
		exit(1);
	}
	fwrite(medicine,SMEDICINE_LEN,bn,fb);
	fclose(fb);
}

//=====================================================================================//
//功能:实现药品信息的初始化
//参数:无
//返回:输出药品的数量
//主要思路:用for循环实现输入多种药品信息,并写入文件
//======================================================================================//
//int originalmedicine(void)
int originalmedicine()
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='y';n++)
	{
		printf("\n输入药品%d的信息: \n",n+1);
		inputonemedicine(n);								//调用函数，输入第n种药品
		printf("\n继续输入请按'y',停止请按'n':");
		c=getchar();
		//这里没必要吧 
		//getchar();
	}
	saveallmedicines(n);									//将输入的n种药品的数据保存至文件
	return(n);												//返回n的值，即输出药品的数量
}

//========================================================================================//
//功能:修改药品信息
//参数:bn表示药品的数量
//返回:无
//主要思路:通过switch实现修改药品的任意信息项，并将修改后的信息写入文件
//=========================================================================================//
void modifymedicine(int bn)
{
	int select,k=-1;
	char c1='y',c2;
	int isbn;
	if(bn==0)
	{
		printf("\n药品信息为空，无法执行操作!\n");
		return;														//返回到管理员功能选择菜单
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("请输入要修改的药品的编号: ");
		//gets(isbn);
		scanf("%d",&isbn);
		for(int i=0;i<bn;i++)
			//if(medicine[i].ISMN==isbn)
			if(medicine[i].ISBN==isbn)
			{
				k=i;
				break;
			}
		if(k<0)														//k小于0，表示在数组medicine中没有找到输入书号对应的药品
			printf("\n输入的编号有误，请重新输入！\n");
		else														//k大于0，表示在数组medicine中找到该图书，应进行以下操作
		{
			printf("此药品的信息: \n");
			//outputonebook(k);										//显示该药品的全部信息
			outputonemedicine(k);
			while(c2=='y'||c2=='Y')
			{
				printf("\n药品信息包括以下数据项\n");
				printf("---------------------------------------------------------------------------\n");
				printf("   1 编号                       5 药品厂家									 \n");
				printf("   2 药品名                     6 生产日期									 \n");
				printf("   3 库存数量                   7 药品进货价格								 \n");
				printf("   4 销售价格                   8 药品保质期(年.月)							 \n");
				printf("-----------------------------------------------------------------------------\n");
				printf("请输入要修改的数据项(1-9):	\n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("	编号:	");
						   scanf("%d",&medicine[k].ISBN);
						//gets(medicine[k].ISBN);
						break;
					case 2:printf("	药品名:	");
						gets(medicine[k].medicinename);
						break;
					case 3:printf("	库存数量:");
						//gets(medicine[i].quantity);
						scanf("%d",&medicine[k].quantity);
						break;
					case 4:printf("	销售价格:	");
						//gets(medicine[i].sprice);
						scanf("%f",&medicine[k].price);
						break;
					case 5:printf("	药品进货价格:	");
						//gets(medicine[i].price);
						scanf("%f",&medicine[k].iprice);
						break;
					case 6:printf("	生产日期:	");
						//gets(medicine[k].produce_time.year,&medicine[k].produce_time.month,produce_time.day);
						scanf("%d.%d.%d",medicine[k].produce_time.year,&medicine[k].produce_time.month,&medicine[k].produce_time.day);
						//这里为什么加上一个getchar(); 
						//getchar();
						break;
					default:printf("\n按键错误，请重新输入!\n");
				}//end switch
				//这里不用写的 
					//printf("还要修改此药品的其他信息吗？(y/n):");
					//c2=getchar();
					//getchar();
			}//end while(c2)
		}
		//saveonemedicine(k);									//保存修改后的药品信息
		printf("\n还要修改此药品的其他信息吗？(y/n):");
		c1=getchar();
		//getchar();
	}															//end while(c1)
	//这些都没有，加上它们干什么啊? 
	//printf("\n按任意键继续!\n");
	//getchar();
}

//========================================================================================//
//功能:添加药品信息
//参数:bn表示添加前的药品数量
//返回:添加后的药品数量
//主要思路:调用inputonemedicine函数输入要添加的药品信息，再用fwrite将其写入文件
//===========================================================================================//
int addmedicine(int bn)
{
	char c='y';
	//file *fb;
	FILE *fb;
	if((fb=fopen("medicine.dat","ab"))==NULL)						//以二进制追加方式打开文件
	{
		printf("can't open file medicine.dat\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("请输入新增药品的信息:\n");
		inputonemedicine(bn);										//调用函数，输入第n种药品的信息
		fwrite(&medicine[bn],SMEDICINE_LEN,1,fb);					//将第bn种药品的信息保存至文件
		bn++;														//药品数量加1
		printf("\n继续输入其他新药品的信息吗(y/n)?");
		c=getchar();
		//这里没有用啊? 
		//getchar();
	}
	//这里也没有用啊 
	//printf("\n按任意键继续!\n");
	//getch();
	fclose(fb);
	return(bn);														//返回添加药品后的图书数量
}

//=============================================================================================//
//功能:删除药品信息
//参数:bn表示删除前的药品数量
//返回:删除后的药品数量
//主要思路:先输入要删除的药品编号，找到该药品后进行删除操作，再调用saveallmedicines
//					函数将删除后的药品信息写入文件
//===============================================================================================//
int delmedicine(int bn)
{
	int i,k=-1;
	//这里的c不赋初始值他的第一次该如何实现呢？ 
	//char c2,c;
	char c2,c='y'; 
	int isbn; 
	if(bn==0)
	{
		printf("药品信息为空，无法进行操作!\n");
		return(bn);
	}
	while(c=='y'||c=='Y')
	{
		//这里写不写都无所谓，因为后面有赋值嘛. 
		c2='n';
		printf("\n请输入要删除的药品编号:	");
		scanf("%d",&isbn);
		//这里差一个getchar（）；
		getchar(); 
		for(i=0;i<bn;i++)
			if(medicine[i].ISBN==isbn)
			{
				k=i;													//找到要删除的药品，用k记录其下标
				break;
			}
			if(k<0)														//k小于0，表示没找到输入编号所对应的药品
				printf("\n输入的编号有误，请重新输入!\n");
			else
			{
				printf("\n显示该药品的信息:\n");
				outputonemedicine(k);
				//暴漏了吧！！！ 
				//printf("\n确定要删除该图书的全部信息吗？(y/n):	");
				printf("\n确定要删除该药品的全部信息吗？(y/n):	");
				c2=getchar();
				getchar();
				if(c2=='y'||c2=='Y')												//c2为'y'，表示确定进行删除操作
				{
					for(i=k;i<bn;i++)
						medicine[i]=medicine[i+1];						//从数组中删除第k种药品
					bn--;												//药品数量减1
					printf("\n成功删除!\n");
				}
				else													//c2为n，表示不进行删除操作
					printf("\n取消删除!\n");
				printf("\n继续删除其他药品的信息吗？(y/n):");
				c=getchar();
				//getchar();
			}
	}//end while
	saveallmedicines(bn);
	//这里没有用啊?													//保存删除后的全部药品信息
	//printf("\n按任意键继续！\n");
	//getchar();
	return(bn);															//返回删除后的药品数量
}
//================================================================================================//
//功能:输出一种药品
//参数:i表示对第种药品进行输出操作
//返回:无
//主要思路:用printf函数输出一种图书的全部信息
//=================================================================================================//
void outputonemedicine(int i)
{
	printf("\n");
	printf(" 编号 : %d\n",medicine[i].ISBN);
	//puts(medicine[i].ISBN);
	printf(" 药品名 : %s\n",medicine[i].medicinename);
	//puts();
	printf(" 库存数量: %d\n",medicine[i].quantity);
	//puts(medicine[i].quantity);
	//这个地方你定义的是price啊 
	//printf(" 销售价格: %.3f\n",medicine[i].sprice);
	printf(" 销售价格: %.3f\n",medicine[i].price);
	//puts();
	printf(" 药品进货价格: %.3\n",medicine[i].price);
	//puts();
	printf(" 生产日期: %d.%d.%d\n",medicine[i].produce_time.year,medicine[i].produce_time.month,medicine[i].produce_time.day);
	//printf("",);
}

//==================================================================================================//
//功能:输出全部药品的详细信息
//参数:bn表示药品的数量
//返回:无
//主要思路:通过for循环多次调用outputonemedicine函数是输出全部药品的信息
//==================================================================================================//
void outputallmedicines(int bn)
{
	int i;
	printf("\n全部药品详细信息: ");
	for(i=0;i<bn;i++)								//用循环输出全部药品的信息
	{
		outputonemedicine(i);						//调用函数，输出第i种药品的信息
		//写这两句话有什么用啊？闲的吗？自己给自己找事情干啊？ 
		//printf("\n按任意键继续!\n");
		//getch();
	}
	printf("\n全部信息输出完毕。\n");
	//写这两句话有什么用啊？闲的吗？自己给自己找事情干啊？ 
	//printf("\n按任意键返回!\n");
	//getch();
}

//====================================================================================================//
//功能:以列表的方式输出全部药品的简要信息
//参数:bn表示药品的数量
//返回:无
//主要思路:用for循环输出全部药品的简要信息(编号、药品名、库存数量)
//===================================================================================================//
void outputbrief(int bn)
{
	int i;
	printf("\n全部药品的简要信息:  \n");
	printf("\n 序号   编号   药品名     库存量 \n");
	for(i=0;i<bn;i++)
	{
		//这里你自己写的都是按照数字来输出，那么为什么声明的时候要声明成  字符数组 啊? 
		//这里我改了 
		//printf("%2d%-18d%-20s%-%5d\n",i+1,medicine[i].ISBN,medicine[i].medicinename,medicine[i].quantity);
		//难道分不请%的用法吗?
		printf("%2d	%d	%s	%5d\n",i+1,medicine[i].ISBN,medicine[i].medicinename,medicine[i].quantity); 
	}
	//以后不要再写这些东西了 
	//printf("\n按任意键继续 \n");
	//getchar();
}

//==============================================================================================//
//功能:实现查询的主菜单 
//参数:bn表示药品的数量
//返回:无
//主要思路:通过switch实现对药品的任意信息项的查询
//===================================================================================================//
void searchmenu(int bn)
{    
	int select;
	while(1)
	{   printf("\n       欢迎使用药品查询服务\n");
		printf("------------------------------------------------------------------------\n");
		printf("   1. 按编号查询                   2.按药名查询\n");
		printf("   3. 按厂家查询                   0. 退出查询服务\n");
		printf("-------------------------------------------------------------------------\n");
		printf("\n请选择查询方式(0-3):");
		scanf("%d",& select);
		getchar();
		switch(select)
		{ 
	        case 1: SearchISBN(bn);break;
	        case 2:searchmedicinename(bn);break;
	        case 3:searchmamu(bn);break;
			//case 2: SearchMedicinename(bn);break;
			//case 3: SearchMamu(bn);break;
			case 0: return;
			default: printf("\n按键错误,请重新选择!\n");break;
		}
	}
}

//===============================================================================================//
//功能:按编号进行药品查询
//参数:bn表示图书的数量
//返回:无
//主要思路:输入药品编号,直接用函数进行模糊查询
//================================================================================================//
void SearchISBN(int bn)
{    
	int i,j,k;
	char c='y';
	int ISBN; 
	//while(c='y'||c='Y');
	while(c=='y'||c=='Y')
	{  
		k=-1;
		printf("请输入药品编号:");
		scanf("%d",&ISBN);
		//gets(TSBN);
		//j 有用到吗? 
		for(i=0,j=1;i<bn;i++)
			if(medicine[i].ISBN==ISBN)
			{   
				k=i;
				printf("\n药品%d的信息:\n",j++);
				outputonemedicine(k);
				//printf("\n按任意键继续!\n");
				//getch();
			}
		if(k==-1)
			printf("\n抱歉!没有相应药品的信息!\n");
		printf("\n继续查询其他药品的信息吗?(y/n):");
		c=getchar();  
		getchar();
	}
	//printf("\n按任意键继续!\n");
	//getch();
}

//=====================================================================================================//
//功能:按药品名进行药品查询
//参数:bn表示药品数量
//返回:无
//主要思路:输入药品名,先用strcmp函数进行精确查询,若无查询结果,再用strstr函数进行模糊查询
//=====================================================================================================//
void searchmedicinename(int bn)
{     
	int i,j,k;
	char medicinename[40],c='y';
	//while(c=='y'||'Y')
	while(c=='y'||c=='Y') 
	{   
		k=-1;
	    printf("\n请输入药名:");
		//gets(mname);
		gets(medicinename);
		//j 有用到吗? 
		for(i=0,j=1;i<bn;i++)
		//for(i=0;i<bn;i++)
			if(strcmp(medicine[i].medicinename,medicinename)==0)        //精确查询
			{  
			    k=i;
			    printf("\n药品%d的信息: \n",j++);
			    outputonemedicine(k);
			    //printf("\n按任意键继续!\n"); getch();
			}
		 //if(k==1)
		 //这里应该是k==-1吧
		 if(k==-1) 
		 {   
		 	 printf("\n模糊查询结果如下: \n");
		     for(i=0,j=1;i<bn;i++)
		     	  if(strstr(medicine[i].medicinename,medicinename)!=NULL)  //模糊查询
				 //if(strstr(medicine[i].medicine,medicine)!=NULL)  //模糊查询
				 {  
				 	k=i;
				    printf("\n药品%d的信息: \n",j++);
					outputonemedicine(k);
					//printf("\n按任意键继续!\n");
					//getch();
				 }
			if(j==1) printf("\n抱歉!没有相应的药品信息!\n");
		 }
		 printf("\n继续查询其他药品的信息吗?(y/n):");
		 c=getchar(); 
		 getchar();
	}
	//printf("\n按任意键继续!\n");
	//getchar();
}
//==============================================================================//
//功能:按药品厂家查询药品
//参数:bn表示图书数量
//返回:无
//主要思路:输入药品厂家名称,直接用strstr函数进行模糊查询
//==============================================================================//
void searchmamu(int bn)
{    
	int i,j,k;
	char mmamu[40],c='y';
	//while(c='y'||c='Y')
	while(c=='y'||c=='Y')
	{  
	   k=-1;
	   printf("\n请输入药品厂家:");
	   gets(mmamu);
	   for(i=0,j=1;i<bn;i++)
	   		if(strstr(medicine[i].manu,mmamu)!=NULL)
		   //if(strstr(medicine[i].medicinemamu,mmamu)!=NULL)
		   {  
		   	  k=i;
		      printf("\n药品厂家的%d药品的信息:\n",j++);
			  outputonemedicine(k);
			  //printf("\n按任意键继续!\n");
//			  getchar();
		   }
		if(k==-1) 
			printf("\n抱歉!没有相应的药品信息!\n");
		printf("\n继续查询其它药品的信息吗?(y/n):");
		c=getchar();
		getchar();
	}
	//printf("\n按任意键继续!\n");
//	getchar();
}



