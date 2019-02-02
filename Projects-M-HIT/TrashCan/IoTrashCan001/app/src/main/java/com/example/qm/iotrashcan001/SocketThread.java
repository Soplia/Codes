package com.example.qm.iotrashcan001;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
/**
 * Created by QM on 2018/2/24.
 */

public class SocketThread implements Runnable
{
    /**
     * 调试部分
     */
    private static final String TAG = "SocketThread";
    /**
     * 网络连接部分
     */
    protected Socket socketLinkedToAppServer;
    private InputStream isFromServer;
    private DataInputStream dataisFromServer;
    private OutputStream osToServer;
    private DataOutputStream dataosToServer;
    /**
     *  Handler部分
     */
    protected Handler sendToActivityHandler;
    protected Handler sendToServerHandler;

    /**
     *  函数部分
     */
    public SocketThread(Handler handler)
    {
        sendToActivityHandler = handler;
        socketLinkedToAppServer = null;
        isFromServer = null;
        osToServer = null;
        sendToServerHandler=null;
    }


    public void onLinkClosed()
    {
        if(dataisFromServer!=null)
            try {
                dataisFromServer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        if(dataosToServer!=null)
            try {
                dataosToServer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        if(socketLinkedToAppServer!=null)
            try {
                socketLinkedToAppServer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
    }

    @Override
    public void run()
    {
        new Thread()
        {
            public void run()
            {
                try
                {
                    Log.d("haha", "进入run");
                    Log.d(TAG, "正在连接 SERVER...");
                    socketLinkedToAppServer = new Socket(GlobalVar.IP, GlobalVar.PORT);

                    if(null != socketLinkedToAppServer)
                    {
                        Log.d(TAG, "获取 socketlink 成功");
                        //isFromServer = socketLinkedToAppServer.getInputStream();
                        dataisFromServer = new DataInputStream(socketLinkedToAppServer.getInputStream());
                        //dataisFromServer = new DataInputStream(isFromServer);

                        //osToServer = socketLinkedToAppServer.getOutputStream();
                        dataosToServer = new DataOutputStream(socketLinkedToAppServer.getOutputStream());
                        //dataosToServer = new DataOutputStream(osToServer);


                        if(null == dataosToServer)
                            Log.d(TAG, "1 获取 SERVER输出流 失败");
                        if(null == dataisFromServer)
                            Log.d(TAG, "1 获取 SERVER输入流 失败");
////////////////////////////////////////////////////////////////////////////////
                        //Log.d(TAG, "输出TRASH");
                        //dataosToServer.writeUTF("TRASH");
                        //dataosToServer.flush();

                        if(null != dataisFromServer)
                        {
                            Log.d(TAG, "获取 SERVER输入流 成功");
                            //循环 监听 服务器
                            while(true)
                            {
                              /*  int count = 0;
                                while (count == 0)
                                    count = isFromServer.available();
                                byte[] rebyte = new byte[count];
                                isFromServer.read(rebyte);

                                Message toActivityMsg = new Message();
                                //# 登录信息
                                if(rebyte[0] == GlobalVar.LOGIN_MSG)
                                {
                                    toActivityMsg.what = GlobalVar.LOGIN_MSG;

                                }
                                //$ 垃圾箱状态信息
                                else if(rebyte[0] == GlobalVar.TRASHCAN_MSG)
                                    toActivityMsg.what = GlobalVar.TRASHCAN_MSG;
                                    //% 服务器反馈信息（暂时不用）
                                else
                                    toActivityMsg.what = GlobalVar.SYSTEM_MSG;

                                toActivityMsg.obj = rebyte;
                                sendToActivityHandler.sendMessage(toActivityMsg);
                                Log.d(TAG, "向 Activity 发送 "+ new String(rebyte)+" 信息完毕");*/
                                String s = dataisFromServer.readUTF();
                                Log.d("haha", s);
                                Message toActivityMsg = new Message();
                                Bundle myBundle = new Bundle();
                                myBundle.putString("key", s);
                                toActivityMsg.setData(myBundle);
                                  Log.d(TAG, "runner pre stop");
                                sendToActivityHandler.sendMessage(toActivityMsg);

                            }
                        }
                        else
                            Log.d(TAG, "获取 SERVER输入流 失败");
                    }
                    else
                    {
                        Log.d(TAG, "连接 SERVER 失败");
                    }
                }
                catch (Exception e)
                {
                    Log.d(TAG, "服务器Down.....");
                }
                Log.d(TAG, "runner stop");
            }
        }.start();

        Looper.prepare();

        sendToServerHandler=new Handler()
        {
            public void handleMessage(Message msg)
            {
                try
                {
                    if(msg.what == GlobalVar.TOSERVER_SINGLE)
                        if(null != dataosToServer)
                        {
                            //Log.d(TAG, "获取 SERVER输出流 成功");
                            //osToServer.write(msg.obj.toString().getBytes());

                            dataosToServer.writeUTF("TRASH");
                            dataosToServer.flush();
                            Log.d(TAG, "输出TRASH");

                        }
                        else
                            Log.d(TAG, "获取 SERVER输出流 失败");
                    else
                        Log.d(TAG, "发送 信息类型 错误");
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                    Log.d(TAG, "发送信息时服务器Down.....");
                }
            }
        };
        Looper.loop();
    }

}