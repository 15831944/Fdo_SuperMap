#ifndef UGSYMBOL_H
#define UGSYMBOL_H

#include "Base/UGString.h"
#include "Algorithm/UGPoint.h"

namespace UGC 
{
	/** Symbol���ż̳���ϵ�ĳ������
	    @remarks
		    1��ÿ�����Ŷ���һ��ID(>0),����һ�����֣�
			2��ϵͳ�������ַ��ţ�����š��߷��š�������
			3�����־�����ŵ�����UGPointSymbol��UGLineSymbol��UGFillSymbol
			   ���Ӹó������UGSymbol�̳�
			4�����ű�����ж�д���ܣ�Load()��Save()
	*/
	class SYMBOL_API UGSymbol  
	{
	public:
		UGSymbol( UGint id = -1) : m_nID(id)
		{
		}

		virtual ~UGSymbol()
		{
			// virtual Destructor
		}

        //��ʱ��û�б�Ҫ  Y.M.Zheng 
		//UGSymbol(const UGSymbol& symbol){}
		//virtual void operator = (const UGSymbol& symbol){}
		
	public:
		UGint GetID() const
		{
			return m_nID;
		}
		
		void  SetID(UGint nID)
		{
			m_nID = nID;
		}
		
		UGString GetName() const
		{
			return m_strName;
		}
		
		void SetName(const UGString& strName)
		{
			m_strName = strName;
		}
		
		UGbool IsModified() const
		{
			return m_bModified;
		}
		
		void SetModifiedFlag(UGbool bModified = true)
		{
			m_bModified = bModified;
		}
		
		virtual UGbool Load(UGStream& stream, UGuint nVersion = 0) = 0;
		virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const = 0;
		
	protected:  
		//����Ϊprotected����Ϊ���������ܹ���ȡ֮��
		//�ر�أ�Ϊ�������operator =���غ����п���ֱ��Ϊ�������ݸ�ֵ

		UGbool   m_bModified;
		UGint    m_nID;
		UGString m_strName;
		
	};
	
}

#endif


