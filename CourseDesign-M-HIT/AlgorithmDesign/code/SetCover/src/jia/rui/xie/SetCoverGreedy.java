package jia.rui.xie;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Set;

public class SetCoverGreedy 
{
	//集合列表
	private static LinkedHashMap<String, Set<Integer>> sets = new LinkedHashMap<String, Set<Integer>>();
	//所有元素的集合
	private static HashSet<Integer> universe = new HashSet<Integer>();
	
	private static Set<Integer> intersection;
	
	//只为排序，验证结果
	static List<Integer> list;
	static ArrayList<String> coverKeys = new ArrayList<String>();
	
	public static void main(String[] args) 
	{
		Date dt1=null,dt2=null;
		Long time1,time2;
		
		if(args.length != 3)
		{
			System.out.println("Usage Error! Specify filename as command line argument.");
			System.exit(1);
		}
		
		//生成相应的文件
		Tool tool=new Tool();
		tool.WriteSetIntoFile(100,100);
		tool.WriteSetIntoFile(1000,1000);
		tool.WriteSetIntoFile(5000,5000);
		
		//测试100时
		readFile(args[0]);
		//printSets();
		dt1= new Date();
		time1= dt1.getTime();
		greedySetCover();
		dt2= new Date();
		time2= dt2.getTime();
		System.out.println("The Clapse time is:"+(time2-time1)+"ms");
		Sort();
		System.out.println();
		
		//测试1000时
		readFile(args[1]);
		//printSets();
		dt1= new Date();
		time1= dt1.getTime();
		greedySetCover();
		dt2= new Date();
		time2= dt2.getTime();
		System.out.println("The Clapse time is:"+(time2-time1)+"ms");
		Sort();
		System.out.println();
		
		//测试5000时
		readFile(args[2]);
		//printSets();
		dt1= new Date();
		time1= dt1.getTime();
		greedySetCover();
		dt2= new Date();
		time2= dt2.getTime();
		System.out.println("The Clapse time is:"+(time2-time1)+"ms");
		Sort();
		System.out.println();
	}

	private static void readFile(String filename) 
	{
		int set = 1;
		try 
		{
			BufferedReader in = new BufferedReader(new FileReader(filename));
			String line;
			while ((line = in.readLine()) != null) 
			{
				String elements[] = line.split(",");
				Set<Integer> list = new HashSet<Integer>();
				for (String e : elements) 
				{
					//首先把所有的元素都放到了list中
					list.add(Integer.parseInt(e));
					//存放所有的元素,如果有重复的，会自动清除重复值
					universe.add(Integer.parseInt(e));
				}
				//然后给list一个标识，再放到set中
				sets.put("S" + set, list);
				set++;
			}
			in.close();
		} 
		catch (IOException e) 
		{
			System.out.println(e.getMessage());
			System.exit(1);
		}
	}

	private static void greedySetCover() 
	{
		while (!universe.isEmpty()) 
		{
			int max = Integer.MIN_VALUE;
			String maxKey = "";
			
			//存放交集最大的子集
			Set<Integer> maxIntersection = new HashSet<Integer>();
			
			//遍历寻找当前与universe交集最大的子集合
			for (String key : sets.keySet()) 
			{
				intersection = new HashSet<Integer>(sets.get(key));
				//只留下intersection中与universe相交的元素
				intersection.retainAll(universe);
				if (max < intersection.size()) 
				{
					maxKey = key;
					max = intersection.size();
					maxIntersection = intersection;
				}
			}
			//在universe中去除maxIntersection中的元素
			universe.removeAll(maxIntersection);
			//将该集合的名字添加到结果集合中
			coverKeys.add(maxKey);
		}
		System.out.println("Set-cover = " + coverKeys);
	}

	//用于验证，查看是否包含了集合的所有数据
	private static void Sort()
	{
		//只为获得一个list对象，然后使用Collections自带的排序函数
		//将结果集合中的数据全部存放到list中
		list=new ArrayList<Integer>();
		Object key[]= (Object[])coverKeys.toArray();
		for(int i=0;i<key.length;i++)
		{
			Object[] temp=(Object[])sets.get(coverKeys.get(i)).toArray();
			for(int j=0;j<temp.length;j++)
				list.add(new Integer(temp[j].toString()));
		}
		Collections.sort(list);
		System.out.println("List = "+list);
	}
	
	private static void printSets() 
	{
		//这个东西本来就是一个键值对
		for (String key : sets.keySet()) 
		{
			System.out.printf("%-3s = ",key);
			System.out.println(sets.get(key));
		}
		System.out.println("Universe  = " + universe);
		System.out.println();
	}
	
}

