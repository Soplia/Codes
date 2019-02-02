package com.jinan.LSM;
//在使用的时候直接调用inputP，来输入数组内容，数组大小，要进行那种方式拟合的标志这三个参数。
//然后再调用solve，自动进行计算。
//最后调用outputR函数进行结果的输出。
//这三个是接口
public class LSM 
{
    public double X[];//存放输入的x坐标
    public double Y[];//存放输入的y坐标
    public double a0,a1,a2;//存放拟合曲线的系数
    public double a,b,c,d,e,f,g,h,j;//存放第一个方阵的数值
    public double r,s,t;//存放第二个方阵的数值
    public int sizeA;//存放数组的实际大小
    public boolean flag;//进行标示；如果是false就代表进行线性拟合、如果是true就进行曲线拟合
    public void LSM()
    {
        //进行初始化
        a0=a1=a2=0;
        a=b=c=d=e=f=g=h=j=0;
        r=s=t=0;
    }
    //用于清空变量的数值
    public void myClear()
    {
        sizeA=0;
        a0=a1=a2=0;
        a=b=c=d=e=f=g=h=j=0;
        r=s=t=0;
    }
    //用于调试程序
    public void outputX_Y()
    {
        for(int i=0;i<sizeA;i++)
            System.out.println("("+X[i]+","+Y[i]+")");
    }
    //给数组进行赋值
    public void inputP(double x[],double y[],int s,boolean f)
    {
        X=new double[100];
        Y=new double[100];
        setSizeA(s);
        setFlag(f);
        for(int i=0;i<sizeA;i++)
        {   
            X[i]=x[i];
            Y[i]=y[i];
        }
    }
    //输出结果
    public void outputR()
    {
        System.out.println("Y="+a0+" X0 "+a1+" X1 "+a2+" X2 ");
    }
    //从此向下都是线性拟合的函数L
    public void setLA()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=1;
        this.a=sum;
    }
    public void setLBC()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i];
        this.b=this.c=sum;
    }
    public void setLD()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i]*X[i];
        d=sum;
    }
    public void setLG()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=Y[i];
        g=sum;
    }
    public void setLH()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=Y[i]*X[i];
        h=sum;
    }
    public void setLA0()
    {
        a0=(g-b*a1)/a;
    }
    public void setLA1()
    {
        a1=(g*c-a*h)/(b*c-a*d);
    }
    public void solveL()
    {
        setLA();
        setLBC();
        setLD();
        setLG();
        setLH();
        setLA1();
        setLA0();
    }
    //从此向下都是进行二次拟合的函数S
    public void setSA()
    {
       double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=1;
        this.a=sum; 
    }
    public void setSBD()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i];
        this.b=this.d=sum;
    }
    public void setSCEG()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i]*X[i];
        this.c=this.e=this.g=sum;
    }
    public void setSFH()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i]*X[i]*X[i];
        this.f=this.h=sum;
    }
    public void setSJ()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=X[i]*X[i]*X[i]*X[i];
        this.j=sum;
    }
    public void setSR()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=Y[i];
        r=sum;
    }
    public void setSS()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=Y[i]*X[i];
        s=sum;
    }
    public void setST()
    {
        double sum=0;
        for(int i=0;i<sizeA;i++)
            sum+=Y[i]*X[i]*X[i];
        t=sum;
    }
    public void setSA0()
    {
        a0=(r-b*a1-c*a2)/a;
    }
    public void setSA1()
    {
        a1=(s-r*d/a-(f-c*d/a)*a2)/(e-d*b/a);
    }
    public void setSA2()
    {
        //a2=(  (s-r*d/a)*(h-g*h/a)-(e-d*b/a)*(t-g*r/a)  )/(  (f-r*d/a)*(h-g*h/a)-(e-d*b/a)*(j-g*c/a)  );
        a2=( ((t*d-s*g)*(e*a-b*d)-(s*a-r*d)*(h*d-e*g))/( (j*d-f*g)*(e*a-b*d)-(f*a-c*d)*(h*d-e*g) ) );
    }
    public void solveS()
    {
        setSA();
        setSBD();
        setSCEG();
        setSFH();
        setSJ();
        setSR();
        setSS();
        setST();
        setSA2();
        setSA1();
        setSA0();
    }
    //总的调用方法
    public void solve()
    {
        if(!flag)
            solveL();
        else
            solveS();
    }
    //进行信息的交互
   public void setSizeA(int a)
   {
       sizeA=a;
   }
   public void setFlag(boolean f)
   {
       flag=f;
   }
   //用于调试，输出中间结果
   public void outputRST()
   {
       System.out.println("a="+a+",b="+b+",c="+c+",d="+d+",e="+e+",f="+f+",g="+g+",h="+h+",j="+j);
   }
   /*
   public static void main(String args[])
   {
        LSM myLsm=new LSM();
        double x[]={34,36,37,38,39,39,39,40,40,41,42,43,43,45,47,48};
        double y[]={1.3,1,0.73,0.9,0.81,0.7,0.6,0.5,0.44,0.56,0.3,0.42,0.35,0.4,0.41,0.6};
        //double x[]={1.9,2.1,2.7,3.5,4.0,4.5,5.0,5.2,6.0,6.3};
        //double y[]={1.4,1.8,2.8,3.0,4.0,4.2,5.5,5.0,5.5,6.4};
        myLsm.inputP(x, y, 16, true);
        //myLsm.outputX_Y();
        myLsm.solve();
       // myLsm.outputRST();
        myLsm.outputR();
   }
    */
}
