//
// Created by sheldon on 17-1-4.
//
/*
（1）JNIEXPORT ：在Jni编程中所有本地语言实现Jni接口的方法前面都有一个"JNIEXPORT",这个可以看做是Jni的一个标志，至今为止没发现它有什么特殊的用处。

（2）jint ：这个学过编程的人都知道，当然是方法的返回值了。

（3）JNICALL ：这个可以理解为Jni 和Call两个部分，和起来的意思就是 Jni调用XXX（后面的XXX就是JAVA的方法名）。

（4）Java_com_test01_Test_firstTest：这个就是被上一步中被调用的部分，也就是Java中的native 方法名，这里起名字的方式比较特别，是：包名+类名+方法名。

（5）JNIEnv * env：这个env可以看做是Jni接口本身的一个对象，在上一篇中提到的jni.h头文件中存在着大量被封装好的函数，这些函数也是Jni编程中经常被使用到的，要想调用这些函数就需要使用JNIEnv这个对象。例如：env->GetObjectClass()。（详情请查看jni.h）

（6）jobject obj：刚才在Test类的main方法中有这样一段代码:　
*/

/* DO NOT EDIT THIS FILE - it is machine generated */
#include "com_li_sheldon_ffmpeg4android_FFmpegNative.h"
/* Header for class com_hsb_ffmpeg_FFmpegNative */
#include "libavcodec/avcodec.h"
#include "libavcodec/avdct.h"
#include "libavcodec/avfft.h"
#include "libavcodec/dirac.h"
#include "libavcodec/dv_profile.h"
#include "libavcodec/vaapi.h"
#include "libavcodec/version.h"
#include "libavcodec/vorbis_parser.h"

#include "libavdevice/avdevice.h"
#include "libavdevice/version.h"

#include "libavfilter/avfilter.h"
#include "libavfilter/avfiltergraph.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
#include "libavfilter/version.h"

#include "libavformat/avformat.h"
#include "libavformat/avio.h"
#include "libavformat/version.h"

#include "libavutil/adler32.h"
#include "libavutil/aes_ctr.h"
#include "libavutil/aes.h"
#include "libavutil/attributes.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/avconfig.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/base64.h"
#include "libavutil/blowfish.h"
#include "libavutil/bprint.h"
#include "libavutil/bswap.h"
#include "libavutil/buffer.h"
#include "libavutil/camellia.h"
#include "libavutil/cast5.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/crc.h"
#include "libavutil/des.h"
#include "libavutil/dict.h"
#include "libavutil/display.h"
#include "libavutil/downmix_info.h"
#include "libavutil/error.h"
#include "libavutil/eval.h"
#include "libavutil/ffversion.h"
#include "libavutil/fifo.h"
#include "libavutil/file.h"
#include "libavutil/frame.h"
#include "libavutil/hash.h"
#include "libavutil/hmac.h"
#include "libavutil/imgutils.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lfg.h"
#include "libavutil/log.h"
#include "libavutil/lzo.h"
#include "libavutil/macros.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/mathematics.h"
#include "libavutil/md5.h"
#include "libavutil/mem.h"
#include "libavutil/motion_vector.h"
#include "libavutil/murmur3.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixelutils.h"
#include "libavutil/pixfmt.h"
#include "libavutil/random_seed.h"
#include "libavutil/rational.h"
#include "libavutil/rc4.h"
#include "libavutil/replaygain.h"
#include "libavutil/ripemd.h"
#include "libavutil/samplefmt.h"
#include "libavutil/sha.h"
#include "libavutil/sha512.h"
#include "libavutil/stereo3d.h"
#include "libavutil/tea.h"
#include "libavutil/threadmessage.h"
#include "libavutil/time.h"
#include "libavutil/timecode.h"
#include "libavutil/timestamp.h"
#include "libavutil/tree.h"
#include "libavutil/twofish.h"
#include "libavutil/version.h"
#include "libavutil/xtea.h"

#include "libswresample/swresample.h"
#include "libswresample/version.h"

#include "libswscale/swscale.h"
#include "libswscale/version.h"

#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "keymatch", __VA_ARGS__)


JNIEXPORT jint JNICALL Java_com_li_sheldon_ffmpeg4android_FFmpegNative_ffmpeg_1h264
  (JNIEnv* env, jobject obj, jint codecID)
 {
    AVCodec* codec = NULL;
    av_register_all();//该函数在所有基于ffmpeg的应用程序中几乎都是第一个被调用的。只有调用了该函数，才能使用复用器，编码器等
    codec = avcodec_find_decoder(codecID);//通过code ID查找一个已经注册的音视频编码器。H264的codecID是28，所以我们java那边传28下来如果检测到H264注册过了这边codec就不为空，返回0

    /*
    //Linux v4l2
    AVFormatContext *pFormatCtx;
    int             i, videoindex;
    AVCodecContext  *pCodecCtx;
    AVCodec         *pCodec;

    avdevice_register_all(); //注册libavdevice

    av_register_all();
    avformat_network_init();
    pFormatCtx = avformat_alloc_context();
    AVInputFormat *ifmt = av_find_input_format("video4linux2");
    if(avformat_open_input(&pFormatCtx,"/dev/video1",ifmt,NULL)!=0){
       LOGD("[sz_cam_ffmpeg]Couldn't open input stream.\n");
       return -1;
    }

    if(avformat_find_stream_info(pFormatCtx,NULL)<0)
    {
       LOGD("[sz_cam_ffmpeg]Couldn't find stream information.\n");
       return -1;
    }

    videoindex=-1;
    for(i=0; i<pFormatCtx->nb_streams; i++){
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoindex=i;
            break;
        }
    }

    if(videoindex==-1)
    {
        LOGD("[sz_cam_ffmpeg]Couldn't find a video stream.\n");
        return -1;
    }
    pCodecCtx=pFormatCtx->streams[videoindex]->codec;
    pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
    if(pCodec==NULL)
    {
        LOGD("[sz_cam_ffmpeg]Codec not found.\n");
        return -1;
    }
    if(avcodec_open2(pCodecCtx, pCodec,NULL)<0)
    {
        LOGD("[sz_cam_ffmpeg]Could not open codec.\n");
        return -1;
    }

    AVFrame *pFrame,*pFrameYUV;
    pFrame=av_frame_alloc();
    pFrameYUV=av_frame_alloc();

    //......

    av_free(pFrameYUV);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
    */
    if(codec != NULL){
      return 0;
    }else{
      return -1;
    }
}
