/* 
	\file UG3DUtility.h
	\brief 3Dʵ���ࡣ
	\author malq zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_)
#define AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC 
{

//! \brief 3Dʵ���ࡣ
class SCENE_API UG3DUtility  
{

public:
	
	//! \brief ���캯����
	UG3DUtility();	
	
	//! \brief ����������
	virtual ~UG3DUtility();
	//! \brief 
	static void ReadIndexFile(const UGString& strIndexFile,UGArray<UGint>& arryID);
	
};

}

#endif // !defined(AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_)
