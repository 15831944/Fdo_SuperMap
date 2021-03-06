// UGReferenced.h: interface for the UGReferenced class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGREFERENCED_H
#define UGREFERENCED_H
#include "Base/ugdefs.h"
namespace UGC
{
	class UGDeleteHandler;
	//! \brief 与智能指针UGRefPtr配合使用
	class BASE_API UGReferenced  
	{
	public:
		UGReferenced()
		{
			m_nRefCount = 0;
		}
		UGReferenced(const UGReferenced&)
		{
			m_nRefCount = 0;
		}
		void Ref()const;
		void Unref() const;
		void UnrefNoDelete()const;
		inline UGint GetReferenceCount() const{return m_nRefCount;}
	public:
		friend class UGDeleteHandler;
		static UGDeleteHandler* GetDeleteHandler();
		static void SetDeleteHandler(UGDeleteHandler* handler);
		

	protected:
		virtual ~UGReferenced();
		
		mutable UGint m_nRefCount;
	
	};

	class UGDeleteHandler
	{
	public:
		virtual ~UGDeleteHandler(){}
		inline void DoDelete(const UGReferenced* pObject){delete pObject;};
		virtual void RequestDelete(const UGReferenced* pObject){DoDelete(pObject);}
	};
}


#endif 
