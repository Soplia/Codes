package xiejiarui;
//导入robocode编程所需的类库
import robocode.*;
import java.awt.Color;
public class LiuSha extends AdvancedRobot
{
	//Enemy类是敌机类.
    Enemy enemy; 
    //常量
    final double PI=Math.PI; 
    //坦克前进方向
    int direction=1; 
    //子弹的能量
    double fireOfPower; 
    public void run() 
    {
        enemy=new Enemy(); 
        //初始化与敌机的距离，以此来寻找敌机。
        enemy.distance=1000;
        //设置坦克的颜色
        setColors(Color.blue,Color.green,Color.red); 
        setAdjustGunForRobotTurn(true);
        setAdjustRadarForGunTurn(true);
        //让坦克旋转360度，来寻找敌机。
        turnRadarRightRadians(2*Math.PI);  
        while(true)
        {
        	//机器人移动
            move();               
            //设置子弹的能量
            setFirePower();          
            //进行扫描
            setRadar();                
            //预测敌人
            setGun();  
            //坦克开火
            setFire(fireOfPower);
            //与后续程序并行执行
            execute();
        }
    }
    //设置子弹的能量
    void setFirePower() 
    {
    	//根据敌机距离我的远近来设置子弹的能量。
        fireOfPower=300/enemy.distance;
    }
   //机器人移动的方法。
    void move() 
    {
    	//每隔25秒钟变化一次方向。
        if (getTime()%25==0)  
        {
            direction*=-1;       
            setAhead(direction*300);    
        }
         //每一时间周期以敌人为中心绕圆运动
        setTurnRightRadians(enemy.bearing + (PI/2)); 
    }
    
    void setRadar() 
    {
    	double radarOffset;  //雷达偏移量
    	//扫描的时间长于四个单位，则再重新扫描一次。
        if (getTime()-enemy.ctime>4) 
        {
            radarOffset=360;      
        } 
        else 
        {
            //通过扫描决定雷达旋转的弧度，雷达弧度-敌人角度得到两者相差为旋转值
            radarOffset=getRadarHeadingRadians()-getEnemyDirection(getX(),getY(),enemy.x,enemy.y)-0.2;
            //在得到的角度中加或减一点角度，让雷达很小的范围内摆而不失去目标
            if (radarOffset<0)
            	radarOffset-=PI/8;
            else
            	radarOffset+=PI/8; 
        }
        //旋转雷达
        setTurnRadarLeftRadians(standardBearing(radarOffset)); 
    }
    
    void setGun() 
    {
        long time = getTime()+(int)(enemy.distance/(20-(3*fireOfPower)));
        //以直线为目标，偏移子弹下一次发射的角度。
        double gunOffset = getGunHeadingRadians()-getEnemyDirection(getX(),getY(),enemy.getNextX(time),enemy.getNextY(time));
        setTurnGunLeftRadians(standardBearing(gunOffset));  //调整相对角度到2PI内
    }
    double standardBearing(double a) 
    {
        if(a>PI)
        	a-=2*PI;
        if(a<-PI)
        	a+=2*PI;
        return a;
    }
   
    //以两边长求得与对手之间的距离
    public double getLoop(double x1,double y1, double x2,double y2)
    {
        double xo=x2-x1;
        double yo=y2-y1;
        double h=Math.sqrt(xo*xo+yo*yo); 
        return h;   
    }
    //根据x,y的坐标求出绝对角度
    public double getEnemyDirection(double x1,double y1, double x2,double y2)
    {
        double x0=x2-x1;
        double y0=y2-y1;
        double h=getLoop(x1,y1,x2,y2);
        if(x0>0&&y0>0)
        {
            //反正弦定义，对边除斜边得弧度.以robocode中的绝对方向系及坐标系参照
            //x,y为正右上角为0-90,x正y负右下角为90-180,x,y负左下角180-270,x负，y正右上角270-360
            //此处要理解robocode中的绝对角度是上为0,下为180，如以中心为点划分象限则得到下面的结果
            return Math.asin(x0/h);
        }
        if(x0>0&&y0<0)
        {
            return Math.PI-Math.asin(x0/h); //x为正,y为负第二象限角
        }
        if(x0<0&&y0<0)
        {
            return Math.PI+Math.asin(-x0/h); //第三象限内180+角度
        }
        if(x0<0&&y0>0)
        {
            return 2.0*Math.PI-Math.asin(-x0/h); //四象限360-角度
        }
        return 0;
    }
    public void onScannedRobot(ScannedRobotEvent e) 
    {	
        if ((e.getDistance()<enemy.distance)||(enemy.name==e.getName())) 
        {
           //求得对手的绝对弧度
            double ang=(getHeadingRadians()+e.getBearingRadians())%(2*PI);
            enemy.name=e.getName();
            //求得对手的x,y坐标
            enemy.x=getX()+Math.sin(ang)*e.getDistance(); 
            enemy.y=getY()+Math.cos(ang)*e.getDistance(); 
            enemy.bearing=e.getBearingRadians();
            enemy.head=e.getHeadingRadians();
            enemy.ctime=getTime();              
            enemy.speed=e.getVelocity();       
            enemy.distance=e.getDistance();
        }
    }
    public void onRobotDeath(RobotDeathEvent e) 
    {
       if (e.getName()==enemy.name)
        enemy.distance=1000; 
    }   
    class Enemy 
    {
        String name;
        public double bearing;
        public double head;
        public long ctime; 
        public double speed;
        public double x,y;
        public double distance;     
        public double getNextX(long when)
        {
            //以扫描时和子弹到达的时间差 ＊ 最大速度=距离, 再用对手的坐标加上移动坐标得到敌人移动后的坐标
            long diff = when-ctime;
            return x+Math.sin(head)*speed*diff; //目标移动后的坐标
        }
        public double getNextY(long when)
        {
            long diff=when-ctime;
            return y+Math.cos(head)*speed*diff;
        }
    }
}


