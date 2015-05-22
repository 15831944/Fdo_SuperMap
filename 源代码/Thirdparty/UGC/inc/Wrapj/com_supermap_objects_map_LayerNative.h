/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_map_LayerNative */

#ifndef _Included_com_supermap_objects_map_LayerNative
#define _Included_com_supermap_objects_map_LayerNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_ToXML
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_map_LayerNative_jni_1ToXML
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_FromXML
 * Signature: (JLjava/lang/String;ZI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1FromXML
  (JNIEnv *, jclass, jlong, jstring, jboolean, jint);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetDescription
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetDescription
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetDescription
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetDescription
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetDataset
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetDataset
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetCaption
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetCaption
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetCaption
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetCaption
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetVisibleScaleMax
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetVisibleScaleMax
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetVisibleScaleMin
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetVisibleScaleMin
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetVisibleScaleMax
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetVisibleScaleMax
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetVisibleScaleMin
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetVisibleScaleMin
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetOptions
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetOptions
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetOptions
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetOptions
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetRasterOpaqueRate
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetRasterOpaqueRate
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetRasterOpaqueRate
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetRasterOpaqueRate
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetThemes
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetThemes
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetDisplayFilter
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetDisplayFilter
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetMinimumVisible
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetMinimumVisible
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetVisible
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetVisible
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_IsVisibleScale
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1IsVisibleScale
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetMinimumVisible
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetMinimumVisible
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetVisible
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetVisible
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_ConvertThemeToDataset
 * Signature: (JJLjava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1ConvertThemeToDataset
  (JNIEnv *, jclass, jlong, jlong, jstring, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetAllowTextOverlapped
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetAllowTextOverlapped
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetChildLayer
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetChildLayer
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetDatasetVector
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetDatasetVector
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetDisplayFilter
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetDisplayFilter
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetKeepOrder
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetKeepOrder
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetParentLayer
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetParentLayer
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetSelectable
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetSelectable
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetStyle
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetStyle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetSymbolScalable
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetSymbolScalable
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetSymbolScaleDefinition
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetSymbolScaleDefinition
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_HitTest
 * Signature: (JDDDJ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1HitTest
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_HitTestEx
 * Signature: (JDDDJ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1HitTestEx
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetAllowTextOverlapped
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetAllowTextOverlapped
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetKeepOrder
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetKeepOrder
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetSelectable
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetSelectable
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetStyle
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetStyle
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetSymbolScalable
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetSymbolScalable
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_SetSymbolScaleDefinition
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_map_LayerNative_jni_1SetSymbolScaleDefinition
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetVector
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetVector
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_map_LayerNative
 * Method:    jni_GetDatasetRaster
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_map_LayerNative_jni_1GetDatasetRaster
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
