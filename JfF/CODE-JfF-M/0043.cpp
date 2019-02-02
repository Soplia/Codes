#include <iostream>
using namespace std;
const int SIZE = 1000000;
int g_num = 0;
int g_array[SIZE][3];

bool Judge(int i, int j)
{
	if (g_array[j][0] <= g_array[i][1] 
			&& g_array[j][1] >= g_array[i][0] )
		return true;
	return false;
}

void Dis(int size)
{
	for(int i = 0; i < g_num; i++)
		if(g_array[i][2] == 1 && (size > 1))
		{
			size--;
			cout << g_array[i][0] << "," << g_array[i][1] << ";";
		}
		else if(size == 1)
			cout << g_array[i][0] << "," << g_array[i][1];
		
}

int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d,%d", &g_array[g_num][0], &g_array[g_num][1]);
		g_array[g_num++][2] = 1;
		char t;
		scanf("%c", &t);
		while (t == ';')
		{
			scanf("%d,%d", &g_array[g_num][0], &g_array[g_num][1]);
			g_array[g_num++][2] = 1;
			scanf("%c", &t);
		}
	}

	
	//cout << g_num;
	int size = g_num;
	for (int i = 0; (g_array[i][2] ==1) && i < g_num; i++)
		for (int j = i+1; (g_array[j][2] ==1) && j < g_num; j++)
			if (Judge(i, j))
			{
				g_array[i][1] = g_array[j][1];
				g_array[j][2] = 0; 
				size--;
				j = i;
			}
			
	Dis(size);
	
	return 0;
}

/*

3 
1,10;32,45
78,94;5,16
80,100;200,220;16,32

*/




















