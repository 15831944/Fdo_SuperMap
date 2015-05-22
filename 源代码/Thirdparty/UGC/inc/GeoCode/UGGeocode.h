#ifndef UGGEOCODE_H
#define UGGEOCODE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"

#include "Algorithm/UGOpLines.h"
#include "Algorithm/UGOpPoints.h"
#include "Algorithm/UGRelLines.h"
#include "Algorithm/UGOpPointLine.h"

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGQueryDef.h"

#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoPoint.h"

#include "UGGeoCodeDefine.h"
#include "UGAddressStandardize.h"

#include <math.h>

#include "Base/ugdefs.h"

/*!
   **************************************************************************************
    \file     UGGeocode.h
   **************************************************************************************
    \author   ����������
    \brief    ���������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1997-2006 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2006-06-29  ����    ��ʼ���汾.       ��ʵ��Ӣ�Ľֵ���ַƥ��           <br>
   **************************************************************************************
   
   **************************************************************************************
   ********							�޸ļ�¼									*********
   **************************************************************************************
   **************************************************************************************
*/

/*	�������������ϵ:
*	BuildIndex(��������) 
 *	  <- SetIndexField(���������ֶ�) <- SetFieldValue(���û�׼��ַ�ֶ�����) 
 *		    <- SetDatasetReference(ָ����׼��ַ) <- SetType(��ַ���ͣ�ȷ������)
 *	m_AddStamd(��ַ��׼��) <- ���ùؼ��ʡ���׼����д�������ֶ� <- ���ý������ݼ� <- SetType���õ�ַ����
 
 */
/* ���������ѵ�:
 *	1.(��USStreet��ַ)����һ���ڲ���Ӧ��ϵ�������� ����е�ַ380 New York Streetȥƥ��һ����׼��ַ ����
 *     ��׼��Ϊ7���ֶ� HN/PD�ȣ�HN=380 SN=New York ST= Street �������׼��ַ���ֶ�L_F_HN
 *     �ڲ���Ӧ��ϵΪ (�ⲿ) 380 ->   (�ڲ�)HN->FROMLEFT(�ڲ�)   ->		(�ⲿ)L_F_HN
 *     (�ڲ�)HN->FROMLEFT(�ڲ�)���ڲ��Զ���ģ��൱��ESRI�е�MAT��
 */



namespace UGC {

class GEOCODE_API UGGeoCode
{
public:
	/*!	\brief ����״̬ */
	enum SmIndexState
	{
		SMIndexNonexistant	= 1,			// ����������
		SMIndexInvalid		= 2,			// ������Ч
		SMIndexUnreadable	= 3,			// �������ɶ�
		SMIndexExists		= 4				// ��������
	};

	/*!	\brief ��ַ���ڱߵ���߻����ұ� */
	enum SmStreetSide
	{
		SMSideNone			= 0,			// Ԥ���ӿ� ����һ������
		SMSideLeft			= 1,			// �ڽֵ����
		SMSideRight			= 2,			// �ڽֵ��ұ߱�
		SMSideBoth			= 3,			// �ڽֵ����߾���
		SMIntersectionSide	= 4,			// �������
		SMSideOther			= 5				// ����
	};

	/*!	\brief ƥ���� */
	enum SmMatchConstants
	{
		SMMatchFailed		= 0,			// ƥ��ʧ��
		SMMatchSingleBest	= 1,			// ��һ�����ƥ��
		SMMatchMultipleBest	= 2,			// ������ƥ��
		SMMatchPartial		= 3,			// ����ƥ�䣬Ҳ����û�дﵽ��ͷ���
	};
	
	/*!	\brief ��ѡ��¼��ƥ���� */
	enum SmCandidateState
	{
		SMCandidateMatch	= 0,			// ��ѡ������֮ƥ��
		SMCandidateUnMatch	= 1,			// ��ѡ����δƥ��
	};

