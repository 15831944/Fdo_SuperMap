// UGDataHistory.h: interface for the UGDataHistory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)
#define AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataPool.h"

namespace UGC
{
	//�༭��ʷ��Ϣ,����������ʲôͼ��,�����Ķ���id����,����������
struct EditHistoryInfo {
	UGDatasetVector* pDatasetVector;
	UGArray<UGint> nIDs;
	UGint nOptType;
};


class ENGINE_API UGDataHistory  
{
public:
	UGDataHistory();
	virtual ~UGDataHistory();
public:
	enum OptType{				//�����������
			OPT_ADDNEW=0,		//����¶���
			OPT_MODIFIED=1,		//���������ı�
			OPT_DELETE=2,		//����ɾ��
	};

public:
	UGbool RemoveAllEvent();
	UGbool Goto(
		UGint nEventIndex);							  //	

	UGbool GetEventInfo(                                //ȡ���¼���Ϣ
		UGint nEventIndex,                             //�¼�������
		UGint & nAction,                               //
		UGint & nLayerIndex,                           //�¼�����ͼ�㣬����¼������ڶ��ͼ�㣬��ôֻ�������һ��ͼ�������
		UGString & strNote);							  //�¼�˵��	

	UGint GetCurrentIndex();                           //��ǰ�¼�������

	UGint GetCapacity();                               //����һ�����������������ɵļ�¼��

	UGint GetMaxEvtCount();                            //ȡ������¼���

	UGint SetCapacity(                                 //����һ�����������������ɵļ�¼��
		UGint lMaxSize);

	UGint SetMaxEvtCount(                              //��������¼���
		UGint lEvtCount);

	UGbool RemoveEvent(	                              //��������ɾ���¼�
		int lEvtIndex);								  //�¼�������

	UGbool BeginEvent(								  //��ʼһ���¼�	
		UGint nAction=0,								  //��ǰ��action,���Ϊ0
													  //��ʾʹ�ð󶨵�ͼ��ǰ��action			
		UGString strEvtNote="");					  //�¼���˵��	

	void EndEvent(									  //����һ���¼�
		UGbool bRecord=TRUE);							  //�Ƿ�Ըղŷ������¼����м�¼	
	

	//******************************************************************************//
   //*			�˺���������beginevent��EndEvent֮�����,���Խ��ж�֮���á�		  *//
  //******************************************************************************//
	UGbool SetEvtInfo(								  //�����¼�������	
		OptType etype,								  //����Ĳ�������
		UGRecordset* pRecordset);		  //�������ڼ�¼��������ΪNULL


	UGbool GoBack();									  //���ˣ�������ǰ���¼���
													  //�ص���һ�¼����ɹ�����true	

	UGbool GoForward();                                 //ǰ�����ָ���һ�¼�

	UGbool CanGoForward();							  //�Ƿ����ǰ��	

	UGbool CanGoBack();								  //�Ƿ���Ի���		

	
	UGint GetEvtCount();								  //ȡ���¼�����	
	
	//added by xielin 2007-05-23 
	//! \brief ���ݼ��ͷŵ�ʱ����øýӿ�
	UGbool OnDatasetDestory(UGDataset* pDt);
	
	//! \brief �õ��༭����ʷ��Ϣ����
	UGArray<EditHistoryInfo> GetEditHistoryInfo();

protected:
	UGDataPool * m_pDataPool;
	UGString m_strEvtTbName;							  //�¼��������
	UGbool m_bEvtBegin;								  //�¼��Ƿ��Ѿ���ʼ	
	UGint m_nAction;									  //�¼���action	
	UGString m_strEvtNote;							  //�¼���˵��
	UGArray<UGint> m_arEvtIndex;				  //�¼�������	
	UGint m_nCurEvtIndex;							  //��ǰ�¼�������	
	//{{qiuli 03.5.6
	UGbool m_bGoback;
	//}}qiuli 03.5.6

	UGArray<EditHistoryInfo> m_aryEditHistoryInfo;   //����edit��������ʷ��¼��Ϣ,�ڲ�ʹ��,������

private://��Ǹ���������ڲ�ʹ�ã� 
	
	//�����ݼ����޸ļ�¼���а����Ķ���
	void ModifyGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector *pDtV);			//���ݼ�

	//�����ݼ�����Ӽ�¼���а����Ķ���   
	void AddNewGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector *pDtV); 			//���ݼ�
 
	//�����ݼ���ɾ����¼���а����Ķ��� 
	void DeleteGeometry(UGRecordset *pRs,				//��¼��
						UGDatasetVector * pDtV);			//���ݼ�

};

}
#endif // !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)
