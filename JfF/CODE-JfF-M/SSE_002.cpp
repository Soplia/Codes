#include <stdio.h>

int main()
{
	float op1[4] = {1.0, 2.0, 3.0, 4.0};  
    float op2[4] = {1.0, 2.0, 3.0, 4.0};  
    float result[4]; 
    for(int i=0;i<4;i++)
    	result[i]=op1[i]+op2[i];
    printf("0: %lf\n", result[0]);  
    printf("1: %lf\n", result[1]);  
    printf("2: %lf\n", result[2]);  
    printf("3: %lf\n", result[3]);
	return 0;
}

