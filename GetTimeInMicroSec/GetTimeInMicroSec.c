#include <jni.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "GetTimeInMicroSec.h"

JNIEXPORT jlongArray JNICALL Java_GetTimeInMicroSec_get_1time_1in_1microsec
(JNIEnv *jenv, jobject jobj) {
    // get current time
    struct timeval now;
    gettimeofday(&now, NULL);
    jlong retCArray[] = { now.tv_sec, now.tv_usec };

    // alloc JNI long array
    jlongArray retJNIArray = (*jenv)->NewLongArray(jenv, 2);
    if (NULL == retJNIArray) return NULL;

    // set JNI long array
    (*jenv)->SetLongArrayRegion(jenv, retJNIArray, 0 , 2, retCArray);

    return retJNIArray;
}
