
#include "SMCTest.h"

int main()
{
	
/*	SMCWorkspace workspace;
	SMCDataSource* pDataSource = new SMCDataSource ;
	SMCDatasetVector* pDataset = new SMCDatasetVector;

	//! ���Թ����ռ��
	_tstring strWorkspaceName(_T("C:\\TestDS\\World.sxw"));
	//	std::string strWorkspaceName("D:\\World.sxw");

	bool bOpen = workspace.Open(strWorkspaceName);
	if(bOpen)
	{
		std::cout << "�����ռ�򿪳ɹ���" << std::endl;
	}
	else
	{
		std::cout << "�����ռ��ʧ�ܣ�" << std::endl;
		return 0;
	}

	//! ���Թ����ռ�������Դ�ĸ���
	std::cout << "����Դ����:   " << workspace.m_DataSources.GetCount() << std::endl;



	//! ��������Դ���Ϻ�����Դ
	SMCDataSource *pDs = new SMCDataSource();

	if(workspace.m_DataSources.Lookup (_T("world"), pDs))
	{ 
		std::wcout << "����Դ��ȫ·����:   "  << pDs->GetName().c_str() << std::endl; //�õ�����Դ��ȫ·����
		std::wcout << "����Դ������:   " << pDs->GetEngineName().c_str() << std::endl;
		std::cout << "����Դ�Ƿ��Ѿ���:   " << pDs->IsOpen() << std::endl;
		std::cout << "����������Ϣ:   " << pDs->SaveInfo() <<std::endl;
		std::cout << "����Դ�Ƿ�����:   " << pDs->IsConnected() <<std::endl;
		std::cout << "�������ݿ�:   " << pDs->Connect() <<std::endl;

		pDs->SetModifiedFlag(true);
		std::cout << "����Դ�Ƿ��Ѿ��޸�:   " << pDs->IsModified() <<std::endl;
		std::cout << "������Դ�����ݼ��ĸ���:   " << pDs->GetDatasetCount() << std::endl; 

		SMCDatasetVector *pDst = new SMCDatasetVector();

		if(pDs->GetDataset(_T("Ocean"), (SMCDataset*&)pDst))
		{
			std::cout << "��ȡ����ΪOcean�����ݼ��ɹ�!" << std::endl;
			std::wcout << "����ΪOcean�����ݼ�����Ϊ:   " << pDst->GetName() << std::endl;

			pDst->Open();
			//���²������ݼ��в�ѯ���ļ�¼��
			SMCQueryDef def;
			SMCRecordset *pRecordset = new SMCRecordset();
			if(pDst->Query(def, pRecordset))
			{
				std::cout << "��¼����ȡ�ɹ�!   " << std::endl; 

				//���²��Լ�¼���Ľӿ�pRecordset
				std::cout << "��¼���Ƿ����������ݣ�  " << pRecordset->HasDBInfo() << std::endl;
				std::cout << "��¼���Ƿ��м�������:   " << pRecordset->HasGeometry() <<std::endl;
				pRecordset->GetDataset(pDst);
				std::cout << "��¼����Ӧ�����ݼ�Ϊ:   " << pDst->m_pDataset <<std::endl;

				std::cout << "ˢ�¼�¼��:     " << pRecordset->Refresh() <<std::endl;
				std::cout << "��¼���Ƿ�Ϊ��:   " << pRecordset->IsEmpty() <<std::endl;
				int nRecCount = pRecordset->GetRecordCount();

				std::cout << "��¼���ĸ���Ϊ:   " << nRecCount << std::endl;

				while (!pRecordset->IsEOF())
				{
					std::cout << "������¼��"  << std::endl;
							//���²��Եõ��ֶ�ֵ
					SMCVariant var;

					pRecordset->GetFieldValue(1, var);
					std::cout << var.m_nType <<std::endl;
//					std::cout << double(var.m_value) << std::endl;
//					double varvalue = (double)var.m_value;

					pRecordset->MoveNext();

				}
				int nFieldCount = pRecordset->GetFieldCount();
				std::cout << "�ֶεĸ���Ϊ:   " << nFieldCount << std::endl;

				//���²��Եõ��ֶ���Ϣ
				//SMCFieldInfos infos;
				//pRecordset->GetFieldInfos(infos);
	//			std::wcout << infos.at(3).m_strName <<  std::endl;
			}
			else
			{
				std::cout << "��¼����ȡʧ��!   " << std::endl; 
			}

			delete pRecordset;
		}
		else
		{
			std::cout << "��ȡ����Ϊ0�����ݼ�ʧ��!" << std::endl;
		}

		std::cout << "ɾ��T1���ݼ�:   " << pDs->DeleteDataset(_T("T1")) <<std::endl;



		delete pDst;

	}
	delete pDs;




	//! ���Թ����ռ�������Դ�Ƿ�Ϊ��
	std::cout << "����Դ�Ƿ�Ϊ��:   " << workspace.m_DataSources.IsEmpty() << std::endl ;

	//! ����ͨ������Դ������������
	std::cout << "����Ϊworld������Դ������Ϊ:   " << workspace.m_DataSources.FindAlias(_T("world")) << std::endl;

	//! ��������Դ���ϵ�ToXML
//	std::cout << workspace.m_DataSources.ToXML("D:\\World.sxw") << std::endl;

	//! ��������Դ��GetAliasAt
	std::wcout << "����Ϊ0������Դ����Ϊ:   " << workspace.m_DataSources.GetAliasAt(0) << std::endl;

	//! ��������Դ����Ϊ���޸�״̬
	workspace.m_DataSources.SetModifiedFlag();

	//! �ж�����Դ�����Ƿ��Ѿ��޸�
	std::cout << "����Դ�Ƿ��޸�:   " << workspace.m_DataSources.IsModified() << std::endl;

	//! ��������Դ���ϵ�Rename
	//	std::cout << workspace.m_DataSources.Rename(_T("123"),_T("abc")) << std::endl;


	//! ���湤���ռ�
	bOpen = workspace.Save();
	if(bOpen)
	{
		std::cout << "�����ռ䱣��ɹ���" << std::endl;
	}
	else
	{
		std::cout << "����Դ��ȡʧ�ܣ�" << std::endl;
		return 0;
	}

	std::cout << "���������Դ��Ӧ���ǣ� " << ASCII_STRING(pDataSource->GetName()) << std::endl;


	SMCRecordset* pRecordset = new SMCRecordset;
	SMCQueryDef queryDef;

	//! �õ������ռ�����
	int nType = workspace.GetType();
	switch( nType )
	{
		pDataSource->GetDataset(n, (SMCDataset*&)pDataset);
		if(!pDataset->Open())
		{
			std::cout << "���ݼ���ʧ�ܣ� " << std::endl;
		}
		if(!pDataset->Query(queryDef, pRecordset))
		{
			std::cout << "��ѯ��ȡ��¼��ʧ�ܣ�" << std::endl;
		}
		if(pDataset != NULL)
		{
			std::cout << ASCII_STRING(pDataset->GetName()) << "��¼�������� " << pDataset->GetRecordsetCount() << std::endl;
		}
	}




	//! �õ������ռ�����
	std::wstring strPwd = workspace.GetPassword();
	std::wcout << _T("�����ռ������ǣ� ") << strPwd << std::endl;

	//! �رչ����ռ�
	workspace.Close();*/

	SMCDataSource	sdbDs;
/*	sdbDs.CreateDataSource(SMCDsConnection::SMEngineType::SDBPlus);
	SMCDsConnection conn;
	conn.m_strServer    =	_T("C:\\TestDS\\World.sdb");
	conn.m_strAlias     =	_T("World");
	sdbDs.SetConnection(conn);

//	std::cout << "��������Դ--C:\\World.sdb   " << sdbDs.Create() << std::endl;

	std::cout << "������Դ--C:\\TestDS\\World.sdb   " << sdbDs.Open() << std::endl;
	std::cout << "�Ƿ�ɹ�������Դ--C:\\TestDS\\World.sdb   " << sdbDs.IsOpen() << std::endl;


	std::cout << "ɾ�����ݼ�--T1:   " << sdbDs.DeleteDataset(_T("T1")) <<std::endl;


	std::wcout << "����Դ��ȫ·����:   "  << sdbDs.GetName().c_str() << std::endl; //�õ�����Դ��ȫ·����
	std::wcout << "����Դ������:   " << sdbDs.GetEngineName().c_str() << std::endl;
	std::cout << "����Դ�Ƿ��Ѿ���:   " << sdbDs.IsOpen() << std::endl;
	std::cout << "����������Ϣ:   " << sdbDs.SaveInfo() <<std::endl;
	std::cout << "����Դ�Ƿ�����:   " << sdbDs.IsConnected() <<std::endl;
	std::cout << "�������ݿ�:   " << sdbDs.Connect() <<std::endl;

	sdbDs.SetModifiedFlag(true);
	std::cout << "����Դ�Ƿ��Ѿ��޸�:   " << sdbDs.IsModified() <<std::endl;
	std::cout << "������Դ�����ݼ��ĸ���:   " << sdbDs.GetDatasetCount() << std::endl;*/
//	_tstring file(_T("SDB;file=C:\\TestDS\\testds.sdb;user=majun;pwd=majun;"));
//	_tstring file(_T("Ora;server=ugces;database=majun2;user=majun2;pwd=majun2;"));

	sdbDs.OpenDataSource(sdbDs, _T("type=SDB;file=C:\\TestDS\\world.sdb;"));


	std::cout << "�Ƿ�ɹ�������Դ--  " << sdbDs.IsOpen() << std::endl;
	std::cout << "ɾ�����ݼ�--T1:   " << sdbDs.DeleteDataset(_T("T1")) << std::endl;
	std::wcout << "����Դ��ȫ·����:   "  << sdbDs.GetName().c_str() << std::endl; //�õ�����Դ��ȫ·����
	std::wcout << "����Դ������:   " << sdbDs.GetEngineName().c_str() << std::endl;
	std::cout << "����Դ�Ƿ��Ѿ���:   " << sdbDs.IsOpen() << std::endl;
	std::cout << "����������Ϣ:   " << sdbDs.SaveInfo() << std::endl;
	std::cout << "����Դ�Ƿ�����:   " << sdbDs.IsConnected() << std::endl;
	std::cout << "�������ݿ�:   " << sdbDs.Connect() << std::endl;

	sdbDs.SetModifiedFlag(true);
	std::cout << "����Դ�Ƿ��Ѿ��޸�:   " << sdbDs.IsModified() << std::endl;
	std::cout << "������Դ�����ݼ��ĸ���:   " << sdbDs.GetDatasetCount() << std::endl;

//	sdbDs.OpenOraDS();




}




