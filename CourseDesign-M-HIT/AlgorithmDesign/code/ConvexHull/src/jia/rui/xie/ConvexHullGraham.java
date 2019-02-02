package jia.rui.xie;

public class ConvexHullGraham 
{
	//向量（x1,y1）,(x2,y2)的叉积，行列式 
	double CrossMul(double x1,double y1,double x2,double y2)
	{
	    return x1*y2-x2*y1;
	}

	//带入真实值尝试
	//判断点c是在向量ab的逆时针方向还是顺时针方向，大于零逆时针，等于0则共线
	double CrossMul(Point a,Point b,Point c)
	{
	    return CrossMul(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
	}

	//向量（x1,y1）,(x2,y2)的点积
	double DotMul(double x1,double y1,double x2,double y2)
	{
	    return x1*x2+y1*y2;
	}

	//计算向量ab和ac点积
	double DotMul(Point a,Point b,Point c)
	{
	    return DotMul(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
	}

	//判断浮点数符号 
	int doublecmp(double d)
	{
	    if(Math.abs(d)<10e-6)
	        return 0;
	    return d>0?1:-1;
	}

	//带入真实值尝试
	//判断同一直线上的三个点位置，点c是否在点ab之间
	boolean betweenCmp(Point a,Point b,Point c)
	{
	    if(doublecmp(DotMul(c,a,b))<=0)
	        return true;
	    return false;
	}

	//判断j是否在base->i向量的左边或当共线时j是否位于它们的线段之间
	boolean isLeftorNearer(Point base,Point i,Point j)
	{
	    if(CrossMul(base,i,j)>0)
	        return true;
	    if(CrossMul(base,i,j)==0 && betweenCmp(base,i,j))
	        return true;
	    return false;
	}
	
	//以s中的最低点为参考点，对其他所有点进行极角排序（逆时针）
	//共线时离参考点较远的点排在前面，凸包的起始边共线点从近到远排列
	void sortpoint(Point s[],int nums)
	{
	    //找最低点
	    for(int i=1;i<nums;i++)
	    {
	        if(s[i].y<s[0].y || (s[i].y==s[0].y && s[i].x<s[0].x))
	        {
	        	Point temp = s[0];
	    	    s[0]=s[i];
	    	    s[i]=temp;
	        }  
	    }
	    qsortpoint(s,s[0],1,nums);
	    //将起始边上的共线点重新排列 
	    sortstartedge(s,nums);
	}

	//将点按极角逆时针排序
	void qsortpoint(Point s[],Point base,int start,int end)
	{
	    if(start>=end)
	        return;
	        
	    Point temp =null;
	    Point partition = s[end-1];
	    int i=start-1,j=start-1;
	    
	    while(++j<end-1)
	        if(isLeftorNearer(base,s[j],partition))
	        {
	        	temp = s[++i];
	    	    s[i]=s[j];
	    	    s[j]=temp;
	        }

	    temp = s[++i];
	    s[i]=s[j];
	    s[j]=temp;
	    
	    qsortpoint(s,base,start,i);
	    qsortpoint(s,base,i+1,end);
	}

	
	void sortstartedge(Point s[],int nums)
	{
	    int i, j;
	    //找到不共线的三个点
	    for(i=2;i<nums;i++)
	        if(CrossMul(s[0],s[1],s[i])!=0)
	            break;
	    
	    for(j=1;j<(i+1)/2;j++)
	    {
	    	Point temp = s[j];
    	    s[j]=s[i-j];
    	    s[i-j]=temp;
	    }
	    
	}
	
	//很明显因为这个地方要使用栈
	int ConvexHull(Point s[],int nums,Point result[])
	{
	    sortpoint(s,nums);
	    //栈顶指针
	    int top=0;
	    
	    if(nums<=3)
	    {
	        for(int i=0;i<nums;i++)
	            result[top++] = s[i];
	        return top;
	    }
	    
	    int i;
	    //先把前两节点放入
	    for(i=0;i<2;i++)
	        result[top++] = s[i];
	        
	    while(i<nums)
	    {
	    	//画图发现为正确步骤
	        //用<号判断则包含凸包边上的共线点，<=号判断则只包含凸包顶点
	    	//这个地方需要特别注意，因为当点少的时候没有共线的可能，如果点多了的话，肯定有共线的可能
	        if(CrossMul(result[top-2],result[top-1],s[i])<0)
	            top--;
	        else
	            result[top++] = s[i++];
	    }
	    //最后加入起点形成闭包
	    while(CrossMul(result[top-2],result[top-1],s[0])<=0)
	        top--;
	    
	    result[top++]=s[0];
	    
	    //返回值为栈中包含的节点数量
	    return top;
	}
}
