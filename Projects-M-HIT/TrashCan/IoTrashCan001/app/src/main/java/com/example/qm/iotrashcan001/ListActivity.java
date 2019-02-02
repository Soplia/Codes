package com.example.qm.iotrashcan001;

import android.app.LauncherActivity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class ListActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);

        final ArrayList<ListItem> Items=new  ArrayList<ListItem> ();


        final MyCustomAdapter myadpter= new MyCustomAdapter(Items);
        ListView ls=(ListView)findViewById(R.id.listView);
        ls.setAdapter(myadpter);

        /**
         * 这是在为列表项添加响应事件，无需关注
         */

        ls.setOnItemClickListener(new AdapterView.OnItemClickListener()
        {

            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id)
            {
                TextView txtname =(TextView) view.findViewById(R.id.txt_date);
                TextView txtdes =(TextView) view.findViewById(R.id.txt_state);

                Toast.makeText(getApplicationContext(),txtname.getText(),Toast.LENGTH_LONG).show();
                //这个地方就很好的说明了，可以再加
                //以及加上之后该如何刷新

                myadpter.notifyDataSetChanged();
            }
        });

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
            TextView txtdes2 =(TextView) view1.findViewById(R.id.txt_state2);
            txtname.setText(Items.get(i).Date);
            txtdes.setText(Items.get(i).Recycle);
            txtdes2.setText(Items.get(i).Unrecycle);
            return view1;
        }
    }
}
