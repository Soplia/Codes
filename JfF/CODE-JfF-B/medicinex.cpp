#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ṹ�����͵Ķ���

//��������
typedef struct date									
{
	int year;										//��
	int month;									//��
	int day;										//��
}SDATE;

//ҩƷ����
typedef struct medicine								
{
	//���ﲻ��Ҫ����� 
	//char ISBN [20];	
	//���ﲻ��Ҫ�����										
    //char quantity[20];								
    //���ﲻ��Ҫ�����
	//char price[20];								
	//���ﲻ��Ҫ�����
	//char iprice[20];	
								
	int ISBN;//ҩƷ���
	char medicinename[40];//ҩƷ����
	char manu[40];//ҩƷ����(manufacturers)
	float price;//ҩƷ���ۼ۸�
	float iprice;//ҩƷ�����۸�
    int quantity;//ҩƷ�������
	SDATE produce_time;//ҩƷ��������(date of manufacture)	
}SMEDICINE;
SMEDICINE medicine[1000];
//SMEDICINE_LENΪҩƷ����ռ�ô洢�ռ�Ĵ�С
#define SMEDICINE_LEN sizeof(SMEDICINE)				
#define SDATE_LEN sizeof(SDATE)						

//�û���¼ģ��ĺ�������
void managerlogin(int *pbn,int *psn);					//�û���¼���� 



//ҩƷ��Ϣ����ģ��ĺ�������
void inputonemedicine(int i);							//����һ��ҩƷ��Ϣ�ĺ���
int loadmedicines(void);								//���ļ�����ȫ��ҩƷ��Ϣ�ĺ���
void saveonemedicine(int i);							//����һ��ҩƷ��Ϣ�ĺ���
void saveallmedicines(int bn);							//����ȫ��ҩƷ��Ϣ�ĺ���
int originalmedicine(void);								//ҩƷ��Ϣ��ʼ���ĺ���
void modifymedicine(int bn);							//�޸�ҩƷ��Ϣ�ĺ���
int addmedicine(int bn);								//���ҩƷ��Ϣ�ĺ���
int delmedicine(int bn);								//ɾ��ҩƷ��Ϣ�ĺ���
void outputonemedicine(int i);							//���һ��ҩƷ��Ϣ�ĺ���
void outputallmedicines(int bn);						//���ȫ��ҩƷ��ϸ��Ϣ�ĺ���
void outputbrief(int bn);								//���ȫ��ҩƷ��Ҫ��Ϣ�ĺ���

//ҩƷ��ѯģ��ĺ�������//
void searchmenu(int bn);								//ҩƷ��ѯ����
void SearchISBN(int bn);								//����Ų�ѯ����
void searchmedicinename(int bn);						//��ҩ����ѯ����
void searchmamu(int bn);								//�����Ҳ�ѯ����
						
//ҩƷ����ģ��ĺ�������//
void salemedicine(int bn);						//ҩƷ���ۺ���

int main()
{
	int select,bn,sn=0;
	//����loadmedicines(),����ֵΪҩƷ���������丳ֵ��bn;
	bn=loadmedicines();								
	if(bn==0)
		printf("ҩƷ��ϢΪ��!\n\n");
	while(1)
	{
		printf("\n");
		printf("\t----------------------------------------------\n");
		printf("\t*                                            *\n");
		printf("\t*            ҩƷ����ϵͳ                    *\n");
		//����ط���û����ʾ��Ӧ��ѡ�����ô�û����֪��������ʲô������?
		printf("\t*1.�û���¼               0.�û��˳���ϵͳ   *\n");
		printf("\t*                                            *\n");
		printf("\t----------------------------------------------\n");
		//����ط���Ҫ��ӡһ����ʾ 
		printf("\n��ѡ��Ҫ���еĲ���:\n");
	    scanf("%d",&select);
	    
		switch(select)
		{
			//�ܸ�����sn��ֵ��ʲô��? ����ط�sn��ֵ����֪����ʲô��ΪʲôҪ��sn���� 
			case 1:managerlogin(&bn,&sn);break;	
			case 0:printf("ллʹ��!�ټ�\n");exit(1);break;//end while
	        default:printf("\n��������������ѡ��!\n");break;
		}											
	}	
	return 0;											
}

