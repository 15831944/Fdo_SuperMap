/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_SymbolGroupNative */

#ifndef _Included_com_supermap_objects_data_SymbolGroupNative
#define _Included_com_supermap_objects_data_SymbolGroupNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_AddSymbolItem
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1AddSymbolItem
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_CreateChildGroup
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1CreateChildGroup
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetChildGroupFromIndex
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetChildGroupFromIndex
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetChildGroupFromName
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetChildGroupFromName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetChildGroupCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetChildGroupCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetSymbolItemCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetSymbolItemCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetSymbolItemID
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetSymbolItemID
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_GetSymbolItemName
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1GetSymbolItemName
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_MoveSymbolItemToA
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1MoveSymbolItemToA
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_MoveSymbolItemToB
 * Signature: (JIIJ)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1MoveSymbolItemToB
  (JNIEnv *, jclass, jlong, jint, jint, jlong);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_RemoveChildGroup
 * Signature: (JIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1RemoveChildGroup
  (JNIEnv *, jclass, jlong, jint, jboolean);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_RemoveSymbolItemA
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1RemoveSymbolItemA
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_RemoveSymbolItemB
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1RemoveSymbolItemB
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_SymbolGroupNative
 * Method:    jni_SetName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_SymbolGroupNative_jni_1SetName
  (JNIEnv *, jclass, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
