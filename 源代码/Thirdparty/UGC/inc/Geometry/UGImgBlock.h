/*! \file	 UGImgBlock.h
 *  \brief	 Ӱ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGImgBlock.h,v 1.14 2007/11/16 06:05:09 zhouqin Exp $
 */

#ifndef UGIMGBLOCK_H
#define UGIMGBLOCK_H

#include "Base/ugdefs.h"
#include "Algorithm/UGSize.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGColorset.h"
#include "UGImgScanline.h"

#define UG_IMG_NOVALUE -9999 


namespace UGC {

//! Ӱ�����
class GEOMETRY_API UGImgBlock  
{
public:
	//! ���캯��
	UGImgBlock();
	//! ��������
	~UGImgBlock();
	void Create(PixelFormat ePixelFormat, 
					UGint nBlockRowIndex, 
					UGint nBlockColIndex, 
					UGint nPixelRowIndex,
					UGint nPixelColIndex,
					UGint nWidth,
					UGint nHeight,
					UGSize validSize,
					UGColorset * pColorset,
					UGbool bInited,
					UGint nWidthBytes
					);

	//! ��ȡ�ֽڿ��
	UGint GetWidthBytes();

	UGbool IsModified() const {
		return m_bModified;
	}

	void SetModifiedFlag(UGbool bFlag = TRUE) {
		m_bModified = bFlag;
	}

	//! ������ݣ��ͷ��ڴ�
	void Empty(){
		m_Data.RemoveAll();
	};

	//! �Ƿ���Ч����
	UGbool IsValid() const {
		//! wait to implement
		return TRUE;
	}	
	
	UGint GetByteSize() const {
		return m_Data.GetSize();
	}	

	void SetByteSize(const UGint nNewSize)
	{
		m_Data.SetSize(nNewSize);
	}
			
	UGbyte* GetBlockData() const {
		return const_cast<UGuchar*>(m_Data.GetData());
	}	

	//! ����Pixel
	UGbool SetPixel(UGint x,UGint y,UGint nPixel);
	
	//! ��ȡPixel
	UGint GetPixel(UGint x,UGint y);
	
	//! ����Value
	UGbool SetValue(UGint x,UGint y,UGdouble dValue);
	
	//! ��ȡValue
	UGdouble GetValue(UGint x,UGint y);
	
	//! �õ�ɨ����
	UGbool GetScanline(UGint nRowIndex,UGImgScanline& ScanLine, UGint nStartPosInSL,UGint nStartPosInBlk = 0 );
	
	//! ͨ��������������ɨ����
	UGbool SetScanline(UGint nRowIndex,
		const UGImgScanline& scanline, UGint nStartPosInSL,UGint nStartPosInBlk = 0 );

	void SetBounds(const UGRect2D & rc2Bounds)
	{
		m_rc2Bounds = rc2Bounds;
	}

	//! ��ʼ��	
	UGbool Init();

	//! Grid��Blockʹ��NoValue��ʼ��
	UGbool InitGrid(UGint nNoValue);

	//! �������ô�С
	UGbool Resize(const UGRect2D& rcNewBounds) {
		m_rc2Bounds = rcNewBounds;
		SetModifiedFlag();
		return true;
	}
	
	UGbool CalcuExtremum(UGdouble& dMaxZ,UGdouble& dMinZ);

// 	void SetMinZ(UGdouble nMinZ){
// 		m_dMinZ = nMinZ;
// 	}
// 	
// 	void SetMaxZ(UGdouble nMaxZ){
// 		m_dMaxZ = nMaxZ;
// 	}
	
	UGdouble GetMinZ() {
		if(m_bIsExtremumDirty)
		{
			CalcuExtremum(m_dMaxZ, m_dMinZ);
		}
		return m_dMinZ;
	}

	UGdouble GetMaxZ() {
		if(m_bIsExtremumDirty)
		{
			CalcuExtremum(m_dMaxZ, m_dMinZ);
		}
		return m_dMaxZ;
	}

	//! \brief ImageBlock�Ĵ洢
	UGbool SaveBlock(UGStream& stream);
	
	//! \brief ImageBlock�Ĵ洢
	UGbool LoadBlock(UGStream& stream);
	
protected:
	UGColor GetPixel1(UGint x, UGint y);

	UGColor GetPixel4(UGint x, UGint y);

	UGColor GetPixel8(UGint x, UGint y);

	UGColor GetPixel16(UGint x, UGint y);

	UGColor GetPixel24(UGint x, UGint y);

	UGColor GetPixel32(UGint x, UGint y);

	UGColor GetPixel32UGint(UGint x, UGint y);

	UGbool SetPixel1(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel4(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel8(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel16(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel24(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel32(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel32UGint(UGint x, UGint y, UGColor ColorValue);

	
public:
	//! ���صĸ�ʽ
	PixelFormat m_ePixelFormat;

	//! ������������
	UGint m_nBlockRowIndex;

	//! ������������
	UGint m_nBlockColIndex;

	//! ��ʼ������(���ص�λ)
	UGint m_nPixelColIndex;
	
	//! ��ʼ������(���ص�λ)
	UGint m_nPixelRowIndex;

	//! ���
	UGint m_nWidth;

	//! �ֽڿ��
	UGint m_nWidthBytes;

	//! �߶�
	UGint m_nHeight;

	//! ��Ч����
	UGSize m_ValidSize;
	
	//! �Ƿ��Ѿ���ʼ��
	UGbool m_bInited;

	//! ����Χ
	UGRect2D m_rc2Bounds;

	//! �ж��Ƿ��޸�
	UGbool m_bModified;

	//! ��С�߳�
	UGdouble m_dMinZ;

	//! ���߳�
	UGdouble m_dMaxZ;

	//! ��ɫ��
	UGColorset* m_pColorset;	
	
private:
	//! ��������
	UGArray<UGuchar> m_Data;
	
	//! ���m_dMax��m_dMin�Ƿ���Ҫ���¼���
	UGbool m_bIsExtremumDirty;		
};

//! Blockָ��ļ���
class GEOMETRY_API UGImgBlocks : public UGArray<UGImgBlock*>
{
public:
	void SetBlockSize(const UGint nNewSize)
	{
		this->SetSize(nNewSize);
	}
};

}

#endif

