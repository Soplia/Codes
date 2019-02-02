package jia.rui.xie;

import java.util.ArrayList;
import java.util.List;

public class StackElement 
{
	public List<Integer> PointsIndex;
	public Point from;
	public Point to;
	public Point pamx;
	
	StackElement()
	{
		PointsIndex=new ArrayList<Integer>();
	}
}
