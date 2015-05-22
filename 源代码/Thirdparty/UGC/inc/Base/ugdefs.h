#ifndef UGDEFS_H
#define UGDEFS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>


#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <functional>

#include "ugres.h"
#include "ugtypedef.h"
#include "ugexports.h"
#include "ugversion.h"
#include "ugkeydef.h"

#ifdef WIN32
	#pragma warning(disable: 4251)
	#pragma warning(disable: 4275)
	#pragma warning(disable: 4786)
#endif

// Truth values
#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#ifndef MAYBE
	#define MAYBE 2
#endif

#ifndef NULL
	#define NULL 0
#endif

// modified by zengzm 2007-4-25 ����Ϊ 2.0.0��
//#define UGS_DLL_VERSION		("100")	//dll�汾��1.0.0
#define UGS_DLL_VERSION		("200")	//dll�汾��2.0.0

//! Pi
#ifndef PI
	#define PI      3.1415926535897932384626433833
#endif

//! Euler constant
#define EULER   2.7182818284590452353602874713

//! Multiplier for degrees to radians
#define DTOR    0.0174532925199432957692369077

//! Multiplier for radians to degrees
#define RTOD    57.295779513082320876798154814

#define UNIT_UNKNOWN	-1   // δ֪�ĵ�λ
#define UNIT_LINEAR		10  // ���ȵ�λ
#define UNIT_ANGULAR    20  // �Ƕȵ�λ  

//{{��������뵥λ���� - ���Է�ʽ
#define AU_MM	10			//mm����
#define AU_CM	100			//����
#define AU_DM	1000		//����
#define AU_M	10000		//��
#define AU_KM	10000000	//����
#define AU_MI	16090000	//Ӣ��
#define AU_IN	254			//Ӣ��(��������ô��)
#define AU_YD	9144		//Yard��
#define AU_FT	3048		//FeetӢ��
#define AU_RD	0			//Radian����(5.0������ǰ�汾ʹ�õĽǶȵ�λ����������͵����Ƕȼ�����degree)
//}}��������뵥λ����

//{{��������뵥λ���� - ��׼��ʽ
#define AU_MILIMETER	10			//mm����
#define AU_CENTIMETER	100			//����
#define AU_DECIMETER	1000		//����
#define AU_METER		10000		//��
#define AU_KILOMETER	10000000	//����
#define AU_MILE			16090000	//Ӣ��
#define AU_INCH			254			//Ӣ��??
#define AU_YARD			9144		//Yard�� 
#define AU_FOOT			3048		//FeetӢ��
#define	AU_YARD_SEARS   9144		//Yard�� 
//#define AU_DEGREE     0           // 5.0������ǰ�汾ʹ�õĽǶȵ�λ

// �Ƕȵ�λ�� (10e8)��֮һ����Ϊ ��λ1Ϊ����ͳ��ȵ�λ������������10e10
// ����ڼ���ʱ��Ӧ��ȥ10e10��Ȼ���ټ���
// ��Щ��λ��Arc/Info PE�ĵ�λ������һ�µ�
/*
 *					name    	id     	   factor
              Degree----       9102 ----- 0.01745329 
                 Gon----       9106 ----- 0.01570796 
                Grad----       9105 ----- 0.01570796 
         Microradian----       9109 ----- 0.00000100 
            Mil_6400----       9114 ----- 0.00098175 
              Minute----       9103 ----- 0.00029089 
   Minute_Centesimal----       9112 ----- 0.00015708 
              Radian----       9101 ----- 1.00000000 
              Second----       9104 ----- 0.00000485 
   Second_Centesimal----       9113 ----- 0.00000157 
 */
#define AU_DIFF              1000000000
#define AU_RADIAN            100000000 + 1000000000/* Radian                                 */
#define AU_DEGREE			 1745329   + 1000000000/* Degree                                 */
#define AU_MINUTE            29089     + 1000000000/* Arc-minute                             */
#define AU_SECOND            485       + 1000000000/* Arc-second                             */
#define AU_GRAD              1570796   + 1000000000/* Grad (angle subtended by 1/400 circle) */
//#define AU_GON               1570796   + 1000000000/* Gon  (angle subtended by 1/400 circle) */
#define AU_MICRORADIAN       100       + 1000000000/* Microradian ( 1e-6 radian )            */
#define AU_MINUTE_CENTESIMAL 15708     + 1000000000/* Centesimal minute (1/100th Gon (Grad)) */
#define AU_SECOND_CENTESIMAL 157       + 1000000000/* Centesimal second(1/10000th Gon (Grad))*/
#define AU_MIL_6400          98175     + 1000000000/* Mil (angle subtended by 1/6400 circle) */


