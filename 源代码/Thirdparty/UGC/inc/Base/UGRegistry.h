#ifndef UGREGISTRY_H
#define UGREGISTRY_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGMarkup.h"
#include "UGHash.h"
#include "UGToolkit.h"
#include "UGMarkup.h"

namespace UGC{

class BASE_API UGRegistry : public UGHash<UGString>
{
private:
	enum ElemType 
	{ 
		Value = 0, 
		Object = 1, 
		Sequence = 2, 
		ObjectSequence = 3, 
		SubRegistry = 4, 
		ExternalFile = 5 
	};
	static ElemType Convert(const UGString &strType);
	
public:
	typedef UGHash<UGString> ObjType;
	typedef UGArray<UGString> SeqType;
	typedef UGArray<ObjType> ObjSeqType;
	typedef UGHash<void*> VHash;
	typedef VHash::POSITION VHash_Pos;

protected:
	UGRegistry();
	UGRegistry(const UGString& file);
	void LoadFile(const UGString& filename);
	virtual void LoadDoc(const UGString& content);

	void SaveDoc(UGMarkup& markup);
	
public:
	static UGString XmlPath();
	
	static UGRegistry& Root();
	
	virtual ~UGRegistry();
	
//	static ObjType ObjNull;
//	static SeqType SeqNull;
//	static ObjSeqType ObjSeqNull;
//	static UGRegistry RegNull;
	
	UGString Encoding() const;
	ObjType& Obj(const UGString& s) const;
	SeqType& Seq(const UGString& s) const;
	ObjSeqType& ObjSeq(const UGString& s) const;	
	UGRegistry& SubReg(const UGString& s) const;
	UGRegistry& SubFile(const UGString& s) const;	
	UGString Name() const;

	//! \brief ���޸����ڴ��еĶ����洢��ugc.xml�ļ���
	UGbool Save();

	//! \brief �õ�SubFile�е��ļ���
	//! \param strTag ugc.xml�ļ��м�¼subfile�ı�ǩ������"PrjConfig"
	//! \return ������ugc.xml�ļ��м�¼���ⲿ�ļ���,��"PrjConfig.xml"
	//! \remarks �����ı�ǩΪ:<PrjConfig type="external">PrjConfig.xml</PrjConfig>
	UGString GetSubFileName(const UGString& strTag) const;

private: 
	VHash m_Objs;
	VHash m_Seqs;
	VHash m_ObjSeqs;
	VHash m_SubRegs;
	VHash m_SubExts;
	ObjType m_SubFiles;

	UGString m_strFileName;
	UGString m_strRootName;
};


//! ��resource.xml�ж�ȡ�ַ�����Դ����
//! \author zengzm
//! \remark resource.xml�����ݽ�����һЩ����, ��Ҫ�ǲ�����id��Ϊtag name,����id �Զ�����
//! �ʶ�ԭ��Registry�಻������. �����Registry������ר�Ŵ���resource.xml����
class UGRegistryResource : public UGRegistry
{
public:
	virtual void LoadDoc(const UGString& content);
};

//! ��epsfont.xml�ж�ȡ�ַ�����Դ����
class UGRegistryEpsFont: public UGRegistry
{
public:
	virtual void LoadDoc(const UGString& content);
};

}
#endif
