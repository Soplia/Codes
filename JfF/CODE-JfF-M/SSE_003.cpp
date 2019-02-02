#define WIN  
#include "timing.h"  
#include <intrin.h>  
#include <stdlib.h>  
#include <math.h>  
  
#define N 4*300000000      // 注意：必须是4的倍数，否则使用SSE指令计算，要进行一些处理，从而保证正确。  

/*
_MM_ALIGN16 float op1[N];  
_MM_ALIGN16 float op2[N];  
_MM_ALIGN16 float result1[N];  
_MM_ALIGN16 float result2[N];  
*/

float op1[N];  
float op2[N];  
float result1[N];  
float result2[N];  

void init()  
{  
    for(long i = 0;i < N; i++)  
    {  
        op1[i] = (float)rand()/(float)RAND_MAX;  
        op2[i] = (float)rand()/(float)RAND_MAX;  
    }  
}  
  
void checkResult(int debug)  
{  
    bool isSame = true;  
    for(long i = 0;i < N; i++)  
    {  
        if (debug)  
        {  
            printf("%lf     %lf\n", result1[i], result2[i]);  
        }  
        else  
        {  
            if (fabs(result1[i] - result2[i]) > 0.000001)  
            {  
                isSame = false;  
                break;  
            }  
        }  
    }  
    if (!debug) {  
        if (isSame)  
            printf("Result is Same\n");  
        else  
            printf("Result is not same\n");  
    }  
}  
  
void add1()  
{  
    for(long i = 0; i < N;i++)  
        result1[i] = op1[i] + op2[i];  
}  
  
void add2()  
{  
    __m128  a;  
    __m128  b;  
    __m128  c;  
  
    for(long i = 0; i < N;i = i + 4)  
    {  
        // Load  
        a = _mm_load_ps(op1 + i);  
        b = _mm_load_ps(op2 + i);  
  
        c = _mm_add_ps(a, b);   // c = a + b  
  
        _mm_store_ps(result2 + i, c);  
    }  
}  
  
int main(int argc, char* argv[])  
{  
    init();  
    srand((unsigned int)time(NULL));  
  
    printf("Add a vector:\n");  
    startTiming();  
    add1();  
    stopWithPrintTiming();  
  
    printf("\n");  
    printf("Add a vector with SSE instructions:\n");  
    startTiming();  
    add2();  
    stopWithPrintTiming();  
  
    printf("\n");  
    checkResult(0);  
  
    return 0;  
}  
