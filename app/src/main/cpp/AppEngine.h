//
// Created by 潘易 on 2018/12/25.
//



#ifndef VBOVAO_APPENGINE_H
#define VBOVAO_APPENGINE_H

#include "GLES3/gl3.h"
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

extern JNIEnv *gJniEnv;
extern jobject gAssetManager;

int readAssetFile(const char *filename);


class IApp{
public:
    int mWidth;
    int mHeight;
    virtual void init() = 0;
    virtual void resize(int w , int h) = 0;
    virtual void step() = 0;
};

class AppEngine : public IApp{
protected:
    GLuint vtxBuf[1];
public:
    void init();

    void resize(int w , int h);

    void step();

    ~AppEngine(){

    }
};
#endif //VBOVAO_APPENGINE_H
