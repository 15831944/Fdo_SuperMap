
/*!
    **************************************************************************************
     \file     UGFileStdio.h
    **************************************************************************************
     \author   ����
     \brief    �ı��ļ���                   
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-28  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_)
#define AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_

#include "Base/UGFileStream.h"
#include "Base/UGString.h"

namespace UGC{


class BASE_API UGFileStdio  
{
public:
	
	//�ļ����з�����
	enum EnterType
	{
		Enter_Adapt = 1,   //��ǰ�ĸ���ϵͳ
		Enter_Windows = 2, //Windows�ϵĻ��з�
		Enter_Unix = 3    //Linux��Unix�ϵĻ��з�
		//Enter_Other = 4    //������ϵͳ�����ڲ�֪������WinCE�ȣ��Ժ������չ
	};


	UGFileStdio();
	~UGFileStdio();

public:

	//! \brief 		���ı��ļ�
	//! \return 	UGbool
	//! \param 		filename
	//! \param 		save_or_load
	//! \param 		size=8192
	//! \remarks 		
	UGbool Open(const UGchar* filename,UGStreamDirection save_or_load,UGuint size=8192);

	//! \brief �Ƿ����ļ�δ
	UGbool IsEOF() const;
	//! \brief ���ò���ϵͳ���з�
	void SetCurEnterType(EnterType eEnterType);
	//! \brief �õ��ļ���ǰ��λ��
	UGulong GetPosition() const;
	//! \brief �����ļ���λ��
	UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);
	//! \brief �õ��ļ��ĳ���
	UGlong GetLength();

	//! \brief  ���ļ��ж�ȡһ���ı�
	//! \remarks ��ȡһ������ʱ���Զ�ȥ����δ�Ļ��з��������Զ�ʶ����δ�Ļ��з����û�ֻ�ܷ��Ķ�
	int ReadLine(UGString& strSource);
	//! \brief дһ���ı����ļ�
	//! \remarks д��һ������ʱ���Զ������δ�Ļ��з�
	UGbool WriteLine(const UGString& strSource);

	// added by zengzm 2005.12.9 ����flush��������û��д���ļ�������д��
	//! \brief �����ݼ�ʱд�뵽�ļ���
	UGbool Flush();

	//! \brief �ر��ļ�
	UGbool Close();

private:
	UGFileStream m_FileStream;  //�ļ�������
	EnterType m_eEnterType;		//�س�������,����ϵͳ����һ��

	static const UGString m_strEnterAdapt;	 //�س����ַ������ݵ�ǰ�Ĳ���ϵͳ
	static const UGString m_strEnterWindows; //�س����ַ���Windows�ϻس���
	static const UGString m_strEnterUnix;	 //�س����ַ���Unix�ϻس���

};


} //namespace UGC
#endif // !defined(AFX_UGFILESTDIO_H__93B98C9C_498A_43C5_8D3D_F4D4D3FD5FC5__INCLUDED_)
