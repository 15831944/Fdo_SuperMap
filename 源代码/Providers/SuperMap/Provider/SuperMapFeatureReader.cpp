
/** \file	 SuperMapFeatureReader.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-29
*/

#include "SuperMap.h"

//TODO:: ��������ʱ�׳��쳣�Ƿ��б�Ҫ����MAP3D��û��Ӱ�죬�ڱ������Ƿ������⣡

SuperMapFeatureReader::SuperMapFeatureReader (void)
{
	m_bReadFirst = true;
}

SuperMapFeatureReader::SuperMapFeatureReader(FdoClassDefinition* ClassDef, UGC::UGRecordset *pRecordset)
{
	m_ClassDef = ClassDef;
	m_pRecordset = pRecordset;
	m_pDatasetRaster = NULL;
	m_bReadFirst= true;
}

SuperMapFeatureReader::SuperMapFeatureReader(FdoClassDefinition* ClassDef, UGC::UGDatasetRaster *pDatasetRaster)
{
	m_ClassDef = ClassDef;
	m_pRecordset = NULL;
	m_pDatasetRaster = pDatasetRaster;
	m_bReadFirst= true;
}

SuperMapFeatureReader::~SuperMapFeatureReader (void)
{
	Close();
}

/** Do not implement the copy constructor. **/
//SuperMapFeatureReader::SuperMapFeatureReader (const SuperMapFeatureReader &right) { }

void SuperMapFeatureReader::Dispose ()
{
    delete this;
}

/// <summary>Gets the definition of the object currently being read. If the user
/// has requested only a subset of the class properties, the class 
/// definition reflects what the user has asked, rather than the full class 
/// definition.</summary>
/// <returns>Returns the class definition object.</returns> 
FdoClassDefinition* SuperMapFeatureReader::GetClassDefinition ()
{
	return FDO_SAFE_ADDREF(m_ClassDef.p);
}

/// <summary>Gets a value indicating the depth of nesting for the current reader.
/// The depth value increases each time GetFeatureObject is called and a new 
/// reader is returned. The outermost reader has a depth of 0.</summary>
/// <returns>Returns the depth</returns> 
FdoInt32 SuperMapFeatureReader::GetDepth ()
{
	return 0; //not support nest now
}

/// <summary>Gets a reference to an FdoIFeatureReader to read the data contained in
/// the object or object collection property. If the property is not an
/// object property, an exception is thrown.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the nested feature reader</returns> 
FdoIFeatureReader* SuperMapFeatureReader::GetFeatureObject (FdoString* propertyName)
{
	return NULL; //not supported now
}

/// <summary>Gets the geometry value of the specified property as a byte array in 
/// FGF format. Because no conversion is performed, the property must be
/// of Geometric type; otherwise, an exception is thrown. 
/// This method is a language-specific performance optimization that returns a
/// pointer to the array data, rather than to an object that encapsulates
/// the array.  The array's memory area is only guaranteed to be valid
/// until a call to ReadNext() or Close(), or the disposal of this reader
/// object.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <param name="count">Output the number of bytes in the array.</param> 
/// <returns>Returns a pointer to the byte array in FGF format.</returns> 
const FdoByte* SuperMapFeatureReader::GetGeometry (FdoString* identifier, FdoInt32 * count)
{
	FdoPtr<FdoByteArray> byteArray = GetGeometry (identifier);
	if(NULL == byteArray)
	{
		return NULL;
	}
	FdoByte *ret = byteArray->GetData();
	*count = byteArray->GetCount();

	return ret;
}

/// <summary>Gets the geometry value of the specified property as a byte array in 
/// FGF format. Because no conversion is performed, the property must be
/// of Geometric type; otherwise, an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the byte array in FGF format.</returns> 
FdoByteArray* SuperMapFeatureReader::GetGeometry (FdoString* identifier)
{
	TRACE(_T("��ʼ���� SuperMapFeatureReader::GetGeometry()... \n"));
	if(NULL == m_pRecordset || NULL == identifier)
		return NULL;
	
	FdoPtr<FdoByteArray> ret; //the result for return
	SuperMapGeoToFgfGeo FgfGeo(m_pRecordset);
	ret = FgfGeo.GetGeometry();

	if(NULL == ret)
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "No geometry has been queried (%1$ls).","GetGeometry"));
	
	return FDO_SAFE_ADDREF(ret.p);
}

//-------------------------------------------------------
// FdoIReader implementation
//-------------------------------------------------------

