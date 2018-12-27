#include <jni.h>
#include <string>
#include "AppEngine.h"
#include <android/log.h>

static IApp *app = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_vbovao_NativeBridge_init(JNIEnv *env, jclass type) {
    if (app != nullptr) {
        delete app;
        app = nullptr;
    }

    app = new AppEngine();
    app->init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_vbovao_NativeBridge_resize(JNIEnv *env, jclass type, jint width, jint height) {
    if (app != nullptr) {
        app->resize(width, height);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_vbovao_NativeBridge_step(JNIEnv *env, jclass type) {
    if (app != nullptr) {
        app->step();
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_vbovao_NativeBridge_setAssetManager(JNIEnv *env, jclass type, jobject manager) {
    if(env == nullptr){
        __android_log_print(ANDROID_LOG_ERROR , "panyi tips" , "env 111 is null");
    }

    gJniEnv = env;
    __android_log_print(ANDROID_LOG_ERROR , "panyi tips" , "gEnv = %ld" ,gJniEnv);
    gAssetManager = manager;

    __android_log_print(ANDROID_LOG_ERROR , "panyi tips" , "%s" , "env setsetset...");

    //readAssetFile("panyi.txt");

//    if(gEnv == nullptr){
//        __android_log_print(ANDROID_LOG_ERROR , "panyitest" , "env is null");
//    }else{
//        __android_log_print(ANDROID_LOG_ERROR , "panyitest" , "env is not null");
//    }
//
//    AAssetManager* mgr = AAssetManager_fromJava(gEnv, gAssetManager);
//    AAsset* asset = AAssetManager_open(mgr, "panyi.txt", AASSET_MODE_UNKNOWN);
//    if (nullptr == asset) {
//        __android_log_print(ANDROID_LOG_ERROR, "TAG", "_ASSET_NOT_FOUND_");
//        return;
//    }
//    long size = AAsset_getLength(asset);
//    char* buffer = (char*) malloc (sizeof(char)*size);
//    AAsset_read (asset,buffer,size);
//    __android_log_print(ANDROID_LOG_ERROR, "TAG", "%s" , buffer);
//    AAsset_close(asset);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_vbovao_NativeBridge_readFile(JNIEnv *env, jclass type, jobject gAssetManager) {
    __android_log_print(ANDROID_LOG_ERROR , "read test" , "begin read file...");

    const char *filename = "normal_vertex.glsl";
    AAssetManager* mgr = AAssetManager_fromJava(env, gAssetManager);
    AAsset* asset = AAssetManager_open(mgr, filename, AASSET_MODE_UNKNOWN);
    if (nullptr == asset) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "_ASSET_NOT_FOUND_");
        return;
    }
    long size = AAsset_getLength(asset);
    char* buffer = (char *) malloc (sizeof(char)*size);
    memset(buffer , 0 , size * sizeof(char));
    AAsset_read (asset,buffer,size);
    __android_log_print(ANDROID_LOG_ERROR, "Content", "%s END" , buffer);
    AAsset_close(asset);

    __android_log_print(ANDROID_LOG_ERROR , "read test" , "end read file");
}