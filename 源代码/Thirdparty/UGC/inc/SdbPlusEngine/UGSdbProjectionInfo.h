// ElemProjectionInfo.h: interface for the UGSdbProjectionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_UGSDBPROJECTIONINFO_H)
#define _UGSDBPROJECTIONINFO_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"


#include "Project/UGPrjCoordSys.h"

namespace UGC
{

class UGRecordHeader;

class  UGSdbProjectionInfo
{
public:
	UGSdbProjectionInfo();
	virtual ~UGSdbProjectionInfo();

	//����ϵͳ��
	void SetCoordinateSystem(UGint nCoordSys);
	UGint GetCoordinateSystem();
public:
	UGbool IsValid();				//�Ƿ���Ч����
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//�����¼ͷ���ڴ��

	UGuchar* GetData();
	UGint GetDataSize();

	void To(UGPrjCoordSys &PJCoordSys);
	void From(const UGPrjCoordSys& PJCoordSys);
protected:
	UGArray<UGuchar> m_Data;
	//PJCoordSys-->����ϵ����
//	void GetProjection( CSmPJCoordSys  &PJCoordSys );
//	void SetProjection( CSmPJCoordSys  PJCoordSys );
};

}

#endif // !defined(_UGSDBPROJECTIONINFO_H)
