/*
Complier:Xcode
Auther:Jiarui XIE
Language: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cfloat>
#include <vector>
using namespace std;

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[N]; /* the array for the state vector  */
static int mti = N + 1; /* mti==N+1 means mt[N] is not initialized */

/***************************************JrXIE-S****************************/
#define SIZE_REPLICATE 1000

//the table used to calculate confidenct interval
double TableArr[] =
{
	-1, 12.706, 4.303, 3.182, 2.776, 2.571, 2.474, 2.365, 2.308, 2.262, 2.228,
	2.201, 2.179, 2.160, 2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086,
	2.08, 2.074, 2.069, 2.064, 2.060, 2.056, 2.052, 2.048, 2.045, 2.042
};
//To record the frequence of  litter 
int litterNumArr[9] = { 0 };
//To record the frequence of  pup per litter
int pupNumArr[8] = { 0 };
//To record the frequence of  time needed to mature
int timeMaturedArr[9] = { 0 };
// Store the number of rabbit every month
unsigned long RabbitNum[1000000];
// Act as the index of RabbitNum[];
static int pos = 0;
// Used to display the contents of litterNumArr / pupNumArr and timeMaturedArr
void disArr();
// Used to display the number of Rabbits every month
void DisplayRabbitNumbers();
// Used to change the matured pup to the matured vector
void ChangeVector();
// Used to simulate the growth of rabbits. Year: the years to simulate,
//initNum: the init couple number of matured rabbits
int RabbitSimulation(int year, int initNum);
// Used to generate the value between 0 and 100
int genrand_int100(void);
// Those two are used to generate the value for pup numbers and so on
double Uniform2GaussianDistribution();
int GaussianDistribution(int mean, int deviation);
// Those three are provided by ...
void init_genrand(unsigned long s);
unsigned long genrand_int32(void);
double genrand_real1(void);
// Thoes four are used to calculate the confidence interval
double GetMean(unsigned long arr[], int size);
double GetS2(unsigned long arr[], int size, double mean);
double GetTa(int n);
void GetInterval(int n);

class Rabbit
{
public:
	Rabbit();
	void MaturedSurivial();
	void unMSurivial();
	bool GrowUpAdult(); // true like alive
	bool GrowUpBaby(); // false like dead

	void CopulateTimes();
	int NewRabbitNumber();
	void MaturityTimes();
	bool IsMaturity();
	bool IsAlilve();

	void Init();
	void SetGenderRatio(int a);
	void SetAlive();
	void SetAttrS(int, int, int, bool, bool, int, int, int);

public:
	int _age; // calculate by month
	int _gender; // 1 like male, 0 like female
	int _radiOfGender;
	bool _isAlive;
	bool _isMaturity;
	int _maturityTimes;
	int _couplateTimes;
	int _deadRatio;
};

// The vector used to store the objects of Rabbit
vector <Rabbit> mFe;
vector <Rabbit> mMa;
vector <Rabbit> unM;

int main(void)
{
	//必须初始化种子，才能保证每一次的值不一样
	init_genrand((unsigned long)time(NULL));
	clock_t start, finish;

	start = clock();
	for (int i = 0; i < 10; i++)
	{
		int temp = RabbitSimulation(5, 2);
		cout << temp << endl;
		RabbitNum[pos++] = temp;
	}
	//disArr();
	finish = clock();

	GetInterval(pos);

	double totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "The run time is :" << totaltime << " s" << endl;

	system("pause");
	return 0;
}

void Rabbit::SetAttrS(int b, int c, int d, bool e, bool f, int g, int h, int a)
{
	_age = b;
	_gender = c;
	_radiOfGender = d;
	_isAlive = e;
	_isMaturity = f;
	_maturityTimes = g;
	_couplateTimes = a;
	_deadRatio = h;
}

bool Rabbit::IsAlilve()
{
	return _isAlive;
}

void Rabbit::MaturedSurivial() // At the time when got Matured
{
	if (_age == _maturityTimes)
		if (genrand_int100() <= 50)
			_isAlive = true;
		else
			_isAlive = false;
}