//�û���¼ģ��ĺ�������
//============================================================================//
//����:ʵ�ֹ���Ա��¼����ʾ����Ա�û��Ĳ˵������й���ѡ��
//����:pbn,psn�ֱ�Ϊmain�����б���bn,sn�ĵ�ַ
//����ֵ:��
//��Ҫ˼·:��strcmp����ʵ��������֤����switch�ṹʵ�ֲ˵�����ѡ��
//============================================================================//
void managerlogin(int *pbn,int *spn)
{
	//����ط���Ҫ�ն���Ϊû�пն��ͻ���������Գ��ִ��� 
	getchar();									//�ն�
	int select,flag=0;
	char password[11];								//�������Ϊ10λ
	printf("\n ����������: \n");
	gets(password);
	//������Ҫ�ն� 
	getchar();
	if(strcmp(password,"123")!=0)					//������Ҫ�������úã��������Ϊ"123"
	{
		printf("\n�������,����������:\n");
		return ;								
	}
	printf("\n");
	printf("����Ա������!\n");
	while(1)
	{
		printf("------------------------------------------------------\n");
		printf("	1. ҩƷ��Ϣ��ʼ��		5. ���ҩƷ��Ϣ\n");
	    printf("	2. �޸�ҩƷ��Ϣ			6. ҩƷ��Ϣ��ѯ\n");
		printf("	3. ����ҩƷ��Ϣ			7. ҩƷ���۹���\n");
		printf("	4. ɾ��ҩƷ��Ϣ			0. �������˵�\n");
		printf("------------------------------------------------------\n");
		printf("��ѡ������Ҫ�ķ���(0-7): ");
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
				printf("�����ϸ��Ϣ��'1',�����Ҫ��Ϣ�밴'2': ");
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
			default:printf("\n��������������ѡ��\n");
		}																//end switch
	}																	//end while
}

//ҩƷ��Ϣ����ģ��ĺ�������
//===================================================================================//
//���ܣ��Ӽ�������һ��ҩƷ��ȫ����Ϣ
//������i��ʾ�Ե�i��ҩƷ�Ľ����������
//���أ���
//��Ҫ˼·������ʾ��Ϣ��scanf����ҩƷ�ĸ�����Ϣ����ŵ�����medicine��
//====================================================================================//
void inputonemedicine(int i)
{
	printf("���: ");
	//gets(medicine[i].ISBN);
	scanf("%d",&medicine[i].ISBN);
	//����ط���Ҫʹ�ÿն��������س���Ӱ�� 
	getchar();
	printf("����: ");
	gets(medicine[i].medicinename);
	printf("�������:");
	//gets(medicine[i].quantity);
	scanf("%d",&medicine[i].quantity);
	printf("�۸�: ");
	//gets(medicine[i].sprice);
	scanf("%f",&medicine[i].price);
	//����ط���Ҫ�ÿն��������س���Ӱ�� 
	getchar();
	printf("ҩƷ����: ");
	gets(medicine[i].manu);
	printf("��������(��.��): ");
    scanf("%d.%d",&medicine[i].produce_time.year,&medicine[i].produce_time.month);
	medicine[i].produce_time.day=0;
	getchar();
}

