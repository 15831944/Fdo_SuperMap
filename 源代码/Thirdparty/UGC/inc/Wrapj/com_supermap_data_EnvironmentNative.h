/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_data_EnvironmentNative */

#ifndef _Included_com_supermap_data_EnvironmentNative
#define _Included_com_supermap_data_EnvironmentNative
#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     com_supermap_data_EnvironmentNative
	* Method:    jni_InitEnvironment
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_com_supermap_data_EnvironmentNative_jni_1InitEnvironment
		(JNIEnv *, jclass);

	/*
	* Class:     com_supermap_data_EnvironmentNative
	* Method:    jni_GetCurrentLoadedEngineCount
	* Signature: ()I
	*/
	JNIEXPORT jint JNICALL Java_com_supermap_data_EnvironmentNative_jni_1GetCurrentLoadedEngineCount
		(JNIEnv *, jclass);

	/*
	* Class:     com_supermap_data_EnvironmentNative
	* Method:    jni_GetCurrentLoadedEngine
	* Signature: ([I)V
	*/
	JNIEXPORT void JNICALL Java_com_supermap_data_EnvironmentNative_jni_1GetCurrentLoadedEngine
		(JNIEnv *, jclass, jintArray);

#ifdef __cplusplus
}
#endif
#endif
