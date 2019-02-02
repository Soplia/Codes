/**
  ******************************************************************************
  * @file    gsMazi.cpp
  * @author  JiaruiXie
  * @version V1.0
  * @date    01-Jan-2018
  * @brief   Achieve GS Algorithm in Machine Learning. 
  *          
  ******************************************************************************
  * @attention
  *
  * ���뻷���� Devcpp
  * PE��NE �����˳��Ҫ���� AttOrder ��˳����д 
  * AttValueOrder ��ÿ�����Ե�ȡֵ��Χ����С�����ĸ�������Ĳ� "" 
  * ����������������Ĭ������ͬ�ģ���Ϊ MAXINSNUM 
  * ���������� ��true- ��������false- δ������ 
  * ���������� ��true- ���ã�false- ������ 
  * �������� ��true- ���ã�false- ������ 
  * 
  * 
  * <h2><center>&copy; COPYRIGHT 2017 JiaruiXieFTCL</center></h2>
  ******************************************************************************
  */

#ifndef GS_MAZI_
#define GS_MAZI_

#include <iostream>
#include <cstring>
using namespace std;


/*********************************************************����һ��******************/
///���������뷴��������ͬ 
const int MAXINSNUM=5;
const int MAXATTNUM=5;
const int MAXATTVALUENUM=4;

//�������Ĺ��� 
int numOfRule=0;
int posInRule=0;
string GS[MAXINSNUM][MAXINSNUM];

string PE[MAXINSNUM][MAXATTNUM]={
									"high",	"heavy", "flack", "normal", "bubblelike",
									"mediu", "heavy","flack","normal","bubblelike",
									"low",	"slight","spot","normal","dry-peep",
									"high",	"mediu","flack","normal","bubblelike",
									"mediu","slight","flack","normal","bubblelike"
								};
								
string NE[MAXINSNUM][MAXATTNUM]={	
									"absent","slight","strip","normal","normal",
									"high",	"heavy",  "hole","fast","dry-peep",
									"low",	"slight", "strip","normal","normal",
									"absent","slight","spot","fast","dry-peep",
									"low","mediu","flack","fast","normal"
								};
								
string AttOrder[MAXATTNUM]={
							"Fever","Cough","X-ray","ESR","Auscultat"
							};

///�����Ӱ������Դ��ϵ��½������� 
string AttValueOrder[MAXATTNUM][MAXATTVALUENUM]={
													"high","mediu","low","absent",
													"heavy","slight","mediu", "",
													"flack","spot","strip","hole",
													"normal","fast","","",
													"bubblelike","dry-peep" ,"normal", ""
												};
												
												
int PosInsNum[MAXATTNUM][MAXATTVALUENUM];
int NegInsNum[MAXATTNUM][MAXATTVALUENUM];

///true :��������false��δ������ 
bool PosInsBeContained[MAXINSNUM];
bool NegInsBeContained[MAXINSNUM];

///true�����ã�false�������� 
bool PosInsBeUsed[MAXINSNUM];
bool NegInsBeUsed[MAXINSNUM];

///true�����ã�false�������� 
bool AttBeUsed[MAXATTNUM];
/*********************************************************����һ��******************/


/*********************************************************��ӡһ��***********/
void DisTF(bool flag)
{
	if(flag)
		cout<<"T"<<" ";
	else
		cout<<"F"<<" ";
}

void DisInsBeUsed()
{
	cout<<endl<<"PosInsBeUsed:"<<endl;
	for(int i=0;i<MAXINSNUM;i++)
		DisTF(PosInsBeUsed[i]);
		
	cout<<endl<<"NegInsBeUsed:"<<endl;
	for(int i=0;i<MAXINSNUM;i++)
		DisTF(NegInsBeUsed[i]);
	
	cout<<endl<<endl;
}

void DisInsBeContained()
{
	cout<<"PosInsBeContained:"<<endl;
	for(int i=0;i<MAXINSNUM;i++)
		DisTF(PosInsBeContained[i]);
		
	cout<<endl<<"NegInsBeContained:"<<endl;		
	for(int i=0;i<MAXINSNUM;i++)
		DisTF(NegInsBeContained[i]);
}

void DisAttBeUsed()
{
	cout<<endl<<"AttBeUsed:"<<endl;
	for(int i=0;i<MAXATTNUM;i++)
		DisTF(AttBeUsed[i]);
}

