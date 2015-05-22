/* 
	\file UGAddressData.h
	\brief ���ĵ�ַģ����ѯ����������
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGADDRESSDATA_H
#define UGADDRESSDATA_H

#include "GeoCode/UGDictionary.h"
#include "GeoCode/UGMMWordSeg.h"
#include "Engine/UGDatasetVector.h"



namespace UGC {
	
	class  GEOCODE_API UGAddressData
	{
	public:
	    //!	\brief	���캯��	
		UGAddressData();
		
	     //!	\brief	����������������������ڴ�й¶������
        virtual ~UGAddressData();
		
		//!	\brief	�ַ�����ģʽ��
		enum SmCharType
		{
			//!	\brief ���ֽ�
			UGChSINGLE	    = 1,	
			//!	\brief ɾ����
			UGChDELIMITER	= 2,    
			//!	\brief ����
			UGChCHINESE     = 3,    
			//!	\brief ��ĸ
			UGChLETTER	    = 4,	
			//!	\brief ����
			UGChNUM	        = 5,    
			//!	\brief  ����
			UGChINDEX       = 6,    
			//!	\brief �����ַ�
			UGChOTHER       = 7,    
				
		};
		
		//!	\brief ���شʵ�
		//! \param strDictName �ֵ�����[in]
		//! \return ���شʵ�ɹ�����TRUE,���򷵻�FALSE
		//! \remarks ���شʵ�
		UGbool LoadDict(UGchar* pcDictName) ;

		//!	\brief �ʵ�ȡ����Ƶ��
		//! \param pWord ����ָ��[in]
		//!	\return ���ش�Ƶ
		UGint DictGetWordFre(UGchar *pcWord) ;
		
		//!	\brief	  Ԥ��׼��
		//! \param strAddress	�ַ���[in]
		//! \return Ԥ����󷵻�TRUE,���򷵻�FALSE
		UGbool PreStand(UGString  &strAddress) ;
		
		//! \brief �ַ�������λ��
		//! \param sChar �ַ���[in]
		//! \return �����ַ���������λ��
		UGint GetCharPos(UGchar *pcString);

		//! \brief	 ����ַstrAddress�ִ�
		//!	\param strAddress Ŀ�괮[in]
		//! \return ���ص�ַstrAddress�ִʽ��
		UGString CHAdressSeg(UGString &strAddress);
		
		//! \brief	����ַstrAddress���պ��ֵ�ԭ������з�
		//! \param strAddress Ŀ�괮[in]
		//! \return ���ص�ַstrAddress�ִʽ��
		UGString CHAdressAtomSeg(UGString  &strAddress);
		
		//!	\brief	����ַ�Ƿ��зֳ�����
		//! \param StrAddress   ��ַ�ַ���[in]
		//!	\return ����зֳ����ﷵ��TRUE,���򷵻�FALSE
		UGbool IsChAdressSegSucess(UGString  &strAddress);
		
		//!	\brief	����ַ�Ƿ��зֳ�����
		//! \param StrAddress ��ַ�ַ���[in]
		//! \param strAddressRes �зֳ�������ַ���[out]
		//! \return	����зֳ����ﷵ��TRUE,���򷵻�FALS
		UGbool IsChAdressSegSucess(UGString  &strAddress,UGString  &strAddressRes);
		
		//!	\brief ���ִʵĽ���洢ΪUGStrArray��ʽ
		//! \param strAddress	�ִ��ַ���[in]
		//! \param strAddressArray	�ִʵĽ��[out]
		//!	\return	����зֳ����ﷵ��TRUE,���򷵻�FALS
		UGbool GetAdressSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief ���ִʵĽ���洢ΪUGStrArray��ʽ
		//! \param strAddress	�ִ��ַ���[in]
		//! \param strAddressArray	�ִʵĽ��[out]
		//!	\return	����зֳ����ﷵ��TRUE,���򷵻�FALS
		UGbool GetAdressMinSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief ���ִʵĽ���洢ΪUGStrArray��ʽ
		//! \param strAddress	�ִ��ַ���[in]
		//! \param strAddressArray	�ִʵĽ��[out]
		//!	\return	����зֳ����ﷵ��TRUE,���򷵻�FALS
		UGbool GetLoadAdressMinSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief ���ص�ַ�����ַ���
		//! \param nDTIndex ͼ��[in]
		//! \param nID nID[in]
		//! \param strAddress ��ַ���ﴮ����[in]
		//! \return �ɹ����ط���TRUE,���򷵻�FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGString strAddress);
		
		//!	\brief ���ص�ַ�����ַ���
		//! \param nDTIndex ͼ��[in]
		//! \param nID nID[in]
		//! \param strAddress ��ַ���ﴮ����[in]
		//! \return �ɹ����ط���TRUE,���򷵻�FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGStrArray StrAddressArray);
		
		//��ʼд�򵥵�ַ��ѯģ��ĺ���
		//!	\brief	���ҵ��������Ӧ�ĵ�ͼ��Ϣ
		//! \param sWord ����[in]
		//! \param StrAddressArray ��ַ��Ϣ[out]
		//! \param bAppoint �Ƿ�ָ�����ݼ���ѯ[in]
		//! \return ����ҵ�����TRUE,���򷵻�FALSE
		UGbool FindWordIDs(UGchar *pcWord,UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &StrAddressArray,UGbool bAppoint = TRUE);
		
		//!	\brief	���ҵ�����������λ�ö�Ӧ�ĵ�ͼ��Ϣ
		//! \param sWord ����[in]
		//! \param StrAddressArray ��ַ��Ϣ[out]
		//! \param bAppoint �Ƿ�ָ�����ݼ���ѯ[in]
		//! \return ����ҵ�����TRUE,���򷵻�FALSE
		UGbool FindWordIDs(UGint &nPOs,UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &StrAddressArray,UGbool bAppoint = TRUE);
		
		//!	\brief �������ݼ�����	
		//! \param pArrDatasets ���ݼ�ָ������[in]
		//! \param ArrNames ���ݼ��ֶ���������[in]
		//! \return �������ݼ�����ɹ�����TRUE,����FALSE	
		UGbool SetDatasets(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief ׷�����ݼ�����	
		//! \param pArrDatasets ���ݼ�ָ������[in]
		//! \param ArrNames ���ݼ��ֶ���������[in]
		//! \return ׷�����ݼ�����ɹ�����TRUE,����FALSE	
		UGbool AppendDatasets(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief �ж����ݼ��Ƿ���Ч	
		//! \param pDataset ���ݼ�ָ��[in]
		//! \return ���ݼ���Ч����TRUE,����FALSE	
		UGbool IsDatasetValid(UGDatasetVector* pDatasetNew,UGString &strFeildName);
		
		//!	\brief �õ���ǰ�ĵ�ͼͼ��	
		//! \param pDatasetNew ���ݼ�ָ��[in]
		//! \return �������ݼ�ͼ�����ڵ�LayerID	
		UGint  GetDatasetLayerID(UGDatasetVector* pDatasetNew);

		//!	\brief �õ����е�ǰ���ݼ���ͼ��	
		//! \param pDatasetNew ���ݼ�ָ��[in]
		//! \return �ɹ��ҵ����е�ͼͼ�㷵��TRUE,����FALSE	
		UGbool GetDatasetLayerIDs(UGDatasetVector* pDatasetNew,UGArray<UGint> &arrlayerIDs);

		//!	\brief ����ָ�����ݼ���nDTIndex
		//! \param nDTIndex ���ݼ�ָ������[in]
		//! \return ������óɹ�����TRUE,���򷵻�FALSE
		UGbool SetDatasetnLayer(UGint nDTIndex);

		//!	\brief ɾ�����ݼ�����	
		//! \return ɾ��ָ�����ݼ�����
		UGbool RemoveDatasetnLayer();
		
		//!	\brief �ͷ����ݼ�����	
		//! \return �ͷ����ݼ�����	
		UGbool ReleaseDatasets();

		//!	\brief �����˵�ͼ���ݼ������ĳ����ѡ�����ݼ��Ѿ���ӣ����ü��������
		//! \param pArrDatasets ���ݼ�ָ������[in]
		//! \param ArrNames ���ݼ��ֶ���������[in]
		void CheckDatasetValid(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
			
		//!	\brief ���ҵ�ͼ��ַ�ĺ���
		//! \param MapLayerID ������ҵĵ�ͼ��Ϣ[in]
		//! \param strAddress ���ҵĵ�ͼ��Ϣ[out]
		//! \return ���ز��ҵõ��ĵ�ַ
		UGbool FindMapAdress(UGint nIDCount,CHAddressDataID &MapLayerID,UGString &strAddress,UGint & nLength);
		
		//!	\brief ���ص�ͼ����
		//! \param pArrDatasets ���ݼ�ָ������[in]
		//! \param ArrNames ���ݼ��ֶ���������[in]
		//! \param bAdd �Ƿ���ӣ������FALSE���ǲ����[in]
		//! \return ������سɹ��ͷ���TRUE,���򷵻�FALSE
		UGbool  LoadMapData(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief ׷�ӵ�ͼ����
		//! \param pArrDatasets ���ݼ�ָ������[in]
		//! \param ArrNames ���ݼ��ֶ���������[in]
		//! \return ���׷�ӳɹ��ͷ���TRUE,���򷵻�FALSE
		UGbool  AppendMapData(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief ׷�ӵ������ݼ��ĵ�ͼ����
		//! \param pArrDataset ���ݼ�ָ��[in]
		//! \param ArrName ���ݼ��ֶ�����[in]
		//! \return ���׷�ӳɹ��ͷ���TRUE,���򷵻�FALSE
		UGbool  AppendMapData(UGDatasetVector* pDataset,UGString &FieldName);

		//!	\brief �õ����ݼ��ĸ���
		//! \return �������ݼ��ĸ���
		UGint GetDataSetCount();

		//!	\brief �õ��������λ�õ����ݼ�ָ��
		//! \param nPos ����λ��[in]
		//! \return �����������λ�õ����ݼ�ָ��
		UGDatasetVector* GetDataSetAt(UGint nPos);

		//!	\brief ���ò�ѯ���ݼ�
		//! \param ArrnDTIndex ָ�����ݼ���ַ��Ϣ����[in]
		//! \return ����ƥ��ķ���
		UGbool SetSearchDT(UGArray<UGint> &ArrnDTIndex);

		//!	\brief ��ѯ���ݼ�����
		//! \return ���ݼ�����ɹ�����TRUE�����򷵻�FALSE
		UGbool SortSearchDT();

		//!	\brief ������������
		//! \param location �����ַ��Ϣ[in]
		//! \return ������ҵ���ص����ݼ�����TRUE�����򷵻�FALSE
		UGbool FindIndexDT(UGint nPos,UGArray<UGint> &arrnDTIndex,UGint nCount);

		UGint GetMapIDCount();

private:
		//! \brief ���㺺������λ��
		//! \param High  ���ָ�λ[in]
		//! \param Low  ���ֵ�λ[in]
		//! \return ���ֵ�����nID
		//! \remarks ��ע��Ϣ
		UGuint ComputeChID(UGuchar High,UGuchar Low);
		
		//! \brief �õ��ַ�����
		//! \param sChar �ַ���[in]
		//! \return �ַ�����
		UGint CharType(UGuchar *pcChar);	
		
		//! \brief ���㺺������λ��
		//! \param sString �ַ���[in]
		//! \return �ַ������ֵ�����λ��
		UGuint ComputeChnPos(UGchar *pcString);
		
		//! \brief �ж�sString�Ƿ��Ǻ����ַ�
		//! \param sString �ַ���[in]
		//! \return ���ȫ�Ǻ��ַ���true�����򷵻�false
		UGbool IsAllChinese(UGuchar *pucString);
		
		//! \brief �ж��ַ����Ƿ��ǵ��ֽ��ַ�
		//! \param sString �ַ���[in]
		//! \return ���ȫ�ǵ��ֽ��ַ�����true�����򷵻�false
        UGbool IsAllSingleByte(UGuchar *pucString);
		
		//! \brief �ӵ���strAddress�л�ȡ����
		//! \param strAddress Ŀ�괮[in]
		//! \return �ӵ���strAddress�л�ȡ����,���ؾ��Ǹ�����;���û������,�ͷ��ؿ��ַ���
		UGString GetNumeric(UGString  strAddress);

		//!\brief ���ַ���
		//! \param string	�ִ��ַ���
		//! \param strCharSet �ַ���
		//! \return	        �Ҵ���
		UGchar *CHWordFind(const UGchar *pctring, const UGchar *pcstrCharSet);
		
		//!	\brief ���������в��Ҵ���
		//! \param nPos  ����λ��nID
		//! \param sWord  ����
		//! \param pFindRet ����ͷָ��[out]
		//! \return ����ҵ�����TRUE�����򷵻�FALSE
		UGbool FindInOriginalTable(UGint &nPos,UGchar *pcWord,PCHWORD_CHAIN *pFindRet);
		
		//!	\brief ���������в��Ҵ���
		UGbool FindInOriginalTable( UGint &nPos,UGchar *pcWord);

		//!	\brief ���������в��Ҵ������λ��
		UGint FindInsetPos(UGint nPos,UGchar *pcWord,UGint nCount,UGint &nPosIndex);

		//!	\brief ���������в��Ҵ���	
		//! \param nPos ����λ��nID[in]
		//! \param sWord  ���ﴮ[in]
		//! \param pFindRet ������ʽָ��[out]
		//! \return ����ҵ�����TRUE�����򷵻�FALSE
		UGbool FindPreNodeInOriginalTable(UGint &nPos,UGchar *pcWord,PCHWORD_CHAIN *pFindRet);

		//!	\brief ���������в��Ҵ����Ǹ�������ĸ���	
		//! \param nPos ����λ��nID[in]
		//! \param pWord �����ַ���[in]
		//! \return ���ص�����������nID��nPos,�Ҵ�����sWord���ݵĴ������
		UGint GetWordCount(UGint &nPos,UGchar *pcWord);
		
		//!	\brief ���������в��Ҵ������	
		//! \param nPos ����λ��nID[in]
		//! \return ���ص�����������nID��nPos�Ĵ������		
		UGint GetWordCount(UGint &nPos);
		
		//!	\brief �����������ܵĴ�����ֵĸ���	
		//! \return ���ص������������ܵĴ�����ֵĸ���	
		UGint GetWordTotalCount();
		
		//!	\brief �����������ܵĴ������	
		//! \return ���ص������������ܵĴ������	
		UGint GetCHWordTotalCount();
		
		//!	\brief ���������д������ĸ���	
		//! \return ���ص������������д������ĸ���	
		UGint GetCHWordMaxCount();
		
		//!	\brief �ڵ�ͼ���ݱ�������λ����nPos�Ĵ�����sWord��صĵ�ַnID����	
		//! \param nPos ����λ��nID[in]
		//! \param pWord �����ַ���[in]
		//! \return �ڵ�ͼ���ݱ�������λ����nPos�Ĵ�����sWord��صĵ�ַnID����	
		UGint GetMapWordIDSCount(UGint &nPos,UGchar *pcWord);
		
		//!	\brief �ڵ�ͼ���ݱ�������λ����nPos�Ĵ�����صĵ�ַnID���� 	
		//! \param nPos ����λ��nID[in]
		//! \return ���ص������ڵ�ͼ���ݱ�������λ����nPos�Ĵ�����صĵ�ַnID���� 	
		UGint GetMapWordIDSCount(UGint &nPos);
		
		//!	\brief ��ͼ�����ܵĴ������	
		//! \return ���ص��ǵ�ͼ�����ܵĴ������	
		UGint GetMapWordIDSTotalCount();
		
		//!	\brief �õ�������ַ�зֵĸ���	
		//! \param SigleAddressSeg ��ַ��[in]
		//! \return ���ص�����ַ�зֵĸ���	
		UGint GetSigleAddressSegCount(UGString &SigleAddressSeg);
		
		//!	\brief ���ص�������
		//! \param nDTIndex ͼ��[in]
		//! \param nID nID[in]
		//! \param sWord ���ﴮ����[in]
		//! \return �ɹ����ط���TRUE,���򷵻�FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGchar *pcWord);

public:
		//! \brief ���ݼ�����
		UGArray<UGDatasetVector*> m_pArrDatasets;
			
			//! \brief ��ַ�ֶ�������
		UGStrArray m_ArrNames;

private:
		//! \brief ����ָ��
		pCHAdressINDEX_TABLE m_pMapIndexTable;
		//CHAdressINDEX_TABLE  m_pMapIndexTable[UG_GEOCODE_CHNSIZE];

         //! \brief �ʵ���
		UGDictionary m_dictCore;
		
		//! \brief �ִ���
		UGMPWordSeg  m_MPWordSegment;

		//! \brief ָ��ͼ��ID����
		UGArray <UGint> m_ArrnDTIndex;
		
		//! \brief ��ͼ�ֶ���Ϣ�洢
		UGArray<UGCHMapData>    m_ArrCHMapData;

		//! \brief ��ͼÿ��ͼ�����ĸ���
		UGArray< UGint >    m_ArrLayerCount;
		
		//! \brief ָ��ͼ���nDTIndex
		//UGint  m_nLayer;
		
  protected:
		//! \brief �ֶ�
		UGFieldInfo m_FieldInfo ;
};

}

#endif
