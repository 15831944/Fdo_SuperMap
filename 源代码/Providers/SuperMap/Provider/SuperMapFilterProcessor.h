
/** \file	 SuperMapFilterProcessor.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#ifndef __SUPERMAP_FILTERPROCESSOR_H__
#define __SUPERMAP_FILTERPROCESSOR_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFilterProcessor SuperMapFilterProcessor.h
	\brief ���ڴ����������
	return ���ַ�������ʽ���ع��˱��ʽ
*/

class UGSpatialQuery;

class SuperMapFilterProcessor : public FdoIFilterProcessor
{
public:
	SuperMapFilterProcessor(UGC::UGEngineType DsEngineType);

public:
	~SuperMapFilterProcessor(void);

public:
	virtual void Dispose() 
	{ 
		delete this; 
	}

	/// \brief
    /// Processes the FdoBinaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoBinaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& filter);

    /// \brief
    /// Processes the FdoUnaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoUnaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& filter);

    /// \brief
    /// Processes the FdoComparisonCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoComparisonCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessComparisonCondition(FdoComparisonCondition& filter);

    /// \brief
    /// Processes the FdoInCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoInCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInCondition(FdoInCondition& filter);

    /// \brief
    /// Processes the FdoNullCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoNullCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessNullCondition(FdoNullCondition& filter);

    /// \brief
    /// Processes the FdoSpatialCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoSpatialCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessSpatialCondition(FdoSpatialCondition& filter);

    /// \brief
    /// Processes the FdoDistanceCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoDistanceCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDistanceCondition(FdoDistanceCondition& filter);

public:
	/*
		\brief �õ�������Ĺ��˱��ʽ
		\return ���ַ�������ʽ���ؽ�����Ĺ��˱��ʽ
	*/
	const char* GetFilterText() 
	{ 
		return m_StringBuff.GetString(); 
	}  

	/*
		\brief �õ��ռ��ѯʱ�ļ��ζ���
		\note ʹ����ü��ζ���󣬵����߱����ͷ��ڴ�ռ䣬��������ڴ�й¶
	*/
	UGC::UGGeometry *GetGeometry();
	
	/*
		\brief �õ��ռ��ѯ������
		\return �ռ��ѯ����
	*/
	int GetSpatialQueryType();


protected:
	/*
		\brief ���ڴ�����˴������ڵݹ���ã�����Filter���������
		\param [in]Filter ָ��Fileter����Filter������Filter
		\note ���ڵݹ����
	*/
	void ProcessFilter(FdoFilter* Filter); 

	/*
		\brief ���ڴ�����ʽ
		\param [in]Expr ָ����ʽ���������ָ��
		\note ���ڴ�����ʽ
	*/
    void ProcessExpresion( FdoExpression* Expr, bool bSpatialCondition=false, bool bEnvelopeIntersect=false);

	/*
		\brief �����������������ڹ��˴���ǰ����ߺ�������ַ���
		\param [in]Str ָ��Ҫ����ַ�����ָ��
	*/
    void AppendString(const char *Str);
    void PrependString(const char *Str);

protected:
	SuperMapFilterStringBuffer m_StringBuff;	//���ڴ�Ž�����Ĺ��˴��Ļ�����
	UGC::UGGeometry *m_pGeometry;				//���ڿռ��ѯʱ���ɵ�UGC���ζ���
	UGC::UGEngineType m_DsEngineType;			//����Դ�������ͣ����ڴ���bool����ʱ�����ԣ����õ����棬��ʽ��ͬ
	int m_nSpatialQueryType;					//�ռ��ѯ������ ��������UGC::UGSpatialQuery::SpatialQueryMode type ��������!!! 

public:
	std::vector<UGC::UGGeometry *> m_GeometryArray; //����ռ��ѯ����ʱ�����UGC���ζ��������

};

#endif