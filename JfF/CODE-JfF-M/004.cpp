#include <stdio.h>
#include <time.h>

int F(int n) 
{  
        if(n<=1)   
            return n;  
        else  
            return F(n-1)+F(n-2);  
 }  
 
 int main()
 {
 	time_t rand;
 	time(&rand);
 	struct tm *timeinfo;
 	timeinfo=localtime(&rand);
 	//printf ( "\007The current date/time is: %s", asctime (timeinfo) );

 	
 	for(int i=0;i<30;i++)
 		printf("%d,%d\n",F(i),timeinfo->tm_sec);
 	return 0;
 }
