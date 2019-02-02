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

node vex[1000];//存入的所有的点  
node stackk[1000];//凸包中所有的点  
int xx,yy;  

bool cmp1(node a,node b)//排序找第一个点  
{  
    if(a.y==b.y)  
        return a.x<b.x;  
    else  
        return a.y<b.y;  
}  

double cross(node a,node b,node c)//计算叉积 判断bc向量到ac向量 是否通过左转得到 >0左转 <0右转  =0共线   
{  
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);  
}  

double dis(node a,node b)//计算距离  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y));  
}  

bool cmp2(node a,node b)//极角排序另一种方法，速度快  
{  
    if(atan2(a.y-yy,a.x-xx)!=atan2(b.y-yy,b.x-xx))  
        return (atan2(a.y-yy,a.x-xx))<(atan2(b.y-yy,b.x-xx));  
    return a.x<b.x;  
}  

bool cmp(node a,node b)//极角排序  
{  
    int m=cross(vex[0],a,b);  
    if(m>0)  
        return 1;  
    else if(m==0&&dis(vex[0],a)-dis(vex[0],b)<=0)  //共线 也读入凸包   
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
    vex[6].x=-2,vex[6].y=-0;   //可以用while读  更改   
          
     
    memset(stackk,0,sizeof(stackk));  
      
    sort(vex,vex+t,cmp1);//最左下角的点   
    stackk[0]=vex[0];  //第一个凸包点   
    sort(vex+1,vex+t,cmp);//cmp2是更快的，cmp更容易理解   极角排序  
              
    stackk[1]=vex[1];//将第2个点存入凸包的结构体中  
      
    int top=1;//最后凸包中拥有点的个数  实际为2   
    for(i=2; i<t; i++)  
    {  
            //<span style="white-space:pre;">   </span>  
        while(cross(stackk[top-1],stackk[top],vex[i])<0)
		{   //是否满足叉乘大于0 不满足出栈  控制<0或<=0可以控制重点，共线  
            top--;          
        }  
        stackk[++top]=vex[i];  //满足的入栈   
    }  
         
    for(i=0; i<=top; i++)     
        cout<<stackk[i].x<<" "<<stackk[i].y<<endl;  
}  
