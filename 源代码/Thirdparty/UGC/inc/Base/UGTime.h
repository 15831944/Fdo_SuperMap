/*! \file	 UGTime.h
 *  \brief	 ʱ����
 *  \author	 zengzm
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGTime.h,v 1.8 2007/07/26 08:09:30 zengzm Exp $
	\remarks ����˵�����ο�MFC�е�COleDateTime����ʵ�֣��Լ���SFC��������ʱ��Ĵ���
	�����Դ���� 1 January 100 �� 31 December 9999 ������ʱ��
 */

#ifndef UGTIME_H
#define UGTIME_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! ʱ������
class BASE_API UGTimeSpan 
{
public:
	// Constructors
	//! \brief Ĭ�Ϲ��캯��,ʱ����Ϊ0
	UGTimeSpan();
	//! \brief ָ��ʱ�������й���
	UGTimeSpan(UGint nDays, UGint nHours, UGint nMins, UGint nSecs);
	//! \brief ָ��doubleʱ����й���,�Ƚϸ���,һ�㲻Ҫʹ��
	UGTimeSpan(double dTime);
	
	//! \brief �������캯��
	UGTimeSpan(const UGTimeSpan& timeSpanSrc);
	//! \brief ������ֵ����
	const UGTimeSpan& operator=(const UGTimeSpan& timeSpanSrc);
	
	// Attributes
	//! \brief �õ���
	UGint GetDays() const;
	//! \brief �õ�Сʱ,��ת��Ϊ24Сʱ
	UGint GetTotalHours() const;
	//! \brief �õ�Сʱ,�ղ���������
	UGint GetHours() const;
	//! \brief �õ�����,�պ�ʱ��ת��Ϊ��
	UGint GetTotalMinutes() const;
	//! \brief �õ�����,�պ�ʱ����������
	UGint GetMinutes() const;
	//! \brief �õ���,��ʱ�ֶ�ת��Ϊ��
	UGint GetTotalSeconds() const;
	//! \brief �õ���,��ʱ�ֲ���������
	UGint GetSeconds() const;
	
	// Operations
	// time math
	UGTimeSpan operator-(UGTimeSpan timeSpan) const;
	UGTimeSpan operator+(UGTimeSpan timeSpan) const;
	const UGTimeSpan& operator+=(UGTimeSpan timeSpan);
	const UGTimeSpan& operator-=(UGTimeSpan timeSpan);
	UGbool operator==(UGTimeSpan timeSpan) const;
	UGbool operator!=(UGTimeSpan timeSpan) const;
	UGbool operator<(UGTimeSpan timeSpan) const;
	UGbool operator>(UGTimeSpan timeSpan) const;
	UGbool operator<=(UGTimeSpan timeSpan) const;
	UGbool operator>=(UGTimeSpan timeSpan) const;
	
	// û����ʹ��,��ʱ������
	//UGString Format(LPCTSTR pFormat) const;
	
private:
	double m_timeSpan; // ���������м����
	friend class UGTime;
};

//! \brief ʱ����, ����COleDateTimeʵ��
//! \remarks implemented as a floating-point value, measuring days from midnight, 
//! 30 December 1899. So, midnight, 31 December 1899 is represented by 1.0. 
//! Similarly, 6 AM, 1 January 1900 is represented by 2.25, 
//! and midnight, 29 December 1899 is �C 1.0. 
//! However, 6 AM, 29 December 1899 is �C 1.25.
//! Now, UGTime can handle dates from 1 January 100 �C 31 December 9999
class BASE_API UGTime  
{
public:
	static UGTime GetCurrentTime();

	//! \brief �õ��Ժ���Ϊ������ʱ��; ������ȷ�������ܵ�; 
	static UGint GetMillisecond();
	
	//! \brief Ĭ�Ϲ��캯��
	UGTime();

	//! \brief �������캯��
	UGTime(const UGTime& timeSrc);

	//! \brief ͨ��time_t���й���
	UGTime(time_t t);

	//! \brief ֱ��ͨ��UGTime�ڲ���double��ֵ���й���
	UGTime(double tValue);
	
	//! \brief �����չ��캯��
	UGTime(UGint nYear,UGint nMonth,UGint nDay);
	
	//! \brief ������ʱ���빹�캯��
	UGTime(UGint nYear, UGint nMonth, UGint nDay, UGint nHour, UGint nMin, UGint nSec);

	const UGTime& operator=(const UGTime& timeSrc);
	const UGTime& operator=(time_t t);

//	struct tm* GetGmtTm(struct tm* ptm = NULL) const;
//	struct tm* GetLocalTm(struct tm* ptm = NULL) const;

