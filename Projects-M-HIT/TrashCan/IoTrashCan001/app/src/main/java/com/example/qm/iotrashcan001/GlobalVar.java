package com.example.qm.iotrashcan001;

/**
 * Created by QM on 2018/2/24.
 */

public class GlobalVar
{
    /**
     *  网络连接部分
     */
    public static String IP = "10.10.10.132";//120.79.24.19
    public static int PORT = 11000;

    /**
     *  APP → 服务器
     */
    public static String START = "0000";
    public static String STOP = "0001";
    public static String FRESH = "0010";
    public static String LOGIN = "0011";
    public static byte TOSERVER_SINGLE = 0x00;

    /**
     * 服务器 → APP
     */
    public static byte LOGIN_MSG = 0x23;
    public static byte TRASHCAN_MSG = 0x24;
    public static byte SYSTEM_MSG = 0x25;

    /**
     * 用户登录部分
     */
    public static String LOGIN_SUCCESS="#1";
    public static String LOGIN_FAIL="#0";
}
