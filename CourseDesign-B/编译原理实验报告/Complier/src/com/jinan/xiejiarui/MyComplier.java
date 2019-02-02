package com.jinan.xiejiarui;
import javax.swing.JFileChooser;
import java.io.*;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
//创建一个链表类，用于存放字符串的 值——属性 对。
class List
{
    public String value;
    public String type;
    List next;
    public List()
    {
        this.value="";
        this.type="";
        this.next=null;
    }
    public List(String a,String b)
    {
        this.value=a;
        this.type=b;
        this.next=null;
    }
}
public class MyComplier extends javax.swing.JFrame 
{
    //设置两个字符串一个是简单的字符串一个是复杂的字符串
    //复杂的字符串用于接受来自文件的字符，然后把它传递给预处理程序，进行处理。
    //预处理程序把处理后的字符串传给简单的字符串，然后再由词法分析器去处理。
    String strS="";
    String strT="";
    //创建一个链表头
    List head=null;
    //返回一个字符的类型
    public String getCharType(char c)
    {
        //将char型转化成string类型，便于后续使用equals函数。
        String temp=String.valueOf(c);
        //正则表达式
        String second="[+\\-*/()=]";
        String third="[0-9]";
        String forth="[a-zA-Z_]";
        if(temp.equals(";"))
            return "1";//代表这是一个界符
        else if(temp.matches(second))
            return "2";//代表这是一个算符
        else if(temp.matches(third))
            return "3";//代表这是一个数字
        else if(temp.matches(forth))
            return "4";//代表这是一个字母
        //添加一个空格的识别类型（类似于算符和界符），就是把它也放到识别的行列中但是在显示的时候不把它显示出来
        else if(temp.equals(" "))
            return "6";
        else 
            return "5";//代表这是一个错误字符
    }
    //看当前两种类型str1和str2是否匹配
    public boolean isMatch(String str1,String str2)
    {
        boolean flag=false;
        switch(str1)
        {
            //如果是一二五六种情况，因为他们都是包含一个字符的所以应该立即返回false；
            case "1":
            case "2":
            case "5":
            case "6":break;
            //对于第二种情况，如果它的后面还是数字，则是同一种字符
            case "3":
            {
                if(str2.equals("3")) 
                    flag=true;
            };break;
            //对于第四种情况如果它的后面还是三四种情况，那么它们是同一种情况。
            case "4":
            {
                if(str2.equals("3")||str2.equals("4"))
                    flag=true;
            };break;
        }
        return flag;
    }
    public MyComplier() 
    {
        initComponents();
    }
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jScrollPane3 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTextArea2 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setFont(new java.awt.Font("宋体", 1, 18)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 102, 102));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("词法分析器");

        jButton1.setText("打开文件");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("词法分析");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("保存文件");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("预处理");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        jLabel2.setText("文件原始内容");

        jLabel3.setText("预处理之后的内容");

        jLabel4.setText("分析后的内容");

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "字符", "类型"
            }
        ));
        jScrollPane3.setViewportView(jTable1);

        jTextArea2.setColumns(20);
        jTextArea2.setRows(5);
        jScrollPane2.setViewportView(jTextArea2);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jButton1)
                                    .addComponent(jLabel2))
                                .addGap(18, 18, 18)
                                .addComponent(jButton4)
                                .addGap(18, 18, 18)
                                .addComponent(jButton2))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(117, 117, 117)
                                .addComponent(jLabel1)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(18, 18, 18)
                                .addComponent(jButton3))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(5, 5, 5)
                                .addComponent(jLabel4))))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(21, 21, 21)
                                .addComponent(jLabel3)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addComponent(jScrollPane1)
                            .addComponent(jScrollPane2))
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton4))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 232, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel3)
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 119, Short.MAX_VALUE))
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    //根据方法的形式参数数值以及类型构造节点并且将节点插入到链表中
    public void insertIntoList(String temp,String type1)
    {
        List t=new List(temp,type1);
        if(head==null)//不知道这个地方可不可以,毕竟不同于指针
            head=t;
        else
        {
            List th=head;
            while(th.next!=null)
                th=th.next;
            th.next=t;
        }
    }
    //仅仅是一个字符的转化
    public String typeConvert(String a)
    {
        if(a.equals("1"))
            return "界符";
        else if(a.equals("2"))
            return "算符";
        else if(a.equals("3"))
            return "常数";
        else if(a.equals("4"))
            return "变量";
        else
            return "错误";
    }
    //词法分析按钮
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed

        //初始化表格需要的内容
        DefaultTableModel firstModel=new DefaultTableModel();
        String data[][]=new String[100][2];
        String nameOfHead[]={"字符","类型"};
        //先把表格清空.
        jTable1.setModel(firstModel);
        //当前指针指示的位置,用于标识是否匹配到该字符串的末尾，即标识什么时候结束.
        int startPos=1;
        //记录截取字符串的开始位置
        int tempStartPos=0;
        //设置偏移量，由它及tempStartPos来获得截取单词的结束位置。
        int offset=0;
        //开始第一个字符的类型，以后进行类型匹配，都是与第一个字符的类型进行匹配，存储类型的时候也是存储第一个字符的类型.
        String type1="";
        //指针当前指向的字符的类型.
        String type2="";
        //strS.trim();
        while(startPos<strS.length())
        {
            //System.out.println("strS="+strS);
            //每次开始offset都清空。
            offset=0;
            //因为是从1开始计数，所以offset立即加1.
            offset++;
            //这里的位置是从0开始的.
            tempStartPos=startPos;
            type1=getCharType(strS.charAt(startPos));
            //System.out.println("type1="+type1);
            //如果遇到了错误,就截取字符，并且结束循环。
            if(type1.equals("5"))
            {
                //截取字符串，并且将字符串放到链表中.
                String temp=strS.substring(tempStartPos,tempStartPos+offset);
                //System.out.println("*"+temp+"*");
                insertIntoList(temp,type1);
                break;
            }
            //如果没有遇到错误，就继续进行匹配，直到遇到不和第一个单词类型相同的字符
            else
            {
                while(true)
                {
                    //指针前移
                    startPos++;
                    //如果指针没有到达尾部就继续进行判断
                    if(startPos<strS.length())
                    {
                        type2=getCharType(strS.charAt(startPos));
                        //System.out.println("type2="+type2);
                        //如果类型相同则偏移量++
                        if(isMatch(type1,type2))
                            offset++;
                        //如果不同，进行截取，并且插入链表同时结束当前循环.
                        //回到起点处，由次来判断是否遇到了错误的单词。
                        else
                        {
                            //截取字符串，并且将字符串放到链表中.
                            String temp=strS.substring(tempStartPos,tempStartPos+offset);
                            //System.out.println("*"+temp+"*");
                            //如果不是空格就把这个字符插入到链表中
                            if(!temp.equals(" "))
                                insertIntoList(temp,type1);
                            break;
                        }     
                    }
                    else//如果到达末尾就把当前的字符串截取出来
                    {
                        //截取字符串，并且将字符串放到链表中.
                        String temp=strS.substring(tempStartPos,tempStartPos+offset);
                        //System.out.println("*"+temp+"*");
                        //如果不是空格就把这个字符插入到链表中
                        if(!temp.equals(" "))
                             insertIntoList(temp,type1);
                        break;
                    }
                }
            }
        }//结束while
        //将内容显示到表格中
        if(head!=null)
        {
            int i=0;
            List temp=head;
            while(temp!=null)
            {
                data[i][0]=temp.value;
                //进行类型转换.
                data[i++][1]=typeConvert(temp.type);
                temp=temp.next;
            }
        }
        firstModel.setDataVector(data,nameOfHead);
        jTable1.setModel(firstModel);
        //防止再次读入的时候产生累加
        strS="";
    }//GEN-LAST:event_jButton2ActionPerformed
