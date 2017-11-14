package com.example.demo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.jty.myutils.utils.EncryptUtils;

public class MainActivity extends Activity {
    static {
		System.loadLibrary("test");
	}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Context context = getApplicationContext();
        int sdk_version = NativeFunc.init(context);
        Log.d("demo", String.valueOf(sdk_version));
        String sha = EncryptUtils.SHA1Encrypt("hello");
        Log.d("sha1", sha);
        Button bt1 = (Button) findViewById(R.id.button);
        bt1.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                Toast tst = Toast.makeText(MainActivity.this, "test", Toast.LENGTH_SHORT);
                tst.show();
                Test();
            }
        });
    }

    void Test() {
		Log.i("debug", "MainActivity "+jartest.Test.Add(2, 3)+"");
		Log.i("debug", "MainActivity "+jartest.Test.readString());

	}
}
