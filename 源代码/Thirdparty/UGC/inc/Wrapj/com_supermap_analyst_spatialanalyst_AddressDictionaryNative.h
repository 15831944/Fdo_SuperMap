/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_analyst_spatialanalyst_AddressDictionaryNative */

#ifndef _Included_com_supermap_analyst_spatialanalyst_AddressDictionaryNative
#define _Included_com_supermap_analyst_spatialanalyst_AddressDictionaryNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_New
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1New
  (JNIEnv *, jclass);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_Delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1Delete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_GetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1GetCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_GetItem
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1GetItem
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_Contains
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1Contains
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_IndexOf
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1IndexOf
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_Add
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1Add
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_DeleteWorld
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1DeleteWorld
  (JNIEnv *, jclass, jlong, jstring);

///*
// * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
// * Method:    jni_Clear
// * Signature: (J)V
// */
//JNIEXPORT void JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1Clear
//  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_Load
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1Load
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_SaveAs
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1SaveAs
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_TextToDictionary
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1TextToDictionary
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_DictionaryToText
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1DictionaryToText
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_supermap_analyst_spatialanalyst_AddressDictionaryNative
 * Method:    jni_MergeDictionary
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_analyst_spatialanalyst_AddressDictionaryNative_jni_1MergeDictionary
  (JNIEnv *, jclass, jstring, jstring, jstring);



#ifdef __cplusplus
}
#endif
#endif