/// <summary>Gets the Boolean value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Boolean or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the Boolean value.</returns> 
bool SuperMapFeatureReader::GetBoolean (const FdoString* identifier)
{
	//TODO::�ٲ���һ��ORAһ����Ƿ�һ��

	if(NULL == m_pRecordset || NULL == identifier)
	{
		return false;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();

	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Byte) // UGC��������󣬸������涼���ڸ��ֶ��У�ͳһ��
	{
		unsigned char ret = var.GetValue().bVal;
		TRACE(_T("���� SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
		if (ret)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//if(var.GetType() == UGC::UGVariant::Short) // sdb/sdb+ �������SVal�ֶ���
	//{
	//	short ret = var.GetValue().sVal;
	//	TRACE(_T("���� SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
	//	if (ret)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	//if (var.GetType() == UGC::UGVariant::Integer) //SQL/SQL+ �������IVal�ֶ���
	//{
	//	int ret = var.GetValue().iVal;
	//	TRACE(_T("���� SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
	//	if(ret)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not bool (%1$ls).", "GetBoolean"));
	}
}

/// <summary>Gets the byte value of the specified property. No conversion is 
/// performed, thus the property must be FdoDataType_Byte or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the byte value.</returns> 
FdoByte SuperMapFeatureReader::GetByte (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}
	
	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Byte)
	{
		FdoByte ret = (FdoByte)var.GetValue().bVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not byte (%1$ls).", "GetByte"));
	}
}

/// <summary> Gets the date and time value of the specified property. No conversion is 
/// performed, thus the property must be FdoDataType_DateTime or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the date and time value.</returns> 
FdoDateTime SuperMapFeatureReader::GetDateTime (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		FdoDateTime Ftime;
		return Ftime;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);

	//if(var.GetType() == UGC::UGVariant::Double) //sdb/sdb+ ���潫ʱ��ֵ����dVal��
	//{
	//	double timeVar = var.GetValue().dVal;
	//	UGC::UGTime ugTime(timeVar);

	//	FdoDateTime Ftime((FdoInt16)ugTime.GetYear(), 
	//		(FdoInt8)ugTime.GetMonth(), 
	//		(FdoInt8)ugTime.GetDay(),
	//		(FdoInt8)ugTime.GetHour(), 
	//		(FdoInt8)ugTime.GetMinute(), 
	//		(float)ugTime.GetSecond());

	//	return Ftime;
	//}
	
	if(var.GetType() == UGC::UGVariant::Time) //UGC��������󣬸������涼���ڸ��ֶ��У�ͳһ��
	{
		double timeVar = var.GetValue().tVal;
		UGC::UGTime ugTime(timeVar);

		FdoDateTime Ftime((FdoInt16)ugTime.GetYear(), 
							(FdoInt8)ugTime.GetMonth(), 
							(FdoInt8)ugTime.GetDay(), 
							(FdoInt8)ugTime.GetHour(), 
							(FdoInt8)ugTime.GetMinute(), 
							(FdoInt8)ugTime.GetSecond());
		//TRACE(_T("���� SuperMapFeatureReader::GetDateTime().��[%d].��[%d].��[%d].ʱ[%d].��[%d].��[%f]. \n"), Ftime.year, Ftime.month, Ftime.day, Ftime.hour, Ftime.minute, Ftime.seconds);
		return Ftime;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not datatime (%1$ls).", "GetDateTime"));
		//TODO::�ٲ����Ƿ�Ҫ��
		FdoDateTime Ftime;
		return Ftime;
	}
}

