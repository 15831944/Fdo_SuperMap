#ifndef UGADDRESSSTANDARDIZE_H
#define UGADDRESSSTANDARDIZE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGQueryDef.h"


#include "UGGeoCodeDefine.h"

/*!
   **************************************************************************************
    \file     UGAddressStandardize.h
   **************************************************************************************
    \author   ����������
    \brief    ��ַ��׼����                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1997-2006 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2006-06-21  ����    ��ʼ���汾.       ��ʵ��Ӣ�Ľֵ���ַ��׼��          <br>
   **************************************************************************************
   
   **************************************************************************************
   ********							�޸ļ�¼									*********
   **************************************************************************************
   2006-06-29	����	��ɵ�ַ����(��֧��Ӣ�Ľֵ���ַ����Ԥ���ӿ�),�Ƚ�ArcMapʵ��
   **************************************************************************************
*/


namespace UGC {
	
/* �ʵ������*/
struct DicTreeNode
{
	UGchar m_ch				;				// �ý��������ĸ
	DicTreeNode * pRChild	;				// �ֵܽ�� 
	DicTreeNode * pLChild	;				// ���ӽ�� 
	UGString m_strAb		;				// ��׼������
	UGString m_strWordType	;				// �õ��ʵ�����
	UGbool m_bIsEndNode		;				// �ɷ���Ϊ������

};

/* �ʵ��� ���ڶԵ��ʵĿ��ټ���*/
class GEOCODE_API UGDictionaryTree
{
	/*	�ʵ��������ԭ��
	 *	�ʵ����У�һ�����������������ӣ���ô�����Ǹý��ĺ�һ����ĸ
	 *	�ʵ����У�һ���������������Һ��ӣ���ô�Һ�����ý������ͬ�ĵ���ǰ׺
	 *	����:
	 *						A
	 *					   / \ 	
	 *					  C	  D
	 *					 / \  /	
	 *					E   F G
	 *	���ڸ���:	D��A���Һ��ӣ���ôA��D����ͬ��ǰ׺(����Ϊ��)	F��C��ǰ׺ ˵���е������AC������AF����				
	 *				E��C�����ӣ���ôE��ǰ׺����C���򹹳ɵ���ACE.		
	 *	����ÿ����㶼�н������� ��ô�����е���:ACE��AC��A��AF��DG			
	 */
	
public:

	UGDictionaryTree();
	virtual ~UGDictionaryTree();


	/*!	\brief			�������һ���µĵ���
	*	\param strWord	��ӵĵ���
	*	\remarks		ʹ����ֻҪѭ�����øýӿ� �Ϳ�����
	*/
	UGbool AddNewWord( UGString  strWord ,UGString strAb ,UGString strType);

	/*!	\brief			�鵥�ʱ�
	*	\param strWord	���ҵĵ���
	*	\return			���ظõ��ʵ����һ����㣻���û���ҵ� ����null
	*/
	DicTreeNode * FindWord( UGString  strWord );
	
private:

	/*!	\brief	��ȡһ���µĽ��	
	*	\param ch	�ý�����������ĸ
	*/
	DicTreeNode * GetNewNode( UGchar ch );

	/*!	\brief	���Һ����в��ҽ��
	*	\param ch	���븸�׽��
	*	\param ch	����Ҫ���ҵ���ĸ
	*	\remarks	�÷�������һ�����У�֪��һ����㣬˳����Ҹý������ұߺ���
	*/
	DicTreeNode * FindNodeFromRChild(DicTreeNode * pParent ,UGchar ch ,UGbool bAddNewWhenFaild = FALSE );

	/*!	\brief			ɾ��һ����㼰�����еĺ��� 	*/
	UGbool DeleteNodeAndChild( DicTreeNode * pDicTreeNode );

private:
	DicTreeNode * m_pRoot ;		// �����

};

class GEOCODE_API UGAddressStandardize  
{
public:

	/*!	\brief ��ַ���� */
	enum SmLanguageType
	{
		SMChinese	= 1,			// ����
		SMEnglish	= 2				// Ӣ��
	};

	/*!	\brief ��ַ���� */
	enum SmAddressType
	{
		SMStreet	= 1,			// �ֵ�
		SMZone		= 2				// С��
	};

	UGAddressStandardize();
	virtual ~UGAddressStandardize();
	

	/*!	\brief	��ַ��׼���ӿ�	
	  *	\param strAddress	�����ַ�� ����: 380 New York
	  *	\remarks �ڵ��øýӿ�ǰ�����������õ�ַ�����ࡢ�����Լ���׼��ַ��
	  *	\remarks �����ṹ���洢��m_strArrFieldValue��
	  *	\remarks ��֧�ֽ������������ʽ ���ⲿ����Ȼ���뼴��
	  */
	UGbool StandardizeAddress(UGString  strAddress);

	/*!	\brief	������ַ��׼���ӿ�	
	  *	\param pDtVector	��Ҫ��׼�������ݼ�
	  *	\param strFieldName	��׼�����ֶ�����
	  *	\param strNewDtName	�洢��������ݼ������ƣ����Ϊ�� �����ֱ��д�뵽pDtVector��
	  *	\remarks ��֧�ֽ������������ʽ ���ⲿ����Ȼ���뼴��
	  */
	UGbool StandardizeAddress(UGDatasetVector * pDtVector,UGString  strFieldName, UGString strNewDtName = "");

	// �ؽ��ʵ���
	UGbool ReBuildDicTree();

	UGbool GetResult(UGString & strResult ) ;



	/*!	\brief	���ñ�׼���ؼ��ֱ� */
	UGbool SetDatasetCLS(UGDatasetVector* pDtCLS);	
	/*!	\brief	��ȡ��׼���ؼ��ֱ�*/
	const UGDatasetVector* GetDatasetCLS()const;