//	UNIT_METER            = 9001, /* International meter                    */
//
//	UNIT_DECIMETER		  =  9002, //"Decimeter"		//dm����
//	UNIT_CENTIMETER		  =  9003, //"Centimeter"	//cm����
//	UNIT_MILLIMETER		  =  9004, //"Milimeter"		//mm����
//	UNIT_KILOMETER		  =  9005, //"Kilometer"		//km����
//	UNIT_MILE			  =  9006, //"Mile"			//miӢ��
//	UNIT_YARD			  =  9007, //"Yard"			//Yard��
//	UNIT_FOOT			  =  9008, //"Foot"			//FeetӢ��
//	UNIT_INCH			  =  9009, //"Inch"			//InӢ��
//	UNIT_FOOT_US          = 9010, /* US survey foot                         */
//	UNIT_FOOT_CLARKE      = 9011, /* Clarke's foot                          */
//	UNIT_FATHOM           = 9014, /* Fathom                                 */
//	UNIT_NAUTICAL_MILE    = 9030, /* International nautical mile            */
//	UNIT_METER_GERMAN     = 9031, /* German legal meter                     */
//	UNIT_CHAIN_US         = 9033, /* US survey chain                        */
//	UNIT_LINK_US          = 9034, /* US survey link                         */
//	UNIT_MILE_US          = 9035, /* US survey mile                         */
//	UNIT_YARD_CLARKE      = 9037, /* Yard (Clarke)                          */
//	UNIT_CHAIN_CLARKE     = 9038, /* Chain (Clarke)                         */
//	UNIT_LINK_CLARKE      = 9039, /* Link (Clarke's ratio) (was PE_U_LINK 9007) */
//	UNIT_YARD_SEARS       = 9040, /* Yard (Sears)          (was 9012)       */
//	UNIT_FOOT_SEARS       = 9041, /* Sears' foot           (was 9032)       */
//	UNIT_CHAIN_SEARS      = 9042, /* Chain (Sears)         (was 9011)       */
//	UNIT_LINK_SEARS       = 9043, /* Link (Sears)          (was 9009)       */
//	UNIT_YARD_BENOIT_A    = 9050, /* Yard (Benoit 1895 A)                   */
//	UNIT_FOOT_BENOIT_A    = 9051, /* Foot (Benoit 1895 A)                   */
//	UNIT_CHAIN_BENOIT_A   = 9052, /* Chain (Benoit 1895 A)                  */
//	UNIT_LINK_BENOIT_A    = 9053, /* Link (Benoit 1895 A)                   */
//	UNIT_YARD_BENOIT_B    = 9060, /* Yard (Benoit 1895 B)                   */
//	UNIT_FOOT_BENOIT_B    = 9061, /* Foot (Benoit 1895 B)                   */
//	UNIT_CHAIN_BENOIT_B   = 9062, /* Chain (Benoit 1895 B) (was PE_U_CHAIN_BENOIT 9010)*/
//	UNIT_LINK_BENOIT_B    = 9063, /* Link (Benoit 1895 B) (was PE_U_LINK_BENOIT 9008)*/
//	UNIT_FOOT_1865        = 9070, /* Foot (1865)                            */
//	UNIT_FOOT_INDIAN      = 9080, /* Indian geodetic foot  (was 9006)       */
//	UNIT_FOOT_INDIAN_1937 = 9081, /* Indian foot (1937)                     */
//	UNIT_FOOT_INDIAN_1962 = 9082, /* Indian foot (1962)                     */
//	UNIT_FOOT_INDIAN_1975 = 9083, /* Indian foot (1975)                     */
//	UNIT_YARD_INDIAN      = 9084, /* Indian yard           (was 9013)       */
//	UNIT_YARD_INDIAN_1937 = 9085, /* Indian yard (1937)                     */
//	UNIT_YARD_INDIAN_1962 = 9086, /* Indian yard (1962)                     */
//	UNIT_YARD_INDIAN_1975 = 9087, /* Indian yard (1975)                     */
//
//	UNIT_RADIAN           = 9101, /* Radian                                 */
//	UNIT_DEGREE           = 9102, /* Degree                                 */
//	UNIT_MINUTE           = 9103, /* Arc-minute                             */
//	UNIT_SECOND           = 9104, /* Arc-second                             */
//	UNIT_GRAD             = 9105, /* Grad (angle subtended by 1/400 circle) */
//	UNIT_GON              = 9106, /* Gon  (angle subtended by 1/400 circle) */
//	UNIT_MICRORADIAN      = 9109, /* Microradian ( 1e-6 radian )            */
//	UNIT_MINUTE_CENTESIMAL= 9112, /* Centesimal minute (1/100th Gon (Grad)) */
//	UNIT_SECOND_CENTESIMAL= 9113, /* Centesimal second(1/10000th Gon (Grad))*/
//	UNIT_MIL_6400         = 9114 /* Mil (angle subtended by 1/6400 circle) */

