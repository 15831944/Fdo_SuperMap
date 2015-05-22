
/*!
    **************************************************************************************
     \file     UGExportParams.h
    **************************************************************************************
     \author   ����
     \brief    ����ת������������           
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_)
#define AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_


#include "UGExchangeParams.h"

namespace UGC {


struct  UGDgnUnits
{
	//! \brief	һ��Main Unit���ڶ��ٸ�Sub Unit
	UGint	m_nSuPerMu;  
	//! \brief	һ��Sub Unit���ڶ��ٸ�Pos Unit
	UGint	 m_nPosPerSu; 
	//! \brief	����λ������
	UGString m_strMuName; 
	//! \brief	�ӵ�λ������
	UGString m_strSuName; 

	UGDgnUnits()
	{
		m_nSuPerMu = 1000;
		m_nPosPerSu = 1000;
		m_strMuName = ("m");
		m_strSuName = ("mm");
	}
	UGDgnUnits(const UGDgnUnits& dgnUnits)
	{
		m_nSuPerMu = dgnUnits.m_nSuPerMu;
		m_nPosPerSu = dgnUnits.m_nPosPerSu;
		m_strMuName = dgnUnits.m_strMuName;
		m_strSuName = dgnUnits.m_strSuName;
	}
	void operator =(const UGDgnUnits &dgnUnits)
	{
		m_nSuPerMu = dgnUnits.m_nSuPerMu;
		m_nPosPerSu = dgnUnits.m_nPosPerSu;
		m_strMuName = dgnUnits.m_strMuName;
		m_strSuName = dgnUnits.m_strSuName;
	}
}; 



class DATAEXCHANGE_API UGExportParams : public UGExchangeParams  
{
public:
	UGExportParams();
	virtual ~UGExportParams();

public:
	void SetDatasetName(const UGString& strDatasetName);
	UGString GetDatasetName() const;

	void SetVersion(UGint nVersion);
	UGint GetVersion() const;

	void SetDgnUnits(const UGDgnUnits& dgnUnits);
	UGDgnUnits GetDgnUnits() const;

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);
	UGint GetDgnUnitsSelected() const;

protected:


	//! \brief 	�������ݼ������� 
	UGString m_strDatasetName;
	
	//! \brief	��һ�����ͱ��������õ����ļ���ʽ��ʲô���ͣ���ֵӦ����һЩö����
	UGint m_nVersion;
	
	//! \brief 	Dgn�����굥λ
	UGDgnUnits m_dgnUnits; 

	//! \brief 	˵�������λm_nDesUnits����Ϊdgn��λ����һ��(dgn��������λ)
	UGint m_nDgnUnitsSelected; 


};


}


#endif // !defined(AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_)