	/*!	\brief	����Word�ֶ�*/
	UGbool SetCLSWordField(const UGString& strCLSWord);
	/*!	\brief	��ȡWord�ֶ�*/
	const UGString GetCLSWordField()const;

	/*!	\brief	����Abbreviation�ֶ�*/
	UGbool SetCLSAbField(const UGString& strCLSAb);
	/*!	\brief	��ȡAbbreviation�ֶ�*/
	const UGString GetCLSAbField()const;

	/*!	\brief	����CLSType�ֶ�*/
	UGbool SetCLSTypeField(const UGString& strCLSType);
	/*!	\brief	��ȡCLSType�ֶ�*/
	const UGString GetCLSTypeField()const;

	/*!	\brief	���õ�ַ�����ֺ����ͣ�����ͬʱ���ò���Ч	
	  *	\param nLanguageType	��ַ����
	  *	\param nAddressType		����
	  */
	UGbool SetType(UGint nLanguageType , UGint nAddressType);

	/*!	\brief	��ȡ��ַ�ֶθ���  */
	UGint GetFieldNameCount();

	/*!	\brief	��ȡ��ַ�ֶ���	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetFieldName(UGint nIndex );

	/*!	\brief	��ȡ��ַ�ֶ�ֵ	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  */
	UGString GetFieldValue(UGint nIndex );

	/*!	\brief	���õ�ַ�ֶ�ֵ	
	  *	\param nIndex	�ֶ��������� ������������� 0��FieldNameCount֮��
	  *	\param strValue	�ֶ�ֵ
	  */
	UGbool SetFieldValue(UGint nIndex,UGString strValue );
	
	/*!	\brief	��ȡ��ַ�ֶ�ֵ	
	  *	\param strFieldName	
	  */
	UGString GetFieldValue(UGString strFieldName );

	/*!	\brief	���õ�ַ�ֶ�ֵ	
	  *	\param strValue	�ֶ�ֵ
	  */
	UGbool SetFieldValue(UGString strFieldName ,UGString strValue );
	

	/*!	\brief	�Ƿ���Ч	 */	
	UGbool IsValid();

	// �����ݼ��л�ȡһ���Ϸ������ݼ�����
	UGbool GetFieldValidName(UGDatasetVector * pDtVector ,UGString & strFieldName);


private:
	// USStreet��ʽ����
	UGbool USStreetStandardize(UGString  strAddress);
	
	// �ӵ���strAddress�л�ȡ���� ���ؾ��Ǹ����� ���û������ �ͷ��ؿ��ַ���
	UGString GetNumeric(UGString  strAddress);

	// �жϴ���������Ƿ��ǹؼ������� ����T��A��
	UGbool IsAddressKeyElem(UGString strType);

	// �жϴ���������Ƿ��Ƿ���ؼ�������
	UGbool IsDirectionElem(UGString strType);

	// �жϴ���������Ƿ������͹ؼ�������
	UGbool IsTypeElem(UGString strType);


	// Ԥ��׼��
	UGbool PreStand(UGString  & strAddress) ;

	// ���ڴ��� ��Ҫ�Ƕ���Щ�����ַ���д��� �ڱ�׼����ʹ�� strAddress���Ǳ�׼����ʱ����ĵ���
	UGbool SufStand(UGString   strAddress) ;

	// ����m_nArrPos���� ���� ��PT��ֵΪstreet �������m_nArrPos[1] = 2 (2��ʾ����m_strArrSplitWord�ڶ�������)
	UGbool SetFieldPos(UGString strFieldName,int nPos);
	UGint GetFieldPos(UGString strFieldName);



private:
	
	//! \brief ��ַ����
	//! \remarks ��ʱ֧�����ġ�Ӣ�ģ�Ϊ�Ժ�ӿ���չ
	UGint m_nLanguageType	;
	
	//! \brief ��ַ����
	//! \remarks �ֵ���С��������
	UGint m_nAddressType	;

	//! \brief ��ַ�ֶ�����
	//! \remarks "SN"��"ST"��
	UGStrArray m_strArrFieldName	;

	//! \brief ��ַ�ֶ�ֵ
	//! \remarks "380"��"New York"��
	UGStrArray m_strArrFieldValue	;
	
	//! \brief ��ַ���ո�ֿ������Ч���ֱ��� ������ �ڲ�ʹ��(���ڴ����ʱ��ʹ��)
	//! \remarks ���ﱣ��ĵ�ַ��û�о�����д��׼���� 
	UGStrArray m_strArrSplitWord	;

	//! \brief ��������ĵ�ַԪ����m_strArrSplitWord�е�λ�� �ڲ�ʹ��(���ڴ����ʱ��ʹ��)
	UGArray<UGint> m_nArrPos		;

	//! \brief ��ַ�ؼ��ʽ�����
	//! \remarks �ؼ��ʱ���Ҫ�������ֶ�:һ�㵥��(word)����д(Abbreviation)���ؼ�������(Type)
	UGDatasetVector   * m_pDtCLS;
	UGString	 m_strCLSWordField	;		// �ؼ��ʽ������еĵ����ֶ�
	UGString	 m_strCLSAbField	;		// �ؼ��ʽ������е���д�ֶ�
	UGString	 m_strCLSTypeField	;		// �ؼ��ʽ������е������ֶ�

private:
	UGDictionaryTree * m_pDicTree	;		// ˽�еĴǵ���
	UGbool		 m_bReBuildDicTree  ;		// �Ƿ���Ҫ�ؽ��ʵ���


};

/* �������뷨
 * дһ����ַ�࣬�����������������ַ�����࣬���ڿ���	
 */

}// end of namespace

#endif

