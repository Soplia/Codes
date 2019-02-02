
//实现文件ConvexHull.cpp就实现了一个函数：
//#include "ConvexHull.h"
#include <iostream>

#include<vector>
#include<stack>

using namespace std;

struct Point
	{
		float x;
		float y;

		Point(float a,float b)
			:x(a),y(b)
		{}
		Point()
			:x(0),y(0)
		{}
	};

	//线
	struct Line
	{
		Point from;
		Point to;
		Line(Point f,Point t)
			:from(f),to(t)
		{}
	};

	//该算法可以用递归实现，我这里是用非递归实现
	//所有一个辅助栈实现
	struct StackElement
	{
		//当前需要处理的点的集合的索引
		std::vector<int> PointsIndex;	

		Point		from;
		Point		to;
		//在划分集合的同时计算出一个最大点
		Point		Pmax;
	};

	typedef std::vector<Point>	PointVector;
	typedef std::vector<Line>	LineVector;
	typedef std::stack<StackElement>	ConvexHullStack;



void go(PointVector & Points,LineVector &Lines)
{
	Lines.clear();
	if(Points.size() < 2)
		return;
	
	//1.找出点中最左和最右的两个点，这两个点一定是凸包顶点
	Point mostLeft = *(Points.begin());
	Point mostRight = *(Points.begin());
	
	
	
	PointVector::iterator it = Points.begin();
	while(it != Points.end())
	{
		if(it->x < mostLeft.x )
			mostLeft = *it;
		if(it->x > mostRight.x)
			mostRight = *it;
		it++;
	}
	
	//2.把集合分治为两个集合，上包和下包

	StackElement UpHull;	//上包
	StackElement DownHull;	//下包,实际处理跟上包一样

	UpHull.from = mostLeft;
	UpHull.to = mostRight;

	DownHull.from = mostRight;
	DownHull.to = mostLeft;

	//		    |x1 y1 1|
	//行列式	|x2 y2 1| = x1*y2+x3*y1+x2*y3-x3*y2-x2*y1-x1*y3
	//		    |x3 y3 1|
	//				      = x1*y2-x2*y1+x3*(y1-y2)+y3*(x2-x1)
	//当P3位于射线P1P2的左侧时，该表达式为正。
	//同时该表达式的值为三角形P1P2P3的面积的一半

	//遍历所有点
	it = Points.begin();
	//减小while循环负担的辅助变量
	//即先求出 x1*y2-x2*y1
	float xy = UpHull.from.x * UpHull.to.y -
		UpHull.to.x * UpHull.from.y;

	float max = 0;
	float min = 0;

	//遍历所有的点，划分为两个集合
	//同时求出两个集合中的最大点
	while(it != Points.end())
	{
		//计算行列式的值
		float express = 
			xy + it->x*(UpHull.from.y - UpHull.to.y)+
			(UpHull.to.x - UpHull.from.x) * it->y;
		if(express > 0.0f)
		{
			//当前点在P1P2的左端，划分到上包
			//记录索引而已
			UpHull.PointsIndex.push_back(it - Points.begin());

			//同时算出面积最大的一个点
			if(express > max)
			{
				max = express;
				UpHull.Pmax = *it;
			}
		}

		//如果不能划分到上包，那么可能划分到下包
		if(express < 0.0f)
		{
			DownHull.PointsIndex.push_back(it - Points.begin());
			if(express < min)
			{
				min = express;
				DownHull.Pmax = *it;
			}
		}
		it++;
	}

	//将上包和下包压入栈，等待进一步处理
	ConvexHullStack chstack;
	chstack.push(UpHull);
	chstack.push(DownHull);

	//3.分治处理上包和下包
	do
	{
		StackElement element = chstack.top();
		chstack.pop();

		//该集合当中不需要再扩展，则两个点就为组成凸包的线段
		if(element.PointsIndex.size() == 0)
		{
			Lines.push_back(Line(element.from,element.to));
		}
		else
		{
			//再次将当前集合划分到不同的集合中去
			StackElement left,right;
			left.from = element.from;
			left.to = element.Pmax;

			right.from = element.Pmax;
			right.to = element.to;

			float express;
			float leftmax = 0;
			float rightmax = 0;

			std::vector<int>::iterator indexit=element.PointsIndex.begin();
			while(indexit != element.PointsIndex.end())
			{
				//检测是否在 left的左侧
				express = left.from.x * left.to.y - left.to.x *left.from.y +
					Points[*indexit].x * (left.from.y - left.to.y) +
					Points[*indexit].y * (left.to.x - left.from.x);
				if(express > 0.0f)
				{
					left.PointsIndex.push_back(*indexit);
					//同时算出面积最大的一个点
					if(express > leftmax)
					{
						leftmax = express;
						left.Pmax = Points[*indexit];
					}
					indexit++;
					continue;
				}

				express = right.from.x * right.to.y - right.to.x *right.from.y +
					Points[*indexit].x * (right.from.y - right.to.y) +
					Points[*indexit].y * (right.to.x - right.from.x);
				if(express > 0.0f)
				{
					right.PointsIndex.push_back(*indexit);
					//同时算出面积最大的一个点
					if(express > rightmax)
					{
						rightmax = express;
						right.Pmax = Points[*indexit];
					}
					indexit++;
					continue;
				}
				indexit++;
			}
			chstack.push(left);
			chstack.push(right);
		}
	}while(!chstack.empty());
}

int main()
{
	//CConvexHull convex=new CConvexHull();
    Point pa[] = {{0,0},{1,0},{2,0},{3,0},{4,0},
                {4,1},{4,2},{4,3},{4,4},
                {3,4},{2,4},{1,4},{0,4},
                {0,3},{0,2},{0,1},{2,2},{1,1}};

    cout<<"convex hull is:"<<endl;
    LineVector line; 
    PointVector point;
    for(int i=0;i<18;i++)
    	point.push_back(pa[i]);
    int nums;
    go(point,line);
    
	for(int i=0;i<line.size();i++)
    {
    	cout<<i+1<<line[i].from.x<<" "<<line[i].from.y<<endl;
    	cout<<i+1<<line[i].to.x<<" "<<line[i].to.y<<endl;
	}
    return 0;
}