void DisNumMazi()
{
	cout<<"PosInsNumMazi:"<<endl;
	for(int i=0;i<MAXATTNUM;i++)
	{
		for(int j=0;j<MAXATTVALUENUM;j++)
			cout<<PosInsNum[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"NegInsNumMazi:"<<endl;
	for(int i=0;i<MAXATTNUM;i++)
	{
		for(int j=0;j<MAXATTVALUENUM;j++)
			cout<<NegInsNum[i][j]<<"  ";
		cout<<endl;
	}
}

void DisInsMazi()
{
	cout<<"PEMazi:"<<endl;
	for(int i=0;i<MAXINSNUM;i++)
	{
		for(int j=0;j<MAXATTNUM;j++)
			cout<<PE[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"NEMazi:"<<endl;
	for(int i=0;i<MAXINSNUM;i++)
	{
		for(int j=0;j<MAXATTNUM;j++)
			cout<<NE[i][j]<<"  ";
		cout<<endl;
	}
}

void DisGS()
{
	for(int i=0;i<MAXINSNUM&&GS[i][0]!="0";i++)
	{
		if(i!=0)
			cout<<"��";
		for(int j=0;j<MAXINSNUM&&GS[i][j]!="0";j++)
			cout<<"["<<GS[i][j]<<"]";
		
	}
}

/*********************************************************��ӡһ��***********/


/*********************************************************����һ��***********/
///��õ�row�����Ե�����ֵ���±� 
int FindAttValuePos(int row,string aim)
{
	if(row>=0&&row<MAXATTNUM&&aim!="")
	{
		for(int i=0;i<MAXATTVALUENUM;i++)
			if(AttValueOrder[row][i]==aim)
				return i;
		return -2;
	}		
	else
		return -1;
}


///���λ��posλ�ô������Ե����� 
string FindAtt(int pos)
{
	if(pos>=0&&pos<MAXATTNUM)
		return AttOrder[pos];
	else 
		return "gsMazi.cpp:"+__LINE__;
}

///���λ�ڵ�row�����Եĵ�col������ֵ 
string FindAttValue(int row,int col)
{
	if(row>=0&&row<MAXATTNUM&&col>=0&&col<MAXATTVALUENUM)
		return AttValueOrder[row][col];
	else 
		return "gsMazi.cpp:"+__LINE__;
}

///��ø���������࣬�ҷ������ٵ�λ���±� 
void GetMostPosLessNeg(int &row,int &col)
{
	row=col=0;
	int tempPos=PosInsNum[row][col];
	int tempNeg=NegInsNum[row][col];
	
	for(int i=0;i<MAXATTNUM;i++)
		if(AttBeUsed[i])//�����������ܹ���ʹ�ã��ͼ���ͳ���У�������ܹ���ʹ�þͲ�����ͳ���� 
			for(int j=0;j<MAXATTVALUENUM;j++)
			{
				//���������������һ�� 
				if(PosInsNum[i][j]>tempPos)
				{
					tempPos=PosInsNum[i][j];
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
				//�����������ͬ�����Ƿ������� 
				else if(PosInsNum[i][j]==tempPos&&NegInsNum[i][j]<tempNeg)
				{
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
			}
}

void GetMostPosLessNeg(int &row,int &col,int &posNum,int &negNum)
{
	row=col=0;
	int tempPos=PosInsNum[row][col];
	int tempNeg=NegInsNum[row][col];
	
	for(int i=0;i<MAXATTNUM;i++)
		if(AttBeUsed[i])//�����������ܹ���ʹ�ã��ͼ���ͳ���У�������ܹ���ʹ�þͲ�����ͳ����
			for(int j=0;j<MAXATTVALUENUM;j++)
			{
				//���������������һ�� 
				if(PosInsNum[i][j]>tempPos)
				{
					tempPos=PosInsNum[i][j];
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
				//�����������ͬ�����Ƿ������� 
				else if(PosInsNum[i][j]==tempPos&&NegInsNum[i][j]<tempNeg)
				{
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
			}
		posNum=tempPos;
		negNum=tempNeg;
}
/*********************************************************����һ��***********/


/*********************************************************����һ��***********/
bool FinishThisTurn()
{
	for(int i=0;i<MAXINSNUM;i++)
		if(NegInsBeContained[i])/*<  �������һ���������־�û�н���*/
			return false;
	return true;
}

bool FinishThisLoop()
{
	for(int i=0;i<MAXINSNUM;i++)
		if(PosInsBeUsed[i])/*<  �����һ�������ܹ���ʹ�þ�δ��������ѭ��*/
			return false;
	return true;
}

/*********************************************************����һ��***********/


/*********************************************************��ʼһ��***********/
///��ʼ���������� 
void initMaZi()
{
	memset(PosInsNum,0,sizeof(PosInsNum));
	memset(NegInsNum,0,sizeof(NegInsNum));
	
	for(int i=0;i<MAXINSNUM;i++)
		for(int j=0;j<MAXINSNUM;j++)
			GS[i][j]="0";
	
	for(int i=0;i<MAXINSNUM;i++)
	{
		PosInsBeContained[i]=true;
		NegInsBeContained[i]=true;
		PosInsBeUsed[i]=true;
		NegInsBeUsed[i]=true;
	}
	
	//һ��ʼ��ʱ��ÿ�����Զ����ܹ���ʹ�õ� 
	for(int i=0;i<MAXATTNUM;i++)
		AttBeUsed[i]=true;
}

///���°Ѹ���յ�������� 
void ResumeMazi()
{
	posInRule=0;
	numOfRule++;
	
	memset(PosInsNum,0,sizeof(PosInsNum));
	memset(NegInsNum,0,sizeof(NegInsNum));
	
	//���¿�ʼ��ʱ��ÿ�����Զ����ܹ���ʹ�õ� 
	for(int i=0;i<MAXATTNUM;i++)
		AttBeUsed[i]=true;
		
	for(int i=0;i<MAXINSNUM;i++)
	{
		PosInsBeContained[i]=PosInsBeUsed[i];
		NegInsBeContained[i]=NegInsBeUsed[i];
	}
	
}

void ResumeNumMazi()
{
	memset(PosInsNum,0,sizeof(PosInsNum));
	memset(NegInsNum,0,sizeof(NegInsNum));
}

/*********************************************************��ʼһ��***********/


/********************************************************����һ��************/ 
///����ÿ������ֵ���Ƕ������������� 
void UpdateNumMazi()
{
	for(int j=0;j<MAXINSNUM;j++)//���������� 
		if(PosInsBeUsed[j])/*< ��������ܹ���ʹ��*/
			for(int i=0;i<MAXATTNUM;i++)
				PosInsNum[i][FindAttValuePos(i,PE[j][i])]++;
			
	for(int j=0;j<MAXINSNUM;j++)
		if(NegInsBeUsed[j])/*< ��������ܹ���ʹ��*/
			for(int i=0;i<MAXATTNUM;i++)
				NegInsNum[i][FindAttValuePos(i,NE[j][i])]++;
} 

///�����������ܷ�ʹ�� 
void UpdateAttBeUsed(int row)
{
	AttBeUsed[row]=false; 
} 

///���������������Ƿ񱻸���
void UpdateInsBeContained(int row,int col)
{
	string temp=FindAttValue(row,col);
	
	for(int i=0;i<MAXINSNUM;i++)
	{
		//����pe 
		if(PosInsBeContained[i])
			if(PE[i][row]==temp)
				PosInsBeContained[i]=true;
			else//���Ǳ���� 
				PosInsBeContained[i]=false;
				
		if(NegInsBeContained[i])
			if(NE[i][row]==temp)
				NegInsBeContained[i]=true;
			else//��Ϊ��ʼ���ǰ��Ƿ��������������Ϊ�� 
				NegInsBeContained[i]=false;
	}
} 

///���������������Ƿ���Ա�ʹ�� 
void UpdateInsBeUsed(int row,int col)
{
	///��������˵�ǰ��һ��
	///���б����������������ܹ���ʹ�� 
	///�������¶��ܹ���ʹ�� 
	if(FinishThisTurn())
	{
		for(int i=0;i<MAXINSNUM;i++)
		{
			if(PosInsBeUsed[i])
				if(PosInsBeContained[i])
					PosInsBeUsed[i]=false;
				else
					PosInsBeUsed[i]=true;
				
			NegInsBeUsed[i]=true;
		} 	
		//���¸ø��µľ��� �Լ��洢����������±� 
		ResumeMazi();
		
		
	}
	///�����ǰ��һ��û�н��� 
	///ֻ�б������������ܹ���ʹ�� 
	///ֻ���ܹ��������ķ����ܹ���ʹ�� 
	else
	{
		for(int i=0;i<MAXINSNUM;i++)
		{
			if(PosInsBeContained[i])
				PosInsBeUsed[i]=true;
			else
				PosInsBeUsed[i]=false;
				
			if(NegInsBeContained[i])
				NegInsBeUsed[i]=true;
			else
				NegInsBeUsed[i]=false;
		}
		ResumeNumMazi();	
	}
} 
/*******************************************************����һ��************/

void DisEveryTurn()
{
	int row=0,col=0; 
	int pos=0,neg=0;
	
	UpdateNumMazi();
	DisNumMazi();
	GetMostPosLessNeg(row,col,pos,neg);
	cout<<"����ֵ�±�:"<<row<<" "<<col<<endl;
	cout<<"����������:"<<pos<<" "<<neg<<endl;
	
	string tempRule=FindAtt(row)+"="+FindAttValue(row,col);
	GS[numOfRule][posInRule++]=tempRule;
	cout<<"��õ�Լ��:"<<tempRule<<endl;
	
	UpdateInsBeContained(row,col);
	DisInsBeContained();
	UpdateAttBeUsed(row);
	//DisAttBeUsed();
	UpdateInsBeUsed(row,col);
	DisInsBeUsed();
}

int main()
{
	initMaZi();
	int i=1;
	while(!FinishThisLoop())
	{
		cout<<"�� "<<i++<<" ��"<<endl;
		DisEveryTurn();
	}
	cout<<"GS�㷨ѧϰ���Ĺ����ǣ�"<<endl;
	DisGS();
	getchar(); 
	return 0;
}

												
#endif
