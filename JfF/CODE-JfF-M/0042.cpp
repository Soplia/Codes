#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 1001;
int g_array[SIZE][SIZE];

int g_line;
int g_col;
int g_maxNum = 0;
int g_teamNum = 0;

class Pos
{
 public:
 	Pos(int x = 0, int y = 0);
	int x;
	int y;
};
Pos::Pos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Search(queue<Pos> *myQueue)
{
	int tempTeamNum = 0;
	
	while(!myQueue->empty())
	{
		Pos p = myQueue->front();  
		myQueue->pop();
		int x = p.x;
		int y = p.y;
		
		if ((x-1 >= 0) && g_array[x-1][y] != 0)//左 
		{
			tempTeamNum++;
			g_array[x-1][y] = 0;
			myQueue->push(Pos(x-1,y));
		}
		if ((x+1 < g_col) && g_array[x+1][y] != 0)//右 
		{
			tempTeamNum++;
			g_array[x+1][y] = 0;
			myQueue->push(Pos(x+1,y));
		}
		if ((y-1 >= 0) && g_array[x][y-1] != 0)//上 
		{
			tempTeamNum++;
			g_array[x][y-1] = 0;
			myQueue->push(Pos(x,y-1));
		}
		if ((y+1 < g_line) && g_array[x][y+1] != 0)//下 
		{
			tempTeamNum++;
			g_array[x][y+1] = 0;
			myQueue->push(Pos(x,y+1));
		}
		if ((y-1 >= 0) && (x-1 >= 0) && g_array[x-1][y-1] != 0)//左上 
		{
			tempTeamNum++;
			g_array[x-1][y-1] = 0;
			myQueue->push(Pos(x-1,y-1));
		}
		if ((x-1 >= 0) && (y+1 < g_line) && g_array[x-1][y+1] != 0)//左下 
		{
			tempTeamNum++;
			g_array[x-1][y+1] = 0;
			myQueue->push(Pos(x-1,y+1));
		}
		if ((x+1 < g_col) && (y-1 >= 0) && g_array[x+1][y-1] != 0)//右上 
		{
			tempTeamNum++;
			g_array[x+1][y-1] = 0;
			myQueue->push(Pos(x+1,y-1));
		}
		if ((x+1 < g_col) && (y+1 < g_line) && g_array[x+1][y+1] != 0)//右下 
		{
			tempTeamNum++;
			g_array[x+1][y+1] = 0;
			myQueue->push(Pos(x+1,y+1));
		}
	}
	
	
	if (tempTeamNum > g_maxNum) 
		g_maxNum = tempTeamNum;
} 

int main()
{
	scanf("%d,%d", &g_line, &g_col);
	for (int i = 0; i < g_line; i++)
	{
		for (int j = 0; j < g_col-1; j++)
			scanf("%d,", &g_array[i][j]);
		scanf("%d", &g_array[i][g_col-1]);
	}
		
			
	queue<Pos> *myQueue = new queue<Pos>();
	for (int i = 0; i < g_line; i++)
		for (int j = 0; j < g_col; j++)
			if (g_array[i][j] != 0)
			{
				g_teamNum++;
				myQueue->push(Pos(i,j));
				Search(myQueue);
			} 
			
	cout << g_teamNum << "," <<g_maxNum;
	return 0;
}

