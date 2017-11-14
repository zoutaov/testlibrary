#include <jni.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <test.h>
#include <android/log.h>
#include <unistd.h>

#define LOG_TAG "Dexload_Jni_Tag"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__)

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	LOGI("JNI_Onload Init");
	JNIEnv* env;
	if( vm->GetEnv((void**)&env , JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }

	//anti_debug();
    return JNI_VERSION_1_4;
}

int GetAndroidVersion(JNIEnv *jenv)
{
	//android.os.Build.VERSION
	/* int sdk_version = android.os.Build.VERSION.SDK_INT; */
    jclass cls_VERSION = jenv->FindClass("android/os/Build$VERSION");
    jfieldID SDK_INT = jenv->GetStaticFieldID(cls_VERSION, "SDK_INT", "I");
    jint sdk_version = jenv->GetStaticIntField(cls_VERSION, SDK_INT);

   return sdk_version;
}

JNIEXPORT jint JNICALL Java_com_example_demo_NativeFunc_init(JNIEnv* env, jobject thiz, jobject context)
{
	return GetAndroidVersion(env);
}
