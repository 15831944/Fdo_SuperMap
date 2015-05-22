/*! \file	 UGGeoText.h
 *  \brief	 �ı�������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
<<<<<<< UGGeoText.h
 *  \version $Id: UGGeoText.h,v 1.51 2007/12/07 10:42:18 qiuli Exp $
=======
 *  \version $Id: UGGeoText.h,v 1.51 2007/12/07 10:42:18 qiuli Exp $
>>>>>>> 1.34.2.1
 */


#ifndef UGGEOTEXT_H
#define UGGEOTEXT_H

#include "UGGeometry.h"
#include "Base/UGString.h"
#include "Base/UGTextStyle.h"

namespace UGC {

//! \brief �ı��Ӷ���
class GEOMETRY_API UGSubText 
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGSubText();

	//! \brief �������캯����
	//! \param subText [in] ���е��ı��Ӷ���
	UGSubText(const UGSubText& subText);	

	//! \brief ���ı������ַ������й���
	//! \param strText [in] �ı������ַ�����
	//! \param dAngle [in] ��ת�Ƕ�,Ĭ��Ϊ0
	UGSubText(const UGString& strText, UGdouble dAngle=0);
	
	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	UGdouble GetAngle() const;	

	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	void SetAngle(UGdouble dAngle);	
	
	//! \brief �õ��ı����ݡ�
	//! \return �����ı����ݡ�
	UGString GetText() const;	

	//! \brief �����ı����ݡ�
	//! \param strText [in] �ı����ݡ�
	void SetText(const UGString& strText);	
	
	//! \brief ��ֵ������
	//! \param subText [in] ���е��ı��Ӷ���
	void operator=(const UGSubText& subText);
	
private:
	// modified by zengzm 2007-4-27 
	//UGint m_nAngle; //! ���ı�����ǣ���λΪ 0.1��, ��ʱ�뷽��
	//! \brief ���ı�����ת�Ƕ�, ��λΪ:��, ��ʱ�뷽��
	//! \remarks �ڴ��и�Ϊdouble,�Ƕȵ�λ,�洢ʱ��SFC���ּ���
	UGdouble m_dAngle;
	
	//! \brief Ԥ��
	//UGint m_nReserved;

	//! \brief �ı������ַ���
	UGString m_strText;
};



//! \brief �ı�������
//! \remarks ���ı�����,�����ж���ı��Ӷ���,ÿ���ı��Ӷ������Լ���ê�����ת�Ƕ�,
//! ���ı��ķ����ͳһ��,ֻ���ı�������һ��.
class GEOMETRY_API UGGeoText : public UGGeometry
{
public:
	//! \brief ���캯��
	UGGeoText();
	
	//! \brief ��������
	virtual ~UGGeoText();
	
public: 
	
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ-1
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����,�̶�ΪGeoText
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return ���ص�һ���Ӷ����ê��
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;	

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual UGint GetSubCount() const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 
	
public:
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public://��Ҫ����ʵ�ֵķ���
	
