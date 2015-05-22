/*! \file	 UGCursorDataException.h
 *  \brief	 �������⴦��
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGCursorDataException.h,v 1.1.1.1 2004/12/15 06:54:08 litt Exp $
 */

#ifndef UGCURSORDATAEXCEPTION_H
#define UGCURSORDATAEXCEPTION_H

#include "Base/ugdefs.h"
#include "Base/UGException.h"

namespace UGC {

//! �������⴦����
class ORCENGINE_API UGCursorDataException : public UGException
{
public:
	//! ���캯��
	UGCursorDataException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);
	//! ��������
	virtual ~UGCursorDataException();

};

}

#endif


