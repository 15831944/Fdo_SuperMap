// UGODBCCacheRecordset.h: interface for the UGODBCCacheRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_)
#define AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_


#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRectUInt.h"
#include "Geometry/UGGeometry.h"
#include "Base/UGVariant.h"
#include "UGODBCRecordset.h"

namespace UGC
{
class UGODBCDatasetVector;
class UGEXPORT UGODBCCacheRecordset: public UGODBCRecordset
{
public:
	UGODBCCacheRecordset();
	UGODBCCacheRecordset(UGODBCDatasetVector *pDataset);
	virtual ~UGODBCCacheRecordset();

	UGbool Open(UGArray<UGString> & aryField);

	virtual UGbool GetWordRectBounds(UGRectUInt & rcWdRectBounds);

	
	//! \brief �رռ�¼��
	//! \param 
	virtual void Close();
	//! \brief ��ǰ��¼ָ���Ƿ�ָ��β
	//  \param 
	virtual UGbool IsEOF();

	//! \brief ��ǰ��¼ָ���Ƿ�ָ��ͷ
	//  \param 
	virtual UGbool IsBOF();

	//! \brief �õ���ǰ��¼��ID
	// \param
	virtual UGint GetID();

	//! \brief �Ƿ��¼��Ϊ��(û�м�¼)
	//  \param 
	virtual UGbool IsEmpty();

	//! \brief ȡ�ü��ζ���
	//  \param 
	//  \remarks *geometry�ں����ڷ����ڴ棬���渺��ɾ������������ڴ�й©!
	virtual UGbool GetGeometry(UGGeometry *&geometry);

	//! \brief ����ֶε�ֵ
	//  \param	strName   �ֶε�����
	//  \param	varValue  ���ص��ֶ�ֵ
	//  \remarks ����ֶα�����OPEN��ʱ������ֶ�.���򲻺�ʹ
	virtual UGbool GetFieldValue(const UGString &strName, UGVariant& varValue );

	//! \brief ����ֶε�ֵ
	//  \param nIndex     �ֶε�������
	//  \param varValue   ���ص��ֶ�ֵ
	//  \remarks ���ڻ���ģʽ�ֶ���Ϣ����,��������Ų�����
	virtual UGbool GetFieldValue( UGint nIndex, UGVariant& varValue );


	//! \brief ����ǰ�α�λ���ƶ�ָ��������
	//  \attention	ֻ�е�ǰ�α�����Ϊdynaset����snapshotʱ��֧�ִ˲���
	//  \param nRows���ƶ������������Ϊ���������¼��β�����ƶ������Ϊ���������¼��ͷ�����ƶ�
	//  \sa	MoveFirst,MoveLast, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool Move(UGint nRows);

	//! \brief ����ǰ�α�λ���ƶ�����¼����ͷ
	//  \attention	ֻ�е�ǰ�α�����Ϊdynaset����snapshotʱ��֧�ִ˲���
	//  \sa	Move,MoveLast, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool MoveFirst();

	//! \brief ����ǰ�α�λ���ƶ�����¼����β
	//  \sa	MoveFirst,Move, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool MoveLast();

	//! \brief ����ǰ�α�λ������ƶ�һ��
	//  \sa	MoveFirst,MoveLast, Move, MovePrev, MoveTo, SeekID
	virtual UGbool MoveNext();

	//! \brief ����ǰ�α�λ����ǰ�ƶ�һ��
	//  \attention	ֻ�е�ǰ�α�����Ϊdynaset����snapshotʱ��֧�ִ˲���
	//  \sa	MoveFirst,MoveLast, MoveNext, Move, MoveTo, SeekID
	virtual UGbool MovePrev();

	//! \brief ����ǰ�α�λ���ƶ���ָ������
	//  \param nRows���ƶ���Ŀ��λ��
	//  \attention	ֻ�е�ǰ�α�����Ϊdynaset����snapshotʱ��֧�ִ˲���
	//  \sa	MoveFirst,MoveLast, MoveNext, MovePrev, Move, SeekID
	virtual UGbool MoveTo(UGint nRows);

	virtual UGbool SeekID(UGint nID);

private:
	UGbool RefreshCurrentIdxItem();

	//! \brief��ȡ����
	UGbool FetchData(const UGString &strSQL);
	//! \brief ˢ�µ�ǰ��¼
	void FlushCurrentRecord();
public:
	UGint m_nLibTileID;
private:
	FILE m_DataFile;
	UG_DATA_CACHE_FILE_HEADER m_dfh;
	UG_INDEX_CACHE_FILE_HEADER m_ifh;
	UGbyte * m_pIndexData;
	UGbyte * m_pGeoData;

	UGint m_nTotalGeoLen;
	UGint m_nCurrentPos;

	UG_SUPER_INDEX_ITEM  m_CurIndexItem;

	UGint m_nCurrentID;
};

}
#endif // !defined(AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_)
