
/*!
    **************************************************************************************
     \file     UGExchangeFileType.h
    **************************************************************************************
     \author   ����
     \brief    ����ת���ļ�������           
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

#if !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)
#define AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_

#include "Base/ugexports.h"


namespace UGC {


class FILEPARSER_API UGExchangeFileType  
{
public:

	// �ļ���ʽ����
	enum EmGroup
	{
		GroupUncertain	= 0,	// ��֪��Ӧ�÷ŵ��ĸ�����
		GroupVector		= 1,	// ʸ�����͵��ļ���ʽ
		GroupUserVector	= 2,	// �û������ʸ����ʽ
		GroupRaster		= 3,	// դ�����͵��ļ���ʽ
		GroupUserRaster  = 4 	// �û������դ���ʽ
	};

	// �ļ�������������Щ���͵�����
	enum EmGeoType
	{
		GeoTypeNull		= 0x00,	// �յ�
		GeoTypePoint	= 0x01,	
		GeoTypeLine		= 0x02,
		GeoTypeRegion	= 0x04,
		GeoTypeText		= 0x08,
		GeoTypeTabular	= 0x10  // �����Ա�����
		//??	= 0x20,
	};

	// �ļ���ʽ����
	enum EmType
	{
		//fileNone = 0, ��ʾ����û��ָ��ת�����ת�����ļ�������ʲô��
		// �ڼ��ת�����ת����������ʱ���������������Ҫ������return false��
		TypeNone = 0, 
	
		// SuperMapԤ����ʸ����ʽ���� [1, 100]
		// ����ͨ��ʸ����ʽ[1, 50]	XML��ʽ[51, 60]	���ݿ��ļ�[60, 70]
		// SuperMap���Ÿ��û����п�����ʸ����ʽ����: [101, 200]

		// AutoCAD File		[1, 5]
		TypeAutoCAD		= 1,	//AutoCAD �ļ���DWG ���� DXF �ļ�������
		TypeDWG			= 2,	//AutoCAD DWG �����ļ�
		TypeDXF			= 3,	//AutoCAD DXF �����ļ�
		// ERSI File			[6, 10]
		TypeCoverage	= 6,	//Arc/Info Coverage
		TypeE00			= 7,	//Arc/Info E00�����ļ�
		TypeShape		= 8,	//ArcView Shape�ļ�
		// MapInfo File		[11, 15]
		TypeTAB			= 11,	//MapInfo TAB
		TypeMIF			= 12,	//MapInfo MIF �����ļ�
		// MicroStation File [16, 20]
		TypeDGN			= 16,	//Microstation DGN�ļ�
		// other GIS/CAD software File [21, 50]
		TypeVEC			= 21,	//Idrisi ʸ���ļ�
		TypeVCT			= 22,	//���ұ�׼ʸ���ļ� *.VCT
		TypeMapGis		= 23,	//MapGIS���뽻���ļ�  
		// other vector file 
		TypeWMF			= 31,	//wmf�ļ�(windows metaFile:Ԫ�ļ�)
		TypeEPS			= 32,	//eps�ļ�

		//XML document		[51, 60]
		TypeGML			= 51,	//OpenGIS �����XML �ĵ�
		TypeSML			= 52,	//SuperMap �����XML�ĵ�
		
		//database file		[61, 70]
		TypeDBF			= 61,	//dbf ���ݿ��ļ�
		TypeMDB			= 62,	//Microsoft Access ���ݿ��ļ�

		// SuperMapԤ����դ���ʽ���� [101, 200]
		// ����Ӱ����[101, 120] ͼƬ��[121, 140] DEM/Grid��[141-160] 
		// ����[161, 180] Ԥ����ʽ[181, 200]

		// Ӱ����[101, 120]
		TypeIMG			= 101,	//Erdas Image�ļ�
		TypeSID			= 102,	//sid�ļ�
		TypeTIF			= 103,	//tif�ļ�
		TypeECW			= 106,	//Er-Mapper ECW�ļ�
		TypeIDR			= 107,	//Idrisi դ���ļ�
		TypeFST			= 108,	//Landsat��7 FST�ļ�����׺��(*.fst)

		// ͼƬ��[121, 140]
		TypeBMP			= 121,	//bitmap�ļ�
		TypeJPG			= 122,	//jpg�ļ�
		TypePNG			= 123,	//portal network graphic(PNG)

		// DEM/Grid��[141-160]
		TypeBIL		= 141,	// BIL��ʽ��grd�ļ�
		TypeArcGrid		= 142,	//Arc/Info �����ļ�grd�ļ�
		TypeDEM			= 143,	//������������ļ�
		TypeUSGSGrid	= 144,	//USGS���������ļ� ������׼
		TypeArcBinaryGrid = 145,	//Arc/Info binary grid�ļ���������arcinfo����GridAscii��AsciiGrid������ fileGRD ��ʽ���л���

		// ����[161, 180]
		TypeRAW			= 161,	//raw�ļ�

		// Ԥ����ʽ[181, 200]
		TypeGIF			= 181,	//gif�ļ�
		TypeTGA			= 182,	//tga�ļ�
		
		
		//Japanese File (vector[200, 250] and rastor[251, 300])
		//Japanese File vector [200, 250]
		TypeGXML		= 200, //�ձ������ XML�ĵ�
		TypeJIF50		= 201, //*.mem,�ձ�������ϢԺ��50ʸ��ͼ�ļ���ʽ
		TypeJIF250		= 202, //*.sem,�ձ�������ϢԺ��250ʸ��ͼ�ļ���ʽ
		TypeJIF1000		= 203, //*.tem,�ձ�������ϢԺ��1000ʸ��ͼ�ļ���ʽ
		TypeJIF2500		= 204, //*.txt,�ձ�������ϢԺ��2500ʸ��ͼ�ļ���ʽ
		TypeJIF10000	= 205, //*.lge,�ձ�������ϢԺ��10000ʸ��ͼ�ļ���ʽ
		TypeJIF25000	= 206, //*.mby,�ձ�������ϢԺ��25000ʸ��ͼ�ļ���ʽ

		TypeENC			= 210, //�ձ���ͼENC��ʽ��*.000�ļ���

		//Japanese File rastor [251, 300]
		TypeJRF10Landuse = 251, //*.tdu,�ձ�������ϢԺ��10LANDUSEդ���ļ���ʽ
		//*.tdg,�ձ�������ϢԺ��10mդ���ļ���ʽ
		//��ǰ��Ϊ�ձ�������ϢԺ��10mդ���ļ���ʽֻ��һ����*.tdu,��������������
		//����֪������һ����*.tdg�����������������ݣ�����û�а취���ˣ�����ĸ�ʽ��ȫһ��

		TypeJRF10Volcano= 252, //*.dat,�ձ�������ϢԺ��10VOLCANOդ���ļ���ʽ
		TypeJRF50		= 253, //*.mem,�ձ�������ϢԺ��50դ���ļ���ʽ
		TypeJRF250		= 254, //*.sem,�ձ�������ϢԺ��250դ���ļ���ʽ
		TypeJRF1000		= 255, //*.tem,�ձ�������ϢԺ��1000դ���ļ���ʽ
		TypeJRF10000	= 256, //*.lbi,�ձ�������ϢԺ��10000դ���ļ���ʽ
		TypeJIFSDF		= 257, //*.xml,�ձ���������Ժ����ֵ��ͼ25000�ռ����(Spatial Data Framework)

		// ������Ԥ�� 100����� �����ܵ�ʹ�� [301, 400]

		// SuperMapΪ�û����п�������ת��Ԥ�����ļ���ʽ���� [401, 500]
		// ʸ��: [401, 450]
		TypeUserVectorBegin	= 401, 
		TypeUserVectorEnd	= 450, 
		// դ��: [451, 500]
		TypeUserRasterBegin	= 451, 
		TypeUserRasterEnd	= 500
	};

	// �����ļ���ʽ�����ж����ָ�ʽ������һ����
	static EmGroup GetFileGroup(EmType eFileType);
};

} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEFILETYPE_H__EAB125D4_D53A_4784_A77E_5A8636BC43BD__INCLUDED_)

