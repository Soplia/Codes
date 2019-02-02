package com.example.qm.iotrashcan001;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;

import com.amap.api.maps.AMap;
import com.amap.api.maps.MapView;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by 朱宏博 on 2018/2/24.
 */

public class MapActivity extends Activity implements View.OnClickListener{
    private MapView mapView;
    private AMap aMap;
    private Button basicmap;
    private Button rsmap;
    private Button nightmap;
    private Button navimap;

    private CheckBox mStyleCheckbox;


    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.basicmap_activity);

        mapView = (MapView)findViewById(R.id.map);
        mapView.onCreate(savedInstanceState);

        init();
    }

    private void init(){
        if(aMap == null){
            aMap = mapView.getMap();
        }

        setMapCustomStyleFile(this);
        basicmap = (Button)findViewById(R.id.basicmap);
        basicmap.setOnClickListener(this);
        rsmap = (Button)findViewById(R.id.rsmap);
        rsmap.setOnClickListener(this);
        nightmap = (Button)findViewById(R.id.nightmap);
        nightmap.setOnClickListener(this);
        navimap = (Button)findViewById(R.id.navimap);
        navimap.setOnClickListener(this);

        mStyleCheckbox = (CheckBox) findViewById(R.id.check_style);

        mStyleCheckbox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b){
                aMap.setMapCustomEnable(b);
            }
        });
    }

    private void setMapCustomStyleFile(Context context){
        String styleName = "style_json.json";
        FileOutputStream outputStream = null;
        InputStream inputStream = null;
        String filePath = null;
        try{
            inputStream = context.getAssets().open(styleName);
            byte[] b = new byte[inputStream.available()];
            inputStream.read(b);

            filePath = context.getFilesDir().getAbsolutePath();
            File file = new File(filePath + "/" + styleName);
            if(file.exists()){
                file.delete();
            }
            file.createNewFile();
            outputStream = new FileOutputStream(file);
            outputStream.write(b);
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            try {
                if (inputStream != null)
                    inputStream.close();

                if (outputStream != null)
                    outputStream.close();

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        aMap.setCustomMapStylePath(filePath + "/" + styleName);

        aMap.showMapText(false);
    }


    @Override
    protected void onResume(){
        super.onResume();
        mapView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mapView.onPause();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        mapView.onSaveInstanceState(outState);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mapView.onDestroy();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.basicmap:
                aMap.setMapType(AMap.MAP_TYPE_NORMAL);// 矢量地图模式
                break;
            case R.id.rsmap:
                aMap.setMapType(AMap.MAP_TYPE_SATELLITE);// 卫星地图模式
                break;
            case R.id.nightmap:
                aMap.setMapType(AMap.MAP_TYPE_NIGHT);//夜景地图模式
                break;
            case R.id.navimap:
                aMap.setMapType(AMap.MAP_TYPE_NAVI);//导航地图模式
                break;
        }

        mStyleCheckbox.setChecked(false);

    }

}
