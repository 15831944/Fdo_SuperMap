// UGMapStorage.h: interface for the UGMapStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapStorage.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ͼXML�ַ����洢�ࡣ                                                
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_)
#define AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_

#include "Base/UGString.h"

namespace UGC {
class WORKSPACE_API UGMapStorage  
{
public:
	UGMapStorage();
	virtual ~UGMapStorage();
	UGMapStorage& operator = (const UGMapStorage& storage);

public:
	//========================================================
	//! \brief 		�����޸ı�ʶ��
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;

	//========================================================
	//! \brief 		�õ���ͼ���ơ�
	UGString GetName()const;
	//========================================================
	//! \brief 		���õ�ͼ���ơ�
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		�õ���ͼ��ϢXML�ַ�����
	UGString GetXML()const;
	//========================================================
	//! \brief 		���õ�ͼ��ϢXML�ַ�����
	void SetXML(const UGString& strXML, UGint nVersion = 0);
	//========================================================
	//! \brief 		�õ���ͼ�汾��
	UGint GetVersion()const;
	
protected:
	//! \brief 		�޸ı�ʶ��
	UGbool m_bModified;
	//! \brief 		��ͼ��ϢXML�ַ�����
	UGString m_strXML;
	//! \brief 		��ͼ���ơ�
	UGString m_strName;
	//! \brief 		��ͼ�汾��
	UGint m_nVersion;
};

}

#endif // !defined(AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_)
