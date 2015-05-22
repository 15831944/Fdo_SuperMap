// UGMultiResolutionTIN.h: interface for the UGMultiResolutionTIN class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_)
#define AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once 
#endif // _MSC_VER > 1000

#include "Algorithm/UGPoint3D.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGLogFile.h"
#include "Algorithm/UGKdTree.h"
#include "Geometry/UGTINBlock.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

#include "UGTriangle.h"

class UGMultiResolutionTINTest;

namespace UGC{

const UGint nAddForOnce = 10; // ������ÿ�������Ĵ�С
const UGint SAMPLEFACTOR = 11;  // Ѱ��һ��������ֵΪ�����θ������Ը�ֵ�����η���

struct Segment
{
	UGint nTriID;
	
	UGint nFromID;
	UGint nPntID;
	
	Segment ()
	{
		nTriID = -1;
		nFromID = -1;
		nPntID = -1;
	}

	Segment& operator = (const Segment& seg)
	{
		nTriID = seg.nTriID;
		nFromID = seg.nFromID;
		nPntID = seg.nPntID;
		return *this;
	}
};


typedef UGArray<UGint> pntNbrs; // ���ڵ���Ϣ

struct TriPntInfo 
{
	UGArray<pntNbrs*> arrPntNbrs;
	UGArray<Segment*> arrArc;
	UGint nArcIndex;
};



class GRIDANALYST_API UGMultiResolutionTIN : public UGTriangle
{
public:
	
// 	struct MultiResolution {
// 		UGdouble dTolerance;
// 		UGlong lResolution;
// 	};
	
	struct edgelist
	{
		UGint nFrom;  // �ߵ�����ڿ��е�λ��
		
		UGint nTo; // �ߵ��յ��ڿ��е�λ��
		
		UGint nBlockID;  // ���
		
		TriLocation RightTri; // �͸ñ����ڵ�������
		
		edgelist* next;
	};
	
	enum ExecuteType {UGCreate, UGInsert, UGDelete};
	
	enum BlockMark {UGRead, UGWaited, UGDone, UGUninserted};  // read��ʾ�Ѷ��룬waited��ʾδ����, done��ʾ�Ѿ�������ɣ�uninserted��ʾ�Ѷ��룬��Ϊ���뵽����
	
	enum Direction {UGTop, UGRight, UGBottom, UGLeft, UGNone};
	
	enum TypeForKdTree {UGSave, UGBuild, UGMerge};
	
	struct NeighbourInfo {
		UGArray<UGint> arrNeighbour;
		BlockMark nMark;
		
		NeighbourInfo ()
		{
			nMark = UGWaited;
		}
	};
	
	struct BlockWinge {
		TriLocation farleft;
		TriLocation farright;
		UGint nLeft;
		UGint nRight;
		
		BlockWinge ()
		{
			nLeft = nRight = -1;
		}
	};
	
	class MemoryQueue {
	
	public:
		UGint* pInMemory;
		UGbyte* pInUse;
		UGint* pUsedIndex;
		UGint nUsedCount;
		UGint nCount;
		UGint nRear;
		
		enum MarkType {UGBaseedge, UGLeftcand, UGRightcand, UGNextedge, UGTopcasing};