	/*!	\brief �ֶ�ƥ���� */
	enum SmFieldMatchConstants
	{
		SMFieldMatchFailed	  = 0,			// �ֶ�ƥ��ɹ� �۷�
		SMFieldMatchNotFialed = 1,			// ���ӷ�Ҳ���۷�
		SMFieldMatchSuccess	  = 2,			// �ֶ�ƥ��ɹ� �ӷ�
	};

	struct SmAddressLocation
	{
		UGint	    m_nAddressID	;		// ��Ӧ����׼��ַ�ϵ�SMID
		UGint		m_nScore		;		// �õ��õķ��� ��0��100֮��
		UGPoint2D   m_ptLocation	;		// ��λ���ĵ�
		UGdouble    m_dPersent		;		// ���ߵĿ�ʼ��FromNode����λ����ռ�����߶εİٷֱ�
		UGint       m_nSide			;		// ��ַ���ڱ�
		UGint		m_nCandidateState;		// ��ѡ����ƥ��״̬
	//---------�������ʱ���ʹ��
		UGint		m_nAddressID1;		// ������ڵ�����һ��ID
		UGint		m_nAddressID2;		// ������ڵ�����һ��ID
	};

	
	UGGeoCode();
	virtual ~UGGeoCode();


	/*!	\brief	����ַƥ��
	*! \remarks ������ǰ��ı�׼�� ������
	*/
	UGbool MatchAddress(UGString strAddress,UGProgress * pProgres = NULL);

	/*!	\brief	��������
	 *! \remarks ����ǰ m_strArrIndexFieldName���벻��Ϊ��
	 *! \remarks ����һ������ʹ��̽�ⷨ���� �������μ���
	*/
	UGbool BuildIndex(UGString strNewDtName = "sm_GeoCode_index",UGProgress * pProgres = NULL);


	/*!	\brief	���ַƥ��
	*! \remarks ������ǰ��ı�׼�� ������ 
	*/
	UGbool MatchAddress(UGDatasetVector * pDtVector,UGString  strFieldName,UGString strZip, UGString strNewDtName ,UGProgress * pProgres = NULL );

	/*!	\brief	�Զ��Ƴ��������ݼ� �����ڵ�����������ʹ��	*/
	UGbool RemoveIndexDt();


	/*!	\brief	���õ�ַ�����ֺ����ͣ�����ͬʱ���ò���Ч	
	  *	\param nLanguageType	��ַ����
	  *	\param nAddressType		����
	  */
	UGbool SetType(UGint nLanguageType , UGint nAddressType);

//---------------------------------------------------------------	
	/*!	\brief	���ñ�׼���ؼ��ֱ� */
	UGbool SetDatasetCLS(UGDatasetVector* pDtCLS);	
	/*!	\brief	��ȡ��׼���ؼ��ֱ�*/
	const UGDatasetVector* GetDatasetCLS();

	/*!	\brief	����Word�ֶ�*/
	UGbool SetCLSWordField(UGString strCLSWord);
	/*!	\brief	��ȡWord�ֶ�*/
	UGString GetCLSWordField();

	/*!	\brief	����Abbreviation�ֶ�*/
	UGbool SetCLSAbField(UGString& strCLSAb);
	/*!	\brief	��ȡAbbreviation�ֶ�*/
	UGString GetCLSAbField();

	/*!	\brief	����CLSType�ֶ�*/
	UGbool SetCLSTypeField(UGString& strCLSType);
	/*!	\brief	��ȡCLSType�ֶ�*/
	UGString GetCLSTypeField();

	// �ؽ��ʵ���
	UGbool ReBuildDicTree() ;

	/*!	\brief	��ȡ��ַ��׼���ֶθ���  */
	UGint GetAddStanFieldNameCount();