//=====================================================================================//
//����:���ļ�msdicine.dat������ȫ��ҩƷ��Ϣ
//����:��
//����:�����ļ���ҩƷ������
//��Ҫ˼·:��whileѭ�����ļ���ȡҩƷ��Ϣ������medicine��ͬʱͳ��ҩƷ����
//=====================================================================================//
//�������û���βεĻ�������Ҫʹ��void����ע 
//int loadmedicines(void)
int loadmedicines()
{
	FILE *fb;
	int bn=0;											//����bn������¼ҩƷ������
	if((fb=fopen("medicine.dat","rb+"))==NULL)			//�Զ����ƶ���д��ʽ���ļ�
    {
		printf("cant open file medicine.dat\n");
		return(bn);										//�ļ���ʧ��ʱ������ֵΪ0								
	}
	while(!feof(fb))									//�ļ�û�н���ʱ���ж����ݲ���
		if(fread(&medicine[bn],SMEDICINE_LEN,1,fb))
			bn++;										//���ļ���ÿ��һ��ҩƷ��ҩƷ������1
	fclose(fb);										    //�ر��ļ�
	return(bn);									        //����ͼ����������bn��ֵ
}

//====================================================================================//
//����:��һ��ҩƷ����Ϣ���浽�ļ�medicine.dat��
//����:i����ʾ��i��ҩƷ����Ϣ���浽�ļ���
//����:��
//��Ҫ˼·:����fseek������λ������fwrite����д���i��ҩƷ����Ϣ
//====================================================================================//
void saveonemedicine(int i)
{
	FILE *fb;
	//if((fb=fopen("book.dat","rb+"))==NULL)				//�Զ����ƶ���д�ķ�ʽ���ļ�
	if((fb==fopen("medicine.dat","rb+"))==NULL)
	{
		printf("can't open file medicine.dat\n");
		exit(1);
	}
	fseek(fb,SMEDICINE_LEN*i,0);						//�ļ�ָ�붨λ����i��ҩƷ
	//fwrite(&book[i],SMEDICINE_LEN,1,fb);				//����i��ҩƷ����Ϣд���ļ�
	fwrite(&medicine[i],SMEDICINE_LEN,1,fb);
	fclose(fb);
}

//====================================================================================//
//����:��ȫ��ҩƷ����Ϣ���浽�ļ�medicine.dat��
//����:bn��ʾͼ�������
//����:��
//��Ҫ˼·:��fwrite����������medicine�е�����һ����д���ļ�
//====================================================================================//
void saveallmedicines(int bn)
{
	//file*b;
	FILE *fb;
	if((fb=fopen("medicine.dat","wb"))==NULL)					//�Զ�����д��ʽ���ļ�
	{
		printf("can't open file medicine.dat\n ");
		exit(1);
	}
	fwrite(medicine,SMEDICINE_LEN,bn,fb);
	fclose(fb);
}

//=====================================================================================//
//����:ʵ��ҩƷ��Ϣ�ĳ�ʼ��
//����:��
//����:���ҩƷ������
//��Ҫ˼·:��forѭ��ʵ���������ҩƷ��Ϣ,��д���ļ�
//======================================================================================//
//int originalmedicine(void)
int originalmedicine()
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='y';n++)
	{
		printf("\n����ҩƷ%d����Ϣ: \n",n+1);
		inputonemedicine(n);								//���ú����������n��ҩƷ
		printf("\n���������밴'y',ֹͣ�밴'n':");
		c=getchar();
		//����û��Ҫ�� 
		//getchar();
	}
	saveallmedicines(n);									//�������n��ҩƷ�����ݱ������ļ�
	return(n);												//����n��ֵ�������ҩƷ������
}

