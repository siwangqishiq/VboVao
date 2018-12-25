//
// Created by 潘易 on 2018/12/25.
//

#ifndef VBOVAO_APPENGINE_H
#define VBOVAO_APPENGINE_H

#include "GLES3/gl3.h"

class IApp{
public:
    int mWidth;
    int mHeight;
    virtual void init() = 0;
    virtual void resize(int w , int h) = 0;
    virtual void step() = 0;
};

class AppEngine : public IApp{

public:
    void init();

    void resize(int w , int h);

    void step();

    ~AppEngine(){

    }
};
#endif //VBOVAO_APPENGINE_H
