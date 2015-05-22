
/*!
    **************************************************************************************
     \file     UGExchangeParams.h
    **************************************************************************************
     \author   ����
     \brief    ����ת����������             
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                             <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_)
#define AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_



#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGDict.h"
#include "FileParser/UGFileParseVector.h"


namespace UGC {




class DATAEXCHANGE_API UGExchangeParams  
{
public:
	UGExchangeParams();
	virtual ~UGExchangeParams();

public:
	//! \brief �����ļ���ʽ����
	UGbool SetFileType(UGint nFileType);
	//! \brief �õ��ļ���ʽ����
	UGint GetFileType() const;

	//! \brief ���������ļ���
	void SetFilePathName(const UGString& strFilePathName);
	//! \brief �õ������ļ��� 
	UGString GetFilePathName() const;
	
	//! \brief �����Ƿ���ʾ������
	void SetShowProgress(UGbool bShowProgress);
	//! \brief �õ��Ƿ���ʾ������
	UGbool IsShowProgress() const;

	//! \brief ���һ�����ŷ��ӳ��
	void AddOneSymbolStyleMapper(UGString strSourceID, UGString strDesStyleID, UGdouble dbScale);
	UGSymbolStyleMapper GetSymbolStyleMapper() const;

	//! \brief ���һ�����ͷ��ӳ��
	void AddOnePenStyleMapper(UGString strSourceID, UGString strDesStyleID);
	UGPenStyleMapper GetPenStyleMapper() const;

	//! \brief ���һ�������ӳ��
	void AddOneBrushStyleMapper(UGString strSourceID, UGString strDesStyleID);
	UGBrushStyleMapper GetBrushStyleMapper() const;

	//! \brief ���һ��������ӳ��
	void AddOneFontStyleMapper(UGString strSourceID, UGString strDesStyleID,UGdouble dbHeightScale,	
		UGdouble dbWidthScale, UGdouble dbRotateAngle);
	UGFontStyleMapper GetfontStyleMapper() const;

	//! \brief ������ʱ�ļ���·��
	void SetTempPath(const UGString& strTempPath);
	
	//! \brief �õ���ʱ�ļ���·�� 
	UGString GetTempPath() const; 

	//! \brief ���õ�������굥λ
	void SetDesUnits(UGint nDesUnits);

	//! \brief �õ���������굥λ
	UGint GetDesUnits() const;

	//! \brief ����Ӱ������ο��ļ�������
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief �õ�Ӱ������ο��ļ�������
	UGString GetImageGeoRefFileName() const;

	//! \brief ����������Ӱ������ο��ļ�������
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);

	//! \brief �õ�������Ӱ������ο��ļ�������
	UGint GetImageGeoRefFileType() const;

	//! \brief ����ͼ���ֶ�����
	void SetLayerName(const UGString& strLayerName);
	//! \brief �õ�ͼ���ֶ�����
	UGString GetLayerName() const;

	//! \brief �����������뵼������
	void SetOtherParams(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);

	//! \brief �����ļ����͵õ���������������
	UGString GetOtherParamsName(const UGString& strFileType) const;

	//! \brief �����ļ����͵õ�����������ֵ
	UGVariant GetOtherParamsValue(const UGString& strFileType) const;
	
protected:
	//! \brief ���ݸ�ʽ����
	UGint m_nFileType;
	
	//! \brief �������ļ���
	UGString m_strFilePathName;
	
	//! \brief �Ƿ���ʾ������
	UGbool m_bShowProgress;
	
	//! \brief �㡢�ߡ����塢����� ӳ���
	UGSymbolStyleMapper m_SymbolStyleMapper;
	UGPenStyleMapper m_PenStyleMapper;
	UGBrushStyleMapper m_BrushStyleMapper;
	UGFontStyleMapper m_FontStyleMapper;

	//! \brief ��ʱ�ļ�Ŀ¼
	UGString m_strTempPath;

	//! \brief 	ָ�����ɵ��ⲿ�ļ��ĵ�λ
	UGint m_nDesUnits; 

	//! \brief 	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGString m_strImageGeoRefFileName; 

	//! \brief	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGint m_nImageGeoRefFileType;

	//! \brief	ͼ���ֶ���
	//! \remarks ����ʱ��Ϊ���ɵġ����ͼ����Ϣ���ֶΣ�����
	//! ����ʱ��������ֶε�ֵ�����õ�ǰ��¼������������ͼ��
	UGString m_strLayerName;

protected:

	struct UGExchangeOtherParam
	{
		UGString m_strName; //! ����ʲô��˼
		UGVariant m_varValue; //! �˲�����ֵ
		UGExchangeOtherParam() {}
		UGExchangeOtherParam(const UGString& strName, const UGVariant& varValue)
		{
			m_strName = strName;
			m_varValue = varValue;
		}
		UGExchangeOtherParam(const UGExchangeOtherParam& otherParams)
		{
			m_strName = otherParams.m_strName;
			m_varValue = otherParams.m_varValue;
		}
	};
	//! \brief	����һЩ����������û��Զ������
	UGDict<UGString, UGExchangeOtherParam> m_otherParams;
};



} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_)
