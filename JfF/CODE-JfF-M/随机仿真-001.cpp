#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define CICLE 32

void First()
{
    int start = 100;
    int res;

    for (int i = 0; i <= 60; i ++)
    {
        res = start * start;
        // printf("%08d\n", res);

        res = res / 100;
        // printf("%06d\n", res);

        res = res % 10000;
        printf("%03d : %04d\n", i, res);

        start = res;
        //printf("%d\n", res);
    }
}


void Third()
{
    int tail = 0;
    int head = 0;

    srand((unsigned) time(0));

    for(int i = 0 ; i < 10000 ; i++)
    {
        if (0 == rand() % 2)
            head++;
        else if (1 == rand() %2)
            tail++;

    }

    printf("%d\n", head);
    printf("%d\n", tail);
}

void Dis(int *a, int size)
{
    for(int i = 0 ; i < size ; i++)
        printf("%4d : %4d\n", i + 1, a[i]);
}

void Fifth()
{
    int a[SIZE] = { 0 };
    int size = 6;
    srand((unsigned) time(0));

    for(int i = 0 ; i < 10000 ; i++)
        a[rand() % size]++;

    Dis(a, size);
}

void intRand(int a, int c, int m, int x)
{
    int first = 0;

    for(int i = 0 ; i < CICLE ; i++)
    {
        first = (a * x + c) % m;
        printf("%4d : %4d\n", i + 1, first);
        x = first;
    }

}

void floatRand(int a, int c, int m, int x)
{
    int first = 0;

    for(int i = 0 ; i < CICLE ; i++)
    {
        first = (a * x + c) % m;
        printf("%4d : %.4f\n", i + 1, (double)first /16);
        x = first;
    }

}

void Lcg(int a, int c, int m, int x)
{
    intRand(a, c, m, x);
    floatRand(a, c, m, x);
}



int main()
{

    Lcg(5, 1, 16, 5);
    return 0;
}

