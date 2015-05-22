// UGDataPool.h: interface for the UGDataPool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)
#define AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

//=====================================================================================
#define EVTINFTB		"EventInfo"			//���������¼�����Ϣ�ı���
#define EVTTB			"EventTable"			//Ψһ���¼������
#define EVTTBNAME		"EventTbName"		//�¼���ı���
#define EVTTBID			"EvtTbID"			//�¼����id
#define CUREVTID		"CurrentEvt"		//��ǰ�¼���id
#define EVTCOUNT		"EventCount"		//�¼�����Ŀ
#define LASTEVTID		"LstEventID"		//���µ�EventID
#define FIRSTEVTID		"FrtEventID"		//�����EventID

#define OBJINFTB		"ObjInf"			//�������ж������Ϣ�ı���
#define OBJTBNAME		"ObjTbName"			//�����ı���
#define DATASETHANDLE   "DatasetHandle"         //���ݼ���ָ��
#define OBJTBID			"ObjTbID"			//������ID
#define OBJTBREF		"ObjTbRef"			//��������ü���
#define OBJTBISSDB      "objTbIsSDB"		//�Ƿ񱣴���sdb���ݼ�������	
#define OBJTBHASSTYLE   "objTbHasStyle"	    //�Ƿ���[smEvtGeoStyle]�ֶ�

#define	EVTID			"EventID"			//�¼���id
#define EVTACTION		"EventAction"       //�¼���Ӧ��Actionֵ
#define EVTLAYER		"EventLayer"		//�¼���������ͼ��
#define EVTNOTE			"EventNote"			//�¼���˵��
#define EVTORDERID		"EventOrdID"		//�¼��Ⱥ�˳��
#define SUBEVTID		"SubEventID"		//���¼���id��added by xielin ����һ���¼����м������¼������

#define	OBJID			"ObjectID"		//�����id
#define EVTOPERATOR		"ObjOperator"		//�¼��ж��������Ĳ���
#define EVTGEOINDEX		"ObjIndexPos"	    //�¼��м��ζ�����sdb�е�����

#define NOTTHISTB     0						//������
#define EVTTYPETB		1						//�¼���	
#define OBJTYPETB     2						//�����

#define TEXTFIELDSIZE   80						//�ı����͵��ֶγ���

#define HANDLETEXTSIZE  8						//��Ϊudb��֧��8���ֽڵ����ͣ���ָ��ֻ����text����

#define SDBENGINE       1                       //�Ƿ�ʱSDB����
#define GEOHASSTYLE     2                       //���ζ����Ƿ���SYTLE
//=====================================================================================



namespace UGC
{

class ENGINE_API UGDataPool  
{
public:
	UGDataPool();
	virtual ~UGDataPool();

public:
	UGbool ClearEvtTable(	                        //���һ���¼��� 
		UGString strEvtTbName);                  //�¼��������

	UGbool CreateObjectTableFromDataset(          //ͨ��һ�����ݼ���������� 
		UGDatasetVector * pDtV);

	UGbool CreateDatabase(						//�����������ݿ�,�������Ϊ�գ�ϵͳ����һ�����������
		 UGString strDbName="");				//���ݿ���
	void DestoryDatabase();						//�رղ�ɾ�����ݿ�
	UGbool OpenDatabase();						//�����ݿ�
	UGbool CloseDatabase();						//�ر����ݿ�

	UGbool GetTbNameFromID(	                    //ͨ�����ID����ñ���
		UGString & strTbName,					//����
		UGint  nTbType,							//������ͣ�SMEVTTYPETB���¼�����SMOBJTYPETB�������
		const UGint & nTbID);					//���ID
												//�ɹ�����TRUE,ʧ�ܷ���FALSE

	UGint GetTbSize(                             //ȡ��һ����Ĵ�С   
		UGString strTbName);                    //����  
	
	UGint GetTbType(								//�ж�һ���������
		UGString strTableName,                   //����
		UGint & lTableID);					    //���ID
												//�ú�������ֵ����:
	                                            //-1:�����ˣ����ݿ�û�д�
												//SMNOTTHISTB�������ڣ�
												//SMEVTTYPETB��Event��
												//SMOBJTYPETB, Object��

	UGbool GetDatasetHandleFromObjTbName(	            //����object����ȡ�����ݼ���ָ��
		const UGString & strObjTbName,           //�������
		UGlong & lDatasetHandle);                //���ݼ�ָ��

	UGbool GetObjTbNameFromDatasetHandle(             //�������ݼ�ָ��ȡ��obj�������
		const UGlong & lDatasetHandle,           //���ݼ�ָ��
		UGString & strObjTbName);                //����������
	
	UGbool CreateEventTable(	                    //�½�һ��EventTable
		UGString strTbName,                      //EventTable�ı���
		UGFieldInfos * pFieldInfoList);       //�ֶ��б�

	UGbool DeleteEventTable(						//ɾ��һ�������ͼ�����ı�����ͼ
		                                        //�ر�ʱҪ��ס������Ŷ
		UGString strTableName);					//����
	
	
	
	UGbool Purge();								//�������ݿ������еı�

	//*******************************************************************************************//
	//һ��objTable�����ݼ�һһ��Ӧ����objTable��Ӧ�����ݼ���������ͼ��ȫ���ر�ʱ����ɾ���˶���� //
	//*******************************************************************************************//	
	UGbool DeleteObjTable(						//ɾ��һ�����漸�ζ��������Եı�
	                                        	//��һ��ͼ�㱻�ɵ�ʱ����Ҫ���ô˱�
		UGString strObjTbName); 				    //ͼ����

	UGbool ReleaseObjTable(						//�ͷ�һ�������,���ݼ��ͷŵ�ʱ���Ӧ�Ķ������ͷ�
		UGDataset* pDt);					//����
		
	UGint SetMaxEventCount(						//��������ܱ�����ٸ��༭Event
		 UGint lEventCount);						//Event�ĸ���
	UGint GetMaxEventCount();					//ȡ������ܱ�����ٸ��༭Event
	UGint SetMaxEventSize(						//��������ܱ�����ٸ��༭���󣨼�¼��
		 UGint lEventSize);						//Event�ĸ���
	UGint GetMaxEventSize();						//ȡ������ܱ�����ٸ��༭���󣨼�¼��

	UGDatasetVector* GetEventInfoDv();
	
	UGDatasetVector* GetObjInfoDv();


protected: 
	UGString m_strDbName;						//���ݿ��ļ�������	
	UGint m_nNextObjTbKey;						//���ɵ���һ�������Ĺؼ���
public:
	UGint m_nMaxEventCount;						//���ı���༭�¼��ĸ���
	UGint m_nMaxEventSize;						//һ��������󱣴�༭���󣨼�¼���ĸ���
	UGDataSource* m_pDatasource;

};


}
#endif // !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)