		MemoryQueue ()
		{
			pInMemory = NULL;
			pInUse = NULL;
			pUsedIndex = NULL;
			nCount = 0;
			nRear = -1;
		}
		void Init(UGint nSize, UGint nBlockCount)
		{
			if (nSize <= 0)
			{
				return;
			}
			UGint i;
			pInMemory = new UGint [nSize];
			
			for (i = 0; i < nSize; i ++) 
			{
				pInMemory[i] = -1;
			}
			nCount = nSize;
			nRear = nCount - 1; // ���������һλ��ʼ��������0��ʼ

			if (nBlockCount > 0)
			{
				pInUse = new UGbyte [nBlockCount];
				memset(pInUse, 0, nBlockCount * sizeof (UGbyte));

				UGint i;
				nUsedCount = 5;
				pUsedIndex = new UGint [nUsedCount];
				for (i = 0; i < nUsedCount; i ++)
				{
					pUsedIndex[i] = -1;
				}
			}
		}
		void Mark (UGint nBlockID, MarkType type)
		{
			UGint nIndex;
			
			switch (type)
			{
			case UGBaseedge:
				{
					nIndex = pUsedIndex[0];
					pUsedIndex[0] = nBlockID;
				}
				break;
			case UGLeftcand:
				{
					nIndex = pUsedIndex[1];
					pUsedIndex[1] = nBlockID;
				}
				break;
			case UGRightcand:
				{
					nIndex = pUsedIndex[2];
					pUsedIndex[2] = nBlockID;
				}
				break;
			case UGNextedge:
				{
					nIndex = pUsedIndex[3];
					pUsedIndex[3] = nBlockID;
				}
				break;	
			case UGTopcasing:
				{
					nIndex = pUsedIndex[4];
					pUsedIndex[4] = nBlockID;
				}
				break;
			default:
				return;
			}

			if (nIndex != -1)
			{
				UGASSERT (pInUse[nIndex] > 0);

				pInUse[nIndex] --;
			}
			pInUse[nBlockID] ++;
		}

		~MemoryQueue ()
		{
			if (pInMemory)
			{
				delete [] pInMemory;
				pInMemory = NULL;
			}

			if (pInUse)
			{
				delete [] pInUse;
				pInUse = NULL;
			}

			if (pUsedIndex)
			{
				delete [] pUsedIndex;
				pUsedIndex = NULL;
			}
		}
	};
	
	struct BlockSize {
		UGint nIndex;
		UGint nCount;
	};
	
	struct BlockBound {
		UGint nIndex;
		UGRect2D rcbound;
		
		BlockBound& operator = (const BlockBound bb)
		{
			nIndex = bb.nIndex;
			rcbound.top = bb.rcbound.top;
			rcbound.left = bb.rcbound.left;
			rcbound.right = bb.rcbound.right;
			rcbound.bottom = bb.rcbound.bottom;
			return *this;
		}
	};
	
	// �����洢ĳ���б����뵽��Ŀ�ĵ��ڱ�Ŀ�Ŀ�ż���������
	class PointRead {
		
	public:
		PntLocation* m_pPntLoc;
		UGint m_nCount; // ĳ������ܱ����뵽������У��ڲ�ͬ�Ŀ��ж�Ӧ�в�ͬ��������m_pPntLoc�洢֮
		
		PointRead ()
		{
			m_pPntLoc = NULL;
			m_nCount = 0;
		}
		~PointRead ()
		{
			free (m_pPntLoc);
			m_nCount = 0;
		}
	};

	class TriRead {

	public:
		UGint* m_pnRead;
		UGint m_nCount;

		TriRead ()
		{
			m_pnRead = NULL;
			m_nCount = 0;
		}
		UGbool Init (UGint nCount)
		{
			if (nCount <= 0)
			{
				return FALSE;
			}
			m_nCount = nCount;
			m_pnRead = new UGint [nCount];

			if (m_pnRead == NULL)
			{
				UGERROR(UGS_MEMMORY_NOT_ENOUGH);
				return FALSE;
			}
			memset(m_pnRead, 0, nCount * sizeof (UGint));
			return TRUE;
		}
		~TriRead ()
		{
			delete m_pnRead;
			m_nCount = 0;
		}
	};
	
	typedef UGArray<PointRead*> BlockRead;

	class PointMap {
		
	public:
		UGchar* pProcessed;   // �ж�ÿ�����Ƿ񱻴���0Ϊδ����1δ��������������Ŀ���ǿ���һ���룬һ��ɾ��
		
		UGTriedge* pTriedge;

		PointMap ()
		{
			pProcessed = NULL;
			pTriedge = NULL;
		}