	//! \brief ���÷��
	//! \param pStyle ���ָ��
	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻delete; ����Ḵ��һ�ݷ��
	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
	virtual void SetStyle(const UGStyle* pStyle);
	
	
public: //! group �����ı�����
	//! \brief ͨ���ı�����/ê��/��ת�Ƕ��������ı�����
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ����true��
	UGbool Make(const UGString& strText, const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı�����(�����ı�)
	//! \param strText [in] �ı����ݡ�
	//! \param geoline [in] Ҫ���ߵ��ߡ�
	//! \param bFixedAngle [in] �Ƿ�̶��Ƕȡ�
	//! \param dAngle [in] �̶��Ƕ�ʱ���ı��Ƕȡ�
	//! \return ����ı�Ϊ��,�����߶���Ƿ�,����false��
	UGbool Make(const UGString& strText, const UGGeoLine& geoline, 
						UGbool bFixedAngle=FALSE, UGdouble dAngle=0.0);	
	
	//! \brief �����ı�����(Ĭ�Ϸ��)
	//! \param pntAnchor [in] ê��(�ı�����Ķ�λ��)��
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true
	UGbool Make(const UGPoint2D& pntAnchor, const UGSubText& subText);	

	//! \brief �����ı�����(ָ�����,���ж���Ӷ���)
	//! \param textStyle [in] �ı����
	//! \param pPoints [in] �ı��Ӷ���Ķ�λ��㴮ָ�롣
	//! \param pSubText [in] �ı��Ӷ����ָ�롣
	//! \param nSubCount [in] �ı��Ӷ������Ŀ��
	//! \return ����true��
	UGbool Make(const UGTextStyle& textStyle, const UGPoint2D* pPoints, const UGSubText* pSubText, UGint nSubCount);	

	//! \brief ͨ�����ƹ����ı�����
	//! \param geotext [in] ���е��ı�����
	//! \return ����true��
	UGbool Make(const UGGeoText& geotext);	
	
	//! \brief �����ı��Ӷ���
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] �Ӷ����ê�㡣
	//! \param dAngle=0.0 [in] �Ӷ������ת�Ƕȡ�
	//! \return ����true��
	UGbool AddSub(const UGString& strText, const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	

	//! \brief �����ı��Ӷ���
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ����true��
	UGbool AddSub(const UGPoint2D& pntAnchor, const UGSubText& subText);	

	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return 
	UGbool InsertSub(UGint nIndex, const UGString& strText, const UGPoint2D& pntAnchor,UGdouble dAngle);	

	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] �����λ��������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ��
	UGbool InsertSub(UGint nIndex, const UGPoint2D& pntAnchor, const UGSubText& subText);	
	
	//! \brief ɾ���ı��Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ���λ��������
	//! \return �����Ƿ�,����false��
	UGbool DelSub(UGint nIndex);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param strText [in] �ı����ݡ�
	//! \param pntAnchor [in] ê�㡣
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \return ��
	UGbool SetSub(UGint nIndex, const UGString& strText, 
				const UGPoint2D& pntAnchor, UGdouble dAngle=0.0);	
	
	//! \brief �����ı��Ӷ���
	//! \param nIndex [in] ���õ�������
	//! \param pntAnchor [in] ê�㡣
	//! \param subText [in] �ı��Ӷ���
	//! \return ��
	UGbool SetSub(UGint nIndex, const UGPoint2D& pntAnchor, const UGSubText& subText);	
	
	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	const UGSubText& GetSub(UGint nIndex) const {return m_SubTexts[nIndex];}	

	//! \brief �õ��ı��Ӷ���
	//! \param nIndex [in] λ��������
	//! \return �����ı��Ӷ���
	UGSubText& GetSub(UGint nIndex) {return m_SubTexts[nIndex];}
	
	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	const UGPoint2D& GetSubAnchor(UGint nIndex) const {return m_Points[nIndex];}	

	//! \brief �õ��ı��Ӷ����ê�㡣
	//! \param nIndex [in] Ҫ�õ��Ӷ����λ��������
	//! \return ����ê�������á�
	UGPoint2D& GetSubAnchor(UGint nIndex) {return m_Points[nIndex];}
	
	//! \brief �����ı����
	//! \param textStyle [in] �ı����
	void SetTextStyle(const UGTextStyle& textStyle);	

	//! \brief �õ��ı����
	//! \return �����ı����
	const UGTextStyle& GetTextStyle() const;	
	
