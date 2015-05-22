/*! \file	 UGDatasetRaster.h
 *  \brief	 դ�����ݼ������ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRaster.h,v 1.42 2007/12/25 08:52:17 liwl Exp $
 */

#ifndef UGDATASETRASTER_H
#define UGDATASETRASTER_H

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Algorithm/UGRect2D.h"
#include "Algorithm/UGRect.h"
#include "Geometry/UGImgScanline.h"
#include "Geometry/UGImgBlock.h"
#include "UGDatasetRasterInfo.h"
#include "Geometry/UGGeoRegion.h"
#include "UGRecordset.h"
#include "Algorithm/UGPoint.h"
#include "Base/UGColorTable.h"
#include "Base/UGThread.h"
#include "UGImgBlocksManager.h"

namespace UGC {

//! դ�����ݼ�
class ENGINE_API UGDatasetRaster : public UGDataset
{
public:
	//! ���캯��
	UGDatasetRaster();

	//! ��������
	virtual ~UGDatasetRaster();

public:

	//! �������ݼ�����
	virtual DatasetType GetType() const{
		return (DatasetType)m_RasterInfo.m_nType;
	}

	//! �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName() {
		return m_RasterInfo.m_strName;
	}

	//! ������С�߳�
	virtual UGdouble GetMinZ() {
		return m_RasterInfo.m_dMinZ;
	}
	
	//! ������С�߳�
	virtual void SetMinZ(UGdouble d) {
		m_RasterInfo.m_dMinZ = d;
		SetModifiedFlag();
	}
	
	//! �������߳�
	virtual UGdouble GetMaxZ() {
		return m_RasterInfo.m_dMaxZ;
	}
	
	//! �������߳�
	virtual void SetMaxZ(UGdouble d) {
		m_RasterInfo.m_dMaxZ = d;
		SetModifiedFlag();
	}

	//! ��ȡ���ݼ�������Ϣ
	virtual UGString GetDescription() const;

	//! �������ݼ�������Ϣ
	virtual void SetDescription(const UGString& /*strDesc*/);

	//! �õ�դ�����ݵļ�ֵ��
	//ע�⣺���դ�����ݵ�ֵ�����仯���˺����������¼��㼫ֵ��
	//�����ȵ���CalculateExtremum�����¼��㼫ֵ�ſ��ԡ�
	void GetExtremum(UGdouble& dMax, UGdouble& dMin)
	{
		dMax = GetMaxZ();
		dMin = GetMinZ();
	}

	//! �������ݼ���ά��
	virtual UGint GetDimension() {
		return 2;
	}
	
	//! �ж��Ƿ���ʸ�����ݼ�
	virtual UGbool IsVector() {return FALSE;}
	//! �ж��Ƿ���topo���ݼ�
	virtual UGbool IsTopoDataset(){return FALSE;};

	//! �ж��Ƿ���դ�����ݼ�
	virtual UGbool IsRaster(){return TRUE;};

	virtual UGbool IsLinkTable(){return FALSE;};

	//! �õ���ɫ��
	UGColorset GetColorset(){
		return m_RasterInfo.m_Colorset;
	}

	//! ���õ�ɫ��
	void SetColorset(const UGColorset& Colorset) {
		m_RasterInfo.m_Colorset = Colorset;
		SetModifiedFlag();
	}
	
	//! ���ؿռ����ݱ��뷽ʽ
	virtual UGDataCodec::CodecType GetCodecType() {
		return m_RasterInfo.m_nCodecType;
	}
	
	//! ���ÿռ����ݱ��뷽ʽ
	virtual void SetCodecType(UGDataCodec::CodecType c) {
		m_RasterInfo.m_nCodecType = c;
		SetModifiedFlag();
	}

	virtual UGint GetOptions() {
		return m_RasterInfo.m_nOptions;
	}

	UGDatasetRasterInfo* GetInfo();
	
	//! ��ȡ���
	UGint GetWidth() const {
		return m_RasterInfo.m_nWidth;
	}
	
	//! ��ȡ�߶�
	UGint GetHeight() const {
		return m_RasterInfo.m_nHeight;
	}
	
	//! �������ݼ��ķ�Χ
	virtual const UGRect2D& GetBounds() const {
		return m_RasterInfo.m_rc2Bounds;
	}
	