//}}��������뵥λ����

//{{��������뵥λ���� - ���Է�ʽ - MIF�ַ���
#define AUS_MM	("mm")	//mm����
#define AUS_CM	("cm")	//����
#define AUS_DM	("dm")	//����
#define AUS_M	("m")		//��
#define AUS_KM	("km")	//����
#define AUS_MI	("mi")	//Ӣ��
#define AUS_IN	("in")	//Ӣ��
#define AUS_YD	("yd")	//Yard��
#define AUS_FT	("ft")	//FeetӢ��
#define AUS_RD  ("dg")    //Radian����

// �Ƕ����Ƶ��ַ����ǰ��� Arc/info PEȡ�� 
#define AUS_RDN  ("Radian")   
#define AUS_DG	 ("Degree")	
#define AUS_MN	 ("Minute")
#define AUS_SC   ("Second")
#define AUS_GR   ("Grad")          
//#define AUS_GN   ("Gon")           
#define AUS_MR	 ("Microradian")
#define AUS_MC   ("Minute_Centesimal")
#define AUS_SCT   ("Second_Centesimal")
#define AUS_ML6000  ("Mil_6400")		      

//}}��������뵥λ����

//{{��������뵥λ���� - ��׼��ʽ - MIF�ַ���
#define AUS_MILIMETER	("mm")	//mm����
#define AUS_CENTIMETER	("cm")	//����
#define AUS_DECIMETER	("dm")	//����
#define AUS_METER		("m")		//��
#define AUS_KILOMETER	("km")	//����
#define AUS_MILE		("mi")	//Ӣ��
#define AUS_INCH		("in")	//Ӣ��??
#define AUS_YARD		("yd")	//Yard��
#define AUS_FOOT		("ft")	//FeetӢ��
#define AUS_DEGREE		("dg")	//Degree��


#define AUS_RADIAN          ("Radian") 
#define AUS_DEGREE_NEW      ("Degree")      
#define AUS_MINUTE			("Minute") 	    
#define AUS_SECOND			("Second")    
#define AUS_GRAD			("Grad")      
//#define AUS_GON			("Gon")               
#define AUS_MICRORADIAN		        ("Microradian")    
#define AUS_MINUTE_CENTESIMAL		("Minute_Centesimal")
#define AUS_SECOND_CENTESIMAL		("Second_Centesimal")
#define AUS_MIL_6400				("Mil_6400")		      

//}}��������뵥λ����
//{{/* Device Parameters for GetDeviceCaps() */
// modified by zengzm 2007-3-24 ����ƽ̨��һ����,�Ͳ�������WIN32��ֱ�д��
#define UG_HORZSIZE      4		/* Horizontal size in millimeters           */
#define UG_VERTSIZE      6     /* Vertical size in millimeters             */
#define UG_HORZRES       8     /* Horizontal width in pixels               */
#define UG_VERTRES       10    /* Vertical height in pixels                */
//#ifdef WIN32
//	#define UG_HORZSIZE      4/*HORZSIZE Horizontal size in millimeters           */
//	#define UG_VERTSIZE      6/*VERTSIZE Vertical size in millimeters             */
//	#define UG_HORZRES       8/*HORZRES  Horizontal width in pixels               */    
//	#define UG_VERTRES       10/*VERTRES  Vertical height in pixels                */ 
//#else
//	#define UG_HORZSIZE      4		/* Horizontal size in millimeters           */
//	#define UG_VERTSIZE      6     /* Vertical size in millimeters             */
//	#define UG_HORZRES       8     /* Horizontal width in pixels               */
//	#define UG_VERTRES       10    /* Vertical height in pixels                */
//#endif
//}}/* Device Parameters for GetDeviceCaps() */

