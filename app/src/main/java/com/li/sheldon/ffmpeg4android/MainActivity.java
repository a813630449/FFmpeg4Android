package com.li.sheldon.ffmpeg4android;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        int codec_id=28;
        FFmpegNative ffmpeg = new FFmpegNative();
        int tmp = ffmpeg.test_h246(codec_id); //28 is the H264 Codec ID
        TextView tv = (TextView)this.findViewById(R.id.hello_ffmpeg);
        tv.setText(tmp==0?"Support Codec ID:"+codec_id:"Not support Codec ID:"+codec_id);
    }
}
