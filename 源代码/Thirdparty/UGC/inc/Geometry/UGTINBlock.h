// UGTINBlock.h: interface for the UGTINBlock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_)
#define AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "UGGeometry.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGLogFile.h"
//#include "GridAnalyst/UGMultiResolutionTIN.h"

namespace UGC {

class UGTriedge {
public:
	UGint tri;
	UGchar ori;

	UGTriedge()
	{
		tri = -1;
		ori = 0;
	}
	~UGTriedge()
	{
	}
	UGTriedge& operator = (const UGTriedge& triedge)
	{
		tri = triedge.tri;
		ori = triedge.ori;
		return *this;
	}
	UGbool operator == (const UGTriedge& triedge)
	{
		return tri == triedge.tri
			&& ori == triedge.ori;
	}
};

class UGTri {
public:
	
	UGbool  bConstrained[3];
	UGdouble dSlope;
	UGdouble dAspect;
	UGint  nTri[3];
	UGTriedge triedge[3];
	UGbool bDeleted;

	UGTri() 
	{
		nTri[0] = nTri[1] = nTri[2] = -1;
		bConstrained[0] = bConstrained[1] = bConstrained[2] = false;
		
		dSlope = 0.0;
		dAspect = 0.0;
		
		bDeleted = FALSE;
	}
	~UGTri()
	{
	}
	UGTri& operator = (const UGTri& tri)
	{
		bConstrained[0] = tri.bConstrained[0];
		bConstrained[1] = tri.bConstrained[1];
		bConstrained[2] = tri.bConstrained[2];
		dSlope = tri.dSlope;
		dAspect = tri.dAspect;
		nTri[0] = tri.nTri[0];
		nTri[1] = tri.nTri[1];
		nTri[2] = tri.nTri[2];
		triedge[0] = tri.triedge[0];
		triedge[1] = tri.triedge[1];
		triedge[2] = tri.triedge[2];
		bDeleted = tri.bDeleted;

		return *this;
	}
	void Init ()
	{
		nTri[0] = nTri[1] = nTri[2] = -1;
		bConstrained[0] = bConstrained[1] = bConstrained[2] = false;
		
		dSlope = 0.0;
		dAspect = 0.0;
		triedge[0].tri = triedge[1].tri = triedge[2].tri = -1;
		triedge[0].ori = triedge[1].ori = triedge[2].ori = 0;
		bDeleted = FALSE;
	}
};

struct TriLocation {
	UGTriedge triedge;
	UGint nBlockID;   // ������

	TriLocation& operator = (const TriLocation& triloc)
	{
		nBlockID = triloc.nBlockID;
		triedge = triloc.triedge;
		return *this;
	}
	UGbool operator == (const TriLocation& triloc)
	{
		return nBlockID == triloc.nBlockID 
			&& triedge == triloc.triedge;
	}
	UGbool operator != (const TriLocation& triloc)
	{
		return ! operator == (triloc);
	}
};


struct PntLocation {
	UGint nPntID;
	UGint nBlockID;
	PntLocation& operator = (const PntLocation& pntloc)
	{
		nPntID = pntloc.nPntID;
		nBlockID = pntloc.nBlockID;
		return *this;
	}
	UGbool operator == (const PntLocation& pntloc)
	{
		return nPntID == pntloc.nPntID 
			&& nBlockID == pntloc.nBlockID;
	}
};

struct TinBlock {
	UGTri* pTriangle;     // UGTri���е��ڽ���������Ϣ������洢�Ĳ����������ε�ָ�룬���������ε�id��
                          // �������������ڸÿ����⣬��ô��arrNeighbour���洢���ڵ���������Ϣ��

	UGPoint3D* pPnt;      // �ÿ��ڴ���malloc���䣬�ڴ�������У���ĸ��������ӣ��ǾͿ�����realloc��ʵ��

	PntLocation* pPntLocs;  // ���л���һЩ����㣬����ṹ�洢��Щ������ڱ�Ŀ��е�λ��

	UGArray<TriLocation*> arrNeighbour;  // ����������Щ�����ε��ڽ��������ڱ�Ŀ��У�ʹ�����array�������Щ�����ε��ڽӹ�ϵ
	
	UGint nTriCount;
	UGint nRealTri;

	UGint nLivePnt;
 	UGint nDeadPnt;
	UGint nRealPnt;     // pPnt�����Ĵ�С�����ܺ����е�λ���ǿյģ�Ϊ�˴�������ĵ�

	TinBlock()
	{
		pTriangle = NULL;
		pPnt = NULL;
		pPntLocs = NULL;
		
		nTriCount = nRealTri = 0;
		nLivePnt = nDeadPnt = nRealPnt = 0;
	}
	TinBlock& operator = (const TinBlock& tinblock)
	{
		pTriangle = tinblock.pTriangle;
		pPnt = tinblock.pPnt;
		pPntLocs = tinblock.pPntLocs;

		nTriCount = tinblock.nTriCount;
		nRealTri = tinblock.nRealTri;

		nLivePnt = tinblock.nLivePnt;
		nDeadPnt = tinblock.nDeadPnt;
		nRealPnt = tinblock.nRealPnt;

		arrNeighbour.Append(tinblock.arrNeighbour);

		return *this;
	}
	~TinBlock ()
	{
		UGint i;
		UGint nSize;
		TriLocation* pTriNeighbour = NULL;
		if (pTriangle)
		{
			free (pTriangle);	
			pTriangle = NULL;
		}
		if (pPnt)
		{
			free (pPnt);
			pPnt = NULL;
		}
		if (pPntLocs)
		{
			free (pPntLocs);
			pPntLocs = NULL;
		}
		
		nSize = arrNeighbour.GetSize();
		for (i = 0; i < nSize; i ++)
		{
			pTriNeighbour = arrNeighbour.GetAt(i);
			delete pTriNeighbour;
			pTriNeighbour = NULL;
		}
		arrNeighbour.RemoveAll();
		
		nRealTri = nTriCount = 0;
		nRealPnt = nLivePnt = nDeadPnt = 0;
	}
};

struct Contour
{
	UGdouble dTopValue;
	UGint nTriIndex;
};

typedef UGArray<Contour> Contours;

struct ContourLayer
{
	UGdouble dBegin;
	