void Rabbit::unMSurivial() // At the time of Birth
{
	if (genrand_int100() <= 20)
		_isAlive = true;
	else
		_isAlive = false;
}

void Rabbit::SetAlive()
{
	_isAlive = _age > 15 * 12 ? false : true;
}

Rabbit::Rabbit()
{
	_deadRatio = 20;
	_couplateTimes = 0;
	_age = 0;
	_isAlive = true;
	_isMaturity = false;
	SetGenderRatio(50);
	MaturityTimes();
}

int Rabbit::NewRabbitNumber()
{
	int temp;
	do
	{
		temp = GaussianDistribution(4, 2);
	}
	while (temp < 3 || temp > 6);
	pupNumArr[temp]++;

	return temp;
}

void Rabbit::CopulateTimes()
{
	int temp;
	do
	{
		temp = GaussianDistribution(6, 2);
	}
	while (temp < 4 || temp > 8);
	_couplateTimes = temp;
	litterNumArr[temp]++;
}

void Rabbit::MaturityTimes()
{
	int temp;
	do
	{
		temp = GaussianDistribution(7, 2);
	}
	while (temp < 5 || temp > 8);
	_maturityTimes = temp;

	timeMaturedArr[temp]++;
}

bool Rabbit::IsMaturity()
{
	_isMaturity = _age >= _maturityTimes ? true : false;
	return _isMaturity;
}

void Rabbit::SetGenderRatio(int a)
{
	_radiOfGender = a;
}

void Copulate()
{
	//閲嶈鍋囪鍏殑涓�鐩磋兘澶熶氦閰嶏紝涓斾竴涓叕鐨勮兘鍜屽緢澶氭瘝鐨勪氦閰嶏紝鍙鏈変竴涓叕鐨勫氨琛屼簡
	if (!mMa.empty())
		for (int i = 0; i < mFe.size(); i++)
		{
			if (mFe[i]._age % (mFe[i]._maturityTimes + 12) == 0)
				mFe[i].CopulateTimes();
				

			if (mFe[i]._couplateTimes > 0)
			{
				mFe[i]._couplateTimes--;

				int numOfRabbit = mFe[i].NewRabbitNumber();

				for (int i = 0; i < numOfRabbit; i++)
				{
					Rabbit newRabbit = Rabbit();
					if (genrand_int100() >= newRabbit._radiOfGender)
						newRabbit._gender = 1;
					else
						newRabbit._gender = 0;
					unM.push_back(newRabbit);
				}
			}
		}
}

bool Rabbit::GrowUpAdult()
{
	_age++;
	SetAlive();
	if (_isAlive && _age >= 11 * 12 && _age % 12 == 0)// Once per Year
	{
		if (genrand_int100() < (100 - _deadRatio))
			_isAlive = true;
		else
			_isAlive = false;
	}
	_deadRatio += 20;

	return _isAlive;
}

bool Rabbit::GrowUpBaby()
{
	_age++;
	MaturedSurivial();
	return _isAlive;
}

/* initializes mt[N] with a seed */
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

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
	return genrand_int32()*(1.0 / 4294967295.0);
	/* divided by 2^32-1 */
}

/* generates an integer number on [0,100] interval */
int genrand_int100(void)
{
	return (int)(genrand_int32()*(1.0 / 4294967295.0) * 100);
	/* divided by 2^32-1 */
}

double GetMean(unsigned long arr[], int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += (double)arr[i];
	return sum / size;
}

double GetS2(unsigned long arr[], int size, double mean)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += pow((double)arr[i] - mean, 2);
	return sum / (size - 1);
}

double GetTa(int n)
{
	if (n >= 1 && n <= 30)
		return TableArr[n];
	else if (n == 30)
		return 2.021;
	else if (n == 40)
		return 2.0;
	else if (n == 80)
		return 1.980;
	else if (n > 80)
		return 1.96;
	else
		return -1;
}

