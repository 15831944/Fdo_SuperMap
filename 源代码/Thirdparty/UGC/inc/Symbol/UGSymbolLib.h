
//UGSymbolLib.h

#ifndef UG_SYMBOLLIB_H
#define UG_SYMBOLLIB_H

#include "Base/UGString.h"
#include "Base/UGStream.h"
#include "Base/UGDict.h"
#include "UGSymbol.h"
#include "UGSymbolGroup.h"

namespace UGC 
{
	/** ������Դ��
	    @remarks
		    1.�洢���ŵĲֿ⣻
			2.���ö༶��������֯�͹�����ţ�
			3.������: 
			    ��һ�����Ŵ洢�б�(m_Symbols)�����д��ϵͳ�����еķ���(����ָ��UGSymbol*)��
				��һ������ID�����б�(m_IDs)�����д��m_Symbols�еķ��ŵ�ID��
				��һ���������ĸ���(m_pRootGroup)��
			4.Ҫͬʱά��m_Symbols��m_IDs����ɾ������m_Symbols��m_IDs��Ԫ�ظ���ʱʱ����һ�£�
			5.֧�ֶ�д���ܣ�
	*/
	class SYMBOL_API UGSymbolLib  
	{
	public:
		UGSymbolLib();
		virtual ~UGSymbolLib();
		
		//----------------------------------------------------------------
		virtual UGbool Load(UGStream& stream) = 0;
		virtual UGbool Append(UGStream& stream, UGbool bReplace = TRUE) = 0;
		//! nVersion��Ĭ��ֵ����߰汾
		virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const = 0;
		//----------------------------------------------------------------

		UGbool LoadFromFile(const UGString& strFileName);
		UGbool AppendFromFile(const UGString& strFileName, UGbool bReplace = TRUE);
		//! nVersion��Ĭ��ֵ0��ʾ��߰汾
		UGbool SaveToFile(const UGString& strFileName, UGuint nVersion = 0) const;

		//----------------------------------------------------------------
		
		UGbool AddSymbol(UGSymbol *pSymbol, UGSymbolGroup *pSymbolGroup = NULL);
		
		//----------------------------------------------------------------

		UGSymbolGroup* GetRootGroup() const;
		UGint GetSymbolCount() const;

		//----------------------------------------------------------------
		
		UGbool IsIDExisted(UGint nID) const;

		//! ���ҷ���ID�������������Ҳ�������-1
		UGint FindID(UGint nID) const;
		//! ���ҷ������ƣ���������
		UGint FindName(const UGString& strSymName, UGint nStartIndex = 0) const;
		//! ������ҷ������ƣ�����������������ʼ�����Ӻ���ǰ��
		UGint ReverseFindName(const UGString& strSymName, UGint nStartIndex = 0) const;
		
		UGbool Swap(UGint nOldIndex, UGint nNewIndex);
		
		UGint GetMaxID() const;
		void SortByID();
		
		void RemoveAll();
		//! �Ƴ�ָ��λ�õķ��ţ������Ƴ���Ŀ
		UGint RemoveAt(UGint nIndex, UGint nCount = 1);
		//! �Ƴ�ָ��ID����
		UGbool RemoveID(UGint nID);
		
		UGSymbol* GetSymbolAt(UGint nIndex) const;
		//! ����IDΪnID�ķ��ţ�û���ҵ��򷵻�NULL
		UGSymbol* GetSymbolByID(UGint nID) const; 

		//! ����ָ��λ�õķ��ţ������ԭ�����ͷ�
		//	void SetAt(UGint nIndex, UGSymbol* pSymbol);
		void InsertAt(UGint nIndex, UGSymbol* pSymbol);
		
		UGint GetIDAt(UGint nIndex) const;
		UGbool SetIDAt(UGint nIndex, UGint nID);
		
		UGString GetNameAt(UGint nIndex) const;
		void SetNameAt(UGint nIndex, const UGString& strSymName);
		
		UGbool IsModified() const;
		void SetModifiedFlag(UGbool bModified = TRUE);
		
		
		UGuint GetVersion();
		
		UGString GetDefaultPath() const;
		void SetDefaultPath(const UGString& strPathName);
		
		UGbool LoadDefault();
		
	protected:

		//! ���Ŵ洢�б�
		UGDict<UGint, UGSymbol*> m_Symbols;

		//! ����ID������֯�б�
		UGArray<UGint> m_IDs;
			
		//! �������ĸ���
		UGSymbolGroup *m_pRootGroup;

		//! �汾
		UGuint m_nVersion;

		UGbool m_bModified;
		
		UGString m_strDefaultPath;
	};
	
}

#endif


