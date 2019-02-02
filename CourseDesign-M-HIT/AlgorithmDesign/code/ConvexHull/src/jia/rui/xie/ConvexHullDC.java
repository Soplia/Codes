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
		
		//�ҳ�������������ҵ������㣬��������һ����͹������
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
		
		//�Ѽ��Ϸ���Ϊ�������ϣ��ϰ����°�
		StackElement UpHull =new StackElement();	//�ϰ�
		StackElement DownHull =new StackElement();	//�°�,ʵ�ʴ�����ϰ�һ��
		UpHull.from = mostLeft;
		UpHull.to = mostRight;
		DownHull.from = mostRight;
		DownHull.to = mostLeft;

		//�������е�
		//��Сwhileѭ�������ĸ�������
		//������� x1*y2-x2*y1
		
		double xy = UpHull.from.x * UpHull.to.y -UpHull.to.x * UpHull.from.y;
		double max = 0;
		double min = 0;

		//�������еĵ㣬����Ϊ��������
		//ͬʱ������������е�����
		for(int i=0;i<Points.size();i++)
		{
			Point temp= Points.get(i);
			//��������ʽ��ֵ
			double express =xy + temp.x*(UpHull.from.y - UpHull.to.y)+(UpHull.to.x - UpHull.from.x) * temp.y;
			
			if(express > 10e-6)
			{
				//��ǰ����P1P2����ˣ����ֵ��ϰ�
				//��¼��������
				UpHull.PointsIndex.add(new Integer(i));
				//ͬʱ�������������ҵĵ㹹���������һ����
				if(express > max)
				{
					max = express;
					UpHull.pamx=temp;
				}
			}

			//������ܻ��ֵ��ϰ�����ô���ܻ��ֵ��°�
			if(express < 10e-6)
			{
				DownHull.PointsIndex.add(new Integer(i));
				//������Ҫ������ֵ��
				if(express < min)
				{
					min = express;
					DownHull.pamx =temp;
				}
			}
		}

		//���ϰ����°�ѹ��ջ���ȴ���һ������
		Stack<StackElement> chstack=new Stack<StackElement>();
		chstack.push(UpHull);
		chstack.push(DownHull);

		//���δ����ϰ����°�
		do
		{
			StackElement element = chstack.pop();
			
			//�ü��ϵ��в���Ҫ����չ�����������Ϊ���͹�����߶�
			//���Ҳ���ǽ�������
			if(element.PointsIndex.size() == 0)
				Lines.add(new Line(element.from,element.to));

			else
			{
				//�ٴν���ǰ���ϻ��ֵ���ͬ�ļ�����ȥ
				StackElement left = new StackElement();
				StackElement right = new StackElement();
				
				left.from = element.from;
				left.to = element.pamx;

				right.from = element.pamx;
				right.to = element.to;

				double express;
				double leftmax = 0;
				double rightmax = 0;
				
				//����ϰ��������ĵ�
				List<Integer> indexit=element.PointsIndex;
				
				for(int i=0;i<indexit.size();i++)
				{
					int index= indexit.get(i).intValue();
					//����Ƿ��� left�����
					express = left.from.x * left.to.y - left.to.x *left.from.y +
						Points.get(index).x * (left.from.y - left.to.y) +
						Points.get(index).y * (left.to.x - left.from.x);
					
					if(express > 0.0f)
					{
						left.PointsIndex.add(new Integer(index));
						//ͬʱ����������һ����
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
						//ͬʱ����������һ����
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