		PointMap (UGint nCount)
		{
			if (nCount > 0)
			{
				pProcessed = new UGchar[nCount];
				memset(pProcessed, 0, nCount * sizeof (UGchar));

				pTriedge = new UGTriedge[nCount];
			}
			else
			{
				pProcessed = NULL;
				pTriedge = NULL;
			}
		}

		~PointMap ()
		{
			if (pProcessed)
			{
				delete [] pProcessed;
				pProcessed = NULL;
			}
			if (pTriedge)
			{
				delete [] pTriedge;
				pTriedge = NULL;	
			}
		}
		
	};

	struct PntRecord {

		PntLocation pntloc;   // ����εĵ�

		TriLocation RightTri; // �͸õ����ڵ�������
	};

	
	struct DAG {
		int nTriIndex;       // ������ID���������β����մ��ڣ�ֻ��һ���м�������ônTriIndexֵΪ��1��
		int nPntIndex[3];    // �������ε�����
		DAG* pDown[3];

		DAG ()
		{
			pDown[0] = pDown[1] = pDown[2] = NULL;
		}
	};

	enum PntRelation {ONEDGE, INSIDE, OUTSIDE};

	typedef UGArray<UGdouble> PTolerance; // ÿһ�������

	typedef UGArray<NeighbourInfo*> NeighboursInfo; // ���ڿ���Ϣ

	struct NbrTri  // ������ڵ�������
	{
		TriLocation* pNbrTri;
		UGint nNbrCount;   // ����Ĵ�С
		UGint nTriCount;   // ����ʵ�ʴ�ŵĶ������
	};

	struct NbrBlock  // ����ڽӵĿ��
	{
		UGint* pNbrBlock;  
		UGint nNbrCount;  // ����Ĵ�С
		UGint nBlockCount; // ����ʵ�ʴ�ŵĶ������
	};

public:
	UGMultiResolutionTIN();
	virtual ~UGMultiResolutionTIN();

	friend class UGMultiResolutionTINTest;
	
public:
	
	UGDatasetVector* CreateMultiResolutionTIN(UGDatasetVector* pFromDataset, const UGString& strFieldName, UGDataSource* pOutputDS, const UGString& strTinName);

	UGDatasetVector* CreateMultiResolutionTIN(UGDatasetVector* pFromDataset, const UGString& strFieldName, UGDataSource* pOutputDS, const UGString& strTinName, UGArray<UGdouble>& arrMultiPara);
	
	UGbool InsertResolutionLayer(UGDatasetVector* pTin, UGdouble multiPara);
	
	UGbool DeleteResolutionLayer(UGDatasetVector* pTin, UGint nLayerName);
	
	// ��ȡ��ֵ��
	UGDatasetVector* Contour(UGDataSource* pDataSource, const UGString& strOutputVectorName, UGDatasetVector* pTinDataset, UGdouble dBase, UGdouble dInterval, UGint nSmoothDegree = 3, UGint nSmoothMethod = 0);
	
#ifdef sparc  // ��solaris�¶Ե�Ԫ���������Ԫ�����ò������ã���Ԫ���Ա಻��ȥ��
	            // ��������solarisϵͳ�½����е�private��pretected���Ϳ���Ϊpublic
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
private:
#endif

	void BuildDelaunay(UGPoint3D*& pnts, UGint lCount, UGRect2D& rect);

	// ��ʼ��m_arrTinBlock
	void InitTINBlock(UGint nBlockCount);
	
	void CalAveragePlane(NbrTri& nbrTri, UGdouble* dAverageNormal, UGPoint3D& pnt);
		
	void CalcuNormal(UGint nBlockID, UGint nApex, UGint nOrg, UGint nDest, UGdouble *dNormal);
	void NormalSingle(UGdouble &f1, UGdouble &f2, UGdouble &f3);
	
	void CalcuArea(UGdouble* dNormal, UGdouble* dArea);
	void CalcuCoordinate(UGint nBlockID, UGint nApex, UGint nOrg, UGint nDest, UGPoint3D* pnt);
	