/// <summary>Gets the double-precision floating point value of the specified property. No
/// conversion is performed, thus the property must be FdoDataType_Double
/// or an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the double floating point value</returns> 
double SuperMapFeatureReader::GetDouble (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;

	// added by zhoux 2007-12-10 for �ı����ݼ���TEXT_SIZE_PROPERTY�ֶ�������Ϊ�����ݼ����ı���С�ֶ�

	UGC::UGDatasetVector* pDatasetVector = m_pRecordset->GetDataset();
	VALIDATE_POINTER(pDatasetVector);

	if((pDatasetVector->GetType() == UGC::UGDataset::Text) && (0 == wcscmp(identifier,TEXT_SIZE_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		m_pRecordset->GetGeometry((UGC::UGGeometry*&)pGeoText); // pGeoText ��Ҫ���ڲ�����ռ䣬��Ҫ�ͷ�
		if(pGeoText != NULL)  //��ʱ�������ı��Ӷ����������1����� ToDo:
		{
			UGC::UGTextStyle textStyle = pGeoText->GetTextStyle();     
			double retSize = textStyle.GetHeight(); // ȡ��С
			delete pGeoText;
			return retSize;	
		}
		else
		{
			return 0.0;
		}
	}
	// end added 

	// added by zhoux 2008-4-28 ֧�ָ������ݼ����ı�����
	if((pDatasetVector->GetType() == UGC::UGDataset::CAD) && (0 == wcscmp(identifier,TEXT_SIZE_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		UGC::UGGeometry* pGeometry = NULL;
		m_pRecordset->GetGeometry(pGeometry); // pGeoText ��Ҫ���ڲ�����ռ䣬��Ҫ�ͷ�
		if(pGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			//�������ݼ��з��ı�����Ĵ��ֶ�ֵ��Ϊ0.0
			return 0.0;
		}
		pGeoText = (UGC::UGGeoText*)pGeometry ;
		if(pGeoText != NULL)  //��ʱ�������ı��Ӷ����������1����� ToDo:
		{
			UGC::UGTextStyle textStyle = pGeoText->GetTextStyle();     
			double retSize = textStyle.GetHeight(); // ȡ��С
			delete pGeoText;
			return retSize;	
		}
		else
		{
			return 0.0;
		}
	}
	// end added 

	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Double)
	{
		double ret = var.GetValue().dVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not double (%1$ls).", "GetDouble"));
	}
}

/// <summary>Gets the 16-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int16 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt16 value.</returns> 
FdoInt16 SuperMapFeatureReader::GetInt16 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Short) //UGC��������󣬸������涼���ڸ��ֶ��У�ͳһ��
	{
		FdoInt16 ret = (FdoInt16)var.GetValue().sVal;
		return ret;
	}
	//if(var.GetType() == UGC::UGVariant::Integer) //Oracle �����ͷ��ڴα�����
	//{
	//	FdoInt32 ret = (FdoInt16)var.GetValue().iVal;
	//	return ret;
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not short (%1$ls).", "GetInt16"));
	}
}

/// <summary>Gets the 32-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int32 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt32 value</returns> 
FdoInt32 SuperMapFeatureReader::GetInt32 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Integer)
	{
		FdoInt32 ret = (FdoInt32)var.GetValue().iVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not int (%1$ls).", "GetInt32"));
	}
}

/// <summary>Gets the 64-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int64 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt64 value.</returns> 
FdoInt64 SuperMapFeatureReader::GetInt64 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Long)
	{
		FdoInt64 ret = (FdoInt64)var.GetValue().lVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not long (%1$ls).", "GetInt64"));
	}
}

/// <summary>Gets the Single floating point value of the specified property. No
/// conversion is performed, thus the property must be FdoDataType_Single
/// or an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the single value</returns> 
float SuperMapFeatureReader::GetSingle (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Float) //UGC��������󣬸������涼���ڸ��ֶ��У�ͳһ��
	{
		float ret = var.GetValue().fVal;
		return ret;
	}
	//if(var.GetType() == UGC::UGVariant::Double) //Oracle �����ȷ��ڴ˱�����
	//{
	//	double ret = var.GetValue().dVal;
	//	TRACE(_T("���� SuperMapFeatureReader::GetSingle[%g] \n"), ret);
	//	return ret;
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not float (%1$ls).", "GetSingle"));
	}
}

