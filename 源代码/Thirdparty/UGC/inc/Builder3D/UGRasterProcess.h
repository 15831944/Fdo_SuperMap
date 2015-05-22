// UGRasterProcess.h: UGUGinterface for the UGRasterProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_)
#define AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"Base/ugdefs.h"
#include "Base/UGString.h"
namespace UGC
{
class UGDatasetRaster;
class BUILDER3D_API UGRasterProcess  
{
public:
	UGRasterProcess();
	UGRasterProcess(UGDatasetRaster* pDataset, const UGString& strDestPath,const UGString& strExtName = "png",UGint nMaxLevel=9,UGint nSampleSize=512);
	virtual ~UGRasterProcess();
	UGbool Produce();
	void SetDestPath(const UGString& strDestPath);
	void SetDestDsName(const UGString& strDestPath);
	void SetDataset(UGDatasetRaster* pDataset);
	void SetFileExt(const UGString& strFileExt);
	void SetMaxLevel(UGint nMaxLevel=9);
	void SetSampleSize(UGint nSampleSize=512);
	UGint GetMaxLevel();
	// �⼸������Ҫ��ComputParam()����ò��ܷ�����Чֵ
	UGint GetLevelBegin();
	UGint GetLevelEnd();
	UGdouble GetL0Degree();

private:
	UGbool ComputParam();

	UGbool WriteXML(const UGString& strFileName);
	void BuildDir(UGint nLevel,UGdouble dNorth,UGdouble dSouth,UGdouble dEast,UGdouble dWest,UGProgress* pProgress=NULL);
	void OuputBlock(UGString strFileName, UGdouble x1, UGdouble x2, UGdouble y1, UGdouble y2);
	UGbool OuputRGBA(UGString strFileName, UGdouble x1, UGdouble x2, UGdouble y1, UGdouble y2);

private:
	UGString m_strDestDsName;
	UGString m_strDesPath;               // Ŀ��·�� 
	UGString m_strFileExt;				// ��չ��
	UGdouble m_dNorth;					// ��γ
	UGdouble m_dSouth;					// ��γ
	UGdouble m_dWest;						// ����
	UGdouble m_dEast;						// ����
	UGint m_nLevelBegin;					// ��ʼ����
	UGint m_nLevelEnd;				    // ��������
	UGdouble m_dL0LatDegree;			// ��С�����Ķ���
	UGdouble m_dL0LonDegree;			// ��С�����Ķ���
	UGDatasetRaster* m_pDatasetRaster;	 // դ�����ݼ�       
	UGint m_nSampleSize;
	UGint m_nMaxLevel;
	// ���������m_strDesPath+"/"m_strDestDsName���
	UGString m_strDestDir;
};

}

#endif // !defined(AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_)
