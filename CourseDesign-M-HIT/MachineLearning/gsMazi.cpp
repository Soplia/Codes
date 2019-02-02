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
  * 编译环境是 Devcpp
  * PE、NE 数组的顺序要根据 AttOrder 的顺序来写 
  * AttValueOrder 是每个属性的取值范围，大小按照四个，不足的补 "" 
  * 正例、反例的数量默认是相同的，都为 MAXINSNUM 
  * 对于正反例 ：true- 被包含；false- 未被包含 
  * 对于正反例 ：true- 可用；false- 不可用 
  * 对于属性 ：true- 可用；false- 不可用 
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


/*********************************************************常量一族******************/
///假设正例与反例数量相同 
const int MAXINSNUM=5;
const int MAXATTNUM=5;
const int MAXATTVALUENUM=4;

//保存最后的规则 
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

///将例子按照属性从上到下进行排列 
string AttValueOrder[MAXATTNUM][MAXATTVALUENUM]={
													"high","mediu","low","absent",
													"heavy","slight","mediu", "",
													"flack","spot","strip","hole",
													"normal","fast","","",
													"bubblelike","dry-peep" ,"normal", ""
												};
												
												
int PosInsNum[MAXATTNUM][MAXATTVALUENUM];
int NegInsNum[MAXATTNUM][MAXATTVALUENUM];

///true :被包含；false：未被包含 
bool PosInsBeContained[MAXINSNUM];
bool NegInsBeContained[MAXINSNUM];

///true：可用；false：不可用 
bool PosInsBeUsed[MAXINSNUM];
bool NegInsBeUsed[MAXINSNUM];

///true：可用；false：不可用 
bool AttBeUsed[MAXATTNUM];
/*********************************************************常量一族******************/


/*********************************************************打印一族***********/
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
			cout<<"∪";
		for(int j=0;j<MAXINSNUM&&GS[i][j]!="0";j++)
			cout<<"["<<GS[i][j]<<"]";
		
	}
}

/*********************************************************打印一族***********/


/*********************************************************查找一族***********/
///获得第row个属性的属性值的下标 
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


///获得位于pos位置处的属性的名字 
string FindAtt(int pos)
{
	if(pos>=0&&pos<MAXATTNUM)
		return AttOrder[pos];
	else 
		return "gsMazi.cpp:"+__LINE__;
}

///获得位于第row个属性的第col个属性值 
string FindAttValue(int row,int col)
{
	if(row>=0&&row<MAXATTNUM&&col>=0&&col<MAXATTVALUENUM)
		return AttValueOrder[row][col];
	else 
		return "gsMazi.cpp:"+__LINE__;
}

