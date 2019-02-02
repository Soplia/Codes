package jinan.GS;
public class GS 
{
    //存放U
    public double A[][];
    //存放Y
    public double B[];
    //X是最终的结果
    public double X[];
    public int size;
    public void init(double a[][],double b[],int s)
    {
        this.size=s+1;
        B=new double[this.size];
        A=new double[this.size][this.size];
        for(int i=1;i<this.size;i++)
            for(int j=1;j<this.size;j++)
                A[i][j]=a[i-1][j-1];
        for(int i=1;i<this.size;i++)
            B[i]=b[i-1];
        X=new double [this.size];
    }
    //利用高斯消元法，将系数矩阵化为上三角矩阵
    public void makeStand()
    {
        //从第一行开始到N-1行为止，逐行进行消元
        for(int row=1;row<size-1;row++)
        {
            //使用-Li/Ar进行消元
            for(int i=row+1;i<size;i++)
            {
                double temp=A[i][row];
                for(int j=row;j<size;j++)
                    A[i][j]+=A[row][j]*(-temp/A[row][row]);
                B[i]+=B[i-1]*(-temp/A[row][row]);
            }
        }
    }
    //回代求得相应的X
    public double getUY(int row)
    {
        double sum=0;
        for(int i=row+1;i<size;i++)
            sum+=X[i]*A[row][i];
        return sum;
    }
    //计算最终的结果
    public void setX()
    {
        X[size-1]=B[size-1]/A[size-1][size-1];
        for(int i=size-2;i>=1;i--)
            X[i]=(B[i]-getUY(i))/A[i][i];
    }
    public void solve()
    {
        makeStand();
        setX();
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
    /*
    public static void main(String args[])
    {
        double a[][]={{2,-1,0,0,0},{-1,2,-1,0,0},{0,-1,2,-1,0},{0,0,-1,2,-1},{0,0,0,-1,2}};
        double b[]={1,2,3,2,1};
        int size=5;
        GS myGs=new GS();
        myGs.init(a,b,size);
        myGs.solve();
        myGs.printArray('A');
        myGs.printArray('B');
        myGs.printArray('X');
    }*/
}
