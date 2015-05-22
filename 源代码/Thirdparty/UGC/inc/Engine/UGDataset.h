/*! \file	 UGDataset.h
 *  \brief	 ���ݼ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataset.h,v 1.35 2008/04/01 02:13:22 zhouqin Exp $
 */

#ifndef UGDATASET_H
#define UGDATASET_H

#include "Base/ugdefs.h"
#include "Base/UGTime.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Geometry/UGDataCodec.h"
#include "ugeng.h"
#include "UGEngDefs.h"

namespace UGC {

class UGDataSource;

//! ���ݼ�����
class ENGINE_API UGDataset  
{
public:
	//! ���ݼ�����,����Դ��IsSupport����������ϸ֧��˵��
	enum DatasetType
	{
		Tabular		=0,		//! ֻ�����Ա�û�м��ζ���
		Point		=1,		//! �����ݼ�
		Line		=3,		//! �����ݼ�
		Network		=4,		//! �������ݼ�
		Region		=5,		//! ��������ݼ�
		Text		=7,		//! �ı����ݼ�
		LineM		=35,	//! ·�����ݼ�
		Image		=81,	//! Ӱ��
		MrSID		=82,	//! MrSID
		Grid		=83,	//! դ��
		DEM			=84,	//! DEM
		ECW			=85,	//! ECW
		WMS			=86,	//! WMS	
		WCS			=87,	//! WCS
	
		PointZ		=101,	//! ��ά��
		LineZ		=103,	//! ��ά��
		RegionZ		=105,	//! ��ά��
		PointGL		=137,	//! ����������Point3D
		TIN			=139,	//! TIN���ݼ�
		CAD			=149,	//! CAD���ݼ�
		
		WFS			=151,	//! WFS
		LinkTable	=153,	//! ���ݿ��,ֻ������
		Topo		=154,	//! Topo���ݼ�
		TIN2		=155	//! �µ�Tin���ݺ���ǰ�����ֿ�
	}; 

	enum DatasetOption
	{
		Default		= 0x00000000,	/**< Ĭ��ѡ�� */
		HasStyle	= 0x00000001,	/**< ���֧�� */
		//{{2007.7.15 ri�Ժ��ֹӦ��
		Zip			= 0x00000002,	/**< Zipѹ���洢 */
		//}}
		Pyramid     = 0x00000004,	/**< ֧��Ӱ��������洢 */
		Sequence	= 0x00000008,	/**< ֧��ʱ��洢 */
		MemCache	= 0x00000010,	/**< ֧���ڴ滺��ģʽ */
		LongTrans	= 0x00000020,	/**< ֧�ֳ�������� */
		UserLock	= 0x00000040,	/**< ֧���û����� */
		CacheMode	= 0x00000080,	/**< ֧�ֱ��ػ���ģʽ */
		//{{2007.7.15 ri�Ժ��ֹӦ��
		Library		= 0x00010000,	/**< ֧�ֵ���ͼ��ģʽ */
		//}}
		ReadOnly	= 0x00020000,	/**< ֻ�� */
		DataVersion = 0x00040000,	/**< �汾���� */
		TopoAdscription = 0x00080000, /**< topo ���� */
//		CacheIndex		= 0x00100000 /**< ��̬�������� */
		//CHARSET		((nOptions & 0x0000ff00 ) >> 8)
	};


public:
	//! ���캯��
	UGDataset();
	
	//! ��������
	virtual ~UGDataset();

public:
	//! �����ݼ�
	virtual UGbool Open() = 0;

	//! �ر����ݼ�
	virtual void Close() = 0;
	
	//! �������ݼ�����
	virtual UGDataset::DatasetType GetType() const = 0;

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated() = 0;

	//! ���ش���ʱ��
	virtual UGTime GetDateCreated() = 0;
	
	//! �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName() =0;
	
	//! �������ݼ���Ӧ����
	virtual UGString GetTableName() =0;
	
	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName) = 0;

	//! ������С�߳�
	virtual UGdouble GetMinZ() =0;

	//! ������С�߳�
	virtual void SetMinZ(UGdouble d) =0;

	//! �������߳�
	virtual UGdouble GetMaxZ() =0;