//========================================================================================//
//����:�޸�ҩƷ��Ϣ
//����:bn��ʾҩƷ������
//����:��
//��Ҫ˼·:ͨ��switchʵ���޸�ҩƷ��������Ϣ������޸ĺ����Ϣд���ļ�
//=========================================================================================//
void modifymedicine(int bn)
{
	int select,k=-1;
	char c1='y',c2;
	int isbn;
	if(bn==0)
	{
		printf("\nҩƷ��ϢΪ�գ��޷�ִ�в���!\n");
		return;														//���ص�����Ա����ѡ��˵�
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("������Ҫ�޸ĵ�ҩƷ�ı��: ");
		//gets(isbn);
		scanf("%d",&isbn);
		for(int i=0;i<bn;i++)
			//if(medicine[i].ISMN==isbn)
			if(medicine[i].ISBN==isbn)
			{
				k=i;
				break;
			}
		if(k<0)														//kС��0����ʾ������medicine��û���ҵ�������Ŷ�Ӧ��ҩƷ
			printf("\n����ı���������������룡\n");
		else														//k����0����ʾ������medicine���ҵ���ͼ�飬Ӧ�������²���
		{
			printf("��ҩƷ����Ϣ: \n");
			//outputonebook(k);										//��ʾ��ҩƷ��ȫ����Ϣ
			outputonemedicine(k);
			while(c2=='y'||c2=='Y')
			{
				printf("\nҩƷ��Ϣ��������������\n");
				printf("---------------------------------------------------------------------------\n");
				printf("   1 ���                       5 ҩƷ����									 \n");
				printf("   2 ҩƷ��                     6 ��������									 \n");
				printf("   3 �������                   7 ҩƷ�����۸�								 \n");
				printf("   4 ���ۼ۸�                   8 ҩƷ������(��.��)							 \n");
				printf("-----------------------------------------------------------------------------\n");
				printf("������Ҫ�޸ĵ�������(1-9):	\n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("	���:	");
						   scanf("%d",&medicine[k].ISBN);
						//gets(medicine[k].ISBN);
						break;
					case 2:printf("	ҩƷ��:	");
						gets(medicine[k].medicinename);
						break;
					case 3:printf("	�������:");
						//gets(medicine[i].quantity);
						scanf("%d",&medicine[k].quantity);
						break;
					case 4:printf("	���ۼ۸�:	");
						//gets(medicine[i].sprice);
						scanf("%f",&medicine[k].price);
						break;
					case 5:printf("	ҩƷ�����۸�:	");
						//gets(medicine[i].price);
						scanf("%f",&medicine[k].iprice);
						break;
					case 6:printf("	��������:	");
						//gets(medicine[k].produce_time.year,&medicine[k].produce_time.month,produce_time.day);
						scanf("%d.%d.%d",medicine[k].produce_time.year,&medicine[k].produce_time.month,&medicine[k].produce_time.day);
						//����Ϊʲô����һ��getchar(); 
						//getchar();
						break;
					default:printf("\n������������������!\n");
				}//end switch
				//���ﲻ��д�� 
					//printf("��Ҫ�޸Ĵ�ҩƷ��������Ϣ��(y/n):");
					//c2=getchar();
					//getchar();
			}//end while(c2)
		}
		//saveonemedicine(k);									//�����޸ĺ��ҩƷ��Ϣ
		printf("\n��Ҫ�޸Ĵ�ҩƷ��������Ϣ��(y/n):");
		c1=getchar();
		//getchar();
	}															//end while(c1)
	//��Щ��û�У��������Ǹ�ʲô��? 
	//printf("\n�����������!\n");
	//getchar();
}