	// ��ĳһ���н���ÿ����͸õ����ڵ�һ�������ε�ӳ���ϵ
	void MakePointMap(UGTINBlock* pTinBlock, PointMap** pMap, UGint nBlockID);
	
	// ����triloc��ΧһȦ�������Σ�������arrTri��
	void CalNeighbour(const TriLocation& triloc, NbrTri& nbrTri, NbrBlock& nbrBlock);
	
	void CalNeighbour(UGKdTreeNode* pRoot, NeighboursInfo* pNeighbourInfo);
	void CalNeighbourInfo(UGKdTreeNode* pNode, UGArray<BlockBound>& arrLeft, UGArray<BlockBound>& arrRight);
	void FillBound(UGKdTreeNode* pNode, UGArray<BlockBound>& arrBlockBound, Direction dir);
	void KnitTeeth(NeighboursInfo* pNeighbourInfo, UGArray<BlockBound>& arrLeft, UGArray<BlockBound>& arrRight, UGKdTreeNode::DType type);
	
	void bondnull(TriLocation& triloc);
	
	// �ڵ�nCurLayer��ɵ�������triloc
	void RemoveSuperfluous(TriLocation& triloc);
	
	UGdouble counterclockwiseInBlock(UGint nFirst, UGint nSecond, UGint nThird, UGint nBlockID);
	UGdouble counterclockwiseInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird);
	
	void GetValue(UGint nBlockID, UGint nIndex, UGdouble& x1, UGdouble& y1);
	
	void CalCircleInBlock(UGint nFirst, UGint nSecond, UGint nThird, UGint nBlockID, 
		UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
	void CalCircleInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird,
		UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
		
	UGbool incircleInBlock(UGint pa, UGint pb, UGint pc, UGint nBlockID, PntLocation& pntloc);
	UGbool incircleInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird, PntLocation& pntloc);
	
	UGPoint3D* GetPnt(PntLocation& pntloc);
	
	// ��nBlockID�����ӵ�pnt�������õ�ԭʼ����Ϣд��
	UGint AddPnt(const UGPoint3D* pnt, const PntLocation& pntloc, UGint  nBlockID);
	
	// ��nBlockIDδ��ŵĿ�������pntloc��
	UGint AddPnt(const PntLocation& pntloc, UGint nBlockID);
	
	// �Զ����ɸ����ֱ���
	void DoAsDijkstra(NeighboursInfo* pNeighbourInfo, UGdouble* pNeighbourCount, UGint* pIndex, UGArray<PTolerance*>& arrTol, NbrTri& nbrTri, NbrBlock& nbrBlock);

	// �ֱ����Ѿ����ú���
	void DoAsDijkstra(NeighboursInfo* pNeighbourInfo, UGdouble* pNeighbourCount, 
										UGint* pIndex, UGdouble dTolerance, UGPoint3D*& pPnts, UGint& nPntIndex, NbrTri& nbrTri, NbrBlock& nbrBlock);
	
	UGint prevIndex(UGint nIndex, UGint nCount);
	
	void MergeDataInKdTree(UGKdTreeNode* pRoot);
	
	void SaveDataInKdTreeNode(UGKdTreeNode* pRoot);
	
	void BuildDataInKdTreeNode(UGKdTreeNode* pRoot);
	
	UGint GetIndex(UGKdTreeNode* pLeft, Direction type);
	UGint GetIndex(UGKdTreeNode* pNode, UGKdTreeNode::DType nCutDim, UGint nType);
	
	void EnQueue(MemoryQueue& memQueue, UGint nIndex, NeighboursInfo* pNeighbourInfo);
	
	// �����ΪnIndex�Ŀ���뵽�ڴ���
	void EnQueue(MemoryQueue& memQueue, UGint nIndex);
	
