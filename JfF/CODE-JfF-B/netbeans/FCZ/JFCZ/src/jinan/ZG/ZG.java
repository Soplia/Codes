package jinan.ZG;
public class ZG 
{
    public double A[][];
    public double Y[];
    public double X[];
    public double B[];
    public double b[];
    public int size;
    //进行数组初始化
     public void init(double a[][],double c[],int s)
    {
        this.size=s+1;
        b=new double[this.size];
        A=new double[this.size][this.size];
        for(int i=1;i<this.size;i++)
            for(int j=1;j<this.size;j++)
                A[i][j]=a[i-1][j-1];
        for(int i=1;i<this.size;i++)
            b[i]=c[i-1];
        Y=new double [this.size];
        X=new double [this.size];
        B=new double [this.size];
    }
    public void solve()
    {
        setB();
        setY();
        setX();
    }
    //求解B
    public void setB()
    {
        B[1]=A[1][2]/A[1][1];
        for(int i=2;i<size-1;i++)
            B[i]=A[i][i+1]/(A[i][i]-A[i][i-1]*B[i-1]);
    }
    //求解Y
    public void setY()
    {
        Y[1]=b[1]/A[1][1];
        for(int i=2;i<size;i++)
            Y[i]=(b[i]-A[i][i-1]*Y[i-1])/(A[i][i]-A[i][i-1]*B[i-1]);
    }
    //求解X
    public void setX()
    {
        X[size-1]=Y[size-1];
        for(int i=size-2;i>=1;i--)
            X[i]=Y[i]-B[i]*X[i+1];
    }
    //用于进行调试
    public void printArray(char name)
    {
        switch(name)
        {
            case'A':
            {
                for(int i=1;i<size;i++)
                {
                    for(int j=1;j<size;j++)
                        System.out.print(A[i][j]+"   ");
                    System.out.println();
                } 
            };break;
             case'Y':
           {
                for(int i=1;i<size;i++)
                    System.out.print(Y[i]+"   ");
            };break;  
             case 'X':
            {
                for(int i=1;i<size;i++)
                    System.out.print(X[i]+"   ");
            };break; 
             case 'B':
            {
                for(int i=1;i<size;i++)
                    System.out.print(B[i]+"   ");
            };break; 
        }
    }
  
    public static void main(String args[])
    {
        double a[][]={{2,-1,0,0,0},{-1,2,-1,0,0},{0,-1,2,-1,0},{0,0,-1,2,-1},{0,0,0,-1,2}};
        double b[]={1,2,3,2,1};
        int size=5;
        ZG myZg=new ZG();
        myZg.init(a,b,size);
        myZg.solve();
        myZg.printArray('B');
        System.out.println();
        myZg.printArray('Y');
        System.out.println();
        myZg.printArray('X');
    }

}
