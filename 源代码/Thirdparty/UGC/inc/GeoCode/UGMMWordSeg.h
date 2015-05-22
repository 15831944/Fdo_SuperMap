/* 
	\file UGDictionary.h
	\brief ���ĵ�ַģ���ִ���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGMMWORDSEG_H
#define UGMMWORDSEG_H

#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"
#include "Base/UGFileStdio.h"


namespace UGC {

	class UGDictionary;
	
	class GEOCODE_API UGMMWordSeg
	{
	public:

		UGMMWordSeg();
		
        virtual ~UGMMWordSeg();
		
		//!	\brief ���÷ִ���Ҫ�Ĵʵ�
		//!	\param DictCoreMM �ִ���Ҫ�Ĵʵ�[in]
		//!	\return ���óɹ�����TRUE,���򷵻�FALSE
		UGbool SetDict(UGDictionary &DictCoreMM);

		//!	\brief	�ַ���������䷨�ִʺ���	
		//!	\param StringSrc �ַ���[in]
		//!	\return ���طִʺ�Ľ���ַ���
		//!	\remarks ��һ���ַ�������������䷨�ִʺ���
		UGString SegmentHzStrMM ( UGString StringSrc); 
		
		//!	\brief  ����������䷨�ִʺ���
		//!	\param StringSrc �ַ���[in]
		//!	\return ���طִʺ�Ľ���ַ���
		//!	\remarks	        �Ծ��ӽ������ƥ�䷨�ִʴ���ĺ���
		UGString SegmentSentenceMM ( UGString StringSrc);   
		
	private:
		//!	\brief ���ƥ�䷨�ֵ�
		UGDictionary *m_pdictCoreMM; 
		
	};
	
	class GEOCODE_API UGMPWordSeg
	{
	public:
		UGMPWordSeg();
		
        virtual ~UGMPWordSeg();

		//!	\brief ���÷ִ���Ҫ�Ĵʵ�
		//!	\param DictCoreMP �ִ���Ҫ�Ĵʵ�[in]
		//!	\return ���óɹ�����TRUE,���򷵻�FALSE
		UGbool SetDict(UGDictionary &DictCoreMP);

		//!	\brief	�ַ���������䷨�ִʺ���	
		//!	\param StringSrc �ַ���[in]
		//!	\return ���طִʺ�Ľ���ַ���
		//!	\remarks ��һ���ַ�������������䷨�ִʺ���
		UGString SegmentHzStrMM ( UGString StringSrc); 
		
		//!	\brief  ����������䷨�ִʺ���
		//!	\param StringSrc �ַ���[in]
		//!	\return ���طִʺ�Ľ���ַ���
		//!	\remarks	        �Ծ��ӽ������ƥ�䷨�ִʴ���ĺ���
		UGString SegmentSentenceMM ( UGString StringSrc);   

		//!	\brief �����ʷ��ִʺ���
		//!	\param StringSrc Ŀ�괮[in]
		//!	\return ���طִʴ������ַ���
		//!	\remarks �����ʷ��ִʺ���
		UGString SegmentHzStrMP(UGString StringSrc);
		
		//!	\brief ���������ʷ��ִʴ���ĺ���
		//!	\param StringSrc Ŀ�괮[in] 
		//!	\return ���طִʴ������ַ��� 
		//!	\remarks �Ծ��ӽ��������ʷ��ִʴ���ĺ��� 
		UGString SegmentSentenceMP(UGString StringSrc);
		
		//! \brief ���ִ���ԭ���и��
		//!	\param StringSrc  �����ַ���[in]
		//!	\return ���غ��ִַʽ������ÿ�������п���
		//!	\remarks ע����ǷǺ��ֲ����������һ��Ͳ��з���
		UGString CHWordAtomSegment(UGString StringSrc);

		//! \brief �ַ�����ԭ���и�
		//!	\param StringSrc  �ַ���[in]
		//!	\return �ַ�����ԭ���и���зֽ��
		//!	\remarks ע����ǷǺ��ֲ����������һ��Ͳ��з���
		UGString AtomSegment (UGString StringSrc);

		UGbool IsInDict(UGString StringSrc);

	private:

		//!	\brief ��ȡ���к�ѡ�ʵĺ����������ʷ��ִʳ������
		//!	\param StringSrc Ŀ�괮[in]
		//!	\return ���ش�����ַ���
		//!	\remarks ��ȡ���к�ѡ�ʵĺ����������ʷ��ִʳ������
		UGshort GetTmpWords(UGString StringSrc);
		
		//!	\brief �����ѡ�ʵ����ǰ���ʵĺ���
		//!	\param nPos	���������λ��[in]
		//!	\remarks �����ѡ�ʵ����ǰ���ʵĺ���
		void GetPrev(UGint nPos);

	private:
		//!	\brief�����ʷ���Ҫ�ķִʴʵ�
		UGDictionary *m_pdictCoreMP; 

	};
}

#endif
