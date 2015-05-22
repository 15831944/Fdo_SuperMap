
/*!
    **************************************************************************************
     \file     UGFileParse.h
    **************************************************************************************
     \author   ����
     \brief    �ļ���������                 
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"




namespace UGC {

class FILEPARSER_API UGFileParse  
{
public:
	UGFileParse();
	virtual ~UGFileParse();

public:

	//! \brief ������ʱ·��
	virtual void SetTempPath(const UGString& strTempPath);

	//! \brief	���õ����İ汾
	virtual void SetImportVersion(UGint nVersion);

	//! \brief	����һ�������Ĳ���������������ĸ�ʽ���û��Զ��������
	virtual void SetOneParam(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);
public:


	//////////////////////////////////////////////////////////////////////////
	// ��ȡ����
	//////////////////////////////////////////////////////////////////////////

	//! \brief ׼����ȡһ�������ļ�
	virtual UGbool OpenForRead(const UGString& strFileName);

	//! \brief �õ�ͼ�����Ŀ
	virtual UGint GetLayerCount();
	
	//! \brief �õ�ָ����ŵ�ͼ����Ϣ��
	virtual UGbool GetLayerInfo(UGint nIndex, UGString& strLayerName, 
							  UGint& nLayerType, UGString& strSubName);


	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼��д��һ�������ļ�

	virtual UGbool OpenForWrite(const UGString& strFileName);

	//! \brief ����ͼ��������
	virtual void SetLayerCount(UGint nCount);

	//! \brief ����ָ��ͼ����ŵ�ͼ����Ϣ��
	virtual void SetLayerInfo(UGint nIndex, 
					const UGString& strLayerName, UGint nLayerType, 
					const UGRect2D& rcBounds, 
					const UGString& strSubName);

	//! \brief �ر��ļ�
	virtual void Close();
	
protected:
	
	//! \brief ��ʱ�ļ�Ŀ¼
	UGString m_strTempPath;

	//! \brief ���ð汾
	UGint m_nVersion;
};

} //namespace UGC

#endif // !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
