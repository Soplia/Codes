#include<cstdio>  
#define min(a,b) (a>b?b:a)  
const int M=5850;  
int hum[M];  
int ta,tb,tc,td,a,b,c,d,min_v,i,n;  
using namespace std;  
int main()  
{  
    hum[1]=1;  
    a=b=c=d=1;  
    for(i=2;i<=5842;i++)  
    {  
        ta=hum[a]*2;  
        tb=hum[b]*3;  
        tc=hum[c]*5;  
        td=hum[d]*7;  
        min_v=min(min(ta,tb),min(tc,td));  
        if(ta==min_v) a++;  
        if(tb==min_v) b++;  
        if(tc==min_v) c++;  
        if(td==min_v) d++;  
        hum[i]=min_v;  
    }  
    while(scanf("%d",&n),n)  
    {  
        if(n%10==1&&n%100!=11)  
         printf("The %dst humble number is %d.\n",n,hum[n]);  
        else if(n%10==2&&n%100!=12)  
         printf("The %dnd humble number is %d.\n",n,hum[n]);  
        else if(n%10==3&&n%100!=13)  
         printf("The %drd humble number is %d.\n",n,hum[n]);  
        else  
         printf("The %dth humble number is %d.\n",n,hum[n]);  
  
    }  
    return 0;  
}  


