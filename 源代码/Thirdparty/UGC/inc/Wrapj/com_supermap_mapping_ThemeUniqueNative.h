/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_mapping_ThemeUniqueNative */

#ifndef _Included_com_supermap_mapping_ThemeUniqueNative
#define _Included_com_supermap_mapping_ThemeUniqueNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_New
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1New
  (JNIEnv *, jclass);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_Delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Delete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_GetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_GetUniqueExpression
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetUniqueExpression
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_SetUniqueExpression
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetUniqueExpression
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_GetDefaultStyle
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetDefaultStyle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_SetDefaultStyle
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetDefaultStyle
  (JNIEnv *, jclass, jlong, jlong);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_Add
* Signature: (JLjava/lang/String;ZLjava/lang/String;J)I
*/
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Add
(JNIEnv *, jclass, jlong, jstring, jboolean, jstring, jlong);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_Insert
* Signature: (JILjava/lang/String;ZLjava/lang/String;J)Z
*/
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Insert
(JNIEnv *, jclass, jlong, jint, jstring, jboolean, jstring, jlong);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_Remove
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Remove
  (JNIEnv *, jclass, jlong, jint);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_MakeDefault
* Signature: (JLjava/lang/String;JI)J
*/
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1MakeDefault
(JNIEnv *, jclass, jlong, jstring, jlong, jint);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_Clear
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Clear
  (JNIEnv *, jclass, jlong);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_IndexOf
* Signature: (JLjava/lang/String;)I
*/
JNIEXPORT jint JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1IndexOf
(JNIEnv *, jclass, jlong, jstring);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_IsExist
* Signature: (JLjava/lang/String;)Z
*/
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1IsExist
(JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_mapping_ThemeUniqueNative
 * Method:    jni_ReverseStyle
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1ReverseStyle
  (JNIEnv *, jclass, jlong);
/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_Clone
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Clone
(JNIEnv *, jclass, jlong);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_GetUniqueAt
* Signature: (JI)Ljava/lang/String;
*/
JNIEXPORT jstring JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetUniqueAt
(JNIEnv *, jclass, jlong, jint);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_SetUniqueAt
* Signature: (JILjava/lang/String;)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetUniqueAt
(JNIEnv *, jclass, jlong, jint, jstring);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_GetCaptionAt
* Signature: (JI)Ljava/lang/String;
*/
JNIEXPORT jstring JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetCaptionAt
(JNIEnv *, jclass, jlong, jint);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_SetCaptionAt
* Signature: (JILjava/lang/String;)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetCaptionAt
(JNIEnv *, jclass, jlong, jint, jstring);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_GetIsVisible
* Signature: (JI)Z
*/
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetIsVisible
(JNIEnv *, jclass, jlong, jint);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_SetIsVisible
* Signature: (JIZ)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetIsVisible
(JNIEnv *, jclass, jlong, jint, jboolean);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_GetStyleAt
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetStyleAt
(JNIEnv *, jclass, jlong, jint);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_SetStyleAt
* Signature: (JIJ)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1SetStyleAt
(JNIEnv *, jclass, jlong, jint, jlong);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_GetStylesHandle
* Signature: (J[J)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1GetStylesHandle
(JNIEnv *, jclass, jlong, jlongArray);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_MakeFourColor
* Signature: (JLjava/lang/String;)Z
*/
JNIEXPORT jboolean JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1MakeFourColor
(JNIEnv *, jclass, jlong, jstring);

/*
* Class:     com_supermap_mapping_ThemeUniqueNative
* Method:    jni_Reset
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_supermap_mapping_ThemeUniqueNative_jni_1Reset
(JNIEnv *, jclass, jlong);


#ifdef __cplusplus
}
#endif
#endif
