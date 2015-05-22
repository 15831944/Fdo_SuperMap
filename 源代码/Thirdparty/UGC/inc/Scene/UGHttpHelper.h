// UGHttpHelper.h: interface for the UGHttpHelper class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGHTTPHELPER_H
#define UGHTTPHELPER_H

#include "Scene/UGPrerequisites.h"
#include "Base/UGFileStream.h"
#include "Algorithm/UGRect2D.h"

namespace UGC{
	
//! \brief Http���֣��ṩWeb����Դʹ�õ���Http���󼰽�������ز�����
//! \remarks ��ע��Ϣ��
class SCENE_API UGHttpHelper
{
public:
UGHttpHelper();

virtual ~UGHttpHelper();

enum RequestMethod
{
	GET = 0,
	POST = 1
};

enum HttpFileType
{
	CHARACTER = 0,
	BINARY = 1
};

enum ProtocolType
{
	FTP = 1,
	GOPHER = 2,
	HTTP = 3
};


//! \brief ͨ��URL����õ���������Ӧ�ļ������浽�궨·����
//! \param strURL ������URL��ַ[in]��
//! \param strDstPath ����õ����ļ��ĵ�ַ���ļ���[in]��
//! \param strUser ��¼�������û���,���������ÿ�[in]��
//! \param strPasswd ��¼������������,���������ÿ�[in]��
//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
//! \return �Ƿ�ɹ��õ��ļ�,�ɹ�����TRUE,ʧ�ܷ���FALSE����
//! \remarks ��
//! \attention ��
static UGbool RequestFile2(UGString strURL,UGString strDstPath, UGString strUser, 
	UGString strPasswd, RequestMethod reqMmethod, HttpFileType fileType);


};
	
}
#endif // !defined(UGHTTPHELPER_H)