	void mergehulls(UGint nLeft, UGint nRight, UGint axis, 
		MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	void Merge(UGKdTreeNode* pNode, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	void AddNewTriangle(UGTriedge& newTriedge, UGint nBlockID);
	
	UGbool BlockInMemory(const TriLocation& triloc);
	
	void MoveToEnd(TriLocation& triloc, UGint dir,  MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	void MoveBack(TriLocation& triloc, UGint dir, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	UGint GetAxis(Direction type);
	UGint GetAxis(UGKdTreeNode::DType type);
	
	void Sort(UGKdTreeNode* pNode, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	void WriteNewQueue(UGKdTreeNode* pNode, NeighboursInfo* pNeighbourInfo, MemoryQueue& memTemp);
	
	// �������ݼ���Bound
	void SetBound(UGRect2D& rect);
	
	// ����߽������õ�������
	void CleanBound(TriLocation& triloc, MemoryQueue& memQueue);
	
	// ����߽��ϵ������Σ�triloc��apexҪô������ߣ�Ҫô�����ұ�
	void CleanBound(TriLocation& triloc);

	// �洢ÿ�����ڿ��ָ�뱻���
	void CleanNeighbourInfo();
	
	// �����õ�������ɾ����־�޸�Ϊ0����������������bondnull
	void DeleteTri(TriLocation& triloc, MemoryQueue& memQueue);
	
	// �����õ�������ɾ����־�޸�Ϊ0����������������bondnull
	void DeleteTri(TriLocation& triloc);
	
	UGint Add(UGTINBlock* tin);
	UGbool Save(UGTINBlock* tin, UGint nBlockID);
	UGbool Load(UGTINBlock* tin, UGint nBlockID);
	
	// ����ָ�����ָ�룬Ϊ�ÿ�����ڴ�
	BlockRead* SetBlockReadAt(UGArray<BlockRead*>& arrBlockRead, UGint nIndex);
	
	UGint FindPointRead(PointRead* pPointRead, UGint nBlockID);
	
	// ����ĳ��������ʵ��λ��
	void GetOriginPnt(PntLocation& pntloc);
	
	// ����arrBlockRead
	void CleanBlockRead();

	// ����m_arrTinBlock
	void CleanTINBlock();
	
	// ���pointmap
	void CleanPointMap();

	// ���winge
	void CleanWinge();

	// ������������ɾ��ĳ������γɵĶ�������ǻ�
	void PolygonTriangulation(UGArray<PntRecord*>& arrPntRecords, UGRect2D& rect);

	// �������ΪnIndex�ĵ��������ĸ���������
	PntRelation GetTriIndex(UGint nIndex, DAG* pTriRecord, UGArray<PntRecord*>& arrPntRecords, UGTriedge& triedge);

	// ��������delaunay��
	void LegalizeTriangle(UGTriedge& triedge, UGArray<PntRecord*>& arrPntRecords, UGArray<DAG*>& arrDAG);

	void ReAlign(UGArray<PTolerance*>& arrTol, UGint lCount, UGdouble& dTol, UGint& lLayerCount);

	UGdouble GetTolValue(UGint nPivot, UGint nBlockSize, UGArray<PTolerance*>& arrTol);
	
	void GetPointsTolerance(UGArray<PTolerance*>& arrTol, NbrTri& nbrTri, NbrBlock& nbrBlock, UGint nBlockID);

	UGdouble GetTolerance(const TriLocation& triloc, NbrTri& nbrTri, NbrBlock& nbrBlock);

	void GetPoints(UGPoint3D*& pPnts, UGint& nPntIndex, UGint& nPntCount, NbrTri& nbrTri, NbrBlock& nbrBlock, UGint nBlockID, UGdouble dTolerance);

	// ����arrPntNbrs�ڴ�ռ�
	void DeletePntNbrs(UGArray<pntNbrs*>& arrPntNbrs);

	// Ϊ���������η����ڴ�
	void AllocTriLocation(NbrTri& nbrTri, UGint nCount);

	// ����������
	void AddToNbrTri(NbrTri& nbrTri, const TriLocation& triOri);

	// Ϊ���������������ͷ��ڴ�
	void FreeNbrTri(NbrTri& nbrTri);

	// ���ٿռ䣬������ڿ��������Ĺ��Ŀ��
	UGint* AllocQueue(UGint nCount);

	// nNbrΪ���Ĺ��Ŀ�ţ��������Ų��뵽pNbr�����д洢����
	void InsertToQueue(UGint*& pNbr, UGint& nQueueIndex, UGint& nQueueSize, UGint nNbr);

	// �ͷſռ�
	void FreeQueue(UGint*& pNbr);

	// ����ռ䣬�������doasdijkstra���¶���Ŀ��
	void AllocBlock(NbrBlock& nbrBlock, UGint nCount);

	// �����ŵ�����nbrBlock��
	void AddToNbrBlock(NbrBlock& nbrBlock, UGint nBlockID);

	// �ͷ��ڴ�
	void FreeNbrBlock(NbrBlock& nbrBlock);

	// ����ÿ����ڽӿ�
	void CalBlockNeighbours(UGDatasetVector* pTin, NeighboursInfo*& pNeighbourInfo);

	// �����ݼ�������ȡ��
	void GetPntFromDataset(UGDatasetVector* pDataset, const UGString& strFieldName, UGPoint3D*& pnt, UGint& lCount);

	// �޳��ظ���
	void CleanRepeatedPnt(UGPoint3D*& pnts, UGint& lCount);

	// �����ķ�Χ������pnt
	void InflateBound(UGTINBlock* pTinBlock, const UGPoint3D* pnt);

	// ��ʼ��tripntInfo���ò�����Ϊ����contourtree�Ĵ������
	void InitTriPnt(TriPntInfo& tripntInfo);

	// ɾ��tripntInfo
	void DeleteTriPnt(TriPntInfo& tripntInfo);

	// ��ȡĳһ��ĵ�ֵ��
	void Contour(UGDatasetVector* pRtDataset, const UGString strElev, UGint nBlockID, UGdouble dBase, UGdouble dInterval);

#ifdef sparc
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
protected:
#endif

	UGbool symselfInBlock(TriLocation& triLoc);
	UGbool symInBlock(TriLocation& triloc1, TriLocation& triloc2);
	void apexInBlock(const TriLocation& triloc, UGint& apex);
	void orgInBlock(const TriLocation& triloc, UGint& org);
	void destInBlock(const TriLocation& triloc, UGint& dest);
	void setorgInBlock(TriLocation& triloc, UGint point);
	void setdestInBlock(TriLocation& triloc, UGint point);
	void setapexInBlock(TriLocation& triloc, UGint point);
	
	void bondInBlock(TriLocation& triNew, TriLocation& triOld);
	
	UGbool symselfInBlock(TriLocation& triloc, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	UGbool symInBlock(TriLocation& triloc1, TriLocation& triloc2, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);

	// ����ÿ�������ڵĵ��Լ���������Щ��
	void CalPntNbrs(UGTINBlock* pTin, UGint nBlockID, TriPntInfo& tripntInfo);

	// ��������
	void QuickSort(UGPoint3D* p, UGint lCount);

	// ����������triloc���¶�����
	void ReCalSlopeAspect(TriLocation& triloc);

#ifdef sparc
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
private:
#endif
	UGPoint3D* m_pPoint3D;
	UGRect2D m_rcBound;  // �������ݼ��ķ�Χ
	
	NeighboursInfo* m_pNeighbourInfo;
	
	UGArray<BlockRead*> m_arrBlockRead; // ɢ�б��ڴ���ͬ��֮��������ʱ�øñ������������������ظ�����
	
	UGArray<PointMap*> m_arrPointMap; // �ظ�����Ϣ(���ڹ�����ֱ���ͼ���Լ�����ͼ��)
	
	UGArray<UGTINBlock*> m_arrTinBlock;    // tin����
	
	UGint m_nBlockCount;
	
	UGRecordset *m_pRecordset;

	// ÿ�鶼����һ���������Σ�һ���������Σ�����BlockWinge�У�����һ�����飬����ÿ���BlockWinge��Ϣ
	UGArray<BlockWinge*> m_arrWinge;

};

}
#endif // !defined(AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_)