///获得覆盖正例最多，且反例最少的位置下标 
void GetMostPosLessNeg(int &row,int &col)
{
	row=col=0;
	int tempPos=PosInsNum[row][col];
	int tempNeg=NegInsNum[row][col];
	
	for(int i=0;i<MAXATTNUM;i++)
		if(AttBeUsed[i])//如果这个属性能够被使用，就加入统计中，如果不能够被使用就不加入统计中 
			for(int j=0;j<MAXATTVALUENUM;j++)
			{
				//如果正例数大于上一个 
				if(PosInsNum[i][j]>tempPos)
				{
					tempPos=PosInsNum[i][j];
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
				//如果正例数相同，但是反例数少 
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
		if(AttBeUsed[i])//如果这个属性能够被使用，就加入统计中，如果不能够被使用就不加入统计中
			for(int j=0;j<MAXATTVALUENUM;j++)
			{
				//如果正例数大于上一个 
				if(PosInsNum[i][j]>tempPos)
				{
					tempPos=PosInsNum[i][j];
					tempNeg=NegInsNum[i][j];
					row=i;
					col=j;
				}
				//如果正例数相同，但是反例数少 
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
/*********************************************************查找一族***********/


/*********************************************************判终一族***********/
bool FinishThisTurn()
{
	for(int i=0;i<MAXINSNUM;i++)
		if(NegInsBeContained[i])/*<  如果包含一个反例该轮就没有结束*/
			return false;
	return true;
}

bool FinishThisLoop()
{
	for(int i=0;i<MAXINSNUM;i++)
		if(PosInsBeUsed[i])/*<  如果有一个正例能够被使用就未结束整个循环*/
			return false;
	return true;
}

/*********************************************************判终一族***********/


/*********************************************************初始一族***********/
///初始化计数数组 
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
	
	//一开始的时候每个属性都是能够被使用的 
	for(int i=0;i<MAXATTNUM;i++)
		AttBeUsed[i]=true;
}

///重新把该清空的数组清空 
void ResumeMazi()
{
	posInRule=0;
	numOfRule++;
	
	memset(PosInsNum,0,sizeof(PosInsNum));
	memset(NegInsNum,0,sizeof(NegInsNum));
	
	//重新开始的时候每个属性都是能够被使用的 
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

/*********************************************************初始一族***********/


/********************************************************更新一族************/ 
///更新每个属性值覆盖多少正例、反例 
void UpdateNumMazi()
{
	for(int j=0;j<MAXINSNUM;j++)//控制例子数 
		if(PosInsBeUsed[j])/*< 如果正例能够被使用*/
			for(int i=0;i<MAXATTNUM;i++)
				PosInsNum[i][FindAttValuePos(i,PE[j][i])]++;
			
	for(int j=0;j<MAXINSNUM;j++)
		if(NegInsBeUsed[j])/*< 如果反例能够被使用*/
			for(int i=0;i<MAXATTNUM;i++)
				NegInsNum[i][FindAttValuePos(i,NE[j][i])]++;
} 

///更新正属性能否被使用 
void UpdateAttBeUsed(int row)
{
	AttBeUsed[row]=false; 
} 

///更新正例、反例是否被覆盖
void UpdateInsBeContained(int row,int col)
{
	string temp=FindAttValue(row,col);
	
	for(int i=0;i<MAXINSNUM;i++)
	{
		//更新pe 
		if(PosInsBeContained[i])
			if(PE[i][row]==temp)
				PosInsBeContained[i]=true;
			else//这是必须得 
				PosInsBeContained[i]=false;
				
		if(NegInsBeContained[i])
			if(NE[i][row]==temp)
				NegInsBeContained[i]=true;
			else//因为初始化是把是否包含反例都设置为真 
				NegInsBeContained[i]=false;
	}
} 

///更新正例、反例是否可以被使用 
void UpdateInsBeUsed(int row,int col)
{
	///如果结束了当前这一轮
	///所有被包含的正例都不能够再使用 
	///正例重新都能够被使用 
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
		//更新该更新的矩阵 以及存储规则的行列下标 
		ResumeMazi();
		
		
	}
	///如果当前这一轮没有结束 
	///只有被包含的正例能够被使用 
	///只有能够被包含的反例能够被使用 
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
/*******************************************************更新一族************/

void DisEveryTurn()
{
	int row=0,col=0; 
	int pos=0,neg=0;
	
	UpdateNumMazi();
	DisNumMazi();
	GetMostPosLessNeg(row,col,pos,neg);
	cout<<"属性值下标:"<<row<<" "<<col<<endl;
	cout<<"正例反例数:"<<pos<<" "<<neg<<endl;
	
	string tempRule=FindAtt(row)+"="+FindAttValue(row,col);
	GS[numOfRule][posInRule++]=tempRule;
	cout<<"获得的约束:"<<tempRule<<endl;
	
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
		cout<<"第 "<<i++<<" 轮"<<endl;
		DisEveryTurn();
	}
	cout<<"GS算法学习到的规则是："<<endl;
	DisGS();
	getchar(); 
	return 0;
}

												
#endif
