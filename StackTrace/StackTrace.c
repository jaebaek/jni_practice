#include <jni.h>
#include <stdio.h>
#include "StackTrace.h"

jobject createClass(JNIEnv *jenv, jclass cls) {
    jmethodID midInit = (*jenv)->GetMethodID(jenv, cls, "<init>", "()V");
    if (NULL == midInit) {
        return NULL;
    }
    jobject newObj = (*jenv)->NewObject(jenv, cls, midInit, NULL);
    return newObj;
}

JNIEXPORT void JNICALL Java_StackTrace_do_1print_1stack (JNIEnv *jenv, jobject jobj) {
    // create object
    jclass cls = (*jenv)->FindClass(jenv, "StackTracePrinter");
    jobject newObj = createClass(jenv, cls);
    if (newObj == NULL) {
        perror("Get init method fail");
        return;
    }

    // get method to print stack trace
    jmethodID midPrintStackTrace = (*jenv)->GetMethodID(jenv, cls, "printStackTrace", "()V");
    (*jenv)->CallObjectMethod(jenv, newObj, midPrintStackTrace);
    return;
}
