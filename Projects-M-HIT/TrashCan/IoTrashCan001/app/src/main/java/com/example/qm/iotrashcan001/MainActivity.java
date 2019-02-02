package com.example.qm.iotrashcan001;

import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity
{
    /**
     * 调试部分
     */
    private static final String TAG = "LoginActivity";
    /**
     * 控件部分
     */
    private Button login_bnt = null;
    private EditText userNameET = null;
    private EditText userPassET = null;

    /**
     * Handler部分
     */
    private Handler loginHandler = null;
    private Message toServerMsg = null;
    protected SocketThread socketThread;
    Thread thread;
    /**
     * 变量部分
     */
    private String userName = null;
    private String userPass = null;
    private String userNamePass = "#0$0$#0011#";

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        InitWidget();

        SetWidgetListener();

        loginHandler=new Handler()
        {
            @Override
            public void handleMessage(Message msg)
            {
                String loginMsg=new String((byte[])msg.obj);
                Log.d(TAG, "LOGIN 收到 服务器消息:"+loginMsg);
                if(msg.what == GlobalVar.LOGIN_MSG)
                {
                    if(loginMsg.compareTo(GlobalVar.LOGIN_SUCCESS) == 0)
                    {
                        Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                        Intent intent = new Intent(MainActivity.this,MaPage.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        /**
                         * 这个地方不知道需不需要
                         */
                        /*
                        try {
                            socketThread.socketLinkedToAppServer.close();
                        } catch (IOException e) {
                            Log.d(TAG,"关闭服务器端口失败!");
                        }
                        */
                        socketThread.onLinkClosed();
                        //thread.stop();
                        finish();
                        startActivity(intent);
                    }
                    else
                        Toast.makeText(MainActivity.this, "登录失败", Toast.LENGTH_SHORT).show();

                }
            }
        };

        //socketThread=new SocketThread(loginHandler);
        //我觉得这个线程在活动切换时需要关闭
        //thread=new Thread(socketThread);
        ///thread.start();

    }

    public void InitWidget()
    {
        login_bnt = (Button) findViewById(R.id.login_but);
        userNameET = (EditText) findViewById(R.id.usernameET);
        userPassET = (EditText) findViewById(R.id.userpasswdET);
    }

    public void GetUserNamePass()
    {
        if(null != userNameET)
            userName = userNameET.getText().toString();
        if(null != userPassET)
            userPass = userPassET.getText().toString();
        int size1=userName.length();
        int size2=userPass.length();
        //用户名 密码 不能够为空
        if(size1 < 1 || size1 >50 || size2<1 || size2>50)
            Toast.makeText(MainActivity.this, "请规范填写用户名、密码！（1-50）", Toast.LENGTH_SHORT).show();
        else
        {
            if(null != userName && null != userPass)
            {
                userNamePass="";
                userNamePass = "#"+userName+"$"+userPass+"$#0011#";
            }
        }
    }

    public void SetWidgetListener()
    {
        if(null!=login_bnt)
            login_bnt.setOnClickListener(
                    new View.OnClickListener()
                    {
                        @Override
                        public void onClick(View v)
                        {
                            GetUserNamePass();
                            if((userPass.compareTo("1")==0)&&(userName.compareTo("1")==0))
                            {
                                Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                                Intent intent = new Intent(MainActivity.this,MaPage.class);
                                intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                                intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);

                                finish();
                                startActivity(intent);
                            }
                            else
                                Toast.makeText(MainActivity.this, "登录失败", Toast.LENGTH_SHORT).show();


                            /*
                            toServerMsg = new Message();
                            toServerMsg.what = GlobalVar.TOSERVER_SINGLE;
                            toServerMsg.obj=new String(userNamePass.getBytes());
                            Log.d(TAG, "Login 向服务器 发送的消息:"+userNamePass);
                            socketThread.sendToServerHandler.sendMessage(toServerMsg);
                            */
                        }
                    }
            );
    }
}
