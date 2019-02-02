
//ʵ���ļ�ConvexHull.cpp��ʵ����һ��������
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



void go(PointVector & Points,LineVector &Lines)
{
	Lines.clear();
	if(Points.size() < 2)
		return;
	
	//1.�ҳ�������������ҵ������㣬��������һ����͹������
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
	
	//2.�Ѽ��Ϸ���Ϊ�������ϣ��ϰ����°�

	StackElement UpHull;	//�ϰ�
	StackElement DownHull;	//�°�,ʵ�ʴ�����ϰ�һ��

	UpHull.from = mostLeft;
	UpHull.to = mostRight;

	DownHull.from = mostRight;
	DownHull.to = mostLeft;

	//		    |x1 y1 1|
	//����ʽ	|x2 y2 1| = x1*y2+x3*y1+x2*y3-x3*y2-x2*y1-x1*y3
	//		    |x3 y3 1|
	//				      = x1*y2-x2*y1+x3*(y1-y2)+y3*(x2-x1)
	//��P3λ������P1P2�����ʱ���ñ��ʽΪ����
	//ͬʱ�ñ��ʽ��ֵΪ������P1P2P3�������һ��

	//�������е�
	it = Points.begin();
	//��Сwhileѭ�������ĸ�������
	//������� x1*y2-x2*y1
	float xy = UpHull.from.x * UpHull.to.y -
		UpHull.to.x * UpHull.from.y;

	float max = 0;
	float min = 0;

	//�������еĵ㣬����Ϊ��������
	//ͬʱ������������е�����
	while(it != Points.end())
	{
		//��������ʽ��ֵ
		float express = 
			xy + it->x*(UpHull.from.y - UpHull.to.y)+
			(UpHull.to.x - UpHull.from.x) * it->y;
		if(express > 0.0f)
		{
			//��ǰ����P1P2����ˣ����ֵ��ϰ�
			//��¼��������
			UpHull.PointsIndex.push_back(it - Points.begin());

			//ͬʱ����������һ����
			if(express > max)
			{
				max = express;
				UpHull.Pmax = *it;
			}
		}

		//������ܻ��ֵ��ϰ�����ô���ܻ��ֵ��°�
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

	//���ϰ����°�ѹ��ջ���ȴ���һ������
	ConvexHullStack chstack;
	chstack.push(UpHull);
	chstack.push(DownHull);

	//3.���δ����ϰ����°�
	do
	{
		StackElement element = chstack.top();
		chstack.pop();

		//�ü��ϵ��в���Ҫ����չ�����������Ϊ���͹�����߶�
		if(element.PointsIndex.size() == 0)
		{
			Lines.push_back(Line(element.from,element.to));
		}
		else
		{
			//�ٴν���ǰ���ϻ��ֵ���ͬ�ļ�����ȥ
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
				//����Ƿ��� left�����
				express = left.from.x * left.to.y - left.to.x *left.from.y +
					Points[*indexit].x * (left.from.y - left.to.y) +
					Points[*indexit].y * (left.to.x - left.from.x);
				if(express > 0.0f)
				{
					left.PointsIndex.push_back(*indexit);
					//ͬʱ����������һ����
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
					//ͬʱ����������һ����
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




