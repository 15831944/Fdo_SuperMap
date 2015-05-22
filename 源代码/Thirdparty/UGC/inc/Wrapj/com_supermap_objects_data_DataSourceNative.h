/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_DataSourceNative */

#ifndef _Included_com_supermap_objects_data_DataSourceNative
#define _Included_com_supermap_objects_data_DataSourceNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetSchema
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetSchema
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetConnectionInfo
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetConnectionInfo
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Execute
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Execute
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Open
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Open
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Close
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsOpen
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsOpen
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDateLastUpdated
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDateLastUpdated
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDateCreated
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDateCreated
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_ChangePassword
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1ChangePassword
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetPassword
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetPassword
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetEngineType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetEngineType
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetEngineName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetEngineName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_BeginTrans
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1BeginTrans
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Commit
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Commit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Rollback
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Rollback
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsTransStarted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsTransStarted
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetDescription
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetDescription
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDescription
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDescription
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetVersion
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetVersion
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetUnoccupiedDatasetName
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetUnoccupiedDatasetName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsAvailableDatasetName
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsAvailableDatasetName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsReadOnly
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsReadOnly
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsExclusive
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsExclusive
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsTransacted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsTransacted
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsEncrypt
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsEncrypt
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsAutoConnect
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsAutoConnect
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetAutoConnect
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetAutoConnect
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetModifiedFlag
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetModifiedFlag
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsModified
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsModified
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetAlias
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetAlias
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetAlias
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetAlias
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_HasAbility
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1HasAbility
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsSupport
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsSupport
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDatasetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDatasetCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDatasetByIndex
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDatasetByIndex
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetDatasetByName
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetDatasetByName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CreateDatasetVectorA
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CreateDatasetVectorA
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CreateDatasetRasterA
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CreateDatasetRasterA
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CreateDatasetFrom
 * Signature: (JLjava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CreateDatasetFrom
  (JNIEnv *, jclass, jlong, jstring, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CopyDataset
 * Signature: (JJLjava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CopyDataset
  (JNIEnv *, jclass, jlong, jlong, jstring, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_DeleteDataset
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1DeleteDataset
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_UndoCheckOut
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1UndoCheckOut
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CheckIn
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CheckIn
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CheckOut
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CheckOut
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Login
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Login
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_IsLogged
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1IsLogged
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_LogOff
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1LogOff
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetSpatialReference
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetSpatialReference
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Connect
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Connect
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_disconnect
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1disconnect
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_RecordsetToDataset
 * Signature: (JLjava/lang/String;JZ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1RecordsetToDataset
  (JNIEnv *, jclass, jlong, jstring, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetAutoCheckOut
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetAutoCheckOut
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetLogged
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetLogged
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_LogIn
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1LogIn
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_LogOut
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1LogOut
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetAutoCheckOut
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetAutoCheckOut
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetUser
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetUser
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetPassword
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetPassword
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_CreateDatasetVectorFrom
 * Signature: (JLjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1CreateDatasetVectorFrom
  (JNIEnv *, jclass, jlong, jstring, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetConnected
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetConnected
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetExclusive
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetExclusive
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetLongTransaction
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetLongTransaction
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetReadOnly
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetReadOnly
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetTransacted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetTransacted
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_GetTransaction
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1GetTransaction
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetConnectionInfo
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetConnectionInfo
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_Begin
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1Begin
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_SetPrjCoordSys
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1SetPrjCoordSys
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_PJForward
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1PJForward
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_PJInverse
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1PJInverse
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DataSourceNative
 * Method:    jni_PJTranslate
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DataSourceNative_jni_1PJTranslate
  (JNIEnv *, jclass, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif
