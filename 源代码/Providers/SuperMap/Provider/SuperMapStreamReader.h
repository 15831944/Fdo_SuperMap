/** \file	 SuperMapStreamReader.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#ifndef __SUPERMAP_STREAMREADER_H__
#define __SUPERMAP_STREAMREADER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapStreamReader SuperMapStreamReader.h
	\brief ���ڶ�ȡӰ�����ݼ��е����ݣ��ڵ���Raster��GetStreamReaderʱ�����ظ���Ķ���
    return Ӱ�����ݼ������ݵĶ�ȡ�ǰ�Ӱ�������ȡ�ģ����ø����е�ReadNext�����
*/

class SuperMapStreamReader : public FdoBLOBStreamReader
{
public:
	SuperMapStreamReader(UGC::UGDatasetRaster *pDatasetRaster, FdoRasterDataModel* datamodel);

protected:
	virtual void Dispose();

public:
	/// \brief
    /// Get the size of a stream.
    /// 
    /// \return
    /// Returns the size of the data source in number of items 
    /// 
    virtual FdoInt64   GetLength();   

    /// \brief
    ///  Skips a number of items 
    /// 
    /// \param offset 
    /// Number of items to skip. Must be a positive number
    /// 
    /// \return
    /// Returns nothing 
    /// 
    virtual void       Skip(const FdoInt32 offset);  
      
    /// \brief
    ///  Get the current index in the stream 
    /// 
    /// \return
    /// Returns the current index in the stream in number of items 
    /// 
    virtual FdoInt64   GetIndex();  

    /// \brief
    ///  Reset the current index in the stream. Allows re-reading 
    /// 
    /// \return
    /// Returns nothing 
    /// 
    virtual void       Reset();      
     
    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. 
    /// 
    /// \param buffer 
    /// Buffer holding data read in
    /// \param offset 
    /// Index in the buffer indicating the beginning of the output buffer. 
    /// The caller is responsable for allocating a buffer of a proper size.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached. 
    /// 

    virtual FdoInt32   ReadNext( FdoByte* buffer, 
                                        const FdoInt32 offset = 0,
                                        const FdoInt32 count = -1);

    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. The caller is responsible to create/dispose the FdoArray. 
    /// 
    /// \param buffer 
    /// FdoArray object holding data read in. Cannot be NULL
    /// \param offset 
    /// Index in the array indicating the beginning of the output buffer. 
    /// If the end of the buffer, then read in appending mode (store at the end). 
    /// Otherwise, overwrite the buffer. Throws "invalid parameter" exception if not in this range.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns number of items read.
    /// 
    virtual FdoInt32    ReadNext(  FdoArray<FdoByte> * &buffer, 
                                            const FdoInt32 offset = 0,
                                            const FdoInt32 count = -1 ); 

public:
	~SuperMapStreamReader(void);

public:
	/*
		\brief ʹ�ñ��ʺͺ���ӳ��ķ�����ԭͼ������ز���
		\param[out] buffer ָ������ֵ�����飬�Ѿ�������ƫ����
		\param[in] nFileXlen ԭͼ��Ŀ��
		\param[in] nFileYLen ԭͼ��ĸ߶�
		\param[in] nViewXLen ��ʾ����Ŀ��
		\param[in] nViewYLen ��ʾ����ĸ߶�
		\param[in] nImgColorType Ӱ����ɫ����
		\param[in] nCount �����ж����ֽ���
		\return int �������ж�ȡ���ֽ���
 		\note buffer ����Ϊ��
	*/
	int  FuncRatioResample(FdoByte* buffer, int nFileXlen, int nFileYLen, 
		int nViewXLen, int nViewYLen, int nImgColorType, int nCount);

	/*
		\brief �жϸ���ͼ���Ƿ��Ǵ��е�ɫ����Ϣ��ͼ��
		\return bool �ǵ�ɫ��ͼ�񷵻��棬���򷵻ؼ�
	*/
	bool IsPalletteImage();

private:
	UGC::UGDatasetRaster *m_pDatasetRaster;		//ָ��դ�����ݼ���ָ��
	FdoInt64 m_nStreamIndex;					//���ж��������ص�����
	FdoPtr<FdoRasterDataModel> m_dataModel;		//ָ��դ��ͼ��֧�ֵ�����ģ��
	int m_nBytesPerPixel;						//ͼ����ÿ�����ص��ֽ���
	enum ImgColorType
	{
		IMGMONO			= 1,	//��ֵ
		IMGRGB4			= 2,	//4 bits
		IMGGRAY			= 3,	//�Ҷ�
		IMGRGB16		= 4,	//16 bits
		IMGRGB24		= 5,	//24 bits
		IMGRGB32		= 6,	//32 bits
		IMGRGB48		= 7,	//48 bits
		IMGRGB64		= 8,	//64 bits
		IMGRGBFLOAT 	= 9,    //32 bits float
		IMGRGBDOUBLE	= 10,	//64 bits double 
	};

	enum BytesPerPixel
	{
		ONEBYTEPIXEL		= 1,	//һ���ֽ�
		THREEBYTESPIXEL		= 3,	//�����ֽ�
		FOURBYTESPIXEL		= 4,	//�ĸ��ֽ�
		SIXBYTESPERPIXEL	= 6,	//�����ֽ�
		EIGHTBYTESPERPIXEL	= 8		//�˸��ֽ�
	};
};

#endif // __SUPERMAP_STREAMREADER_H__
