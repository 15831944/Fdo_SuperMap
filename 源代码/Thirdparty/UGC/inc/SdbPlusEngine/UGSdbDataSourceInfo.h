// UGSdbDataSourceInfo.h: interface for the UGSdbDataSourceInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_)
#define AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_

#include "Base/UGArray.h"
#include "Engine/UGDatasetVectorInfo.h"
#include "Engine/UGDatasetRasterInfo.h"

#include "CompoundFile/UGFileLogical.h"

namespace UGC{

class UGRecordHeader;

class UGSdbDataSourceInfo
{
public:
	void SetDescription(UGString strDescription);//������Ϣ
	UGString GetDescription();

	//���뵥λ������Ϊ��
	void SetDistanceUnit(UGint  nDistanceUnit);	//CSmElement::Units
	UGint GetDistanceUnit();		//CSmElement::Units 

	//���굥λ�������Ƕ�
	void SetCoordinateUnit(UGint nCoordUnit);	//CSmElement::Units 
	UGint GetCoordinateUnit();		//CSmElement::Units 

	//����ϵͳ�ţ�> 1 ΪԤ�������ͶӰ����ϵ��Ҳ��������Ч������ϵ,
	//			  = 1 Ϊ����γ����ϵ��
	//            = 0 Ϊ��ͨ�ǵ���ƽ������ϵ��
	//            =-1 Ϊ�Զ������ͶӰ����ϵ,
	//			  <-1 Ϊ��Ч������ϵ.
	void SetCoordinateSystem(UGint nCoordSys);
	UGint GetCoordinateSystem();

	//�汾��
	void SetVersion(UGint nVersion);
	UGint GetVersion();

	//ͶӰϵͳ���ַ�������
//	void SetProjectionString( CString strProjection );
//	CString GetProjectionString();

	UGuchar* GetData() 
	{
		return m_Data.GetData();
	}
	UGint GetDataSize()
	{
		return m_Data.GetSize();
	}

	// ���ļ��ж�ȡnDataSize��С������, 
	UGbool Load(UGFileLogical* pFile, int nDataSize);


public:
	UGbool IsValid();				//�Ƿ���Ч����
//	CSmElement::Type GetType();	//����Element����
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//�����¼ͷ���ڴ��
	//UGbool WriteRecordHeader(CFile *pFile,UGRecordHeader *pRcdHdr=NULL);				//�����¼ͷ���ļ�
public:	
	UGbool GetModifiedFlag();
	void SetModifiedFlag(UGbool bModified=TRUE);
	UGSdbDataSourceInfo();
	UGSdbDataSourceInfo(UGint nCoordSys, UGint nCoordUnit, UGint nDistanceUnit/*, CString strDescription*/);

	virtual ~UGSdbDataSourceInfo();

protected:
	UGArray<UGuchar> m_Data;
	UGbool m_bModified;
};


class UGSdbDatasetInfo
{
public:
	UGSdbDatasetInfo();
	~UGSdbDatasetInfo();

public:

	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);
	UGuchar* GetData();
	UGint GetDataSize();

	void From(const UGDatasetVectorInfo& Info,UGint nNextID,UGint nEncrypt1,UGint nEncrypt2);
	void To(UGDatasetVectorInfo& Info,UGint& nNextID,UGint& nEncrypt1,UGint& nEncrypt2);

	void From(const UGDatasetRasterInfo& Info);
	void To(UGDatasetRasterInfo& Info);


	UGbool HasPyramid();
	void SetPyramidFlag(UGbool bPyramid);

	UGuint GetKey();
	UGint GetNextID();
	void SetNextID(UGint nNextID);
	UGint GetRecordCount();

	void SetDatasetType(UGint nType);
	int  GetDatasetType();

	//! ѡ����Ϣ
	UGint	GetOptions();
				
	//! ���ݱ�������
	UGint	GetCodecType();
				
	//! ��άBounds����Сֵ
	UGdouble	GetMinZ();
				
	//! ��άBounds�����ֵ
	UGdouble	GetMaxZ();	

protected:
	UGArray<UGuchar> m_Data;
};




}

#endif // !defined(AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_)