//========================================================================================//
//����:���ҩƷ��Ϣ
//����:bn��ʾ���ǰ��ҩƷ����
//����:��Ӻ��ҩƷ����
//��Ҫ˼·:����inputonemedicine��������Ҫ��ӵ�ҩƷ��Ϣ������fwrite����д���ļ�
//===========================================================================================//
int addmedicine(int bn)
{
	char c='y';
	//file *fb;
	FILE *fb;
	if((fb=fopen("medicine.dat","ab"))==NULL)						//�Զ�����׷�ӷ�ʽ���ļ�
	{
		printf("can't open file medicine.dat\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("����������ҩƷ����Ϣ:\n");
		inputonemedicine(bn);										//���ú����������n��ҩƷ����Ϣ
		fwrite(&medicine[bn],SMEDICINE_LEN,1,fb);					//����bn��ҩƷ����Ϣ�������ļ�
		bn++;														//ҩƷ������1
		printf("\n��������������ҩƷ����Ϣ��(y/n)?");
		c=getchar();
		//����û���ð�? 
		//getchar();
	}
	//����Ҳû���ð� 
	//printf("\n�����������!\n");
	//getch();
	fclose(fb);
	return(bn);														//�������ҩƷ���ͼ������
}

//=============================================================================================//
//����:ɾ��ҩƷ��Ϣ
//����:bn��ʾɾ��ǰ��ҩƷ����
//����:ɾ�����ҩƷ����
//��Ҫ˼·:������Ҫɾ����ҩƷ��ţ��ҵ���ҩƷ�����ɾ���������ٵ���saveallmedicines
//					������ɾ�����ҩƷ��Ϣд���ļ�
//===============================================================================================//
int delmedicine(int bn)
{
	int i,k=-1;
	//�����c������ʼֵ���ĵ�һ�θ����ʵ���أ� 
	//char c2,c;
	char c2,c='y'; 
	int isbn; 
	if(bn==0)
	{
		printf("ҩƷ��ϢΪ�գ��޷����в���!\n");
		return(bn);
	}
	while(c=='y'||c=='Y')
	{
		//����д��д������ν����Ϊ�����и�ֵ��. 
		c2='n';
		printf("\n������Ҫɾ����ҩƷ���:	");
		scanf("%d",&isbn);
		//�����һ��getchar������
		getchar(); 
		for(i=0;i<bn;i++)
			if(medicine[i].ISBN==isbn)
			{
				k=i;													//�ҵ�Ҫɾ����ҩƷ����k��¼���±�
				break;
			}
			if(k<0)														//kС��0����ʾû�ҵ�����������Ӧ��ҩƷ
				printf("\n����ı����������������!\n");
			else
			{
				printf("\n��ʾ��ҩƷ����Ϣ:\n");
				outputonemedicine(k);
				//��©�˰ɣ����� 
				//printf("\nȷ��Ҫɾ����ͼ���ȫ����Ϣ��(y/n):	");
				printf("\nȷ��Ҫɾ����ҩƷ��ȫ����Ϣ��(y/n):	");
				c2=getchar();
				getchar();
				if(c2=='y'||c2=='Y')												//c2Ϊ'y'����ʾȷ������ɾ������
				{
					for(i=k;i<bn;i++)
						medicine[i]=medicine[i+1];						//��������ɾ����k��ҩƷ
					bn--;												//ҩƷ������1
					printf("\n�ɹ�ɾ��!\n");
				}
				else													//c2Ϊn����ʾ������ɾ������
					printf("\nȡ��ɾ��!\n");
				printf("\n����ɾ������ҩƷ����Ϣ��(y/n):");
				c=getchar();
				//getchar();
			}
	}//end while
	saveallmedicines(bn);
	//����û���ð�?													//����ɾ�����ȫ��ҩƷ��Ϣ
	//printf("\n�������������\n");
	//getchar();
	return(bn);															//����ɾ�����ҩƷ����
}
//================================================================================================//
//����:���һ��ҩƷ
//����:i��ʾ�Ե���ҩƷ�����������
//����:��
//��Ҫ˼·:��printf�������һ��ͼ���ȫ����Ϣ
//=================================================================================================//
void outputonemedicine(int i)
{
	printf("\n");
	printf(" ��� : %d\n",medicine[i].ISBN);
	//puts(medicine[i].ISBN);
	printf(" ҩƷ�� : %s\n",medicine[i].medicinename);
	//puts();
	printf(" �������: %d\n",medicine[i].quantity);
	//puts(medicine[i].quantity);
	//����ط��㶨�����price�� 
	//printf(" ���ۼ۸�: %.3f\n",medicine[i].sprice);
	printf(" ���ۼ۸�: %.3f\n",medicine[i].price);
	//puts();
	printf(" ҩƷ�����۸�: %.3\n",medicine[i].price);
	//puts();
	printf(" ��������: %d.%d.%d\n",medicine[i].produce_time.year,medicine[i].produce_time.month,medicine[i].produce_time.day);
	//printf("",);
}

//==================================================================================================//
//����:���ȫ��ҩƷ����ϸ��Ϣ
//����:bn��ʾҩƷ������
//����:��
//��Ҫ˼·:ͨ��forѭ����ε���outputonemedicine���������ȫ��ҩƷ����Ϣ
//==================================================================================================//
void outputallmedicines(int bn)
{
	int i;
	printf("\nȫ��ҩƷ��ϸ��Ϣ: ");
	for(i=0;i<bn;i++)								//��ѭ�����ȫ��ҩƷ����Ϣ
	{
		outputonemedicine(i);						//���ú����������i��ҩƷ����Ϣ
		//д�����仰��ʲô�ð����е����Լ����Լ�������ɰ��� 
		//printf("\n�����������!\n");
		//getch();
	}
	printf("\nȫ����Ϣ�����ϡ�\n");
	//д�����仰��ʲô�ð����е����Լ����Լ�������ɰ��� 
	//printf("\n�����������!\n");
	//getch();
}

//====================================================================================================//
//����:���б�ķ�ʽ���ȫ��ҩƷ�ļ�Ҫ��Ϣ
//����:bn��ʾҩƷ������
//����:��
//��Ҫ˼·:��forѭ�����ȫ��ҩƷ�ļ�Ҫ��Ϣ(��š�ҩƷ�����������)
//===================================================================================================//
void outputbrief(int bn)
{
	int i;
	printf("\nȫ��ҩƷ�ļ�Ҫ��Ϣ:  \n");
	printf("\n ���   ���   ҩƷ��     ����� \n");
	for(i=0;i<bn;i++)
	{
		//�������Լ�д�Ķ��ǰ����������������ôΪʲô������ʱ��Ҫ������  �ַ����� ��? 
		//�����Ҹ��� 
		//printf("%2d%-18d%-20s%-%5d\n",i+1,medicine[i].ISBN,medicine[i].medicinename,medicine[i].quantity);
		//�ѵ��ֲ���%���÷���?
		printf("%2d	%d	%s	%5d\n",i+1,medicine[i].ISBN,medicine[i].medicinename,medicine[i].quantity); 
	}
	//�Ժ�Ҫ��д��Щ������ 
	//printf("\n����������� \n");
	//getchar();
}

//==============================================================================================//
//����:ʵ�ֲ�ѯ�����˵� 
//����:bn��ʾҩƷ������
//����:��
//��Ҫ˼·:ͨ��switchʵ�ֶ�ҩƷ��������Ϣ��Ĳ�ѯ
//===================================================================================================//
void searchmenu(int bn)
{    
	int select;
	while(1)
	{   printf("\n       ��ӭʹ��ҩƷ��ѯ����\n");
		printf("------------------------------------------------------------------------\n");
		printf("   1. ����Ų�ѯ                   2.��ҩ����ѯ\n");
		printf("   3. �����Ҳ�ѯ                   0. �˳���ѯ����\n");
		printf("-------------------------------------------------------------------------\n");
		printf("\n��ѡ���ѯ��ʽ(0-3):");
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
			default: printf("\n��������,������ѡ��!\n");break;
		}
	}
}