void GetInterval(int n)
{
	if (n >= 0 && n <= SIZE_REPLICATE)
	{
		double ave = GetMean(RabbitNum, n);
		printf("ave=%10.6f \n", ave);
		double s2 = GetS2(RabbitNum, n, ave);
		printf("s2=%10.6f \n", s2);
		double ta = GetTa(n);
		printf("ta=%10.6f \n", ta);
		if (ta != -1)
		{
			double r = ta * sqrt(s2 / n);
			printf("[%8.6f, %8.6f]\n", ave - r, ave + r);
		}
		else
			printf("Can not calculate the confidence interval\n");

	}
	else
		printf("Please input right n\n");
}

double Uniform2GaussianDistribution()
{
	double sum = 0.0;
	//需要有负值，如果没有负值的话就仅仅能够生成一边了
	for (int i = 0; i < 12; i++)
		sum += genrand_real1();
	return sum - 6.0;
}

int GaussianDistribution(int mean, int deviation)
{
	return  (int)(mean + Uniform2GaussianDistribution() * deviation);
}

void disArr()
{
	cout << "Litter number of Rabbit:" << endl;
	for (int i = 4; i <= 8; i++)
		cout << i << " litters per year is :" << litterNumArr[i] << endl;

	cout << "Pup number of Rabbit:" << endl;
	for (int i = 3; i <= 6; i++)
		cout << i << " pups per year is :" << pupNumArr[i] << endl;

	cout << "Mature time of Rabbit:" << endl;
	for (int i = 5; i <= 8; i++)
		cout << i << " months needed is :" << timeMaturedArr[i] << endl;
}

void DisplayRabbitNumbers()
{
	unsigned long totalNum = mMa.size() + mFe.size() + unM.size();
	cout << "The number of maturedMale is:" << mMa.size() << endl;
	cout << "The number of maturedFemale is:" << mFe.size() << endl;
	cout << "The number of unMatured is:" << unM.size() << endl;
	cout << "The total number of Rabbits is :" << totalNum << endl;
}

void ChangeVector()
{
	for (int j = 0; j < unM.size(); j++)
		if (unM[j].GrowUpBaby())
		{
			if (unM[j].IsMaturity())
				if (unM[j]._gender == 0)
				{
					mFe.push_back(unM[j]);
					unM.erase(unM.begin() + j);
				}
				else
				{
					mMa.push_back(unM[j]);
					unM.erase(unM.begin() + j);
				}
		}
		else
			unM.erase(unM.begin() + j);
}

int RabbitSimulation(int year, int initNum)
{
	mFe.clear();
	mMa.clear();
	unM.clear();
	Rabbit fr = Rabbit();
	Rabbit mr = Rabbit();
	fr.SetAttrS(6, 0, 50, true, true, 6, 20, 4);
	mr.SetAttrS(6, 1, 50, true, true, 6, 20, 4);

	Rabbit temp, tfr, tmr;
	for (int i = 0; i < initNum; i++)
	{
		mFe.push_back(fr);
		mMa.push_back(mr);
	}

	for (int i = 0; i < year * 12; i++) //Years to be Simulate
	{
		//灏忓厰瀛愭槸鍚︽垚鐔熴�佸瓨娲汇�佸垏鎹㈠悜閲?
		ChangeVector();

		// 澶у厰瀛愮敓浜?
		Copulate();

		//澶ф瘝鍏斿瓙鏄惁娲荤潃
		for (int i = 0; i < mFe.size(); i++)
			if (!mFe[i].GrowUpAdult())
				mFe.erase(mFe.begin() + i);
		//澶у叕鍏斿瓙鏄惁娲荤潃
		for (int i = 0; i < mMa.size(); i++)
			if (!mMa[i].GrowUpAdult())
				mMa.erase(mMa.begin() + i);

		//cout << i + 1 << "th Month:" << endl;
		//DisplayRabbitNumbers();

	}
	return mMa.size() + mFe.size() + unM.size();
}
