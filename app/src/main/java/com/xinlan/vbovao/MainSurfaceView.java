package com.xinlan.vbovao;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MainSurfaceView extends GLSurfaceView implements GLSurfaceView.Renderer {
    public MainSurfaceView(Context context) {
        super(context);
        NativeBridge.setAssetManager(context.getAssets());

        setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        setEGLContextClientVersion(3);
        setRenderer(this);
    }


    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        NativeBridge.init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        NativeBridge.resize(width , height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        NativeBridge.step();
    }
}//end class
