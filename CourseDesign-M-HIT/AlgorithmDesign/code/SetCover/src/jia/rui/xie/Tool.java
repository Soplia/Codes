package jia.rui.xie;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Random;
import java.util.Set;

public class Tool 
{
	LinkedHashMap<String, Set<String>> sets = new LinkedHashMap<String, Set<String>>();
	//定义每个集合的元素的个数的大小
	int subSetLengthBound=30;
	
	//size 集合中数据的总量
	//num  子集合的个数
	private void CreateSet(int size,int num)
	{
		Random r = new Random();
		//标志有多少数据已经被使用了。
		boolean arr[]=new boolean[size+1];
		
		//生成每个子集合的长度，最后一个不生成
		int length[]=new int[num-1];
		for(int i=0;i<num-1;i++)
			length[i]=r.nextInt(subSetLengthBound)+1;//标志不能为0
		
		for(int i=0;i<num-1;i++)
		{
			Set<String> subs=new HashSet<String>();
			for(int j=0;j<length[i];j++)
			{
				//不要产生0
				int temp=r.nextInt(size)+1;
				arr[temp]=true;
				subs.add(temp+"");
			}
			sets.put("S"+(i+1),subs);
		}
		
		//将没有被使用的元素，统统的都放到最后一个集合中
		Set<String> subs=new HashSet<String>();
		for(int i=1;i<=size;i++)
			if(!arr[i])
				subs.add(i+"");
		//防止没有元素剩余，将随便一个数1写到集合中。
		subs.add("1");
		sets.put("S"+num,subs);
	}

	public void WriteSetIntoFile(int size,int num)
	{
		String filePath = "F:\\Matlab\\subSets"+size+".txt";
		Set<String> subSet;
		boolean first;
		
		CreateSet(size,num);
		
		try 
		{
			BufferedWriter out = new BufferedWriter(new FileWriter(filePath));
			for (String key : sets.keySet()) 
			{
				first=true;
				subSet=new HashSet<String>(sets.get(key));
				for(Iterator it=subSet.iterator();it.hasNext();)
				{
					if(first)
					{
						out.write((String)it.next());
						first=false;
					}
					else
						out.write(","+(String)it.next());
				}
				out.write("\r\n");
			}
			out.close();
		} 
		catch (IOException e) 
		{
			System.out.println(e.getMessage());
			System.exit(1);
		}
	}
}
