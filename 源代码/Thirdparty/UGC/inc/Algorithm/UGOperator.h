/**  
   \file		UGOperator.h

   \brief		һЩ�������㷨�����磬���ֲ��ҡ�����ȡ�

   \author		guohui

   \attention 

   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>

   All Rights Reserved.

   \version 2.0

      <b>����˵����</b>\n

<em>1����һ��˵����\n

<em>2���ڶ���˵����\n

 */ 

#ifndef UGOPERATOR_H
#define UGOPERATOR_H
#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class UGEXPORT UGOperator  
{
private:
	
	UGOperator();

public:

	//! \brief				���ֲ��ұ� dID С�ĵ�һ����
	//! \param dID			�������
	//! \param arrIDs		���С����б����ǽ������еġ�
	//! \param nCount		���и���
	//! \remarks			��������ڱ� dID С�������򷵻�-1�����򷵻�����(��0��ʼ)
	static UGint FindIndexByDecreaseArray(UGdouble dID, const UGdouble* arrIDs, UGint nCount);

	//! \brief				���ֲ��ұ� dID ��ĵ�һ����
	//! \param dID			�������
	//! \param arrIDs		���С����б������������еġ�
	//! \param nCount		���и���
	//! \remarks			��������ڱ� dID ��������򷵻�-1�����򷵻�����(��0��ʼ)
	static UGint FindIndexByIncreaseArray(UGdouble dID, const UGdouble* arrIDs, UGint nCount);

	//! \brief				Ѱ�������е���󵥵���������
	//! \param arrSrc		���������
	//! \param arrSubIndex	����������(��0��ʼ)
	//! \remarks			��󵥵��������У��ٶ����� A = {a(i)}(n>i>=0)�������������B = {b(j)}��b(j)����A
	//!						��b(j+1)>b(j)>b(j-1).ͬʱ��b(j)��A�е�λ�ô���b(j-1)��A�е�λ�á�������B�����и���
	//!						�ﵽ���B���о�������A����󵥵���������
	static UGbool FindSubIncreaseArray(const UGArray <UGdouble> &arrSrc, UGArray <UGint> &arrSubIndex);

	//! \brief				Ѱ�������е���󵥵��ݼ�����
	//! \param arrSrc		���������
	//! \param arrSubIndex	����������(��0��ʼ)
	//! \remarks			��󵥵��������У��ٶ����� A = {a(i)}(n>i>=0)�������������B = {b(j)}��b(j)����A
	//!						��b(j+1)<b(j)<b(j-1).ͬʱ��b(j)��A�е�λ�ô���b(j-1)��A�е�λ�á�������B�����и���
	//!						�ﵽ���B���о�������A����󵥵��ݼ�����
	static UGbool FindSubDecreaseArray(const UGArray <UGdouble> &arrSrc, UGArray <UGint> &arrSubIndex);

	//! \brief				�������� UGint ������ 
	static void QuickSort(UGint  *l, UGint nStart, UGint nEnd);  

	//! \brief				�������� UGint ������ 
	static void QuickSort(UGdouble *d, UGint nStart, UGint nEnd);
	
	static UGint FindInsertPos(UGint nID, UGint* pIDs, UGint nCount);
	
	static UGint FindIndex(UGint nID, UGint* pIDs, UGint nCount);

private:

	//! \brief				��������double������ʱ��֧��
	static UGdouble Median(UGdouble *d, UGint nStart, UGint nEnd);

	//! \brief				��������double������ʱ��֧��
	static UGint Median(UGint *l, UGint nStart, UGint nEnd);
};

}

#endif


