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
	//�����б�
	private static LinkedHashMap<String, Set<Integer>> sets = new LinkedHashMap<String, Set<Integer>>();
	//����Ԫ�صļ���
	private static HashSet<Integer> universe = new HashSet<Integer>();
	
	private static Set<Integer> intersection;
	
	//ֻΪ������֤���
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
		
		//������Ӧ���ļ�
		Tool tool=new Tool();
		tool.WriteSetIntoFile(100,100);
		tool.WriteSetIntoFile(1000,1000);
		tool.WriteSetIntoFile(5000,5000);
		
		//����100ʱ
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
		
		//����1000ʱ
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
		
		//����5000ʱ
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
					//���Ȱ����е�Ԫ�ض��ŵ���list��
					list.add(Integer.parseInt(e));
					//������е�Ԫ��,������ظ��ģ����Զ�����ظ�ֵ
					universe.add(Integer.parseInt(e));
				}
				//Ȼ���listһ����ʶ���ٷŵ�set��
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
			
			//��Ž��������Ӽ�
			Set<Integer> maxIntersection = new HashSet<Integer>();
			
			//����Ѱ�ҵ�ǰ��universe���������Ӽ���
			for (String key : sets.keySet()) 
			{
				intersection = new HashSet<Integer>(sets.get(key));
				//ֻ����intersection����universe�ཻ��Ԫ��
				intersection.retainAll(universe);
				if (max < intersection.size()) 
				{
					maxKey = key;
					max = intersection.size();
					maxIntersection = intersection;
				}
			}
			//��universe��ȥ��maxIntersection�е�Ԫ��
			universe.removeAll(maxIntersection);
			//���ü��ϵ�������ӵ����������
			coverKeys.add(maxKey);
		}
		System.out.println("Set-cover = " + coverKeys);
	}

	//������֤���鿴�Ƿ�����˼��ϵ���������
	private static void Sort()
	{
		//ֻΪ���һ��list����Ȼ��ʹ��Collections�Դ���������
		//����������е�����ȫ����ŵ�list��
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
		//���������������һ����ֵ��
		for (String key : sets.keySet()) 
		{
			System.out.printf("%-3s = ",key);
			System.out.println(sets.get(key));
		}
		System.out.println("Universe  = " + universe);
		System.out.println();
	}
	
}

