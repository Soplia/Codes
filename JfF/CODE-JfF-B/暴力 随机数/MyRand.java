import java.util.Random;
public class MyRand 
{
	//��Բ�İ뾶��100;
	public static void main(String args[])
	{
		Random rand=new Random();
		int x;
		int y;
		int count=0;//��¼������������ĸ���;
		int temp=0;
		for(int i=1;i<=100000;i++)
		{
			x=rand.nextInt(100);
			y=rand.nextInt(100);
			if(x*x+y*y<=100*100)
				count++;
			else 
				temp++;
		}
		System.out.println(count);
		System.out.println("Բ������:"+4*((float)count/100000));
	}
}
