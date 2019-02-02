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

double PI[SIZE];

void* Function_t(void* Param);
double KahanSum(double *input, int size);

double GetAveNormal(double *input, int size);
double GetAveKahan(double *intput, int size);
double CalPI();

void init_genrand(unsigned long s)
{
	mt[0] = s & 0xffffffffUL;
	for (mti = 1; mti<N; mti++)
	{
		mt[mti] =
			(1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
		/* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
		/* In the previous versions, MSBs of the seed affect   */
		/* only MSBs of the array mt[].                        */
		/* 2002/01/09 modified by Makoto Matsumoto             */
		mt[mti] &= 0xffffffffUL;
		/* for >32 bit machines */
	}
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
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
	init_genrand((unsigned long)time(NULL));
	//	int size = 2;
	//	double input[] = { 100998, 2.338 };
	//	printf("the sum of  input is %.18f\n", KahanSum(input, size));

	//	pthread_mutexattr_t attrM;
	//	pthread_mutexattr_init(&attrM);
	//	pthread_mutexattr_setpshared(&attrM, PTHREAD_PROCESS_SHARED);
	//
	//	pthread_mutex_init(&mut, NULL);

	/*pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);*/

	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
		arr[i] = i;

	pthread_t pid;
	for (int i = 0; i< SIZE; i++)
		pthread_create(&pid, NULL, Function_t, &arr[i]);
	//这个sleep是很有必要的，如果没有的话是不正确的结果，因为有的线程还没有计算完毕 
	Sleep(1000);
	printf("AveNormal = %.18f\n", GetAveNormal(PI, SIZE));
	printf("AveKahan = %.18f\n", GetAveKahan(PI, SIZE));
	//	pthread_attr_destroy(&attr);
	//	pthread_mutex_destroy(&mut);
	system("pause");
	return 0;
}

double CalPI()
{
	int numPoint = 1000000;
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
	double pi = numInCircle / (numPoint * 0.25);
	printf("QueFir: %d,%10.6f\n", numPoint, pi);
	return pi;
}

void* Function_t(void* Param)
{
	//	pthread_mutex_lock(&mut);
	int *pos = (int *)Param;
	PI[*pos] = CalPI();
	pthread_t myid = pthread_self();
	printf("线程ID=%d finish calculating\n", myid);
	//	pthread_mutex_unlock(&mut);
	return NULL;
}

double KahanSum(double *input, int size)
{
	//SUM C 都是不变的
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

double GetAveNormal(double *input, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += input[i];
	return sum / (double)size;
}

double GetAveKahan(double *input, int size)
{
	return KahanSum(input, size) / (double)size;
}

/*
// 第二次试验

int main()
{
float a = 0.7, b = 0.5; // These are FLOATS
double c = (double)a;
double d = 0.7;
//printf("%0.10f\n", a);
//printf("%0.15f\n", c);
printf("%0.15f\n", d);   //(1) why is different even there is different between 0.15 and 0.18

//printf("%0.18f\n", c);
printf("%0.18f\n", d); //打印double的时候需要使用.18，如果使用.15的话就是一种近似
if (a < .7) // This is a DOUBLE
if (b < .5)
printf("2 are right\n"); // Here too , the test is a DOUBLE
else
printf("1 is right\n");
else
printf("0 are right\n");

double x = 10;
double y = sqrt(x);
y *= y;
if (x == y)
cout << "Square root is exact\n";
else
cout << x - y << "\n";
cout << FLT_EPSILON << endl;
cout << DBL_EPSILON << endl;

float f = 0.1f;
float sum = 0;
for (int i = 0; i < 10; ++i)
sum += f;
float product = f * 10;
printf("sum = %1.15f, product = %1.15f, f*10 = %1.15f\n", sum, product, f * 10);


for (int i = 1; i < 20; ++i)
{
double h = pow(10.0, -i);
printf("(sin(1.0 + h) - sin(1.0)) / h = %1.15f\n",(sin(1.0 + h) - sin(1.0)) / h );

}
printf("cos(1.0)= %1.15f \n", cos(1.0));

float ff = 16777216;
cout  <<  ff  << " $ "  <<  ff + 1 << "\n";
x = 9007199254740992; // 2^53
cout << ((x + 1) - x) << "\n";

x = 1.0;
y = x + 0.5 * DBL_EPSILON;
if (x == y)
cout << "Sorry!\n";

x = exp(logFactorial(200)
- logFactorial(190)
- logFactorial(10));
printf("x= %1.15f \n", x);

x = DBL_MAX;
cout << 2 * x << "\n";

cout << (pow(10, -3) + 1) - 1 << endl; //(4) The result are same.
// cout的精度不够，同时如果使用set::precision进行设置
// 就能够使用了
printf("%0.18f \n", (pow(10, -3) + 1) - 1);
printf("%0.18f \n", pow(10, -3) + (1 - 1));
//cout << pow(10, -3) + (1 - 1) << endl;

float aa = 100998;
float bb = 2.338;

aa = aa + bb;

double aaaa[] = {100998, 2.338};
printf("the sum is %.18f\n", KahanSum(aaaa, 2));

system("pause");
return 0;
}

*/
/*
//测试一
int main()
{
//float a = 0.7;
//float b = 0.5;
double a = 0.7;
double b = 0.5;
if (a < 0.7)
if (b < 0.5)
printf("2 conditions are right\n");
else
printf("only 1 is right\n");
else
printf("0 conditions are right\n");
system("pause");
return 0;
}
*/