	//! �������߳�
	virtual void SetMaxZ(UGdouble d) =0;

	//! �������ݼ���ά��
	virtual UGint GetDimension() =0;

	//! �ж��Ƿ���ʸ�����ݼ�
	virtual UGbool IsVector() =0;

	//! �ж��Ƿ���Topo���ݼ�
	virtual UGbool IsTopoDataset() =0;

	//! �ж��Ƿ���դ�����ݼ�
	virtual UGbool IsRaster() =0;

	virtual UGbool IsLinkTable() = 0;

	//! �������ݼ��ķ�Χ
	virtual const UGRect2D& GetBounds() const =0;

	//! �������ݼ��ķ�Χ
	virtual void SetBounds(const UGRect2D& r) = 0;

	//! ���ؿռ����ݱ��뷽ʽ
	virtual UGDataCodec::CodecType GetCodecType() =0;
	
	//! ���ÿռ����ݱ��뷽ʽ
	virtual void SetCodecType(UGDataCodec::CodecType c) =0;

	//! �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	virtual UGint GetOptions() =0;

	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo() = 0;
	
	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo() = 0;	
	
public:
	//! �������ݼ���ID
	UGint GetID() const {return m_nID;}

	//! �������ݼ���ID
	void SetID(UGint nID) { m_nID = nID; }

	UGString GetSchema() const;

	//! ��������Դָ��
	UGDataSource* GetDataSource() const {return m_pDataSource;}

	//! ��������Դָ��
	void SetDataSource(UGDataSource* pDs) {m_pDataSource = pDs;}

	UGbool IsModified() const {return m_bModified;}
	
	void SetModifiedFlag(UGbool bModified = TRUE) {m_bModified = bModified;}

	//! �ж����ݼ��Ƿ��Ѿ���
	virtual UGbool IsOpen() const {return m_bOpened;}

	//! �������ݼ���Χ,һ�������ݼ���Ԫ�ر�ɾ�����޸ĺ�ʹ��,
	//! ���ܺķѽ϶�ʱ��
	virtual UGbool ComputeBounds() {return FALSE;};

	//! ֱ�Ӵ��ڴ��з��ض������,�ٶȱȽϿ�,
	//! �����ܱ�֤��ȷ,ͨ��DatsetInfo��ȡ
	virtual UGint GetObjectCountDirectly() {return -1;};

	//! �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! ͨ��Register���ȡ
	virtual UGint GetObjectCount() {return -1;}

	//! ��ȡ���ݼ�ռ�õ�Ӳ�̿ռ�
	virtual UGint GetStoredSpace() {return -1;}

	//! ��ȡ���ݼ�������Ϣ
	virtual UGString GetDescription() const {return "";};

	//! �������ݼ�������Ϣ
	virtual void SetDescription(const UGString& /*strDesc*/) {};
	
	//! �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate() {return FALSE;}
	
	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint /*nOption*/) {return FALSE;}

	//! ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint /*nOption*/) {return FALSE;}
	
	//! �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	virtual UGbool HasFlag(UGint /*nOption*/) {return FALSE;}
	
	//! ���ݼ��Ƿ���ĳ��ģʽ�Ĳ���������
	virtual UGbool HasAbility(UGEngAbility /*dwEngAbility*/) {return FALSE;}
	
	//! �ж����ݼ��Ƿ�֧��ĳ�ֲ���
	virtual UGbool IsSupport(UGEngAction /*nAction*/) {return FALSE;}

#if PACKAGE_TYPE==PACKAGE_UGC
	//! �������ݼ�,�����������û��༭
	virtual UGbool Lock() {return FALSE;}

	//! �����ݼ�����
	virtual UGbool Unlock() {return FALSE;}

#endif // end declare ugc sdk
protected:

	//! �������ݼ���ѡ����Ϣ
	virtual void SetOptions(UGint nOptions) =0;

public:
	//! ���ݼ���ID
	UGint m_nID;
protected:	
	//! �Ƿ��
	UGbool m_bOpened;
	//! �Ƿ��Ѿ��޸�
	UGbool m_bModified;	
	//! ����Դָ��
	UGDataSource* m_pDataSource;
};

typedef UGArray<UGDataset*> UGDatasets;
 
}

#endif 
