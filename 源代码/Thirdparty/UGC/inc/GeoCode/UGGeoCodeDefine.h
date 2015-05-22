#ifndef UGGEOCODEDEFINE_H
#define UGGEOCODEDEFINE_H


//{{ ���¶���ΪUSStreet���͵�ַ�ĵ�ַ����
#define SM_GEOCODE_TYPE_0         "0"        //  NULL word (THE, OF)
#define SM_GEOCODE_TYPE_B         "B"	     //  Box  (BOX)
#define SM_GEOCODE_TYPE_Q         "Q"        //  Post  (POST)
#define SM_GEOCODE_TYPE_Y         "Y"		 //  Office  (OFFICE)
#define SM_GEOCODE_TYPE_K         "K"        //  FPO APO GENDEL
#define SM_GEOCODE_TYPE_L         "L"        //  OLD
#define SM_GEOCODE_TYPE_M         "M"        //  Multiunit (APT)
#define SM_GEOCODE_TYPE_E         "E"        //  Building type
#define SM_GEOCODE_TYPE_F         "F"        //  Floor
#define SM_GEOCODE_TYPE_G         "G"        //  Directional modifier (END POINT VIEW) for  EAST END
#define SM_GEOCODE_TYPE_C         "C"        //  Cardinal number (ONE TWO)
#define SM_GEOCODE_TYPE_O         "O"        //  Ordinal number (FIRST SECOND)
#define SM_GEOCODE_TYPE_D         "D"        //  Direction (NORTH)
#define SM_GEOCODE_TYPE_T         "T"        //  Street type (ST AV)
#define SM_GEOCODE_TYPE_R         "R"        //  Rural route (RR)
#define SM_GEOCODE_TYPE_X         "X"        //  Route modifier (US, STATE)
#define SM_GEOCODE_TYPE_S         "S"        //  St
#define SM_GEOCODE_TYPE_N         "N"        //  Number which may be followed by either an ordinal or a cardinal(FIFTY, SIXTY, etc.)
#define SM_GEOCODE_TYPE_Z         "Z"        //  Number suffix (TH, ND)
#define SM_GEOCODE_TYPE_H         "H"        //  Mile
#define SM_GEOCODE_TYPE_J         "J"        //  RURAL, STAR
#define SM_GEOCODE_TYPE_I         "I"        //  Comppany suffix (INC., AGENCY)
#define SM_GEOCODE_TYPE_A         "A"        //  Abbreviations to expand
#define SM_GEOCODE_TYPE_V         "V"        //  State names or abbreviations
#define SM_GEOCODE_TYPE_P         "P"        //  used internally
//}} ���¶���ΪUSStreet���͵�ַ�ĵ�ַ����


//{{ USStreet�ֵ������е�ַԪ�ص�����
#define SM_GEOCODE_USSTREET_HN    "HN"        //  House Number
#define SM_GEOCODE_USSTREET_PD    "PD"        //  Pre-direction
#define SM_GEOCODE_USSTREET_PT    "PT"        //  Pre-type
#define SM_GEOCODE_USSTREET_SN    "SN"        //  Street Name
#define SM_GEOCODE_USSTREET_ST    "ST"        //  Suffix type
#define SM_GEOCODE_USSTREET_SD    "SD"        //  Suffix direction
#define SM_GEOCODE_USSTREET_ZN    "ZN"        //  Zone
//}} USStreet�ֵ������е�ַԪ�ص�����

//{{ USStreet�ֵ������е�ַԪ�صļƷ�M��Uֵ
#define SM_GEOCODE_USSTREET_HN_U    0.050
#define SM_GEOCODE_USSTREET_HN_M    0.999
#define SM_GEOCODE_USSTREET_PD_U	0.100
#define SM_GEOCODE_USSTREET_PD_M    0.800
#define SM_GEOCODE_USSTREET_PT_U    0.100
#define SM_GEOCODE_USSTREET_PT_M    0.700
#define SM_GEOCODE_USSTREET_SN_U    0.010
#define SM_GEOCODE_USSTREET_SN_M    0.900
#define SM_GEOCODE_USSTREET_ST_U    0.100
#define SM_GEOCODE_USSTREET_ST_M    0.850
#define SM_GEOCODE_USSTREET_SD_U    0.100
#define SM_GEOCODE_USSTREET_SD_M    0.850
#define SM_GEOCODE_USSTREET_ZN_U    0.010
#define SM_GEOCODE_USSTREET_ZN_M    0.900
//}} USStreet�ֵ������е�ַԪ�صļƷ�M��Uֵ

