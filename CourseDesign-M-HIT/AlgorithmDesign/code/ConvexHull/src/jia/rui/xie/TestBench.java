package jia.rui.xie;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Date;
import java.util.List;

public class TestBench extends javax.swing.JFrame
{
	private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JPanel jPanel1;
    Graphics g=null;//ȫ�ֱ���
    List<Point> point=null;
    List<Line> lineEnum=null;
    List<Line> lineGra=null;
    List<Line> lineDc=null;
    
    Tool tool = null;
    int scope= 400;
	int number=1000;
	
	TestBench()
	{
		initComponents();
		//��ֹ���ڱ���ק�ı��С
		this.setResizable(false);
	}
	
    private void initComponents() 
    {
        jPanel1 = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 340, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 450, Short.MAX_VALUE)
        );

        jButton1.setText("Enum");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("DrawPoint");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("Graham");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("DC");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 99, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 99, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 99, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, 99, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton4)))
        );

        pack();
    }// </editor-fold>                        
   
    //CreatePoint
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) 
    {  
        DrawPoint();
    }
    //Enum
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) 
    {     
    	DrawLineEnum();
    }
    //Graham
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) 
    {                                         
    	DrawLineGra();
    }                                        
    //DC
    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) 
    {                                         
    	DrawLineDc();
    } 
    
    public void DrawPoint()
	{
		g=jPanel1.getGraphics();
		if(g==null)
		{
			System.out.println("g = NULL");
		}
		else
		{
			tool =new Tool();
			/*
			 * �����������1000-20000������м�������Ҫ��ʱ��
			for(int k=1;k<=20;k++)
			{
				point= new Tool().GrenatePointSet(scope, number*k);
				Date dt1= new Date();
				Long time1= dt1.getTime();
				line= new ConvexHullEnum().ConvexHullEnumSlove(point);
				Date dt2= new Date();
				Long time2= dt2.getTime();
				System.out.println("Number of point is:"+(number*k)+" ,The Clapse time is:"+(time2-time1)+"ms");
			}
			*/
			
			//�������
			point= tool.GrenatePointSet(scope, number);
			for(int i=0;i<point.size();i++)
				g.drawOval((int)point.get(i).x,(int)point.get(i).y,4,4);
			
			
			Date dt1= new Date();
			Long time1= dt1.getTime();
			lineEnum= new ConvexHullEnum().ConvexHullEnumSlove(point);
			Date dt2= new Date();
			Long time2= dt2.getTime();
			System.out.println("Number of point is:"+number+" ,The Clapse time of Enum is:"+(time2-time1)+"ms");
			
			//Graham ��͹��
			//point= tool.GrenatePointSet(scope, number);
			//��õ������
			Point arr[]=tool.PointListToArray(point);
			Point res[]=new Point[point.size()];
			
			Date dt3= new Date();
			Long time3= dt3.getTime();
			int numOfPoint= new ConvexHullGraham().ConvexHull(arr,point.size(),res);
			Date dt4= new Date();
			Long time4= dt4.getTime();
			System.out.println("Number of point is:"+number+" ,The Clapse time of Graham is:"+(time4-time3)+"ms");
			
			lineGra=tool.PointArrToLineList(res, numOfPoint);
			//for(int i=0;i<point.size();i++)
				//g.drawOval((int)point.get(i).x,(int)point.get(i).y,4,4);
			
			/*
			 * Graham ��͹�� ѭ��20��
			for(int k=1;k<=20;k++)
			{
				
				point= tool.GrenatePointSet(scope, number*k);
				//��õ������
				Point arr[]=tool.PointListToArray(point);
				Point res[]=new Point[point.size()];
				
				Date dt1= new Date();
				Long time1= dt1.getTime();
				
				int numOfPoint= new ConvexHullGraham().ConvexHull(arr,point.size(),res);
				line=tool.PointArrToLineList(res, numOfPoint);
				
				Date dt2= new Date();
				Long time2= dt2.getTime();
				
				System.out.println("Number of point is:"+(number*k)+" ,The Clapse time is:"+(time2-time1)+"ms");
			}
			*/
			
			///*
			// * ���� -ʵ��
			//point= tool.GrenatePointSet(scope, number);
			Date dt5= new Date();
			Long time5= dt5.getTime();
			
			lineDc= new ConvexHullDC().GetConvexHull(point);
			
			Date dt6= new Date();
			Long time6= dt6.getTime();
			
			System.out.println("Number of point is:"+number+" ,The Clapse time of DC is:"+(time6-time5)+"ms");
			//for(int i=0;i<point.size();i++)
				//g.drawOval((int)point.get(i).x,(int)point.get(i).y,4,4);
			//*/
			
			/*
			 * �����������1000-20000������м�������Ҫ��ʱ��
			for(int k=1;k<=20;k++)
			{
				point= new Tool().GrenatePointSet(scope, number*k);
				Date dt1= new Date();
				Long time1= dt1.getTime();
				line= new ConvexHullDC().go(point);
				Date dt2= new Date();
				Long time2= dt2.getTime();
				System.out.println("Number of point is:"+(number*k)+" ,The Clapse time is:"+(time2-time1)+"ms");
			}
			*/
			
		}
	}
	
	public void DrawLineEnum()
	{
		g=jPanel1.getGraphics();
		g.setColor(Color.red);
		
		if(g==null)
		{
			System.out.println("g = NULL");
		}
		else
		{
			for(int i=0;i<lineEnum.size();i++)
			{
				Line temp=lineEnum.get(i);
				Point s=temp.head;
				Point t=temp.tail;
				
				//�����еı߽��ϵ�Բ��Ϳ�ɺ�ɫ
				g.fillOval((int)s.x,(int)s.y,4,4);
				g.fillOval((int)t.x,(int)t.y,4,4);
				//����������Բ�ĵ�
				g.drawLine((int)s.x,(int)s.y,(int)t.x,(int)t.y);
			}
		}
	}
	
	public void DrawLineGra()
	{
		g=jPanel1.getGraphics();
		g.setColor(Color.green);
		
		if(g==null)
		{
			System.out.println("g = NULL");
		}
		else
		{
			for(int i=0;i<lineGra.size();i++)
			{
				Line temp=lineGra.get(i);
				Point s=temp.head;
				Point t=temp.tail;
				
				//�����еı߽��ϵ�Բ��Ϳ�ɺ�ɫ
				g.fillOval((int)s.x,(int)s.y,4,4);
				g.fillOval((int)t.x,(int)t.y,4,4);
				//����������Բ�ĵ�
				g.drawLine((int)s.x,(int)s.y,(int)t.x,(int)t.y);
			}
		}
	}

	public void DrawLineDc()
	{
		g=jPanel1.getGraphics();
		g.setColor(Color.blue);
		
		if(g==null)
		{
			System.out.println("g = NULL");
		}
		else
		{
			for(int i=0;i<lineDc.size();i++)
			{
				Line temp=lineDc.get(i);
				Point s=temp.head;
				Point t=temp.tail;
				
				//�����еı߽��ϵ�Բ��Ϳ�ɺ�ɫ
				g.fillOval((int)s.x,(int)s.y,4,4);
				g.fillOval((int)t.x,(int)t.y,4,4);
				//����������Բ�ĵ�
				g.drawLine((int)s.x,(int)s.y,(int)t.x,(int)t.y);
			}
		}
	}
	
	public static void main(String args[])
	{
		new TestBench().setVisible(true);
	}
}

