package jia.rui.xie;

import java.util.ArrayList;
import java.util.List;

public class ConvexHullEnum 
{
	//���жϵ㼯
	List<Point> pointSet;
	//͹���߼�
	List<Line> lineSet;
	
	ConvexHullEnum()
	{
		pointSet=null;
		lineSet=new ArrayList<Line>();
	}
	
	public List<Line> getLineSet()
	{
		return this.lineSet;
	}
	
	public void setPointSet(List<Point> pointSet) 
	{
		this.pointSet = pointSet;
	}

	public void setLineSet(List<Line> lineSet) 
	{
		this.lineSet = lineSet;
	}

	public List<Line> ConvexHullEnumSlove(List<Point> point)
	{
		setPointSet(point);
		if(pointSet==null)
			return null;
		
		lineSet.clear();
		double a,b,c,cc;
		Point lineHead,lineTail,temp;
		int size=pointSet.size();
		
		for(int i=0;i<size;i++)
		{
			lineHead=pointSet.get(i);
			for(int j=i+1;j<size;j++)
			{
				lineTail=pointSet.get(j);
				
				//������жϵ�ֱ��
				a=lineHead.y-lineTail.y;
				b=lineTail.x-lineHead.x;

				c=lineHead.y*lineTail.x-lineHead.x*lineTail.y;
				
				//�Լ�����ʣ��ĵ�����ж�
				int great=0,less=0;
				
				for(int k=0;k<size;k++)
				{
					if(k==i||k==j)
						continue;
					temp=pointSet.get(k);
					cc=a*temp.x+b*temp.y;
					if(cc>c)
						great++;
					else if(cc<c)
						less++;
					if(great*less!=0)
						break;
				}
				if(0==great*less)
					lineSet.add(new Line(lineHead,lineTail));
			}
		}
		return lineSet;
	}
}