	UGArray<Contours*> arrContours;
};

typedef UGArray<UGint> NbrTris;

struct TriInfo 
{
	UGdouble dSlope;
	UGdouble dAspect;
	UGPoint2D pnt[3];
};

class GEOMETRY_API UGTINBlock : public UGGeometry
{
public:
	UGTINBlock();

	virtual ~UGTINBlock();

public: //! �õ�������һЩ��Ϣ
	
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	virtual UGPoint2D GetInnerPoint() const;
	
	
	//! \brief �õ��ռ�����
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief ���ζ����Ƿ���Ч
	virtual UGbool IsValid() const;
	
	//! \brief �������
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0);
	
	virtual UGbool Resize(const UGRect2D& rcNewBounds);
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	virtual UGString ToXML(UGGeometry::GMLVersionType versionType, UGint nPace = 0)  const;
	
	//! \brief ��XML�ַ���������Geometry
	virtual UGbool FromXML(const UGString& strXML,UGGeometry::GMLVersionType versionType);

protected:
	
	virtual UGRect2D ComputeBounds() const;
	
public:

	// �õ�������
	UGTri* GetTriangle();

	// ����������
	void SetTriangle(UGTri* pTriangle);

	// �õ���
	UGPoint3D* GetPoints();

	// ���õ�ָ��
	void SetPoints(UGPoint3D* pnt);

	// �õ������εĸ���
	UGint GetTriCount();

	// �õ�ʵ�������εĸ���
	UGint GetRealTriCount();

	// ���ÿ����µ���������
	UGTri* AllocRealTriCount(UGint nCount);

	// �õ����ڵ�ĸ���
	UGint GetLivePntCount();

	// ���ÿ��ڵ�ĸ���
	void SetLivePntCount(UGint nCount);

	// ���ÿ��������εĸ���
	void SetTriCount(UGint nCount);

	// ���ÿ���ʵ�������̵ĸ���
	void SetRealTricount(UGint nCount);

	// �õ��ÿ��������ĸ���
	UGint GetDeadPntCount();

	// ���������ĸ���
	void SetDeadPntCount(UGint nCount);

	// �õ�ʵ�ʿ��ڵĵ���
	UGint GetRealPntCount();

	// ����ʵ�ʿ��ڵ���
	void SetRealPntCount(UGint nCount);

	// ���ÿ����µĵ���
	UGPoint3D* AllocRealPntCount(UGint nCount);

	// �õ�ĳ�������ʵ�����ڵ�λ��
	PntLocation* GetOriLocation(UGint nIndex);

	// �õ��ھ�
	TriLocation* GetNeighbour(UGint nIndex);

	// ����ھ�
	UGint AddNeighbour(TriLocation* pTriloc);

	// ���ؼ�¼�����λ�õ�����
	PntLocation* GetPntLocation();

	// Ϊ��¼�����λ�õ���������ڴ�ռ�
	PntLocation* AllocPntLocation(UGint nCount);

	// ɾ��tinblock
	void DeleteTinBlock();

	// �������߳�ֵ
	void SetMax(UGdouble dMax);

	// �õ����߳�ֵ
	UGdouble GetMax();

	// ������С�߳�ֵ
	void SetMin(UGdouble dMin);

	// �õ���С�߳�ֵ
	UGdouble GetMin();

	// �ÿ�������
	UGbool IsInUse();

	// Ϊm_pTinBlock�����ڴ�
	TinBlock* AllocTinBlock();

	// ����m_arrContours
	UGArray<ContourLayer*>& GetContourLayer();
	
	// ɾ��arrContours
	void DeleteContourLayer(UGArray<ContourLayer*>& arrContours);

	// �ҳ�dValue��Խ��������id������id�����arrTriIndex��
	void FindContours(UGdouble dValue, UGArray<UGint>& arrTriIndex);

	// ����������ÿ�������ζ�ת��Ϊ�պ���
	void ToGeoLine(UGGeoLine*& pGeoLine, UGint& nCount);

	// ����дhittest
	UGbool HitTest1( const UGPoint2D &pntHitTest, UGdouble dTolerance, TriInfo& triInfo);

	// ��UGTri��Ϣת��ΪTriInfo���
	void ToTriInfo(UGTri* pTri, TriInfo& triInfo);

	//! \brief ��������GeoTinBlock
	//! \param geoTinBlock [in] ����Tin����
	//! \return ����Tin����Ƿ�, ����false��
	UGbool Make(UGTINBlock& geoTinBlock);
	
	// �����ھӵĸ���
	UGint GetNbrCount();

private:

	// ��ʱ���ж�
	UGint counterclockwise(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);

	// �����������ڷ����ж�
	UGint PntInTriangle(const UGPoint2D& pnt, UGdouble* pTriangle);

private:

	TinBlock* m_pTinBlock;

	UGArray<ContourLayer*> m_arrContours;	

	UGdouble m_dMin;
	UGdouble m_dMax;

public:
	
	

};

}
#endif // !defined(AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_)
