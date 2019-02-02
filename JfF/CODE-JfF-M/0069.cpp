#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <float.h> 
#include <math.h> 
#include <time.h>
#pragma comment(lib, "pthreadVC2.lib")
#define SIZE 10
/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[N]; /* the array for the state vector  */
static int mti = N + 1; /* mti==N+1 means mt[N] is not initialized */

pthread_mutex_t mut;

float PI[SIZE];

void* Function_t(void* Param);
double KahanSum(float *input, int size);

double GetAveNormal(float *input, int size);
double GetAveKahan(float *intput, int size);
float CalPI();

void init_genrand(unsigned long s)
{
	mt[0] = s & 0xffffffffUL;
	for (mti = 1; mti<N; mti++)
	{
		mt[mti] =(1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
		/* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
		/* In the previous versions, MSBs of the seed affect   */
		/* only MSBs of the array mt[].                        */
		/* 2002/01/09 modified by Makoto Matsumoto             */
		mt[mti] &= 0xffffffffUL;
		/* for >32 bit machines */
	}
}

void init_by_array(unsigned long init_key[], int key_length)
{
	int i, j, k;
	init_genrand(19650218UL);
	i = 1; j = 0;
	k = (N>key_length ? N : key_length);
	for (; k; k--)
	{
		mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1664525UL))
			+ init_key[j] + j; /* non linear */
		mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
		i++; j++;
		if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
		if (j >= key_length) j = 0;
	}
	for (k = N - 1; k; k--)
	{
		mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1566083941UL))
			- i; /* non linear */
		mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
		i++;
		if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
	}

	mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
	unsigned long y;
	static unsigned long mag01[2] = { 0x0UL, MATRIX_A };
	/* mag01[x] = x * MATRIX_A  for x=0,1 */

	if (mti >= N)
	{ /* generate N words at one time */
		int kk;

		if (mti == N + 1)   /* if init_genrand() has not been called, */
			init_genrand(5489UL); /* a default initial seed is used */

		for (kk = 0; kk<N - M; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		for (; kk<N - 1; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}
		y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
		mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

		mti = 0;
	}

	y = mt[mti++];

	/* Tempering */
	y ^= (y >> 11);
	y ^= (y << 7) & 0x9d2c5680UL;
	y ^= (y << 15) & 0xefc60000UL;
	y ^= (y >> 18);

	return y;
}

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void)
{
	return (long)(genrand_int32() >> 1);
}

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
	return genrand_int32()*(1.0 / 4294967295.0);
	/* divided by 2^32-1 */
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
	return genrand_int32()*(1.0 / 4294967296.0);
	/* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void)
{
	return (((double)genrand_int32()) + 0.5)*(1.0 / 4294967296.0);
	/* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void)
{
	unsigned long a = genrand_int32() >> 5, b = genrand_int32() >> 6;
	return(a*67108864.0 + b)*(1.0 / 9007199254740992.0);
}

int main()
{
	float a = 123456;
	float b = 2.123456;
	float aaaa[] = {123456,2.123456};
	printf("Result of KahanSum     : %.18f\n", KahanSum(aaaa, 2));
	printf("Result without KahanSum:%.18f\n", a+b);
	init_genrand((unsigned long)time(NULL));

	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
		arr[i] = i;

	pthread_t pid;
	for (int i = 0; i< SIZE; i++)
		pthread_create(&pid, NULL, Function_t, &arr[i]);
	//这个sleep是很有必要的，如果没有的话是不正确的结果，因为有的线程还没有计算完毕 
	Sleep(10000);
	printf("AveNormal = %.18f\n", GetAveNormal(PI, SIZE));
	printf("AveKahan = %.18f\n", GetAveKahan(PI, SIZE));
	
	system("pause");
	return 0;
}

float CalPI()
{
	int numPoint = 10000000;
	int numInCircle = 0;
	double radius = 0.5;
	double x, y;
	for (int i = 0; i < numPoint; i++)
	{
		x = genrand_real1() - 0.5;
		y = genrand_real1() - 0.5;
		if (x * x + y *y - 0.5 * 0.5 <= DBL_EPSILON)
			numInCircle++;
	}
	float pi = numInCircle / (numPoint * 0.25);
	printf("QueFir: %d,%.18f\n", numPoint, pi);
	return pi;
}

void* Function_t(void* Param)
{
	int *pos = (int *)Param;
	PI[*pos] = CalPI();
	pthread_t myid = pthread_self();
	printf("线程ID=%d finish calculating\n", myid);
	return NULL;
}

double KahanSum(float *input, int size)
{
	double sum = 0.0;
	double c = 0.0;
	for (int i = 0; i < size; i++)
	{
		double y = input[i] - c;
		double t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	return sum;
}

double GetAveNormal(float *input, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += input[i];
	return sum / (double)size;
}

double GetAveKahan(float *input, int size)
{
	return KahanSum(input, size) / (double)size;
}

