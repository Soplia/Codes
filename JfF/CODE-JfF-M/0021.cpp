#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
  
using namespace std;  

struct node  
{  
    int x,y;  
};  

node vex[1000];//��������еĵ�  
node stackk[1000];//͹�������еĵ�  
int xx,yy;  

bool cmp1(node a,node b)//�����ҵ�һ����  
{  
    if(a.y==b.y)  
        return a.x<b.x;  
    else  
        return a.y<b.y;  
}  

double cross(node a,node b,node c)//������ �ж�bc������ac���� �Ƿ�ͨ����ת�õ� >0��ת <0��ת  =0����   
{  
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);  
}  

double dis(node a,node b)//�������  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y));  
}  

bool cmp2(node a,node b)//����������һ�ַ������ٶȿ�  
{  
    if(atan2(a.y-yy,a.x-xx)!=atan2(b.y-yy,b.x-xx))  
        return (atan2(a.y-yy,a.x-xx))<(atan2(b.y-yy,b.x-xx));  
    return a.x<b.x;  
}  

bool cmp(node a,node b)//��������  
{  
    int m=cross(vex[0],a,b);  
    if(m>0)  
        return 1;  
    else if(m==0&&dis(vex[0],a)-dis(vex[0],b)<=0)  //���� Ҳ����͹��   
        return 1;  
    else return 0;  
       
}  

int main()  
{  
    int t,L;  
    int i;  
	//<span style="white-space:pre;"> </span>t=7;  
          
    vex[0].x=1,vex[0].y=0;   
    vex[1].x=-1,vex[1].y=1;   
    vex[2].x=2,vex[2].y=0;   
    vex[3].x=0,vex[3].y=0;   
    vex[4].x=-1,vex[4].y=-1;   
    vex[5].x=1,vex[5].y=-1;   
    vex[6].x=-2,vex[6].y=-0;   //������while��  ����   
          
     
    memset(stackk,0,sizeof(stackk));  
      
    sort(vex,vex+t,cmp1);//�����½ǵĵ�   
    stackk[0]=vex[0];  //��һ��͹����   
    sort(vex+1,vex+t,cmp);//cmp2�Ǹ���ģ�cmp���������   ��������  
              
    stackk[1]=vex[1];//����2�������͹���Ľṹ����  
      
    int top=1;//���͹����ӵ�е�ĸ���  ʵ��Ϊ2   
    for(i=2; i<t; i++)  
    {  
            //<span style="white-space:pre;">   </span>  
        while(cross(stackk[top-1],stackk[top],vex[i])<0)
		{   //�Ƿ������˴���0 �������ջ  ����<0��<=0���Կ����ص㣬����  
            top--;          
        }  
        stackk[++top]=vex[i];  //�������ջ   
    }  
         
    for(i=0; i<=top; i++)     
        cout<<stackk[i].x<<" "<<stackk[i].y<<endl;  
}  