	/*!	\brief	��ȡ��ַ��׼���ֶ���	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetAddStanFieldName(UGint nIndex );

	/*!	\brief	��ȡ��ַ��׼���ֶ�ֵ	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetAddStanFieldValue(UGint nIndex );

	/*!	\brief	���õ�ַ��׼���ֶ�ֵ	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  *	\param strValue	�ֶ�ֵ
	  */
	UGbool SetAddStanFieldValue(UGint nIndex,UGString strValue );
	
	/*!	\brief	��ȡ��ַ��׼���ֶ�ֵ	
	  *	\param strFieldName	
	  */
	UGString GetAddStanFieldValue(UGString strFieldName );

	/*!	\brief	���õ�ַ��׼���ֶ�ֵ	
	  *	\param strValue	�ֶ�ֵ
	  */
	UGbool SetAddStanFieldValue(UGString strFieldName ,UGString strValue );

//---------------------------------------------------------------	
	// ��Щ�������Ƕ��ֶεĲ���/��������Է�װ��:
	// Private Const m_ToLeft = "L_t_add"
	// geo.MatchVariableField("FromLeft") = m_FromLeft����ʽ

	/*!	\brief	���û�׼��ַ */
	UGbool SetDatasetReference(UGDatasetVector* pDtReference);	
	/*!	\brief	��ȡ��׼��ַ*/
	const UGDatasetVector* GetDatasetReference();

	
	/*!	\brief	��ȡ��׼��ַ�����ֶθ��� --> (MO) MathchVariableCount */
	UGint GetVariableFieldNameCount();

	
	/*!	\brief	��ȡ��׼��ַ�����ֶ���	--> (MO) MathchVariable
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetVariableFieldName(UGint nIndex );

	
	
	/*!	\brief	��ȡ��׼��ַ�����ֶ�ֵ	--> (MO) MathchVariableField
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetVariableFieldLink(UGint nIndex );

	/*!	\brief	���û�׼��ַ�����ֶ�	--> (MO) MathchVariableField
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  *	\param strValue	�ֶ�ֵ
	  */
	UGbool SetVariableFieldLink(UGint nIndex,UGString strValue );
	
	
	
	/*!	\brief	��ȡ��׼��ַ�����ֶ�ֵ	--> (MO) MathchVariableField
	  *	\param strFieldName	
	  */
	UGString GetVariableFieldLink(UGString strFieldName );

	/*!	\brief	���û�׼��ַ�����ֶ�ֵ	--> (MO) MathchVariableField
	  *	\param strValue	�ֶ�ֵ ����:��SM_GEOCODE_USSTREET_FROMLEFT��Ӧ�ֶ���Ϊ'fromleft'
	  */
	UGbool SetVariableFieldLink(UGString strFieldName ,UGString strValue );
	

	/*!	\brief	�Ƿ���Ч	 */	
	UGbool IsValid();

	
	/*!	\brief	����UGAddressStandardize�еķ���	 */	
	UGbool StandardizeAddress(UGString  strAddress);

//---------------------------------------------------------------	
	
	
	/*!	\brief	��ȡ��׼��ַ�������ݼ�	  */
	UGDatasetVector * GetIndexDt();

	/*!	\brief	���û�׼��ַ�������ݼ�	  */
	UGbool SetIndexDt(UGDatasetVector * pIndexDt );

	
	/*!	\brief	������Щ��ӽ����������ݼ� 
	  *	\param strValue	strArrFieldsName[0]�������� ��Ҫ���������� �����ֶν�ֱ�ӿ��������������ݼ�
	  *	\param strValue	strArrFieldsName�е��ַ���������m_strArrFieldValue�е��ַ��� 
	  */
	UGbool SetIndexField(const UGStrArray & strArrFieldsName);

	
	// ���úͻ�ȡ��С����
	UGbool SetMinMatchScore(UGint nMinMatchScore );
	UGint GetMinMatchScore();

	// ���ñ�ƫ��
	UGbool SetOffset(UGdouble dOffset );
	UGdouble GetOffset();

	// ����ĩ��ƫ��
	UGbool SetEndOffset(UGdouble dEndOffset  );
	UGdouble GetEndOffset();

