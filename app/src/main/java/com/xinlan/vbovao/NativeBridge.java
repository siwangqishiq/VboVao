package com.xinlan.vbovao;

import android.content.res.AssetManager;

public class NativeBridge {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static native void init();
    public static native void resize(int width, int height);
    public static native void step();

    public static native void setAssetManager(AssetManager manager);

    public static native void readFile(AssetManager mgr);
}
