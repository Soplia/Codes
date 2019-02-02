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
	//����ÿ�����ϵ�Ԫ�صĸ����Ĵ�С
	int subSetLengthBound=30;
	
	//size ���������ݵ�����
	//num  �Ӽ��ϵĸ���
	private void CreateSet(int size,int num)
	{
		Random r = new Random();
		//��־�ж��������Ѿ���ʹ���ˡ�
		boolean arr[]=new boolean[size+1];
		
		//����ÿ���Ӽ��ϵĳ��ȣ����һ��������
		int length[]=new int[num-1];
		for(int i=0;i<num-1;i++)
			length[i]=r.nextInt(subSetLengthBound)+1;//��־����Ϊ0
		
		for(int i=0;i<num-1;i++)
		{
			Set<String> subs=new HashSet<String>();
			for(int j=0;j<length[i];j++)
			{
				//��Ҫ����0
				int temp=r.nextInt(size)+1;
				arr[temp]=true;
				subs.add(temp+"");
			}
			sets.put("S"+(i+1),subs);
		}
		
		//��û�б�ʹ�õ�Ԫ�أ�ͳͳ�Ķ��ŵ����һ��������
		Set<String> subs=new HashSet<String>();
		for(int i=1;i<=size;i++)
			if(!arr[i])
				subs.add(i+"");
		//��ֹû��Ԫ��ʣ�࣬�����һ����1д�������С�
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
