#ifndef _CONVEXHULL_HGW_
#define _CONVEXHULL_HGW_

#include<vector>
#include<stack>

class CConvexHull
{
 public:
	//点
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

public:
	//给定点的集合，返回由线组成的凸包
	void go(PointVector & Points,LineVector &Lines);
};

#endif
