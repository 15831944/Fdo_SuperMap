/*! \file	 UGDatasetRasterInfo.h
 *  \brief	 դ�����ݼ���Ϣ����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRasterInfo.h,v 1.7 2007/09/24 08:01:57 zhouqin Exp $
 */

#ifndef UGDATASETRASTERINFO_H
#define UGDATASETRASTERINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGColorset.h"
#include "Geometry/UGDataCodec.h"

namespace UGC {

//! դ�����ݼ���Ϣ
class ENGINE_API UGDatasetRasterInfo  
{
public:
	
	//! Ӱ����Сѡ��
	enum IBSizeOption {
		IBS_64				= 64,	//! 64*64
		IBS_128				= 128,	//! 128*128
		IBS_256				= 256,	//! 256*256
		IBS_512				= 512,	//! 512*512
		IBS_1024			= 1024,	//! 1024*1024
		IBS_2048			= 2048,	//! 2048*2048
		IBS_4096			= 4096,	//! 4096*4096
		IBS_8192			= 8192	//! 8192*8192
	};

	
public:
	//! ���캯��
	UGDatasetRasterInfo();

	//! ��������
	~UGDatasetRasterInfo();

	void operator=(const UGDatasetRasterInfo& rInfo);


public:
	//! ���ݼ�����
	UGString m_strName;

	//! �ײ������
	UGString m_strTableName;
	
	//! ���ݼ�����
	UGint m_nType;

	//! ѡ����Ϣ
	UGint m_nOptions;

	//! ���صĸ�ʽ
	PixelFormat m_ePixelFormat;

	//! Ӱ����
	UGint m_nWidth;

	//! Ӱ��߶�
	UGint m_nHeight;

	//! Ӱ�����ֽ���
	UGint m_nWidthBytes;

	//! Ӱ��ֿ�߳�
	IBSizeOption m_eBlockSize;

	//! ���ݼ���Bounds
	UGRect2D m_rc2Bounds;
		
	//! ���ݱ�������
	UGDataCodec::CodecType m_nCodecType;	

	//! ����ֿ�����(��������)
	UGint m_nColBlocks;		
	
	//! ����ֿ�����(��������)
	UGint m_nRowBlocks;		
	
	//! ��άBounds����Сֵ
	UGdouble m_dMinZ;
	
	//! ��άBounds�����ֵ
	UGdouble m_dMaxZ;	
	//! ��ɫ��
	UGColorset m_Colorset;

	//! ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ
	UGdouble m_dbNoValue;

	UGString m_strDescription;	//�����ݼ���������Ϣ
};

}

#endif