#define UG_CXFULLSCREEN         16
#define UG_CYFULLSCREEN         17

#define AM_FIELD_NAME_HEADER_UPPER	("SM")
#define AM_FIELD_NAME_HEADER		("sm")

// ��Сֵ����
#define EP 1e-10
#define NEP -1e-10
//����������͵ļ�ֵ caogf
#define UG_DBLMAX 1.7976931348623158e+308 /* max value */
#define UG_DBLMIN 2.2250738585072014e-308 /* min positive value */
#define UG_FLTMAX 3.402823466e+38F  /* max value */
#define UG_FLTMIN 1.175494351e-38F  /* min positive value */


//! ͨ�õ�NoValue
#ifndef NOVALUE
	#define NOVALUE -9999
#endif

// Win32��RAND_MAXҲ��0x7fff,Ӧ�˾ͱ�ֿ�д��.
#define UG_RAND_MAX RAND_MAX
//#ifdef WIN32
//	#define UG_RAND_MAX 0x7fff
//#else
//	#define UG_RAND_MAX RAND_MAX
//#endif

#define LENGTH_MAX_PATH 2048
#define LENGTH_MAX_DRIVE 5
#define LENGTH_MAX_DIR   1024
#define LENGTH_MAX_TITLE 1024
#define LENGTH_MAX_EXT   8

// �������
#define  INFINITEBIG UGC::uginfinitebig()
//! \brief �ж��ֽ���
#define  UGC_ISBIGENDIAN (UGC::ugisbigendian())

// 2007-3-26 by zengzm �ŵ�ugwin32��ugnowin��
// Path separator
//#ifdef WIN32
//#define PATHSEP '\\'
//#define PATHSEPSTRING "\\"
//#define PATHLISTSEP ';'
//#define PATHLISTSEPSTRING ";"
//#define ISPATHSEP(c) ((c)=='/' || (c)=='\\')
//#else
//#define PATHSEP '/'
//#define PATHSEPSTRING "/"
//#define PATHLISTSEP ':'
//#define PATHLISTSEPSTRING ":"
//#define ISPATHSEP(c) ((c)=='/')
//#endif

// 2007-3-26 by zengzm �ŵ�ugwin32��ugnowin��
// End Of Line
//#ifdef WIN32
//#define EOLSTRING "\r\n"
//#else
//#define EOLSTRING "\n"
//#endif


// For Windows
#ifdef _DEBUG
	#ifndef DEBUG
	#define DEBUG
#endif
#endif

#ifdef _NDEBUG
	#ifndef NDEBUG
	#define NDEBUG
#endif
#endif

// added by zengzm 2005.7.27
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : "

// Checking printf and scanf format strings
#if defined(_CC_GNU_) || defined(__GNUG__) || defined(__GNUC__)
	#define UG_PRINTF(fmt,arg) __attribute__((format(printf,fmt,arg)))
	#define UG_SCANF(fmt,arg)  __attribute__((format(scanf,fmt,arg)))
#else
	#define UG_PRINTF(fmt,arg)
	#define UG_SCANF(fmt,arg)
#endif

