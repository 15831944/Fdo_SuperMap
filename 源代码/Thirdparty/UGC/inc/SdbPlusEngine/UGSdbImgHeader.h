// ElemImgHeader.h: interface for the UGSdbImgHeader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
#define AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGRect2D.h"
#include "Engine/UGDatasetRasterInfo.h"


namespace UGC{

class UGRecordHeader;

class  UGSdbImgHeader  
{
public:
	UGSdbImgHeader();
	~UGSdbImgHeader();

public:

	enum ImgGridViewMode
	{
		VIEWMODE_IMAGE,
		VIEWMODE_GRID,
		VIEWMODE_GRID_COLOR,
		VIEWMODE_GRID_COLOR_LEVEL,
		VIEWMODE_GRID_COLOR_RANGE,
		VIEWMODE_GRID_LEVEL,
		VIEWMODE_GRID_RANGE,
			
		VIEWMODE_FACE,
		VIEWMODE_FACE_COLOR,
		VIEWMODE_FACE_COLOR_LEVEL,
		VIEWMODE_FACE_COLOR_RANGE,
		VIEWMODE_FACE_COLOR_IMAGE,
		VIEWMODE_FACE_LEVEL,
		VIEWMODE_FACE_RANGE,
		VIEWMODE_FACE_TEXTURE
	};
	
	enum ImgDataType
	{
		IMGDT_IMAGE = 0,			//Ӱ������.
		IMGDT_MRSID_LINK = 16,		//���ӵ��ⲿӰ���ļ�.
		IMGDT_AMI_LINK = 17,		//���ӵ��ⲿӰ���ļ�.
		IMGDT_ECW_LINK = 18,		//���ӵ��ⲿӰ���ļ�.
		
		IMGDT_GRID = 2,			//GRID.
		IMGDT_DEM = 3,			//DEM.
		IMGDT_TREND = 4,		//TREND SURFACE.
		IMGDT_COST = 5,			//distance cost surface.
		IMGDT_APPRAISAL = 6,	//���۽��.
		IMGDT_BUFFER = 7,		//���������.-*
		IMGDT_BASIN = 256,		//���ˮ�ͷ������.
		IMDDT_VISIBILITY = 257,	//��������������.
	};
	
	struct ImgHistogram
	{
		UGuint ColorIndex;
		UGuint dwCount; 	
	};
	
	enum ImgCompression
	{
		IMGCOM_NONE = 0,	//û��ѹ��.
		IMGCOM_RLE = 2,		//RLEѹ��.
		IMGCOM_LZW = 4,		//LZWѹ��.
		IMGDT_JPEG = 8,		//JPEGѹ��.
		IMGDT_WAVE = 16,	//С���任ѹ��.
	};

protected:
	UGint m_lSize;		//���ļ�ͷ����.
	UGint m_lTypeFlag;	//�ļ���ʽ��־��,"AMIF".
	UGint m_lVersion;	//�ļ���ʽ�汾��.
	ImgDataType m_eDataType;	//Ӱ�����ݻ�GRID����,DEM����.
	PixelFormat m_PixelFormat;	//���صĸ�ʽ.
	UGint m_lWidth;
	UGint m_lHeight;
	UGint m_lWidthBytes;
	
	UGDatasetRasterInfo::IBSizeOption m_eBlockSize;	//Ӱ��ֿ�߳�(���ص�λ)
	UGint m_lBlockSizes;			//Ӱ��ֿ��С(�ֽڵ�λ)
	ImgColorSpace m_ColorSpace;	//ɫ�ʿռ�����.
	UGint m_lColBlocks;				//����ֿ�����(��������).
	UGint m_lRowBlocks;				//����ֿ�����(��������).
	UGint m_lIndexOffset;			//��������Ϣ��ʼ��ƫ����.
	UGRect2D m_rcGeoReference;		//Ӱ��ĵ�����������.
	UGint m_lSampleDistance;			//�������.
	ImgHistogram m_HistogramRed[256];		//ͼ��ֱ��ͼ-��ɫ.
	ImgHistogram m_HistogramGreen[256];		//ͼ��ֱ��ͼ-��ɫ.
	ImgHistogram m_HistogramBlue[256];		//ͼ��ֱ��ͼ-��ɫ.
	UGuint m_dwColorMax;		//��ɫ���ֵ.�ֱ���RGB��,GRID��ΪUGuintֵ.
	UGuint m_dwColorMin;		//��ɫ��Сֵ.�ֱ���RGB��,GRID��ΪUGuintֵ.
	UGdouble m_dAverage;	//ƽ��ֵ.
	UGdouble m_Variance;	//���ϵ��.
	CRect m_rcThumbSize;
//DEMʹ��.
	UGint m_lBackColor;	//��������ģ��ʹ��.
	UGint m_lColorLevel;	//��ɫ�ּ��ļ���.
	ImgGridViewMode m_eViewMode;
	CRect m_rc3DView;	//��ǰ������ʾ����Ұ��Χ.
	UGdouble m_dXRatio;	//CELL��X����.���ݲ��շ�Χ����.
	UGdouble m_dYRatio;	//CELL��Y����.���ݲ��շ�Χ����.
	UGdouble m_dZRatio;	//CELL��Z����.���û�ָ��,ȱʡΪ1.0(����ʵ�߳�).
	UGint m_crBegin;		//����ɫ��ʼ��ɫ.
	UGint m_crEnd;		//����ɫ������ɫ.
	UGint m_crFloor;		//�����������ɫ.
	UGfloat m_fZFloor;	//���(��ƽ��)���Ƹ߶�.
	UGfloat m_fZMax;		//������Ƹ߶�.
	UGint m_lTrendSquare;	//���Ʒ����ķֿ��С.
	UGint m_lTrendSmooth;	//���Ʒ�����ƽ����Χ.
	ImgCompression m_Compression;	//ѹ����ʽ.
	UGchar m_FilePath[256];	//�ļ������·��,�����ⲿ�ļ�ʹ��.

public:
	void operator = (const UGSdbImgHeader &value);
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//�����¼ͷ���ڴ��
	void FromRasterInfo(const UGDatasetRasterInfo& ugRasterInfo,UGint nNoValue);
	void ToRasterInfo(UGDatasetRasterInfo& ugRasterInfo,UGint& nNowValue);

};



}

#endif // !defined(AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
