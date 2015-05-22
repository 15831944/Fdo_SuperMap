/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_GeoLineMNative */

#ifndef _Included_com_supermap_objects_data_GeoLineMNative
#define _Included_com_supermap_objects_data_GeoLineMNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_AddPart
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1AddPart
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetPart
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetPart
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_SetPart
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1SetPart
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_InsertPart
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1InsertPart
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_RemovePart
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1RemovePart
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_ConvertToRegion
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1ConvertToRegion
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_ConvertToLine
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1ConvertToLine
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_Joint
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1Joint
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_Split
 * Signature: (JDDJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1Split
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_FindPointOnLineByDistance
 * Signature: (JDJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1FindPointOnLineByDistance
  (JNIEnv *, jclass, jlong, jdouble, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetCrossings
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetCrossings
  (JNIEnv *, jclass, jlong, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetPointAtM
 * Signature: (JDDJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetPointAtM
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetSubCurveAtM
 * Signature: (JDDJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetSubCurveAtM
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetDistanceAtM
 * Signature: (JDI)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetDistanceAtM
  (JNIEnv *, jclass, jlong, jdouble, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetMAtDistance
 * Signature: (JDI)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetMAtDistance
  (JNIEnv *, jclass, jlong, jdouble, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_UpdateMeasure
 * Signature: (JIIDDIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1UpdateMeasure
  (JNIEnv *, jclass, jlong, jint, jint, jdouble, jdouble, jint, jint, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_InsertMAtDistance
 * Signature: (JDDI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1InsertMAtDistance
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_ExtrapolateMeasure
 * Signature: (JIIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1ExtrapolateMeasure
  (JNIEnv *, jclass, jlong, jint, jint, jint, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_InterpolateMeasure
 * Signature: (JIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1InterpolateMeasure
  (JNIEnv *, jclass, jlong, jint, jint, jint, jint);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_ReverseMOrder
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1ReverseMOrder
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_CalculateNoM
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1CalculateNoM
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_OffsetMeasure
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1OffsetMeasure
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_SetMAsDistance
 * Signature: (JDD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1SetMAsDistance
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetMaxMeasure
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetMaxMeasure
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetMinMeasure
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetMinMeasure
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetMonotonicStyle
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetMonotonicStyle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_Clone
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1Clone
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_GeoLineMNative
 * Method:    jni_GetLength
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_GeoLineMNative_jni_1GetLength
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
