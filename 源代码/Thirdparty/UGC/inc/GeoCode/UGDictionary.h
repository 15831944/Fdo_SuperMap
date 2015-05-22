/* 
	\file UGDictionary.h
	\brief ���ĵ�ַģ����ѯ�ʵ���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGDICTIONARY_H
#define UGDICTIONARY_H

#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"
#include "Base/UGFileStdio.h"   //�ļ�ͷ�ļ�

#include "UGGeoCodeDefine.h"
#include "UGFuzzySearchTypes.h"

namespace UGC {

class   GEOCODE_API UGDictionary  
{
public:

	UGDictionary();

    virtual ~UGDictionary();

	//!	\brief	���ڶ������ļ��Ĵʵ����뺯��
	//!	\param pcFileName �ʵ�����[in]
	//!	\param bReset	�Ƿ���������
	//!	\return ���شʵ�ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks	���������ļ�ת��Ϊ�ʵ�ṹ
	UGbool Load(const UGchar *pcFileName,UGbool bReset = FALSE);

	//!	\brief	������ת��Ϊ�ı��ļ�
	//!	\param pcFileName �ʵ�����[in]
	//!	\param sFileSavename ����ļ�����[in]
	//!	\param bReset �Ƿ���������[in]
	//!	\return ���ת���ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks �ʵ�����
	UGbool DictBinaryToTxt(UGchar *pcFileName,UGchar *sFileSavename,UGbool bReset=FALSE);

	//! \brief ׷���ı���ʽ�Ĵ���
    //! \param pcFileName �ı�����[in]
	//!	\return ���ת���ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks �ʵ�����
	UGbool AddWordItemsFromTxt(UGchar *pcFileName);

	//! \brief ɾ���ı���ʽ�Ĵ���
    //! \param pcFileName �ı�����[in]
	//!	\return ���ת���ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks �ʵ�����
	UGbool DelWordItemsFromTxt(UGchar *pcFileName);

	//!	\brief �ʵ�ϲ�
	//!	\param dict2	�����ֵ�����[in]
	//!	\return ����ʵ�ϲ��ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks �ϲ��ʵ�
	UGbool Merge(UGDictionary &DictMerge);

	//!	\brief	�õ�����Ƶ��
	//! \param pcWord �������[in]
	//! \return ���ش���Ƶ�ʣ�����ʵ�û���������,�ͷ���0
	UGint GetFreq( UGchar *pcWord);

	//!	\brief	�Ҵ���
	//!	\param pcWord �������[in]
	//!	\return �ҵ����ﷵ��TRUE�����򷵻�FALSE
	UGbool IsGetWord(UGchar *pcWord);

	//!	\brief	�Ҵ���
	//!	\param pcWord �������[in]
	//!	\return �ҵ����ﷵ�����������򷵻�-1
	UGint IsContainWord(UGchar *pcWord);

	//!	\brief	�õ�����Ƶ��
	//! \param pcWord �������[in]
	//! \return ���ش���Ƶ�ʣ�����ʵ�û���������,�ͷ���0
	UGint GetSameWordCount( UGchar *pcWord);

	//!	\brief	���ش����ܵĸ���
	//! \return ���شʵ��д����ܵĸ���
	UGint GetWordCount( );

	//!	\brief	���شʵ�ĳ��λ���ϵĴ�����Ϣ
	//!	\param  nIndex �����ڴʵ��е�λ�ã�ȡֵ��ΧΪ[0,nCount-1]��nCount=GetWordCount( )[in]
	//!	\param  strWord		�����϶�Ӧ�Ĵ���[Out]
	//!	\param  nFrequency	����Ƶ����Ϣ[Out]
	//! \return ��nIndex����ȡֵ��Χ�ڣ��򷵻�false��
	UGbool GetWord( UGint nIndex,UGString & strWord,UGint&nFrequency);

	//!	\brief	���ش���
	//!	\param pcWord ����ָ��[in]
	//!	\param nFrequency ����Ƶ����Ϣ[in]
	//!	\return ���ش���ɹ�����TRUE�����򷵻�FALSE
	UGbool AddItem(UGchar *pcWord,UGint nFrequency);

	//!	\brief	���ش���
	//!	\param pcWord ����ָ��[in]
	//!	\return ���ش���ɹ��������������򷵻�-1��
	UGint AddItem(UGchar *pcWord);

	//!	\brief	�Ҵ��������
	//!	\param pcWord ����ָ��[in]
	//!	\return ����ɹ��������������򷵻�-1��
	UGint GetWordnIndex(UGchar *pcWord);

	//!	\brief	ɾ������
	//!	\param pcWord	����[in]
	//!	\return ɾ������ͷ���TRUE�����򷵻�FALSE
	UGbool DelItem(UGchar *pcWord);

	//!	\brief	�ʵ䱣��
	//!	\param pcFileName �ʵ�����[in]
	//!	\return �ɹ�����ʵ�ͷ���TRUE�����򷵻�FALSE
	UGbool SaveAs(UGchar *pcFileName);

	//!	\brief	�ʵ䱣���ı���ʽ
	//!	\param pcFileName �ʵ�����[in]
	//!	\return �ɹ�����ʵ�ͷ���TRUE�����򷵻�FALSE
	UGbool SaveAsTxt( UGchar *pcFileName ,UGbool bStandard = TRUE);

	//////////////////////////////////////////////////////////////////////////
	//�������

	//!	\brief	�����ı��ļ��Ĵʵ����뺯��
	//!	\param pcFileName �ʵ�����[in]
	//!	\param bReset	�Ƿ���������
	//!	\return ���شʵ�ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks	���������ļ�ת��Ϊ�ʵ�ṹ
	UGbool LoadFromTxt(const UGchar *pcFileName,UGbool bReset = FALSE);
	
	//!	\brief	�ı��ļ�ת��Ϊ������
	//!	\param pcFileName �ʵ�����[in]
	//!	\param sFileSavename ����ļ�����[in]
	//!	\param bReset �Ƿ���������[in]
	//!	\return ���ת���ɹ�����TRUE�����򷵻�FALSE
	//!	\remarks �ʵ�����
	UGbool DictTxtToBinary(UGchar *pcFileName,UGchar *sFileSavename,UGbool bReset=FALSE);

	//!	\brief	�ʵ䱣���ı���ʽ
	//!	\param pcFileName �ʵ�����[in]
	//!	\return �ɹ�����ʵ�ͷ���TRUE�����򷵻�FALSE
	UGbool SaveAsStandardTxtForm( UGchar *pcFileName );

	//!	\brief	�õ�����Ƶ��
	//! \param pcWord �������[in]
	//! \return ���ش���Ƶ�ʣ�����ʵ�û���������,�ͷ���0
	UGbool AddUseCount( UGchar *pcWord);

private:

	//!	\brief			�ж��ַ�������
	//!	\param sChar ����ָ��[in]
	//!	\return �����ַ�������
	//!	\remarks ʹ����ֻҪѭ�����øýӿ� �Ϳ�����
	UGint GetCharType( UGuchar *pucChar);

	//!	\brief  �õ���������
	//!	\param pcWord ����[in]
	//!	\return ���ش�������
	UGint  GetWordType(UGchar *pcWord);

	//!	\brief			�ж��Ƿ��Ǻ���
	//!	\param sString	�жϵ��ַ���ָ��[in]
	//!	\return ������Ǻ��־ͷ���TRUE�����򷵻�FALSEe
	UGbool IsAllChinese(UGuchar *pucString);

	//!	\brief	            �Һ���
	//!	\param pucString	    Ŀ�괮ָ��[in]
	//!	\param pstrCharSet	Դ��[in]
	//!	\return �����Ƿ���Դ���п�ʼ��ָ��
	UGchar *CCFind(const UGchar *pucString, const UGchar *pstrCharSet);

	//!	\brief	�ֵ��Ż�
	//!	\return ����Ż��ʵ�ͷ���TRUE�����򷵻�FALSE
	void Optimum();

	//!	\brief	����Ԥ����
	//!	\param pcWord ����[in]
	//!	\param nId ����λ��[out]
	//!	\param sWordRet ȥ���׺��ֵĴ���ָ��[out]
	//!	\return ����ҵ���ص�λ�þͷ���TRUE�����򷵻�FALSE
	//!	\remarks	����Ԥ����ȥ���׺��ֵĴ���ָ��
	UGbool PreProcessing(UGchar *pcWord,UGint *pnId,UGchar *pcWordRet,UGbool bAdd=FALSE);
	
private:
	//!	\brief �ʵ�����������
	INDEX_TABLE   m_IndexTable[UG_GEOCODE_CC_NUM];

protected:
	
	//!	\brief	��ԭʼ���в�ѯ����
    //!	\param nInnerCode ��������λ��[in]
	//!	\param pcWord ������Ϣ[in]
	//!	\return ������ҵ��ͷ���TRUE�����򷵻�FALSE
	//!	\remarks	�ڴʵ���в�ѯ�ĺ���
	UGbool FindInOriginalTable(UGint nInnerCode,UGchar *pcWord,UGint *pnPosRet=0);
};

}

#endif
