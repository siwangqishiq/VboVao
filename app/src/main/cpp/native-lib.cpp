#include <jni.h>
#include <string>
#include "AppEngine.h"

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