/// <summary>Gets the string value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_String or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the string value</returns> 
FdoString* SuperMapFeatureReader::GetString (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return NULL;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;

	// added by zhoux 2007-11-28 for �ı����ݼ���TEXT_PROPERTY�ֶ�������Ϊ�����ݼ����ı��ֶ�

	UGC::UGDatasetVector* pDatasetVector = m_pRecordset->GetDataset();
	VALIDATE_POINTER(pDatasetVector);
	if((pDatasetVector->GetType() == UGC::UGDataset::Text) && (0 == wcscmp(identifier,TEXT_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		m_pRecordset->GetGeometry((UGC::UGGeometry*&)pGeoText); // pGeoText ��Ҫ���ڲ�����ռ䣬��Ҫ�ͷ�
		if(pGeoText != NULL)  //�����ı��Ӷ����������1����������ı����ݺϲ�:
		{
			FdoStringP tmpString;
			m_CachedString = L"";
			for(FdoInt32 i = 0; i < pGeoText->GetSubCount(); ++i)
			{
				tmpString = SuperMapUtil::StringToWString(pGeoText->GetSub(i).GetText().Cstr()).c_str();
				m_CachedString += tmpString;
			}
			delete pGeoText;
			return m_CachedString.operator FdoString*( );	
		}
		else
		{
			return L"";
		}
	}
	// end added 

	// added by zhouxu 2008-4-28  ֧�ָ������ݼ��е��ı�����
	if((pDatasetVector->GetType() == UGC::UGDataset::CAD) && (0 == wcscmp(identifier,TEXT_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		UGC::UGGeometry* pGeometry = NULL;
		m_pRecordset->GetGeometry(pGeometry); // pGeometry ��Ҫ���ڲ�����ռ䣬��Ҫ�ͷ�
		if(pGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			//���ڸ������ݼ��ķ��ı����󣬴��ֶ���Ϊ��
			return L"";
		}
		pGeoText = (UGC::UGGeoText*)pGeometry;
		if(pGeoText != NULL)  //�����ı��Ӷ����������1����������ı����ݺϲ�:
		{
			FdoStringP tmpString;
			m_CachedString = L"";
			for(FdoInt32 i = 0; i < pGeoText->GetSubCount(); ++i)
			{
				tmpString = SuperMapUtil::StringToWString(pGeoText->GetSub(i).GetText().Cstr()).c_str();
				m_CachedString += tmpString;
			}
			delete pGeoText;
			return m_CachedString.operator FdoString*( );	
		}
		else
		{
			return L"";
		}
	}
	// end added
	
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::String)
	{
		/*char *strHeader = (char*)var.GetValue().pVal;
		strHeader += 4;
		m_CachedString = SuperMapUtil::StringToWString(strHeader).c_str();
		return m_CachedString.operator FdoString*( );*/	
		
		UGC::UGString StrVal = "";
		StrVal = var.ToString();
		m_CachedString = SuperMapUtil::StringToWString(StrVal.Cstr()).c_str();
		if(StrVal.GetLength() == 0)
		{
			TRACE(_T("���� SuperMapFeatureReader::GetString()..�ַ���Ϊ��! \n"));
		}
		return m_CachedString.operator FdoString*( );
	}

	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not string (%1$ls).", "GetString"));
	}
}

/// <summary>Gets a LOBValue reference. The LOB is fully read in and data available.
/// Because no conversion is performed, the property must be FdoDataType_BLOB or
/// FdoDataType_CLOB etc. (a LOB type)
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the reference to LOBValue</returns> 
FdoLOBValue* SuperMapFeatureReader::GetLOB (FdoString* identifier)
{
	return NULL; //not support now;
}

/// <summary>Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
/// FdoCLOBStreamReader etc. to allow reading in blocks of data.
/// Because no conversion is performed, the property must be FdoDataType_BLOB 
/// or FdoDataType_CLOB etc. (a LOB type)
/// Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns a reference to a LOB stream reader</returns> 
FdoIStreamReader* SuperMapFeatureReader::GetLOBStreamReader(FdoString* identifier)
{
	return NULL; //not support now;
}

/// <summary>Returns true if the value of the specified property is null.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns true if the value is null.</returns> 
bool SuperMapFeatureReader::IsNull (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return true;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	if(wcscmp(GEOMETRY_PROPERTY, identifier) == 0) //�ռ���Ϣ
	{
		if(m_pRecordset->HasGeometry())//�м�����Ϣ
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// added by zhouxu 2007-11-28
	if(wcscmp(TEXT_PROPERTY, identifier) == 0)
	{
		return false; 
	}
	
	// added by zhouxu 2007-12-10
	if(wcscmp(TEXT_SIZE_PROPERTY, identifier) == 0)
	{
		return false;
	}

	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);//TRACE(_T("���� SuperMapFeatureReader::ISNull()..[%ls].[%d] \n"), identifier, var.GetType());
	if(var.GetType() == UGC::UGVariant::Null) //if the value of this property is NULL
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>Gets the raster object of the specified property.
/// Because no conversion is performed, the property must be
/// of Raster type; otherwise, an exception is thrown.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the raster object.</returns> 
FdoIRaster* SuperMapFeatureReader::GetRaster (FdoString* identifier)
{
	if(NULL == m_pDatasetRaster || NULL == identifier)
	{
		return NULL;
	}
	FdoPtr<FdoIRaster> rv = new SuperMapRaster(m_pDatasetRaster, FDO_SAFE_ADDREF(m_ClassDef.p));
	return FDO_SAFE_ADDREF(rv.p);
}

/// <summary>Advances the reader to the next item and returns true if there is
/// another object to read or false if reading is complete. The default
/// position of the reader is prior to the first item. Thus you must
/// call ReadNext to begin accessing any data.</summary>
/// <returns>Returns true if there is a next item.</returns> 
bool SuperMapFeatureReader::ReadNext ()
{
	TRACE(_T("��ʼ���� SuperMapFeatureReader::ReadNext()... \n"));
	if( NULL == m_pDatasetRaster ) //����ʸ�����ݼ�
	{
		if(NULL == m_pRecordset)
		{
			return false;
		}

		if (m_bReadFirst)
		{
			if (!m_pRecordset->IsEmpty()) //��¼������
			{
				m_pRecordset->MoveFirst();
				m_bReadFirst = false;
			}
			else //��¼����
			{
				return false;
			}		
		}
		else
		{
			m_pRecordset->MoveNext();
		}

		if (!m_pRecordset->IsEOF())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else //����դ�����ݼ�
	{
		if (m_bReadFirst)
		{
			m_bReadFirst = false;
			return true;
		}
		else
		{
			return false;
		}
	}
}

/// <summary>Closes the Reader object, freeing any resources it may be holding.</summary>
/// <returns>Returns nothing</returns> 
void SuperMapFeatureReader::Close ()
{
	if(NULL != m_pRecordset)
	{
		UGC::UGDatasetVector *pDataset = m_pRecordset->GetDataset();
		// ����UGC��ԭ�򣬻����ֶ��ͷŲ�ѯ�ļ�¼��
		pDataset->ReleaseRecordset(m_pRecordset);
		m_pRecordset = NULL;
		pDataset->Close();
	}
}

//four functions do with the SuperMapDataReader
FdoInt32 SuperMapFeatureReader::GetPropertyCount()
{
	FdoInt32 nPropCount = 0;
	if(NULL != m_pRecordset)
	{
		nPropCount =  m_pRecordset->GetFieldCount();
	}
	return nPropCount;
}

FdoString* SuperMapFeatureReader::GetPropertyName(FdoInt32 index)
{
	UGC::UGFieldInfo fieldInfo;
	FdoString *ret = NULL;
	if(NULL != m_pRecordset)
	{
		m_pRecordset->GetFieldInfo(index, fieldInfo);
		ret = SuperMapUtil::StringToWString(fieldInfo.m_strName.Cstr()).c_str();
	}
	return ret;
}

FdoDataType SuperMapFeatureReader::GetDataType(FdoString* propertyName)
{
	UGC::UGString strProperName = SuperMapUtil::WcharToString(propertyName).c_str();
	UGC::UGFieldInfo fieldInfo;
	FdoDataType nDataType = FdoDataType_Int32;
	if(m_pRecordset)
	{
		m_pRecordset->GetFieldInfo(strProperName, fieldInfo);
		switch(fieldInfo.m_nType)
		{
		case UGC::UGFieldInfo::Boolean:
			nDataType = FdoDataType_Boolean;
			break;

		case UGC::UGFieldInfo::Byte:
		case UGC::UGFieldInfo::Char:
			nDataType = FdoDataType_Byte;
			break;

		case UGC::UGFieldInfo::Integer:
			nDataType = FdoDataType_Int16;
			break;

		case UGC::UGFieldInfo::Long:   
			nDataType = FdoDataType_Int32;
			break;

		case UGC::UGFieldInfo::Single:
		case UGC::UGFieldInfo::Float:
			nDataType = FdoDataType_Single;
			break;

		case UGC::UGFieldInfo::Double:
			nDataType = FdoDataType_Double;
			break;

		case UGC::UGFieldInfo::Date:
		case UGC::UGFieldInfo::Time:
		case UGC::UGFieldInfo::TimeStamp:
			nDataType = FdoDataType_DateTime;
			break;

		case UGC::UGFieldInfo::Decimal:
			nDataType = FdoDataType_Decimal;
			break;

		case UGC::UGFieldInfo::Binary:
		case UGC::UGFieldInfo::LongBinary:
		case UGC::UGFieldInfo::VarBinary:
			nDataType = FdoDataType_BLOB;
			break;

		case UGC::UGFieldInfo::Text:
			nDataType = FdoDataType_String; 
			break;

		default:
			break;
		}
	}
	return nDataType;
}

FdoPropertyType SuperMapFeatureReader::GetPropertyType(FdoString* propertyName)
{
	FdoPropertyType nPropType = FdoPropertyType_DataProperty;
	if( wcscmp(propertyName, GEOMETRY_PROPERTY) == 0)
	{
		nPropType = FdoPropertyType_GeometricProperty;
	}
	return nPropType;

}
