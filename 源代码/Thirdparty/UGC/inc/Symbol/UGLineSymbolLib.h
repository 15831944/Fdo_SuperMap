
// UGLineSymbolLib.h

#ifndef UGLINESYMBOLLIB_H
#define UGLINESYMBOLLIB_H

#include "UGSymbolLib.h"
#include "UGLineSymbol.h"
#include "UGMarkerSymbolLib.h"

namespace UGC 
{
	
	/** �߷��ſ�
	*/
class SYMBOL_API UGLineSymbolLib : public UGSymbolLib 
{
public:
	UGLineSymbolLib();
	virtual ~UGLineSymbolLib();
	
	virtual UGbool Load(UGStream& stream);	
	virtual UGbool Append(UGStream& stream, UGbool bReplace = true);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	void SetResMarkerSymLib(UGMarkerSymbolLib* pResSymLib);
	UGMarkerSymbolLib* GetResMarkerSymLib() const;
	UGMarkerSymbolLib* GetMarkerSymLib();
	
protected:
	//! ��Դ�еĵ���ſ��ָ��
	UGMarkerSymbolLib* m_pResSymLib;
	
	//! ���߷��ſ���Ҫʹ�õ��ĵ���ſ�(�����߷��ŵ��Զ�����չ����)
	UGMarkerSymbolLib m_MarkerSymLib;
};
	
}

#endif


