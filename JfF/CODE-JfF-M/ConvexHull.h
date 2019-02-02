#ifndef _CONVEXHULL_HGW_
#define _CONVEXHULL_HGW_

#include<vector>
#include<stack>

class CConvexHull
{
 public:
	//��
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

	//��
	struct Line
	{
		Point from;
		Point to;
		Line(Point f,Point t)
			:from(f),to(t)
		{}
	};

	//���㷨�����õݹ�ʵ�֣����������÷ǵݹ�ʵ��
	//����һ������ջʵ��
	struct StackElement
	{
		//��ǰ��Ҫ����ĵ�ļ��ϵ�����
		std::vector<int> PointsIndex;	

		Point		from;
		Point		to;
		//�ڻ��ּ��ϵ�ͬʱ�����һ������
		Point		Pmax;
	};

	typedef std::vector<Point>	PointVector;
	typedef std::vector<Line>	LineVector;
	typedef std::stack<StackElement>	ConvexHullStack;

public:
	//������ļ��ϣ�����������ɵ�͹��
	void go(PointVector & Points,LineVector &Lines);
};

#endif
