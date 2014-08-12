#include <jni.h>
#include <stdio.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_sayHello (JNIEnv *jenv, jobject jobj) {
    printf("Hello World!\n");
    return;
}
