/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_StringsNative */

#ifndef _Included_com_supermap_objects_data_StringsNative
#define _Included_com_supermap_objects_data_StringsNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_Get
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_StringsNative_jni_1Get
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_Add
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_StringsNative_jni_1Add
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_Remove
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_StringsNative_jni_1Remove
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_RemoveAll
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_StringsNative_jni_1RemoveAll
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_Exchange
 * Signature: (JII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_StringsNative_jni_1Exchange
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_InsertAt
 * Signature: (JILjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_StringsNative_jni_1InsertAt
  (JNIEnv *, jclass, jlong, jint, jstring);

/*
 * Class:     com_supermap_objects_data_StringsNative
 * Method:    jni_GetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_StringsNative_jni_1GetCount
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
