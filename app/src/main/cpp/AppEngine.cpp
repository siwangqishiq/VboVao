//
// Created by 潘易 on 2018/12/25.
//
#include "AppEngine.h"

#include <android/log.h>
#include <malloc.h>
#include <cstring>

int readAssetFile(const char *filename){
    if(gJniEnv == nullptr){
        __android_log_print(ANDROID_LOG_ERROR , "panyitest" , "gJniEnv is null");
    }else{
        __android_log_print(ANDROID_LOG_ERROR , "panyitest" , "gJniEnv is not null");
    }

    AAssetManager* mgr = AAssetManager_fromJava(gJniEnv, gAssetManager);
    AAsset* asset = AAssetManager_open(mgr, filename, AASSET_MODE_UNKNOWN);
    if (nullptr == asset) {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "_ASSET_NOT_FOUND_");
        return JNI_FALSE;
    }
    long size = AAsset_getLength(asset);
    char* buffer = (char*) malloc (sizeof(char)*size);
    memset(buffer , 0 , sizeof(char)*size);
    AAsset_read (asset,buffer,size);
    __android_log_print(ANDROID_LOG_ERROR, "TAG", "%s" , buffer);
    AAsset_close(asset);

    return JNI_TRUE;
}

void AppEngine::init() {
    //readAssetFile("panyi.txt");
    glGenBuffers(1,vtxBuf);
    glBindBuffer(GL_ARRAY_BUFFER , vtxBuf[0]);

}

void AppEngine::resize(int w, int h) {
    this->mWidth = w;
    this->mHeight = h;
    glViewport(0, 0, w, h);
}

void AppEngine::step() {
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}



