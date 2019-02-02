package com.jinan.paint;
import com.jinan.LSM.*;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Toolkit;
public class Paint extends javax.swing.JFrame 
{
    public LSM myLsm;
    public double x[],y[];
    int size;
    boolean flag;
    //获取屏幕大小
    public int screenHeight;
    public int screenWidth;
    //信息初始化
    public void init()
    {
        myLsm=new LSM();
        x=new double [100];
        y=new double [100];
        size=0;
        //调用那种拟合的标志
        flag=false;
        Toolkit kit=Toolkit.getDefaultToolkit();
        Dimension screenSize=kit.getScreenSize();
        screenHeight = screenSize.height;
        screenWidth = screenSize.width;
    }
    public Paint() 
    {
        initComponents();
        init();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenu2 = new javax.swing.JMenu();
        jMenu3 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                formMousePressed(evt);
            }
        });

        jMenu1.setText("File");
        jMenuBar1.add(jMenu1);

        jMenu2.setText("Edit");
        jMenuBar1.add(jMenu2);

        jMenu3.setText("LSM");

        jMenuItem1.setText("single");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu3.add(jMenuItem1);

        jMenuItem2.setText("square");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu3.add(jMenuItem2);

        jMenuBar1.add(jMenu3);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 279, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
//鼠标相应事件用于画点
    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        Graphics g=this.getGraphics();
        x[size]=(double)evt.getX();
        y[size++]=(double)evt.getY();
        g.fillRect(evt.getX(), evt.getY(), 4, 4);
        //System.out.println("("+evt.getX()+","+evt.getY()+")");
    }//GEN-LAST:event_formMousePressed
//一次拟合相应事件
    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        flag=false;
        myLsm.inputP(x,y,size,flag);
        Graphics g=this.getGraphics();
        myLsm.solve();
        myLsm.outputR();
        //x=10时和x=screen-10时 进行画线
        g.drawLine(10,(int)(myLsm.a0+myLsm.a1*10),screenWidth-10,(int)(myLsm.a0+myLsm.a1*(screenWidth-10)));
    }//GEN-LAST:event_jMenuItem1ActionPerformed
//二次拟合相应事件
    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
       Graphics g=this.getGraphics();
       flag=true;
       myLsm.inputP(x, y, size, flag);
       myLsm.solve();
       myLsm.outputR();
       //记录需要用作画折线的数据点
       int xx[],yy[];
       xx=new int[screenWidth];
       yy=new int[screenWidth];
       //记录数据点数
       int s=0;
       for(int i=0;i<screenWidth;i+=10)
       {
           xx[s]=i;
           //
           //这是我第一次遇到的问题，=74.13134022962373 X0 0.9985165397294532 X1 -0.011054003593372577 X2。
           //这个问题就类似与课件上的那个题，解题思路、解答过程都对但是就是有错误。这个错误是精度引起的。
           //在使用它进行计算的时候需要先把直线的系数进行强制类型转换，然后再进行画图。
           //
           yy[s++]=((int)myLsm.a0+(int)(myLsm.a1*xx[s-1])+(int)(myLsm.a2*xx[s-1]*xx[s-1]));
           //yy[s++]=((int)myLsm.a0+(int)myLsm.a1*xx[s-1]+(int)myLsm.a2*xx[s-1]*xx[s-1]);
       }
       g.drawPolyline(xx, yy, s);
    }//GEN-LAST:event_jMenuItem2ActionPerformed

    public static void main(String args[]) 
    {
       Paint myPaint=new Paint();
       myPaint.setVisible(true);
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    // End of variables declaration//GEN-END:variables
}
