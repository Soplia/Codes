package jia.rui.xie;

public class ConvexHullGraham 
{
	//������x1,y1��,(x2,y2)�Ĳ��������ʽ 
	double CrossMul(double x1,double y1,double x2,double y2)
	{
	    return x1*y2-x2*y1;
	}

	//������ʵֵ����
	//�жϵ�c��������ab����ʱ�뷽����˳ʱ�뷽�򣬴�������ʱ�룬����0����
	double CrossMul(Point a,Point b,Point c)
	{
	    return CrossMul(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
	}

	//������x1,y1��,(x2,y2)�ĵ��
	double DotMul(double x1,double y1,double x2,double y2)
	{
	    return x1*x2+y1*y2;
	}

	//��������ab��ac���
	double DotMul(Point a,Point b,Point c)
	{
	    return DotMul(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
	}

	//�жϸ��������� 
	int doublecmp(double d)
	{
	    if(Math.abs(d)<10e-6)
	        return 0;
	    return d>0?1:-1;
	}

	//������ʵֵ����
	//�ж�ͬһֱ���ϵ�������λ�ã���c�Ƿ��ڵ�ab֮��
	boolean betweenCmp(Point a,Point b,Point c)
	{
	    if(doublecmp(DotMul(c,a,b))<=0)
	        return true;
	    return false;
	}

	//�ж�j�Ƿ���base->i��������߻򵱹���ʱj�Ƿ�λ�����ǵ��߶�֮��
	boolean isLeftorNearer(Point base,Point i,Point j)
	{
	    if(CrossMul(base,i,j)>0)
	        return true;
	    if(CrossMul(base,i,j)==0 && betweenCmp(base,i,j))
	        return true;
	    return false;
	}
	
	//��s�е���͵�Ϊ�ο��㣬���������е���м���������ʱ�룩
	//����ʱ��ο����Զ�ĵ�����ǰ�棬͹������ʼ�߹��ߵ�ӽ���Զ����
	void sortpoint(Point s[],int nums)
	{
	    //����͵�
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
	    //����ʼ���ϵĹ��ߵ��������� 
	    sortstartedge(s,nums);
	}

	//���㰴������ʱ������
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
	    //�ҵ������ߵ�������
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
	
	//��������Ϊ����ط�Ҫʹ��ջ
	int ConvexHull(Point s[],int nums,Point result[])
	{
	    sortpoint(s,nums);
	    //ջ��ָ��
	    int top=0;
	    
	    if(nums<=3)
	    {
	        for(int i=0;i<nums;i++)
	            result[top++] = s[i];
	        return top;
	    }
	    
	    int i;
	    //�Ȱ�ǰ���ڵ����
	    for(i=0;i<2;i++)
	        result[top++] = s[i];
	        
	    while(i<nums)
	    {
	    	//��ͼ����Ϊ��ȷ����
	        //��<���ж������͹�����ϵĹ��ߵ㣬<=���ж���ֻ����͹������
	    	//����ط���Ҫ�ر�ע�⣬��Ϊ�����ٵ�ʱ��û�й��ߵĿ��ܣ��������˵Ļ����϶��й��ߵĿ���
	        if(CrossMul(result[top-2],result[top-1],s[i])<0)
	            top--;
	        else
	            result[top++] = s[i++];
	    }
	    //����������γɱհ�
	    while(CrossMul(result[top-2],result[top-1],s[0])<=0)
	        top--;
	    
	    result[top++]=s[0];
	    
	    //����ֵΪջ�а����Ľڵ�����
	    return top;
	}
}
