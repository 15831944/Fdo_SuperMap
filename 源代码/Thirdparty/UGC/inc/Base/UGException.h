/*! \file	 UGException.h
 *  \brief	 �쳣������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGException.h,v 1.2 2007/10/22 06:30:31 zengzm Exp $
 */

#ifndef UGEXCEPTION_H
#define UGEXCEPTION_H
#include "ugdefs.h"
#include "UGErrorObj.h"

namespace UGC {

//! \brief �쳣���࣬UGC���Զ���������쳣�࣬Ӧ�ô�UGException�̳�
class BASE_API UGException  
{
public:

	//! \brief ���캯����
	//! \param nErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strMessage [in] ��Ϣ�ַ�����
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);	
	
	//! \brief ���캯����
	//! \param nErrorID [in] ������Ϣ���ַ�����ԴID��
	//! \param strCodeFile [in] �쳣�����Ĵ����ļ���
	//! \param nCodeLine [in] �쳣�����Ĵ����С�
	UGException(UGuint nErrorID,
		const UGString& strCodeFile,
		UGint nCodeLine);	

	//! \brief ���쳣������д�뵽��־�С�
	//! \remarks �쳣�Ĺ��캯���У�����ñ�������
	virtual void WriteToLog();	

	//! \brief �õ��ڲ�ά���Ĵ�����Ϣ�ṹ��
	//! \return �����ڲ�ά���Ĵ�����Ϣ�ṹ��
	const UGErrorObj::ErrorInfo& GetErrorInfo() const;	


private:
	//! �ڲ�ά���Ĵ�����Ϣ�ṹ
	UGErrorObj::ErrorInfo m_ErrorInfo;
};

}

#endif


