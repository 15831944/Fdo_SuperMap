/*!
    **************************************************************************************
     \file     UGStyleMapperDefn.h
    **************************************************************************************
     \author   ����
     \brief    �������ļ�               
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2007-03-09  ����      Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

namespace UGC {
	
	//! \brief ���ŷ��
	struct FILEPARSER_API UGSymbolStyle
	{
		//! brief Ŀ����
		UGString m_strDesStyleID;
		//! brief ���ű���
		UGdouble m_dbScale;
		
		UGSymbolStyle()
		{
			m_strDesStyleID = "";
			m_dbScale = 0.0;
		}
		UGSymbolStyle(UGString strDesStyleID, UGdouble dbScale)
		{
			m_strDesStyleID = strDesStyleID;
			m_dbScale = dbScale;
		}
	};
	//! \remarks UGString Ϊ Դ���
	//! eg:����ʱӦ��Ϊ�ⲿ�ļ��ķ�񣬶�UGSymbolStyle�е�m_strDesStyleΪUGC��Style
	//! ����ʱ UGStringΪUGC��Style����UGSymbolStyle�е�m_strDesStyleΪ�ⲿ�ļ��ķ��
	typedef UGDict<UGString, UGSymbolStyle> UGSymbolStyleMapper;

	//! \brief �߷��
	struct FILEPARSER_API UGPenStyle
	{
		//! brief Ŀ����
		UGString m_strDesStyleID;
		
		UGPenStyle()
		{
			m_strDesStyleID = "";
		}
		UGPenStyle(UGString strDesStyleID)
		{
			m_strDesStyleID = strDesStyleID;
		}
	};
	//! \remarks UGString Ϊ Դ���
	//! eg:����ʱӦ��Ϊ�ⲿ�ļ��ķ�񣬶�UGSymbolStyle�е�m_strDesStyleΪUGC��Style
	//! ����ʱ UGStringΪUGC��Style����UGSymbolStyle�е�m_strDesStyleΪ�ⲿ�ļ��ķ��
	typedef UGDict<UGString, UGPenStyle> UGPenStyleMapper;

	//! \brief �����
	struct FILEPARSER_API UGBrushStyle
	{
		//! brief Ŀ����
		UGString m_strDesStyleID;
		
		UGBrushStyle()
		{
			m_strDesStyleID = "";
		}
		UGBrushStyle(UGString strDesStyleID)
		{
			m_strDesStyleID = strDesStyleID;
		}
	};
	//! \remarks UGString Ϊ Դ���
	//! eg:����ʱӦ��Ϊ�ⲿ�ļ��ķ�񣬶�UGSymbolStyle�е�m_strDesStyleΪUGC��Style
	//! ����ʱ UGStringΪUGC��Style����UGSymbolStyle�е�m_strDesStyleΪ�ⲿ�ļ��ķ��
	typedef UGDict<UGString, UGBrushStyle> UGBrushStyleMapper;

	//! \brief ������
	struct FILEPARSER_API UGFontStyle
	{
		//! brief Ŀ����
		UGString m_strDesStyleID;
		UGdouble m_dbHeightScale;
		UGdouble m_dbWidthScale;
		UGdouble m_dbRotateAngle;
		
		UGFontStyle()
		{
			m_strDesStyleID = "";
			m_dbHeightScale = 0.0;
			m_dbWidthScale = 0.0;
			m_dbRotateAngle = 0.0;
		}
		UGFontStyle(UGString strDesStyleID, UGdouble dbHeightScale, 
			UGdouble dbWidthScale, UGdouble dbRotateAngle)
		{
			m_strDesStyleID = strDesStyleID;
			m_dbHeightScale = dbHeightScale;
			m_dbWidthScale = dbWidthScale;
			m_dbRotateAngle = dbRotateAngle;
		}
	};
	//! \remarks UGString Ϊ Դ���
	//! eg:����ʱӦ��Ϊ�ⲿ�ļ��ķ�񣬶�UGSymbolStyle�е�m_strDesStyleΪUGC��Style
	//! ����ʱ UGStringΪUGC��Style����UGSymbolStyle�е�m_strDesStyleΪ�ⲿ�ļ��ķ��
	typedef UGDict<UGString, UGFontStyle> UGFontStyleMapper;
}
