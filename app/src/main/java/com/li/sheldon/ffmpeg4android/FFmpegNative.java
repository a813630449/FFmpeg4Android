package com.li.sheldon.ffmpeg4android;

/**
 * Created by sheldon on 17-1-4.
 */
public class FFmpegNative {

    static{
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avutil-55");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
        System.loadLibrary("ffmpegjni");
    }

    private native int ffmpeg_h264(int codecID);

    public int test_h246(int id){
        return ffmpeg_h264(id);
    }
}