	//! �������ݼ��ķ�Χ
	virtual void SetBounds(const UGRect2D& r) {
		m_RasterInfo.m_rc2Bounds = r;
		SetModifiedFlag();
	}

	
	//! Image�����Block��Ŀ
	UGint GetRowBlockCount() const {		
		return (UGint)UGCEIL(((UGdouble)m_RasterInfo.m_nHeight)/
			m_RasterInfo.m_eBlockSize);
	}
	
	//! Image�����Block��Ŀ
	UGint GetColBlockCount() const {
		return (UGint)UGCEIL(((UGdouble)m_RasterInfo.m_nWidth)/
			m_RasterInfo.m_eBlockSize);
	}

	//! ж��ָ��Block
	virtual UGbool ReleaseBlock(UGint nIndex);

	//! ж�������ѷ����ڴ�Ŀ�
	virtual void ReleaseAllBlock();

	//! ��ȡ��Чֵ
	UGdouble GetNoValue() const{
		return m_RasterInfo.m_dbNoValue;
	}

	//! brief ������ֵ
	void SetNoValue(UGdouble dbNoValue)
	{
		m_RasterInfo.m_dbNoValue = dbNoValue;
		SetModifiedFlag();
	}

	//! Image�����ظ�ʽ
	PixelFormat GetPixelFormat() const {
		return m_RasterInfo.m_ePixelFormat;
	}

	//! Block�ı߳�
	UGDatasetRasterInfo::IBSizeOption GetBlockSize() const {
		return m_RasterInfo.m_eBlockSize;
	}

	//! ��ȡ�������ĵ�ַ
	UGbyte * GetBlockCache() const{
		return m_pBlockCache;
	}

	//! ��ȡBlock��Byte����
	UGint GetBlockByteSize() const{
		return (GetBlockSize()*GetBlockSize()*UGToolkit::GetBitCount(GetPixelFormat())+7)/8;
	}

	//! ��ȡPixel
	UGColor GetPixel(UGint X,UGint Y);
	
	//! ����Pixel
	void SetPixel(UGint X,UGint Y,UGColor nColor);
	
	//! ��ȡValue
	UGdouble GetValue(UGint X,UGint Y);
	
	//! ����Value
	void SetValue(UGint X,UGint Y,UGdouble dValue);
	
	//! �õ�ɨ����
	UGbool GetScanline(UGint nRowIndex,UGImgScanline& ScanLine, UGint nStartCol = 0);
	
	//! ͨ��������������ɨ����
	UGbool SetScanline(UGint nRowIndex,UGint nColIndex,
		const UGImgScanline& ScanLine) ;


	//! ��ȡBlock,pImgBlock�ڴ�����������з��䣬�����߱������ͷ�
	UGbool GetBlockAt(UGint nBlockRow,UGint nBlockCol,
		UGImgBlock*& pImgBlock);
	
	//! ͨ������Χ��������
	UGbool CacheByGeoRef(const UGRect2D& rc2FocusedArea);

	//! ͨ��Block��������
	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight) {
		return FALSE;
	}

	//! ͨ��Pixel��������
	UGbool CacheByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! ͨ������Χ���ƻ������ݵĴ�С
	UGint EstimateCachSizeByGeoRef(const UGRect2D& rc2FocusedArea);

	//! ͨ��Block���ƻ������ݵĴ�С
	UGint EstimateCachSizeByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! ͨ��Pixel���ƻ������ݵĴ�С
	UGint EstimateCachSizeByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight) ;

	//{{ ����������ز���  ***
	//! ��ǰ���ݼ���Ӱ��������ĸ���ָ������
	UGDatasets& GetPyramidDatasets() {
		return m_PyramidDatasets;
	}

	//! \brief	�õ�ĳ����������ݼ�
	UGDatasetRaster * GetPyramidTier(UGint nImgWidth,UGint nDeviceWidth);

	//! �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	virtual UGbool HasFlag(UGint nOption);

#if PACKAGE_TYPE==PACKAGE_UGC
	virtual UGbool BuildPyramid(UGbool bShhowProgress) =0;
	virtual UGbool RemovePyramids() = 0;
	//}} ����������ز���  ***
