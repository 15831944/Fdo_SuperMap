// UGFileRasterJPG.h: interface for the UGFileRasterJPG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_)
#define AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_

#ifdef WIN32
extern "C"
{
	#define JPEG_CJPEG_DJPEG	/* define proper options in jconfig.h */
	#define JPEG_INTERNAL_OPTIONS	/* cjpeg.c,djpeg.c need to see xxx_SUPPORTED */
	#include "jinclude.h"
	#include "jpeglib.h"
	#include "jerror.h"
}
#else
extern "C"
{
	#define JPEG_CJPEG_DJPEG	/* define proper options in jconfig.h */
	#define JPEG_INTERNAL_OPTIONS	/* cjpeg.c,djpeg.c need to see xxx_SUPPORTED */
	#include "../../LibShared/jpeg/include/jinclude.h"
	#include "../../LibShared/jpeg/include/jpeglib.h"
	#include "../../LibShared/jpeg/include/jerror.h"
}
#endif

#include "Graphics/UGImage.h"
#include "UGFileParseRaster.h"


namespace UGC {
class FILEPARSER_API UGFileRasterJPG : public UGFileParseRaster  
{
public:
	UGFileRasterJPG();
	virtual ~UGFileRasterJPG();

public:
	//! \brief 		���UGImage���ݵ�PNG�ļ�.
	//! \return 	UGbool  
	//! \param 		strFileName  ������ļ�·��
	//! \param 		pImage       
	//! \remarks 		
	UGbool OutputDirect(UGString strFileName, UGImage* pImage);

public:

	//////////////////////////////////////////////////////////////////////////
	// ��ȥ����
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼����ȡһ�������ļ�
	virtual UGbool OpenForRead(const UGString& strFileName);
	//! \brief ׼����ʼ��ȡդ������,�ڵ���ReadData֮ǰ�������
	virtual UGbool BeginRead(UGint nIndex = 1);
	//! \brief ��ȡһ��ɨ���е�����
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0);

	//! \brief �ر�����
	virtual void Close();

	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼��д��һ�������ļ�
	virtual UGbool OpenForWrite(const UGString& strFileName);
	//! \brief ׼����ʼд����,�ڵ���WriteData֮ǰ�������
	virtual UGbool BeginWrite();
	//! \brief д��һ��ɨ���е�����
	virtual UGbool WriteScanLine(UGint nRowIndex, UGImgScanline& imgScanline);
	//! \brief ����д����,�ڵ���WriteData֮��������
	virtual void EndWrite();

private:
	UGint m_quality;
	FILE *m_File;

	struct jpeg_decompress_struct m_dinfo;
	struct jpeg_compress_struct m_cinfo;
	struct jpeg_error_mgr m_jerr;
	JSAMPROW row_pointer[1];	// pointer to JSAMPLE row[s]
};

}
#endif // !defined(AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_)
