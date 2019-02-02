/*
	Subject:‘S•”ŠÔˆá‚¢‚Ì”r—ñi‚Í‚¢‚ê‚Âj 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7.2
	Date_Begin:04/02/17 11:08
	Result:Accepted
	Date_End:04/02/17 11:10
*/
#include <stdio.h>
#define N 100

int main()
{
	long long array[N];
	array[1]=0;
	array[2]=1;
	for(int i=3;i<N;i++)
		array[i]=(i-1)*array[i-1]+(i-1)*array[i-2];
	int size;
	while(scanf("%d",&size)!=EOF&&size!=0)
		printf("%lld\n",array[size]);
	return 0;
}
/*
InputData:
2
3
OutputData:
1
2
*/