	//! \brief ȡ���ı������������(���е��Ӷ�������ִ��ĺϲ�,ȥ���ո񡢻��е�)
	//! \remarks 
	//!		1) ȥ��ǰ��� �ո�/�س�����/Tab ���ַ�
	//!		2) �м�� �ո�/�س�����/Tab , ���ǰ���� ����/���� ��, Ҳȥ��
	//!		3) ���ǰ���� Ӣ��(or���ֵ�ACSII��), �� ����һ���ո�(�س�����/Tab��Ҳת��Ϊһ���ո�)
	//! ԭ��: ����ӿھ������� ���� �ַ����Ƚϲ�ѯ��, �� �����ı����ݼ��� ToString ��, 
	//! ���浽�ı��ֶ���, Ȼ�� �û��Ϳ��Ժܷ���� ���ֶ��н��� ����, 
	//! �� ��ͼ����ʾ�� ��Ҫ д��" I am   \r\n a student.   ", �� �û������Ա��в�ѯʱ, 
	//! ֻ��Ҫ ���� "I am a student.", �ﵽ���뼴���� ��Ч��
	//!	��:��" I am   \r\n a student.   " ��Ϊ "I am a student."
    //!					 "Hello, \r�й� "  			  ��Ϊ "Hello,�й�"
    //!					 "Abc\rABC"					  ��Ϊ "Abc ABC"
	//! \return �����ı�����ĺϲ����
	UGString GetIndexString() const;		
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \remarks �ı������޷�ת��,�̶�����false
	//! \return ����false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGlong nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \remarks �ı������޷�ת��,�̶�����false
	//! \return ����false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGlong nSegmentCount = 0 ) const;

#if PACKAGE_TYPE==PACKAGE_UGC
		
	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;
	
	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
	
#endif // end declare ugc sdk

public:
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ
	
	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
     virtual UGint  GetHandleCount();

	
	//nHandle:��ֵ����Ƶ�Ĺ�ϵ����ͼ                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	
	//! \brief ���ݾ�������Ӧ���Ƶ��ֵ
	//! \param nHandle ���Ƶ���
	//! \param point �����Ӧ�Ŀ��Ƶ������ֵ
	//! \return ���ظ����������
	 virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle ���Ƶ���
	//! \param point ���Ƶ�����
	 virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);


	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);

	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	 //GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual UGbool GetSnapLines(UGLineArray& aryLines);

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end

	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���
	virtual void SetTextCharset(UGTextCodec::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual void ChangeTextCharset(UGTextCodec::Charset nCharset);
private: //! �ڲ���������
	//! \brief �ı�ͷ
	UGTextStyle m_textStyle;
	
	//! \brief �Ӷ���λ��
	UGArray<UGPoint2D> m_Points;
	
	//! \brief �Ӷ�������
	UGArray<UGSubText> m_SubTexts;
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	//! \brief 
	virtual UGRect2D ComputeBounds() const;
	/*virtual UGRect2D GetBoundsInside() const;
	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/
	
	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;
	//! \brief ��Stream������Geometry
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief ����һ���Ӷ����Bounds
	//! \param bConsiderRotation : �Ƿ�����ת
	//! \param bAlignOffset : �Ƿ���Align == 3,4,5 ʱ, �ı���ʾλ�õ�ƫ��
	
	UGRect2D ComputeSubBounds(UGint nSubIndex, 
		UGbool bConsiderRotation=true, UGbool bAlignOffset=false) const;
	
	//! \brief �����ı���Bounds�������Ѿ��ṩ�㹻�����Ϣ��
	static UGRect2D ComputeTextBounds(const UGString& strText,
		double dFontHeight, double dFontWidth, 
		const UGPoint2D& pntAnchor, 
		UGint nAlign, double dRadian=0, UGbool bAlignOffset=false);
	
	//! \brief �����ı����뷽ʽ������ƫ��
	//! \remarks ���뷽ʽΪ3 4 5 ʱ��������������룬����Baseline
	static UGRect2D AlignOffset(const UGRect2D& rcBounds, 
		UGint nAlign, double dFontHeight);
	
	// �ı��� Align == 3 4 5 ʱ, ��ʾ�����Ǿ��е�, ����BaseLine, 
	// ��ʾλ��Ҫ���� ƫ��һЩ, ������һ��ͳһ�ĺ�������ƫ�Ʊ���
	static double GetTextAlignOffset(UGbyte nAlign, double dFontHeight);
	
	//! \brief �õ��һ�е��ַ�����,  �������ַ���������
	//! \return ����ֵ:	UGSize::cx = �һ�е��ַ�����
	//!					UGSize::cy = �����ַ���������	
	static UGSize GetTextSize(const UGString& strText);
	
	//!  ������, ������ת֮��ľ���
	//! \param bAlign: ���뷽ʽ, ͬbCenterType
	//! \param dRadian: ��λ�ǻ���
	static UGRect2D UnionRotate(const UGRect2D& rcBounds, UGbyte bAlign, UGdouble dRadian); 
	
	//! \brief ��תһ��Rect2D�����ͨ��pPntResult���أ�pPntResult������4����Ŀռ�
	static void RotateRect(const UGRect2D& rcBounds, UGbyte bCenterType, UGdouble dRadian,
							UGPoint2D *pPntResult);
	
	void GetVertexes(UGint nIndex, UGPoint2D* pPoints) const;
};

}

#endif
