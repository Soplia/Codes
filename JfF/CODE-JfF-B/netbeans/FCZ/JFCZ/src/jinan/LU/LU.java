package jinan.LU;
public class LU 
{
    public double A[][];
    public double L[][];
    public double U[][];
    public double Y[];
    public double X[];
    public double B[];
    public int size;
    //进行数组初始化
    public void totalInit(double a[][],double b[],int size)
    {
        init(a,b,size);
        initL();
        initU();
    }
    //进行LU分解
    public void setLU()
    {
        for(int row=2;row<size;row++)
        {
            //填U
            for(int col=row;col<size;col++)
                U[row][col]=getU(row,col);
            //填L
            for(int col=row;col<size;col++)
                if(col>row)
                    L[col][row]=getL(col,row);
        }
    }
    //计算XY
    public void setXY()
    {
        setY();
        setX();
    }
    public void solve()
    {
        setLU();
        setXY();
    }
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
        L=new double[this.size][this.size];
        U=new double[this.size][this.size];
        for(int i=1;i<this.size;i++)
            for(int j=1;j<this.size;j++)
            {
                L[i][j]=0;
                U[i][j]=0;
            }
        Y=new double [this.size];
        X=new double [this.size];
        for(int i=1;i<this.size;i++)
            Y[i]=X[i]=0;
    }
    //初始化L
    public void initL()
    {
        for(int i=1;i<size;i++)
            for(int j=1;j<size;j++)
            {
                if(i==j)
                    L[i][j]=1;
                if(j==1)
                    L[i][j]=A[i][j]/A[1][1];
            }
    }
    //初始化U
    public void initU()
    {
        for(int i=1;i<this.size;i++)
            U[1][i]=A[1][i];
    }
    //求解L时用到的Σ
    public double L_addLU(int row,int col)
    {
        double sum=0;
        for(int k=1;k<=col-1;k++)
             sum+=L[row][k]*U[k][col];
        return sum;
    }
    ////求解U时用到的Σ
    public double U_addLU(int row,int col)
    {
        double sum=0;
        for(int k=1;k<=row-1;k++)
            sum+=L[row][k]*U[k][col];
        return sum;
    }
    //求解L时的标准公式
    public double getL(int row,int col)
    {
        return (A[row][col]-L_addLU(row,col))/U[col][col];
    }
    //求解U时的标准公式
    public double getU(int row,int col)
    {
        return A[row][col]-U_addLU(row,col);
    } 
    //利用B和L求得Y
    public double getLB(int row)
    {
        double sum=0;
        for(int i=1;i<row;i++)
            sum+=Y[i]*L[row][i];
        return sum;
    }
    //利用U和Y求得X
    public double getUY(int row)
    {
        double sum=0;
        for(int i=row+1;i<size;i++)
            sum+=X[i]*U[row][i];
        return sum;
    }
    //求解Y
    public void setY()
    {
        Y[1]=B[1];
        for(int i=2;i<size;i++)
            Y[i]=(B[i]-getLB(i))/L[i][i];
    }
    //求解X
    public void setX()
    {
        X[size-1]=Y[size-1]/U[size-1][size-1];
        for(int i=size-2;i>=1;i--)
            X[i]=(Y[i]-getUY(i))/U[i][i];
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
            case'U':
            {
                for(int i=1;i<size;i++)
                {
                    for(int j=1;j<size;j++)
                        System.out.print(U[i][j]+"   ");
                    System.out.println();
                } 
            };break;
            case'L':
           {
                for(int i=1;i<size;i++)
                {
                    for(int j=1;j<size;j++)
                        System.out.print(L[i][j]+"   ");
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
   /*
    public static void main(String args[])
    {
        double a[][]={{2,-1,0,0,0},{-1,2,-1,0,0},{0,-1,2,-1,0},{0,0,-1,2,-1},{0,0,0,-1,2}};
        double b[]={1,2,3,2,1};
        int size=5;
        LU myLu=new LU();
        myLu.totalInit(a, b, size);
        myLu.setLU();
        myLu.setXY();
        myLu.printArray('L');
        System.out.println();
        myLu.printArray('U');
        System.out.println();
        myLu.printArray('Y');
        System.out.println();
        myLu.printArray('X');
        System.out.println();
    }
    */
}