#endif // end declare ugc sdk

	//! ����MrSID���ⲿ����,
	//! bFileMode��ָ���ļ�����ķ�ʽ���Ǵ洢�����ݿ��еķ�ʽ
	UGbool CreateMrSIDLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE) {
		//wait to implement
		return FALSE;
	}

	//! ����ECW���ⲿ����
	UGbool CreateECWLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE) {
		//wait to implement
		return FALSE;
	}

	//! �Ϸ������ļ����
	UGbool IsValidExternalFileLink() {
		//wait to implement
		return FALSE;
	}

	//! ȡ�ù����ļ���
	UGString GetLinkFileName() const {
		return m_strLinkFileName;
	}
	
	//! ����ָ��������
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock) = 0;
    
	//! pImgBlock����
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);


	//�ӿڱ任.===========================================================

	void PrepareGeoRefrence();		//��ʼ��GeoRefernce

	//! ��������תΪ��������
	void ImgToXY(const UGPoint& pntImg,UGPoint2D& pntXY);

	//! ��������תΪ��������
	void ImgToXY(const UGRect& rectImg,UGRect2D& rectXY);

	//! ��������תΪ��������
	void XYToImg(const UGPoint2D& pntXY,UGPoint& pntImg);

	//! ��������תΪ��������
	void XYToImg(const UGRect2D& rectXY,UGRect& rectImg);
	
	//! ��ȡ�ü�����
	UGGeoRegion* GetClipRegion() const {
		return m_pClipRgn;
	}

	//! ���òü�����
	void SetClipRegion(UGGeoRegion* pClipRgn);
	
	UGDatasetRaster* GetParentDataset() const{
		return m_pParentDataset;
	}

	//! \brief 		����Ӱ��ĵ�����������
	//! \return 	void
	//! \param 		&rc2GeoReference
	//! \remarks 		
	void SetGeoReference(const UGRect2D &rc2GeoReference);


	//! \brief 		��ȡӰ��ĵ�����������
	//! \return 	UGRect2D
	//! \remarks 		
	UGRect2D GetGeoReference();	

	//!	\brief	դ�����ݼ���׷��
	UGbool Append(UGDatasetRaster *pSrcRaster);
	
	UGbool CalculateExtremum(
		UGDatasetRaster * pDtGrid, 
		UGdouble &dMax, 
		UGdouble& dMin, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL){
	
		//wait to implement
		return FALSE;
	}

	UGbool CalculateExtremum(
		UGdouble &dMax,
		UGdouble& dMin, 
		UGRecordset * pRsRegion = NULL,
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL);
	
	//! \brief 		
	//! \return 	UGColorTable*
	//! \remarks 		
	UGColorTable* GetColorTable();
	
	//! \brief 		���÷ֲ���ɫ��ɫ��
	UGbool SetGridColorTable(UGColorTable* pColorTable=NULL);

	void SetParentDataset(UGDatasetRaster* pParent) {
		this->m_pParentDataset = pParent;
	}

protected:

	UGint EncodeBlock(UGImgBlock * pImgBlock);
	UGbool DecodeBlock(UGImgBlock * pImgBlock, const UGbyte * pByte,UGint nRawSize);

	//! �������ݼ���ѡ����Ϣ
	virtual void SetOptions(UGint nOptions) {
		m_RasterInfo.m_nOptions = nOptions;
		SetModifiedFlag();
	}

	UGImgBlock * GetBlockByPos(UGint nIndex);
	UGbool	SetBlockByPos(UGint nIndex,UGImgBlock *pImgBlock);

private:

	UGbool CalculateExtremumByRegion(UGdouble &dMax,
		UGdouble& dMin,
		UGGeoRegion * pRegion = NULL, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL) ;
	
	//դ����Ӱ�������Ƶ��ǲ�ͬ��
	void GridToXY(const UGPoint& pntImg,UGPoint2D& pntXY);
	void XYToGrid(const UGPoint2D& pntXY,UGPoint& pntImg);

public:
	//!��ǰ�������굽Ӱ�������ӳ�����.
	UGSize2D m_ImgRatio;

 #if PACKAGE_TYPE==PACKAGE_UGC
 	//!դ��ֲ���ɫ��ɫ��
 	UGColorTable m_ColorTable;
