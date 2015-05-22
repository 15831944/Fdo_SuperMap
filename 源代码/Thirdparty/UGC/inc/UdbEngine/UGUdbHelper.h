// UGUdbHelper.h: interface for the UGUdbHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_)
#define AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_


#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVectorInfo.h"
#include "Engine/UGDatasetRasterInfo.h"

namespace UGC{

class UDBENGINE_API UGUdbHelper  
{
public:
	UGUdbHelper();

	virtual ~UGUdbHelper();

	UGbool GetInsertSQL();

	UGbool GetUpdateSQL();

	//! \brief �õ�����ʧ������ע���SMRegister��SQL��䡣
	//! \return ����ʧ������ע���SMRegister��SQL��䡣
	//! \remarks ��
	//! \attention ��
	UGString GetSmRegisterSQL();

	//! \brief �õ�����դ������ע���SmImgRegister��SQL��䡣
	//! \return ����դ������ע���SmImgRegister��SQL��䡣
	//! \remarks ��
	//! \attention ��
	UGString GetSmImgRegisterSQL();

	//! \brief �õ���������Դע���SmDataSourceInfo��SQL��䡣
	//! \return ��������Դע���SmDataSourceInfo��SQL��䡣
	//! \remarks ��
	//! \attention ��
	UGString GetSmDataSourceInfoSQL();

	//! \brief �õ������ֶ�ע���SmFieldInfo��SQL��䡣
	//! \return �����ֶ�ע���SmFieldInfo��SQL��䡣
	//! \remarks ��
	//! \attention ��
	UGString GetSmFieldInfoSQL();

	//! \brief �õ�����ʧ�����ݼ���SQL��䡣
	//! \param vInfo ʧ�����ݼ���Ϣ��
	//! \return ����ʧ�����ݼ���SQL��䡣
	//! \remarks ��
	//! \attention ��
	UGString GetCreateVectorSQL(UGDatasetVectorInfo vInfo);
	
	//! \brief �õ�����դ�����ݼ���SQL��䡣
	//! \param rInfo դ�����ݼ���Ϣ[in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGString GetCreateRasterSQL(UGDatasetRasterInfo rInfo);
};
}

#endif // !defined(AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_)