//{{ USStreet�ֵ����ͻ�׼��ַ�ֶδ��� ��ƥ���ʱ�� ���������໥��Ӧ��
#define SM_GEOCODE_USSTREET_FROMLEFT			"FROMLEFT"		     
#define SM_GEOCODE_USSTREET_FROMRIGHT			"FROMRIGHT"		     
#define SM_GEOCODE_USSTREET_TOLEFT				"TOLEFT"		     
#define SM_GEOCODE_USSTREET_TORIGHT				"TORIGHT"		     
#define SM_GEOCODE_USSTREET_PREDIR				"PREDIR"		     
#define SM_GEOCODE_USSTREET_PRETYPE				"PRETYPE"		     
#define SM_GEOCODE_USSTREET_STREETNAME			"STREETNAME"		     
#define SM_GEOCODE_USSTREET_STREETTYPE			"STREETTYPE"		     
#define SM_GEOCODE_USSTREET_SUFDIR				"SUFDIR"		     
#define SM_GEOCODE_USSTREET_LEFTZONE			"LEFTZONE"		     
#define SM_GEOCODE_USSTREET_RIGHTZONE			"RIGHTZONE"		     
//}} USStreet�ֵ����ͻ�׼��ַ�ֶδ��� ��ƥ���ʱ�� ���������໥��Ӧ��


// ���ֶ������Ϸ�ʱ ������Ӻ�׺��
#define SM_FIELD_NAME_SUF_MAX	1000

// �����ж�Ӧ��ID�ֶ�
#define SM_INDEX_FIELD_NAME_ID	"XSMID"


// ��ƥ����С��ֵ
#define SM_GEOCODE_UNMATCH_VALUE_MIN	0.000000001

// ƥ�����ֵ
#define SM_GEOCODE_MATCH_VALUE_MAX		0.999999999


// ��ַ��׼������ֶ�����

#define SM_GEOCODE_FIELDNAME_STANDARD		"ADDRESS_STANDARD"
#define SM_GEOCODE_FIELDNAME_SCORE			"GeoCode_SCORE"
#define SM_GEOCODE_FIELDNAME_SIDE			"GeoCode_Side"
#define SM_GEOCODE_FIELDNAME_STATUS			"GeoCode_Status"
#define SM_GEOCODE_FIELDNAME_MATCHID		"GeoCode_MatchSMID"


#define SM_GEOCODE_DEFAULT_MINSCORE		60
#define SM_GEOCODE_DEFAULT_OFFSET		0
#define SM_GEOCODE_DEFAULT_ENDOFFSET	0


//{{���ĵ�ַģ����ѯ��Ҫ�ĺ궨��

//�ʵ�����Ҫ�ĺ궨��

#define UG_GEOCODE_CC_NUM  6768   //���깲��6768��λ�ã�������5����λ��3756-3761
#define UG_GEOCODE_WORD_MAXLENGTH 100
#define UG_GEOCODE_WT_DELIMITER 0
#define UG_GEOCODE_WT_CHINESE   1
#define UG_GEOCODE_WT_OTHER     2
#define UG_GEOCODE_CC_ID(c1,c2) ((UGuchar)(c1)-176)*94+((UGuchar)(c2)-161)
	    //((unsigned UGchar)(c1)-176)*94+((unsigned UGchar)(c2)-161)
//���㺺�ִ��ߵ�λ�ļ���ʽ�� 

#define UG_GEOCODE_CC_CHAR1( id) ( id)/94+176
//���㺺�ָ�λ�ļ���ʽ��

#define UG_GEOCODE_CC_CHAR2( id) ( id)%94+161
//���㺺�ֵ�λ�ļ���ʽ��

#define  UG_GEOCODE_CT_SENTENCE_BEGIN 1//Sentence begin 
#define  UG_GEOCODE_CT_SENTENCE_END   4//Sentence ending
#define  UG_GEOCODE_CT_SINGLE  5//SINGLE byte
#define  UG_GEOCODE_CT_DELIMITER 6//delimiter
#define  UG_GEOCODE_CT_CHINESE   7//Chinese Char
#define  UG_GEOCODE_CT_LETTER    8//HanYu Pinyin
#define  UG_GEOCODE_CT_NUM       9//HanYu Pinyin
#define  UG_GEOCODE_CT_INDEX     10//HanYu Pinyin
#define  UG_GEOCODE_CT_OTHER     17//Other

//�ִ�����Ҫ�ĺ궨��
#define UG_GEOCODE_MAXWORDLENGTH 8  // ���ʳ�Ϊ8���ֽڣ���4�����֣�
#define UG_GEOCODE_SEPARATOR "*"    // �ִʴʽ���
#define UG_GEOCODE_CORPUSSIZE 200000 // �������Ͽ��ģ

//��ͼ���ݼ�������Ҫ�ĺ궨��
#define  UG_GEOCODE_CHNSIZE 6774
//}}���ĵ�ַģ����ѯ��Ҫ�ĺ궨��

#endif
