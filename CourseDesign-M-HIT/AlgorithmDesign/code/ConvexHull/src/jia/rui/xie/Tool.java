package jia.rui.xie;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Tool 
{   
	//标志是否产生过这个点
	public List<Point> GrenatePointSet(int scope,int number)
	{
		List<Point>pointSet= new ArrayList<Point>();
		boolean [] []flag = new boolean[scope][scope];
		
		Random r = new Random();
		do
		{
			int x = r.nextInt(scope);
			int y = r.nextInt(scope);
			if(!flag[x][y])
			{
				number--;
				flag[x][y]=true;
				pointSet.add(new Point(x,y));
			}
		}while(number>0);

		return pointSet;
	}
	
	//为函数提供输入参数
	Point [] PointListToArray(List<Point> s)
	{
		int size=s.size();
		if(0==size)
			return null;
		Point arr[]=new Point[size];
		
		for(int i=0;i<size;i++)
		{
			arr[i]=s.get(i);
		}
		return arr;
	}
	
	//为函数提供输入参数
	List<Line> PointArrToLineList(Point arr[],int size)
	{
		if(0==size)
			return null;
		List<Line> line =new ArrayList<Line>();
		for(int i=0;i<size-1;i++)
			line.add(new Line(arr[i],arr[i+1]));
		return line;
	}
}
