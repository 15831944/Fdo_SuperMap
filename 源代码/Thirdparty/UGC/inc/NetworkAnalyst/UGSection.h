// ����˵����		��̬�ֶ�·�ɶ���

#ifndef UGSECTION_H
#define UGSECTION_H

#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGSection
{
public:
	///	���캯��	
	UGSection();

	/// ��������
	virtual ~UGSection();
	
	/// ���ڲ�����
	UGbool operator==(const UGSection& sec);
	
	/// �����ڲ�����
	UGbool operator!=(const UGSection& sec);
	
public:
	UGint m_nArcID;			/// ��Ӧ�Ļ���ID
	UGint m_nRouteID;		/// ��Ӧ��Route ID
	UGdouble m_dFromMeasure;	/// ��ʼ�߱�ֵ
	UGdouble m_dToMeasure;	/// ��ֹ�߱�ֵ
	UGdouble m_dFromPos;		/// �ڻ����ϵ���ʼλ��
	UGdouble m_dToPos;		/// �ڻ����ϵ���ֹλ��
};

}


#endif
