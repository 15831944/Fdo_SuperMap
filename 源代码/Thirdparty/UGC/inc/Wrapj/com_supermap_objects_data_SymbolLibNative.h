/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_SymbolLibNative */

#ifndef _Included_com_supermap_objects_data_SymbolLibNative
#define _Included_com_supermap_objects_data_SymbolLibNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_Export
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1Export
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_Find
 * Signature: (JLjava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1Find
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetMaxID
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetMaxID
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetRootGroup
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetRootGroup
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetSymbolCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetSymbolCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetSymbolItemID
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetSymbolItemID
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetSymbolItemIndex
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetSymbolItemIndex
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetSymbolItemName
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetSymbolItemName
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_Import
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1Import
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_Remove
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1Remove
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_RemoveAll
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1RemoveAll
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_RemoveAt
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1RemoveAt
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_ReverseFind
 * Signature: (JLjava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1ReverseFind
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_SetSymbolItemID
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1SetSymbolItemID
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_SetSymbolItemName
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1SetSymbolItemName
  (JNIEnv *, jclass, jlong, jint, jstring);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_DrawMarkSymbol
 * Signature: (JJJJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1DrawMarkSymbol
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_DrawLineSymbol
 * Signature: (JJJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1DrawLineSymbol
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_DrawFillSymbol
 * Signature: (JJJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1DrawFillSymbol
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolLibNative
 * Method:    jni_GetSymbolDefaultSize
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_SymbolLibNative_jni_1GetSymbolDefaultSize
  (JNIEnv *, jclass, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
