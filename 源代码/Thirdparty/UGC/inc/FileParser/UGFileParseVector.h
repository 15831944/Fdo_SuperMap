
/*!
    **************************************************************************************
     \file     UGFileParseVector.h
    **************************************************************************************
     \author   ����
     \brief    �ļ�����ʸ����               
     \remarks   ����ʸ�������඼�����̳�                                                                       <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
#define AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_



#include "UGFileParse.h"
#include "Base/UGList.h"
#include "Base/UGDict.h"
#include "Engine/UGFieldInfo.h"
#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoRegion.h"
#include "Geometry/UGGeoText.h"
#include "Geometry/UGGeoCompound.h"
#include "Geometry/UGGeoMultiPoint.h"
#include "UGStyleMapperDefn.h"

namespace UGC {

	class UGGeometry;
	
class FILEPARSER_API UGFileParseVector : public UGFileParse  
{
public:

	UGFileParseVector();
	virtual ~UGFileParseVector();
public:

	//////////////////////////////////////////////////////////////////////////
	// �������ú���
	//////////////////////////////////////////////////////////////////////////

	//! brief ���õ���ӳ���
	virtual void SetSymbolStyleMapper(UGSymbolStyleMapper SymbolStyleMapper);	
	//! brief ��������ӳ���
	virtual void SetPenStyleMaper(UGPenStyleMapper PenStyleMapper);	
	//! brief ���������ӳ���
	virtual void SetBrushStyleMapper(UGBrushStyleMapper BrushStyleMapper);	
	//! brief ����������ӳ���
	virtual void SetFontStyleMapper(UGFontStyleMapper FontStyleMapper);

	//! \brief	�������굥λ			
	virtual void SetDesUnits(UGint nDesUnits);
	//! \brief	�����û�ָ��Ҫ�����ͼ������ּ��ϣ�����û�г�Ա��������������ʵ�֣�
	virtual void SetLayers(const UGList<UGString>& layers);
	//! \brief	���õ���򵼳�ͼ���ֶ���������û�г�Ա��������������ʵ�֣�
	virtual void SetLayerName(const UGString& strLayerName);
	//! \brief	���õ���򵼳�����ֶ���������û�г�Ա��������������ʵ�֣�
	virtual void SetElevationName(const UGString& strElevationName);

	//! \brief	���õ����Ƿ����
	virtual void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);
	//! \brief	���õ����Ƿ��������
	virtual void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);
	//! \brief	���õ����Ƿ��������
	virtual void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);
	//! \brief	���õ����Ƿ���Է��
	virtual void SetIsIgnoreStyle(UGbool bIgnoreStyle);

	//! \brief ���õ���ΪCAD���ݼ�������ֵ����IsImportAsCAD������������CAD���ݼ�ר�ã�
	virtual UGbool SetIsImportAsCAD(UGbool bImportAsCADDataset);
	
	//////////////////////////////////////////////////////////////////////////
	// ����ѯ�ʺ���
	//////////////////////////////////////////////////////////////////////////

	//! \brief �Ƿ���Ե���ΪCAD���ݼ�
	virtual UGbool IsImportAsCAD();

	//! \brief �Ƿ���ͶӰ
	virtual UGbool IsProject();

	//! \brief �Ƿ��е�������ݼ������ָ���ͼ�����������������û�����������������
	//! ��Щ���ݵ���ʱ��һ������
	virtual UGbool IsDatasetNameByLayer();

	//////////////////////////////////////////////////////////////////////////
	// ��ȡ����
	//////////////////////////////////////////////////////////////////////////

	//! \brief �õ�����ο�ϵͳ
	virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef);

	//! \brief �õ���ǰͼ��Ķ�����
	virtual UGint GetFeatureCount();

	//! \brief �õ���ǰͼ��ķ�Χ
	virtual UGRect2D GetLayerExtent();

	//! \brief �õ�ָ��ͼ����ֶ���Ŀ
	virtual UGint GetFieldCount(UGint nLayerIndex);

	//! \brief �õ�ָ��ͼ�㡢ָ���ֶ���ŵ��ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nLayerIndex, UGint nFieldIndex, UGFieldInfo &fieldInfo);

	//! \brief �õ�ָ��ͼ�����չ�ֶε���Ŀ
	virtual UGint GetExtendFieldCount(UGint nLayerIndex);

	//! \brief �õ�ָ��ͼ�㡢ָ���ֶ���ŵ���չ�ֶ���Ϣ
	virtual UGbool GetExtendFieldInfo(UGint nLayerIndex, UGint nFieldIndex, 
							  UGString& strFieldName, UGint& nFieldType, UGint& nFieldSize);

	//! \brief �õ���ǰ��¼�ġ�ָ����ŵ���չ�ֶ�ֵ��
	virtual UGbool GetExtendFieldValue(UGint nIndex, UGVariant& value);

	

	//! \brief �Ѷ��ļ���ָ�������������ļ�ͷ�������Ϳ������¶�ȥ�ļ�
	virtual void ResetReading();

	//! \brief ��ʼ��ȡ��¼���ڵ�һ�ε��ö�ȡ��¼ǰ��������á�
	virtual void BeginReadRecord();

	//! \brief �Ƿ��Ѿ���ȡ���ļ�β�ˣ������Ϊ��ȡ�����ı�־
	//! \remarks ������Ϊ���麯������Ϊ�ļ���������û����������������ѭ���ģ�����Ҫ
	//! \return ����true,˵���ѵ��ļ�β,��Ҫ������ȡ��
	virtual UGbool IsEOF() = 0;

	//! \brief ��ʼ��ȡһ����¼��
	virtual void BeginReadOneRecord();

	//! \brief ��ȡһ����¼�еļ��ζ���
	//! \remarks �������false��ֻ˵����ȡ����Geometry�����⣬���������Ѿ�����
	//! ��ȡ�ļ��Ƿ������ʹ��IsEOF�����ж�
	virtual UGbool ReadOneGeometry(UGGeometry*& pGeometry);

	//! \brief �õ���ǰ���ζ�������ͼ������֣������ͼ�㲻��Ҫת����ô�Ͳ���Ҫ��ȡ������ζ���
	virtual UGString GetLayerOfGeometry();

	//! \brief �õ���ǰ��¼�ġ�ָ����ŵ��ֶ�ֵ��
	virtual UGbool GetFieldValue(UGint nIndex, UGVariant& value);

	//! \brief ������ȡһ����¼��
	virtual void EndReadOneRecord();

	//! \brief �õ���ǰ�Ѿ���������ݵİٷֱ�
	//! \remarks ���ڲ��ṩ�ܼ�¼���ĺ���,�ʶ���������Ҫ�������
	virtual UGint GetCurrentPercent();

	//! \brief ������ȡ���м�¼
	virtual void EndReadRecord();


	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////

	//! \brief ���õ���ռ�ο�ϵ��
	//virtual void SetSpatialRef(const Projection::CSmSpatialRef& spatialRef);
	
	//! \brief ����ָ��ͼ����ֶ�������
	virtual void SetFieldCount(UGint nLayerIndex, UGint nFieldCount);
	
	//! \brief ����ָ��ͼ���ָ���ֶ���ŵ��ֶ���Ϣ��
	virtual void SetFieldInfo(UGint nLayerIndex, UGint nFieldIndex, 
					const UGString& strFieldName, UGint nFieldType, UGint nFieldSize);

	//! \brief ��ʼ׼��д���¼��������д���¼ǰ������á�
	virtual void BeginWriteRecord();

	//! \brief ׼��д��һ����¼
	virtual void BeginWriteOneRecord();
	
	//! \brief д��һ����¼�ļ��ζ���
	virtual UGbool WriteOneGeometry(UGGeometry* pGeometry, 
								  const UGString& strLayerName);
	
	//! \brief ���õ�ǰ��¼��ָ����ŵ��ֶ�ֵ��
	virtual void SetFieldValue(UGint nIndex, const UGVariant& value);
	
	//! \brief ����д��һ����¼��
	virtual void EndWriteOneRecord();

	//! \brief ���� ���еļ�¼��д��
	virtual void EndWriteRecord();
	
protected:
	//! \brief �Ƿ���Է��
	UGbool m_bIgnoreStyle;

	//! \brief �Ƿ��������ϵͳ
	UGbool m_bIgnoreCoordSys;

protected:
	//! brief ���Ŷ��ձ�
	UGSymbolStyleMapper m_SymbolStyleMapper;	
	//! brief ���Ͷ���
	UGPenStyleMapper m_PenStyleMapper;	
	//! brief ��������
	UGBrushStyleMapper m_BrushStyleMapper;	
	//! brief ��������
	UGFontStyleMapper m_FontStyleMapper;	
};

} //namespace UGC

#endif // !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
