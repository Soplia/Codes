package xiejiarui;
//����robocode�����������
import robocode.*;
import java.awt.Color;
public class LiuSha extends AdvancedRobot
{
	//Enemy���ǵл���.
    Enemy enemy; 
    //����
    final double PI=Math.PI; 
    //̹��ǰ������
    int direction=1; 
    //�ӵ�������
    double fireOfPower; 
    public void run() 
    {
        enemy=new Enemy(); 
        //��ʼ����л��ľ��룬�Դ���Ѱ�ҵл���
        enemy.distance=1000;
        //����̹�˵���ɫ
        setColors(Color.blue,Color.green,Color.red); 
        setAdjustGunForRobotTurn(true);
        setAdjustRadarForGunTurn(true);
        //��̹����ת360�ȣ���Ѱ�ҵл���
        turnRadarRightRadians(2*Math.PI);  
        while(true)
        {
        	//�������ƶ�
            move();               
            //�����ӵ�������
            setFirePower();          
            //����ɨ��
            setRadar();                
            //Ԥ�����
            setGun();  
            //̹�˿���
            setFire(fireOfPower);
            //�����������ִ��
            execute();
        }
    }
    //�����ӵ�������
    void setFirePower() 
    {
    	//���ݵл������ҵ�Զ���������ӵ���������
        fireOfPower=300/enemy.distance;
    }
   //�������ƶ��ķ�����
    void move() 
    {
    	//ÿ��25���ӱ仯һ�η���
        if (getTime()%25==0)  
        {
            direction*=-1;       
            setAhead(direction*300);    
        }
         //ÿһʱ�������Ե���Ϊ������Բ�˶�
        setTurnRightRadians(enemy.bearing + (PI/2)); 
    }
    
    void setRadar() 
    {
    	double radarOffset;  //�״�ƫ����
    	//ɨ���ʱ�䳤���ĸ���λ����������ɨ��һ�Ρ�
        if (getTime()-enemy.ctime>4) 
        {
            radarOffset=360;      
        } 
        else 
        {
            //ͨ��ɨ������״���ת�Ļ��ȣ��״ﻡ��-���˽Ƕȵõ��������Ϊ��תֵ
            radarOffset=getRadarHeadingRadians()-getEnemyDirection(getX(),getY(),enemy.x,enemy.y)-0.2;
            //�ڵõ��ĽǶ��мӻ��һ��Ƕȣ����״��С�ķ�Χ�ڰڶ���ʧȥĿ��
            if (radarOffset<0)
            	radarOffset-=PI/8;
            else
            	radarOffset+=PI/8; 
        }
        //��ת�״�
        setTurnRadarLeftRadians(standardBearing(radarOffset)); 
    }
    
    void setGun() 
    {
        long time = getTime()+(int)(enemy.distance/(20-(3*fireOfPower)));
        //��ֱ��ΪĿ�꣬ƫ���ӵ���һ�η���ĽǶȡ�
        double gunOffset = getGunHeadingRadians()-getEnemyDirection(getX(),getY(),enemy.getNextX(time),enemy.getNextY(time));
        setTurnGunLeftRadians(standardBearing(gunOffset));  //������ԽǶȵ�2PI��
    }
    double standardBearing(double a) 
    {
        if(a>PI)
        	a-=2*PI;
        if(a<-PI)
        	a+=2*PI;
        return a;
    }
   
    //�����߳���������֮��ľ���
    public double getLoop(double x1,double y1, double x2,double y2)
    {
        double xo=x2-x1;
        double yo=y2-y1;
        double h=Math.sqrt(xo*xo+yo*yo); 
        return h;   
    }
    //����x,y������������ԽǶ�
    public double getEnemyDirection(double x1,double y1, double x2,double y2)
    {
        double x0=x2-x1;
        double y0=y2-y1;
        double h=getLoop(x1,y1,x2,y2);
        if(x0>0&&y0>0)
        {
            //�����Ҷ��壬�Ա߳�б�ߵû���.��robocode�еľ��Է���ϵ������ϵ����
            //x,yΪ�����Ͻ�Ϊ0-90,x��y�����½�Ϊ90-180,x,y�����½�180-270,x����y�����Ͻ�270-360
            //�˴�Ҫ���robocode�еľ��ԽǶ�����Ϊ0,��Ϊ180����������Ϊ�㻮��������õ�����Ľ��
            return Math.asin(x0/h);
        }
        if(x0>0&&y0<0)
        {
            return Math.PI-Math.asin(x0/h); //xΪ��,yΪ���ڶ����޽�
        }
        if(x0<0&&y0<0)
        {
            return Math.PI+Math.asin(-x0/h); //����������180+�Ƕ�
        }
        if(x0<0&&y0>0)
        {
            return 2.0*Math.PI-Math.asin(-x0/h); //������360-�Ƕ�
        }
        return 0;
    }
    public void onScannedRobot(ScannedRobotEvent e) 
    {	
        if ((e.getDistance()<enemy.distance)||(enemy.name==e.getName())) 
        {
           //��ö��ֵľ��Ի���
            double ang=(getHeadingRadians()+e.getBearingRadians())%(2*PI);
            enemy.name=e.getName();
            //��ö��ֵ�x,y����
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
            //��ɨ��ʱ���ӵ������ʱ��� �� ����ٶ�=����, ���ö��ֵ���������ƶ�����õ������ƶ��������
            long diff = when-ctime;
            return x+Math.sin(head)*speed*diff; //Ŀ���ƶ��������
        }
        public double getNextY(long when)
        {
            long diff=when-ctime;
            return y+Math.cos(head)*speed*diff;
        }
    }
}