namespace UGC {

// Streamable types; these are fixed size!
typedef char                   UGchar;
typedef unsigned char          UGuchar;
typedef UGuchar				   UGbyte;
typedef UGuchar				   UGbool;
typedef unsigned short         UGushort;
typedef short                  UGshort;
typedef unsigned int           UGuint;
typedef wchar_t				   UGwchar;
typedef int                    UGint;
typedef float                  UGfloat;
typedef double                 UGdouble;

#if defined(_MSC_VER) || (defined(__BCPLUSPLUS__) && __BORLANDC__ > 0x500) || defined(__WATCOM_INT64__)
	#define UG_LONG
	typedef unsigned __int64       UGulong;
	typedef __int64                UGlong;	
	#define UG_ULONG_MAX		   _UI64_MAX
	#define UG_LONG_MIN			   _I64_MIN	
	#define UG_LONG_MAX			   _I64_MAX
#elif defined(__GNUG__) || defined(__GNUC__) || defined(__SUNPRO_CC) || defined(__MWERKS__) || defined(__SC__)
	#define UG_LONG
	typedef unsigned long long int UGulong;
	typedef long long int          UGlong;
	#define UG_ULONG_MAX		   18446744073709551615ULL	
	#define UG_LONG_MAX			   9223372036854775807LL
	#define UG_LONG_MIN			   (-UG_LONG_MAX - 1LL)	
#endif

// Integral types large enough to hold value of a pointer
#if defined(_MSC_VER) && defined(_WIN64)
	typedef __int64                UGival;
	typedef unsigned __int64       UGuval;
#else
	typedef long                   UGival;
	typedef unsigned long          UGuval;
#endif

// added by zengzm 2007-1-8 ����һ����ֵ����,
//	ר�������洢ָ������,�Խ��32λ��64λ��ָ�����ͳ��Ȳ�һ��������
typedef UGuval UGptr;


typedef UGuint                 UGColor;
typedef UGuint				   UGPixel;

//! Abolute value
#define UGABS(val) (((val)>=0)?(val):-(val))

//! Return the maximum of a or b
#define UGMAX(a,b) (((a)>(b))?(a):(b))

//! Return the minimum of a or b
#define UGMIN(a,b) (((a)>(b))?(b):(a))

//! Return the minimum of x, y and z
#define UGMIN3(x,y,z) ((x)<(y)?UGMIN(x,z):UGMIN(y,z))

//! Return the maximum of x, y and z
#define UGMAX3(x,y,z) ((x)>(y)?UGMAX(x,z):UGMAX(y,z))

//! Swap a pair of numbers
#define UGSWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

//! Clamp value x to range [lo..hi]
#define UGCLAMP(lo,x,hi) ((x)<(lo)?(lo):((x)>(hi)?(hi):(x)))

#define UGROUND(x) ((x>0)?UGint(x+0.5):(UGint(x-0.5)))

#define UGCEIL(x) ((UGint)ceil(x))

#define UGFLOOR(x) ((UGint)floor(x))

#define UGLOWORD(l)           ((UGushort)(l))
#define UGHIWORD(l)           ((UGushort)(((UGuint)(l) >> 16) & 0xFFFF))

#ifndef ROUNDLONG
	#define ROUNDLONG(x) ((x>0)?UGint(x+0.5):(UGint(x-0.5)))	//���������
#endif

// �������Ƿ���ȵ��ж�
#define UGEQUAL(x,y) UGC::ugequal(x,y)
#define UGEQ(x,y,d) UGC::ugequal(x,y,d)

// һ�����Ƿ�Ϊ0 (����0�����ļ�С��) ���ж�
// ��Ҫ��ʾ: �������Ƿ���ȵıȽ� ����ʹ�� UGIS0(a-b) , ��Ӧ��ֱ��ʹ��UGEQUAL(a,b)
#define  UGIS0(x)	(((x)<EP) && ((x)>NEP))

//! ��UGC��ȫ���ֹʹ��_T���˵��
//! ��MFC��,CString�ڶ���MBCS��ʱ,�ڲ�ʹ�õ���char*,�ڶ���UNICODE��ʱ,�ڲ�ʹ�õ���wchar*;
//! ���,�ڸ�CString��ֵʱ,�ַ���ǰ�����_T,�Ա���������MBCS��UNICODE���ֲ�ͬ�ı��뷽ʽ�����¶�����.
//! SFC�ǻ���MFC������,���Ҳ�̳�������ʹ��ϰ��, ����UGC�ܶ�����SFC��ֲ����, �ܶ�ط�Ҳ��ʹ��_T��.
//! ����, ����������UGC���ǲ���Ҫ,�������������. ԭ������: 1)UGString�ڲ��޶���char*,ʹ��_T����������,
//! ��ʵ��,���ھ���#define _T(str) str; 2)ϵͳ�ĺܶ�ط���������_T��,UGC�ڲ����ظ�����,�ᵼ�±��뾯��ͻ���;
//! 3)��WinCE��ϵͳ��,������ϵͳ�ڵ��ַ����̶�ΪUnicode,��#define _T(str) L(str), UGC���ٶ����ʹ��_T,
//! Ҫô����UGC�ڵ��ַ�������(ǰ����˲�Ӧ���е�L),Ҫô����ϵͳ���ַ�������(_T��ȡ����)
//! ���, ��õ�������:1)��UGC��,������_T��; 2)UGC�е��ַ���ǰ�����_T; 3)��UGStringW��ֵʱ,���L(UGStringW����wstringʵ��)
//! ����, ����ȡ��UGC�е�_T��(��ʹ�ûᵼ�±������), ����UGC������_Tɾ��; ����,���ٱ�д����ֲ�����ʱ��ע��ɾ��_T
//#ifndef _T
//	#define _T(str) str
//#endif
//#ifdef _T
//	#undef _T
//#endif

#ifndef NDEBUG
	#define UGASSERT(exp) ((exp)?((void)0):(void)UGC::ugassert(#exp,__FILE__,__LINE__))
#else
	#define UGASSERT(exp) ((void)0)
#endif

#ifndef NDEBUG
	#define UGTRACE(arguments) UGC::ugtrace arguments
#else
	#define UGTRACE(arguments) ((void)0)
#endif

#define UGMALLOC(ptr,type,no)     (UGC::ugmalloc((void **)(ptr),sizeof(type)*(no)))

#define UGCALLOC(ptr,type,no)     (UGC::ugcalloc((void **)(ptr),sizeof(type)*(no)))

#define UGRESIZE(ptr,type,no)     (UGC::ugresize((void **)(ptr),sizeof(type)*(no)))

#define UGMEMDUP(ptr,src,type,no) (UGC::ugmemdup((void **)(ptr),(const void*)(src),sizeof(type)*(no)))

#define UGFREE(ptr)               (UGC::ugfree((void **)(ptr)))

#define UGDPI	(UGC::ugdpi())

extern BASE_API void ugassert(const char* expression,const char* filename,unsigned int lineno);

extern BASE_API void ugtrace(const char* format,...) UG_PRINTF(1,2);

extern BASE_API UGint ugmalloc(void** ptr,unsigned long size);

extern BASE_API UGint ugcalloc(void** ptr,unsigned long size);

extern BASE_API UGint ugresize(void** ptr,unsigned long size);

extern BASE_API UGint ugmemdup(void** ptr,const void* src,unsigned long size);

extern BASE_API void ugfree(void** ptr);

//dpi(ÿӢ�����ظ���)
extern BASE_API UGint ugdpi();

extern BASE_API UGbool ugequal(UGdouble x, UGdouble y);

extern BASE_API UGbool ugequal(UGdouble x, UGdouble y, UGdouble dTolerance);

extern BASE_API UGdouble uginfinitebig();

extern BASE_API UGbool ugisbigendian();
//! Make RGBA color
extern BASE_API UGColor UGRGBA(UGuchar r,UGuchar g,UGuchar b,UGuchar a) ;

extern BASE_API UGColor UGRGB(UGuchar r,UGuchar g,UGuchar b);

extern BASE_API UGuchar UGREDVAL(UGColor rgba);

extern BASE_API UGuchar UGGREENVAL(UGColor rgba);

extern BASE_API UGuchar UGBLUEVAL(UGColor rgba);

extern BASE_API UGuchar UGALPHAVAL(UGColor rgba);

extern BASE_API UGbool UGISSAMERGB(UGColor color1, UGColor color2);

//! \brief windows�ϵ�color���洢��׼��ת���ɵ�ǰƽ̨��color���漰����ȡColor�ĵط�����Ҫ������ת��
extern BASE_API UGColor UGWinColortoCurrentColor(UGColor rgba);

//! \brief ��ǰƽ̨��colorת����windows�ϵ�color(�洢��׼)���漰���洢Color�ĵط�����Ҫ������ת��
extern BASE_API UGColor UGCurrentColortoWinColor(UGColor rgba);

//API PACKAGE
#define PACKAGE_UGC 0
#define PACKAGE_UGE 1 
}

#endif //#ifndef UGDEFS_H



