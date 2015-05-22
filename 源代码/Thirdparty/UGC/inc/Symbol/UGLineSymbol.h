
//UGLineSymbol.h

#ifndef UG_LINESYMBOL_H
#define UG_LINESYMBOL_H

#include "UGSymbol.h"
#include "UGLineSymbolExt.h"
#include "UGLineSymbolBase.h"

namespace UGC {
	
	/** �߷���
	    @remarks
		    1���߷����ɶ���߻�(LineBase�����Ϊ����)�����ص���ɣ�
			   ��Щ�߻���m_LineBases����֯����
			2��ͬʱ�߷��ſ�����һ��������չ���η�(LineSymbolExt)-->�μ�UGLineSymbolExt
			   ������չ�м�¼�����ɸ�λ�õ�token���η���Ϣ
	*/
class SYMBOL_API UGLineSymbol : public UGSymbol
{
public:
	UGLineSymbol();
	virtual ~UGLineSymbol();
	
	UGLineSymbol(const UGLineSymbol& rhs);
	UGLineSymbol& operator = (const UGLineSymbol& rhs);
	
public:
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;	
	
	//! ���ƺ���һ(����һ������)
	void DrawPolyline(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, UGLineSymParam& DrawingParam);
	//! ���ƺ�����(ͬʱ���ƶ�������)
	void DrawPolyPolyline(UGGraphics& graphics, const UGPoint* pPoints, 
		const UGint* pPntCounts, UGint nLineCount, UGLineSymParam& DrawingParam);	
	
	UGbool Merge(const UGLineSymbol& rhs);
	
	const UGLineSymbolExt& GetExtToken() const;
	UGLineSymbolExt& GetExtToken();
	void SetExtToken(const UGLineSymbolExt& extToken);
	
	UGint GetCountOfLineBase() const;
	UGLineSymbolBase* GetLineBaseAt(UGint nIndex) const;
	void AddLineBase(UGLineSymbolBase* pLineSymBase);
	void InsertLineBaseAt(UGint nIndex, UGLineSymbolBase* pLineSymBase);
	UGint RemoveLineBaseAt(UGint nIndex, UGint nCount = 1);
	void RemoveAllLineBase();
	
	UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
	UGbool MoveBottom(UGint nIndex);
	UGbool MoveDown(UGint nIndex);
	UGbool MoveUp(UGint nIndex);
	UGbool MoveTop(UGint nIndex);

	UGbool CanProcessCrossroad();

protected:
	//! �������ز���ȥ��
	UGbool LampHouseSmooth(const UGPoint* lpPoints, UGint nCount, UGdouble dTolerance, UGPoints &arrPoints);

	
protected:
	//! ��չ���η�
	UGLineSymbolExt m_ExtToken;

	//! ���߷��ŵĻ��ߴ洢������
	UGArray<UGLineSymbolBase*> m_LineBases;
};

}

#endif

