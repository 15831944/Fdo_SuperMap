/*! \file	 ugeng.h
 *  \brief	 ���������������Ͷ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: ugeng.h,v 1.6 2007/05/16 00:44:56 liwl Exp $
 */

#ifndef UGENG_H
#define UGENG_H

namespace UGC {

enum UGEngAction {
	eaBeginTrans		= 1,
	eaCommitTrans		= 2,
	eaRollbackTrans		= 3,
	eaCheckOut			= 4,
	eaCheckIn			= 5,
	eaUndoCheckOut		= 6,
	eaLock				= 7,
	eaUnlock			= 8,
	eaShowSequence		= 9,
	eaShowMiniature		= 10,
	eaLoginLongTrans	= 11,
	eaLogoutLongTrans	= 12,
	eaUserLock			= 13,
	eaTrans				= 14,
	eaLongTrans			= 15,
	eaBuildPyramid		= 16,
	eaCache				= 17,
	eaReadOnly			= 18,
	eaTIN				= 19,
	eaRename			= 20

};

//! ����֧�ֵ�����
enum UGEngAbility
{
	ebReadOnly			= 1,
	ebLibrary			= 2,
	ebFileCache			= 3,
	ebLongTrans			= 4,
	ebSequence			= 5,
	ebUserLock			= 6
};

enum UGStatisticMode
{
	smMax				= 1,	//! ���ֵ
	smMin				= 2,	//! ��Сֵ
	smAvg				= 3,	//! ƽ��ֵ 
	smSum				= 4,	//! �ܺ�
	smStdev				= 5,	//! ��׼��
	smVar				= 6		//! ����
};

struct UGDataVersionInfo
{
	UGint nVersionID;
	UGString strDataVersionName;
	UGString strDescription;
	UGTime	CreateTime;
};

struct UGCheckConflict
{
	//����ID
	UGint nDataID;
	//C����SmID = nDataID�����г�ͻ�İ汾ID
	UGint nDataVersionID;
	//��ͻ����
	// 0  ������
	// 1  Add
	// 2  Edit
	// 3  Del
	//		C��			D��
	//		Src      Dataversion
	//		Edit  \	/   Edit
	//		Del   / \   Del  
	//	1   Edit	Edit
	//	2   Edit	Del
	//	3	Del		Edit
	//	4	Del		Del
	UGint nConflictType;
};

enum UGPostOption
{
	POConflictCheck			= 1, //�����ͻ
	POConflictPrev			= 2, //������ͻ��ԭʼ�汾Ϊ׼
	POConflictLast			= 3, //������ͻ���ύ�İ汾Ϊ׼
	POConflictUnion			= 4, //������ͻ��Union�ռ����
};

}

#endif