	UGbool GetResultLocation(UGArray<SmAddressLocation> & arrLocation);



private:
// ����ƥ��Ľӿ��ǲ������ ��ʱ�� ���ڷ��


	/*!	\brief	����ƥ�� ����ID�� 
	*! \remarks �����ݵ�ַ���͵��ò�ͬ˽�нӿ�
	*! \remarks ���е�һ��������m_AddStamd��,�����лὫm_nArrIndexMatchIDs���,Ȼ��д��!
	*/
	UGbool MatchIndex();

	/*!	\brief	������ƥ������ļ�¼ID���н�һ����ƥ�� 
	*! \remarks ������е÷�(Composite Score��Point����Ϣ)
	*/
	UGbool MatchCandidate();

	/*!	\brief	��ȡ��׼��ַ�������ݼ�	  */
	UGbool GetIndexMatchID(UGArray<UGint> & nArrIndexMatchIDs);


	// ��ȡ����Դ�µ�һ���Ϸ����ݼ���
	UGbool GetValidDtName(UGDataSource * pDataSource ,UGString & strDtName);
	
	// Ϊһ�����ʻ�ȡ��Ӧ������
	UGbool GetIndexForWord(UGString & strWord ) ;
	
	// USStreet��������ƥ��
	UGbool USStreetMatchIndex() ;

	// �����û��趨��ַ �����֮��ƥ��ı�׼���ֶ����� ��:  FROMLEF<--->HN
	// �м������Ҫ��û�׼��ַ�ֶ�ֵ
	UGString GetAddressFieldNameByLink(UGString strVariableFieldLinkValue);

	// ���û����óɵ��ֶ����� ��û�׼�����е��ֶ�����
	UGString GetReferenceFieldNameByLink(UGString strVariableFieldLinkValue);

	// �ӻ�׼�����е��ֶ����� ����û����óɵ��ֶ����� 
	UGString GetAddressFieldNameByReferenceFieldName(UGString strAddressFieldName);

	// ���û�ȡԪ�ص�M��Uֵ
	UGdouble GetUnMatchValue( UGString strFieldName );
	UGbool SetUnMatchValue( UGString strFieldName,UGdouble dUValue );

	UGdouble GetMatchValue( UGString strFieldName );
	UGbool SetMatchValue( UGString strFieldName, UGdouble dUValue );

	// ������ͺ���߷��� ��NormalizeScore����
	UGbool CountMaxAndMinScore();

	// ������ͳһ��0��100 ʹ�õ���m_dMaxScore��m_dMinScore
	UGint NormalizeScore(UGdouble dScore);

	// ȥƥ�����е�һ����¼ 
	// ������¼����Ϣ�洢�� strArrAddressElem �У�������m_strArrVariableFieldName���д洢
	// �����ղ�ͬ��ַ���͵���MatchUSStreetAddress ��
	UGbool MatchOneAddress(UGStrArray strArrRefFieldValue,SmAddressLocation & location);
	
	// ȥƥ�����е�һ����¼ 
	// ������¼����Ϣ�洢�� strArrAddressElem �У�������m_strArrVariableFieldName���д洢
	UGbool MatchUSStreetAddress(UGStrArray strArrRefFieldValue,SmAddressLocation & location);
	
	// �� m_ArrLocationResult �в���һ����� ��֤ʱ�����
	UGbool InsertLocation(SmAddressLocation location);

	UGdouble GetScore(UGdouble dM,UGdouble dU,UGbool bMatch = TRUE );

	// һ���� m_strArrVariableFieldName ��ͬ�ṹ�ļ�¼ Ҫ��ȡ���е�ĳ���ֶ�
	UGString GetLinkValue(UGStrArray strArrRefFieldValue,UGString strFieldName );
	
	// ����2�����ƺ��� ���ƥ�����
	UGbool MatchHN(UGint nHN  ,UGint nFROM,UGint nTO , UGdouble & dPosPercent );

