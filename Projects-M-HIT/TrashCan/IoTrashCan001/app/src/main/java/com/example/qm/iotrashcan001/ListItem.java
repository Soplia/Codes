package com.example.qm.iotrashcan001;

/**
 * Created by QM on 2018/2/24.
 */

public class ListItem
{
    public String Date;
    public String Recycle;
    public String Unrecycle;
    ListItem(String date,String Recycle, String Unrecycle)
    {
        this.Date =date;
        this.Recycle = Recycle;
        this.Unrecycle = Unrecycle;
    }
}
