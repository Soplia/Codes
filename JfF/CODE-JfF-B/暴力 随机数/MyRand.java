import java.util.Random;
public class MyRand 
{
	//设圆的半径是100;
	public static void main(String args[])
	{
		Random rand=new Random();
		int x;
		int y;
		int count=0;//记录落在扇形区域的个数;
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
		System.out.println("圆周率是:"+4*((float)count/100000));
	}
}
