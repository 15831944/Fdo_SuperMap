// UGODBCEditRecordset.h: interface for the UGODBCEditRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_)
#define AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_

#include "UGODBCRecordset.h"

namespace UGC
{

class UGEXPORT UGODBCEditRecordset : public UGODBCRecordset
{
public:
	UGODBCEditRecordset();
	virtual ~UGODBCEditRecordset();

public:
	//! \brief  ���£��ύ�޸�
	virtual UGint Update();

	//! \brief  ȡ���޸�
	virtual UGbool CancelUpdate();

	//! \brief  �Ƿ�����
	virtual UGbool CanAppend();
	
	//! \brief  �Ƿ�ɸ���
	virtual UGbool CanUpdate();

	//! \brief  ��ʼ�޸�����
	virtual UGbool Edit();

	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! \brief  ɾ����ǰ��¼
	virtual UGbool Delete();

	//! \brief  ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! \brief  ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! \brief  ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! \brief  ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);

	//! \brief  ͨ���ֶ��������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(const UGString& strName);

	//! \brief  ͨ�����������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(UGint nIndex);


	//! \brief  ˢ�¼�¼
	virtual void FlushCurrentRecord();

	//! \brief  ������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual UGbool Move(UGint nRows);

	//! \brief  �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst();

	//! \brief  �ƶ���¼ָ�뵽���
	virtual UGbool MoveLast();

	//! \brief  �����ƶ�һλ��¼ָ��
	virtual UGbool MoveNext();

	//! \brief  �����ƶ�һλ��¼ָ��
	virtual UGbool MovePrev();

	//! \brief  �ƶ���¼ָ�뵽ָ��λ��
	virtual UGbool MoveTo(UGint nRow);

	//! \brief  ͨ��ID��λ��¼ָ��
	virtual UGbool SeekID(UGint nID);

	//! \brief  ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! \brief  ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! \brief  ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! \brief  ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! \brief  ��ȡ��ǰ��¼��ID
	virtual UGint GetID();

	//! \brief ɾ�����еļ�¼
	virtual UGbool DeleteAll();

	//! \brief  �����ֶ�ֵ,strSrcField��
	//! \brief  strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

protected:
	//! \brief 	General��ѯ
	virtual UGbool CreateWithGeneral(const UGQueryDef &querydef);

	//! \brief IDs��ѯ
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGString &strFieldName);

	//! \brief 	Bounds��ѯ
	/// \param	[in]	  rc2Bounds ��ѯ��Χ
	//! \return	bool
	virtual UGbool CreateWithBounds(const UGRect2D &rc2Bounds, UGint nOptions, UGint  nMode);
	
	//! \brief  ���õ�ǰ��¼�ļ��ζ���
	virtual UGbool SetGeometry(UGGeometry &geometry);

	//! \brief  ���¼����ڴ�
	void ReAllocGeoBuffer(UGint nRawSize);

	//! \brief  ���°�
	void RebindGeoBuffer(UGint nRawSize);

	//! \brief  �����ڴ�λ��
	UGint GetFieldBufferPos(UGint nPos);

	//! \brief AddNew֮�������õ��ֶ�ֵ��������������
	//! \param strName [in] �ֶ�����
	//! \param varVal [out] �ֶ�ֵ
	//! \return ��Ҫ˼·��Ҫ����AddNew֮���Ч����һ��AddNew��ô�α����AddNew��λ�á�
	UGbool GetAddNewFieldValue(const UGString& strName,UGVariant& varVal);

private:
	//! \brief  ȡ����
	UGbool FetchData(const UGString & strSQL);

	//! \brief  ȡID
	UGbool FetchIDs();

	//! \brief  �ж��ֶ��Ƿ��Ѿ�����
	UGbool IsFieldModifyed(const UGString &strFieldName);

	//! ��ȡ��ǰ��¼ID
	UGint GetRealID();

	//! \brief  �汾���ݼ��ı༭
	UGint U_UpdateDataVersion();

	//! \brief  �汾���ݼ�ɾ������
	UGbool U_DeleteWithDV();



protected:
	UGint m_nCurrentID;
	UGint m_nCurrentDataIndex;

	UGODBCBinds m_CurrentBinds;
	UGODBCBind  m_OdbcBind;
	UGFieldInfos m_CurrentModifiedFieldInfos;

	UGRect2D m_RectOldBounds;
	UGRect2D m_RectNewBounds;

	/// \brief ��ǰ�α��еĿռ����,ֻ���ڱ༭��ʱ���������
	UGGeometry* m_pGeometry;
};

}

#endif // !defined(AFX_UGODBCEDITRECORDSET_H__1C3999AE_CE83_4B30_A906_93F4E72BA8C0__INCLUDED_)
