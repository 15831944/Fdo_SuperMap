/* 
	\file UGFuzzySearchTypes.h
	\brief ���ĵ�ַģ����ѯ��Ҫ�ļ����ṹ
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGFUZZYSEARCHTYPES_H
#define UGFUZZYSEARCHTYPES_H

namespace UGC {
//�ʵ�����Ҫ�Ľṹ��

//!	\brief�����������ݽṹ
struct tagWordItem
{
	//{{����������������´ʵ�
	//!	\brief ʹ��Ƶ��
	//UGint nUseCount; 
	//}}
	//!	\brief ���ﳤ��
	UGint nWordLen     ;
	//!	\brief Ƶ�ʣ����ִ���
	UGint nFrequency   ;                 
	//!	\brief ����ָ��
	UGchar *pcWord      ;    
	tagWordItem()
	{
		nWordLen = 0;
		nFrequency = 0;
		pcWord = NULL;
	}
};
typedef struct tagWordItem WORD_ITEM,*PWORD_ITEM;

//�ֵ�������ṹ
struct tagIndexTable
{
	//!	\brief ����
	UGint nCount                    ;     
	//!	\brief ����ͷ
	UGArray<WORD_ITEM> arrWordItemHead;     
	//!	\brief ����ͷ
	//PWORD_ITEM pWordItemHead;   
	tagIndexTable()
	{
		nCount = 0;
		arrWordItemHead.RemoveAll();
	};
};
typedef struct tagIndexTable INDEX_TABLE;

//���أ���ѯ����Ҫ�Ľṹ��
struct CHtagAddressDataID 
{
	//!	\brief ���ݼ�����
	UGuint nDTIndex;                     
	//!	\brief ����ID
	UGuint nID; 
	//!	\brief �ִʵ�λ��
	//UGint nPos;
};
typedef struct CHtagAddressDataID CHAddressDataID,*PCHMapLayer;

//!	\brief �����������ݽṹ
struct ChtagWordItem
{
	//!	\brief ���ﳤ��
	UGint nWordLen ;        
	//!	\brief Ƶ�ʣ����ִ���
	UGint  nCount  ;
	//!	\brief ����
	UGchar *pcWord  ;  
	//!	\brief  
	UGArray<CHAddressDataID> ChAddressIDs;
};
typedef struct ChtagWordItem CHWORD_ITEM,*PCHWORD_ITEM;
	
//!	\brief �������ݽṹ
struct CHtagWordChain
{
	//!	\brief  ��������
	CHWORD_ITEM data           ;            
	//!	\brief  �¸�����
	struct CHtagWordChain *next;           
};
typedef struct CHtagWordChain CHWORD_CHAIN,*PCHWORD_CHAIN;

//!	\brief �ֵ�������ṹ
struct CHtagIndexTable
{
	//!	\brief ����
	UGint nCount           ;          
	
	//!	\brief ����ͷ
	//PCHWORD_CHAIN pWordItemHead; 

	UGArray <CHWORD_ITEM> arrWordItems;
	
};
typedef struct CHtagIndexTable CHAdressINDEX_TABLE,*pCHAdressINDEX_TABLE;

//!	\brief ������ݱ����ʽ
struct UGCHAddressMapData
{
	UGint            m_Len; 
	CHAddressDataID  m_ChAddressIDs;
	UGString         m_MapAdress;
	
};
typedef struct UGCHAddressMapData UGCHMapData;

//!	\brief ������ݱ����ʽ
struct UGCHAddressLocation
{
	//!	\brief ��ѡ����ƥ��״̬
	UGint		m_nCandidateState;	
	//!	\brief �õ��õķ��� ��0��100֮��
	UGdouble	m_nScore		;	
	CHAddressDataID  m_ChAddressIDs;
	UGString    m_MapAdress;	
};

//!	\brief ������ݱ����ʽ
struct UGCHSearchMode
{
	//!	\brief ��ѡ����ƥ��״̬
	UGint		m_nSearchMode;	
	//!	\brief �õ��õķ��� ��0��100֮��
	UGchar		m_chword;
	//!	\brief �дʺ��ַ
	UGString    m_strWordAdress;	
};

//!	\brief �����������������Ҫ�ıȽϺ�����
class CHResultCompareTemp
{
public:
	
	UGbool operator()(const UGCHAddressLocation& CHResult1, const UGCHAddressLocation& CHResult2) 
	{
		
		if (CHResult1.m_nScore == CHResult2.m_nScore)
		{
			if (CHResult1.m_ChAddressIDs.nDTIndex == CHResult2.m_ChAddressIDs.nDTIndex)
			{
				if (CHResult1.m_ChAddressIDs.nID > CHResult2.m_ChAddressIDs.nID)
				{
					return FALSE;
				}
				else
				{
					return TRUE;
				}
				
			}
			else if (CHResult1.m_ChAddressIDs.nDTIndex > CHResult2.m_ChAddressIDs.nDTIndex)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		//!	\brief ע������Ǵ�С�����Ŷ
		else if (CHResult1.m_nScore < CHResult2.m_nScore)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
};

//!	\brief ���ݼ�ID����������Ҫ�ıȽϺ�����
class CHMapDataCompareTemp
{
public:
	
	UGbool operator()(const UGCHMapData& CHMapData1, const UGCHMapData& CHMapData2) 
	{
		
		if (CHMapData1.m_ChAddressIDs.nDTIndex == CHMapData2.m_ChAddressIDs.nDTIndex)
		{
			if (CHMapData1.m_ChAddressIDs.nID > CHMapData2.m_ChAddressIDs.nID)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		else if (CHMapData1.m_ChAddressIDs.nDTIndex > CHMapData2.m_ChAddressIDs.nDTIndex)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
};

//!	\brief ����������Ҫ�ıȽϺ�����
class CHAddressDataIDCompare
{
public:
	
	UGbool operator()(const CHAddressDataID& CHAddressDataID1, const CHAddressDataID& CHAddressDataID2) 
	{
			if (CHAddressDataID1.nDTIndex < CHAddressDataID2.nDTIndex)
			{
				return TRUE;
			}
			else if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
			{
				return CHAddressDataID1.nID < CHAddressDataID2.nID;
			}
			else
			{
				return FALSE;
			}
	}
		/*
		
		  if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
		  {
		  if (CHAddressDataID1.nID > CHAddressDataID2.nID)
		  {
		  return FALSE;
		  }
		  else
		  {
		  return TRUE;
		  }
		  }
		  else if (CHAddressDataID1.nDTIndex > CHAddressDataID2.nDTIndex)
		  {
		  return FALSE;
		  }
		  else
		  {
		  return TRUE;
		  }
	*/
};

class CHAddressDataIDCompareEqual
{
public:
	
	UGbool operator()(const CHAddressDataID& CHAddressDataID1, const CHAddressDataID& CHAddressDataID2) 
	{
		
		if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
		{
			return CHAddressDataID1.nID == CHAddressDataID2.nID;
		}
		else
		{
			return FALSE;
		}
	}

};

}
#endif

