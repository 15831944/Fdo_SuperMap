// UGSqlDatasetRaster.h: interface for the UGSqlDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)
#define AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_

#include "ODBCEngine/UGODBCDatasetRaster.h"

namespace UGC
{
class SQLENGINE_API UGSqlDatasetRaster  : public UGODBCDatasetRaster
{
	friend class UGSqlDatasource;

public:
	UGSqlDatasetRaster();
	UGSqlDatasetRaster(UGDataSource *pDatasource);
	virtual ~UGSqlDatasetRaster();
	
public:
	//! \brief դ�����ݼ��Ĵ���
	//! param rInfo դ�����ݼ������Ϣ[in]
	UGbool Create(const UGDatasetRasterInfo & rInfo);
};

}

#endif // !defined(AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)

