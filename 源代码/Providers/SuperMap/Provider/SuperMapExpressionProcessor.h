
/** \file	 SuperMapExpressionProcessor.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#ifndef __SUPERMAP_EXPRESSIONPROCESSOR_H__
#define __SUPERMAP_EXPRESSIONPROCESSOR_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapExpressionProcessor SuperMapExpressionProcessor.h
	\brief ���ڴ�����ʽ
*/

class SuperMapExpressionProcessor : public FdoIExpressionProcessor
{
public:
	SuperMapExpressionProcessor(void);
	SuperMapExpressionProcessor(SuperMapFilterStringBuffer *pStringBuff, UGC::UGEngineType DsEngineType);

public:
	~SuperMapExpressionProcessor(void);

public:
	virtual void Dispose() 
	{ 
		delete this; 
	}
    /// \brief
    /// Processes the FdoBinaryExpression passed in as an argument.
    /// 
    /// \param expr 
    /// Input binary expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBinaryExpression(FdoBinaryExpression& expr);

    /// \brief
    /// Processes the FdoUnaryExpression passed in as an argument.
    /// 
    /// \param expr 
    /// Input unary expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessUnaryExpression(FdoUnaryExpression& expr);

    /// \brief
    /// Processes the FdoFunction passed in as an argument.
    /// 
    /// \param expr 
    /// Input function
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessFunction(FdoFunction& expr);

    /// \brief
    /// Processes the FdoIdentifier passed in as an argument.
    /// 
    /// \param expr 
    /// Input indentifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessIdentifier(FdoIdentifier& expr);

    /// \brief
    /// Processes the FdoComputedIdentifier passed in as an argument.
    /// 
    /// \param expr 
    /// Input indentifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessComputedIdentifier(FdoComputedIdentifier& expr);

    /// \brief
    /// Processes the FdoParameter passed in as an argument.
    /// 
    /// \param expr 
    /// Input parameter
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessParameter(FdoParameter& expr);

    /// \brief
    /// Processes the FdoBooleanValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBooleanValue(FdoBooleanValue& expr);

    /// \brief
    /// Processes the FdoByteValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessByteValue(FdoByteValue& expr);

    /// \brief
    /// Processes the FdoDateTimeValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDateTimeValue(FdoDateTimeValue& expr);

    /// \brief
    /// Processes the FdoDecimalValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDecimalValue(FdoDecimalValue& expr);

    /// \brief
    /// Processes the FdoDoubleValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDoubleValue(FdoDoubleValue& expr);

    /// \brief
    /// Processes the FdoInt16Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt16Value(FdoInt16Value& expr);

    /// \brief
    /// Processes the FdoInt32Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt32Value(FdoInt32Value& expr);

    /// \brief
    /// Processes the FdoInt64Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt64Value(FdoInt64Value& expr);

    /// \brief
    /// Processes the FdoSingleValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessSingleValue(FdoSingleValue& expr);

    /// \brief
    /// Processes the FdoStringValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessStringValue(FdoStringValue& expr);

    /// \brief
    /// Processes the FdoBLOBValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBLOBValue(FdoBLOBValue& expr);

    /// \brief
    /// Processes the FdoCLOBValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessCLOBValue(FdoCLOBValue& expr);

    /// \brief
    /// Processes the FdoGeometryValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input geometry value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessGeometryValue(FdoGeometryValue& expr);
 
protected:
	/*
		\brief ������ʽ�����ڵݹ���ã�������ʽ���������
		\param [in]Expr ָ��������ұ��ʽ
		\note �����ڵݹ����
	*/
  void ProcessExpresion( FdoExpression* Expr);

    /*
		\brief һ���������������ڹ��˱��ʽ�����ǰ�߻��ߺ�������ַ���
		\param [in]Str ָ��Ҫ���ӵ��ַ�����ָ��
	*/
  void AppendString(const char *Str);
  void PrependString(const char *Str);

protected:
	SuperMapFilterStringBuffer *m_pStringBuff;	//����˱��ʽ����һ������
	UGC::UGEngineType m_DsEngineType;			//����Դ�������ͣ���Ҫ���ڴ���ʱ��Ͳ����У����õ������﷽ʽ��һ��

};

#endif