/*! \file	 UGQueryDef.h
 *  \brief	 ��ѯ������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGQueryDef.h,v 1.14 2008/04/03 03:51:11 zhouqin Exp $
 */

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Geometry/UGGeometry.h"
#include "Algorithm/UGRect2D.h"
#if PACKAGE_TYPE==PACKAGE_UGC
#include "Base/UGTime.h"
#include "Engine/UGDsConnection.h"
#endif // end declare ugc sdk
#ifndef UGQUERY_H
#define UGQUERY_H

namespace UGC
{

//! ������ѯ��
struct ENGINE_API UGJoinItem
{	
	//! ��������ö��
	enum JoinType
	{
		InnerJoin						=0, //! ������
		LeftJoin						=1, //! ������
		RightJoin						=2, //! ������
		FullJoin						=3  //! ȫ����
	};

	//! ��������
	JoinType m_nJoinType;
	//! �ⲿ����
	UGString m_strForeignTable;
	//! �ⲿ��������
	//! ��AA BB : AA.Field1 = BB.Field2
	UGString m_strJoinFilter;
	//! ����
	UGString m_strName;

public:
	UGbool operator==(UGJoinItem joinItem);
};

//! ������ѯ��
struct ENGINE_API UGLinkItem
{	
	//! �ⲿ�����������SuperMap�����ݼ� ��ӦΪ���ݼ�����
	UGString m_strForeignTable;

	//! ���ռ����ݼ������
	UGArray<UGString > m_aryForeignKeys;

	//! ���Ա�����
	UGArray<UGString > m_aryPrimaryKeys;
	
	//! ����
	UGString m_strName;

	//! �ⲿ����Դ
	UGDsConnection m_DsConnect;

	//! ����칹���Ա�Ĺ�������,ֻ����ʹ��m_DsConnect,ʹ��
	UGString m_strFilter;

	//! ���Ա���ֶ�
	UGArray<UGString > m_aryFields;
};

//! ��ѯ������
class ENGINE_API UGQueryDef
{
public:
	//! ��ѯ����ö��
	enum QueryType
	{
		General							=0, //! һ���ѯ
		Bounds							=1, //! ʹ��Bounds��ѯ
		IDs								=2, //! ʹ��ID�����ѯ
	};

	//! ��ѯѡ��ö��
	enum QueryOption
	{		
		Geometry						= 1,//! ��ѯ���ζ���
		Attribute						= 2,//! ��ѯ������Ϣ
		Both							= 3 //! ��ѯ���ζ���������Ϣ
	};

	//! ��ѯģʽö��
	enum QueryMode
	{
		GeneralQuery					=0x00000000, //! һ���ѯ
		FuzzyQuery						=0x00000001  //! ģ����ѯ
	};

#if PACKAGE_TYPE==PACKAGE_UGC
	//! �α�����ö��
	enum CursorType
	{
		OpenForwardOnly					=0, //! ǰ�򻬶��α�
		OpenKeyset						=1, //! �ؼ����α�
		OpenDynamic						=2, //! ��̬�α�
		OpenStatic						=3, //! ��̬�α�
		OpenUnspecified					=-1 //! δ����
	};

	//! �α�λ��ö��
	enum CursorLocation
	{
		UseDefault						=1, //! ��ָ���α�λ��
		UseServer						=2, //! ���������α�
		UseClient						=3  //! �ͻ����α�
	};

#endif // end declare ugc sdk

public:
	//! ���캯��
	UGQueryDef();
	//! ��������
	~UGQueryDef();
	
	void operator=(const UGQueryDef &querydef);

	UGbool operator==(const UGQueryDef &querydef);

	//! ����ѯ������Ϣ��ΪXML��ʽ
	//! \param nVersion �汾��
	//! \return ������XML��ʽ�ַ���
	UGString ToXML(UGint nVersion) const;

	//! ��XML�н�����ѯ������Ϣ(�洢�����ռ�ʱ���п��ܻ��õ��������滻��ǰ��ͼ��DisplayFilter)
	//! \param strXML XML��ʽ�ַ���
	//! \param nVersion �汾��	
	UGbool FromXML(const UGString& strXML,UGint nVersion);

protected:
	UGString GetQueryType(QueryType nType) const;
	void SetQueryType(UGString strQueryType);

public:
	//! ��ѯ����(General,Bounds,IDs�����ֿռ��ѯ�ȣ�
	//! ���� (Ĭ�� General)
    QueryType			m_nType;
	
	//! ��ѯѡ��(�Ƿ񷵻�Geometry��Attribute,�����߶��еȣ�
	//! ���� ��Ĭ�� Both��
	QueryOption			m_nOptions;

	//! ��ѯ��ʽ(GeneralQuery��FuzzyQuery)
	//! ��ѡ Ĭ���أ�GeneralQuery
	QueryMode			m_nMode;

	//! �������ݲ�ѯ����
	//! ��ѡ Ĭ�� ""
	UGString			m_strFilter;
	
	//! �������ݲ�ѯ����
	//! ��ѡ Ĭ�� ""
	UGString			m_strSort;
	
	//! �������ݲ�ѯ�ֶ���
	//! ��ѡ Ĭ�� ""
	UGArray<UGString>	m_Fields;

	//! �洢��ҹ�������
	//! ��ѡ Ĭ�� ""
	UGArray<UGJoinItem>	m_JoinItems;

	//! ��ҹ������Ա�
	UGArray<UGLinkItem>	m_aryLinkItems;
	//! �������ݷ������
	//! ��ѡ Ĭ�� ""
	UGString			m_strGroup;

	//! �ռ��ѯʱ��Ҫ�ļ��ζ���
	//! ��ѡ Ĭ�� NULL
	UGGeometry*			m_pGeometry;

	//! Bounds��ѯʱ����Ӿ���
	//! ��ѡ Ĭ�� empty
	UGRect2D			m_rc2Bounds;

	//! ID��ѯʱ��ID����
	//! ��ѡ Ĭ�� ""
	UGArray<UGint>		m_IDs;

	//! ID��ѯʱ��ID����,Ŀǰֻ֧����ֵ���ֶ�
	//! ��ѡ Ĭ�� ""
	UGString			m_strIDFieldName;

	//! Bounds ��ѯ,���� m_nMode = FuzzyQuery
	//! ��ѡ Ĭ�� 0
	UGdouble			m_dGranule;

	//! �α�(���)����
	//! ��ѡ Ĭ�� OpenDynamic
	CursorType			m_nCursorType;

	//! �α�λ��
	CursorLocation		m_nCursorLocation;

	//! ʱ�����ݵ���ʾʱ���
	UGTime				m_SequenceTime;
};

}

#endif