	// ��������λ�õİٷֱ�����ȡ��
	UGPoint2D FindPoint(UGGeoLine * pline,UGdouble dPosPercent,UGint nSide = SMSideNone) ;

	UGbool MatchUSStreetIntersection (UGString strAddress1,UGString strAddress2);
	UGbool GetSamePnt(UGGeoLine * pline1,UGGeoLine *pline2,UGPoint2D & pntSamePoint);
	
	
	// У��������ڵķ��� �ڽ�������� �Ѿ������ƴ���Ϊ�Ƿ�������-100��
	UGint GetIntersectionScore(UGint nScore1,UGint nScore2);

	// ֻ�Ǳ����ַ����е���ĸ
	UGbool GetLetters(UGString & str);

private:
	
	//! \brief ��ַ��׼��˽�б���
	//! \remarks m_AddStamd�е���������뱾���е��������һ��
	UGAddressStandardize m_AddStand ;

	//! \brief ��ַ�ֶ�Uֵ
	//! \remarks SM_GEOCODE_USSTREET_HN_U ��
	UGArray<UGdouble>  m_dArrUnMatchValue	;

	//! \brief ��ַ�ֶ�Mֵ
	//! \remarks SM_GEOCODE_USSTREET_HN_M ��
	UGArray<UGdouble> m_dArrMatchValue	;

	//! \brief ��ַ����
	//! \remarks ��ʱ֧�����ġ�Ӣ�ģ�Ϊ�Ժ�ӿ���չ
	UGint m_nLanguageType	;
	
	//! \brief ��ַ����
	//! \remarks �ֵ���С��������
	UGint m_nAddressType	;

	//! \brief ��ַ�ֶ�����
	//! \remarks SM_GEOCODE_USSTREET_FROMLEFT��SM_GEOCODE_USSTREET_FROMRIGHT��
	UGStrArray m_strArrVariableFieldName	;

	//! \brief ��׼��ַ�ֶ�ֵ
	//! \remarks Ҳ���ǽ���Щ�ֶδ������õ���׼��ַ�����Ӧ���ֶ�
	//! \remarks ���磺[SM_GEOCODE_USSTREET_TOLEFT] = "LEFT_TO"
	UGStrArray m_strArrVariableFieldLink	;

	//! \brief ��׼��ַ
	//! \remarks ��׼��ַ������ƥ��ı�׼��ַ
	UGDatasetVector  * m_pReferencDt ;

	//! \brief ����״̬
	UGint m_nIndexState	;
	
	//! \brief �������ֶ�����
	//! \remarks ���е������ֶ����ֱ�������m_strArrFieldValue��
	//! \remarks m_strArrIndexFieldName�еĵ�һ����ָ�ֶ���Ҫ����������
	UGStrArray m_strArrIndexFieldName	;

	//! \brief �������ݼ�
	UGDatasetVector * m_pIndexDt ;

	//! \brief ����ƥ������Ľ��ID��
	UGArray<UGint> m_nArrIndexMatchIDs;
	
	//! \brief ���ƥ����� ����0С��100 ȱʡΪ60��
	UGint m_nMinMatchScore	;
	
	//! \brief ��ַƥ����
	UGArray<SmAddressLocation> m_ArrLocationResult	;

	// ���ǰ���M��Uֵ�����������Сֵ ������һ���÷ֱ�׼����0��100֮��
	UGdouble m_dMaxScore	;
	UGdouble m_dMinScore	;

	// ��ʾ�������ֵ����������ƺ�����ռ�еķ��� �����ڽ�����ڵ�����
	UGdouble m_dUSStreetHNScore ;
	
	// ������ڱ�ʾ�� ÿ����ĸ����һ����ʶ��
	UGStrArray m_IntersectionSeparate ;
	
	// ��ƫ��
	UGdouble m_dOffset ;
	// ĩ��ƫ��
	UGdouble m_dEndOffset;

};


}// end of namespace

#endif

