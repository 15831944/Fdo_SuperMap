/* 
	\file UGDictionary.h
	\brief ���ĵ�ַģ����ѯģ����ѯ��
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGFUZZYSEARCH_H
#define UGFUZZYSEARCH_H

namespace UGC {

	class UGDictionary;
	class UGMMWordSeg;
	class UGAddressData;
	//��ѯ�ຯ��
	class GEOCODE_API UGFuzzySearch
	{
	public:

		UGFuzzySearch();

		//!	\brief	����������������������Ҫ��������ݵ��ڴ�й¶������
        virtual ~UGFuzzySearch();

		//!	\brief ���ü��ص�ͼ���������
		//! \param AddressData �����׵�ַָ��[in]
		//! \return ������óɹ�����TRUE,����FALSE
		UGbool SetLoadMapData(UGAddressData &AddressData);

		//!	\brief ����ָ����ѯ�����ݼ�nLayer
		//! \param nLayer ָ�������ݼ���ѯ[in]
		//! \return ������óɹ�����TRUE,���򷵻�FALSE
		UGbool SetDatasetnLayer(UGint nLayer);

		//!	\brief ɾ��ָ����ѯ�����ݼ�nLayer
		//! \return ������óɹ�����TRUE,���򷵻�FALSE
		UGbool RemoveSearchnLayers();

		//!	\brief ����ָ����ѯ�����ݼ�nLayer
		//! \param arrnLayers ���ݼ�ָ������[in]
		//! \return ������óɹ�����TRUE,���򷵻�FALSE
		UGbool SetSearchnLayers(UGArray<UGint> &arrnLayers);

		//!	\brief ���ݼ���ַ���˺���
		//! \param nLayer ָ��ͼ��[in]
		//! \param arrAddressSrc ԭʼ��ַ��Ϣ[in]
		//! \param arrAddressRes ���˺�ĵ�ַ��Ϣ[in]
		//! \return ���ݼ���ַ���˺󷵻�TRUE,���򷵻�FALSE
		UGbool  DatasetAddressFilter(UGint &nLayer,UGArray<CHAddressDataID> &arrAddressSrc,UGArray<CHAddressDataID> &arrAddressRes);
	
		//!	\brief ģ�����Һ���
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool FuzzyMatchSearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief ģ�����Һ���
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool FuzzySearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//! ���ĵ�ַ��ѯ�õ�������ӿ�
		//! ��ѯ��������
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
        UGbool AptitudinallySearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief ��������ľ�ȷ���Һ���
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool AccurateSearchEngine(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief ��ȷ���Һ���
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool AccurateSearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief �����Ӳ������Һ���
		//! \param arrSearchMode ����ģʽ����[in]
		//! \param strAddress �����ַ��Ϣ[in]
		//! \param arrnLayers ָ����ѯͼ������[in]
		//! \param arrLocationResult ��ѯ���[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool MultiSearch(UGArray<UGCHSearchMode> &arrSearchMode,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief	������ѯģʽ
		//! \param strWordAdressArray ��ַ��Ϣ[in]
		//�ؼ���֮��Ĺ�ϵ�����ǡ��͡������򡱡����ǡ���and��or��not����
		UGbool GetSearchMode(UGString strAddress,UGArray<UGCHSearchMode> &arrSearchMode);

		//!	\brief	������ѯģʽ
		//! \param strWordAdressArray ��ַ��Ϣ[in]
		//�ؼ���֮��Ĺ�ϵ�����ǡ��͡������򡱡����ǡ���and��or��not����
		UGbool GetAccurateSearch(UGString &strAddress);

		//!	\brief	�õ���ѯģʽ
		//! \param chPos ��ַ�����ַ�[in]
		UGbyte GetMode(UGchar chPos);
		
private:
	   //Ϊ����ʾ, ��Ҫ��Ӽ�������
	   //������
	   
	   //������
	  
	   //�������
	   
	   //��ȷ����,���Թ鵽����������ȥ

	/*
	   //ԭ���󽻲�ѯ��
	void SearchAtomInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//ԭ���󲢲�ѯ��
	void SearchAtomUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
    
	//ԭ������ѯ��
    void SearchAtomDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//�ִ��󽻲�ѯ��
	void SearchSegInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//�ִ��󲢲�ѯ��
	void SearchSegUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
    //�ִ�����ѯ��
	void SearchSegDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//�󽻲�ѯ��
	void SearchWholeInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//�󲢲�ѯ��
	void SearchWholeUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
    
	//����ѯ��
    void SearchWholeDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	*/
         
	//Ϊ����߲�ѯ���ȶ��Ժ������ԣ�����µ�������ʵ�������Ĳ�ѯ


	    //!	\brief	��ͼ����nID����
	    //! \param strWordAdressArray ��ַ��Ϣ[in]
	    //!\param strAddressArray �����ͼnID[out]   
		void UnionORMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

	    //!	\brief	��ͼ����nID����
		//! \param strWordAdressArray ��ַ��Ϣ[in]
		//!\param strAddressArray �����ͼnID[out]   
		void UnionMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	��ͼ����nID����С��
		//! \param strWordAdressArray ��ַ��Ϣ[in]
		//! \param strAddressArray �����ͼIDs[out]   
		void UnionMinMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	��ͼ����nID����
		//! \param strWordAdressArray ��ַ��Ϣ[in]
		//!\param strAddressArray �����ͼIDs[out]   
		void InterSectMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	��ͼ����nID�������	
		//!\param strWordAdressArray ��ַ��Ϣ[in]
		//!\param strAddressArray  �����ͼIDs[out]   
		void InterSectMaxMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	������ͼ��ַ��Ϣ����ĺϲ�����	
		//! \param StrAdressArray1 ��ַ��Ϣ1[in]
		//! \param StrAdressArray2  ��ַ��Ϣ2[in] 
		//! \param StrAdressArrayRes  �ϲ���ĵ�ַ��Ϣ���[out]
		//! \return �ϲ��ɹ�����TRUE�����򷵻�FALSE
		UGbool MergeIDs(UGArray<CHAddressDataID> &strAdressArray1, UGArray<CHAddressDataID> &strAdressArray2,UGArray<CHAddressDataID> &strAdressArrayRes);
		
		//!	\brief	�����ַ��������������Ҫ˼����KMPģʽƥ��ķ���	
		//! \param pcStrSource Դ�ַ���[in]
		//! \param lpszFind  �����ַ���[in]
		//! \param nStart  ��pcStrSource��ʼ���ҵ�λ��[in]
		//! \return ���ҳɹ��ͷ���ƥ��λ�ã����򷵻�-1
		//! \remarks����pcStrSource�в����ַ���lpszFind��lpszFind�п��԰���ͨ���ַ���?��
		UGint FindingStringOR(const UGchar* pcStrSource, const UGchar* pcStrFind, UGint nStart  = 0 );

		//!	\brief	�����ַ��������������Ҫ˼����KMPģʽƥ��ķ���	
		//! \param pcStrSource Դ�ַ���[in]
		//! \param lpszFind  �����ַ���[in]
		//! \param nStart  ��pcStrSource��ʼ���ҵ�λ��[in]
		//! \return ���ҳɹ��ͷ���ƥ��λ�ã����򷵻�-1
		//! \remarks����pcStrSource�в����ַ���lpszFind��lpszFind�п��԰���ͨ���ַ���?��
		UGint  FindingString(const UGchar* pcStrSource, const UGchar* pcStrSFind, UGint nStart = 0);
		
		//!	\brief	��ͨ������ַ���ƥ��	
		//! \param pcStrSource Դ�ַ���[in]
		//! \param lpszMatch  �����ַ���[in]
		//! \param bMatchCase  bMatchCaseΪ0�������ִ�Сд���������ִ�Сд[in]
		//! \return ���ƥ�䣬����TRUE�����򷵻�FALSE
		//! \remarks ͨ������壺
		//! \		��*��	���������ַ������������ַ�����
		//! \		��?��	��������һ���ַ�������Ϊ�գ�
		UGbool MatchingString(const UGchar* pcStrSource, const UGchar* pcStrMatch, UGbool bMatchCase = TRUE);
		
		//!	\brief	����ƥ�亯��
		//! \param pcStrSource Դ�ַ���[in]
		//! \param lpszMatch  �����ַ���[in]
		//! \param nMatchLogic  nMatchLogic = 0, ��ͬƥ�����else����[in]
		//! \param bRetReversed  bRetReversed = 0, ƥ�䷵��TRUE������ƥ�䷵��TRUE[in]
		//! \return ���bRetReversed = 0, ƥ�䷵��TRUE������ƥ�䷵��TRUE
		//! \remarks������ƥ�䣬��ͬƥ���ַ���֮���á�,������
		//! \			�磺��*.h,*.cpp��������ƥ�䡰*.h���͡�*.cpp��
		UGbool MultiMatching(const UGchar* pcStrSource, const UGchar* pcStrMath, UGint nMatchLogic = 0, UGbool bRetReversed = 0, UGbool bMatchCase = TRUE);	
		
		//!	\brief ����ַ����Ƿ�˳��ƥ��
		//! \param sAdressSrc ��ƥ�䴮[in]
		//! \param sAdress ƥ�䴮[in]
		//! \param nCount ƥ�䴮�ĸ���[out]
		//! \return �������˳��ƥ�䷵��TRUE,���򷵻�FALSE
		UGbool IsOrderMatch(const UGchar* pcAdressSrc,UGStrArray sAdress,UGint &nCount);
		
		//!	\brief ����ַ����Ƿ�ȫ��ƥ��
		//! \param sAdressSrc ��ƥ�䴮[in]
		//! \param sAdress ƥ�䴮[in]
		//! \return �����ȫ��ƥ�䷵��TRUE,���򷵻�FALSE
		UGbool IsFullMatch(const UGchar* pcAdressSrc,UGStrArray sAdress);
		
		//!	\brief ����ִʽ����׺�ĸ���,������Ӧ�ĺ�׺�����ŵ�����
		//! \param strAddress ����ַ���[in]
		//! \param ndex ������λ������[out]
		//! \return ���ؾ�������ִʽ����׺�ĸ���,ͬʱ�õ���Ӧ�ĺ�׺�������������
		UGint  SuffixCount(UGStrArray &strAddress,UGArray<UGint> &Index);
		
		//!	\brief ����ִʽ����׺�ĸ���,
		//! \param strAddress ����ַ���[in]
		//! \return ���ؾ�������ִʽ����׺�ĸ���
		UGint  GetSuffixCount(UGString &strAddress);

		//!	\brief ����Ƿ��к�׺,�о�ɾ����׺
		//! \param strAddress ����ַ���[in]
		//! \return ���ɾ���ɹ��ͷ���TRUE,���򷵻�FALSE
		UGbool  IsDelSuffix(UGStrArray &strAddress);

		//!	\brief ����Ӧ��nID��Ϣ��Ӧ����ص������ֶ�
		//! \param strAddress ��ͼ��ַ��Ϣ[in]
		//! \param strWordAddress ��ַ�ֶ�ֵ[out]
		//! \return ����õ���ַ�ͷ���TRUE,���򷵻�FALSE
		UGbool GetMapIDString( CHAddressDataID &strAddress ,UGString &strWordAddress );
	
		//!	\brief ���ҷִʲ�����ص�ͼ��Ϣ����
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void Search(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief ���ҷִʲ�����ص�ͼ��Ϣ����
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void SearchMinSeg(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief ���ҷִʲ�����ص�ͼ��Ϣ����
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void SearchAccurate(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief ���ҷִʲ�����ص�ͼ��Ϣ����
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void SearchUnion(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief �����������׺�ĺ���
		//! \param strWordAddress ���������ĵ�ַ��Ϣ[in]
		//! \return ���ش����ĵ�ַ��
		UGString DelSuffex(UGString &strWordAddress);
		
		//!	\brief ͨ���зֺ����ַ��ԭ�ӵ����зֲ�����ص�ͼ��Ϣ�ĺ���
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void SearchBySingleWord(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief ͨ���зֺ����ַ��ԭ�ӵ����зֲ�����ص�ͼ��Ϣ�ĺ���
		//! \param strWordAddress ������ҵĵ�ַ��[in]
		//! \param strAddressArray ���ҵ��ĵ�ͼ��Ϣ[out]
		void SearchBySingleWordUnion(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief �����������
		//! \param StrMapAddress ��ͼ��ַ��Ϣ[in]
		//! \param strAddress �����ѯ�ĵ�ַ[in]
		//! \return ���ؾ�������ƥ��ķ���
		//! \remarks ������ķ���������׼��ת����0-100֮�� 
		UGdouble ComputeScore(UGString &StrMapAddress, UGString &strAddress);

		//!	\brief �����������
		//! \param StrMapAddress ��ͼ��ַ��Ϣ[in]
		//! \param strAddress �����ѯ�ĵ�ַ[in]
		//! \return ���ؾ�������ƥ��ķ���
		//! \remarks ������ķ���������׼��ת����0-100֮�� 
		UGdouble ComputeScore(UGString &StrMapAddress, UGbool bFullMatch , UGbool bOrderMatch ,UGbool bSegSucess = TRUE);

		//!	\brief ������뺯��
		//! \param location ��ѯ���ĵ�ͼ��Ϣ[in]
		//! \param ArrLocationResult ��ͼ��Ϣ����[in]
		//! \return �������TRUE
		//! \remarks ����ͼ��Ϣ���뵽��֪�ĵ�ͼ��Ϣ������
		UGbool InsertLocation(UGCHAddressLocation location,UGArray<UGCHAddressLocation> &arrLocationResult);
private:
	    //!	\brief ����ͼ��ָ��
	    UGAddressData * m_pAddressData;

		//!	\brief �Ƿ�ָ����С����
		UGbool m_bSetMinSore;
		
		//! \brief ���ƥ����� ����0С��100 ȱʡΪ50��
		UGint m_nMinMatchScore	;

		//! \brief ָ����ѯ���ݼ�
		UGArray<UGint> m_ArrnLayers;
		
		//! \brief ���ݼ�		
		UGDatasetVector * m_pDtSet;
		
		//! \brief �����ֶ�
		UGFieldInfo m_FieldInfo ;

		//! \brief ��ַ�ֶ�����
		//! \remarks "Name"��"StrName"��
		UGString m_ArrFieldName;
		
};

}

#endif