//===============================================================================================//
//����:����Ž���ҩƷ��ѯ
//����:bn��ʾͼ�������
//����:��
//��Ҫ˼·:����ҩƷ���,ֱ���ú�������ģ����ѯ
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
		printf("������ҩƷ���:");
		scanf("%d",&ISBN);
		//gets(TSBN);
		//j ���õ���? 
		for(i=0,j=1;i<bn;i++)
			if(medicine[i].ISBN==ISBN)
			{   
				k=i;
				printf("\nҩƷ%d����Ϣ:\n",j++);
				outputonemedicine(k);
				//printf("\n�����������!\n");
				//getch();
			}
		if(k==-1)
			printf("\n��Ǹ!û����ӦҩƷ����Ϣ!\n");
		printf("\n������ѯ����ҩƷ����Ϣ��?(y/n):");
		c=getchar();  
		getchar();
	}
	//printf("\n�����������!\n");
	//getch();
}

//=====================================================================================================//
//����:��ҩƷ������ҩƷ��ѯ
//����:bn��ʾҩƷ����
//����:��
//��Ҫ˼·:����ҩƷ��,����strcmp�������о�ȷ��ѯ,���޲�ѯ���,����strstr��������ģ����ѯ
//=====================================================================================================//
void searchmedicinename(int bn)
{     
	int i,j,k;
	char medicinename[40],c='y';
	//while(c=='y'||'Y')
	while(c=='y'||c=='Y') 
	{   
		k=-1;
	    printf("\n������ҩ��:");
		//gets(mname);
		gets(medicinename);
		//j ���õ���? 
		for(i=0,j=1;i<bn;i++)
		//for(i=0;i<bn;i++)
			if(strcmp(medicine[i].medicinename,medicinename)==0)        //��ȷ��ѯ
			{  
			    k=i;
			    printf("\nҩƷ%d����Ϣ: \n",j++);
			    outputonemedicine(k);
			    //printf("\n�����������!\n"); getch();
			}
		 //if(k==1)
		 //����Ӧ����k==-1��
		 if(k==-1) 
		 {   
		 	 printf("\nģ����ѯ�������: \n");
		     for(i=0,j=1;i<bn;i++)
		     	  if(strstr(medicine[i].medicinename,medicinename)!=NULL)  //ģ����ѯ
				 //if(strstr(medicine[i].medicine,medicine)!=NULL)  //ģ����ѯ
				 {  
				 	k=i;
				    printf("\nҩƷ%d����Ϣ: \n",j++);
					outputonemedicine(k);
					//printf("\n�����������!\n");
					//getch();
				 }
			if(j==1) printf("\n��Ǹ!û����Ӧ��ҩƷ��Ϣ!\n");
		 }
		 printf("\n������ѯ����ҩƷ����Ϣ��?(y/n):");
		 c=getchar(); 
		 getchar();
	}
	//printf("\n�����������!\n");
	//getchar();
}
//==============================================================================//
//����:��ҩƷ���Ҳ�ѯҩƷ
//����:bn��ʾͼ������
//����:��
//��Ҫ˼·:����ҩƷ��������,ֱ����strstr��������ģ����ѯ
//==============================================================================//
void searchmamu(int bn)
{    
	int i,j,k;
	char mmamu[40],c='y';
	//while(c='y'||c='Y')
	while(c=='y'||c=='Y')
	{  
	   k=-1;
	   printf("\n������ҩƷ����:");
	   gets(mmamu);
	   for(i=0,j=1;i<bn;i++)
	   		if(strstr(medicine[i].manu,mmamu)!=NULL)
		   //if(strstr(medicine[i].medicinemamu,mmamu)!=NULL)
		   {  
		   	  k=i;
		      printf("\nҩƷ���ҵ�%dҩƷ����Ϣ:\n",j++);
			  outputonemedicine(k);
			  //printf("\n�����������!\n");
//			  getchar();
		   }
		if(k==-1) 
			printf("\n��Ǹ!û����Ӧ��ҩƷ��Ϣ!\n");
		printf("\n������ѯ����ҩƷ����Ϣ��?(y/n):");
		c=getchar();
		getchar();
	}
	//printf("\n�����������!\n");
//	getchar();
}



