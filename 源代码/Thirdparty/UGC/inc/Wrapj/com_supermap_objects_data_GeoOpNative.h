/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_GeoOpNative */

#ifndef _Included_com_supermap_objects_data_GeoOpNative
#define _Included_com_supermap_objects_data_GeoOpNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Union
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Union
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Intersect
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Intersect
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Difference
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Difference
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Xor
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Xor
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Distance
 * Signature: (II)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Distance
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Clip
 * Signature: (IDDDDZ)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Clip
  (JNIEnv *, jclass, jint, jdouble, jdouble, jdouble, jdouble, jboolean);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_ClipByGeometry
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1ClipByGeometry
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Resample
 * Signature: (ID)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Resample
  (JNIEnv *, jclass, jint, jdouble);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Split
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Split
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoOpNative
 * Method:    jni_Link
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoOpNative_jni_1Link
  (JNIEnv *, jclass, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
