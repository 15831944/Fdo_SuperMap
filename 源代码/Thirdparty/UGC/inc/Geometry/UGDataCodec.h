/*! \file	 UGDataCodec.h
 *  \brief	 �ռ����ݱ�����Ķ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataCodec.h,v 1.23 2007/11/16 06:08:51 zhouqin Exp $
 */


#ifndef UGDATACODEC_H
#define UGDATACODEC_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "UGImgBlock.h"
#include "Base/UGArray.h"
#include "Base/UGMemoryStream.h"


namespace UGC {

//! �ռ����ݱ�����
class GEOMETRY_API UGDataCodec  
{
public:
	//! ��������
	enum CodecType
	{
		encNONE		= 0,	//! ��ʹ�ñ��뷽ʽ
		encBYTE		= 1,	//! ʹ��BYTE(1)���ʹ洢
		encWORD		= 2,	//! ʹ��WORD(2)���ʹ洢
		enc3BYTE	= 3,	//! ʹ��3�ֽ����ʹ洢
		encDWORD	= 4,	//! ʹ��4�ֽ����ʹ洢
		//encFLOAT	= 5,	//! ʹ��float���ʹ洢
		encDOUBLE	= 0,	//! ʹ��doubel���ʹ洢		
		encDCT		= 8,	//! Image��ѹ��
		encSGL		= 9,	//! SuperMap Grid LZW encoded.
		encLGL		= 10,	//! another Grid LZW encoded.
		encLZW		= 11,	//! ����������ɫӰ���ѹ����ʽ������
	};

public:
	//! \brief ��һ���㴮����ָ���ı��뷽ʽ���б��룬������������Ļ�����
	//! \param pPoints Ҫ����ĵ㴮��ָ��
	//! \param nPointCount Ҫ����ĵ㴮�ĵ����
	//! \param buf[out] ����Ļ���
	//! \param eType ���뷽ʽ, ֧��encBYTE, encWORD, enc3BYTE, encDWORD���ֱ��뷽ʽ
	//! \param rcBounds �㴮��Bounds, �����ڲ�Ҫʹ��;
	//!		����Geometry,������Geometry��GetBounds����;���ڷ�Geometry�ڵĵ㴮,������UGOpPoints��Bounds����
	//! \remarks ��Ҫ����ʸ�����ݼ�����ʹ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool Encode( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief Encode SDBPlus
	static UGbool EncodeSDB( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief ��Encode��������,��ͬ��������в�����left,bottom��GridSize
	//! \remarks һ��ʹ��Encode, ���������ڻ����ļ�������ط�ʹ��
	static UGbool EncodeStatic( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, UGdouble dLeft,UGdouble dBottom,
		UGdouble dXGridSize,UGdouble dYGridSize);

	/*static UGbool Encode(const UGPoint2GSetReferencePoints( UGPoint2D* pPoints, UGint nCount )
		CodecType eType, 
		const UGRect2DComputeBounds*/

	//! \brief ���������н���õ��㴮, �� Encode �������Ӧ
	//! \param pPoints �õ��ĵ㴮, ע��㴮�Ŀռ�Ҫ���ȷ����
	//! \param pRawData ������ָ��
	//! \param nRawSize �������Ĵ�С(�ֽ�)
	//! \param eType ���뷽ʽ, ֧��encBYTE, encWORD, enc3BYTE, encDWORD���ֱ��뷽ʽ
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool Decode(UGPoint2D* pPoints, const UGuchar* pRawData, UGint nRawSize, CodecType eType);

	//! \brief SDBPlus
	static UGbool DecodeSDB(UGPoint2D* pPoints, UGint nPointCount,UGStream &stream, CodecType eType,const UGRect2D& rcBounds);	

	//! \brief �� EncodeStatic ��Ӧ�Ľ��뷽��
	static UGbool DecodeStatic(UGPoint2D* pPoints,const UGuchar* pRawData,UGint nRawSize,
		UGdouble dLeft,UGdouble dBottom,UGdouble dXGridSize,UGdouble dYGridSize, CodecType eType);

	//! \brief Ӱ������
	static UGint Encode(UGImgBlock * pImgBlock,
		PixelFormat ipf,
		UGbyte *&pBuffer,
		UGuint &nBufferSize,
		UGint nNoValue,
		CodecType eType,
		UGint nQuality = 75);

	//! \brief Ӱ������
	static UGbool Decode(UGImgBlock* pImgBlock,
		const UGuchar* pRawData,
		UGint nRawSize,
		UGint nNoValue,
		CodecType encType);

private:
	//! \brief ��uint���͵���С�������ֽڴ洢��stream��
	static void Save3Byte(UGStream& stream, UGuint value);
	//! \brief ��stream�ж�ȡ�����ֽڣ���С��������һ��uint
	static UGuint Load3Byte(UGStream& stream);

	static UGint Block2DCT(UGbyte * &pData,UGImgBlock* ImgBlock,UGint nQuality);
	static UGint DCT2Block(UGbyte * pData,UGint nSize,UGImgBlock* ImgBlock);

// 	//! \brief 		ѹ������
// 	//! \return 	UGint			�������ݳ���
// 	//! \param 		nPixelFormat	DEM���ݵ����ظ�ʽ������ֵ��
// 	//!								IPF_FLOAT, IPF_DOUBLE
// 	//! \param 		*pSrcData       ����ָ��
// 	//! \param 		lWidth			���ݴ�С
// 	//! \param 		cx				���ݳ���
// 	//! \param 		cy
// 	//! \param 		dMinZ			���ֵ
// 	//! \param 		dMaxZ           ��Сֵ
// 	//! \param 		*pDestData      ѹ���������ָ��
// 	//! \remarks 		
// 	static UGint EncDEM(UGint nPixelFormat, 
// 					 UGbyte *pSrcData, 
// 					 UGint lWidth,
// 					 UGint cx,UGint cy,
// 					 UGdouble dMinZ, 
// 					 UGdouble dMaxZ, 
// 					 UGbyte *pDestData);
// 
// 	//! \brief 		��ѹ��
// 	//! \return 	UGbool
// 	//! \param 		nPixelFormat
// 	//! \param 		*pSrcData
// 	//! \param 		lWidth
// 	//! \param 		cx
// 	//! \param 		cy
// 	//! \param 		&dMinZ
// 	//! \param 		&dMaxZ
// 	//! \param 		*pDestData
// 	//! \remarks 		
	static UGbool DecDEM(UGint nPixelFormat,
					 UGbyte *pSrcData, 
					 UGint lWidth,
					 UGint cx,UGint cy,
					 UGdouble &dMinZ, 
					 UGdouble &dMaxZ, 
					 UGbyte *pDestData);

	static UGint EncDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock);

//	static UGbool DecDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);

	
	// SuperMap Grid LZW ���� 
	static UGbool EncSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	//{{
	static void SGL_SaveOneValue(UGdouble dValue, UGint nBitCount, UGMemoryStream& streamBlock );

	static void SGL_SaveSeperatorValues(UGdouble* pValues, UGint nCount, UGMemoryStream& streamBlock, 
										UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveSameValues(UGdouble dValue, UGint nCount, UGMemoryStream& streamBlock, 
									UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveNoValues(UGint nCount, UGMemoryStream& streamBlock);

	static void SGL_EndSave(UGMemoryStream& streamBlock, UGint nStartPos);
	//}}
	// SuperMap Grid LZW ����
	static UGbool DecSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	// {{
	static UGdouble SGL_LoadOneValue(UGMemoryStream& streamBlock, UGint nValueSize);
	static void SGL_LoadSeperatorValues(UGdouble *dValues, UGint nCount,
										UGMemoryStream& streamBlock,  UGint nTileType, UGdouble dMinValue);
	static UGbyte GetStoreBitCount(UGint nValue);
	// }}

};
}

#endif /*UGDATACODEC_H*/
