/*! \file	 UGFieldInfo.h
 *  \brief	 �ֶ���Ϣ��
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGFieldInfo.h,v 1.7 2007/10/16 06:56:44 liwl Exp $
 */

#ifndef UGFIELDINFO_H
#define UGFIELDINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"

namespace UGC {

class ENGINE_API UGFieldInfo  
{
public:
	//! �ֶ�����
	enum FieldType
	{
		Boolean = 1,
		Byte = 2,
		Integer = 3,
		Long = 4,
		Currency = 5,
		Single = 6,
		Double = 7,
		Date = 8,
		Binary = 9,
		Text = 10,
		LongBinary = 11,
		Memo = 12,
		GUID = 15,
		BigInt = 16,
		VarBinary = 17,
		Char = 18,
		Numeric = 19,
		Decimal = 20,
		Float = 21,
		Time = 22,
		TimeStamp = 23,

		//��ӿ��ֽ� 20070323
		NVarChar =127,
		Geometry = 128,
		DgnLink = 129,
	};

public:
	UGFieldInfo();
	~UGFieldInfo();
public:
	
	//! �ж��ֶ��Ƿ�ɸ���
	UGbool CanUpdate();

	//! �ж��Ƿ���SuperMapϵͳ�ֶ�
	UGbool IsSystemField();

	//! �ж��Ƿ��Ǽ��ζ����ֶ�
	UGbool IsGeoField();

	//! �ж��Ƿ��������
	UGbool IsContainIndex(){
		return !m_strIndexTab.IsEmpty(); 
	}
public:
	//! �ֶ�����
	UGString m_strName;

	//! �ֶ�����
	FieldType m_nType;

	//! �ֶδ�С
	UGint m_nSize;
	
	//! �ֶ�����
	UGint m_nAttributes;
	
	//! �ֶ����λ��
	UGint m_nOrdinalPosition;

	//! �Ƿ��Ǳ����ֶ�
	UGbool m_bRequired;
	
	//! �ֶγ����Ƿ�����Ϊ��
	UGbool m_bAllowZeroLength;
	
	//! m_nCollatingOrder,��δʹ��
	UGint m_nCollatingOrder;

	//! ����
	UGString m_strForeignName;

	//! Դ�ֶ���
	UGString m_strSourceField;

	//! Դ����
	UGString m_strSourceTable;

	//! m_strValidationRule,��δʹ��
	UGString m_strValidationRule;

	//! m_strValidationText,��δʹ��
	UGString m_strValidationText;

	//! Ĭ��ֵ
	UGString m_strDefaultValue;

	//! �̶�
	UGint m_nScale;
	
	//! ����
	UGint m_nPrecision;

	//! ��ʽ
	UGString m_strFormat;

	//! ������Ϣ
	UGString m_strDomain;

	//! �Ƿ�ɱ༭
	UGbool m_bUpdatable;

	//! ����������
    UGString m_strIndexTab;
		
};

class ENGINE_API UGFieldInfos:public UGArray<UGFieldInfo> 
{
public:
	UGString ToXML() const;	
	
	UGbool AddField(						//����ֶ�
		const UGString& strName,				//�ֶ����ƣ�ע���ֶ����Ƶ�ǰ�����ַ�����ʹ�á�Sm���������κδ�Сд��ʽ�����򱾺����ܾ����벢����FALSE
		UGFieldInfo::FieldType nType,					//�ֶ����ͣ��ο�MFC�������� CDaoFieldInfo ����
		UGint lSize,						//��С
		UGint lAttributes = 0,			//���ԣ�Ĭ��Ϊ0
		UGbool bRequired = FALSE,			//�Ƿ���븳ֵ����Ϊ�գ�
		UGbool bAllowZeroLength = TRUE,	//�Ƿ񳤶ȿ���Ϊ0
		UGString strDefaultValue=(""),	//Ĭ��ֵ
		UGString strIndexTabName = ("")	//Ĭ��Ϊ��	 
		)
	{
		UGFieldInfo fieldinfo;
		fieldinfo.m_strName = strName;
		fieldinfo.m_nType = nType;
		fieldinfo.m_nSize = lSize;
		fieldinfo.m_nAttributes = lAttributes;
		fieldinfo.m_bRequired = bRequired;
		fieldinfo.m_bAllowZeroLength = bAllowZeroLength;
		fieldinfo.m_strDefaultValue = strDefaultValue;
		fieldinfo.m_strIndexTab = strIndexTabName;
		return Add(fieldinfo);
	}
};

}

#endif


