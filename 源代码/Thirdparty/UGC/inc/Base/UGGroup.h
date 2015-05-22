/**  \file UGGroup.h
   \brief ʵ�ַ������Ļ���
   \author lugw
   \attention 
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */

#if !defined(AFX_UGGROUP_H__2A4A8687_DF92_47D3_B1A2_0E2DA769546B__INCLUDED_)
#define AFX_UGGROUP_H__2A4A8687_DF92_47D3_B1A2_0E2DA769546B__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
//#include "Base/UGArray.h"
#include "Base/UGList.h"

namespace UGC
{	
	class BASE_API UGGroup  
	{
	public:
		enum GroupDataType
		{
			NoneData   = 0,           //û������
			Group      = 1,           //����
			//DataSource = 2,         //����Դ����			
			LayerData  = 2            //ͼ����
		};
		
		struct UGGroupItem 
		{
			void*    pData;
			UGint    nType;
			UGGroup* pParentGroup;
			UGGroupItem()
			{
				pData = NULL;
				nType = UGGroup::NoneData;
				pParentGroup = NULL;
			}
		};

		public:
			UGGroup();
			virtual ~UGGroup();		
			
			//{{----------�������صĲ���------------------------------------
			UGGroup* GetParentGroup() const;
			void SetParentGroup(UGGroup* pParentGroup);
			
			UGGroup* GetChildGroup(UGint nIndex) const;
			UGGroup* GetChildGroupByID(UGint nID) const;
			UGGroup* GetChildGroup(const UGString& strName) const;
			//UGint GetChildGroupCount() const;
			
			//! �������飬�����´��������ָ�룬���û�гɹ�������NULL
			UGGroup* CreateChildGroup(const UGString& strName, UGbool bTop = false);
			//UGbool AppendGroup(UGGroup *pGroup, UGbool bTop = false);

			virtual void AddItem(void* pData, UGbool bTop = false);
			virtual void DeleteItem(UGGroupItem* pGroupItem);
			UGint GetItemCount();
			UGGroupItem* FindItemAt(UGint nIndex);
			
			UGString GetGroupName() const;
			void SetGroupName(const UGString& strName);

			//�ƶ�����
			UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
			UGbool MoveTo(UGint nIndexFrom, UGGroup* pFromGroup, UGint nIndexTo, UGGroup* pToGroup);
			UGbool MoveBottom(UGint nIndex);
			UGbool MoveDown(UGint nIndex);
			UGbool MoveUp(UGint nIndex);
			UGbool MoveTop(UGint nIndex);

			//�Ƴ�
			UGbool RemoveItem(UGint nIndex, UGbool bMoveUp = false);
			//}}-------------------------------------------------------------

			void clear();
			UGint GetCount()const;
			UGint GetGroupID()const;
			UGGroupItem* GetAt(UGint nIndex)const;
			UGbool RemoveAt(UGint nIndex);
			void RemoveAll();
			void Add(UGGroupItem* pGroupItem, UGbool bTop = false);

			UGList<UGGroupItem*>::POSITION GetTailPosition();
			UGList<UGGroupItem*>::POSITION GetHeadPosition();
			UGbool IsBOF(UGList<UGGroupItem*>::POSITION pos);
			UGbool IsEOF(UGList<UGGroupItem*>::POSITION pos);
			UGGroupItem* GetPrev(UGList<UGGroupItem*>::POSITION pos);
			UGGroupItem* GetNext(UGList<UGGroupItem*>::POSITION pos);
		protected:
			void FindItemCount(UGList<UGGroupItem*> pGroupItemList, UGint& nItemCount);
			void FindItemAt(UGList<UGGroupItem*> pGroupItemList, const UGint nIndex, UGint& nNowIndex, UGGroupItem* pTargetItem);
			UGList<UGGroupItem*> GetGroupItemList();
			

		private:
			UGList<UGGroupItem*> m_pGroupTree;
			UGString m_strGroupName;
			UGint m_nID;
			UGGroup* m_pParentGroup;
			UGint m_nChildGroupNum;
			//UGbool m_bDelete;
	};
	
}

#endif // !defined(AFX_UGGROUP_H__2A4A8687_DF92_47D3_B1A2_0E2DA769546B__INCLUDED_)