	//! \brief �õ�UGTime�ڲ�������
	double GetTime() const;

	//! \brief �õ���(��Ԫ)��
	UGint GetYear() const;	
	//! \brief �õ���(��1-12)
	//! \remarks month of year (1 = Jan)
	UGint GetMonth() const;       // 
	//! \brief �õ���(ÿ���µ���,��1-31)
	//! \remarks day of month
	UGint GetDay() const;         // 
	//! \brief �õ�Сʱ(��0-23)
	UGint GetHour() const;
	//! \brief �õ�����(��0-59)
	UGint GetMinute() const;
	//! \brief �õ���(��0-59)
	UGint GetSecond() const;
	//! \brief �õ���(ÿ���ڵ���,����Ϊ1)
	//! \remarks 1=Sun, 2=Mon, ..., 7=Sat
	UGint GetDayOfWeek() const;   // 
	//! \brief �õ���(ÿ���ڵ���, 1��1��Ϊ1)
	UGint GetDayOfYear() const;   // 
	
	UGTimeSpan operator-(UGTime time) const;
	UGTime operator-(UGTimeSpan timeSpan) const;
	UGTime operator+(UGTimeSpan timeSpan) const;
	const UGTime& operator+=(UGTimeSpan timeSpan);
	const UGTime& operator-=(UGTimeSpan timeSpan);

	UGbool operator==(UGTime time) const;
	UGbool operator!=(UGTime time) const;
	UGbool operator< (UGTime time) const;
	UGbool operator> (UGTime time) const;
	UGbool operator<=(UGTime time) const;
	UGbool operator>=(UGTime time) const;

	//! \brief ����һ����ʽ���ַ���,��UGTime����Ϣ����һ�������Ķ����ַ���
	//! \remarks �ɲο�MSDN�й���strftime��˵��. ���õĸ�ʽ���ַ�����:
	//! %d Day of month as decimal number (01 �C 31);
	//! %H Hour in 24-hour format (00 �C 23);
	//! %m Month as decimal number (01 �C 12)
	//! %M Minute as decimal number (00 �C 59)
	//! %S Second as decimal number (00 �C 59)
	//! %y Year without century, as decimal number (00 �C 99)
	//! %Y Year with century, as decimal number
	UGString Format(LPCTSTR pFormat) const;
//	UGString FormatGmt(LPCTSTR pFormat) const;

	// deleted by zengzm 2007-4-12 ToString��ǰ����ctimeʵ��, ����UGTime֧�ָ��㷺ʱ��,�Ͳ�����ToString��.
	// ������Format("%Y-%m-%d %X")����
	//! ��ͬ�� ctime(), MSDN�ϵ�˵������, ��:Fri Apr 29 12:25:12 1994
	//! Convert a time value to a string and adjust for local time zone settings.
	// UGString ToString() const;

	//! \brief Parses a string to read a date/time value
	//! \remarks ����: strFormatΪ"%Y-%m-%d %H:%M:%S", strDateTimeΪ"1487-05-29 14:25:59", 
	//! ���õ���UGTimeΪ: 1487��05��29�� 14ʱ25��59��
	//! \attention UGTime��ParseDateTimeԶû��MFC��COleDateTime��ParseDateTimeǿ��, 
	//! COleDateTime��ParseDateTime�е�����Win32 API VarDateFromStr,���ڲ�ʵ�ֿ�����,
	//! ʵ����, UGC��Ҳ������ôǿ��. ���,���ϸ������������е��÷�, ����ע������0ҲҪд��
	UGbool ParseDateTime(UGString strDateTime,UGString strFormat);

private:
	//! \brief ��������ʱ����ת��Ϊ �ڲ���double��ֵ
	void SetDateTime(UGint nYear, UGint nMonth, UGint nDay, UGint nHour, UGint nMin, UGint nSec);
	//! \brief ��double��ֵת��Ϊtm�ṹ
	void GetDateTime(struct tm& tmDest) const;
	//! \brief �õ���׼��tm�ṹ
	void GetStandardTm(struct tm& tmDest) const;

	//! \brief �õ�������doubleֵ
	//! \remarks ��ͬ��MFC�е�_AfxDoubleFromDate
	double GetDoubleValue() const;
	//! \brief �Ӵ�����doubleֵ�еõ�time
	//! \remarks ��ͬ��MFC�е�_AfxDateFromDouble
	void FromDoubleValue(double dbl);

	//time_t m_time;
	double m_time;
};

}

#endif 