#endif // end declare ugc sdk
//Ϊʵ�ֶ��̳߳�ͼ���������±������õ�drawing���д����ڴ˸�Ϊ˽�У������⿪��
// 	
// 	//!ר��ͼ��ʾģʽ
// 	//0, theme none; 1, theme unique; 2, theme range;
// 	UGint m_nDrawMode;
// 
// 	//!�ֶ�ר��ͼ��KEYS
// 	UGArray <UGdouble> *m_pAryDoubleKeys;
// 
// 	//!��ֵר��ͼ��KEYS,Ҳ��ugdouble���洢�ɡ�
// 	UGArray <UGdouble> *m_pAryIntKeys;
// 
// 	//!ר��ͼ���
// 	UGColorset *m_pStyles;
// 
// 	//!ר��ͼĬ�Ϸ��
// 	UGColor m_DefaultStyle;
// #endif // end declare ugc sdk
// 
// 	// û�а취Ϊ�˲��ƻ��麯����ʾ�ӿڣ����ȡ��Աȶ��������Ӱɡ�
// 	UGColor m_NoDataStyle;
// 	
// 	UGchar m_btBrightness;
// 	UGchar m_btContrast;	
// 	UGbyte m_btBackColorTolerance;
// 	UGColor m_BackColor;
protected:
	//! Raster��Ϣ
	UGDatasetRasterInfo m_RasterInfo;
	
	//! �����ڴ��л����Block����
	UGImgBlocksManager m_ImgManager; 
	
	//! �ü�����
	UGGeoRegion* m_pClipRgn;
	
	UGRect2D m_rcViewGeoRef;	//��ʾ�ο�����

	UGbool m_bGeoReferencePrepared;	//����ο������Ƿ���

	UGMutex m_mutexBlock;

private:
	//! ���������Ӱ��⣬����������Ӱ�����ݼ�
	UGDatasets m_PyramidDatasets;

	//! ����Ǳ����ݼ��ǽ�������һ�㣬�������ͼ���ָ��
	UGDatasetRaster* m_pParentDataset;

	//! �ļ������·��,�����ⲿ�ļ�ʹ��
	UGString m_strLinkFileName;
	
	//! ��ŵ�ǰBlock��ָ��
	UGImgBlock *m_pBlock; 
	
	//! ����ѹ���Ļ�����
	UGbyte * m_pBlockCache;

	//! �������Ĵ�С
	UGuint m_nBlockCacheSize;

	#if PACKAGE_TYPE==PACKAGE_UGC
	
	//!ר��ͼ��ʾģʽ
	//0, theme none; 1, theme unique; 2, theme range;
	UGint m_nDrawMode;

	//!�ֶ�ר��ͼ��KEYS
	UGArray <UGdouble> *m_pAryDoubleKeys;

	//!��ֵר��ͼ��KEYS,Ҳ��ugdouble���洢�ɡ�
	UGArray <UGdouble> *m_pAryIntKeys;

	//!ר��ͼ���
	UGColorset *m_pStyles;

	//!ר��ͼĬ�Ϸ��
	UGColor m_DefaultStyle;
#endif // end declare ugc sdk

	// û�а취Ϊ�˲��ƻ��麯����ʾ�ӿڣ����ȡ��Աȶ��������Ӱɡ�
	UGColor m_NoDataStyle;
	
	UGchar m_btBrightness;
	UGchar m_btContrast;	
	UGbyte m_btBackColorTolerance;
	UGColor m_BackColor;
/*	
//{{added by yanmb 2007.3.17 �����ڴ����
public:
	//�ڴ����ģʽ
	enum MemoryAdjustMode{
			Seq		= 0,		//���϶��µ���
			Rev		= 1,		//���¶��ϵ���
			Dual	= 2,		//˫�����
			Protect = 3		//��������������	
	};

	UGbool AdjustMemory();
protected:
	MemoryAdjustMode m_nMode;	//�ڴ����ģʽ
	UGuint m_dwMemoUsed;
	UGuint m_dwMemoLimited;//��ʹ���ڴ����С�ڴ���ֵ

	UGuint GetBestMemo();	//�õ�����ڴ�����
	//�ڴ����
	inline UGbool AdjustMemorySeq();	//���϶��µ���
	inline UGbool AdjustMemoryRev();	//���¶��ϵ���
	inline UGbool AdjustMemoryDual();	//˫�����
	inline UGbool AdjustMemoryProtect();//��������������

//}}added by yanmb 2007.3.17 �����ڴ����
*/	

};

}

#endif