//进行文件打开操作.
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        try
        {
            
          JFileChooser f=new JFileChooser();
          if(f.showOpenDialog(null)==JFileChooser.APPROVE_OPTION)
          {
              
             /* FileInputStream in=new FileInputStream(f.getSelectedFile());
              byte temp[]=new byte[1000];
              in.read(temp);
              strT=new String(temp);
              jTextArea1.setText(strT);
              in.close();*/
              BufferedReader r=new BufferedReader(new FileReader(f.getSelectedFile()));
              //BufferedReader r=new BufferedReader(new FileReader(new File("abc.txt")));
              String temp="";
              temp=r.readLine();
              while(temp!=null)
              {
                  strT+=temp;
                  //在两个行之间加上一个回车符号.
                  strT+='\n';
                  temp=r.readLine();
              }
              jTextArea1.setText(strT);
              r.close();
          }
         //for(int i=0;i<strT.length();i++)
            // System.out.println(strT.charAt(i));
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }//GEN-LAST:event_jButton1ActionPerformed
//将词法分析完成的内容写到文件中。
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        try
        {
            JFileChooser f=new JFileChooser();
            if(f.showSaveDialog(null)==JFileChooser.APPROVE_OPTION)
            {
                //FileOutputStream out=new FileOutputStream(f.getSelectedFile());
                BufferedWriter wout=new BufferedWriter(new FileWriter(f.getSelectedFile()));
                //然后再把链表中数据写入到文件中
                if(head!=null)
                {
                    String t="字符    类型";
                    wout.write(t);
                    wout.newLine();
                    List temp=head;
                    while(temp!=null)
                    {
                        String str=temp.value+"      "+typeConvert(temp.type);
                        wout.write(str);
                        wout.newLine();
                        temp=temp.next;
                    }
                    wout.close();
                    JOptionPane.showMessageDialog(this,"存储文件成功!");
                }
                else
                {
                    JOptionPane.showMessageDialog(this,"内容为空无法录入!");
                }
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }//GEN-LAST:event_jButton3ActionPerformed
//进行预处理，即处理strT，让后把处理后的字符串赋值给strS
    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        //消除单行注释
        int startPos=-1,endPos=-1;
        //寻找strT中第一个//直到字符串中没有//
        while((startPos=strT.indexOf("//"))>=0)
        {
            //寻找//之后的第一个换行
            endPos=strT.indexOf('\n', startPos);
            //如果没有找打换行，就把这一句话全部删掉.
            if(endPos<0)
                endPos=strT.length();
            //截取两头的内容重新赋值给strT.
            String temp=strT.substring(0,startPos)+strT.substring(endPos,strT.length());
            strT=temp;
        }
        //消除多行注释
        startPos=endPos=-1;
        while((startPos=strT.indexOf("/*"))>=0)
        {
            //寻找/*之后的第一个*/
            endPos=strT.indexOf("*/", startPos);
            //只有在找到的情况下才能够删除内容
            if(endPos>=0)
            {   
                //截取两头的内容重新赋值给strT.
                String temp=strT.substring(0,startPos)+strT.substring(endPos+2,strT.length());
                strT=temp;
            }   
        }   
        //消除多余的空格，换行，制表等。
        strS.trim();
        for(int i=0;i<strT.length();i++)
            //使用正则表达式
            if(String.valueOf(strT.charAt(i)).matches("\\S"))
                strS+=String.valueOf(strT.charAt(i));
            else//当前是空格但是下一个不是空格，就把这个空格保留着。
                if(String.valueOf(strT.charAt(i)).equals(" ")&&!String.valueOf(strT.charAt(i+1)).equals(" "))
                    strS+=String.valueOf(strT.charAt(i));
        jTextArea2.setText(strS);
        //防止再次读入的时候产生累加
        strT="";
    }//GEN-LAST:event_jButton4ActionPerformed

    public static void main(String args[]) 
    {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MyComplier.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MyComplier.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MyComplier.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MyComplier.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
       
        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new MyComplier().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTable jTable1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextArea jTextArea2;
    // End of variables declaration//GEN-END:variables
}
