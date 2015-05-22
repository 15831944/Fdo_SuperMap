/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_mapping_ThemeGridUniqueNative */

#ifndef _Included_com_supermap_mapping_ThemeGridUniqueNative
#define _Included_com_supermap_mapping_ThemeGridUniqueNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_New
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1New
  (JNIEnv *, jclass);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Delete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetDefaultColor
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetDefaultColor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_SetDefaultColor
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1SetDefaultColor
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Add
 * Signature: (JDZLjava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Add
  (JNIEnv *, jclass, jlong, jdouble, jboolean, jstring, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Insert
 * Signature: (JIDZLjava/lang/String;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Insert
  (JNIEnv *, jclass, jlong, jint, jdouble, jboolean, jstring, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Remove
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Remove
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Clear
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Clear
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_IndexOf
 * Signature: (JD)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1IndexOf
  (JNIEnv *, jclass, jlong, jdouble);

/*
* Class:     com_supermap_mapping_ThemeGridUniqueNative
* Method:    jni_IsExist
* Signature: (JD)Z
*/
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1IsExist
(JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_ReverseColor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1ReverseColor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_Clone
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1Clone
  (JNIEnv *, jclass, jlong);

/*
* Class:     com_supermap_mapping_ThemeGridUniqueNative
* Method:    jni_MakeDefault
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1MakeDefault
(JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetUniqueAt
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetUniqueAt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_SetUniqueAt
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1SetUniqueAt
  (JNIEnv *, jclass, jlong, jint, jdouble);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetCaptionAt
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetCaptionAt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_SetCaptionAt
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1SetCaptionAt
  (JNIEnv *, jclass, jlong, jint, jstring);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetIsVisible
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetIsVisible
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_SetIsVisible
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1SetIsVisible
  (JNIEnv *, jclass, jlong, jint, jboolean);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_GetColorAt
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1GetColorAt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeGridUniqueNative
 * Method:    jni_SetColorAt
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeGridUniqueNative_jni_1SetColorAt
  (JNIEnv *, jclass, jlong, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
