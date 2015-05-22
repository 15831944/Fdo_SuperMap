
#ifndef UG_SYMBOLGROUP_H
#define UG_SYMBOLGROUP_H

#include "Base/UGString.h"
#include "Base/UGStream.h"

namespace UGC 
{
	
	class UGSymbolLib;
	
	/** ���Ź���ķ���
	    @remarks
		    1.֧�ֶ༶����(һ������������ж������m_ChildGroups)
			2.��֯����һ����ţ���Щ���ű���Ϊ�����Item(m_Items�м�¼��������ŵ�ID)
			3.֧�ֿ���Ϣ�Ķ�д
	*/
	class SYMBOL_API UGSymbolGroup  
	{
	public:
		UGSymbolGroup();
		UGSymbolGroup(UGSymbolLib *pSymbolLib);
		~UGSymbolGroup();

		UGSymbolLib* GetAttachedLib();
		void AttachLib(UGSymbolLib * pLib);

        //{{----------�������صĲ���------------------------------------
		UGSymbolGroup* GetParentGroup() const;
		void SetParentGroup(UGSymbolGroup* pParentGroup);

		UGSymbolGroup* GetRootGroup() const;  //�õ�ϵͳ�ĸ���
		UGSymbolGroup* GetChildGroup(UGint nIndex) const;
		UGSymbolGroup* GetChildGroup(const UGString& strName) const;
		UGint GetChildGroupCount() const;

		//! �������飬�����´��������ָ�룬���û�гɹ�������NULL
		UGSymbolGroup* CreateChildGroup(const UGString& strName);
		UGbool AppendGroup(UGSymbolGroup *pSymbolGroup);
		UGbool IsChildGroupExisted(const UGString& strName);
		
		UGString GetGroupName() const;
		void SetGroupName(const UGString& strName);
		//}}--------------------------------------------------------------

        //{{----------��Item����ز���------------------------------------
		UGint GetItemCount() const;
		UGint GetItemID(UGint nIndex) const;
		UGbool SetItemID(UGint nIndex, UGint nID);
		
		UGString GetItemName(UGint nIndex) const;
		void SetItemName(UGint nIndex, const UGString& strItemName);
		
		UGint FindItemID(UGint nID) const; //! �ڱ����ڲ���ID����������
		UGbool IsExistID(UGint nID) const;//! �ڱ��鼰��������ID�Ƿ����

		//�ú�����һ���ڲ����������治Ҫʹ�á�
		UGbool AddItem(UGint nID);  
		//}}--------------------------------------------------------------


		//-------------������Ϣ�Ķ�д����---------------------------------
		void Load(UGStream& stream, UGuint nVersion = 0);
		void Save(UGStream& stream, UGuint nVersion = 0, UGint nSymLibType =0) const;
		//----------------------------------------------------------------
		
		//! �������Ҷ��(Item)������
		void Clear();
		
		//! �Ƴ����鼰��������ָ����ID����ɾ������
		UGbool RemoveSymbol(UGint nID);//
		
		//! �Ƴ�����ָ��������ID����ɾ�����ţ�����ɾ����Ŀ
		UGint RemoveItem(UGint nIndex, UGint nCount = 1);
		
		//! �Ƴ�����ָ�����������飬
		//! ���bMoveUpΪ�棬�������е�item�Ƶ��ϲ�������ɾ�����ţ�
		//! ���bMoveUpΪ�٣�ɾ������
		//! ���б����������������µ�������������
		UGbool RemoveChild(UGint nIndex, UGbool bMoveUp = false);
		
		//! ����Group�������Ŵ�nIndex��ʼ����nCount��Item�ƶ���pGroup��, �����ƶ�����Ŀ(ֻ���ƶ������������Ŵӿ���ɾ��)
		UGint MoveItemTo( UGint nIndex, UGint nCount, UGSymbolGroup* pGroup );

		//! �� �����������nID��Ӧ��Item �ƶ��� pGroup��(ֻ���ƶ������������Ŵӿ���ɾ��)
		UGbool MoveItemTo( UGint nID, UGSymbolGroup* pGroup );

		//! �ڱ��鼰���²���ID���ڵ���
		const UGSymbolGroup *FindChildGroupWithID(UGint nID) const;	
		//! ���������ڱ��鼰���²�����
		const UGSymbolGroup *FindChildGroup(const UGString& strChildName) const;
				
		UGbool IsModified() const;
		void SetModifiedFlag(UGbool bModified = true);
		
		//! ����ID�ڱ��鼰���½�������
		void SortByID();
		
	protected:
		
		//! ���������
		UGString                m_strName;       
		
		UGbool m_bModified;
		
		//! ���������ڵĿ�
		UGSymbolLib*            m_pSymbolLib;    
		
		//! ����ĸ��飬���m_pParentGroupΪNULL����ʾ��Ϊ����
		UGSymbolGroup*          m_pParentGroup;             
		
		//! �����µ���������
		UGArray<UGSymbolGroup*> m_ChildGroups;
		
		//! ��Group��֯�ķ���(Item)����¼��ID��
		//! ע:һ��Group�в���������ͬID��Item����,ͬʱ�������е�Item����Ӧ�ķ���ID����Ψһ��
		UGArray<UGint>          m_Items;
		
	};
	
}

#endif


