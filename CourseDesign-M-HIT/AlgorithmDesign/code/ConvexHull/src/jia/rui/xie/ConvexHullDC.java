package jia.rui.xie;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class ConvexHullDC 
{
	List<Line> GetConvexHull(List<Point> Points)
	{
		List<Line> Lines= new ArrayList<Line>();
		
		if(Points.size() < 2)
			return null;
		
		//找出点中最左和最右的两个点，这两个点一定是凸包顶点
		Point mostLeft = Points.get(0);
		Point mostRight = Points.get(0);
		
		for(int i=0;i<Points.size();i++)
		{
			Point temp=Points.get(i);
			
			if(temp.x < mostLeft.x )
				mostLeft = temp;
			if(temp.x > mostRight.x)
				mostRight = temp;
		}
		
		//把集合分治为两个集合，上包和下包
		StackElement UpHull =new StackElement();	//上包
		StackElement DownHull =new StackElement();	//下包,实际处理跟上包一样
		UpHull.from = mostLeft;
		UpHull.to = mostRight;
		DownHull.from = mostRight;
		DownHull.to = mostLeft;

		//遍历所有点
		//减小while循环负担的辅助变量
		//即先求出 x1*y2-x2*y1
		
		double xy = UpHull.from.x * UpHull.to.y -UpHull.to.x * UpHull.from.y;
		double max = 0;
		double min = 0;

		//遍历所有的点，划分为两个集合
		//同时求出两个集合中的最大点
		for(int i=0;i<Points.size();i++)
		{
			Point temp= Points.get(i);
			//计算行列式的值
			double express =xy + temp.x*(UpHull.from.y - UpHull.to.y)+(UpHull.to.x - UpHull.from.x) * temp.y;
			
			if(express > 10e-6)
			{
				//当前点在P1P2的左端，划分到上包
				//记录索引而已
				UpHull.PointsIndex.add(new Integer(i));
				//同时算出与最左和最右的点构成面积最大的一个点
				if(express > max)
				{
					max = express;
					UpHull.pamx=temp;
				}
			}

			//如果不能划分到上包，那么可能划分到下包
			if(express < 10e-6)
			{
				DownHull.PointsIndex.add(new Integer(i));
				//负数就要看绝对值了
				if(express < min)
				{
					min = express;
					DownHull.pamx =temp;
				}
			}
		}

		//将上包和下包压入栈，等待进一步处理
		Stack<StackElement> chstack=new Stack<StackElement>();
		chstack.push(UpHull);
		chstack.push(DownHull);

		//分治处理上包和下包
		do
		{
			StackElement element = chstack.pop();
			
			//该集合当中不需要再扩展，则两个点就为组成凸包的线段
			//这个也就是结束条件
			if(element.PointsIndex.size() == 0)
				Lines.add(new Line(element.from,element.to));

			else
			{
				//再次将当前集合划分到不同的集合中去
				StackElement left = new StackElement();
				StackElement right = new StackElement();
				
				left.from = element.from;
				left.to = element.pamx;

				right.from = element.pamx;
				right.to = element.to;

				double express;
				double leftmax = 0;
				double rightmax = 0;
				
				//获得上包所包含的点
				List<Integer> indexit=element.PointsIndex;
				
				for(int i=0;i<indexit.size();i++)
				{
					int index= indexit.get(i).intValue();
					//检测是否在 left的左侧
					express = left.from.x * left.to.y - left.to.x *left.from.y +
						Points.get(index).x * (left.from.y - left.to.y) +
						Points.get(index).y * (left.to.x - left.from.x);
					
					if(express > 0.0f)
					{
						left.PointsIndex.add(new Integer(index));
						//同时算出面积最大的一个点
						if(express > leftmax)
						{
							leftmax = express;
							left.pamx = Points.get(index);
						}
						//continue;
					}

					express = right.from.x * right.to.y - right.to.x *right.from.y +
						Points.get(index).x * (right.from.y - right.to.y) +
						Points.get(index).y * (right.to.x - right.from.x);
					
					if(express > 0.0f)
					{
						right.PointsIndex.add(new Integer(index));
						//同时算出面积最大的一个点
						if(express > rightmax)
						{
							rightmax = express;
							right.pamx = Points.get(index);
						}

						//continue;
					}
				}
				chstack.push(left);
				chstack.push(right);
			}
		}while(!chstack.empty());
		
		return Lines;
	}
}
