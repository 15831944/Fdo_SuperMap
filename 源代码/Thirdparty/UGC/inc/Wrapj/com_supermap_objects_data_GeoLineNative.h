/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_GeoLineNative */

#ifndef _Included_com_supermap_objects_data_GeoLineNative
#define _Included_com_supermap_objects_data_GeoLineNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_GetCrossings
 * Signature: (JJJ)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1GetCrossings
  (JNIEnv *, jclass, jlong, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_GetPartAt
 * Signature: (JIJ)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1GetPartAt
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_SetPartAt
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1SetPartAt
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_AddPart
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1AddPart
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_InsertPartAt
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1InsertPartAt
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_RemovePartAt
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1RemovePartAt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_Joint
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1Joint
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_ResampleEquidistantly
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1ResampleEquidistantly
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_Reverse
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1Reverse
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_Split
 * Signature: (JDDJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1Split
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_Clone
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1Clone
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_ConvertToRegion
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1ConvertToRegion
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_FindPointOnLineByDistance
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1FindPointOnLineByDistance
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_GeoLineNative
 * Method:    jni_GetLength
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineNative_jni_1GetLength
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
