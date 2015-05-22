/*! \file	 UGCursorGeneralException.h
 *  \brief	 ��ͨ���⴦��
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGCursorGeneralException.h,v 1.1.1.1 2004/12/15 06:54:08 litt Exp $
 */

#ifndef UGCURSORGENERALEXCEPTION_H
#define UGCURSORGENERALEXCEPTION_H

#include "Base/ugdefs.h"
#include "Base/UGException.h"

namespace UGC {

//! ��ͨ���⴦����
class ORCENGINE_API UGCursorGeneralException : public UGException
{
public:
	//! ���캯��
	UGCursorGeneralException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);

	//! ��������
	virtual ~UGCursorGeneralException();

};

}

#endif


