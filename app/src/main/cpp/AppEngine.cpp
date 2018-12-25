//
// Created by 潘易 on 2018/12/25.
//
#include "AppEngine.h"

void AppEngine::init() {

}

void AppEngine::resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void AppEngine::step() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



