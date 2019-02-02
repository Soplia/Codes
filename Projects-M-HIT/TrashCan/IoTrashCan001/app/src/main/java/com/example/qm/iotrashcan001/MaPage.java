package com.example.qm.iotrashcan001;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class MaPage extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    /**
     * 调试部分
     */
    private static final String TAG = "MaPage";
    /**
     * Handler部分
     */
    private Handler listHandler = null;
    private Message toServerMsg = null;
    protected SocketThread socketThread =null;
    /**
     * 变量部分
     */
    private String toServerMsgStartNew = "TRASH";

    private String toServerMsgStart = "#00#0000#";
    private String toServerMsgStop = "#00#0001#";
    private String toServerMsgFresh = "#00#0010#";
    /**
     * 定时器部分
     */
    protected Timer timer = null;
    protected TimerTask task = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ma_page);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "信息立即刷新完毕", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        Fresh();
                    }
                }).start();
            }
        });

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        final ArrayList<ListItem> Items=new  ArrayList<ListItem> ();
/*

        Items.add(new ListItem("2018-2-21-8:00","箱已满,请清理"));
        Items.add(new ListItem("2018-2-22-14:00","箱已满,请清理"));
        Items.add(new ListItem("2018-2-23-9:00","箱已满,请清理"));
        Items.add(new ListItem("2018-2-24-16:00","箱已满,请清理"));
*/

        final MyCustomAdapter myadpter= new MyCustomAdapter(Items);
        ListView ls=(ListView)findViewById(R.id.listView);
        ls.setAdapter(myadpter);
        /***************************************************************************************/
        listHandler=new Handler()
        {
            @Override
            public void handleMessage(Message msg)
            {
                Log.d(TAG, "收到 服务器消息");
                /*String listMsg=new String((byte[])msg.obj);
                Log.d(TAG, "收到 服务器消息:"+listMsg);
                if(msg.what == GlobalVar.TRASHCAN_MSG)
                {
                    //获取更新信息
                    String reListMsg = listMsg.substring(1);
                    String msgArr [] = reListMsg.split("#");
                    //清空原来的列表
                    Items.clear();
                    //更新
                    if(msgArr.length>0)
                    {
                        for (int i=0;i<msgArr.length;i++)
                            Items.add(new ListItem(msgArr[i], "箱已满,请清空"));
                        myadpter.notifyDataSetChanged();
                        //Toast.makeText(MaPage.this, "更新状态成功", Toast.LENGTH_SHORT).show();
                    }
                }*/
                Bundle uiBundle = msg.getData();
                String uistring = uiBundle.getString("key");
                if(!uistring.isEmpty()){
                    String history[] = uistring.trim().split("#");
                    Items.clear();
                    Log.d("haha", "the length of i:" + history.length);
                    for(int i = 0; i < history.length; i = i + 3){
                        Log.d("haha", "分段" + history[i]);
                        Items.add(new ListItem(history[i + 2], history[i + 1],history[i]));
                        if(i == 42){
                            break;
                        }
                    }
                    myadpter.notifyDataSetChanged();
                    Log.d("haha", uistring);
                }
            }
        };

        socketThread=new SocketThread(listHandler);
        //我觉得这个线程在活动切换时需要关闭
        new Thread(socketThread).start();

        TimerSet();
        timer.schedule(task,4000,4000);

        Log.d(TAG, "完成初始化");
    }
    public void TimerSet()
    {
        timer = new Timer();
        task = new TimerTask() {
            @Override
            public void run() {
                Start();
            }
        };
    }

    public void Start()
    {
        toServerMsg = new Message();
        toServerMsg.what = GlobalVar.TOSERVER_SINGLE;
        //toServerMsg.obj=new String(toServerMsgStart.getBytes());
        toServerMsg.obj=new String(toServerMsgStartNew.getBytes());
        Log.d(TAG, "Login 向服务器 发送的消息:"+toServerMsgStartNew);
        if(null != socketThread)
            socketThread.sendToServerHandler.sendMessage(toServerMsg);
        else
            Log.d(TAG, "socketThread = null");
    }

    public void Fresh()
    {
        toServerMsg = new Message();
        toServerMsg.what = GlobalVar.TOSERVER_SINGLE;
        toServerMsg.obj=new String(toServerMsgStartNew.getBytes());
        Log.d(TAG, "Login 向服务器 发送的消息:"+toServerMsgStartNew);
        if(null != socketThread)
            socketThread.sendToServerHandler.sendMessage(toServerMsg);
        else
            Log.d(TAG, "socketThread = null");
    }

    public void Stop()
    {
        toServerMsg = new Message();
        toServerMsg.what = GlobalVar.TOSERVER_SINGLE;
        toServerMsg.obj=new String(toServerMsgStop.getBytes());
        Log.d(TAG, "Login 向服务器 发送的消息:"+toServerMsgStop);
        if(null != socketThread)
            socketThread.sendToServerHandler.sendMessage(toServerMsg);
        else
            Log.d(TAG, "socketThread = null");
    }
    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        //(1)返回之后全部都停止了，但是再打开确实不行。
        socketThread.onLinkClosed();
        if (drawer.isDrawerOpen(GravityCompat.START))
        {
            drawer.closeDrawer(GravityCompat.START);
        }
        else
        {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.ma_page, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item)
    {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_camera)
        {
            // Handle the camera action
        } else if (id == R.id.nav_gallery)
        {
            Intent intent = new Intent(MaPage.this,CustomMarkerActivity.class);
            startActivity(intent);
        }
        //系统退出
        else if (id == R.id.nav_share)
        {
            //Toast.makeText(this, "系统已经退出", Toast.LENGTH_SHORT).show();
            socketThread.onLinkClosed();
            finish();
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    class MyCustomAdapter extends BaseAdapter
    {
        ArrayList<ListItem> Items = new ArrayList<ListItem>();
        MyCustomAdapter(ArrayList<ListItem> Items )
        {
            this.Items=Items;
        }
        @Override
        public int getCount()
        {
            return Items.size();
        }
        @Override
        public String getItem(int position) {
            return Items.get(position).Date;

        }
        @Override
        public long getItemId(int position)
        {
            return  position;
        }
        @Override
        public View getView(int i, View view, ViewGroup viewGroup)
        {
            LayoutInflater linflater =getLayoutInflater();
            View view1=linflater.inflate(R.layout.row_view, null);
            TextView txtname =(TextView) view1.findViewById(R.id.txt_date);
            TextView txtdes =(TextView) view1.findViewById(R.id.txt_state);
            TextView txtdes2 = (TextView) view1.findViewById(R.id.txt_state2);
            txtname.setText(Items.get(i).Date);
            txtdes.setText(Items.get(i).Recycle);
            txtdes2.setText(Items.get(i).Unrecycle);
            return view1;
        }
    }

}
