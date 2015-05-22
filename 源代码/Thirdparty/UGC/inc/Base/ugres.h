#ifndef UGRES_H
#define UGRES_H



// ������Ϣ: �� 10000 ��ʼ���
#define	UGS_COMPANY                             10000	/*! ������ͼ������Ϣ�������޹�˾*/
#define	UGS_UGC_VERSION                         10001	/*! SuperMap UGC 2.0*/
#define	UGS_CLASSLIB_NAME                       10002	/*! SuperMap ��ƽ̨������� (UGC)*/
#define	UGS_COPYRIGHT                           10003	/*! ��Ȩ����(C) 2005-2007 ������ͼ������Ϣ�������޹�˾����������Ȩ��\n"*/
#define	UGS_CURRENT_TIME                        10004	/*! %Y��%m��%d��  %Hʱ%M��%S��*/
#define	UGS_NEED_HIGHER_VERSION                 10005	/*! ��Ҫ���ߵİ汾*/
#define	UGS_ERROR_CODE                          10006	/*! SuperMap UGC���������: %d��*/
#define	UGS_WORK_ENVIRONMENT_INFO               10007	/*! �û�: %s �����: %s ʱ��: %s ����ϵͳ: %s Ӳ������: %s ���Ի���: %s ���������ڴ�: %dkb ����ҳ���ļ��������ڴ�: %dkb */
#define	UGS_SM_REGISTER_RUNTIME_PLEASE          10008	/*! ���棺�������а汾û��ע�� ����� %sע�����а�*/


// һ���Դ�������Ϣ����11000��ʼ����
#define	UGS_INVALID_DT                          11000	/*! �Ƿ����ݼ�*/
#define	UGS_PARAMETERS_HAVE_NULL_POINTER        11001	/*! �������Ĳ������п�ָ��*/
#define	UGS_DATASOURCE_POINTER_NULL             11002	/*! ����Դָ��Ϊ��*/
#define	UGS_DATASET_POINTER_NULL                11003	/*! ���ݼ�ָ��Ϊ��*/
#define	UGS_INVALID_STARTNODE_EQUAL_ENDNODE_ANALYSE_FAILED 11004	/*! ��ʼ������ֹ����ͬһ���㣬����ID(%d)�Ƿ�������ʧ��*/
#define	UGS_INVALID_NUMBER                      11005	/*! �Ƿ�����������*/
#define	UGS_FILE_POINTER_NULL                   11006	/*! �ļ�ָ��Ϊ�գ�*/
#define	UGS_GRAVENESS_DATA_ERROR                11007	/*! �������ݴ���*/
#define	UGS_LINE_DATASET_POINTER_IS_NULL        11008	/*! �����ݼ�ָ��Ϊ��*/
#define	UGS_REGION_DATASET_POINTER_IS_NULL      11009	/*! �����ݼ�ָ��Ϊ��*/
#define	UGS_CURRENT_DS_NOT_EXIST                11010	/*! ��ǰ����Դ������*/
#define	UGS_LAYER_POINTER_NULL                  11011	/*! ����Ϣָ��Ϊ��*/
#define	UGS_SYMBOL_INVALID_SYM                  11012	/*! �Ƿ�����*/
#define	UGS_SYMBOL_INVALID_STROKE               11013	/*! �Ƿ����űʻ�*/
#define	UGS_SYMBOL_INVALID_RECT                 11014	/*! �Ƿ�����*/
#define	UGS_SYMBOL_INVALID_TEXT                 11015	/*! �Ƿ��ִ�*/
#define	UGS_SCALE_TYPE_INVALID                  11016	/*! ���������ͷǷ�*/
#define	UGS_INVALID_SMOOTH_DEGREE               11017	/*! �Ƿ��Ĺ⻬�Ȳ������⻬��ֵֻ����0��5֮�������*/
#define	UGS_INVALID_EXPRESSION                  11018	/*! �Ƿ��ı��ʽ*/
#define	UGS_SLMSG_THEME_UNIQUE_KEYTYPE_INVALID  11019	/*! �Ƿ��ĵ�ֵר��ͼ��ֵ*/
#define	UGS_SLMSG_THEME_RANGE_KEYTYPE_INVALID   11020	/*! �Ƿ��ķ�Χ�ֶ�ר��ͼ��ֵ*/
#define	UGS_NULL_POINTER                        11021	/*! ָ��Ϊ��*/
#define	UGS_INVALID_VALUE                       11022	/*! �Ƿ�ֵ*/
#define	UGS_MEMMORY_NOT_ENOUGH                  11023	/*! �ڴ治�㣬��رճ����ͷ��ڴ������*/
#define	UGS_MEMMORY_ALLOC_FAILED                11024	/*! �ڴ����ʧ��*/
#define	UGS_BUILDING_SPATIAL_INDEX              11025	/*! ���ڽ�������......*/
#define	UGS_PREPARING                           11026	/*! ����׼��...*/


// �����Ϣ����13000��ʼ����
#define	UGS_BIT_SYMBOL_DATA_IS_NULL             13000	/*! λͼ���ŵ�����Ϊ��*/
#define	UGS_READ_BIT_INFO_ERROR                 13001	/*! ��ȡλͼ��Ϣ����ȷ*/
#define	UGS_READ_BIT_DATA_POINTER_IS_NULL       13002	/*! ��ȡλͼ����ָ��Ϊ��*/
#define	UGS_READ_BIT_DIB_DATA_FAILED            13003	/*! ��ȡλͼDIB����ʧ��*/
#define	UGS_BIT_IS_NULL_WHEN_SAVE               13004	/*! ����ʱ��λͼ����Ϊ��*/
#define	UGS_BIT_IS_NULL_WHEN_GET_BIT_BYTE_COUNT 13005	/*! ��ȡ����λͼ�ֽ���ʱλͼ����Ϊ��*/
#define	UGS_BIT_IS_NULL_WHEN_IMPORT_BIT         13006	/*! ����λͼ����ʱλͼ����Ϊ��*/
#define	UGS_BITMAP_BIT_IS_NULL                  13007	/*! λͼ��������Ϊ��*/
#define	UGS_STREAMINFO_IS_NULL_WHEN_READ_BIT    13008	/*! ��ȡλͼ����ʱ����ϢΪ��*/
#define	UGS_CANNOT_FIND_THE_VERSION_WHEN_READ_BIT 13009	/*! ��ȡλͼ����ʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_NOT_SUPPORT_LOW_VERSION_WHEN_SAVE_BIT 13010	/*! ����λͼ����ʱ��֧�������Ͱ汾*/
#define	UGS_BIT_IS_NULL_WHEN_DRAW_BIT           13011	/*! ����λͼʱλͼ����Ϊ��*/
#define	UGS_CREATE_BRUSH_FAILED                 13012	/*! ������ˢʧ��*/
#define	UGS_GET_INFO_IS_NULL                    13013	/*! ��ȡ��ϢΪ��*/
#define	UGS_GET_BACKGRAPHIC_FAILED              13014	/*! ������������ʧ��*/
#define	UGS_CREATE_TRANSGRAPHIC_FAILED          13015	/*! ������͸������ʧ��*/
#define	UGS_BACK_IMAGE_DATA_INVALID             13016	/*! ����Image���ݲ��Ϸ�*/
#define	UGS_TRANSIMAGE_INVALID                  13017	/*! ͸��Image���ݲ��Ϸ�*/
#define	UGS_GRADIENT_RECTANGLE_IS_NULL          13018	/*! �������Ϊ��*/
#define	UGS_TRANS_HEIGHT_OR_WIDTH_IS_ZERO       13019	/*! ��͸���߶Ȼ���Ϊ��*/
#define	UGS_CREATE_BACKGRAPHICS_FAILED_WHEN_TRANS 13020	/*! ��͸��Ч��ʱ��������������ʧ��*/
#define	UGS_CREATE_BACKIMAGE_FAILED_WHEN_TRANS  13021	/*! ��͸��Ч��ʱ��������Imageʧ��*/
#define	UGS_BIT_DATA_INVLAID                    13022	/*! λͼ���ݲ��Ϸ�*/
#define	UGS_BACKIMAGE_INVLAID                   13023	/*! ����Image���Ϸ�*/
#define	UGS_CLIP_REGION_IS_NULL                 13024	/*! �ü�����Ϊ��*/
#define	UGS_CREATE_CLIP_REGION_FAILED           13025	/*! �����ü�����ʧ��*/
#define	UGS_CLIP_RECTANGLE_IS_NULL              13026	/*! �ü��������Ϊ��*/
#define	UGS_RECTANGLE_IS_NULL                   13027	/*! ����Ϊ��*/
#define	UGS_RECTANGLE_HEIGHT_OR_WIDTH_LESSTHAN_TWO 13028	/*! ���εĿ�Ȼ��߸߶�С��2*/
#define	UGS_CREATE_MEMGRAPHIC_FAILED            13029	/*! �����ڴ滭��ʧ��*/
#define	UGS_CREATE_IMAGE_FAILED                 13030	/*! ����Imageʧ��*/
#define	UGS_FILLSYMPARAM_CREATE_IMAGE_FAILED    13031	/*! ���Ʋ�������Imageʧ��*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_FILLSYMBOL 13032	/*! ��ȡ������ʱ�ֽ���Ϊ��*/
#define	UGS_READ_FILLSYMBOL_FAILED              13033	/*! ��ȡ������ʧ��*/
#define	UGS_CANNOT_FIND_THE_FILLSYMBOL_VERSION  13034	/*! �Ҳ�����Ӧ�����ŵİ汾*/
#define	UGS_FILLSYMBOL_SUBSYMBOL_COUNT_IS_ZERO  13035	/*! �������ӷ��Ÿ���Ϊ��*/
#define	UGS_CANNOT_FIND_THE_FILLSYMBOL_VERSION_WHEN_SAVE 13036	/*! ����������ʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_DRAW_POLYGON_BOUND_RECTANGLE_IS_NULL_WHEN_DRAW_FILLSYM 13037	/*! ������ʱ���ƵĶ����������Ϊ��*/
#define	UGS_GET_FILLSYMPARAM_RECTANGLE_IS_NULL  13038	/*! ��ȡ����������Ϊ��*/
#define	UGS_GET_FILLSYMBOL_SUBLAYER_INDEX_INVLAID 13039	/*! ��ȡ�������Ӳ���������Ϸ�*/
#define	UGS_GET_FILLSYMBOL_SUBSYMBOL_INDEX_INVLAID 13040	/*! ��ȡ�����ŵ��ӷ����������Ϸ�*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_FILLSYMBOL_READ_BIT_INFO 13041	/*! �����Ŷ�ȡλͼ��Ϣʱ�ֽ���Ϊ��*/
#define	UGS_READ_SUBRASTER_SYMBOL_FAILED        13042	/*! ��ȡ��դ�����ʧ��*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_FILLSYMBOL_POINT 13043	/*! ��ȡ�����ŵ����ʱ�ֽ���Ϊ��*/
#define	UGS_READ_FILLSYM_SUBPOINT_FAILED        13044	/*! ��ȡ�������ӵ����ʧ��*/
#define	UGS_BIT_IS_NULL_WHEN_GET_BIT_SIZE       13045	/*! ��ȡλͼ��Сʱλͼ����Ϊ��*/
#define	UGS_BIT_IS_NULL_WHEN_FILLSYM_SAVE_BIT   13046	/*! �����ű���λͼ����ʱλͼ����Ϊ��*/
#define	UGS_CREATE_GRAPHICS_FAILED              13047	/*! ��������ʧ��*/
#define	UGS_FILLSYMBOL_IS_NULL                  13048	/*! ���λͼ����Ϊ��*/
#define	UGS_FILLSYMBOL_REMOVE_SUBLAYER_FAILED   13049	/*! �������Ƴ��Ӳ�ʧ��*/
#define	UGS_READ_BIT_FAILED                     13050	/*! ��ȡλͼ����ʧ��*/
#define	UGS_BIT_IS_NULL                         13051	/*! λͼ����Ϊ��*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_BIT   13052	/*! ��ȡλͼ����ʱ�ֽ���Ϊ��*/
#define	UGS_READ_SUBFILLSYM_POINT_FAILED        13053	/*! ��ȡ�������ŵĵ����ʱʧ��*/
#define	UGS_BIT_IS_NULL_WHEN_GET_SUBSYMBOL_BIT_SIZE 13054	/*! ��ȡ�ӷ���λͼ��Сʱ����Ϊ��*/
#define	UGS_BIT_IS_NULL_WHEN_SAVE_BIT           13055	/*! ����λͼ����ʱ����Ϊ��*/
#define	UGS_BIT_HEIGHT_OR_WIDTH_IS_ZERO         13056	/*! λͼ���ݸ߶Ȼ��߿��Ϊ��*/
#define	UGS_BIT_RECTANGLE_SIZE_INVALID          13057	/*! λͼ���εĴ�С���Ϸ�*/
#define	UGS_CREATE_GRAPHICS_INVALID             13058	/*! �����ڴ滭�����Ϸ�*/
#define	UGS_ROMANCE_POINT_SYMBOL_NOT_FIND_OPPOSITE_SYMBOL_TYPE 13059	/*! ��Ⱦ�����ʱû���ҵ���Ӧ�ķ�������*/
#define	UGS_BYTE_STREAM_INFO_IS_NULL_WHEN_READ_FILLLIB 13060	/*! ��ȡ����ʱ�ֽ�����ϢΪ��*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_FILLLIB_APPEND_INFO 13061	/*! ������׷����Ϣʱ�ֽ���Ϊ��*/
#define	UGS_TEMPORARY_FILLLIB_APPEND_FAILED     13062	/*! ��ʱ����׷��ʧ��*/
#define	UGS_FILLLIB_ADD_FAILED                  13063	/*! �������ʧ��*/
#define	UGS_READ_ICON_CANNOT_FIND_FIT_VERSION   13064	/*! Icon���Ŷ�ȡ�Ҳ������ʰ汾*/
#define	UGS_SAVE_ICON_CANNOT_FIND_FIT_VERSION   13065	/*! ����Icon�Ҳ�����Ӧ�汾*/
#define	UGS_READ_ICON_FAILED                    13066	/*! ��ȡIcon����ʧ��*/
#define	UGS_SAVE_ICON_FAILED                    13067	/*! ����Icon����ʧ��*/
#define	UGS_SAVE_BYTE_LENGTH_LESSTHAN_ZERO      13068	/*! ������ֽڳ���С��0*/
#define	UGS_ICON_IS_NULL                        13069	/*! Icon����Ϊ��*/
#define	UGS_ICON_IDRESERVED_NOT_ZERO            13070	/*! ��ȡIcon���ֶ�idReserved��Ϊ0*/
#define	UGS_ICON_IDTYPE_NOT_ONE                 13071	/*! ��ȡIcon���ֶ�idType��Ϊ1*/
#define	UGS_ICON_IDCOUNT_LESSTHAN_ZERO          13072	/*! ��ȡIcon�е�idCountС��0*/
#define	UGS_ICON_INFO_IS_NULL                   13073	/*! ��ȡIcon��Ϣ����Ϊ��*/
#define	UGS_ICON_BYTE_IS_NULL                   13074	/*! ��ȡIcon��������Ϊ��*/
#define	UGS_SAVE_ICON_IS_NULL                   13075	/*! ����Icon����Ϊ��*/
#define	UGS_DRAW_ICON_IS_NULL                   13076	/*! ����Iconʱ����Ϊ��*/
#define	UGS_READ_LINESYMBOL_SUBLINE_CANNOT_FIND_OPPOSITE_VERSION 13077	/*! ��ȡ�߷�������ʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_SAVE_LINESYMBOL_SUBLINE_CANNOT_FIND_OPPOSITE_VERSION 13078	/*! �������Է����ӷ���ʱ�Ҳ�����Ӧ�汾*/
#define	UGS_CANNOT_FIND_OPPOSITE_VERSION_WHEN_READ_LINESYMBOL 13079	/*! ���ͷ��Ŷ�ȡ�Ҳ�����Ӧ�汾*/
#define	UGS_READ_LINE_SYMBOL_EXTEND_FAILED      13080	/*! ���ͷ�����չ��ȡʧ��*/
#define	UGS_READ_SUBLINE_SYMBOL_FAILED          13081	/*! ���߶�ȡʧ��*/
#define	UGS_SAVE_EXTEND_SYMBOL_FAILED_WHEN_SAVE_SYMBOL 13082	/*! �߷��ű���ʱ��չ���ű���ʧ��*/
#define	UGS_REMOVE_INDEX_INVALID_WHEN_REMOVE_SUB_LINE_SYMBOL 13083	/*! �Ƴ�����ʱ��Ҫ�Ƴ����������Ϸ�*/
#define	UGS_SAVE_D_SUBLINE_FAILED               13084	/*! ��%d�����߱���ʧ��*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO            13085	/*! �����С��2*/
#define	UGS_MOVING_INDEX_OR_MOVEING_TO_INDEX_INVALID_WHEN_MOVING_SUBLINE 13086	/*! �ƶ����߷���ʱ���ƶ����������ƶ������������Ϸ�*/
#define	UGS_MOVING_INDEX_INVALID_WHEN_SUBLINE_MOVE_TO_BOTTOM 13087	/*! �����ƶ����ײ�ʱ��Ҫ�ƶ��������������Ϸ�*/
#define	UGS_MOVING_SUBLINE_INVALID_WHEN_MOVING_SUBLINE_UP 13088	/*! ��������ʱ��Ҫ�ƶ������߲��Ϸ�*/
#define	UGS_MOVING_SUBLINE_INDEX_INVALID_WHEN_MOVING_TOP 13089	/*! �����Ƶ�����ʱ��Ҫ�ƶ��������������Ϸ�*/
#define	UGS_READ_SUBLINE_NOT_FIND_FIT_VERSION   13090	/*! ���߶�ȡ�Ҳ������ʵİ汾*/
#define	UGS_SAVE_SUBLINE_NOT_SUPPORT_LOW_VERSION 13091	/*! ���߱��治֧�ֵͰ汾*/
#define	UGS_SAVE_SUBLINE_FAILED                 13092	/*! �������ݱ���ʧ��*/
#define	UGS_COMPUTE_PARALLEL_LINE_INTERVAL_FAILED_FOR_INTERVAL_IS_ZERO 13093	/*! ����ƽ���߼��ʱ�����Ϊ��ʧ��*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO_OR_POINTER_IS_NULL_WHEN_DRAW_POLYLINE 13094	/*! ����Polylineʱ�������С��2���ߵ�ָ��Ϊ��*/
#define	UGS_JUST_FINISH_DRAWING_WHOLE_POLYLINE_ 13095	/*! �պý����������ߵĻ���*/
#define	UGS_ARRIVE_POLYLINE_END_WHOLE_POLYLINE_DRAWING_FINISH 13096	/*! �Ѿ������������ߵ�����ˣ��������߻��������*/
#define	UGS_JUDEGE_FIRST_WHETHER_JUST_FINISH_DRAWING_WHOLE_POLYLINE 13097	/*! ���ж�һ���Ƿ�պý����������ߵĻ���*/
#define	UGS_DRWING_STARTPOINT_AND_ENDPOINT_IS_THE_SAME_POINT 13098	/*! ������ʱ�����յ�һ��*/
#define	UGS_SOLID_PART_IS_ZERO                  13099	/*! �����ߵ�ʵ����Ϊ��*/
#define	UGS_CALCULATE_GRADIENT_LINE_POINT_POINTER_IS_NULL_OR_COUNT_LESSTHAN_TWO 13100	/*! ���㽥����ʱ����ָ��Ϊ�ջ��ߵ����С��2����ʼ��ֹ��Ŀ��С��0*/
#define	UGS_GRADIENT_INTERVAL_IS_ZERO           13101	/*! �����ߵļ��Ϊ��*/
#define	UGS_DRAWING_GRADIENT_LINE_POINT_COUNT_IS_ZERO 13102	/*! ���ƽ�����ʱ�����Ƶĵ�ĸ���Ϊ��*/
#define	UGS_LINE_EXTENT_COUNT_MORETHAN_FIVE     13103	/*! ������չ��������5*/
#define	UGS_READ_LINEEXTENT_NOT_FIND_OPPOSITE_VERSION 13104	/*! ��չ���Ͷ�ȡʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_SAVE_LINE_EXTENT_NOT_SUPPORT_LOW_VERSION 13105	/*! ������չ����ʱ��֧�ֵͰ汾*/
#define	UGS_NO_TOKEN_INFO                       13106	/*! û��Token��Ϣ*/
#define	UGS_INDEX_OVERTOP_WHEN_GET_SYMBOLEXTENT_INDEX 13107	/*! ��ȡ��չ���ŵ�����ʱ������Խ��*/
#define	UGS_INDEX_OVERTOP_WHEN_REMOVE_EXTENTSYMBOL 13108	/*! �Ƴ���չ����ʱ����Խ��*/
#define	UGS_CREATING_PEN_SAMEAS_CURRENT_PEN_NEEDNOT_CREATE 13109	/*! ��������ʱ�͵�ǰ����ͬ������Ҫ�ٴ�����*/
#define	UGS_CREATING_BRUSH_COLOR_SAMEAS_CURRENT_BRUSH_NEEDNOT_CREATE 13110	/*! ������ˢʱ���͵�ǰ�Ļ�ˢ��ɫ��ͬ������Ҫ�ٴ���*/
#define	UGS_NEEDNOT_CREATE_BRUSH                13111	/*! ����Ҫ������ˢ*/
#define	UGS_POINT_INFO_INVALID_WHEN_DRAW_EXTENTLINE 13112	/*! ������չ����ʱ������Ϣ���Ϸ�*/
#define	UGS_CANNOT_FIND_EXTERIOR_SYMBOL_WHEN_EXTENTLINE_USE_DEFINE_SYMBOL 13113	/*! ��չ����ʹ���Զ������ʱ���Ҳ����ⲿ���ſ�*/
#define	UGS_FILLSYMBOL_READ_BYTESTREAM_IS_NULL  13114	/*! �����Ŷ�ȡ�ֽ���Ϊ��*/
#define	UGS_IAMGE_SIZE_OVERTOP_WHEN_FILLSYMBOL_ROMANCE 13115	/*! ��������Ⱦʱͼ���СԽ��*/
#define	UGS_FILLSYMBOL_CANNOT_FIND_OPPOSITE_POINT_INFO 13116	/*! �������Ҳ�����Ӧ�ĵ������Ϣ*/
#define	UGS_CREATE_MEMORY_GRAPHICS_FAILED_WHEN_FILLSYMBOL_ROMANCE 13117	/*! ��������Ⱦʱ�����ڴ滭��ʧ��*/
#define	UGS_CREATE_IMAGE_INVALID_WHEN_FILLSYMBOL_ROMANCE 13118	/*! ��������Ⱦʱ����Image���Ϸ�*/
#define	UGS_POINT_READ_SYMSTROKE_CANNOT_FIND_THE_OPPOSITE_VERSION 13119	/*! ����űʻ���ȡ�Ҳ�����Ӧ�İ汾*/
#define	UGS_POINT_STROKE_SAVE_NOT_SUPPORT_LOW_VERSION 13120	/*! ����űʻ����治֧�ֵͰ汾*/
#define	UGS_NOT_FIND_POINT_STROKE_OPPOSITE_TYPE 13121	/*! �Ҳ�������űʻ��Ķ�Ӧ������*/
#define	UGS_SAVE_POINT_STROKE_FAILED            13122	/*! �������űʻ�ʧ��*/
#define	UGS_READ_ICON_STROKE_FAILED             13123	/*! ��ȡIcon�ʻ�ʧ��*/
#define	UGS_CANNOT_FIND_OPPOSITE_STROKE_WHEN_READ_STROKE 13124	/*! ��ȡ�ʻ�ʱ�Ҳ�����Ӧ�ıʻ�����*/
#define	UGS_POINT_COUNT_LESSTHAN_THREE_WHEN_READ_POLYGON_STROKE 13125	/*! ��ȡ��������ͱʻ�ʱ�����С��3*/
#define	UGS_READ_BIT_STROKE_FAILED              13126	/*! ��ȡλͼ�ʻ�ʱʧ��*/
#define	UGS_SAVE_STROKE_NOT_SUPPORT_LOW_VERISON 13127	/*! ����ʻ���֧�ֵͰ汾*/
#define	UGS_CONSTRUCT_ARC_POINT_POINTER_IS_NULL 13128	/*! �������ε�ָ��Ϊ��*/
#define	UGS_TEXT_IS_NULL_WHEN_CONSTRUCT_POINT_STROKE 13129	/*! ��ʻ�����ʱ�ı�Ϊ��*/
#define	UGS_NOT_FIND_OPPOSITE_VERSION_WHEN_READ_POINT 13130	/*! ��ȡ�����ʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_NOT_SUPPORT_LOW_VERSION_WHEN_SAVE_POINT 13131	/*! ��������ʱ��֧�ֵͰ汾*/
#define	UGS_POINT_SAVE_D_STROKE_FAILED          13132	/*! ����ŵ�%d���ʻ�����ʧ��*/
#define	UGS_DRAWING_PARAM_DISPLAY_BOUND_LESSTHAN_ZERO_WHEN_DRAWING_POINT 13133	/*! ����Ż���ʱ���Ʋ�����ʾ��ΧС��0*/
#define	UGS_MERGE_FAILED_FOR_MERGE_SYMBOL_IS_NULL 13134	/*! �ϲ�����Ϊ�գ��ϲ�ʧ��*/
#define	UGS_INDEX_D_INVALID_WHEN_REMOVE_POINT   13135	/*! ������Ƴ�ʱ,����%d���Ϸ�*/
#define	UGS_READ_POINT_SYMLIB_FAILED_FOR_MARKER_ERROR 13136	/*! ����ſ��ȡʱ��־�д���ȡʧ��*/
#define	UGS_READ_D_SYMBOL_FAILED                13137	/*! ��%d�����Ŷ�ȡʧ��*/
#define	UGS_POINT_LIB_SAVE_NOT_SUPPORT_THIS_VERSION 13138	/*! ����ſⱣ�治֧�ִ˰汾*/
#define	UGS_POINT_LIB_D_SYMBOL_SAVE_FAILED      13139	/*! ����ſ��е�%d�����ű���ʧ��*/
#define	UGS_SYMBOL_LIB_NOT_FIND_OPPOSITE_NAME_SUBGROUP 13140	/*! ���ſ�û���ҵ���Ӧ���ֵ�����*/
#define	UGS_CREATE_FAILED_FOR_SAME_NAME_SUBGROUP_ALREADY_EXSIT 13141	/*! �Ѿ����ڴ����ֵ����飬����ʧ��*/
#define	UGS_SET_OBJECT_ID_INDEX_OVERLOP         13142	/*! ���ö���ID������Խ��*/
#define	UGS_SET_ID_SAME_AS_SELF_ID              13143	/*! ���õ�ID������ID��ȣ����ø���*/
#define	UGS_SET_ID_FAILED                       13144	/*! ����IDʧ��*/
#define	UGS_NOT_FIND_THE_OPPOSITE_ID_INDEX      13145	/*! û���ҵ���ӦID������*/
#define	UGS_REMOVE_APPOINTED_ID_SYMBOL_FAILED   13146	/*! �Ƴ�ָ��ID�ķ���ʧ��*/
#define	UGS_REMOVE_APPOINTED_INDEX_AND_DELETE_SYMBOL_FAILED 13147	/*! �Ƴ�ָ������ID��ɾ�����ŵĲ���ʧ��*/
#define	UGS_REMOVE_GROUP_APPOINTED_INDEX_SUBGROUP_INDEX_OVERLOP 13148	/*! �Ƴ�����ָ������������ʱ������Խ��*/
#define	UGS_MOVE_FROM_TO_SELFGROUP_FAILED       13149	/*! �û����ڴӱ������ƶ��������У�����ʧ��*/
#define	UGS_NOT_EXIST_NEED_MOVE_SYMBOL_ID       13150	/*! �����ڴ�ʱҪ��Ҫ�ƶ����ŵ�ID*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_THIS_ID_NOT_EXIST 13151	/*! �ڱ��鼰�������в����ڴ�ID*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_NOT_FIND_THE_OPPOSITE_NAME_GROUP 13152	/*! �ڱ��鼰����������û���ҵ���Ӧ���Ƶ���*/
#define	UGS_SYMBOL_WITH_THIS_ID_NOT_EXIST       13153	/*! �����ڴ�ID��Ӧ�ķ���*/
#define	UGS_CURRENT_GROUP_EXIST_SYMBOL_WITH_THIS_ID 13154	/*! ��ǰGroup�д��ڴ�ID�ķ���*/
#define	UGS_INDEX_OVERLOP_WHEN_SEARCH_SYMBOL_NAME 13155	/*! ���ҷ�������ʱ��ʵ����Խ��*/
#define	UGS_SEARCHING_SYMLIB_NOT_HAVE_INDEX_WITH_OPPOSITE_NAME 13156	/*! ���ҷ��ſ���û���ҵ���Ӧ���Ƶ�����*/
#define	UGS_SYMLIB_SYMBOL_COUNT_LESSTHAN_ZERO   13157	/*! ���ſ��з�������С��0*/
#define	UGS_NOT_FIND_SYMBOL_WITH_THE_NAME_WHEN_REVERSE_SEARCH 13158	/*! �������ʱû���ҵ���Ӧ���Ƶķ���*/
#define	UGS_OVERLOP_WHEN_REMOVE_THE_SYMBOL_INDEX 13159	/*! �Ƴ�ָ�����ŵ�����Խ��*/
#define	UGS_NOT_FIND_INDEX_WITH_THE_ID_WHEN_REMOVING 13160	/*! �Ƴ�����ʱ��ָ�������ķ���û���ҵ�*/
#define	UGS_INDEX_OVERLOP_WHEN_GET_THE_SYMBOL   13161	/*! ��ȡ���ſ��з���ʱ������Խ��*/
#define	UGS_APPOINT_ID_NOT_EXIST_IN_SYMLIB      13162	/*! ָ��ID�ڷ��ſ��в�����*/
#define	UGS_SYMBOL_WITH_APPOINT_ID_NOT_EXIST_IN_SYMLIB 13163	/*! ָ��ID�ڷ��ſ����Ҳ�������*/
#define	UGS_INDEX_OVERLOP_WHEN_SET_ID_IN_SYMLIB 13164	/*! ���ſ�������IDʱ������Խ��*/
#define	UGS_SET_ID_REPEAT                       13165	/*! ���õ���ID�ظ�*/
#define	UGS_SYMBOL_FOUND_IN_SYMLIB_IS_NULL      13166	/*! ���ſ������ҵ��ķ���Ϊ��*/
#define	UGS_INDEX_OVERLOP_WHEN_SEARCH_NAME_IN_SYMLIB 13167	/*! ���ſ��в�������ʱ������Խ��*/
#define	UGS_CANNOT_FIND_SYMBOL_WITH_OPPOSITE_INDEX 13168	/*! �Ҳ�����Ӧ�����ķ���*/
#define	UGS_INDEX_OVERLOP_WHEN_SYMLIB_SET_SYMBOL_NAME 13169	/*! ���ſ������÷�������ʱ��ָ������Խ��*/
#define	UGS_INDEX_OVERLOP_WHEN_SWAP             13170	/*! ���ſ��з��Ž���ʱ����Խ��*/
#define	UGS_UNKNOWN_SYMBOL_VERSION              13171	/*! ��ʶ��ķ��Ű汾*/
#define	UGS_SYMBOL_TRUETYPE                     13172	/*! ����TrueType����*/
#define	UGS_INPUT_METAFILE                      13173	/*! �ӽ����ļ�������ſ�*/
#define	UGS_LSL_MSG_LINE_NUMBER_NOTE            13174	/*! ���͵ı�ű������6��*/


// ��ͼ��λ��Ϣ����14000��ʼ����
#define	UGS_SYMBOL_DEGREE                       14000	/*! ��	*/
#define	UGS_SYMBOL_MINUTE                       14001	/*! �@*/
#define	UGS_MILIMETER                           14002	/*! ����*/
#define	UGS_CENTIMETER                          14003	/*! ����*/
#define	UGS_DECIMETER                           14004	/*! ����*/
#define	UGS_METER                               14005	/*! ��*/
#define	UGS_KILOMETER                           14006	/*! ǧ��*/
#define	UGS_MILE                                14007	/*! Ӣ��*/
#define	UGS_INCH                                14008	/*! Ӣ��*/
#define	UGS_YARD                                14009	/*! ��*/
#define	UGS_FOOT                                14010	/*! Ӣ��*/
#define	UGS_DEGREE                              14011	/*! ��*/
#define	UGS_MINUTE                              14012	/*! ��*/
#define	UGS_SECOND                              14013	/*! ��*/
#define	UGS_SQ_MILIMETER                        14014	/*! ƽ������*/
#define	UGS_SQ_CENTIMETER                       14015	/*! ƽ������*/
#define	UGS_SQ_DECIMETER                        14016	/*! ƽ������*/
#define	UGS_SQ_METER                            14017	/*! ƽ����*/
#define	UGS_SQ_KILOMETER                        14018	/*! ƽ������*/
#define	UGS_SQ_MILE                             14019	/*! ƽ��Ӣ��*/
#define	UGS_SQ_INCH                             14020	/*! ƽ��Ӣ��*/
#define	UGS_SQ_YARD                             14021	/*! ƽ����*/
#define	UGS_SQ_FOOT                             14022	/*! ƽ��Ӣ��*/
#define	UGS_SM_STR_TIME_FORMAT                  14023	/*! %Y��%m��%d�� %Hʱ%M��%S��*/


// ��ͼ������Ϣ����15000��ʼ����
#define	UGS_CAN_NOT_CREATE_UNIQUE_THEMATIC_MAP_WITH_MORE_THAN_X_VALUES 15000	/*! ��ֵר���ͼ�ĵ�ֵ�������ܳ���%d����������ֵר��ͼʧ�ܡ�*/
#define	UGS_CAN_NOT_CREATE_RANGE_THEMATIC_MAP_WITH_MORE_THAN_X_RANGES 15001	/*! �ֶε���Ŀ���ܳ���%d,�����ֶ�ר��ͼʧ��!*/
#define	UGS_THEME_WIZARD                        15002	/*! ���򵼽����������ɵĴ���ר��ͼ/n*/
#define	UGS_IMAGE_MSG_COLOR_HISTOGRAN_DLG_ERROE 15003	/*! ����Ӱ��ͼ�������ֱ��ͼ��*/
#define	UGS_LYT_ERR_LOAD_RULER_BMP              15004	/*! ������λͼʱ����*/
#define	UGS_LYT_ERROR_CREATE_SCALE              15005	/*! ��������̫С���޷���ȷ���ɱ�����!*/
#define	UGS_LYT_SCALE_NOT_APPROPRIATE           15006	/*! �������С�ڳ���̫С��*/
#define	UGS_LYT_SCALE_EXISTED                   15007	/*! �˵�ͼ�ı������Ѿ����ڣ�*/
#define	UGS_LYT_LEGEND_EXISTED                  15008	/*! �˵�ͼ��ͼ���Ѿ����ڣ�*/
#define	UGS_LYT_BMP_OVERSIZE                    15009	/*! ѡ���ͼ��̫��*/
#define	UGS_SLMSG_INVALID_DRAG                  15010	/*! �����ϵ���ǰλ��*/
#define	UGS_SLMSG_NOT_SUPPORT_LEGEND_ITEM_TYPE  15011	/*! ��֧�ֵ�ͼ������*/
#define	UGS_LYT_ERROR_MSG                       15012	/*! ��������̫С���޷���ȷ���ɱ�����!*/
#define	UGS_VIEW_MAP_BEGAIN                     15013	/*! ��ʼ��ʾ��ͼ*/
#define	UGS_SLMSG_NO_LAYER                      15014	/*! û��ͼ�㣬�޷���ɳ�ʼ��*/
#define	UGS_SET_INPUT_POLYGONLAYER              15015	/*! �������������ͼ�㣡*/
#define	UGS_SET_INPUT_REGIONLAYER               15016	/*! ����������������ͼ�㣡*/
#define	UGS_LYT_SEL_ONE_GROUP                   15017	/*! ��ѡ��һ�����顱����!*/
#define	UGS_EDIT_ERR_GET_GEOMETRY               15018	/*! ȡ��ͼ���ݴ���*/
#define	UGS_SL_MSG_TREEITEM_NOT_BELONG_TO_ANY_LAYER 15019	/*! �����Ľڵ㲻�����κ�ͼ��*/
#define	UGS_LAYER_LOCK                          15020	/*! ������ǰͼ��*/
#define	UGS_SLMSG_CANNT_CHANGE_ITEM_TYPE        15021	/*! ͼ������Ͳ�ͬ,�����޸�ͼ�������*/
#define	UGS_LYT_OUTPUT_MANAGING                 15022	/*! ���ڴ������Ӱ�����Ժ�...*/


// ���ζ�������Ϣ����18000��ʼ����
#define	UGS_GET_GEOMETRY_DATA_FAILED            18000	/*! ��ȡ����ռ�����ʧ��*/
#define	UGS_MEMORY_ALLOTE_SHORTAGE              18001	/*! �ڴ���䲻��*/
#define	UGS_GET_OBJECT_FAILED                   18002	/*! ��ȡ����ʧ��*/
#define	UGS_OBJECTS_IDENTITY_QUERY_FAILED       18003	/*! ����ͬһ��ѯʧ��*/
#define	UGS_GET_OBJECT_SPATIAL_INFO_FAILED      18004	/*! ��ȡ����ռ���Ϣʧ��*/
#define	UGS_FAILED_TO_DRAW_REGION_FOR_REGION_IS_NULL 18005	/*! �����Ϊ�ջ��������Ľڵ���С�ڵ���0�����������ʧ��*/
#define	UGS_FAILED_TO_DRAW_REGION_FOR_REGION_NODES_NUMBER_BIGGER_THAN_MAX 18006	/*! �����Ľڵ������������ƽڵ��������������ʧ��*/
#define	UGS_SPATIAL_INDEX_NOT_SUPPORT_POITN_DATASET 18007	/*! �ռ�������֧�ֵ����ݼ�*/
#define	UGS_INDEX_TABLE_IS_EXIST_PLEASE_CHECK_ITS_CORRECTNESS 18008	/*! �������Ѿ����ڣ���������ȷ��*/
#define	UGS_IMPORT_MAYBE_GIRD_IS_NULL           18009	/*! �����maybe����Ϊ��*/
#define	UGS_EMPTY_GEODATA                       18010	/*! ��ǰ����Ϊ��*/
#define	UGS_LESS_POINT_COUNT                    18011	/*! ����ĵ�����������%d��*/
#define	UGS_OVERLAP_POINT                       18012	/*! ����ĵ��ص�*/
#define	UGS_NODE_ERROR                          18013	/*! �����Ϣ����*/
#define	UGS_GEODATA_ERROR                       18014	/*! ���ζ��������д���*/
#define	UGS_NO_GEO_FIGURE                       18015	/*! �Ǽ���ͼ��*/
#define	UGS_COMPUTE_AREA                        18016	/*! �����������*/
#define	UGS_ERROR_COV_MOREPOINT                 18017	/*! �����Ŀ����/n*/
#define	UGS_POINT_LACK                          18018	/*! ���߿��Ƶ�ĸ�����������6��*/
#define	UGS_MSG_OBJ_INVALID                     18019	/*! ������Ч*/
#define	UGS_MSG_INTERSECTOR_IS_NOT_TWO_POINT    18020	/*! ��ȷ��������߽�����������!*/
#define	UGS_MSG_DATA_WAS_DAMAGED                18021	/*! �����ѱ��ƻ�*/
#define	UGS_XML_DATA_ERROR                      18022	/*! XML�����д���*/
#define	UGS_XML_POINTNUM_NOT_SAME               18023	/*! ��ĸ�����һ�£�*/
#define	UGS_STRING_AFC_EDIT_DELETE_OBJ          18024	/*! ����ɾ�����������*/
#define	UGS_STRING_AFC_EDIT_ERROR               18025	/*! �еط���������*/
#define	UGS_EDIT_ERR_NORECORD                   18026	/*! ��ǰ�༭�Ķ��󲻴��ڣ�*/
#define	UGS_ERROR_IDENTIAL_POINT                18027	/*! ����ĵ�ȫ���ص�!*/
#define	UGS_SET_INPUT_LINE_LAYER                18028	/*! �����������������ݼ���*/
#define	UGS_POLYGON_AREA_IS_ZERO                18029	/*! ��������Ϊ�㣡*/
#define	UGS_POLYGON_CENTROID_CREATE_ERROR       18030	/*! ��������ĵ㴴������*/
#define	UGS_STEP_1_BUILDING                     18031	/*! ���������(%d/%d)...*/
#define	UGS_STEP_3_BUILDING                     18032	/*! ������δ���(%d/%d)...*/
#define	UGS_STEP_4_BUILDING                     18033	/*! ��������ͼ��(%d/%d)...*/
#define	UGS_MSG_CLEARING_SMALL_POLYGON          18034	/*! ���С�����*/
#define	UGS_MSG_FIND_POLYPOLYLINE               18035	/*! �����ݼ����и����߶���(SMID=%d)*/
#define	UGS_MSG_PICKUP_POLYGON                  18036	/*! ��ȡ�����*/
#define	UGS_MSG_POLYGON_PREPROCESS              18037	/*! �����Ԥ����*/
#define	UGS_STEP_REGION_BUILD                   18038	/*! ��ȡ�����(%d/%d)...*/
#define	UGS_MSG_POLYGON_PREPROCESS_BUILD        18039	/*! �����Ԥ����(%d/%d)...*/


// IO���ļ�������Ϣ����19000��ʼ����
#define	UGS_DATAPUMP_UNKNOWN_FILETYPE           19000	/*! ����ʶ����ļ���ʽ����(%d)*/
#define	UGS_DATAPUMP_IMPORT_PARAMS_ERROR        19001	/*! ����ת�������������*/
#define	UGS_DATAPUMP_CREATE_PMP_FAILED          19002	/*! ������ʽ����Ϊ%d������ת����ʧ��*/
#define	UGS_FILEPARSE_BASE_OPEN_FAILED          19003	/*! ��ʸ������������ļ�(%s)ʧ��*/
#define	UGS_FILEPARSE_READ_HEADER_FAILED        19004	/*! ��ȡ�ļ�ͷʧ��*/
#define	UGS_FILEPARSE_READ_FIELD_FAILED         19005	/*! ��ȡ�ֶ���Ϣʧ��*/
#define	UGS_FILEPARSE_EOF                       19006	/*! �ѵ��ļ�β*/
#define	UGS_FILEPARSE_SHP_IMPORT                19007	/*! ����Shape�ļ�*/
#define	UGS_FILEPARSE_SHP_IMPORTTING            19008	/*! ���ڵ���Shape�ļ�...*/
#define	UGS_FILEPARSE_SHP_HEADER_ERROR          19009	/*! ��ȡShape�ļ���shp�ļ�ͷʱ��������*/
#define	UGS_FILEPARSE_SHX_HEADER_ERROR          19010	/*! ��ȡShape�ļ���shx�ļ�ͷʱ��������*/
#define	UGS_FILEPARSE_SHP_FILECODE_ERROR        19011	/*! Shape�ļ�ͷ��FileCodeΪ%d, ������9994(Shape�ļ���־)*/
#define	UGS_FILEPARSE_SHP_LENGTH_ERROR          19012	/*! Shape�ļ�ͷ�м�¼���ļ�����(%d)���ļ�ʵ�ʳ���(%d)�����*/
#define	UGS_FILEPARSE_SHX_LENGTH_ERROR          19013	/*! shx�ļ�ͷ�м�¼���ļ�����(%d)���ļ�ʵ�ʳ���(%d)�����*/
#define	UGS_FILEPARSE_SHP_VERSION               19014	/*! Shape�ļ�ͷ��¼�İ汾��(%d)������1000(Shape��ʽ�汾��)*/
#define	UGS_FILEPARSE_SHP_GEOTYPE_PROBLEM       19015	/*! ����Shape�ļ�����(%s)����תΪǡ�������ݼ�����*/
#define	UGS_FILEPARSE_SHX_INDEX_ERROR           19016	/*! shx�ļ����������Ѿ���*/
#define	UGS_FILEPARSE_SHP_RECORDLENGTH          19017	/*! ��Shape�ļ�(%s)���Ϊ%d�ļ�¼��shp��shx�ļ��еĳ���������һ��"}*/
#define	UGS_FILEPARSE_SHP_TYPE_ERROR            19018	/*! ����ʶ���ShapeType(%d) */
#define	UGS_FILEPARSE_SHP_MULTIPATCH            19019	/*! ��ʱ��֧��ShapeTypeΪMultiPatch���͵�Shape�ļ�*/
#define	UGS_FILEPARSE_SHP_CREATE_FAILED         19020	/*! ����Shape�ļ�ʧ��*/
#define	UGS_FILEPARSE_DBF_IMPORT                19021	/*! ����DBF�ļ�*/
#define	UGS_FILEPARSE_DBF_IMPORTING             19022	/*! ���ڵ���DBF�ļ�...*/
#define	UGS_FILEPARSE_DBF_VER_NONSUPPORT        19023	/*! ��֧�ֵ�DBF�ļ��汾(0x%x)*/
#define	UGS_FILEPARSE_DBF_UNKNOWN_FIELDTYPE     19024	/*! ��DBF�ļ���, ��������ʶ���ֶ�����(%c)*/
#define	UGS_FILEPARSE_DBF_UNKNOWN_FLAG          19025	/*! ����ʶ��ļ�¼��ʼ���߽������(%d)*/
#define	UGS_FILE_OPEN_FAILED                    19026	/*! �ļ���%s����ʧ��*/
#define	UGS_FILE_CREATE_FAILED                  19027	/*! �ļ���%s������ʧ��*/
#define	UGS_FILE_WRITE_FAILED                   19028	/*! �ļ���%s��д��ʧ��*/
#define	UGS_FILE_READ_FAILED                    19029	/*! �ļ���%s����ȡʧ��*/
#define	UGS_FILE_NO_EXIST1                      19030	/*! �ļ���%s��������*/
#define	UGS_FILE_NO_EXIST2                      19031	/*! ָ�����ļ�������!*/
#define	UGS_FILE_DATA_TYPE_ERROR                19032	/*! �ļ����������ʹ���*/
#define	UGS_FILE_IS_USING                       19033	/*! �ļ�����ʹ����*/
#define	UGS_CANNOT_CREATE_TEMPFILE              19034	/*! ���ܴ�����ʱ�ļ�*/
#define	UGS_CREATE_TEMPORARY_FILE_ERROR         19035	/*! ���ɻ����ļ�����*/
#define	UGS_EXPORT_SIT                          19036	/*! ���ݼ�����ΪSIT�ļ�*/
#define	UGS_MSG_SDBPLUS_EXPORT_TO_TXT           19037	/*! ����ת�����ݵ����ݿ⽻����ʽ�ļ������Ժ�...*/
#define	UGS_WRITING_DXF_FILE                    19038	/*! ������� DXF �ļ�......*/
#define	UGS_WRITING_E00_FILE                    19039	/*! ������� E00 �ļ�......*/
#define	UGS_READING_DXF_FILE                    19040	/*! �������� DXF �ļ�......*/
#define	UGS_READING_E00_FILE                    19041	/*! �������� E00 �ļ�......*/
#define	UGS_READING_DGN_FILE                    19042	/*! ��������DGN �ļ�......*/
#define	UGS_WRITING_DGN_FILE                    19043	/*! ������� DGN �ļ�......*/
#define	UGS_READING_COV_FILE                    19044	/*! �������� Coverage �ļ�......*/
#define	UGS_WRITING_COV_FILE                    19045	/*! ������� Coverage �ļ�......*/
#define	UGS_READING_SHP_FILE                    19046	/*! �������� Shape �ļ�......*/
#define	UGS_LAYER_INFO                          19047	/*! ԭ�ļ���ʽ : %s �� %s �� %sת�� ��ʼ :%s ���� :%s*/
#define	UGS_READING_MIF_FILE                    19048	/*! �������� MIF �ļ�......*/
#define	UGS_WRITING_MIF_FILE                    19049	/*! ������� MIF �ļ�......*/
#define	UGS_READING_VCT_FILE                    19050	/*! �������� ���ұ�׼��ʽVCT ʸ���ļ�......*/
#define	UGS_WRITING_VCT_FILE                    19051	/*! ������� ���ұ�׼��ʽVCT ʸ���ļ�......*/
#define	UGS_COMPACT                             19052	/*! ѹ��:*/
#define	UGS_COMPACT_ECW                         19053	/*! ECWѹ��:*/
#define	UGS_WRITING_SHP_FILE                    19054	/*! ������� Shape �ļ�......*/
#define	UGS_FILE_X_TOO_SMALL                    19055	/*! �ļ� %s ��Ч....*/
#define	UGS_FILE_FORMAT_INCORRECT               19056	/*! �ļ���ʽ����*/
#define	UGS_MSG_IMPORT_TAB                      19057	/*! ת��MapInfo TAB�ļ�*/
#define	UGS_READING_COV_FILE_PC_USERATT         19058	/*! �������� Coverage(PC��) �ļ��û��Զ����......	*/
#define	UGS_READING_COV_FILE_PC_USERATT_ERROR   19059	/*! ���� Coverage(PC��) �ļ��û��Զ����ʱ���������´���*/
#define	UGS_ERROR_COV_WRITEFILE                 19060	/*! д�ļ�ʱ��������/n*/
#define	UGS_ERROR_COV_WRITE_ONLY                19061	/*! ֻд��ʽ���ļ������ܶ�/n*/
#define	UGS_ERROR_COV_WRITESYSFIELDS            19062	/*! дCoverage�ļ�ϵͳ�ֶ�ʱ��������/n*/
#define	UGS_ERROR_COV_DIRLENGTH                 19063	/*! info\arc.dir�ļ������д���/n*/
#define	UGS_ERROR_COV_MOREARC                   19064	/*! infoĿ¼������arc000x.dat�ļ�����/n*/
#define	UGS_ERROR_COV_FIELDINFO                 19065	/*! �����ֶ���Ϣ�ļ�����/n*/
#define	UGS_ERROR_COV_FILEEXIST                 19066	/*! ��ͼ����һ���Ѿ����ڵ��ļ�/n*/
#define	UGS_ERROR_COV_READ_ONLY                 19067	/*! ֻ����ʽ���ļ�������д/n*/
#define	UGS_ERROR_COV_FILE_UNSPECIFIED          19068	/*! ����ȷ�����ļ�����/n*/
#define	UGS_ERROR_COV_PRECISION                 19069	/*! Coverage �ļ����ȴ���/n*/
#define	UGS_ERROR_COV_FILE_HARDIO               19070	/*! ���ļ�ʱӲ������/n*/
#define	UGS_ERROR_COV_FILE_ACCESSDENIED         19071	/*! �����ļ����ܾ�/n*/
#define	UGS_ERROR_COV_FILE_INVALID              19072	/*! �����ļ�ʱ���ļ���Ч/n*/
#define	UGS_ERROR_COV_FILE_TOOMANY              19073	/*! �����ļ�ʱ���ļ���Ŀ̫��/n*/
#define	UGS_ERROR_COV_FILE_NOTFOUND             19074	/*! ָ�����ļ�û���ҵ�/n*/
#define	UGS_ERROR_COV_FILE                      19075	/*! Coverage�ļ�ʧЧ/n*/
#define	UGS_ERROR_COV_FILENOOPEN                19076	/*! �ڲ����󣺶�û�д򿪵��ļ����в���/n*/
#define	UGS_ERROR_COV_FILE_SHARING              19077	/*! �ļ��������/n*/
#define	UGS_READING_COV_FILE_SUN_USERATT_ERROR  19078	/*! ��ת��Coverage(Sun��)�ļ��û����Ա�ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_USERATT        19079	/*! ����ת��Coverage(Sun��)�ļ��û����Ա�*/
#define	UGS_READING_COV_FILE_SUN_TEXT_ERROR     19080	/*! ��ת��Coverage�ļ���Sun���ı�ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_PC_POINT_ERROR     19081	/*! ��ת��Coverage�ļ���Pc���ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_POINT_ERROR    19082	/*! ��ת��Coverage�ļ���Sun���ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_PC_NETWORK_ERROR   19083	/*! ��ת��Coverage�ļ���Pc�����ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_NETWORK_ERROR  19084	/*! ��ת��Coverage�ļ���Sun�����ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_PC_LINE_ERROR      19085	/*! ��ת��Coverage�ļ���Pc�渴����ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_LINE_ERROR     19086	/*! ��ת��Coverage�ļ���Sun�渴����ͼ�㣩ʱ���������´���*/
#define	UGS_READING_COV_FILE_PC_REGION_ERROR    19087	/*! ��ת��Coverage�ļ���Pc����ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_REGION_ERROR   19088	/*! ��ת��Coverage�ļ���Sun����ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_PC_TEXT_ERROR      19089	/*! ��ת��Coverage�ļ���Pc��ע��ͼ�㣩ʱ���������´���/n*/
#define	UGS_READING_COV_FILE_SUN_TEXT_ERROR1    19090	/*! ��ת��Coverage�ļ���Sun��ע��ͼ�㣩ʱ���������´���/n*/
#define	UGS_BEGIN_WRITING_IN_DBF                19091	/*! ����ת��DBF�ļ�*/
#define	UGS_BEGIN_READ_IN_DBF                   19092	/*! ����ת��DBF�ļ�*/
#define	UGS_READING_WMF_FILE                    19093	/*! ����ת��WMF�ļ�*/
#define	UGS_WRITING_WMF_FILE                    19094	/*! ����ת��WMF�ļ�*/
#define	UGS_BEGIN_READING_IN_MDB                19095	/*! ����ת��Microsoft Access���ݿ��ļ�MDB...*/
#define	UGS_READING_DWG_FILE                    19096	/*! �������� DWG �ļ�...*/
#define	UGS_DXF_READING_ERROR                   19097	/*! ��ȡDXF�ļ�ʱ����*/
#define	UGS_READING_DWG_LAYER                   19098	/*! ���ڶ�ȡDWGͼ�εĲ���Ϣ......*/
#define	UGS_WRITING_JIF_FILE                    19099	/*! ת��JIF�ļ�...*/
#define	UGS_WRITING_JIF25000_FILE               19100	/*! ת��JIF25000�ļ�...*/
#define	UGS_MSG_NOT_SUPPORT_DXF_BINARY          19101	/*! %s ��dxf�ļ��Ķ����Ƹ�ʽ��ϵͳ�ݲ�֧�ִ˸�ʽ��ת�롣*/
#define	UGS_ERROR_VEC_DVC_NOEXIST               19102	/*! Idrisi VEC�ļ���˵���ļ�:%s ���ܴ򿪣���ȷ��˵���ļ�DVC�ļ���ͬһ���ļ����¡�*/
#define	UGS_VEC_EXPORT                          19103	/*! ����ת��Idrisi VEC�ļ�...*/
#define	UGS_VEC_IMPORT                          19104	/*! ����ת��Idrisi VEC�ļ�...*/
#define	UGS_SML_EXPORT                          19105	/*! ����ת��SML�ĵ�...*/
#define	UGS_SML_IMPORT                          19106	/*! ����ת��SML�ĵ�...*/
#define	UGS_AFC_DATAPMP_WRITE_CAD               19107	/*! ����� %ld �����϶���*/
#define	UGS_GML_EXPORT                          19108	/*! ����ת��GML�ĵ�...*/
#define	UGS_GML_IMPORT                          19109	/*! ����ת��GML�ĵ�...*/
#define	UGS_GXML_EXPORT                         19110	/*! ����ת��GXML�ĵ�...*/
#define	UGS_GXML_IMPORT                         19111	/*! ����ת��GXML�ĵ�...*/
#define	UGS_IMPORT_AUTOCAD                      19112	/*! ����ת��AutoCAD���ļ�...*/
#define	UGS_IMPORT_JIF50_250_1000               19113	/*! ����ת���ձ�ʸ����ʽ�ļ�...*/
#define	UGS_IMPORT_JIF2500                      19114	/*! ����ת���ձ�ʸ��2500��ʽ�ļ�...*/
#define	UGS_IMPORT_JIF10K                       19115	/*! ����ת���ձ�ʸ��10000��ʽ�ļ�...*/
#define	UGS_IMPORT_JIF25K                       19116	/*! ����ת���ձ�ʸ��25000��ʽ�ļ�...*/
#define	UGS_IMPORT_JRF10K                       19117	/*! ����ת���ձ�դ��10000��ʽ�ļ�...*/
#define	UGS_IMPORT_JRF10LANDUSE                 19118	/*! ����ת���ձ�դ��10LandUse��ʽ�ļ�...*/
#define	UGS_IMPORT_JRF10VOLCANO                 19119	/*! ����ת���ձ�դ��10Volcano��ʽ�ļ�...*/
#define	UGS_IMPORT_JRF50_250_1000               19120	/*! ����ת���ձ�դ���ʽ�ļ�...*/
#define	UGS_READING_FILENAME                    19121	/*! ���ڶ�ȡ�ļ���%s ...*/
#define	UGS_PMP_ACAD_ERROR_EXT_NAME             19122	/*! ��׺�����󣬱���ΪDWG����DXF*/
#define	UGS_PMP_ACAD_ERROR_GET_HEADER           19123	/*! ��ȡ�ļ�ͷʧ��*/
#define	UGS_PMP_ACAD_ERROR_FILE_VERSION         19124	/*! AutoCAD�ļ��汾����*/
#define	UGS_PMP_ACAD_ERROR_INVALID_NAME         19125	/*! ���ֲ��Ϸ�*/
#define	UGS_PMP_ACAD_ERROR_FILE_TYPE            19126	/*! AutoCAD�ļ����ʹ���*/
#define	UGS_PMP_ACAD_ERROR_INVALID_NUMBER       19127	/*! ��Ų��Ϸ�*/
#define	UGS_PMP_SELECT_SHX                      19128	/*! ��ѡ���ʵ���shx�ļ�*/
#define	UGS_PMP_SHX_FILTER                      19129	/*! AutoCAD SHX�ļ�(*.shx)*/
#define	UGS_PMP_OPEN_AUTOCAD                    19130	/*! ���ڴ�AutoCAD�ļ�*/
#define	UGS_PMP_SAVE_AUTOCAD                    19131	/*! ���ڱ���AutoCAD�ļ�*/
#define	UGS_PMP_SCAN_AUTOCAD                    19132	/*! ����ɨ��DXF�ļ�...*/
#define	UGS_PMP_IMPORT_FST                      19133	/*! ����ת��FST�ļ�*/
#define	UGS_PMP_IMPORT_ARCGRID                  19134	/*! ����ת��ArcInfo������Grid�ļ�...*/
#define	UGS_IMPORT_MAPGIS                       19135	/*! ����ת��MapGIS���뽻����ʽ...*/
#define	UGS_PMP_CREATE_LOGFILE_ERROR            19136	/*! ������־�ļ�ʧ�ܡ�*/
#define	UGS_PMP_GETLOGFILE_ERROR                19137	/*! �õ���־�ļ�����ʧ�ܡ�*/
#define	UGS_IMG_IMPORT                          19138	/*! ����ת��Erdas Image�ļ�...*/
#define	UGS_IMG_EXPORT                          19139	/*! ����ת��Erdas Image�ļ�...*/
#define	UGS_PMP_VERSION_ERROR                   19140	/*! Ŀǰ����֧�ִ˰汾���ļ�!*/
#define	UGS_IMPORT_JIFDSF                       19141	/*! ����ת���ձ����ݵ�ͼ25000��ʽ�ļ�...*/
#define	UGS_PMP_IMPORTING_RAW                   19142	/*! ���ڵ���RAW�ļ�...*/
#define	UGS_PMP_IMPORT_BSQ                      19143	/*! ���ڵ���BSQ�ļ�...*/
#define	UGS_PMP_IMPORTING_BIP                   19144	/*! ���ڵ���BIP�ļ�...*/
#define	UGS_IMPORT_MRSID                        19145	/*! ����ת��MrSID �ļ�*/
#define	UGS_READING_ECW_FILE                    19146	/*! ����ת�� ECW �ļ�...*/
#define	UGS_FSL_EDITTOOL_IMAGEIMPORT            19147	/*! ����ͼ���ļ�*/
#define	UGS_FSL_EXPORT_BMP                      19148	/*! ���ΪBMP�ļ�*/
#define	UGS_OUTPUTEX_MSG_CREATE_TEMP_FILE       19149	/*! ����������ʱ�ļ�......*/
#define	UGS_SM_NO_BITMAP_TO_SAVE                19150	/*! û��λͼ���Ա��档*/
#define	UGS_SM_FILE_OPEN_FAILED                 19151	/*! ���ļ�����*/
#define	UGS_SM_BITMAP_NOT_CREATED               19152	/*! ����λͼ����*/
#define	UGS_SM_MSG_FILE_X_NOT_EXISTS            19153	/*! �ļ� "%s" ������!*/
#define	UGS_SM_MSG_FAILED_TO_OPEN_FILE_X        19154	/*! ���ļ� "%s" ʧ��!*/
#define	UGS_SM_MSG_FAILED_TO_CREATE_FILE_X      19155	/*! �����ļ� "%s" ʧ��!*/
#define	UGS_SM_MSG_FAILED_TO_WRITE_FILE_X       19156	/*! д�ļ� "%s" ʧ��!	*/
#define	UGS_SM_MSG_FAILED_TO_READ_FILE_X        19157	/*! ���ļ� "%s" ʧ��!*/
#define	UGS_SM_MSG_FILE_VERSION_NEWER_THAN_SOFTWARE 19158	/*! ���ļ���Ҫ���߰汾��������ܴ򿪡�*/
#define	UGS_SM_FILE_TITLE_ERROR                 19159	/*! �ļ�ͷ����*/
#define	UGS_SM_FILE_DATA_TYPE_ERROR             19160	/*! �ļ��е��������ʹ���*/
#define	UGS_SM_FILE_COLUMNS_ERROR               19161	/*! �ļ�����ֵ����*/
#define	UGS_SM_DISKSPACE_NOT_ENOUGH             19162	/*! ���̿ռ䲻�㣡*/
#define	UGS_NO_ENOUGH_DISKSPACE                 19163	/*! ��ʱ�ļ�Ŀ¼���ڴ���û���㹻�ռ�*/


// ����ϵͶӰ������Ϣ����20000��ʼ����
#define	UGS_MAP_LAMBERT_NAME                    20000	/*! �Ƚ�Բ׶ͶӰ*/
#define	UGS_PJ_NONEARTH_2_EARTH_OR_PJ           20001	/*! �ǵ������겻������������ͶӰ�������ת����*/
#define	UGS_PJ_THE_SAME_SYSTEM                  20002	/*! ͬϵ������ת��*/
#define	UGS_PJ_EARTH_2_EARTH                    20003	/*! ��������ϵ֮����ʱ����ת��*/
#define	UGS_PJ_UGS_INVALID                      20004	/*! ͶӰϵ��Ч*/
#define	UGS_PJ_SRC_IS_NOT_PJ                    20005	/*! Դ����ͶӰϵ*/
#define	UGS_PJ_DES_IS_NOT_PJ                    20006	/*! Ŀ�Ĳ���ͶӰϵ*/
#define	UGS_PJ_SRC_IS_NOT_EARTH                 20007	/*! Դ���ǵ�������ϵ*/
#define	UGS_PJ_DES_IS_NOT_EARTH                 20008	/*! Ŀ�Ĳ��ǵ�������ϵ*/
#define	UGS_PROJECT_INVLAID                     20009	/*! ͶӰ��Ϣ����ȷ*/
#define	UGS_EARTH_COORD_SYSTEM                  20010	/*! ��γ����ϵ*/
#define	UGS_PLANAR_COORD_SYSTEM                 20011	/*! ƽ������ϵ*/
#define	UGS_PJ_NAME                             20012	/*! ͶӰ����*/
#define	UGS_PJ_PARAMETER                        20013	/*! ����*/


// �ռ����������Ϣ����21000��ʼ����
#define	UGS_BUFFER_ANALYSIS_NOT_SUPPORT_DIFFERENT_RADIU 21000	/*! ������������ʱ��֧�����Ҳ��Ȼ���*/
#define	UGS_BUFFER_ANALYSIS_SEMICIRCLESEMENT_NOT_CORRET 21001	/*! ��ϻ���̫С��̫��*/
#define	UGS_BUFFER_ANALYSIS_FAILED              21002	/*! ����������ʧ��*/
#define	UGS_BUFFER_ANALYSIS_OBJECTS_COUNT_IS_0  21003	/*! �������Ϊ0*/
#define	UGS_BUFFER_ANALYSIS_CREATE_UDB_DATASOURCE_FAIL 21004	/*! ����UDB����Դʧ��*/
#define	UGS_BUFFER_ANALYSIS                     21005	/*! ����������*/
#define	UGS_BUFFER_CREATING                     21006	/*! �������ɻ�����...*/
#define	UGS_CLIP_DT                             21007	/*! Clip���ݼ�*/
#define	UGS_CLIPPING_DT                         21008	/*! ����Clip���ݼ�*/
#define	UGS_JUST_REGION_CLIP                    21009	/*! ֻ�ж�������ݼ�������ΪClip���ݼ�*/
#define	UGS_IMAGE_CLIP_FAILED                   21010	/*! Ӱ����ò���ʧ�ܣ�*/
#define	UGS_ERASE_DT                            21011	/*! Erase���ݼ�*/
#define	UGS_ERASING_DT                          21012	/*! ����Erase���ݼ�...*/
#define	UGS_JUST_REGION_ERASE                   21013	/*! ֻ�������ݼ�������ΪErase���ݼ�*/
#define	UGS_INTERSECT_DT                        21014	/*! Intersect���ݼ�*/
#define	UGS_INTERSECTING_DT                     21015	/*! ����Intersect���ݼ�...*/
#define	UGS_JUST_REGION_INTERSECT               21016	/*! ֻ�������ݼ�������ΪIntersect���ݼ�*/
#define	UGS_IDENTITY_DAT                        21017	/*! Identity���ݼ�*/
#define	UGS_IDENTITYING_DT                      21018	/*! ����Identity���ݼ�...*/
#define	UGS_JUST_REGION_IDENTITY                21019	/*! ֻ�������ݼ�������ΪIdentity���ݼ�*/
#define	UGS_UNION_DT                            21020	/*! Union���ݼ�*/
#define	UGS_UNIONING_DT                         21021	/*! ����Union���ݼ�...*/
#define	UGS_JUST_REGION_UNION                   21022	/*! ֻ�������ݼ�������ΪUnion���ݼ�*/
#define	UGS_FAILED_IN_OVERLAY_COMPUTING         21023	/*! Overlay�����г�������*/
#define	UGS_OVERLAY_RESULT_DT_MUST_BE_EMPTY     21024	/*! ������ŵ��Ӳ�����������ݼ�����Ϊ��*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_INTERSECTION 21025	/*! ֻ�ж�������ݼ�������Ϊ����������ݼ���*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_ERASE_DT 21026	/*! ֻ�ж�������ݼ�������Ϊ�������ݼ���*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_CLIP     21027	/*! ֻ�ж�������ݼ�������Ϊ�ü����ݼ���*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_IDENTITY_DT 21028	/*! ֻ�ж�������ݼ�������Ϊͬһ��������ݼ���*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_UNION    21029	/*! ֻ�ж�������ݼ�������Ϊ�ϲ���������ݼ���*/
#define	UGS_PROCESSING                          21030	/*! ���ڴ���...*/
#define	UGS_DT_INTERSECTING                     21031	/*! ���ݼ�������...*/
#define	UGS_DT_IDENTITYING                      21032	/*! ���ݼ�ͬһ����...*/
#define	UGS_DT_UNIONNING                        21033	/*! �ϲ����ݼ�...*/
#define	UGS_DT_CLIPPING                         21034	/*! �ü����ݼ�...*/
#define	UGS_DT_ERASING                          21035	/*! �������ݼ�...*/
#define	UGS_NOT_SUPPORT_DT_TYPE                 21036	/*! �������������ݼ����е��Ӳ���*/
#define	UGS_FAILD_TO_QUERY_DT                   21037	/*! ��ѯ���ݼ�ʧ��*/
#define	UGS_CLIP_NO_INTERSECTION                21038	/*! ���ñ߽��Ӱ��߽�û���ཻ���֣����ò���ʧ�ܣ�*/
#define	UGS_ONLY_DISSOLVE_REGION_AND_LINE       21039	/*! ����ֻ��������������ݼ���*/
#define	UGS_TOO_SMALL_BUFFER                    21040	/*! ���ٵĻ�����̫С��*/
#define	UGS_SM_MSG_ONLY_DISSOLVE_TYPE           21041	/*! �������ݼ����Ͳ��Ϸ�*/
#define	UGS_SM_MSG_TOPO_DISSOLVING              21042	/*! ���ںϲ��ֶ�ֵ��ͬ�Ķ���...*/
#define	UGS_MSG_MERGING_LINE_DISSOLVE           21043	/*! ������*/


// ���˴�����Ϣ����22000��ʼ����
#define	UGS_TOPO_ERROR                          22000	/*! Դ�������ݼ����˹�ϵ����*/
#define	UGS_NO_MATCHING_ARC                     22001	/*! û��ƥ�仡��*/
#define	UGS_NO_DEMAND_NODE_OR_NO_CENTERS        22002	/*! û��������û�����ĵ�*/
#define	UGS_FOUND_REPEATE_VERTEX                22003	/*! �����ظ����㣬����������ԣ�*/
#define	UGS_ARC_DATA_READING_ERROR              22004	/*! �������ݶ�ȡ����*/
#define	UGS_FOUND_A_ERROR_PESUDO_NODE           22005	/*! ����һ������ļٽ�㣺*/
#define	UGS_THIS_IS_A_TOPO_ERROR                22006	/*! ���˴���*/
#define	UGS_FOUND_A_DANGLE_NODE                 22007	/*! ����һ������㣡*/
#define	UGS_ARCS_NUMBER_OF_POLYGON_IS_MROE_THAN_TOTAL_ARCS_NUMBER 22008	/*! �ö���λ������Ѿ������ܻ�������*/
#define	UGS_STEP_1_CLEANING_REDUDANCE_VERTEXES  22009	/*! �޳������(%d/%d)......*/
#define	UGS_DELETED_LINES_AND_VERTEXES          22010	/*! ��ȥ��%d���߶���%d������� */
#define	UGS_TOTAL_DELETED_REPEATE_LINES         22011	/*! ��ɾ��%d���ظ���ͼԪ��*/
#define	UGS_TOTAL_DELETED_DANGLE_LINES          22012	/*! ��ȥ��%d�������ߡ�*/
#define	UGS_TOTAL_DELETED_SMALL_POLYGON         22013	/*! ��ɾ��%d��С����Ρ�*/
#define	UGS_TOTAL_MERGED_PSEUDO_NODES           22014	/*! ���ϲ�%d���ٽ�㡣*/
#define	UGS_STEP_2_EXTENDING_LONG_DANGLE_LINE   22015	/*! ���쳤����(%d/%d)...*/
#define	UGS_THIS_IS_A_FATA_TOPO_ERROR           22016	/*! �������˴���*/
#define	UGS_STEP_2_INTERSECT_ALL_LINES          22017	/*! ���㽻��(%d/%d)...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINES          22018	/*! ȥ�ظ���Ԥ����(%d/%d)...*/
#define	UGS_TOTAL_DELETED_SMALL_LINES           22019	/*! �ںϲ��ڽ����Ĺ����У�ͬʱɾ����%d�����ߣ�*/
#define	UGS_ASK_EXTENDED_AERO_LENGTH            22020	/*! ��������쳤�Ȳ���Ϊ�㣡*/
#define	UGS_STEP_3_LINE_NET_BUILD               22021	/*! ��������ͼ��(%d/%d)...*/
#define	UGS_ERROR_SEARCHING_NEXT_ARC            22022	/*! �ڲ��ҵ�ǰ����ε���һ������ʱ���� �û����Ѿ��������������ʹ�á�*/
#define	UGS_ERROR_SEARCHING_NEXT_NODE           22023	/*! ���������ʱ����*/
#define	UGS_ASK_CONTINUE                        22024	/*! ������*/
#define	UGS_TOPO_ERROR_LINE_SID                 22025	/*! ���˴����߼�¼���Ϊ��%d */
#define	UGS_MSG_BUILDING_POLYGONS               22026	/*! ���ڴ������˶����*/
#define	UGS_MSG_CLEARING_REPEATE_LINES          22027	/*! ����ظ���*/
#define	UGS_MSG_NODE_IDENTIFYING                22028	/*! �ڵ����*/
#define	UGS_MSG_MERGING_PSEUDO_NODE             22029	/*! �ϲ��ٽڵ�*/
#define	UGS_MSG_MERGING_CLOSE_NODE              22030	/*! �ϲ��ٽ��ڵ�*/
#define	UGS_MSG_EXTENDING_DANGLE_LINES          22031	/*! ����������*/
#define	UGS_MSG_INTERSECTING                    22032	/*! ������*/
#define	UGS_MSG_CREATING_TOPO_ERROR_INFO        22033	/*! �������˴�����Ϣ*/
#define	UGS_MSG_CLEARING_SMALL_DANGLE           22034	/*! ���������*/
#define	UGS_MSG_CLEAR_SHORT_LINE_IS_ZERO        22035	/*! �����ߵľ�����ڻ�С����*/
#define	UGS_MSG_CLEAR_REDUNDANCE_LINE_IS_ZERO   22036	/*! �����ľ�����ڻ�С����*/
#define	UGS_MSG_MERGE_CLOSE_NODE                22037	/*! �ٽ��ڵ�ľ�����ڻ�С����*/
#define	UGS_MSG_POLYLINE_PREPROCESS             22038	/*! ��Ԥ����*/
#define	UGS_MSG_MAKE_TOPO_POLYLINE              22039	/*! ��ȡ������*/


// ���ֵ���ģ�ͣ�DEM��������Ϣ����23000��ʼ����
#define	UGS_MAP_ALTIMETER                       23000	/*! �߶ȱ�(m)*/
#define	UGS_ERROR_SWITCH                        23001	/*! ��������TINʱ����ʹ�� -I ����*/
#define	UGS_DTM_MSG_TIN_TO_DEM                  23002	/*! �Ӳ������������������ָ߳�ģ��*/
#define	UGS_DTM_MSG_CREATE_DEM                  23003	/*! ����DEM*/
#define	UGS_DTM_MSG_READ_POINT                  23004	/*! ���ڶ�ȡ�̵߳�*/


// �������洦����Ϣ����24000��ʼ����
#define	UGS_UDB_NOT_SUPPORT_RELEASEPYRAMIDDATASETS 24000	/*! UDB ���治֧�����²���:ReleasePyramidDatasets()*/
#define	UGS_UDB_NOT_SUPPORT_TIER                24001	/*! UDB ���治֧�����²���:Tier()*/
#define	UGS_UDB_NOT_SUPPORT_BULIDPYRAMID        24002	/*! UDB ���治֧�����²���:BuildPyramid()*/
#define	UGS_UDB_NOT_SUPPORT_REMOVEPYRAMIDS      24003	/*! UDB ���治֧�����²���:RemovePyramids()*/
#define	UGS_UDB_NOT_SUPPORT_CALCAVGVALUE        24004	/*! UDB ���治֧�����²���:CalcAvgValue()*/
#define	UGS_DATASET_NOT_OPEN_OR_DATASOURCE_READ_ONLY 24005	/*! ���ݼ�û�д򿪻�����ԴΪֻ��*/
#define	UGS_DATASET_NOT_OPEN_OR_CANNOT_OPEN     24006	/*! ���ݼ�û�д򿪻��޷���*/
#define	UGS_IMAGE_BLOCK_SIZE_IS_ZERO            24007	/*! Ӱ���ߴ�Ϊ0*/
#define	UGS_UDB_NOT_SUPPORT_GETLOCKEDUSERID     24008	/*! UDB ���治֧�����²���:GetLockedUserID()*/
#define	UGS_UDB_NOT_SUPPORT_CREATE              24009	/*! UDB ���治֧�����²���:Create()*/
#define	UGS_UDB_NOT_SUPPORT_COMPUTERECCOUNT     24010	/*! UDB ���治֧�����²���:ComputeRecCount()*/
#define	UGS_UDB_NOT_SUPPORT_RESAMPLE            24011	/*! UDB ���治֧�����²���:Resample()*/
#define	UGS_UDB_NOT_SUPPORT_REGISTEROPTION      24012	/*! UDB ���治֧�����²���:RegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_UNREGISTEROPTION    24013	/*! UDB ���治֧�����²���:UnRegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_GETCACHEFILE        24014	/*! UDB ���治֧�����²���:GetCacheFile()*/
#define	UGS_UDB_NOT_SUPPORT_COPYFIELD           24015	/*! UDB ���治֧�����²���:CopyField()*/
#define	UGS_NOT_FIND_FILED_WITH_THIS_ID         24016	/*! �Ҳ�����ID�ֶ�*/
#define	UGS_CURRENT_CURSOR_POS_ILLEGAL          24017	/*! ��ǰ���α�λ�÷Ƿ�*/
#define	UGS_UDB_NOT_SUPPORT_GETGEOMETRYDIRECT   24018	/*! UDB ���治֧�����²���:GetGeometryDirect()*/
#define	UGS_UDB_NOT_SUPPORT_FINDFIRST           24019	/*! UDB ���治֧�����²���:FindFirst()*/
#define	UGS_UDB_NOT_SUPPORT_FINDLAST            24020	/*! UDB ���治֧�����²���:FindLast()*/
#define	UGS_UDB_NOT_SUPPORT_FINDNEXT            24021	/*! UDB ���治֧�����²���:FindNext()*/
#define	UGS_UDB_NOT_SUPPORT_FINDPREV            24022	/*! UDB ���治֧�����²���:FindPrev()*/
#define	UGS_UDB_NOT_SUPPORT_SETGEOMETRY         24023	/*! UDB ���治֧�����²���:SetGeometry*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUE       24024	/*! UDB ���治֧�����²���:SetFieldValue*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUENULL   24025	/*! UDB ���治֧�����²���:SetFieldValueNull*/
#define	UGS_NO_GEOMETRY_ELEMENT_OR_CANNOT_OPEN_DATASET 24026	/*! û�м���Ԫ�ػ��޷������ݼ�*/
#define	UGS_UDB_NOT_SUPPORT_LOCK                24027	/*! UDB ���治֧�����²���:Lock()*/
#define	UGS_UDB_NOT_SUPPORT_UNLOCK              24028	/*! UDB ���治֧�����²���:UnLock()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUT        24029	/*! UDB ���治֧�����²���:UndoCheckOut()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUTCURRENT 24030	/*! UDB ���治֧�����²���:UndoCheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKINCURRENT      24031	/*! UDB ���治֧�����²���:CheckInCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUTCURRENT     24032	/*! UDB ���治֧�����²���:CheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKIN             24033	/*! UDB ���治֧�����²���:CheckIn()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUT            24034	/*! UDB ���治֧�����²���:CheckOut()*/
#define	UGS_ENG_INVALID_DEST_DS                 24035	/*! Ŀ������Դ�Ƿ�*/
#define	UGS_ENG_GET_POINT_FROM_DT               24036	/*! ���ڴ����ݿ���ȡ��...*/
#define	UGS_ENG_CANNOT_CHANGE_PWD_SHAREMODE     24037	/*! ����򿪷�ʽ�����޸����룡*/
#define	UGS_ENG_INVALID_DATA_FORMAT             24038	/*! ��SuperMap��ʽ���ļ����ļ�ϵͳ���ƻ�*/
#define	UGS_ENG_READONLY                        24039	/*! ֻ�������ܽ����޸Ĳ�����*/
#define	UGS_ENG_CANNOT_WATCH_DS                 24040	/*! ����Դ�Ѿ�������û��Զ�ռ��ʽ�򿪣���û�в鿴���ݵ�Ȩ�ޡ�*/
#define	UGS_ENG_CANNOT_OPEN_READONLY_3001       24041	/*! 3001�汾����ֻ����*/
#define	UGS_ENG_CONNECT_STRING_ERROR            24042	/*! ��������Դ�ִ��Ƿ���*/
#define	UGS_ENG_OPEN_DATASOURCE_FAILED          24043	/*! ����Դ��ʧ��*/
#define	UGS_ENG_DATASOURCE_CONNECT_FAILED       24044	/*! ���ݿ�����ʧ�ܣ���������Դ���Ӳ���*/
#define	UGS_ENG_INVALID_DT                      24045	/*! ���ݼ���Ч*/
#define	UGS_ENG_SAMENAME_DT_EXIST               24046	/*! ͬ�����ݼ��Ѿ����ڣ�*/
#define	UGS_ENG_CANNOT_COPY_BETWEEN_ENGINE      24047	/*! �����ڲ�ͬ��������¡ECW��MrSID���ݼ�*/
#define	UGS_ENG_REPLACE_DATASET_NAME            24048	/*! Ҫ���������ݼ������ִ�(%s)����Ϊ(%s)*/
#define	UGS_ENG_CREATE_DATASET_FAILED2          24049	/*! �������ݼ�(����:%s;����:%d)ʧ��*/
#define	UGS_ENG_EMPTY_RS                        24050	/*! ��ǰ��¼��Ϊ��*/
#define	UGS_ENG_CANNOT_UPDATE                   24051	/*! ��û��AddNew��Edit��״̬�²���Update��*/
#define	UGS_ENG_TOO_SMALL_POLYGON               24052	/*! �ܳ�Ϊ0�������Ϊ0�Ķ���ζ�������ӵ���¼���С�*/
#define	UGS_ENG_TOO_SHORT_LINE                  24053	/*! ����Ϊ0���߶�������ӵ���¼���С�*/
#define	UGS_ENG_ADD_TO_RECORDSET                24054	/*! ������¼����Ӽ�¼\"%s\"...*/
#define	UGS_ENG_REPLACE_FIELD_NAME              24055	/*! Ҫ�������ֶε����ִ�(%s)����Ϊ(%s)*/
#define	UGS_ENG_CLOSE_ALL_RECORDSET             24056	/*! ���ռ�����ǰ��ر����еļ�¼����*/
#define	UGS_ENG_ERROR_SQL_STATEMENT             24057	/*! �����SQL��ѯ��䣡*/
#define	UGS_ENG_SPATIAL_QUERY_NO_GEODATA        24058	/*! �ռ��ѯû�м��ζ���*/
#define	UGS_ENG_LONG_TRANS_NOT_LOGIN            24059	/*! �������û�û�е�¼��*/
#define	UGS_ORAPLUS_NOSUPPORT_DATATYPE          24060	/*! ������������Oracle����Ŀǰ��֧�֡�*/
#define	UGS_PREPARE_CREATE_DS                   24061	/*! ׼����������Դ...*/
#define	UGS_CREATE_DS_SUCCESS                   24062	/*! ��������Դ�ɹ�!*/
#define	UGS_PREPARE_OPEN_DS                     24063	/*! ׼��������Դ...*/
#define	UGS_OPEN_DS_SUCCESS                     24064	/*! ������Դ�ɹ�!*/
#define	UGS_PREPARE_CLOSE_DS                    24065	/*! �ر�����Դ...*/
#define	UGS_CREATE_TABLE_SUCCESS                24066	/*! ����&lt;%s&gt;��ɹ�...*/
#define	UGS_ROLLBACK_TRANS                      24067	/*! �ع�����*/
#define	UGS_READING_INFO_OF_VDT                 24068	/*! ���ڶ�ȡʸ�����ݼ�&lt;%s&gt;�������Ϣ...	*/
#define	UGS_READING_INFO_OF_RDT                 24069	/*! ���ڶ�ȡդ�����ݼ�&lt;%s&gt;�������Ϣ...*/
#define	UGS_LOGIN_LONGTRANS                     24070	/*! ��¼����Դ(%s)�ĳ����񻷾�*/
#define	UGS_LOGOUT_LONGTRANS                    24071	/*! �˳�����Դ(%s)�ĳ����񻷾�*/
#define	UGS_LONGTRANS_LOCK_DATA                 24072	/*! {%s}��������ʽ��������*/
#define	UGS_LONGTRANS_UNLOCK_DATA               24073	/*! {%s}��������ʽ��������*/
#define	UGS_LONGTRANS_ROLLBACK                  24074	/*! {%s}��������ʽ�ع�����	*/
#define	UGS_CREATE_VDT                          24075	/*! ����ʸ�����ݼ���%s*/
#define	UGS_CREATE_RASTER                       24076	/*! ����դ�����ݼ���%s*/
#define	UGS_DELETE_DT                           24077	/*! ɾ�����ݼ���%s*/
#define	UGS_VDT_APPEND                          24078	/*! ��ʸ�����ݼ� (%s) ��׷�Ӽ�¼*/
#define	UGS_VDT_BUILD_SPATIAL_INDEX             24079	/*! Ϊʸ�����ݼ� (%s) �����ռ����� ... ...	*/
#define	UGS_VDT_COMPUTE_BOUNDS                  24080	/*! Ϊʸ�����ݼ� ( %s ) ���㷶Χ...*/
#define	UGS_VDT_CREATE_FIELD                    24081	/*! Ϊʸ�����ݼ� ( %s ) �����ֶ� ( %s ) ...*/
#define	UGS_VDT_DELETE_FIELD                    24082	/*! Ϊʸ�����ݼ�( %s ) ɾ���ֶ� ( %s )*/
#define	UGS_VDT_CREATE_INDEX                    24083	/*! Ϊʸ�����ݼ� (%s) �����ֶ����� ( %s )*/
#define	UGS_VDT_REMOVE_INDEX                    24084	/*! Ϊʸ�����ݼ� ( %s ) �Ƴ����� ( %s ) */
#define	UGS_VDT_RENAME                          24085	/*! ��ʸ�����ݼ� ( %s ) ������Ϊ��( %s )*/
#define	UGS_VDT_RESET_BOUNDS                    24086	/*! ʸ�����ݼ�( %s )����Bounds��*/
#define	UGS_VDT_MODIFY_FIELD_INFO               24087	/*! ʸ�����ݼ� ( %s ) : �޸��ֶ� ( %s ) �������Ϣ*/
#define	UGS_RS_ADD_RECORDSET                    24088	/*! ���ݼ�(%s)�ļ�¼�������һ����¼*/
#define	UGS_RS_DELETE_A_RECORDSET               24089	/*! ���ݼ�(%s)�ļ�¼��ɾ����һ����¼*/
#define	UGS_RS_MODIFY_RECORDSET                 24090	/*! ���ݼ�(%s)�ļ�¼���޸���һ����¼*/
#define	UGS_COMPUTE_EXTREMUM                    24091	/*! �����ֶ� %s �ļ�ֵ*/
#define	UGS_OPEN_VDT                            24092	/*! ��ʸ�����ݼ� (%s)�ɹ���*/
#define	UGS_CLOSE_VDT                           24093	/*! �ر�ʸ�����ݼ�(%s)*/
#define	UGS_CONNECT_DS                          24094	/*! ����Դ{%s}���ӵ����ݿ�*/
#define	UGS_COPY_DT                             24095	/*! ����Դ{%s}�������ݼ�{%s}*/
#define	UGS_VDT_ADD_METADATADESC                24096	/*! ʸ�����ݼ�(%s)���Ԫ����*/
#define	UGS_VDT_LONGTRAN_CHECKIN                24097	/*! ʸ�����ݼ�(%s)��������ʽ�ύ�޸�	*/
#define	UGS_VDT_LONGTRAN_LOCK                   24098	/*! ʸ�����ݼ�(%s)��������ʽ������¼*/
#define	UGS_VDT_CLEAR_METADATA                  24099	/*! ʸ�����ݼ�(%s)���Ԫ����*/
#define	UGS_VDT_COPYFIELD                       24100	/*! ʸ�����ݼ�(%s)�����ֶ�(%s)*/
#define	UGS_VDT_DELETE_METADATA_NODE            24101	/*! ʸ�����ݼ�(%s)ɾ��Ԫ���ݽڵ�*/
#define	UGS_OPEN_RDT                            24102	/*! ��դ�����ݼ�(%s)�ɹ�*/
#define	UGS_CLOSE_RDT                           24103	/*! �ر�դ�����ݼ�(%s)*/
#define	UGS_RDT_CREATEECW                       24104	/*! ����ECW�ļ�(%s)���ⲿ����*/
#define	UGS_RDT_CREATE_MRSID                    24105	/*! ����MrSID�ļ�(%s)���ⲿ����*/
#define	UGS_RDT_RESET                           24106	/*! դ�����ݼ�(%s)ͼ�����*/
#define	UGS_VDT_TRUNCATE                        24107	/*! ʸ�����ݼ�(%s)�������*/
#define	UGS_RDT_RELEASE_PYRAMID                 24108	/*! դ�����ݼ�(%s)�ͷ�Ӱ����������ݼ�*/
#define	UGS_RDT_ADD_METADATA                    24109	/*! դ�����ݼ�(%s)���Ԫ����*/
#define	UGS_RDT_CLEAR_METADATA                  24110	/*! դ�����ݼ�(%s)���Ԫ����*/
#define	UGS_RDT_DELETE_METADATA                 24111	/*! դ�����ݼ�(%s)ɾ��Ԫ���������Ľڵ�*/
#define	UGS_RDT_REMOVE_PYRAMUGS                 24112	/*! դ�����ݼ�(%s)ɾ��Ӱ�������*/
#define	UGS_RDT_BUILD_PYRAMID                   24113	/*! դ�����ݼ�(%s)����Ӱ�������*/
#define	UGS_RS_DELETE_ALL                       24114	/*! ��¼��ɾ�����м�¼*/
#define	UGS_VDT_LONGTRAN_UNDO_LOCK              24115	/*! ʸ�����ݼ�(%s) ��������ʽȡ������*/
#define	UGS_VDT_SET_FIELD_PROPTY                24116	/*! ʸ�����ݼ�(%s) �����ֶ�(%s) ����	*/
#define	UGS_VDT_UPDATE_FIELD                    24117	/*! ʸ�����ݼ�(%s) �����ֶ�(%s) ����*/
#define	UGS_LOG_RS_LOCK                         24118	/*! ����¼����ѯ��������û�б����������ļ�¼����*/
#define	UGS_RS_UNDO_MODIFY                      24119	/*! �����Ե�ǰ��¼���������޸�*/
#define	UGS_LOG_RS_MODIFY_CURRENT               24120	/*! �ύ�Ե�ǰ��¼�������޸�*/
#define	UGS_RS_LOCK_CURRENT                     24121	/*! ������ǰ��¼*/
#define	UGS_RS_UNDO_MODIFY_CURRENT              24122	/*! �����Ե�ǰ��¼�������޸�*/
#define	UGS_RS_COPY_FIELD                       24123	/*! ��¼�������ֶ�(%s)*/
#define	UGS_RS_MODIFY_FIELD_VALUE               24124	/*! ��¼���޸ĵ�ǰ�����ֶ�ֵ*/
#define	UGS_RS_MODIFY_GEOMETRY                  24125	/*! ��¼���޸ĵ�ǰ�ռ�����*/
#define	UGS_VDT_QUERY_FIELD_INFOS               24126	/*! ʸ�����ݼ�(%s) ��ѯ�ֶμ���*/
#define	UGS_VDT_STATISTIC                       24127	/*! ʸ�����ݼ�(%s)ִ��ͳ�Ʋ���*/
#define	UGS_VDT_COMPUTE_EXTREMUM                24128	/*! ʸ�����ݼ�(%s) ���㼫ֵ*/
#define	UGS_VDT_COMPUTE_BOUNDARY                24129	/*! ʸ�����ݼ�(%s) ����߽�*/
#define	UGS_RDT_SAVE_TO_BLOCK                   24130	/*! դ�����ݼ�(%s) ����Ӱ�����ݵ��洢�豸*/
#define	UGS_RDT_LOAD_IMAGE                      24131	/*! դ�����ݼ�(%s) ��ȡӰ������*/
#define	UGS_RS_FIND_FIRST                       24132	/*! ��¼������Ƶ���һ��λ��*/
#define	UGS_RS_FIND_LAST                        24133	/*! ��¼������Ƶ����һ��λ��*/
#define	UGS_RS_FIND_NEXT                        24134	/*! ��¼������Ƶ���һ��λ��*/
#define	UGS_RS_FIND_PREV                        24135	/*! ��¼������Ƶ�ǰһ��λ��*/
#define	UGS_RS_SEEK_BY_ID                       24136	/*! ����ID�ƶ���¼�����*/
#define	UGS_RS_STATISTIC                        24137	/*! ��¼��ִ��ͳ�Ʋ���*/
#define	UGS_RS_QUERY_WITH_BOUNDS                24138	/*! ��¼��ִ��Bounds��ѯ*/
#define	UGS_RS_QUERY_WITH_GENERAL               24139	/*! ��¼��ִ����ͨ��ѯ*/
#define	UGS_RS_QUERY_WITH_IDS                   24140	/*! ��¼��ִ��IDS��ѯ*/
#define	UGS_RS_QUERY_WITH_SPATIAL               24141	/*! ��¼��ִ�пռ��ѯ*/
#define	UGS_RS_COMPUTE_BOUNDS                   24142	/*! ��¼������߽�*/
#define	UGS_RS_FLUSH_CURRENT_RECORDSET          24143	/*! ��¼���ύ��ǰ��¼���洢�豸*/
#define	UGS_RS_UPDATING                         24144	/*! ��¼������ִ�и��²���...*/
#define	UGS_RS_UPDATE                           24145	/*! ��¼�����³ɹ�*/
#define	UGS_CREATE_DT                           24146	/*! ����Դ(%s)�������ݼ�(%s)*/
#define	UGS_DS_CONNECT                          24147	/*! ����Դ(%s)��������*/
#define	UGS_RDT_RENAME                          24148	/*! ��դ�����ݼ� (%s) ������Ϊ (%s)	*/
#define	UGS_FIELD_NAME                          24149	/*! �ֶ���*/
#define	UGS_FIELD_TYPE                          24150	/*! �ֶ�����*/
#define	UGS_FIELD_SIZE                          24151	/*! �ֶδ�С*/
#define	UGS_ERROR_TOO_SMALL_REGION              24152	/*! �ܳ�Ϊ0�������Ϊ0�Ķ���ζ�������ӵ����ݼ��С�*/
#define	UGS_ERROR_TOO_SHORT_LINE                24153	/*! ����Ϊ0���߶�������ӵ����ݼ��С�*/
#define	UGS_INVALID_ROW_OR_COLUMN               24154	/*! ��Ч��������*/
#define	UGS_FAILED_TO_OPEN_DT                   24155	/*! �����ݼ�ʧ��*/
#define	UGS_INVALID_DS_PATH                     24156	/*! ����Դ·���Ƿ�*/
#define	UGS_RS_NOT_EXIST                        24157	/*! ��¼��������*/
#define	UGS_RS_IS_EMPTY                         24158	/*! �ռ�¼��*/
#define	UGS_DT_IS_EMPTY                         24159	/*! �����ݼ�*/
#define	UGS_TYPE_MISMATCH_BETWEEN_RS_AND_DT     24160	/*! ���ݼ��ͼ�¼�������Ͳ�ƥ��*/
#define	UGS_FAILED_TO_CREATE_FIELDS             24161	/*! �����ֶ�ʧ��*/
#define	UGS_DT_NAME_ALREADY_EXIST               24162	/*! ͬ�������ݼ��Ѵ���*/
#define	UGS_DT_WITH_SPECIFIED_NAME_NOT_EXIST    24163	/*! ָ�����ֵ����ݼ�������*/
#define	UGS_DUPLICATED_PARAMETERS_FOUND         24164	/*! ��������������ͬ*/
#define	UGS_FAILED_TO_SEARCH_FIELD_INFO         24165	/*! �����ֶ���Ϣʧ��*/
#define	UGS_MISMATCH_SOURCE_DT_AND_TARGET_DT    24166	/*! Դ���ݼ���Ŀ�����ݼ������ͱ�����ͬ*/
#define	UGS_CREATE_DT_ERROR                     24167	/*! ���������ݼ�ʧ�ܣ�*/
#define	UGS_INVALID_PASSWORD                    24168	/*! �������*/
#define	UGS_DISSOLVING                          24169	/*! ���ںϲ��ֶ�ֵ��ͬ���ڽӶ���...*/
#define	UGS_JOINTING_TABLE                      24170	/*! ���������������ݱ�...*/
#define	UGS_ALL_FIELD_IN_CURRENT_DT             24171	/*! ��ǰ���ݼ�������Ҫ���ӵ����ݱ�������ֶΣ�����Ҫ�����ӡ�*/
#define	UGS_NAME_NULL                           24172	/*! ���Ʋ���Ϊ��!*/
#define	UGS_NAME_BEYOND_LIMIT                   24173	/*! ���Ƴ����˹涨�ַ�����!*/
#define	UGS_NAME_AGAIN_SYSTEMNAME               24174	/*! ���Ʋ�����ϵͳ�����ֶ���ͬ!*/
#define	UGS_NAME_PREFIX_ERROR                   24175	/*! ���Ʋ��������ֻ��»��߿�ͷ!*/
#define	UGS_FIELD_NAME_ALREADY_EXISTS           24176	/*! ͬ�����ֶ��Ѵ���*/
#define	UGS_IS_BOF                              24177	/*! �ѵ���¼ͷ������ִ����ز�����*/
#define	UGS_IS_EOF                              24178	/*! �ѵ���¼β������ִ����ز�����*/
#define	UGS_HAS_NO_GEOMETRY                     24179	/*! ��ǰ��¼���������ռ����ݣ�����ִ�пռ�������ز�����*/
#define	UGS_DT_NOT_OPEN                         24180	/*! ��ǰ���ݼ�û�д򿪡�*/
#define	UGS_QUERY_GEOMETRY_ON_TABULAR           24181	/*! ��ͼ��Tabular���в�ѯ�ռ�����ʱ����*/
#define	UGS_DS_IS_NOT_OPEN                      24182	/*! ����Դû�д򿪣�����ִ����ز�����*/
#define	UGS_DS_INFO_IS_NOT_INTEGRATED           24183	/*! ��������Դ�ַ����Ƿ���*/
#define	UGS_OUT_OF_SEMICOLON                    24184	/*! ȱʧ�ֺ�(;)*/
#define	UGS_OUT_OF_EQUAL                        24185	/*! ȱʧ�Ⱥ�(=)*/
#define	UGS_RS_IS_NOT_OPEN                      24186	/*! ��¼��û�д򿪡�*/
#define	UGS_QUERY_OPTION_IS_NONE                24187	/*! ��ѯѡ�����*/
#define	UGS_CANT_COPY_DT_FROM_IMGPLUGINS        24188	/*! ���ܴ����Ӱ�������и������ݼ�*/
#define	UGS_DELETE_TABLE_FAILED                 24189	/*! ɾ����ʧ��*/
#define	UGS_DELETE_DT_REGISTER_INFO_FAILED      24190	/*! ɾ��ע�����Ϣʧ��*/
#define	UGS_DELETE_DT_METADATA_FAILED           24191	/*! ɾ��Ԫ����ʧ��*/
#define	UGS_DELETE_SEQUENCE_FAILED              24192	/*! ɾ������ʧ��*/
#define	UGS_DELETE_SPATIAL_INDEX_FAILED         24193	/*! ɾ���ռ�������ʧ��*/
#define	UGS_DELETE_PYRAMUGS_TABLE_FAILED        24194	/*! ɾ����������ʧ��*/
#define	UGS_DELETE_PYRAMUGS_DT_REGISTER_INFO_FAILED 24195	/*! ɾ��ע����н�������Ϣʧ��*/
#define	UGS_DELETE_PYRAMUGS_DT_MetaData_FAILED  24196	/*! ɾ��������Ԫ����ʧ��*/
#define	UGS_CANNT_CREATE_ECW_OR_MRSID_BY_TEMPLATE 24197	/*! ECW��MRSID���ݼ�������ģ�崴��*/
#define	UGS_CANNT_COPY_NETWORK_OR_LINEZ_OR_LINEM_OR_POINTZ_BETWEEN_SDB_AND_SQLSERVER 24198	/*! ���ܴ�SDB��SQLSERVER����Դ����LineZ��LineM��PointZ��Network���ݼ�*/
#define	UGS_INVALID_FIELD_NAME_LENGTH           24199	/*! �ֶ�(%s)���ȴ���30,����ʧ��*/
#define	UGS_DT_APPEND_FAILED_WITH_EXCEPTION     24200	/*! ���ݼ�׷���쳣����ֹ*/
#define	UGS_SMETAB_ENGINE_NAME                  24201	/*! SuperMap MicroStation ����.*/
#define	UGS_SMETAB_MSG_INVALID_SQL_SENTENCE     24202	/*! �����SQL��ѯ���!*/
#define	UGS_AUTOCAD_ENGINE_NAME                 24203	/*! SuperMap AutoCAD��������*/
#define	UGS_ORCPLUS_ENGINE_NAME                 24204	/*! SDX+ for Oracle	*/
#define	UGS_ORCPLUS_NOT_SUPPORT_TYPE            24205	/*! SDX+ for Oracle ����Ŀǰ����֧���������͵����ݼ���*/
#define	UGS_ORCPLUS_DB_VERSION_ERROR            24206	/*! ��ǰ��SDX Plus for ORACLE��֧�ְ汾��%ld������Դ�����SuperMap����֧����ϵ(support@supermap.com)��*/
#define	UGS_ORCPLUS_SYSTEMUSER_NOT_CREATE_DATASOURCE 24207	/*! ϵͳĬ���û����ɴ���SUPERMAP����Դ*/
#define	UGS_ORACLEPLUS_NOT_LOG_IN               24208	/*! �������û�û�е�½��*/
#define	UGS_ORAPLUS_RECORD_IS_CHECKED_BY_OTHERS 24209	/*! ��ǰ��¼������������*/
#define	UGS_PREPARE_CREATE_DB                   24210	/*! ׼���������ݼ�...	*/
#define	UGS_CONNECT_TO_SERVER                   24211	/*! ���ӵ�������...*/
#define	UGS_CREATING_SYSTEM_TABLE               24212	/*! ����ϵͳ�� %s ...*/
#define	UGS_CREATING_TEMP_TABLE                 24213	/*! ������ʱ�� %s ...*/
#define	UGS_SETING_DB_INFO                      24214	/*! ��������Դ��Ϣ...*/
#define	UGS_ORACLE_SPATIAL_ENGINE_NAME          24215	/*! Oracle Spatial ����	*/
#define	UGS_SPATIAL_DB_ENGINE                   24216	/*! SuperMap �ռ���������(SDB)*/
#define	UGS_MSG_SDB_DATA_CONVERT                24217	/*! ת���� %d����¼*/
#define	UGS_MSG_CLOSE_OPENED_RS                 24218	/*! ���ȹر������Ѿ��򿪵ļ�¼��(recordset)!*/
#define	UGS_COMPACTING_DATASET                  24219	/*! ���ڽ������ݼ�*/
#define	UGS_SDBPLUS_ENGINE                      24220	/*! SuperMap �ռ����ݿ�����(SDB 5)*/
#define	UGS_MSG_SDBPLUS_INVALID_DATASET         24221	/*! �������ݼ�������������ռ����ݲ�һ�£����ݼ��ѻ���*/
#define	UGS_MSG_SDBPLUS_DATA_CONVERT            24222	/*! ת���� %d����¼*/
#define	UGS_SQL_ENGINE_NAME                     24223	/*! SDX for SQL Server*/
#define	UGS_SQL_NOT_SUPPORT_TYPE                24224	/*! SDX for SQL Server ����Ŀǰ����֧���������͵����ݼ���*/
#define	UGS_SQL_DATABASE_VERSION_ERROR          24225	/*! ��ǰ��SDX for SQL SERVER��֧�ְ汾��Ϊ%s������Դ�����SuperMap��ϵ.*/
#define	UGS_SQL_RECORD_IS_CHECKED_BY_OTHERS     24226	/*! ��ǰ��¼���������û�����������ִ�б༭������*/
#define	UGS_SQL_NOT_LOG_IN                      24227	/*! û�е�¼�����񻷾�������ִ����صĲ�����*/
#define	UGS_SQL_SOME_RECORDS_LOCKED_BY_OTHERS   24228	/*! һЩ��¼�������û����������Բ���ִ�����ȫ��Ĳ�����*/
#define	UGS_MSG_SQL_BUILD_QD_TREE               24229	/*! �Ѵ�����%ld����¼*/
#define	UGS_MSG_SQL_BUILDING_PYRAMID            24230	/*! ����Ӱ�������...*/
#define	UGS_IMAGE_PLUGINS_ENGINE                24231	/*! SuperMap Ӱ�������档*/
#define	UGS_OSQLPLUS_ENGINE_NAME                24232	/*! SDX+ for SQL Server(ODBC)*/
#define	UGS_DATA_VERSION_ERROR                  24233	/*! SDX+ for SQL Server����汾��֧�ִ�����汾������Դ.*/
#define	UGS_ODBC_NONSUPPORT_PYRAMID             24234	/*! ��֧�ֽ���������*/
#define	UGS_ODBC_CAN_NOT_UNRIGISTER             24235	/*! ���м�¼������������������������ȡ��������*/
#define	UGS_ODBC_NOT_LOG_IN                     24236	/*! �������û�û�е�½*/
#define	UGS_ODBC_CANNT_LOCK_TABLE               24237	/*! �������û�������¼���ܽ���ȫ�����,����:����,������.*/
#define	UGS_ODBC_NOT_AUTOLOCK                   24238	/*! �����Զ�����״̬�����ܱ༭����ӣ��������Զ�����״̬���Ҫ�޸ĵļ�¼����*/
#define	UGS_ODBC_RECORD_IS_CHECKED_BY_OTHERS    24239	/*! ��¼���������������ܱ༭*/
#define	UGS_ODBC_BE_TABLE_LOCK                  24240	/*! ��ǰ�����Ѿ���ȫ������,���ܽ���������ز���.	*/
#define	UGS_ODBC_DS_CONNECT_FAILED              24241	/*! ����Դ��������ʧ�ܣ�*/
#define	UGS_MSG_DATASOURCE_ALIAS_X_ALREADY_EXISTED 24242	/*! ����Դ����"%S"�Ѿ�����!*/
#define	UGS_MSG_MISSING_ENGINE                  24243	/*! �Ҳ�������Ϊ%d��SDX����*/
#define	UGS_MSG_DB_WORKSPACE_REQUIRE_CAPTION    24244	/*! ���ݿ�汾�Ĺ����ռ���Ҫ�����ռ����֣����߹����ռ�������*/
#define	UGS_FIELD_COUNT_TOO_SMALL               24245	/*! û�������ֶΣ�*/
#define	UGS_RECORD_NO_IS_TOO_LARGE              24246	/*! ��¼��̫��*/
#define	UGS_DMRS_LINK_NOT_SUPPORT_SET_X2        24247	/*! DMRS���ܱ����óɣ�%s��*/
#define	UGS_ERROR_COV_MKDIR                     24248	/*! ����Ŀ¼����/n*/
#define	UGS_ERROR_COV_NOSUPPORT_TYPE            24249	/*! ���Ա����ݲ�֧�ֵ��ֶ�����/n*/
#define	UGS_ERROR_COV_USERFIELDCOUNT            24250	/*! �û��ֶγ��ִ���/n*/
#define	UGS_ERROR_COV_MORE_USER_FIELD           24251	/*! �û��ֶ���Ŀ̫��/n*/
#define	UGS_ERROR_COV_CREATE_USER_FIELD         24252	/*! �����û��ֶ�ʱ����/n*/
#define	UGS_ERROR_COV_FIELDTYPE                 24253	/*! �ֶ����ʹ���/n*/
#define	UGS_MSG_PMP_SQL_NO_ENOUGH_DISKSPACE     24254	/*! �������ÿ��ٷ����������ݵ�SQL�����У������̿ռ���ܲ��㣡�Ƿ�����ÿ��ٷ����������ݣ������YES����������ÿ��ٷ����������ݣ������NO���� ��ʹ�ô�ͳ�����������ݡ�*/
#define	UGS_OUTPUTEX_MSG_CREATE_DATASET         24255	/*! ���������µ����ݼ�......*/
#define	UGS_LYT_FIELD_NAME                      24256	/*! �ֶ��� : %s*/
#define	UGS_MISMATCH_DATASET_TYPE               24257	/*! ���ݼ����Ͳ�ƥ��*/
#define	UGS_MSG_FAILED_TO_BUILD_SPATIAL_INDEX   24258	/*! �����ռ�����ʧ�ܣ�*/
#define	UGS_DTM_MSG_NO_REGION_OVERLAY           24259	/*! ���ݼ�û�з�Χ�ص�*/
#define	UGS_SET_INPUT_POLYGON_TMPLAYER          24260	/*! ���ȴ�����ʱ�����ݼ���*/
#define	UGS_IMAGE_MSG_SEARCH_ITEM               24261	/*! ����ͼ��*/
#define	UGS_IMAGE_MSG_FAILED_TO_ADD_NEW_RECORD  24262	/*! ����¼�¼ʧ��*/
#define	UGS_NOUN_EXPRESSION_CMB                 24263	/*! ���ʽ...*/
#define	UGS_FILED_OR_TABLE_NAME_IS_NULL         24264	/*! �жϴ�����ֶ���������Ƿ����ʱ�����������Ϊ��*/
#define	UGS_NAME_LENGTH_OVERRUN                 24265	/*! ���Ƴ��ȴ���30���ַ�*/
#define	UGS_WMS_VERSION_INVALID                 24266	/*! û�з��ֿ��õ�WMS�汾,�������URL������*/
#define	UGS_WFS_VERSION_INVALID                 24267	/*! û�з��ֿ��õ�WFS�汾,�������URL������*/
#define	UGS_WCS_VERSION_INVALID                 24268	/*! û�з��ֿ��õ�WCS�汾,�������URL������*/
#define	UGS_CREATING_WEBENGINE_IS_NONSUPPORT    24269	/*! �����������治֧�ִ�������*/
#define	UGS_DELETE_NONE                         24270	/*! û��ɾ���κ����ݼ�*/
#define	UGS_NOT_SUPPORT_THIS_WEB_DATASOURCE     24271	/*! ��֧�ֵĴ������͵���������Դ*/
#define	UGS_FAILED_TO_PARSE_WEB_DATASOURCE      24272	/*! ������������Դ����ʧ��*/
#define	UGS_COORDINATE_REFERENCE_IS_EMPTY       24273	/*! ����ο�ϵΪ��*/
#define	UGS_FAILED_TO_PARSE_URL                 24274	/*! URL����ʧ��*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_RASTER 24275	/*! �����������治֧�ִ���դ�����ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_TOPO 24276	/*! �����������治֧�ִ����������ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_VECTOR 24277	/*! �����������治֧�ִ���ʸ�����ݼ�*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_ROLLBACK   24278	/*! �����������治֧�ֻع�����*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_COMMIT     24279	/*! �����������治֧���ύ����*/
#define	UGS_NOT_SPECIFY_ANY_LAYERS              24280	/*! ��δָ���κ�ͼ��,�볢������SetAllLayers������*/
#define	UGS_WMS_SERVER_REPORT_AN_EXCEPTION      24281	/*! WMS������������һ���쳣*/
#define	UGS_MARKUP_NOT_FIND_CAPABILITY_TAG      24282	/*! Makup û�з���Capability��ǩ*/
#define	UGS_CAPABILITY_XML_FILE_PATH_IS_EMPTY   24283	/*! Capabilities XML�ļ�·��Ϊ��*/
#define	UGS_LAYER_ARRAY_IS_EMPTY                24284	/*! ͼ������Ϊ��*/
#define	UGS_SIZE_OF_GETMAP_IAMEGE_IS_ZERO       24285	/*! GetMap Ӱ���ļ���СΪ0*/
#define	UGS_WMS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED 24286	/*! WMS GetMap����δ�����ڴ�����Դ*/
#define	UGS_NONE_VISIBLE_LAYERS                 24287	/*! û���κο���ͼ����ʾ*/
#define	UGS_WFS_SERVER_REPORT_AN_EXCEPTION      24288	/*! WFS������������һ���쳣*/
#define	UGS_GETFEATURE_XML_FILE_PATH_IS_EMPTY   24289	/*! GetFeature XML�ļ�·��Ϊ��*/
#define	UGS_MARKUP_NOT_FIND_XS_COMPLEXCONTENT_TAG 24290	/*! Makup û�з���xs:complexContent��ǩ*/
#define	UGS_MARKUP_NOT_FIND_XS_SCHEMA_TAG       24291	/*! Makup û�з���xs:schema��ǩ*/
#define	UGS_DESCRIBE_XML_FILE_PATH_IS_EMPTY     24292	/*! Describe XML�ļ�·��Ϊ��*/
#define	UGS_WFS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED 24293	/*! WFS GetFeature����δ�����ڴ�����Դ*/
#define	UGS_SIZE_OF_DESCRIBE_XML_IS_ZERO        24294	/*! Describe XML�ļ���СΪ0*/
#define	UGS_SIZE_OF_GETFEATURE_XML_IS_ZERO      24295	/*! GetFeature XML�ļ���СΪ0*/
#define	UGS_GENERAL_QUERY_RESULT_IS_NULL        24296	/*! General��ѯû�еõ��κμ�¼*/
#define	UGS_IDS_QUERY_RESULT_IS_NULL            24297	/*! IDs��ѯû�еõ��κμ�¼*/
#define	UGS_IDS_ARRAY_COUNT_IS_MISMATCH         24298	/*! IDs ���������ƥ��*/
#define	UGS_ILLEGAL_QUERY_BOUNDS                24299	/*! ��ѯ�߽����*/
#define	UGS_WEB_ENGINE_NOT_SUPPORT_THIS_WFS_VERSION 24300	/*! �����������治֧�ָ�WFS�汾*/
#define	UGS_MARKUP_NOT_FIND_FEATURETYPELIST_TAG 24301	/*! Makup û�з���FeatureTypeList��ǩ*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WFS_VERSION 24302	/*! ������������ֻ֧��WFS1.0.0�汾*/
#define	UGS_CAPABILITIES_XML_DO_NOT_EXIST       24303	/*! Capabilities XML�ļ�������*/
#define	UGS_WCS_SERVER_REPORT_AN_EXCEPTION      24304	/*! WCS������������һ���쳣*/
#define	UGS_DESCRIBE_XML_DO_NOT_EXIST           24305	/*! Describe XML�ļ�������*/
#define	UGS_FAILED_TO_TRANSFER_IMAGE_TO_RASTER  24306	/*! ��Ӱ��դ�������ת��ʧ��*/
#define	UGS_WEBENGINE_NOT_SUPPORT_BEGINTRANS    24307	/*! �����������治֧�ֿ�ʼ�������*/
#define	UGS_MARKUP_NOT_FIND_XS_COMPLEXTYPE_TAG  24308	/*! Makup û�з���xs:complexType��ǩ*/
#define	UGS_WCS_NOT_SUPPORT_SETVISIBLE_LAYER    24309	/*! �������������WCS���ݼ���֧�����ÿɼ�ͼ��Ĳ���*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERINDEXES 24310	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ������*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERTILES 24311	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ�����*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERNEMES 24312	/*! �������������WCS���ݼ���֧�ֻ�ȡ�ɼ�ͼ������*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERINDEXS   24313	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ�������*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERTITLES   24314	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ��ı���*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERNAMES    24315	/*! �������������WCS���ݼ���֧�ֻ�ȡ����ͼ�������*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WCS_VERSION 24316	/*! ������������ֻ֧��WCS1.0.0�汾*/
#define	UGS_PARSE_FILE_NOT_EXIST                24317	/*! �����ļ�������*/
#define	UGS_HTTP_ERROR_NUMBER_OVERRUN           24318	/*! HTTP ����Ŵ���300*/
#define	UGS_FILE_GOT_FROM_WEB_IS_EMPTY          24319	/*! �������ϵõ����ļ�Ϊ��*/
#define	UGS_NOT_GET_FILE_FROM_WEB_CORRECTLY     24320	/*! û����ȷ�ش������ϵõ��ļ�*/
#define	UGS_OGC_SERVER_REPORT_AN_EXCEPTION      24321	/*! OGC ���������������һ���쳣*/
#define	UGS_INVALID_OGC_FILE                    24322	/*! �ⲻ��һ����ȷ��OGC���������ļ�*/
#define	UGS_FAILED_TO_CONNECT_DB                24323	/*! �������ݿ�ʧ��*/
#define	UGS_DATASET_INDEX_TYPE_IS_EMPTY         24324	/*! ���ݼ���������Ϊ��*/
#define	UGS_DATASET_IS_NULL_OR_VERSION_NUM_INVALID 24325	/*! ���ݼ�Ϊ�ջ�汾�ŷǷ�*/
#define	UGS_THIS_DATASET_NOT_HAVE_VERSION_OPTION 24326	/*! �����ݼ������ڰ汾ѡ��*/
#define	UGS_FAILED_TO_GET_DEFAULT_INDEX_PARAMETER 24327	/*! ��ȡĬ����������ʧ��*/
#define	UGS_TILEINDEX_FAILED_TO_UNREGISTER_     24328	/*! ͼ��������ע��ʧ��*/
#define	UGS_FAILED_TO_REGISTER_LIBRARY          24329	/*! ע��Libraryʧ��*/
#define	UGS_FAILED_TO_GET_TILE_SUBDATASET       24330	/*! ��ȡͼ�����������ݼ�ʧ��*/
#define	UGS_FAILED_TO_QUERY_TITLE_DATASET       24331	/*! ��ѯͼ���������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_TILE_DATASET          24332	/*! ��ȡͼ���������ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_TILE_DATASET       24333	/*! ����ͼ���������ݼ�ʧ��*/
#define	UGS_THIS_DATASET_CANNOT_CREATE_DYNAMIC_INDEX 24334	/*! ��֧�ָ����͵����ݼ�������̬����*/
#define	UGS_THE_QUALITY_PARAMETER_TO_CREATE_RTREE_INDEX 24335	/*! ����R��������Quality������Ч*/
#define	UGS_NOT_SUPPORT_THE_INDEX               24336	/*! ��֧�ֵ���������*/
#define	UGS_DATASET_OR_RTREE_POINTER_IS_NULL    24337	/*! ���ݼ�ָ�����R��ָ��Ϊ��*/
#define	UGS_INCORRECT_EDIT_MODE                 24338	/*! �༭ģʽ����*/
#define	UGS_CANNOT_UPDATE_INDEX_FOR_LIBID_NOT_EXIST 24339	/*! LibID�����ڣ��޷���������*/
#define	UGS_FAILED_TO_QUERY_FOR_NOT_TILE_INDEX  24340	/*! �����ݼ�����ͼ����������ѯʧ��*/
#define	UGS_INDEX_TYPE_MISMATCH                 24341	/*! ���������Ͳ���*/
#define	UGS_FAILED_TO_GET_THE_GRID_CORRELATIVE_WITH_QUERY_OBJECTS 24342	/*! ��ȡ���ѯ������صĸ���ʧ��*/
#define	UGS_FAILED_TO_FILETER_OBJECT_FROM_THE_GIRD 24343	/*! ����ظ����й��˶���ʧ��*/
#define	UGS_SCANLINE_ROW_OVERRUN                24344	/*! ɨ�����г������ݼ��߽�*/
#define	UGS_SCANLINE_BEGINING_COLUMN_OVERRUN    24345	/*! ɨ���߿�ʼ�г������ݼ��߽�*/
#define	UGS_ECW_NOT_SUPPORT_TO_GET_SCANLINE     24346	/*! ECW���ݼ���֧�ֵõ�ɨ����*/
#define	UGS_QUERY_CURSOR_HANDLE_IS_NULL         24347	/*! ��ѯ�α�������Ϊ��*/
#define	UGS_FAILED_TO_TRANSCOMMIT_DATA          24348	/*! �ύ����ʧ��*/
#define	UGS_FILED_INDEX_NOT_EXIST               24349	/*! �ֶ�����������*/
#define	UGS_ECW_AND_MRSID_NOT_SUPPORT_BULIDPYRAMID 24350	/*! ��֧�ֶ�ECW��MrSID����������*/
#define	UGS_IMAGEBLOCK_LINE_LESS_THAN_ONE       24351	/*! Ӱ��������С��1�Ƿ�*/
#define	UGS_HEIGHT_AND_WIDTH_ILLEGAL            24352	/*! �߶ȺͿ�Ȳ��Ϸ�*/
#define	UGS_RASTER_FAILED_TO_REGISTER_OPTION    24353	/*! դ�����ݼ�ע��ѡ����Ϣʧ��*/
#define	UGS_RASTER_FAILED_TO_UNREGISTER_OPTION  24354	/*! դ�����ݼ�ע��ѡ����Ϣʧ��*/
#define	UGS_DATASET_NOT_MODIFIED                24355	/*! ���ݼ�û���޸�*/
#define	UGS_INDEX_TABLE_EXIST                   24356	/*! ���������Ѿ�����*/
#define	UGS_FILED_NAME_CANNOT_BE_EMPTY          24357	/*! �ֶ����Ʋ���Ϊ��*/
#define	UGS_FILED_NAME_AND_FORMAT_CANNOT_BE_EMPTY 24358	/*! �ֶα�������ʽ����Ϊ��*/
#define	UGS_NOT_SUPPORT_THIS_STATISTIC_MODE     24359	/*! ��֧�ִ�ͳ��ģʽ*/
#define	UGS_RECORD_AT_THIS_INDEX_NOT_EXIST      24360	/*! �������ļ�¼������*/
#define	UGS_RECORDSET_AT_THIS_INDEX_NOT_EXIST   24361	/*! �����ļ�¼��������*/
#define	UGS_TILE_INDEX_TABLE_NOT_EXIST          24362	/*! ͼ������������*/
#define	UGS_DATASET_NOT_HAVE_THIS_REGISTER_OPTION 24363	/*! ���ݼ������ڸ�ע��ѡ��*/
#define	UGS_FAILED_TO_SAVE_DATASOURCE_INFO      24364	/*! ��������Դ��Ϣʧ��*/
#define	UGS_LOADING_WORKSPACE_NAME_IS_EMPTY     24365	/*! ����Ĺ����ռ���Ϊ��*/
#define	UGS_DATASOURCE_NOT_OPEN                 24366	/*! ����Դδ��*/
#define	UGS_FAILED_TO_START_TRANSACTION         24367	/*! ��ʼ����ʧ��*/
#define	UGS_NOT_START_TRANSACTION               24368	/*! δ��ʼ����*/
#define	UGS_RECORD_NOT_EDITABLE                 24369	/*! �ü�¼���ڷǱ༭ģʽ*/
#define	UGS_CURSOR_IS_FORWARD_ONLY              24370	/*! ���α���ǰ�򻬶��α�*/
#define	UGS_GEOMETRY_ADDED_IS_NULL              24371	/*! ��ӵĶ���Ϊ��*/
#define	UGS_LINE_IS_ILLEGAL                     24372	/*! ���߶���Ƿ�*/
#define	UGS_FILED_NOT_EXIST                     24373	/*! ���ֶβ�����*/
#define	UGS_NOT_SUPPORT_THIS_TYPE_GEOMETRY      24374	/*! ��֧�ָ����Ͷ���*/
#define	UGS_FILED_AT_THE_INDEX_NOT_EXIST        24375	/*! ���������ֶβ�����*/
#define	UGS_RECORD_EDIT_MODE_ILLEGAL            24376	/*! �ü�¼�ı༭ģʽ���Ϸ�*/
#define	UGS_THE_RECORD_INDEX_OVERRUN            24377	/*! ��ǰ��¼����������¼��*/
#define	UGS_THE_RECORD_INDEX_ILLEGAL            24378	/*! ��ǰ��¼�����Ƿ�*/
#define	UGS_NOT_SUPPORT_THE_QUERY_TYPE          24379	/*! ��֧�ָò�ѯ����*/
#define	UGS_CURSOR_HANDLE_IS_NULL               24380	/*! �α���Ϊ��*/
#define	UGS_FAILED_TO_CREATE_DATASOURCE_VERSION 24381	/*! ��������Դ�汾ʧ��*/
#define	UGS_FAILED_TO_DELETE_DATASOURCE_VERSION 24382	/*! ɾ������Դ�汾ʧ��*/
#define	UGS_RECORD_COUNT_IS_ZERO                24383	/*! ��¼���ļ�¼��Ϊ0*/
#define	UGS_FAILED_TO_FETCH_DATA                24384	/*! ȡ����ʧ��*/
#define	UGS_FAILED_TO_SCAN_FIELD_INFO           24385	/*! ɨ���ֶ���Ϣʧ��*/
#define	UGS_ID_ARRAY_COUNT_IS_ZERO              24386	/*! ID�������Ϊ0*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_FILED     24387	/*! ��¼����û�м����ֶ�*/
#define	UGS_THE_RECORD_ID_IS_ZERO               24388	/*! ��ǰ��¼��IDΪ0*/
#define	UGS_ILLEGAL_DATA_FOR_GEOMETY_SIZE_LESSTHAN_EIGHT_BYTE 24389	/*! ���ζ���Ĵ洢����С��8�ֽڣ��Ƿ�����*/
#define	UGS_OVERRUN_RECORDSET_BOUND             24390	/*! ������¼����Χ*/
#define	UGS_MOVE_TO_EOF                         24391	/*! �����ļ�ĩβ*/
#define	UGS_RECORDSET_NOT_OPEN                  24392	/*! ��¼��δ��*/
#define	UGS_MOVE_TO_BOF                         24393	/*! �ѵ����¼��ͷ*/
#define	UGS_NOT_FIND_FILED                      24394	/*! δ�ҵ��ֶ�*/
#define	UGS_FAILED_TO_GET_TEMPTABLE             24395	/*! ��ȡ��ʱ������ʧ��*/
#define	UGS_TILE_GEOMETRY_ERROR                 24396	/*! ͼ���������ݼ���ͼ�����ζ������*/
#define	UGS_TEMPLATE_NAME_IS_EMPTY              24397	/*! ģ����Ϊ��*/
#define	UGS_TEMPLATE_FILE_NOT_EXIST             24398	/*! ģ���ļ�������*/
#define	UGS_TEMPLATE_NAME_ALREADY_EXISTED       24399	/*! ģ�����Ѵ���*/
#define	UGS_TEMPLATE_FILE_IS_EMPTY              24400	/*! ģ���ļ�����Ϊ��*/
#define	UGS_MAPPING_ALREADY_EXIST               24401	/*! ӳ���Ѵ���*/
#define	UGS_FAILED_TO_GET_DATASET_INITIAL_INFO  24402	/*! ���ݼ���ʼ��Ϣ��ȡʧ��*/
#define	UGS_ORIGINAL_COORDINATES_SYSTEM_IS_NULL 24403	/*! Դ����ϵΪ��*/
#define	UGS_ORGINAL_COORDINATES_NOT_PROJECTION_AND_TARGET_COORDINATES_IS_NULL 24404	/*! Դ����ϵ����ͶӰ����ϵ��Ŀ������ϵΪ��*/
#define	UGS_ORGINAL_OR_TARGET_COORDINATES_IS_PLANE_COORDINATE 24405	/*! Դ����ϵ��Ŀ������ϵ��һ����ƽ������ϵ*/
#define	UGS_LONGITUDE_LATITUDE_SAME_COORDINATE_SYSTEM 24406	/*! ��γ�� ==> ��γ��,����ϵ��ͬ*/
#define	UGS_PROJECTION_SAME_COORDINATE_SYSTEM   24407	/*! ͶӰ==>ͶӰ������ϵ��ͬ*/
#define	UGS_APPENDING_DATASET_TYPE_MISMATCH     24408	/*! ׷�ӵ����ݼ����Ͳ�ƥ��*/
#define	UGS_CANNOT_DELETE_FOR_HAVING_UNCOMMITTABLE_DATA 24409	/*! ɾ����¼֮ǰ��δ�ύ�����ݣ����Զ��ύ��Щ����ʧ�ܣ��޷�����ɾ������*/
#define	UGS_ID_IS_ZERO_CANNOT_DELETE            24410	/*! ��ǰIDֵΪ0���޷�ɾ��*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY           24411	/*! ��¼����û�м��ζ����¼*/
#define	UGS_ID_IS_ZERO                          24412	/*! ��ǰ��¼��IDΪ0*/
#define	UGS_NOT_FIND_MATCHING_FILED             24413	/*! δ�ҵ�ƥ����ֶ�*/
#define	UGS_HAVE_UNCOMMITTABLE_DATA_AND_FAILED_TO_AUTOCOMMIT 24414	/*! ����δ�ύ�ı༭���Զ��ύ�����ύʧ��*/
#define	UGS_ALREADY_UNEDITABLE                  24415	/*! �Ѿ��ǷǱ༭״̬*/
#define	UGS_DATASET_POINTER_IS_NULL_CANNOT_REGISTER_VERSION 24416	/*! ���ݼ�ָ��Ϊ�գ��޷�ע��汾*/
#define	UGS_FAILED_TO_CREATE_A_TABLE            24417	/*! ����A��ʧ��*/
#define	UGS_DATASET_POINTER_IS_NULL_CANNOT_COMMIT_VERSION 24418	/*! ���ݼ�ָ��Ϊ�գ��޷��ύ�汾*/
#define	UGS_FAILED_TO_COMMIT_FOR_VERSION_NOT_EXIST 24419	/*! SmVersions�в����ڸð汾���ύʧ��*/
#define	UGS_FAILED_TO_COMMIT_FOR_DATASET_POINTER_IS_NULL 24420	/*! ���ݼ�ָ��Ϊ�գ��ύʧ��*/
#define	UGS_FAILED_TO_ROLLBACK_FOR_NOT_REGISTER_VERSION 24421	/*! ���ݼ�û��ע��汾���ݼ����ع�ʧ��*/
#define	UGS_FAILED_TO_COMMIT_VERSION_FOR_FAILED_TO_UPDATE_INDEX 24422	/*! ��������ʧ�ܣ��汾�ύʧ��*/
#define	UGS_FAILED_TO_UPDATE_INDEX_FOR_FAILED_TO_OPEN_DATASET 24423	/*! ���ݼ���ʧ�ܣ���������ʧ��*/
#define	UGS_CANNOT_ADD_DATASET_FOR_FAILED_TO_OPEN_DATASET 24424	/*! ���ݼ���ʧ�ܣ��޷�������ݼ�*/
#define	UGS_CANNOT_GET_FILELD_INFO_FOR_FAILED_TO_OPEN_DATASET 24425	/*! ��ȡ�ֶ���Ϣʧ�ܣ����ݼ���ʧ��*/
#define	UGS_CANNOT_MODIFY_INFO_FOR_DATASET_IS_READ_ONLY 24426	/*! ���ݼ�Ϊֻ��״̬���޷��޸���Ϣ*/
#define	UGS_FAILED_TO_CREATE_DATASET_FOR_ALREADY_EXIST_IN_REGEDIT 24427	/*! ע������Ѿ�������ؼ�¼���������ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_NETWORK_SUBDATASET 24428	/*! �����������ݼ��������ݼ�ʧ��*/
#define	UGS_SUBDATASET_IS_NULL                  24429	/*! �����ݼ�Ϊ��*/
#define	UGS_NOT_TILE_INDEX_CANNOT_GET_TITLE_ID  24430	/*! ��ǰ������ͼ�����������ܻ�ȡͼ��ID*/
#define	UGS_FIELD_TYPE_ILLEGAL                  24431	/*! �ֶ����ͷǷ�*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_DATASET_NOT_OPEN 24432	/*! ���ݼ�δ�򿪣��޷������ֶ�*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_ILLEGAL 24433	/*! �ֶ����ƷǷ��������ֶ�ʧ��*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_LENGTH_OVERRUN 24434	/*! �ֶ����Ƴ��ȳ���30�������ֶ�ʧ��*/
#define	UGS_FAILED_TO_DELETE_FIELD_FOR_NO_MATCHING_FIELD_NAME 24435	/*! û��ƥ����ֶ����ƣ�ɾ���ֶ�ʧ��*/
#define	UGS_LOADING_PARAM_ILLEGAL               24436	/*! ��������Ƿ�������*/
#define	UGS_CANNOT_DELETE_SYSTEM_FIELD          24437	/*! ϵͳ�ֶΣ��޷�ɾ��*/
#define	UGS_FAILED_TO_GET_FIELD_FOR_NO_MATCHING_FIELD_NAME 24438	/*! δ�ҵ�ƥ���ֶ�����,��ȡ�ֶ���Ϣʧ��*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_CANNOT_APPEND_RECORD 24439	/*! ��¼����û�м��ζ����޷���Ǵ����Ա����ݼ���׷�Ӽ�¼*/
#define	UGS_FIELD_NAME_ALREADY_EXIST            24440	/*! �ֶ����Ѵ���*/
#define	UGS_NAME_ILLEGAL                        24441	/*! �Ƿ�����*/
#define	UGS_NOT_SUPPORT_THIS_ORACLE_DATA_TYPE   24442	/*! ��֧�ֵ�Oracle��������*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_TILE_INDEX 24443	/*! ���������ݼ���֧��ͼ������*/
#define	UGS_FAILED_TO_CREATE_TILE_SUBDATASET    24444	/*! ����ͼ�������ݼ�ʧ��*/
#define	UGS_CANNOT_UNREGISTER_FOR_HAVE_NOT_REGISTERED 24445	/*! δע���ѡ��޷����з�ע��*/
#define	UGS_FAILED_TO_DELETE_FOR_NOT_FIND_SUBDATASET 24446	/*! δ�ҵ������ݼ���ɾ��ʧ��*/
#define	UGS_PJCONVERT_POINTER_IS_NULL_OR_DATASOURCE_COORDINATES_IS_PLANE_COORDINATES 24447	/*! ����ϵת��������ָ��Ϊ�գ�������ԴΪƽ������ϵ��*/
#define	UGS_PJCONVERT_TARGET_PJSYSTEM_IS_PLANE_COORDINATES 24448	/*! ����ϵת��������Ŀ��ͶӰ����ϵΪƽ������ϵ��*/
#define	UGS_PJCOORDSYS_POINTER_IS_NULL_OR_DATASOURCE_COORDSYS_IS_PLANE_COORDSYS 24449	/*! ͶӰ����ϵ����ָ��Ϊ��,������ԴΪͶӰ����ϵ*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_LONGITUDE_LATITUDE 24450	/*! ͶӰ����ϵ����Ŀռ�����ϵ���Ǿ�γ������ϵ��*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_PJCOORDSYS  24451	/*! ͶӰ����ϵ����Ŀռ�����ϵ����ͶӰ����ϵ��*/
#define	UGS_NOT_FIND_ENGINE_DYNAMIC_LIB_DEFINE  24452	/*! û���ҵ��������Ķ�̬�ⶨ��*/
#define	UGS_FAILED_TO_SET_THE_VERSION_BY_VERSION_NAME 24453	/*! �԰汾�����õ�ǰ�汾ʧ��*/
#define	UGS_FAILED_TO_SET_THE_VERSION_BY_VERSION_ID 24454	/*! �԰汾�����õ�ǰ�汾ʧ��*/
#define	UGS_FAILED_TO_GET_VERSION_INFO          24455	/*! �õ��汾��Ϣʧ��*/
#define	UGS_DATASET_FAILED_TO_REGISTER_VERSION  24456	/*! ע�����ݼ�Ϊ�汾ʧ��*/
#define	UGS_DATASET_FAILED_TO_UNREGISTER_VERSION 24457	/*! ��ע�����ݼ��汾ʧ��*/
#define	UGS_FAILED_TO_COMMIT_TO_DEFAULT_VERSION 24458	/*! �ύ�����汾ʧ��*/
#define	UGS_FAILED_ROLLBACK_VERSION             24459	/*! ���һ���汾�ı༭ʧ��*/
#define	UGS_IMGBLOCK_INDEX_ID_LESSTHAN_ZERO     24460	/*! ָ��Ӱ���������С��0*/
#define	UGS_RASTER_FAILED_TO_CALCULATE_EXTREMUM_BY_REGION 24461	/*! CalculateExtremumByRegionդ����㼫ֵʧ��*/
#define	UGS_FAILED_TO_SET_IMGBLOCK              24462	/*! ����Ӱ���ʧ��*/
#define	UGS_FAILED_TO_APPEND_RECORDSET          24463	/*! ׷�Ӽ�¼��ʧ��*/
#define	UGS_SPATIALQUERY_OPTION_ILLEGAL         24464	/*! �ռ��ѯѡ��Ƿ�*/
#define	UGS_VALUE_IMPORTED_ILLEGAL              24465	/*! �����ֵ�Ƿ�*/
#define	UGS_GRID_IMPORTED_IS_NULL               24466	/*! ���������Ϊ��*/
#define	UGS_CANNOT_GET_CONNECTION_INFO_FOR_XML_IS_EMPTY 24467	/*! XML�ļ�Ϊ��,���ܵõ�������Ϣ*/
#define	UGS_CANNOT_GET_CONNECTION_INFO_FOR_XML_STRING_FORMAT_MISMATCH 24468	/*! XML�ַ�����ʽ����,���ܵõ�������Ϣ*/
#define	UGS_IMAGE_POINTER_IS_NULL               24469	/*! Ӱ�����ݼ�ָ��Ϊ��*/
#define	UGS_GET_DATA_STORING_METADATA           24470	/*! �õ��洢Ԫ���ݵ�����*/
#define	UGS_FAILED_TO_INITIALIZE_DATASET        24471	/*! ��ʼ�����ݼ�ʧ��*/
#define	UGS_THE_METADATA_NOT_EXIST              24472	/*! ��ǰ���ݼ���Ԫ���ݲ�����*/
#define	UGS_FAILED_TO_GET_METADATA_FOR_METADATA_COUNT_IS_ZERO 24473	/*! Ԫ����Ԫ�ظ���Ϊ0,��ȡԪ����ʧ��*/
#define	UGS_FAILED_TO_GET_METADATA_FOR_NOT_FIND_METADATA_ELEMENT 24474	/*! Ԫ����Ԫ��û���ҵ�,��ȡԪ����ʧ��*/
#define	UGS_FAILED_TO_QUERY_BY_SUBBOUNDS        24475	/*! ���ӱ߿��ѯʧ��*/
#define	UGS_FAILED_TO_GET_QUERY_DEFINE_FROM_XML 24476	/*! û���ҵ�QueryDef��ǩ����XML�ļ��еõ���ѯ����ʧ��*/
#define	UGS_THE_DATASET_NOT_SUPPORT_INDEX       24477	/*! ��ǰ���ݼ���֧������*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX     24478	/*! ��ǰ���ݼ�����Ҫ��������*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX_FOR_NOT_DIRTY 24479	/*! ��ǰ���ݼ��������಻��Ҫ��������*/
#define	UGS_POINT_CANNOT_BUILDINDEX             24480	/*! �����ݼ����ܴ�������*/
#define	UGS_MEMORY_DATASOURCE_COUNT_IS_ZERO     24481	/*! �ڴ�����Դ�ĸ���Ϊ0*/
#define	UGS_INDEX_BOUNDS_ERROR                  24482	/*! ����������Ҫ�ķ�Χ����*/
#define	UGS_NOT_SUPPORT_THE_EDIT_MODE           24483	/*! ��֧�ָñ༭ģʽ*/
#define	UGS_GEOMETRY_UNKNOWN                    24484	/*! �޷�ʶ��ļ��ζ�������*/
#define	UGS_FAILED_TO_GET_FILED_VALUE_FOR_NO_MATCHING_FILED_NAME 24485	/*! û��ƥ����ֶ�������ȡ�ֶ�ֵʧ��*/
#define	UGS_NO_MATCHING_ID                      24486	/*! û��ƥ���ID*/
#define	UGS_INVALID_RECORD_POINTED_BY_THE_RECORDSET 24487	/*! ��¼����ǰָ��ļ�¼��Ч*/
#define	UGS_CANNOT_CHANGE_PASSWORD_FOR_DATASOURCE_NOT_OPEN 24488	/*! ����Դδ�򿪣������޸�����*/
#define	UGS_USERNAME_IS_EMPTY                   24489	/*! �û���Ϊ�գ��Ƿ�*/
#define	UGS_CANNOT_STARTTRANS_FOR_DATASOURCE_NOT_OPEN 24490	/*! ����Դδ�򿪣��޷���ʼ����*/
#define	UGS_CANNOT_STARTTRANS_FOR_NOT_OPEN_BY_TRANS 24491	/*! ����������ʽ�򿪣��޷���ʼ����*/
#define	UGS_CANNOT_LOGIN_FOR_DATASOURCE_VERSION_MISMATCH 24492	/*! ����Դ�汾���ԣ��޷���¼*/
#define	UGS_CANNOT_LOGIN_FOR_DATASOURCE_NOT_OPEN 24493	/*! ����Դδ�򿪣��޷���¼*/
#define	UGS_CANNOT_DELETE_DATASET_FOR_DATASOURCE_NOT_OPEN 24494	/*! ����Դδ�򿪣��޷�ɾ�����ݼ�*/
#define	UGS_PBYTE_POINTER_IS_NULL               24495	/*! pByte �����ָ��*/
#define	UGS_CANNOT_SAVE_WORKSPACE_FOR_FAILED_TO_CONNECT_DATABASE 24496	/*! ���ݿ�����ʧ�ܣ��޷����湤���ռ�*/
#define	UGS_WORKSPACE_NAME_IS_EMPTY             24497	/*! ����������������ռ����ơ�Ϊ��*/
#define	UGS_CANNOT_GET_WORKSPACE_FOR_FAILED_TO_CONNECT_DATABASE 24498	/*! ���ݿ�����ʧ��,�޷���ȡ�����ռ�*/
#define	UGS_CANNOT_GET_WORKSPACE_INFO_FOR_FAILED_TO_CONNECT_DATABASE 24499	/*! ���ݿ�����ʧ��,�޷���ȡ�����ռ���Ϣ*/
#define	UGS_CANNOT_DELETE_WORKSPACE_INFO_FOR_FAILED_TO_CONNECT_DATABASE 24500	/*! ���ݿ�����ʧ��,�޷�ɾ�������ռ���Ϣ*/
#define	UGS_CANNOT_CREATE_VERSION_FOR_DATASOURCE_NOT_OPEN 24501	/*! ����Դδ��,�޷������°汾*/
#define	UGS_IMPORTING_VERSION_NAME_IS_NULL      24502	/*! ����յİ汾����,����*/
#define	UGS_VERSION_ID_ERROR                    24503	/*! �汾�Ŵ���,����*/
#define	UGS_DATASOURCE_NOT_CREATE_VERSION       24504	/*! ������Դû�д����汾*/
#define	UGS_CANNOT_CREATE_RASTER_FOR_WIDTH_OR_HEIGHT_IS_ZERO 24505	/*! դ�����ݼ��Ŀ���Ϊ0, �޷�����*/
#define	UGS_CANNOT_CREATE_FOR_NOT_SUPPORT_THE_DATASET_TYPE 24506	/*! ��֧�ֵ����ݼ�����,�޷�����*/
#define	UGS_FAILED_TO_CREATE_RASTER_FOR_INVALID_PIXEL_FORMAT 24507	/*! ��֧�ֵ����ظ�ʽ,����դ�����ݼ�ʧ��*/
#define	UGS_CANNOT_BULID_PYRAMID_FOR_FAILED_TO_OPEN_DATASET 24508	/*! ���ݼ���ʧ��,�޷�����������*/
#define	UGS_FAILED_TO_CREATE_PYRAMID_SUBDATASET 24509	/*! ���������������ݼ�ʧ��*/
#define	UGS_IMGBLOCK_SIZE_LESSTHAN_ONE          24510	/*! Ӱ����СС��1,�Ƿ�����*/
#define	UGS_DATASET_READONLY_CANNOT_SET_OPTION  24511	/*! ���ݼ�Ϊֻ��״̬,�޷�����ѡ��*/
#define	UGS_TEMPTABLE_FAILED_TO_RELATE_QUERY    24512	/*! ��ʱ�������ѯʧ��*/
#define	UGS_FAILED_TO_RELATE_QUERY              24513	/*! ������ѯʧ��*/
#define	UGS_FAILED_TO_COPY_FILED_VALUE          24514	/*! �����ֶ�ֵʧ��*/
#define	UGS_FAILED_TO_DELETE_RECORD             24515	/*! ɾ����¼ʧ��*/
#define	UGS_CREATE_WORKSPACE_SMTABLE_FAILED     24516	/*! ���������ռ��ϵͳ��ʧ��*/
#define	UGS_NOT_SUPPORT_THIS_WEBENGINE          24517	/*! ��֧�ֵ�������������*/


// ���ݸ�ʽת��������Ϣ����25000��ʼ����
#define	UGS_CANNT_COPY_ECW_OR_MRSUGS_BETWEEN_DIFFERENT_ENGINES 25000	/*! MrSID��ECW����ֻ���ڱ�������Դ֮�俽��*/
#define	UGS_AFC_DATAPMP_WRITE_LINE              25001	/*! ����� %ld ���߶���*/
#define	UGS_AFC_DATAPMP_WRITE_POLYGON           25002	/*! ����� %ld ������ζ���*/
#define	UGS_AFC_DATAPMP_WRITE_POINT             25003	/*! ����� %ld �������*/
#define	UGS_AFC_DATAPMP_WRITE_TEXT              25004	/*! ����� %ld ���ı�����*/
#define	UGS_AFC_DATAPMP_READ_LINE               25005	/*! ������ %ld ���߶���*/
#define	UGS_AFC_DATAPMP_READ_POLYGON            25006	/*! ������ %ld ������ζ���*/
#define	UGS_AFC_DATAPMP_READ_POINT              25007	/*! ������ %ld �������*/
#define	UGS_AFC_DATAPMP_READ_TEXT               25008	/*! ������ %ld ���ı�����*/
#define	UGS_BEGIN_READ_IN_LINE                  25009	/*! ��ʼת���߶���......*/
#define	UGS_BEGIN_READ_IN_POINT                 25010	/*! ��ʼת������......*/
#define	UGS_BEGIN_READ_IN_POLYGON               25011	/*! ��ʼת�����ζ���......*/
#define	UGS_BEGIN_READ_IN_LINE_ATTRIBUTE        25012	/*! ��ʼת���߶��������......*/
#define	UGS_BEGIN_READ_IN_POLYGON_ATTRIBUTE     25013	/*! ��ʼת�����ζ��������......*/
#define	UGS_READED_IN_LINE_ATTRIBUTE            25014	/*! �Ѿ�ת�� %ld ���߶��������......*/
#define	UGS_READED_IN_POLYGON_ATTRIBUTE         25015	/*! �Ѿ�ת�� %ld ������ζ��������......*/
#define	UGS_AFC_DATAPMP_READED_OBJ              25016	/*! ������%ld ������*/
#define	UGS_BEGIN_READ_IN_TEXT                  25017	/*! ��ʼת��ע�Ƕ���......*/
#define	UGS_BEGIN_READ_IN_NODE_ATTRIBUTE        25018	/*! ����ڵ����Ա�......*/
#define	UGS_BEGIN_READ_IN_LAB_ATTRIBUTE         25019	/*! ��ʼת���ʶ������...*/
#define	UGS_IMAGE_FORMAT_NOT_SUPPORTED          25020	/*! �Բ��𣬱�ϵͳĿǰ��֧�ָø�ʽ*/
#define	UGS_READ_BMP_FILE                       25021	/*! ����ת��BMPͼ��*/
#define	UGS_WRITE_BMP_FILE                      25022	/*! ����ת��BMPͼ��*/
#define	UGS_READ_TIFF_FILE                      25023	/*! ����ת��TIFFͼ��*/
#define	UGS_WRITE_TIFF_FILE                     25024	/*! ����ת��TIFFͼ��*/
#define	UGS_READ_JEPG_FILE                      25025	/*! ����ת��JPEGͼ��*/
#define	UGS_WRITE_JEPG_FILE                     25026	/*! ����ת��JPEGͼ��*/
#define	UGS_BEGIN_WRITE_IN_POINT                25027	/*! ��ʼת�������......*/
#define	UGS_BEGIN_WRITING_IN_NETWORK            25028	/*! ��ʼת�����߶���......*/
#define	UGS_BEGIN_WRITE_IN_LINE                 25029	/*! ��ʼת�������߶���......*/
#define	UGS_BEGIN_WRITING_IN_REGION             25030	/*! ��ʼת�������......*/
#define	UGS_BEGIN_WRITE_IN_TEXT                 25031	/*! ��ʼת��ע�Ƕ���......*/
#define	UGS_WRITE_GRID_FILE                     25032	/*! ����ת�� Grid ���ݣ�*/
#define	UGS_READ_GRID_FILE                      25033	/*! ����ת�� Grid ���ݣ�*/
#define	UGS_IMPORT_TILE                         25034	/*! �Ѿ�ת��%ld/%ld ��Ӱ���...	*/
#define	UGS_PMP_CREATING_TEMP_DATA              25035	/*! ����׼����ʱ���ݣ��������Ҫ������,���Ժ�......*/
#define	UGS_AFC_DATAPMP_READ_CAD                25036	/*! ������ %ld �����϶���*/
#define	UGS_GXML_FEATURE_IMPORT                 25037	/*! ������ %ld ������*/
#define	UGS_GXML_EXPORT_RECORD                  25038	/*! ����� %ld ������*/
#define	UGS_AFC_DATAPMP_READED_ATTRITUBE        25039	/*! ������%d����������*/
#define	UGS_VCT_VARCHAR_FIND                    25040	/*! ���������ļ�%s�ı䳤�ַ���׼��������������...*/


// դ�����������Ϣ����26000��ʼ����
#define	UGS_IMGREG_ERR_INTERRECTIFY             26000	/*! �ⷽ�̴���,�޷����ϵ��! �����ӻ��޸Ŀ��Ƶ�!*/
#define	UGS_IMGREG_NEW_LAYER_NAME               26001	/*! �������½�դ��ͼ�����ƣ�*/
#define	UGS_IMGREG_TRANSFORM                    26002	/*! Ӱ��ת������*/
#define	UGS_OUTPUTEX_TOO_LARGE_RESOLUTION       26003	/*! ����ֱ���̫��*/
#define	UGS_OUTPUTEX_MANAGEMENT_ERROR           26004	/*! ��������г���*/
#define	UGS_OUTPUTEX_MSG_TITLE                  26005	/*! ��ͼդ��*/
#define	UGS_RECTIFY_TITLE                       26006	/*! ���ڽ���Ӱ����׼*/
#define	UGS_CONJOINT_AND_NORMALS                26007	/*! ���㷨�������ڽӹ�ϵ*/
#define	UGS_MSG_INVALID_ISOLIEN_DISTANCE        26008	/*! �Ƿ��ĵȸ߾�*/
#define	UGS_MSG_FAILED_TO_TRACE_CLOSED_ISOLINE  26009	/*! ׷�ٱպϵĵ�ֵ��ʧ��, ��ֵ�߸߶��� %f��*/
#define	UGS_MSG_ASPECT                          26010	/*! ����*/
#define	UGS_MSG_SLOPE                           26011	/*! �¶�*/
#define	UGS_MSG_RECLASS                         26012	/*! �طּ�*/
#define	UGS_DTM_MSG_CUTFILL                     26013	/*! �����������ڷ�����*/
#define	UGS_ERROR_INVERSIBLE_MATRIX             26014	/*! �����ص�*/
#define	UGS_MSG_HILLSHADE                       26015	/*! ��ά����*/
#define	UGS_DTM_MSG_ANALYSIS                    26016	/*! դ�����*/
#define	UGS_DTM_MSG_HYD_DIR                     26017	/*! �������*/
#define	UGS_DTM_MSG_HYD_ACC                     26018	/*! �ۻ���ˮ��*/
#define	UGS_DTM_MSG_HYD_LENGTH                  26019	/*! ����*/
#define	UGS_DTM_MSG_INVALID_CELLSIZE            26020	/*! ָ���Ľ��դ���С��Ч*/
#define	UGS_DTM_MSG_NOT_RASTER                  26021	/*! ��ͼ�÷�դ�����ݽ���դ������*/
#define	UGS_DTM_MSG_NO_STATISTIC_TYPE_MATCHING  26022	/*! û��ƥ���ͳ������*/
#define	UGS_DTM_MSG_CREATE_LAKE                 26023	/*! ��������*/
#define	UGS_DTM_MSG_CLIP_RASTER                 26024	/*! ���ڲü�դ������*/
#define	UGS_DTM_MSG_VALUETABLE                  26025	/*! ͳ��դ��ֵ���ݱ�*/
#define	UGS_DTM_MSG_TRANSLATE_RASTER_PROJECTION_TITLE 26026	/*! ���ڽ���դ��ͶӰת��...*/
#define	UGS_MSG_TRANSLATING_PROJECTION          26027	/*! դ��ͶӰת��...*/
#define	UGS_IMAGE_MSG_NO_IMAGE                  26028	/*! û��Ӱ������*/
#define	UGS_IMAGE_MSG_ERROR_DATA                26029	/*! Ӱ�񳤶Ȼ���С����*/
#define	UGS_IMAGE_MSG_NO_SUCH_DIRECTION         26030	/*! û���Ǹ����������*/
#define	UGS_IMAGE_MSG_CREATING_ORTHO            26031	/*! ����������άӰ��*/
#define	UGS_IMAE_MSG_COMPUTING_COLOR            26032	/*! ������άӰ����ɫ...*/
#define	UGS_IMAGE_MSG_SMOOTHING                 26033	/*! Ӱ��ƽ������....*/
#define	UGS_IMAGE_MSG_INTERP                    26034	/*! �����ڲ����*/
#define	UGS_IMAGE_MSG_INTERP_IDW                26035	/*! ���뷴��Ȩ��(IDW)�ڲ�*/
#define	UGS_IMAGE_MSG_INTERP_KRIG1              26036	/*! ��ͨ�������ڲ�*/
#define	UGS_IMAGE_MSG_INTERP_RBF                26037	/*! ���������(RBF)��ֵ*/
#define	UGS_CHOOSE_PIXELFORMAT_FAILED           26038	/*! ѡ�����ظ�ʽʧ��*/
#define	UGS_SET_PIXELFORMAT_FAILED              26039	/*! �������ظ�ʽʧ��*/
#define	UGS_CREATE_OGLCONTEXT_FAILED            26040	/*! ���ܴ���OpenGL��Ⱦ����*/
#define	UGS_MAKE_CURRENTCONTEXT_FAILED          26041	/*! ����ѡ��ǰ����*/
#define	UGS_DISPLAYSETTINGS_NOT_SUPPORTED       26042	/*! ��֧�ֵ�ǰ��ʾ��������*/
#define	UGS_PLS_CHOOSE_DEEPERDEPTH_OR_LESSSCALE 26043	/*! ��������Ĳ�λ���ѡ���С���������*/
#define	UGS_IMGBLOCK_GET_FAILED                 26044	/*! ��ȡӰ������*/


// �������������Ϣ����27000��ʼ����
#define	UGS_TOO_SMALL_TOLERANCE                 27000	/*! ���޲���С�ڻ����0*/
#define	UGS_INVALID_NODE_SELECT_TOLERANCE       27001	/*! �ڵ�ѡ�����޴���*/
#define	UGS_INVALID_END_NODE                    27002	/*! ָ�����յ���Ч��*/
#define	UGS_NOT_SUPPORT_ALLOCATE_TYPE           27003	/*! ��Դ�������Ͳ�ƥ��*/
#define	UGS_NUMBER_OF_CENTERS_IS_INCORRECT      27004	/*! ָ�������ĸ������Ϸ���*/
#define	UGS_CANDIDATE_CENTERS_CANNOT_BE_ZERO    27005	/*! ��ѡ���ĸ�������Ϊ�㣡*/
#define	UGS_NOT_ENOUGH_CANDIDATE_CENTERS        27006	/*! û���㹻�ĺ�ѡ���ĵ㣡*/
#define	UGS_NOT_ALLOW_ALLOCATE_FOR_NULL_CENTER  27007	/*! ���ܷ�������ĵ㣡*/
#define	UGS_INVALID_DEMAND_NODE                 27008	/*! ����ڵ�δ�ܱ���ȷ����*/
#define	UGS_ALLOCATING                          27009	/*! ��Դ����*/
#define	UGS_FIND_TSP_PATH                       27010	/*! �����̷���*/
#define	UGS_FIND_SHORTEST_PATH                  27011	/*! ���·������*/
#define	UGS_GET_RESULT                          27012	/*! �������ɽ��*/
#define	UGS_FIND_SERVICEAREAING                 27013	/*! ����������*/
#define	UGS_FIND_CLOSEST_FACILITYING            27014	/*! �����ʩ����*/
#define	UGS_LOCATEALLOCATING                    27015	/*! ѡַ��������*/
#define	UGS_NODE_CONNECTED_ANYLAZED             27016	/*! �ڵ���ͨ�Է���*/
#define	UGS_FIND_CONNECTED_NODES                27017	/*! ͨ������*/
#define	UGS_FIND_CONNECTED_EDGES                27018	/*! ͨ��߷���*/
#define	UGS_FIND_CRITIAL_EDGES                  27019	/*! �ؼ��߷���*/
#define	UGS_FIND_CRITIAL_NODES                  27020	/*! �ؼ������*/
#define	UGS_NOT_SET_TRN_FIELD                   27021	/*! û������ת�������ֶ�*/
#define	UGS_NOT_SET_ARCID_OR_NODEID_FIELD       27022	/*! û�����û���ID����ID�ֶ�*/
#define	UGS_NOT_SET_COST_FIELD                  27023	/*! û�����������ֶ�*/
#define	UGS_STEP_2_LINE_NET_BUILD               27024	/*! ���ν�����(%d/%d)...*/
#define	UGS_MSG_BUILDING_TRN                    27025	/*! ���ڴ���ת���*/
#define	UGS_MSG_CANNOT_FIND_NODE                27026	/*! ��ָ����λ���������޷��ҵ��ڵ�!*/
#define	UGS_SL_MSG_MISMATCH_BETWEEN_IMAGELIST_AND_TREEITEM 27027	/*! ���Ľڵ���ͼ���б�ƥ��*/


// �ֶ����Ͷ��壺��28000��ʼ����
#define	UGS_NOUM_BOOLEAN                        28000	/*! ����*/
#define	UGS_NOUM_SHORT                          28001	/*! ������*/
#define	UGS_NOUM_LONG                           28002	/*! ������*/
#define	UGS_NOUM_SINGLE                         28003	/*! ������*/
#define	UGS_NOUM_DOUBLE                         28004	/*! ˫����*/
#define	UGS_NOUM_NUMERIC                        28005	/*! ��ֵ*/
#define	UGS_NOUM_FLOAT                          28006	/*! ������*/
#define	UGS_NOUM_DBTEXT                         28007	/*! �ı�*/
#define	UGS_NOUM_CHAR                           28008	/*! �ַ�*/
#define	UGS_NOUM_BYTE                           28009	/*! �ֽ�*/
#define	UGS_NOUM_BINARY                         28010	/*! ������*/
#define	UGS_NOUM_DATE                           28011	/*! ����*/
#define	UGS_NOUM_CURRENCY                       28012	/*! ����*/
#define	UGS_NOUM_MEMO                           28013	/*! ��ע*/
#define	UGS_NOUM_LONGBINARY                     28014	/*! ��������*/
#define	UGS_NOUM_TIME                           28015	/*! ʱ��*/


// ������Ϣ�������������з��ࣺ��29000��ʼ����
#define	UGS_FAILED_TO_PREPAREEDITBOARD_FOR_PICTURE_INBUFFER_IS_NULL 29000	/*! �ڴ�ͼƬΪ�գ�UGEditToolPack::PrepareEditBoardʧ��*/
#define	UGS_NAME_NOT_EXIST_UGMAPSTORAGE_CLONE_FAILED 29001	/*! ����Ϊ%s��UGMapStorage�����ڣ���¡UGMapStorageʧ��*/
#define	UGS_SOURCE_FILE_FULLNAME_S              29002	/*! Դ�ļ�ȫ��: %s*/
#define	UGS_ADJUSTXMLFILE_UNFULFILMENT          29003	/*! AdjustXMLFile�ӿ�δʵ��*/
#define	UGS_FAILED_TO_MAKE_BLOCK_SEQUENCE       29004	/*! ���л���ʧ��*/
#define	UGS_CANNOT_COMPRESS_FOR_BLOCK_SIZE_IS_OVERRUN 29005	/*! ��ĳߴ粻��Ҫ���޷�����SGL����*/
#define	UGS_FAILED_TO_GETSNAPADDPOINT_FOR_THERE_IS_NO_SANPPOINT_IN_BUFFER 29006	/*! Buffer��û�в�׽�����UGEditSnapBuffer::GetSnapAddPointʧ��*/
#define	UGS_FAILED_TO_GETLINEINDEX_FOR_THERE_IS_NO_SANPLINE_IN_BUFFER 29007	/*! Buffer��û�в�׽�߶���UGEditSnapBuffer::GetLineIndexʧ��*/
#define	UGS_CACHEMASTERFILE_S_CREATE_SUCCESS    29008	/*! CacheMasterFile�� %s �����ɹ�*/
#define	UGS_CACHEMASTERFILE_S_EXIST             29009	/*! CacheMasterFile�� %s �Ѵ���*/
#define	UGS_FAILED_TO_CREATE_CAD_DATASET        29010	/*! CAD���ݼ�����ʧ��*/
#define	UGS_CURSORTYPE_IS_OPENFORWARD_ONLY      29011	/*! ��ǰ�α괦����ǰ����״̬*/
#define	UGS_CURSORTYPE_IS_OPENFORWARDONLY       29012	/*! ��ǰ�α괦����ǰ����״̬*/
#define	UGS_EDITMODE_ISNOT_EDITNONE_AND_CANNOT_UPDATE  29013	/*! EditeMode is not EditNone and Can't Update*/
#define	UGS_EDITMODE_ARENOT_EDITINPROGRESS_EDITADD 29014	/*! ����༭ģʽ��ƥ��*/
#define	UGS_THE_LAYER_NAME_IS_NULL_IN_FINDAVAILABLENAME 29015	/*! �ڷ���һ��������ͼ�����Ʋ�ͬ������ʱ�������ͼ������Ϊ��*/
#define	UGS_GEOARC_RADIUS_IS_NULL               29016	/*! GeoArc�뾶Ϊ0*/
#define	UGS_GEOARC_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29017	/*! GeoArc�����Ƿ�������һ��*/
#define	UGS_GEOCIRCLE_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29018	/*! GeoCircle�����Ƿ�������һ��*/
#define	UGS_FAILED_TO_TRANSFER_GEOCURVE_TO_LINE 29019	/*! GeoCurveת��ΪLineʧ��*/
#define	UGS_GEOMETRY_IS_INVALID                 29020	/*! ���ζ�����Ч*/
#define	UGS_GEOPIE_MAJOR_OR_MINOR_AXIS_SHOULD_MORETHAN_ZERO 29021	/*! ���ε��������Ӧ����0*/
#define	UGS_GETINFO_UNFULFILMENT                29022	/*! ������ݿ�汾�����ռ���Ϣ�Ľӿ�δʵ��*/
#define	UGS_GETTABADJUST_UNFULFILMENT           29023	/*! ��ȡxml��ǩӦ��λ�õĽӿ�δʵ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_GRAPHICS_IS_NULL 29024	/*! GraphicsΪ�գ��ж��ı������Ƿ�ѡ��ʧ��*/
#define	UGS_HASGEOMETRY                         29025	/*! �ж��Ƿ��м�������*/
#define	UGS_ARRAY_IS_NULL                       29026	/*! IDS����Ϊ��*/
#define	UGS_INVALID_ID                          29027	/*! ID�Ƿ�*/
#define	UGS_THE_LAYER_NAME_IS_NULL_IN_ISVALIDNAME 29028	/*! ���ж�ͼ�������Ƿ�Ϸ�ʱ��ָ����ͼ������Ϊ��*/
#define	UGS_LOADINFO_UNFULFILMENT               29029	/*! ����SUW�ļ��汾�ź���Ϣ�Ľӿ�δʵ��*/
#define	UGS_FAILED_TO_SET_EDITING_ENVIRONMENT_FOR_MAPWND_DONOT_LINK_WORKSPACE 29030	/*! ��ͼģ�ⴰ��û�й��������ռ䣬���ñ༭����ʧ��*/
#define	UGS_FAILED_TO_SAVE_SXW_FILE             29031	/*! �洢�����ռ��xml�ļ�ʧ��*/
#define	UGS_MSTERFILE_FULLNAME_S                29032	/*! MasterFile�ļ�ȫ��: %s"*/
#define	UGS_OGRDIVER_IS_S                       29033	/*! OGRDriver Ϊ %s*/
#define	UGS_OGRDRIVER_POINTER_IS_NULL           29034	/*! OGRDriverָ��Ϊ��*/
#define	UGS_FAILED_TO_CHECKMARGINPANMODE_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29035	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ�ײǽ����ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29036	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ����������ʧ��*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29037	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ�����ƶ�ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONDBCLK_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29038	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ�����Ҽ�˫��ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29039	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ�����Ҽ����ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONUP_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29040	/*! ���Ʋ���Ϊ�ջ��߻��ƻ���Ϊ�գ�����Ҽ�����ʧ��*/
#define	UGS_FAILED_TO_ONSIZE_FOR_PDRAWPARAM_IS_NULL 29041	/*! ���Ʋ���Ϊ�գ���ͼ���ڸı��Сʧ��*/
#define	UGS_FAILED_TO_SELECTWITHREGION_FOR_PDRAWPARAM_IS_NULL 29042	/*! ���Ʋ���Ϊ�գ���ѡʧ��*/
#define	UGS_FAILED_TO_BREAK_FOR_PRSBREAKLINES_OR_PRSNEWOBJS_IS_NULL 29043	/*! ��Ҫ����ϵ��߶������ڵļ�¼���������������Ϻ��߶���ļ�¼��Ϊ��
�����ʧ��*/
#define	UGS_FAILED_TO_BREAK_FOR_PRSBREAKLINES_IS_NULL 29044	/*! ��Ҫ����ϵ��߶������ڵļ�¼���ļ�¼��Ϊ0�����ʧ��*/
#define	UGS_QUERYDEF_M_IOS_IS_NULL              29045	/*! QueryDef::m_IDs is null*/
#define	UGS_READCONTENT_UNFULFILMENT            29046	/*! ���ļ��ж�ȡ�ֽ����Ľӿ�δʵ��*/
#define	UGS_ODBC_RTREEINDEX_GET_NODES_FAILED    29047	/*! R��������ȡҶ�ӽ��ʧ��*/
#define	UGS_SAVEINFO_UNFULFILMENT               29048	/*! ����SUW�ļ��汾�ź���Ϣ�Ľӿ�δʵ��*/
#define	UGS_SDB_NOT_SUPPORT_TOPO                29049	/*! SDB������ʱ��֧��Topo���ݼ�*/
#define	UGS_SDX_CREATEDATASOURCE_FAILED         29050	/*! SDX CreateDataSourceʧ�ܣ�*/
#define	UGS_SDX_CREATEDATASOURCE_SUCCESS        29051	/*! SDX CreateDataSource�ɹ���*/
#define	UGS_SMID_VALUE_IS_ZERO                  29052	/*! SMID ��ֵΪ0*/
#define	UGS_SQLPLUS_DELETEMETADATA_FAILED       29053	/*! SQL+����ɾ��Ԫ����ʧ��*/
#define	UGS_DATASETRASTER_NAME_INVALID          29054	/*! SQLPLUSդ�����ݼ�������Ч*/
#define	UGS_DATASETVECTOR_VERSION_REGISTEROPTION_FAILED 29055	/*! SQLPLUSʸ�����ݼ��汾ע��ʧ��*/
#define	UGS_IDS_COUNT_INVALID                   29056	/*! ID�����Ƿ�*/
#define	UGS_TOPO_RULE_ALREADY_EXIST             29057	/*! Topo�����Ѿ�������*/
#define	UGS_UDB_NOT_SUPPORT_DELETEALL           29058	/*! UDB ���治֧��ȫ��ɾ������*/
#define	UGS_UDB_NOT_SUPPORT_GETREACORDCHECKEDBY 29059	/*! UDB ���治֧�ֲ�ѯ��ǰ��¼�������û���������*/
#define	UGS_UDB_NOT_SUPPORT_THIS_VECTOR_TYPE    29060	/*! UDB ���治֧������ʸ�����ݼ�����*/
#define	UGS_UDB_NOT_SUPPORT_DELETE_FIELD        29061	/*! UDB���治֧��ɾ���ֶ�*/
#define	UGS_FAILED_TO_MAKEFIXANGLE              29062	/*! ���������㡢�Ƕȡ�������������һ����ʧ��*/
#define	UGS_FAILED_TO_MAKEFIXLENGTH             29063	/*! �����ϸ��ݳ�����������һ����ʧ��*/
#define	UGS_FAILED_TO_MAKEPARALLELLINE          29064	/*! ����ƽ����ʧ��*/
#define	UGS_FAILED_TO_MAKESAMELINE              29065	/*! UGEditOperater::MakeSameLineʧ��*/
#define	UGS_FAILED_TO_MAKEVERTICALLINE          29066	/*! ���ɴ�ֱ��ʧ��*/
#define	UGS_FAILED_TO_GETPOINT                  29067	/*! �Ӳ�׽Ԫ���в�׽��ʧ��*/
#define	UGS_FAILED_TO_SETPOINT                  29068	/*! ����׽���ĵ�ӵ���׽Ԫ����ʧ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_FAILED_TO_CREATE_UGFONT 29069	/*! �������ʹ���ʧ�ܣ�ѡ���ı�ʧ��*/
#define	UGS_UGIMAGE_IS_NULL                     29070	/*! UGImageΪ��*/
#define	UGS_UGLAYOUTSTORAGE_LOAD_FAILED         29071	/*! ���벼��ʧ��*/
#define	UGS_UGLAYOUTSTORAGE_SAVE_FAILED         29072	/*! ���沼��ʧ��*/
#define	UGS_UGLAYOUTSTORAGES_FROMXML_FAILED     29073	/*! �������������ļ�·����Ϣ��XML�ַ��������첢�򿪲��ּ���ʧ��*/
#define	UGS_FAILED_TO_REDO                      29074	/*! ����ʧ��*/
#define	UGS_FAILED_TO_UNDO                      29075	/*! ����ʧ��*/
#define	UGS_UNEXPECTED_VALUE                    29076	/*! �쳣ֵ*/
#define	UGS_UNZIP_FAILED_OPEN_SUW_FAILED        29077	/*! ��ѹ��ʧ�ܣ���SUW�����ռ�ʧ��*/
#define	UGS_WCS_ERROR                           29078	/*! WCS��������*/
#define	UGS_XML_CHAR_IS_NULL_THAT_CANNOT_FORMAT_GEO 29079	/*! XML�ַ���Ϊ�գ��޷����켸�ζ���*/
#define	UGS_XML_WRONG_FOR_CARDINAL_PARAM_POINTS_SHOULD_MORE_THAN_ZERO 29080	/*! XML����Cardinal ������Ӧ����0*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_LESS_THAN_THREE 29081	/*! XML����GeoArc�Ĳ���������3��*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_SHOULD_MORE_THAN_ZERO 29082	/*! XML����GeoArc�Ĳ�����Ӧ����0*/
#define	UGS_XML_WRONG_FOR_GEOCIRCLE_PARAM_POINTS_LESS_THAN_THREE 29083	/*! XML����GeoCircle�Ĳ���������3��*/
#define	UGS_XML_WRONG_FOR_GEOPOINT_COORDINATE_LESSTHAN_TWO 29084	/*! XML����GeoPoint����������2��*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_CARDINAL_TAB 29085	/*! XML����δ�ҵ�Cardinal��ǩ*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_ELLIPTICARC_TAB 29086	/*! XML����δ�ҵ�EllipticArc��ǩ*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_GEOCURVE_TAB 29087	/*! XML����δ�ҵ�GeoCurve��ǩ*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_TAB       29088	/*! XML����δ�ҵ���ǩ*/
#define	UGS_CANNOT_FORMAT_GEOPIE_FOR_THREE_POINT_IN_ONE_LINE 29089	/*! ���㹲�ߣ��޷�����GeoPie*/
#define	UGS_TRIANGLE_TOPO_ERROR                 29090	/*! ���������˹�ϵ����*/
#define	UGS_FORBID_CUT                          29091	/*! ��������в���������ʧ��*/
#define	UGS_FORBID_DELETE                       29092	/*! ������ɾ��������ɾ��ʧ��*/
#define	UGS_FAILED_TO_INSERTPOINTTOGEOMETRY_FOR_FORBID_BREAKING_LINE 29093	/*! ������׽�����ߣ���ӿ��Ƶ㵽��ǰ������ʧ��*/
#define	UGS_CANNOT_EXPORT_VECTOR_DATASET_TO_VECTOR_FILE 29094	/*! ���ɵ���ʸ�����ݼ�Ϊʸ����ʽ�ļ�*/
#define	UGS_NOT_IN_EDTING_OR_NEVER_EDITED       29095	/*! ���ڱ༭״̬����û�н��й��༭*/
#define	UGS_LAYER_IS_NOT_EXIST                  29096	/*! �����ڴ����ֵ�ͼ��*/
#define	UGS_CANNOT_SUPPORT_APPEND_DIFFERNT_RESOLUTION_IAMGE 29097	/*! ��֧�ֲ�ͬ�ֱ��ʵ�Ӱ�����ݼ�׷��*/
#define	UGS_UNSUPPORT_PIXELFORMAT               29098	/*! ��֧�ֵ����ظ�ʽ*/
#define	UGS_NOT_SUPPORT_THIS_GEOMETRY_FORMAT    29099	/*! ��֧�ֵļ��ζ�������*/
#define	UGS_UNSUPPORT_DATA_TYPE                 29100	/*! ��֧�ֵ���������*/
#define	UGS_NOT_SUPPORT_FILE_TYPE               29101	/*! ��֧�ֵ��ļ�����*/
#define	UGS_UNSUPPORT_CODE_TYPE                 29102	/*! ��֧�ֵı�������*/
#define	UGS_NOT_SUPPORT_THIS_DATASET_TYPE       29103	/*! ��֧�ֵ����ݼ�����*/
#define	UGS_NOT_SUPPORT_THIS_TYPE               29104	/*! ��֧�ָ�����*/
#define	UGS_CANNOT_UPDATE                       29105	/*! ���ܸ���*/
#define	UGS_LAYERS_NEED_NOT_MOVE                29106	/*! ����Ҫ�����ƶ�*/
#define	UGS_FAILED_TO_CONVERT_THEME_VARIABLE_TO_DOUBLE 29107	/*! ר��ͼ����ת˫��������ʧ��*/
#define	UGS_THEME_BASICCLASS_XML_IS_NULL        29108	/*! ר��ͼ�����ȡXML��Ϣ�ַ���Ϊ��*/
#define	UGS_THEME_BASICCLASS_CANNOT_FIND_THEMELABEL_WHEN_READ_XML 29109	/*! ר��ͼ�����ȡXML��Ϣʱ�Ҳ���Theme��ǩ*/
#define	UGS_THEME_POINTER_IS_NULL_WHEN_CONVERT_THEME_TO_DATASET 29110	/*! ר��ͼת���ݼ�ʱר��ͼָ��Ϊ��*/
#define	UGS_THEMES_REMOVE_COUNT_LESSTHAN_ONE    29111	/*! ר��ͼ����ɾ������С��1*/
#define	UGS_THEMES_NOT_FIND_THE_THEME_POINTER   29112	/*! ר��ͼ����û���ҵ���Ӧָ���ר��ͼ*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEGRID 29113	/*! ר��ͼ���ϻ�ȡ�ɼ�Gridר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMELABEL 29114	/*! ר��ͼ���ϻ�ȡ�ɼ���ǩר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEDOTDENSITY 29115	/*! ר��ͼ���ϻ�ȡ�ɼ����ܶ�ר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESYMBOL 29116	/*! ר��ͼ���ϻ�ȡ�ɼ�����ר��ͼʧ��*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESTYLE 29117	/*! ר��ͼ���ϻ�ȡ�ɼ����ר��ͼʧ��*/
#define	UGS_THEMES_READING_XML_STRING_IS_NULL   29118	/*! ר��ͼ���϶�ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_THEMES_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29119	/*! ר��ͼ���϶�ȡXML��Ϣʱ�Ҳ���Themes��ǩ*/
#define	UGS_THEMES_CANNOT_FIND_THE_VERSION_WHEN_READ_XML 29120	/*! ר��ͼ���϶�ȡXML��Ϣʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_CANNOT_MERGE_TWO_GEOMETRY_WITH_DIFFERNT_DIM 29121	/*! ����Geometry��ά�Ȳ�һ�£��޷��ϲ�*/
#define	UGS_TWO_NODES_SAME_ID                   29122	/*! �����ڵ�ID��ͬ*/
#define	UGS_TWO_ARRAY_HAVE_DIFFERNT_SIZE        29123	/*! �������С��ͬ*/
#define	UGS_FAILED_TO_ANALYSE_TWO_NODES         29124	/*! ����֮�����ʧ��*/
#define	UGS_FIND_SHORTPATH                      29125	/*! �����ѯ�����·��*/
#define	UGS_TWO_POINTS_CANNOT_MIRROR            29126	/*! ������ͬ,�޷�����*/
#define	UGS_COUNT_IS_NULL                       29127	/*! ����Ϊ��*/
#define	UGS_COUNT_LESSTHAN_ONE                  29128	/*! ��������һ��*/
#define	UGS_CENTERPOINT_LESSTHAN_SERVICE_COUNT  29129	/*! ���ĵ����С�ڷ�������������*/
#define	UGS_CENTERPOINT_COUNT_LESSTHAN_ZERO     29130	/*! ���ĵ��������0*/
#define	UGS_CENTERPOINT_SIZE_LESSTHAN_ZERO      29131	/*! ���ĵ��СС��0*/
#define	UGS_CENTERPOINTS_DT_IS_NULL             29132	/*! ���ĵ����ݼ�Ϊ��*/
#define	UGS_CENTERPOINT_TYPE_IS_NULL            29133	/*! ���ĵ�����Ϊ��*/
#define	UGS_CENTER_INDEX_IS_NULL                29134	/*! ���ĵ�����Ϊ��*/
#define	UGS_CENTERPOINT_INVALID                 29135	/*! ���ĵ������Ƿ�*/
#define	UGS_CENTER_POINTER_DEMANDE_LESSTHAN_ZERO 29136	/*! ����������СС��0*/
#define	UGS_THE_FIRST_CHAR_OF_WORD_IS_NULL      29137	/*! ����λ��Ϊ��*/
#define	UGS_READ_XML_INFO_FROM_FILE_FAILED_OPEN_SXW_FAILED_S 29138	/*! ���ļ�%s�ж�ȡXML��Ϣʧ��,��SXW�����ռ�ʧ��*/
#define	UGS_READ_XML_INFO_FAILED_OPEN_DB_WORKSPACE_FAILED 29139	/*! ���ļ�%s�ж�ȡXML��Ϣʧ��,�����ݿ⹤���ռ�ʧ��*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE          29140	/*! ���ļ��л�ȡ�������...*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE_D        29141	/*! ���ļ��л�ȡ�������Ϊ��%d*/
#define	UGS_GEOMETRY_POINTER_IS_NULL            29142	/*! ���뼸�ζ���ָ��Ϊ��*/
#define	UGS_IMPORT_POINT3D_IS_NULL              29143	/*! ������ά�����Ϊ��*/
#define	UGS_IMPORT_HANDLE_IS_OUT_EXTENT         29144	/*! ����ľ��Ϊ%d,���ڿ��ƶ��ľ����Χ��*/
#define	UGS_IMPORT_ID_IS_NULL                   29145	/*! �����IDΪ��*/
#define	UGS_FAILED_TO_ONDRAW_FOR_PGRAPHICS_IS_NULL 29146	/*! �����pGraphicsΪ�գ����ƶ���ʧ��*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_IMPORT_UGGRAPHICS_IS_NULL 29147	/*! �����UGGraphicsΪ�գ�ˢ�¼��ζ���ʧ��*/
#define	UGS_FAILED_TO_INVALIDSELECT_FOR_IMPORT_UGGRAPHIC_IS_NULL 29148	/*! �����UGGraphicsΪ�գ�ˢ��ѡ�����ʧ��*/
#define	UGS_UGWORKSPACECONNECTION_M_STRSERVE_IS_NULL_DELETE_WORKSPACE_FAILED 29149	/*! ����Ĺ����ռ����ӵ�m_strServerΪ�գ�ɾ�������ռ�ʧ��*/
#define	UGS_UGWORKSPACECONNECTION_M_STRSERVE_IS_NULL_OPEN_WORKSPACE_FAILED 29150	/*! ����Ĺ����ռ����ӵ�m_strServerΪ�գ��򿪹����ռ�ʧ��*/
#define	UGS_IMPORT_XML_NOT_FIND_MAP_NODE_INFO_UGMAPSTORAGES_FROMXML_FAILED 29151	/*! �����XML�ַ�����û���ҵ���ͼ�Ľڵ���Ϣ��ͨ������xml�ļ������ͼ����ʧ��*/
#define	UGS_IMPORT_XML_NOT_FIND_LAYOUT_NODE_INFO_UGLAYOUTSTORAGES_FROMXML_FAILED 29152	/*! �����XML�ַ�����û���ҵ����ֵĽڵ���Ϣ��ͨ������xml�ļ����첼�ּ���ʧ��*/
#define	UGS_IMPORT_XML_NOT_FIND_NODE_INFO_UGDATASOURCE_FROMXML_FAILED 29153	/*! �����XML�ַ�����û���ҵ�����Դ�Ľڵ���Ϣ��ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_IMPORT_XML_NOT_FIND_RESOURCE_NODE_INFO_UGLAYOUTSTORAGES_FROMXML_FAILED 29154	/*! �����XML�ַ�����û���ҵ���Դ�Ľڵ���Ϣ��ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_IMPORT_XML_STRING_OR_WORKSPACE_NAME_IS_NULL_UGRESOURCES_FROMXML_FAILED 29155	/*! �����XML�ַ���Ϊ�ջ��ߴ���Ĺ����ռ�����Ϊ�գ�ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_IMPORT_XML_STRING_OR_WORKSPACE_NAME_IS_NULL_UGLAYOUTSTORAGES_FROMXML_FAILED 29156	/*! �����XML�ַ���Ϊ�ջ��߹����ռ�����Ϊ�գ�ͨ������xml�ļ����첼�ּ���ʧ��*/
#define	UGS_IMPORT_XML_IS_NULL_UGDATASOURCE_FROMXML_FAILED 29157	/*! �����XML�ַ���Ϊ�գ�ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_IMPORT_XML_IS_NULL_UGMAPSTORAGE_FROMXML_FAILED 29158	/*! �����XML�ַ���Ϊ�գ�ͨ������xml�ļ������ͼ����ʧ��*/
#define	UGS_INVALID_GEODATA                     29159	/*! ����ļ��ζ�����Ч,���Ƽ��ζ���ʧ��*/
#define	UGS_FAILED_TO_INVALIDRECT_FOR_IMPORT_FLASHBOUND_IS_OVERRUN 29160	/*! �����ˢ�·�Χ���ڿ��ӷ�Χ�ڣ�ˢ�¾�������ʧ��*/
#define	UGS_FAILED_TO_INVALIDRECT_FOR_IMPORT_FLASHBOUND_IS_NULL 29161	/*! �����ˢ�·�ΧΪ�գ�ˢ�¾�������ʧ��*/
#define	UGS_IMPORT_TILE_IS_NULL                 29162	/*! �����ͼ��Ϊ��*/
#define	UGS_IMPORT_MAP_NAME_IS_NULL_GET_MAP_FAILED 29163	/*! ����ĵ�ͼ����Ϊ�գ���ȡ��ͼʧ��*/
#define	UGS_FAILED_TO_DRAW_TXT_FOR_THE_STRING_IS_NULL 29164	/*! ������ַ���Ϊ�գ������ı�ʧ��*/
#define	UGS_IMPORT_NAME_IS_NULL_UGLAYOUTSTORAGES_FROMXML_FAILED 29165	/*! ����Ĺ����ռ�����Ϊ�գ�ͨ������xml�ļ����첼�ּ���ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_UGRESOURCES_FROMXML_FAILED 29166	/*! ����Ĺ����ռ�����Ϊ�գ�ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_FAILED_TO_BREAK_FOR_IMPORT_DATASET_OR_BREAKOBJECT_IS_NULL 29167	/*! ��������ݼ�Ϊ�ջ���������ϵĶ���Ϊ�գ�UGEditToolPack::Breakʧ��*/
#define	UGS_FAILED_TO_BREAK_FOR_IMPORT_DATASET_IS_OVERRUN 29168	/*! ��������ݼ����Ͳ�Ϊ�����ݼ����������ݼ���·�����ݼ�����CAD���ݼ������ʧ��*/
#define	UGS_IMPORT_VERSION_ID_NOT_EXIST_UGRESOURCE_FROMXML_FAILED 29169	/*! ����İ汾�Ų����ڣ�ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_IMPORT_VERSION_ID_NOT_EXIST_UGRESOURCE_TOXML_FAILED 29170	/*! ����İ汾�Ų����ڣ�����Դ��Ϣ����Ϊxml�ļ�ʧ��*/
#define	UGS_IMPORT_INDEX_PACKAGE_IS_NULL        29171	/*! �����������Ϊ��*/
#define	UGS_NOT_MATCH                           29172	/*! λ�ô�С�޹أ�û��ƥ��*/
#define	UGS_POS_IS_INVALID                      29173	/*! λ�÷Ƿ�*/
#define	UGS_NOT_SUPPORT_OPEN_LOW_VERSION_DATA   29174	/*! �Ͱ汾�����ݲ�֧�ִ�*/
#define	UGS_WORKSPACE_SAVEAS_SXW_FAILED_SAVEAS_DB_WORKSPACE_FAILED 29175	/*! ���湤���ռ�Ϊ��ʱ��sxw�ļ�ʧ�ܣ�������ݿ⹤���ռ�ʧ��*/
#define	UGS_WORKSPACE_SAVEAS_BINARY_FILE_TO_DB_FAILED 29176	/*! ���湤���ռ�������ļ������ݿ�ʧ��*/
#define	UGS_ODBC_SAVEWORKSPACE_FAILED           29177	/*! ���湤���ռ�ʧ�ܣ�ԭ��%s*/
#define	UGS_SAVE_DATASOURCE_INFO_ERROR          29178	/*! ��������Դ��Ϣ����*/
#define	UGS_LAYERS_SAVED_COUNT_LESSTHAN_ONE     29179	/*! �����ͼ�����С��1*/
#define	UGS_ODBC_SAVEINDEXINFO_FAILED           29180	/*! ����������Ϣʧ��*/
#define	UGS_CANNOT_APPEND_FOR_PIXEL_IS_DIFFERENT 29181	/*! ���ظ�ʽ��һ�£�����׷��*/
#define	UGS_SQLPLUS_METADATA_GET_DATASOURCE_FAILED 29182	/*! Ԫ���ݻ�ȡ����Դʧ��*/
#define	UGS_SQLPLUS_METADATA_GET_DATASET_NAMES_FAILED 29183	/*! Ԫ���ݻ�ȡ���ݼ�����ʧ��*/
#define	UGS_NO_BUSLINE_IN_BUSSTOP               29184	/*! ����վ�㷶Χ������·*/
#define	UGS_NO_BUSSTOP_IN_BUSLINE               29185	/*! ������·��Χ����վ��*/
#define	UGS_INVALID_BUSNETWORK                  29186	/*! ��������*/
#define	UGS_FIND_D_SDX                          29187	/*! ���ҵ�%d�� SDX*/
#define	UGS_LINKDATA_NOT_SUPPORT_QUERY          29188	/*! �������ݲ�֧�ֲ�ѯ*/
#define	UGS_GET_TEMPORARY_TABLE_FAILED_WHEN_RELATE_QUERY 29189	/*! ������ѯʱ����ȡ��ʱ��ʧ��...*/
#define	UGS_ODBC_RASTER_CLOSE_FAILED            29190	/*! �ر�դ�����ݼ�ʧ��*/
#define	UGS_OTHER_INVALID                       29191	/*! ������Ч��Ϣ*/
#define	UGS_INTERNAL_PARAM_NOT_INITIALIZE       29192	/*! �ڲ�������δ��ʼ��*/
#define	UGS_MAP_FAILED_TO_PREPARE_BUFFER        29193	/*! ׼����ͼ����ʧ��*/
#define	UGS_READY_IMPORT_DATA_FILE_S            29194	/*! ׼�����������ļ���%s*/
#define	UGS_CANNOT_WORK_FOR_GEOBOUNDS_AREA_IS_NULL 29195	/*! ���ζ����Bounds���Ϊ0�������޷�����*/
#define	UGS_GEOMETRY_TYPE_INVALID               29196	/*! ���ζ���������Ч*/
#define	UGS_GEOMETRY_INVALID                    29197	/*! ���ζ���Ƿ�*/
#define	UGS_BLOCKCOUNT_ERROR                    29198	/*! �ֿ���Ŀ����*/
#define	UGS_FAILED_TO_ANALYSE                   29199	/*! ����ʧ��*/
#define	UGS_NOT_ENOUGH_SEGMENTS                 29200	/*! �ֶ�������*/
#define	UGS_FAILED_TO_WORDSEGMENT               29201	/*! �ִ�ʧ��*/
#define	UGS_FAILED_TO_ALLOT_MEMORY              29202	/*! �����ڴ�ʧ��*/
#define	UGS_FAILED_INITIALIZE                   29203	/*! ���价����Ϣʧ��*/
#define	UGS_FAILED_ALLOT_HANDLE                 29204	/*! ���价�����ʧ��*/
#define	UGS_FAILED_ALLOT_COST_MEMORY            29205	/*! ���仨���ڴ�ʧ��*/
#define	UGS_CREATE_GRAPHICS_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 29206	/*! ����Graphicsʧ��,׼�����ƻ���ʧ��*/
#define	UGS_CREATE_FROMAT_D_UGBRUSH_FAILED      29207	/*! ��������Ϊ%d�Ļ�ˢʧ��*/
#define	UGS_CREATE_FROMAT_D_UGFONT_FAILED       29208	/*! ��������Ϊ%d������ʧ��*/
#define	UGS_CREATE_FROMAT_D_UGIMAGE_FAILED      29209	/*! ��������Ϊ%d��UGImageʧ��*/
#define	UGS_CREATE_FROMAT_D_UGPEN_FAILED        29210	/*! ��������Ϊ%d�Ļ���ʧ��*/
#define	UGS_CREATE_FORMAT_D_UGRGN_FAILED        29211	/*! ��������Ϊ%d��UGRgnʧ��*/
#define	UGS_CREATE_IMAGE_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 29212	/*! ����Imageʧ��,׼�����ƻ���ʧ��*/
#define	UGS_ODBC_BULID_RETREEINDEX_GET_RTREE_NODEID_FAILED 29213	/*! ����R������ʱ����ȡҶ�ӽ��IDʧ��*/
#define	UGS_BULID_RTREEINDEX_RECORDSETS_IS_NULL 29214	/*! ����R����������¼��Ϊ��*/
#define	UGS_FAILED_TO_CREATE_SMID_SERIAL        29215	/*! ����SmID������ʧ��*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_POINTDT 29216	/*! ����Topo��������ݼ�%sʧ��*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_LINEDT  29217	/*! ����Topo�ߴ������ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_TOPO_DIRTY_DT      29218	/*! ����Topo�������ݼ�%sʧ��*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_REGIONDT 29219	/*! ����Topo��������ݼ�%sʧ��*/
#define	UGS_UGLAYOUTSTORAGE_CREATE_FAILED       29220	/*! ��������ʧ��*/
#define	UGS_UGMAPSTORAGE_CREATE_FAILED          29221	/*! ������ͼʧ��*/
#define	UGS_UGSCENESTORAGE_CREATE_FAILED        29222	/*! ������ά����ʧ��*/
#define	UGS_ODBC_BULIDDYNAMIC_FAILED            29223	/*! ������̬����ʧ��*/
#define	UGS_ODBC_BULID_DYNAMICINDEX_FAILED      29224	/*! ������̬����ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_BULID_QTREE_INDEX_FAILED       29225	/*! �����Ĳ�������ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_BULIDTILE_FAILED               29226	/*! ����ͼ������ʧ�ܣ�ԭ��%s*/
#define	UGS_ODBC_BUILD_TILE_DATASET_FAILED      29227	/*! ����ͼ������ʧ��*/
#define	UGS_ODBC_BULID_TILE_DATASET_FAILED      29228	/*! ����ͼ������ʧ��*/
#define	UGS_ODBC_BULIDTILE_GETFIELDINFO_IS_EMPTY 29229	/*! ����ͼ������ʱ����ȡ�ֶ���Ϣʧ��*/
#define	UGS_CREATE_FIELD_S_FAILED               29230	/*! �����ֶ�[%s]ʧ��*/
#define	UGS_ODBC_BUILD_PYRAMID_DADASET_FAILED   29231	/*! ����Ӱ�������ʧ��*/
#define	UGS_ODBC_BUILDPYRAMID_FAILED            29232	/*! ����Ӱ�������ʧ��*/
#define	UGS_CANNOT_CREATE_DATASOURCE_UGDATASOURCES_FROMXML_FAILED 29233	/*! ��������Դ����Ϊ�գ�ͨ������xml�ļ���������Դ���ϣ��������ӻ������Դʧ��*/
#define	UGS_CREATE_DATASET_S_FAILED             29234	/*! �������ݼ�%sʧ��*/
#define	UGS_SQLPLUS_CREATE_DATASET_VERSION_FAILED 29235	/*! �������ݼ��汾ʧ��*/
#define	UGS_FAILED_TO_CREATE_FILE_TYPE_PARSER   29236	/*! �����ļ���ʽ������ʧ��*/
#define	UGS_CREATE_FILE_FORMAT_PARSER_SUCCESS   29237	/*! �����ļ���ʽ�������ɹ�*/
#define	UGS_ODBC_RASTER_CREATE_FAILED           29238	/*! ����դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_RASTER_DATASET     29239	/*! ����դ�����ݼ���%sʧ��*/
#define	UGS_CREATE_FORMAT_D_GRAPHICS_FAILED     29240	/*! ��������Ϊ%d��Graphicsʧ��*/
#define	UGS_ODBC_CREATEINDEX_FAILED             29241	/*! ��������ʧ��*/
#define	UGS_FAILED_TO_CREATE_INDEX_TABLE        29242	/*! ����������ʧ��*/
#define	UGS_CREATE_RECORDSET_FAILED             29243	/*! ������¼��ʧ��*/
#define	UGS_FAILED_TO_CREATE_TRACEADJMATRIX     29244	/*! ����׷�پ���ʧ��*/
#define	UGS_FAILED_TO_CREAT_ADJMATRIX           29245	/*! �����ڽӾ���ʧ��*/
#define	UGS_FAILED_TO_CREATE_DEMAND_POINTS_FILE 29246	/*! ����������ļ�ʧ��*/
#define	UGS_INITIALIZATION_FAILED               29247	/*! ��ʼ��ʧ��*/
#define	UGS_FAILED_TO_INITIALIZE_TXT_STYLE_FOR_FAILED_TO_ADD_TXTBOUND_TO_BUFFER 29248	/*! ��ʼ���ı����ʧ�ܣ�����ı���Χ��������ʧ��*/
#define	UGS_FAILED_TO_DRAW_TXT_FOR_FAILED_TO_INITIALIZE_TXT_STYLE 29249	/*! ��ʼ���ı����ʧ�ܣ������ı�ʧ��*/
#define	UGS_DELETEMETADATA_INITDATASET_FAILED   29250	/*! ɾ���м�����ʧ�ܣ���ʼ�����ݼ�ʧ��*/
#define	UGS_FAILED_DELETE_POSTFIX               29251	/*! ɾ����׺ʧ��*/
#define	UGS_DELETE_FAILED                       29252	/*! ɾ��ʧ��*/
#define	UGS_SQLPLUS_DELETE_SUBDATASET_FAILED    29253	/*! ɾ�������ݼ�ʧ��*/
#define	UGS_ODBC_DELETEFILED_FAILED             29254	/*! ɾ���ֶ�ʧ��*/
#define	UGS_ODBC_DELETEWORKSPACEINFO_FAILED     29255	/*! ɾ�������ռ���Ϣʧ��*/
#define	UGS_SQLPLUS_DELETE_DATASET_FAILED       29256	/*! ɾ�����ݼ�ʧ��*/
#define	UGS_DROPSPATIALINDEX_FAILED             29257	/*! ɾ���ռ�����ʧ��*/
#define	UGS_ODBC_TRUNCATE_TABLE_FAILED          29258	/*! ɾ�����м�¼ʧ��*/
#define	UGS_ODBC_REMOVEPYRAMIDS_FAILED          29259	/*! ɾ��������ʧ��*/
#define	UGS_RECORDSET_IS_BOF                    29260	/*! �����¼��ͷ*/
#define	UGS_RECORDSET_IS_EOF                    29261	/*! �����¼��β*/
#define	UGS_SQLPLUS_REFRESH_RASTER_REGISTER_FAILED 29262	/*! ˢ�����ݼ�ע����Ϣʧ��*/
#define	UGS_SQLPLUS_REFRESH_VECTOR_REGISTER_FAILED 29263	/*! ˢ�����ݼ�ע����Ϣʧ��*/
#define	UGS_ODBC_FLUSHCURRENTRECORDSET_FAILED   29264	/*! ˢ�¼�¼ʧ��*/
#define	UGS_ODBC_REFRESHPOS_FAILED              29265	/*! ˢ�¼�¼��ʧ��*/
#define	UGS_ODBC_REFRESHOPTION_FAILED           29266	/*! ˢ��ѡ����Ϣʧ��*/
#define	UGS_LAST_EDIT_NOT_FINISH                29267	/*! ǰһ�α༭��û�н���*/
#define	UGS_HAVE_MODIFIED_AND_UPDATE_FAILED     29268	/*! ǰ���Ѿ������޸��Ҹ���ʧ��*/
#define	UGS_LOAD_S_FAILED                       29269	/*! ����%sʧ��*/
#define	UGS_LOAD_S_SUCCESS                      29270	/*! ����%s�ɹ�*/
#define	UGS_FAILED_TO_LOAD_BLOCK                29271	/*! ����Blockʧ��*/
#define	UGS_ODBC_LOADRTREELEAF_FAILED           29272	/*! ����R������Ҷ�ӽڵ�ʧ��*/
#define	UGS_LOAD_SDX_DYNAMIC_LIB_D_SUCCESS_D_FAILED 29273	/*! ����SDX��̬�����: %d ���ɹ���%d��ʧ��"*/
#define	UGS_LOAD_SDX_S_SUCCESS                  29274	/*! ����SDX��s%���ɹ�*/
#define	UGS_ODBC_LOADWORKSPACE_FAILED           29275	/*! ���ع����ռ�ʧ��*/
#define	UGS_LOAD_PROJECT_CONFIG_FILE_ERROR      29276	/*! ���ع��������ļ���%s����*/
#define	UGS_ODBC_RASTER_LOAD_BLOCK_FAILED       29277	/*! ����Ӱ�������ʧ��*/
#define	UGS_LOAD_PRJCONFIG_XML_FAILED           29278	/*! ����ͶӰ�����ļ�%sʧ��*/
#define	UGS_NODE_FAILED_CREATE_DIRECTION        29279	/*! �����ڵ㴴������ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_SWAP          29280	/*! ��ֵר��ͼ����ʧ��*/
#define	UGS_THEMEUNIQUE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29281	/*! ��ֵר��ͼ����XML��Ϣʱ�Ҳ���Theme��ǩ*/
#define	UGS_THEMEUNIQUE_FIELD_INVALID           29282	/*! ��ֵר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMEUNIQUE_FAILED_TO_INSERT_VALUE  29283	/*! ��ֵר��ͼ����ֵ���ڣ�����ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_FIND_THE_VALUE 29284	/*! ��ֵר��ͼ����ֵ�Ķ�Ӧֵʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_FINDSTYLE        29285	/*! ��ֵר��ͼ���ҷ��ʧ��*/
#define	UGS_THEMEUNIQUE_SEGEMENT_COUNT_LESSTHAN_ONE 29286	/*! ��ֵר��ͼ�θ���С��1*/
#define	UGS_THEMEUNIQUE_NOT_FIND_THE_VALUE_CAPTION 29287	/*! ��ֵר��ͼû���ҵ���Ӧֵ�ı���*/
#define	UGS_THEMEUNIQUE_FAILED_TO_ADD_VALUE     29288	/*! ��ֵר��ͼ���ֵ���ڣ����ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_REMOVE        29289	/*! ��ֵר��ͼ�Ƴ�ʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_GET_RECORDSET_FIELD 29290	/*! ��ֵר��ͼ��ȡ��¼���ֶ���Ϣʧ��*/
#define	UGS_THEMEUNIQUE_RECORDSET_COUNT_IS_ZERO 29291	/*! ��ֵר��ͼ��¼������Ϊ��*/
#define	UGS_THEMEUNIQUE_RECORDSET_IS_NULL       29292	/*! ��ֵר��ͼ��¼��Ϊ��*/
#define	UGS_THEMEUNIQUE_RECORDSET_FAILED_TO_GET_FIELDVALUE 29293	/*! ��ֵר��ͼ��¼����ȡ�ֶ�ֵʧ��*/
#define	UGS_THEMEUNIQUE_FAILED_TO_READ_XML      29294	/*! ��ֵר��ͼ��ȡXML��Ϣ�����ȡʧ��*/
#define	UGS_THEMEUNIQUE_READING_XML_STRING_IS_NULL 29295	/*! ��ֵר��ͼ��ȡXML��Ϣ�ַ���Ϊ��*/
#define	UGS_UNINSTALL_S_SUCCESS                 29296	/*! ж��s%�ɹ�*/
#define	UGS_FINISH_UNINSTALL_SDX                29297	/*! ж��SDX�ɹ�*/
#define	UGS_ORIGINAL_CACHEMASTERFILE_S_NOT_EXIST_OR_INVALID_BEGIN_CREATING_NEW_FILE 29298	/*! ԭCacheMasterFile�� %s �����ڻ��߲��Ϸ�,��ʼ�������ļ�...*/
#define	UGS_ORIGINAL_FILE_NAME_IS_NULL          29299	/*! ԭʼ�ļ���Ϊ��,����*/
#define	UGS_ORIGINAL_RECORDSET_IS_NULL          29300	/*! ԭ��¼��Ϊ��*/
#define	UGS_PARAM_IS_NULL                       29301	/*! ����Ϊ��*/
#define	UGS_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29302	/*! ������������һ��*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_MUST_BE_REGION_AND_NOT_NULL 29303	/*! �������󣺴���Geometryָ�����ǿ��ұ����������*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_NOT_NULL_AND_THE_SECOND_GEOMETRY_MUSTBE_REGION 29304	/*! �������󣺴���Geometryָ�����ǿգ��ҵڶ���Geometry����Ϊ�����*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_ANGLE_SHOULD_MORETHAN_ZERO 29305	/*! ��������Բ�Ǿ��ε�Բ�ǻ��ȱ���Ǹ�*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_WIDTH_MUST_MORETHAN_ZERO 29306	/*! ��������Բ�Ǿ��εĿ�ȱ������0*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_HEIGHT_MUST_MORETHAN_ZERO 29307	/*! ��������Բ�Ǿ��εĸ߶ȱ������0*/
#define	UGS_INVALID_PARAM_FOR_INVALID_M         29308	/*! ����������Ч��Mֵ����ö�ٱ���*/
#define	UGS_PARAM_INVALID_FOR_ELLIPSE_MAJORANDMINOR_AXIS_SHOULD_MORETHAN_ZERO 29309	/*! ����������Բ�ĳ����ᶼ�������0*/
#define	UGS_PARAM_INVALID_FOR_POINTS_POINTER_IS_NULL 29310	/*! �������󣺵㴮ָ��Ϊ��*/
#define	UGS_INVALID_PARAM_FOR_INVALID_SHILD_OBJECT 29311	/*! �������󣺷Ƿ����Ӷ���*/
#define	UGS_INVALID_PARAM                       29312	/*! �����Ƿ�*/
#define	UGS_INVALID_PARAM_FOR_GEOMETRY_POINTER_IS_NULL 29313	/*! �����Ƿ���Geometryָ��Ϊ��*/
#define	UGS_PARAM_INVALID_FOR_NO_OVERLAPING_POINTS_SHOULD_MORETHAN_SIX 29314	/*! �����Ƿ������غϵĵ���Ӧ����6*/
#define	UGS_INVALID_PARAM_FOR_CHILD_OBJECT_NEED_MORETHAN_TWO_POINTS 29315	/*! �����Ƿ����Ӷ���������Ҫ2����*/
#define	UGS_PARAM_INVALID_FOR_POINTS_SHOULD_MORETHAN_ZERO 29316	/*! �����Ƿ����㴮Ӧ�ǿ��ҵ�������0*/
#define	UGS_INVALID_PARAM_FOR_AT_LEAST_TWO_POINTS 29317	/*! �����Ƿ���������Ҫ2����*/
#define	UGS_INVALID_PARAM_FOR_AT_LEAST_FOUR_POINTS 29318	/*! �����Ƿ���������Ҫ�ĸ���*/
#define	UGS_FAILED_TO_UNREGISTER_VERSION        29319	/*! ��ע��汾ʧ�ܣ�*/
#define	UGS_OVERLAP_FAILED_TO_TOPO              29320	/*! ���ӷ������˴���ʧ��*/
#define	UGS_OVERLAYANALYSIS_DATASET_TYPE_NOT_MATCH 29321	/*! ���ӷ������ݼ����Ͳ�ƥ��*/
#define	UGS_OVERLAP_TYPE_NOT_MATCH              29322	/*! ���ӷ������Ͳ�ƥ��*/
#define	UGS_TRANSEFER_ANOTHER_SAVEAS_METHOD_SAVEAS_DB_WORKSPACE_FAILED 29323	/*! ��湤���ռ�Ϊ���ݿ⹤���ռ�ʧ�ܣ������SaveAs������һ���ӿ�*/
#define	UGS_WORKSPACE_SAVEAS_FILE_CANNOT_DELETE_FILE_EXIST 29324	/*! ��湤���ռ�Ϊ�ļ��͹����ռ䣬�ļ��Ѿ����ڲ����޷�ɾ��*/
#define	UGS_WORKSPACE_SAVEAS_FILE_SET_FILE_NOT_COVER_FILE_EXIST 29325	/*! ��湤���ռ�Ϊ�ļ��͹����ռ䣬�������ļ����ھͲ����ǣ����ļ��Ѿ�����*/
#define	UGS_ONLY_ONE_ARC                        29326	/*! ֻ��һ��ARC*/
#define	UGS_READONLY_CANNOT_MODIFY              29327	/*! ֻ�����ԣ������޸�*/
#define	UGS_READONLY_DATASOURCE_CANNOT_CREATE_DATASET 29328	/*! ֻ�����ݲ��ܴ������ݼ�*/
#define	UGS_DATASOURCE_READONLY_CANNOT_CREATE_DATASET 29329	/*! ֻ������Դ�����ܴ������ݼ�*/
#define	UGS_DATASOURCE_READONLY_CANNOT_OPERATE  29330	/*! ֻ������Դ�����ܽ��в���*/
#define	UGS_ODBC_VECTOR_READONLY                29331	/*! ֻ�����ݼ�*/
#define	UGS_FAILED_TO_ONDELETE_FOR_THE_LAYER_OR_DATASET_IS_NULL 29332	/*! �ɱ༭ͼ��Ϊ�ջ��߿ɱ༭ͼ���Ӧ�����ݼ�Ϊ�գ�UGMapWnd::OnDeleteʧ��*/
#define	UGS_FAILED_TO_CUT_FOR_LAYER_IS_NULL     29333	/*! �ɱ༭ͼ����Ϊ0��UGMapWnd::Cutʧ��*/
#define	UGS_EDITING_RECORDSET_NOT_SUPPORT_STATISTIC_QUERY 29334	/*! �ɱ༭��¼����֧��ͳ�Ʋ�ѯ*/
#define	UGS_HOMONYMY_DATASET_EXIST              29335	/*! ͬ�����ݼ��Ѿ�����*/
#define	UGS_NAME_NOT_EXIST_UGLAYOUTSTORAGE_CLONE_FAILED 29336	/*! ����Ϊ%s�Ĳ��ֲ����ڣ���¡ʧ��*/
#define	UGS_NAME_NOT_EXIST_UGLAYOUTSTORAGE_REMOVE_FAILED 29337	/*! ����Ϊ%s�Ĳ��ֲ����ڣ��Ƴ�ʧ��*/
#define	UGS_NAME_IS_EXIST_UGLAYOUTSTORAGE_CLONE_FAILED 29338	/*! ����Ϊ%s�Ĳ����Ѿ����ڣ���¡ʧ��*/
#define	UGS_UGMAPSTORAGE_NAME_NOT_EXIST_REMOVE_FAILED 29339	/*! ����Ϊ%s�ĵ�ͼ�����ڣ��Ƴ�ʧ��*/
#define	UGS_NAME_NOT_EXIST_UGMAPSTORAGE_RENAME_FAILED 29340	/*! ����Ϊ%s�ĵ�ͼ�����ڣ�������ʧ��*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_CLONE_FAILED 29341	/*! ����Ϊ%s�ĵ�ͼ�Ѿ����ڣ���¡ʧ��*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_ADD_FAILED 29342	/*! ����Ϊ%s�ĵ�ͼ�Ѿ����ڣ����ʧ��*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_RENAME_FAILED 29343	/*! ����Ϊ%s�ĵ�ͼ�Ѿ����ڣ�������ʧ��*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST_CLONE_FAILED 29344	/*! ����Ϊ%s����ά���������ڣ���¡ʧ��*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST_REMOVE_FAILED 29345	/*! ����Ϊ%s����ά���������ڣ��Ƴ�ʧ��*/
#define	UGS_UGSCENESTORAGE_NAME_IS_EXIST_CLONE_FAILED 29346	/*! ����Ϊ%s����ά�����Ѿ����ڣ���¡ʧ��*/
#define	UGS_NAME_NOT_EXIST_MODIFY_LAYOUT_NAME_FAILED 29347	/*! ����Ϊ%s�Ĳ��ֲ����ڣ��޸Ĳ�������ʧ��*/
#define	UGS_NAME_IS_EXIST_FAILED_TO_ADD_LAYOUT  29348	/*! ����Ϊ%s�Ĳ����Ѿ����ڣ���Ӳ���ʧ��*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_FIXED_LENGTH_IS_TOO_SHORT 29349	/*! �̶�����̫�̣��̶�����ʧ��*/
#define	UGS_INVALID_DATASET_WHEN_PREPARE_SEARCHING 29350	/*! ͼ��׼����ѯ����ʱ���ݼ����Ϸ�*/
#define	UGS_LAYER_DATASET_IS_INVALID            29351	/*! ͼ���Ӧ�����ݼ����Ϸ�*/
#define	UGS_FAILED_TO_ONKEYDOWN_FOR_LAYER_IS_NULL 29352	/*! ͼ����Ϊ0������ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDBCLK_FOR_LAYER_IS_NULL 29353	/*! ͼ����Ϊ0��������˫��ʧ��*/
#define	UGS_HITTEST_INVALID_DATASET             29354	/*! ͼ����ʱ���ݼ����Ϸ�*/
#define	UGS_LAYER_TYPE_INVLAID                  29355	/*! ͼ��������Ч*/
#define	UGS_INVALID_LAYER_INDEX                 29356	/*! ͼ�������Ƿ�*/
#define	UGS_DATASET_IS_NULL_OR_ATTRIBUTE_WHEN_DRAWING 29357	/*! ͼ�����ʱ���ݼ�Ϊ�ջ���Ϊ���Ա����ݼ�*/
#define	UGS_DATASET_IS_NULL_OR_TABLE_WHEN_SETTING_LAYER 29358	/*! ͼ���������ݼ�ʱ���ݼ�Ϊ�ջ���Ϊ������ݼ�*/
#define	UGS_MAPBREADTH_CACHEFILE_ERROR          29359	/*! ͼ�� %d �Ļ����ļ�����*/
#define	UGS_MAP_BREADTH_QUERY_GET_ID_FAILED     29360	/*! ͼ���ռ��ѯ��ȡͼ��IDʧ��!*/
#define	UGS_IDXTILE_DOESNOT_SUPPORT_REBUILD     29361	/*! ͼ��������֧���ؽ�*/
#define	UGS_ODBC_LIBTILE_BOUNDS_DONOT_FIT       29362	/*! ͼ����Χ����*/
#define	UGS_ODBC_LIBTILE_COUNT_OVERLIMIT        29363	/*! ͼ����¼��������*/
#define	UGS_FAILED_TO_SAVE_FOR_QUERY_RECORDSET_IS_NULL 29364	/*! �ڱ༭ͼ���Ӧ�����ݼ��в�ѯ��¼�����ؿգ�����༭����ʧ��*/
#define	UGS_FAILED_TO_SAVE_FOR_FAILED_TO_SEARCH_OBJECT_ID 29365	/*! �ڱ༭�������ڵļ�¼���в��ұ༭�����IDʧ�ܣ�����༭����ʧ��*/
#define	UGS_MAP_AVISIBLE_BOUNDS_TOO_SMALL_TO_DRAW 29366	/*! ��ͼ��ʾ��Χ̫С������ʧ��*/
#define	UGS_MAP_SCALE_IS_ZERO                   29367	/*! ��ͼ������Ϊ��*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_NOT_RESPOND_THE_MOUSE_EVENT 29368	/*! ��ͼ��һ�λ�û�л��Ƴ���������Ӧ����¼�������ƶ�ʧ��*/
#define	UGS_ADDRESS_IS_NULL                     29369	/*! ��ַ��Ϊ��*/
#define	UGS_COORDINATE_OVERRUN                  29370	/*! ����ֵ����ͼ����Χ*/
#define	UGS_INVALID_COORDINATE_BOUND            29371	/*! ���귶Χ���Ϸ�*/
#define	UGS_COORDINATE_CONVER_TO_NODE_FAILED    29372	/*! ����ת��Ϊ�ڵ�ʧ��*/
#define	UGS_FAILED_TO_SEARCHLOOP_BASEON_ARC     29373	/*! ���ڻ��β�ѯ������ͨ��·ʧ��*/
#define	UGS_DEAL_WITH_DATAFILE_S_FAILED         29374	/*! ���������ļ�:%s ʧ��*/
#define	UGS_DEAL_WITH_DATAFILE_S_SUCCESS        29375	/*! ���������ļ�:%s �ɹ�*/
#define	UGS_ODBC_DS_DISPOSE_VERSION_FAILED      29376	/*! ����汾ʧ��*/
#define	UGS_ODBC_DISPOSE_INDEX_FAILED           29377	/*! ��������ʧ��*/
#define	UGS_ODBC_COPYFIELD_FAILED               29378	/*! �����ֶ�ʧ��*/
#define	UGS_FAILED_TO_SPLITGEOCOMPOUND_FOR_CHILD_OBJECT_IS_NULL 29379	/*! ���϶����Ӷ������Ϊ0����ָ��϶���ʧ��*/
#define	UGS_FAILED_TO_MTSP                      29380	/*! �������̷���ʧ��*/
#define	UGS_REGION_COUNT_LESSTHAN_ZERO          29381	/*! ����εĸ���С��0*/
#define	UGS_COUNT_DIFFERNT_WITH_WORD            29382	/*! ��С�ʹʵĵĸ�����һ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_WIDTH_OVERRUN 29383	/*! �����ȴ��������Ӵ�С��������߶�С����С���Ӵ�С��ѡ���ı�ʧ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_HEIGHT_IS_ZERO 29384	/*! ����߶�Ϊ0��ѡ���ı�ʧ��*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_HEIGHT_OVERRUN 29385	/*! ����߶ȴ��������Ӵ�С��������߶�С����С���Ӵ�С��ѡ���ı�ʧ��*/
#define	UGS_FIELD_IS_EMPTY                      29386	/*! �ֶ�Ϊ��*/
#define	UGS_FIELD_INFO_INVALID                  29387	/*! �ֶ���Ϣ��Ч*/
#define	UGS_FIELD_NAME_INVALID                  29388	/*! �ֶ����Ƿ�*/
#define	UGS_INVALID_FIELD_NAME_CREATE_FAILED    29389	/*! �ֶ����Ƿ��������ֶ�ʧ��*/
#define	UGS_FIELD_INDEX_INVALID                 29390	/*! �ֶ������Ƿ�*/
#define	UGS_INDEX_OF_FIELD_OUTOF_BOUNDS         29391	/*! �ֶ�Խ��*/
#define	UGS_STRING_IS_NULL                      29392	/*! �ַ���Ϊ��*/
#define	UGS_ODBC_RASTER_SAVEINFO_FAILED         29393	/*! �洢դ����Ϣʧ��*/
#define	UGS_FINISH_IMPORT_THE_SINGLE_BAND       29394	/*! ��ɵ��������ݵ���*/
#define	UGS_FINISH_IMPORT_THE_D_BAND            29395	/*! ��ɵ� %d �����ε���*/
#define	UGS_TOLERANCE_TOO_SMALL                 29396	/*! ����̫С*/
#define	UGS_PASSWORD_ERROR_OPEN_SUW_FAILED      29397	/*! ������󣬴�SUW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_DCTCODE_FOR_BLOCK         29398	/*! ��Block����DCT����ʧ��*/
#define	UGS_SPATIALQUERY_GEOMETRY               29399	/*! �Էǿռ����ݼ����пռ��ѯ*/
#define	UGS_FINISH_IMPROT_RASTER                29400	/*! ����դ���������*/
#define	UGS_ODBC_VERSION_DATASET_COPY_DATA_BY_VERSION_FAILED 29401	/*! ��A������׷�ӵ�����ʧ��*/
#define	UGS_RECORDSET_ISNOT_MOVEFIRST           29402	/*! ��δ�ƶ�����һ����¼*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_MODIFY_FAILED 29403	/*! �����ռ���û�б���Ϊ%s������Դ���޸ı���ʧ��*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_SEARCH_FAILED 29404	/*! �����ռ���û�б���Ϊ%s������Դ�����ұ���ʧ��*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_GET_ALIAS_FAILED 29405	/*! �����ռ���û�б���Ϊ%s������Դ����ȡ����ʧ��*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_RELEASE_FAILED 29406	/*! �����ռ���û�б���Ϊ%s������Դ���ͷ�ʧ��*/
#define	UGS_NO_INDEX_IN_WORKSPACE_RELEASE_FAILED 29407	/*! �����ռ���û������Ϊ%d������Դ���ͷ�ʧ��*/
#define	UGS_WORKSPACE_IS_NULL                   29408	/*! �����ռ�Ϊ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVE_WORKSPACE_FAILED 29409	/*! �����ռ�����Ϊ�գ����湤���ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_SUW_FAILED 29410	/*! �����ռ�����Ϊ�գ����SUW�����ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_SXW_FAILED 29411	/*! �����ռ�����Ϊ�գ����SXW�����ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_DB_WORKSPACE_FAILED 29412	/*! �����ռ�����Ϊ�գ�������ݿ⹤���ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_FILE_WORKSPACE_FAILED 29413	/*! �����ռ�����Ϊ�գ�����ļ��͹����ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_OPEN_SUW_FAILED 29414	/*! �����ռ�����Ϊ�գ���SUW�����ռ�ʧ��*/
#define	UGS_WORKSPACE_NAME_IS_NULL_OPEN_WORKSPACE_FAILED 29415	/*! �����ռ�����Ϊ�գ��򿪹����ռ�ʧ��*/
#define	UGS_MAP_FAILED_TO_SAVE_FOR_WORKSPACE_POINTER_IS_NULL 29416	/*! �����ռ�ָ��Ϊ�գ������ͼʧ��*/
#define	UGS_MAP_FAILED_TO_SAVEAS_FOR_WORKSPACE_POINTER_IS_NULL 29417	/*! �����ռ�ָ��Ϊ�գ�����ͼʧ��*/
#define	UGS_WORKSPACE_NOT_EXIST_DELETE_WORKSPACE_FAILED 29418	/*! �����ռ��ļ������ڣ�ɾ���ļ��͹����ռ�ʧ��*/
#define	UGS_WORKSPACE_NOT_EXIST_OPEN_FILE_WORKSPACE_FAILED 29419	/*! �����ռ��ļ������ڣ����ļ��͹����ռ�ʧ��*/
#define	UGS_WORKSPACE_FILE_OPEN_FAILED_SAVEAS_SUW_FAILED 29420	/*! �����ռ��ļ���ʧ�ܣ����SUW�����ռ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_SUW_FOR_FAILED_TO_OPEN_WORKSPACE_FILE 29421	/*! �����ռ��ļ���ʧ�ܣ���SUW�����ռ�ʧ��*/
#define	UGS_UNKOWN_VERSION_ID_SAVE_WORKSPACE_FAILED 29422	/*! �����ռ�汾δ֪�����湤���ռ�ʧ��*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION_SAVEAS_SXW_FAILED 29423	/*! �����ռ�汾δ֪�����SXW�����ռ�ʧ��*/
#define	UGS_UNKOWN_VERSION_ID_SAVEAS_WORKSPACE_FAILED 29424	/*! �����ռ�汾δ֪����湤���ռ�ʧ��*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION_OPEN_SUW_FAILED 29425	/*! �����ռ�汾δ֪����SUW�����ռ�ʧ��*/
#define	UGS_ALREADY_IN_EDITING                  29426	/*! �Ѿ��ڱ༭״̬��*/
#define	UGS_EXIST                               29427	/*! �Ѿ�����*/
#define	UGS_ALREADY_IMPORT_D_OBJECT             29428	/*! �Ѿ�����%ld������*/
#define	UGS_HAS_BULIDPYRAMID                    29429	/*! �Ѿ�����������*/
#define	UGS_ALREADY_FULL_EXTENT                 29430	/*! �Ѿ���ȫ����ʾ�ˣ�ȫ����ʾʧ��*/
#define	UGS_FAILED_TO_PUSH_FOR_BUFFER_OVERRUN   29431	/*! �Ѿ��������Ļ��������ˣ�UGEditSnapBuffer::Pushʧ��*/
#define	UGS_FAILED_BUILD_SINGLE_GRADE           29432	/*! �������������ȼ�ʧ��*/
#define	UGS_BULIDPYRAMID_FAILED                 29433	/*! ����������ʧ��*/
#define	UGS_BEGIN_LOADING_SDX_DYNAMAIC_LIB      29434	/*! ��ʼ����SDX��̬��*/
#define	UGS_BEGIN_LOADING_SDX                   29435	/*! ��ʼ����SDX��*/
#define	UGS_BEGIN_UNINSTALL_SDX                 29436	/*! ��ʼж��SDX*/
#define	UGS_BEGIN_IMPORTING_DATA                29437	/*! ��ʼ��������..*/
#define	UGS_BEGIN_IMPORTING_RASTER              29438	/*! ��ʼ����դ������...*/
#define	UGS_ENGINE_NOT_HAVE_THE_ABILITY         29439	/*! null*/
#define	UGS_ODBCCONNECTION_INITALIZE_FAILED     29440	/*! ����û����������*/
#define	UGS_ARC_SELECTIONCOUNT_IS_NULL          29441	/*! null*/
#define	UGS_EDGEFIELD_IS_NULL                   29442	/*! ���θ���Ϊ��*/
#define	UGS_ARC_LENGTH_LESSTHAN_ZERO            29443	/*! ���εĴ�СС��0*/
#define	UGS_FAILED_CONVERT_ARC_TO_NODE          29444	/*! ����ת��Ϊ�ڵ�ʧ��*/
#define	UGS_INVALID_MERGE_BUSSTOP_ID            29445	/*! �鲢վ��ID�Ƿ�*/
#define	UGS_DIVMATRIX_POINTER_NULL              29446	/*! ��Լ����ָ��Ϊ��*/
#define	UGS_EDITING_NOW_PLEASE_EDIT_AFTER       29447	/*! ��ǰ���ڱ༭�У�����»�ȡ������֮���ٱ༭*/
#define	UGS_SQLPLUS_VESION_DATASET_POSTTOMAINVERSION_FAILED 29448	/*! ��ǰ�汾�ύ�����汾ʧ��*/
#define	UGS_CURRENT_VERSION_DATASOURCE_NOT_SUPPORT_THIS_TYPE_DATASET 29449	/*! ��ǰ�汾������Դ��֧�ִ����͵����ݼ�*/
#define	UGS_FAILED_TO_ONCUT_FOR_CURRENT_STATE_IS_UNEDITABLE 29450	/*! ��ǰ״̬���ɱ༭������ʧ��*/
#define	UGS_FAILED_TO_ONDELETE_FOR_CURRENT_STATE_IS_UNEDITABLE 29451	/*! ��ǰ״̬���ɱ༭��ɾ��ʧ��*/
#define	UGS_FAILED_TO_ONREDO_FOR_CURRENT_STATE_IS_UNEDITABLE 29452	/*! ��ǰ״̬���ɱ༭������ʧ��*/
#define	UGS_FAILED_TO_ONUNDO_FOR_CURRENT_STATE_IS_UNEDITABLE 29453	/*! ��ǰ״̬���ɱ༭������ʧ��*/
#define	UGS_FAILED_LINE_FIX_ANGLE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29454	/*! ��ǰ���ƶ��������ߣ�����Σ�ͬһ�߶γɹ̶��Ƕ�ʧ��*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29455	/*! ��ǰ���ƶ��������ߣ�����Σ��̶�����ʧ��*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29456	/*! ��ǰ���ƶ��������ߣ�����Σ�����ƽ����ʧ��*/
#define	UGS_FAILED_LINE_VERTICAL_LINE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29457	/*! ��ǰ���ƶ��������ߣ�����Σ����ƴ�ֱ��ʧ��*/
#define	UGS_FAILED_LINE_FIX_ANGLE_FOR_CURRENT_OBJECT_IS_NULL 29458	/*! ��ǰ���ƶ���Ϊ�գ�ͬһ�߶γɹ̶��Ƕ�ʧ��*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_CURRENT_OBJECT_IS_NULL 29459	/*! ��ǰ���ƶ���Ϊ�գ��̶�����ʧ��*/
#define	UGS_FAILED_LINE_IS_HORV_FOR_CURRENT_OBJECT_IS_NULL 29460	/*! ��ǰ���ƶ���Ϊ�գ�����ƽ�л��ߴ�ֱ��ʧ��*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_OBJECT_IS_NULL 29461	/*! ��ǰ���ƶ���Ϊ�գ�����ƽ����ʧ��*/
#define	UGS_FAILED_LINE_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29462	/*! ��ǰ���Ʒ�ΧΪ�գ��߾�����ʧ��*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_BOUND_IS_NULL 29463	/*! ��ǰ���Ʒ�ΧΪ�գ�����ƽ����ʧ��*/
#define	UGS_FAILED_LINE_VERTICAL_LINE_FOR_CURRENT_BOUND_IS_NULL 29464	/*! ��ǰ���Ʒ�ΧΪ�գ����ƴ�ֱ��ʧ��*/
#define	UGS_FAILED_POINT_AT_LINE_EXTEND_FOR_CURRENT_BOUND_IS_NULL 29465	/*! ��ǰ���Ʒ�ΧΪ�գ������ӳ�����ʧ��*/
#define	UGS_FAILED_POINT_EXTEND_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29466	/*! ��ǰ���Ʒ�ΧΪ�գ�������ͼ�ص�ˮƽ����ֱʧ��*/
#define	UGS_FAILED_POINT_IN_LINE_MIDDLE_FOR_CURRENT_BOUND_IS_NULL 29467	/*! ��ǰ���Ʒ�ΧΪ�գ��������е�ʧ��*/
#define	UGS_FAILED_POINT_ON_LINESTARTOREND_FOR_CURRENT_BOUND_IS_NULL 29468	/*! ��ǰ���Ʒ�ΧΪ�գ������ߵĶ˵�ʧ��*/
#define	UGS_FAILED_POINT_ON_LINE_FOR_CURRENT_BOUND_IS_NULL 29469	/*! ��ǰ���Ʒ�ΧΪ�գ���������ʧ��*/
#define	UGS_FAILED_POINT_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29470	/*! ��ǰ���Ʒ�ΧΪ�գ����غ�ʧ��*/
#define	UGS_FAILED_TO_SNAP_FOR_CURRENT_BOUND_IS_NULL 29471	/*! ��ǰ���Ʒ�ΧΪ�գ���׽ʧ��*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_EQUIPMENT_COORDINATE_IS_NULL 29472	/*! ��ǰ���Ʒ�Χת�����豸����Ϊ�գ�����դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_COMMIT_EDIT_FOR_THE_CURRENT_DATASET_OR_LAYER_IS_NULL 29473	/*! ��ǰ�༭ͼ��Ϊ�ջ��ߵ�ǰ�༭ͼ���Ӧ�����ݼ�Ϊ�գ��ύ�༭ʧ��*/
#define	UGS_FAILED_TO_ISREDOTOOLENABLE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29474	/*! ��ǰ�༭�Ӷ���Ϊ�գ��ж��Ƿ���Իָ���һ������ʧ��*/
#define	UGS_FAILED_TO_ISUNDOTOOLENABLE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29475	/*! ��ǰ�༭�Ӷ���Ϊ�գ��ж��Ƿ���Գ�����һ������ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDBLCLK_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29476	/*! ��ǰ�༭�Ӷ���Ϊ�գ�������˫��ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29477	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����������ʧ��*/
#define	UGS_FAILED_TO_ONLBUTTONUP_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29478	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����������ʧ��*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29479	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����ƶ�ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29480	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����Ҽ�����ʧ��*/
#define	UGS_FAILED_TO_ONRBUTTONUP_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29481	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����Ҽ�����ʧ��*/
#define	UGS_FAILED_TO_ONREDO_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29482	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����ʧ��*/
#define	UGS_FAILED_TO_ONSETCURSOR_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29483	/*! ��ǰ�༭�Ӷ���Ϊ�գ����ù��ʧ��*/
#define	UGS_FAILED_TO_ONUNDO_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29484	/*! ��ǰ�༭�Ӷ���Ϊ�գ�����ʧ��*/
#define	UGS_FAILED_TO_COMPLETE_EDITING_FOR_CURRENT_COMPOUND_OBJECT_IS_NULL 29485	/*! ��ǰ�༭����Ϊ���϶��󣬲���Ϊ�գ���ɱ༭����ʧ��*/
#define	UGS_FAILED_TO_MERGE_FOR_CURRENT_OBJECT_IS_NULL 29486	/*! ��ǰ�༭����Ϊ�գ��ϲ�ʧ��*/
#define	UGS_CURRENT_EDITING_OBJECT_IS_NULL_ONDRAW_NOT_DRAW 29487	/*! ��ǰ�༭����Ϊ�գ�����δ���ƶ���*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_CURRENT_OBJECT_IS_NULL 29488	/*! ��ǰ�༭����Ϊ�գ�����Ҽ����ʧ��*/
#define	UGS_FAILED_TO_SAVE_FOR_CURRENT_OBJECT_IS_NULL 29489	/*! ��ǰ�༭����Ϊ�գ�����༭����ʧ��*/
#define	UGS_FAILED_TO_COMPLETE_EDITING_FOR_CURRENT_OBJECT_IS_NULL 29490	/*! ��ǰ�༭����Ϊ�գ���ɱ༭����ʧ��*/
#define	UGS_FAILED_TO_CALCULATE_FOR_CURRENT_OBJECT_IS_NULL 29491	/*! ��ǰ�༭����Ϊ�գ����㸨���߸�����ʧ��*/
#define	UGS_CURRENT_RECORD_IS_NULL              29492	/*! ��ǰ��¼Ϊ��*/
#define	UGS_CURRENT_RECOR_POINT_TO_BOF_OR_EOF   29493	/*! ��ǰ��¼ָ���ļ�ͷ�����ļ�β*/
#define	UGS_CURRENT_DATASET_CANNOT_EDIT         29494	/*! ��ǰ��¼�����ܱ༭*/
#define	UGS_CURRENT_RECORSET_POINT_TO_BOF_OR_EOF 29495	/*! ��ǰ��¼��ָ���ļ�ͷ�����ļ�β*/
#define	UGS_CURRENT_DATASET_IS_LOCKED_CANNOT_EDIT 29496	/*! ��ǰ��¼���������û����������ܱ༭*/
#define	UGS_FAILED_TO_CALCULATE_BOUND_FOR_SELECTED_OBJETS_IS_NULL 29497	/*! ��ǰѡ�ж������Ϊ0������ѡ�ж����ܷ�Χʧ��*/
#define	UGS_FAILED_TO_SETACCESSIBILITYACTIONPOINTMODE_FOR_SELECTED_OBJETS_ISNOT_ONE 29498	/*! ��ǰѡ�ж���ĸ�����Ϊ1�����ý��༭ģʽʧ��*/
#define	UGS_CURRENT_HEIGHT_OR_WIDTH_IS_ZERO_ADJUST_SCALE_COEFFICIENT_FAILED 29499	/*! ��ǰ�߼���Χ�߶Ȼ��߿��Ϊ0����������ϵ��ʧ��*/
#define	UGS_IMAGE_BLOCK_POINTER_IS_NULL         29500	/*! Ӱ���ָ��Ϊ��*/
#define	UGS_FAILED_TO_DRAW_IMAGE_FOR_IMAGE_BOUNDS_IS_NULL 29501	/*! Ӱ���ķ�ΧΪ�գ�����Ӱ���ʧ��*/
#define	UGS_FAILED_TO_GET_CENTERPOINT_SERVICE_DATASET 29502	/*! �õ����ĵ�������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_CENTERPOINT           29503	/*! �õ��м��ʧ��*/
#define	UGS_GEOMETRY_GETTED_IS_NULL             29504	/*! �õ����ζ���Ϊ��*/
#define	UGS_GET_GEOMETRY_OBJECTS_FAILED         29505	/*! �õ����ζ���ʧ��*/
#define	UGS_SQLPLUS_GETSEQVALUE_FAILED          29506	/*! �õ����л���ֵʧ��*/
#define	UGS_INSERTPOS_INVALID                   29507	/*! �õ�����λ�÷Ƿ�*/
#define	UGS_FAILED_TO_GET_DATASET_POINTER       29508	/*! �õ����ݼ�ָ��ʧ��*/
#define	UGS_FAILED_TO_GET_NETWORK_FIELD         29509	/*! �õ��������ݼ��ֶ�ʧ��*/
#define	UGS_NETWORK_FAILED_TO_GET_NODEDT        29510	/*! �õ���������ݼ�ʧ��*/
#define	UGS_FAILED_TO_GET_COST_PARAM            29511	/*! �õ����Ѳ���ʧ��*/
#define	UGS_FAILED_TO_GET_COST                  29512	/*! �õ�����ʧ��*/
#define	UGS_FAILED_TO_GET_COST_FILED            29513	/*! �õ������ֶ�ʧ��*/
#define	UGS_FAILED_TO_GET_WORD_FREQUENCY        29514	/*! �õ��ʴ�Ƶ��ʧ��*/
#define	UGS_LAYERS_CANNOT_ADD_FOR_CANNOT_OPEN_DATASET 29515	/*! �򲻿����ݼ����޷�����*/
#define	UGS_PRINT_SCALE_IS_ZERO                 29516	/*! ��ӡ������Ϊ��*/
#define	UGS_FAILED_TO_PRINT_FOR_HEIGHT_OR_WIDTH_LESS_THAN_TEN 29517	/*! ��ӡ�ĸ߶Ȼ��߿��С��10����ӡʧ��*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_ZERO 29518	/*! ��5.0�汾����Դʧ��*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_THREE 29519	/*! ��5.3�汾����Դʧ��*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTY_AND_AGO 29520	/*! ��50��ǰ�汾������ʧ��*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTYONE     29521	/*! ��51�汾������ʧ��*/
#define	UGS_FAILED_TO_OPEN_UGPJFILE             29522	/*! ������ο��ļ�ʧ��*/
#define	UGS_SQLPLUS_DS_OPEN_EXPANDTABLE_FAILED  29523	/*! ��������Ա�ʧ��*/
#define	UGS_ODBC_TOPODATASET_OPEN_FAILED        29524	/*! ���������ݼ�ʧ��*/
#define	UGS_TRANSEFER_ANOTHER_OPEN_METHOD_OPEN_DB_WORKSPACE_FAILED 29525	/*! �����ݿ⹤���ռ����������һ���򿪷����������ݿ⹤���ռ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_FILE                 29526	/*! �������ļ�: %s ʧ��*/
#define	UGS_FAILED_TO_OPEN_DATASOURCE_S         29527	/*! ������Դ%sʧ��*/
#define	UGS_FAILED_TO_GET_FIELD_INFO_WHEN_OPEN_DATASET 29528	/*! �����ݼ�ʱ��ȡ�ֶ���Ϣʧ��*/
#define	UGS_UGWORKSPACE_BOXINGSXW_FAILED_OPEN_FILE_S_FAILED 29529	/*! ���ļ�%sʧ�ܣ���SXW�ļ���װ���ֽ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_FILE_AND_CANNOT_WRITE 29530	/*! ���ļ�ʧ�ܣ�����д��*/
#define	UGS_FAILED_TO_OPEN_TEXT                 29531	/*! ���ı��ļ�ʧ��!*/
#define	UGS_ODBC_VECTOR_OPEN_FAILED             29532	/*! ��ʸ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_OPEN_DICTIONARY           29533	/*! �򿪴ʵ��ļ�ʧ��!*/
#define	UGS_FAILED_TO_DRAW_COMPOUND_FOR_FAILED_TO_UNGROUP_THE_COMPOUND 29534	/*! ��ɢ���϶���ʧ�ܣ����Ƹ��϶���ʧ��*/
#define	UGS_ODBC_SQL_EXECUTE_FAILED             29535	/*! ִ��SQL���ʧ��*/
#define	UGS_ODBC_EXECUPDATE_FAILED              29536	/*! ִ�и���ʧ��*/
#define	UGS_CANNOT_FIND_PRJCONFIG_XML           29537	/*! �Ҳ���ͶӰ�����ļ�*/
#define	UGS_CANNOT_FIND_THE_CONNECTING_ENDNODE  29538	/*! �Ҳ�����ͨ���Ǹ��յ�*/
#define	UGS_TOPO_DATASET_POINTER_IS_NULL        29539	/*! �������ݼ�ָ��Ϊ��*/
#define	UGS_TOPO_FAILED_TO_ADD_RULES            29540	/*! �������ݼ���ӹ���ʧ��*/
#define	UGS_FAILED_TO_CUT_FOR_FAILED_TO_COPY_TO_REGEDIT 29541	/*! ������ע���ʧ�ܣ�����ʧ��*/
#define	UGS_THE_DELETING_BUSLINE_NONENTITY      29542	/*! ָ��Ҫɾ���Ĺ�����·������*/
#define	UGS_FAILED_TO_PUSH_FOR_SNAPELEMENT_IS_NONENTITY 29543	/*! ��׽Ҫ�ز����ڣ���ջʧ��*/
#define	UGS_FAILED_TO_PUSH_FOR_SNAPELEMENT_IS_NOT_USED 29544	/*! ��׽Ҫ���Ѿ������ˣ���ջʧ��*/
#define	UGS_PICKUP_COMMON_BOUNDARY_FAILED       29545	/*! ��ȡ�����߽�ʧ��*/
#define	UGS_SQLPLUS_EXTRACT_CONFLICTS_FAILED    29546	/*! ��ȡ��ͻ����ʧ��*/
#define	UGS_INSERT_DATASOURCE_ALIAS_FAILED_S    29547	/*! �������Ϊ%s������Դʧ��*/
#define	UGS_INSERT_LAYER_COUNT_IS_OVERRUN       29548	/*! ���������������������*/
#define	UGS_OPERATE_TEMPORARY_TABLE_FAILED      29549	/*! ������ʱ��ʧ��*/
#define	UGS_IMPORT_DATA_FAILED                  29550	/*! ���ݵ���ʧ��*/
#define	UGS_IMPORT_DATA_SUCCESS                 29551	/*! ���ݵ���ɹ�*/
#define	UGS_DATA_ATTRIBUTE_READONLY             29552	/*! ��������Ϊֻ��*/
#define	UGS_DATA_UNEXPECTED                     29553	/*! �����쳣*/
#define	UGS_DATA_OR_PASSWORD_ERROR              29554	/*! ���ݻ����������*/
#define	UGS_DATASOURCE_IS_NULL                  29555	/*! ����ԴΪ��*/
#define	UGS_DATASOURCE_READONLY                 29556	/*! ����Դֻ��*/
#define	UGS_DATASOURCE_OPEN_SUCCESS             29557	/*! ����Դ�򿪳ɹ�*/
#define	UGS_DATASOURCE_IS_READONLY              29558	/*! ����Դ��ֻ��ģʽ*/
#define	UGS_DATASOURCE_ISNOT_OPEN_OR_READONLY   29559	/*! ����Դû�д򿪻�����ԴΪֻ��*/
#define	UGS_SAME_DATASOURCE                     29560	/*! ����Դ��ͬ*/
#define	UGS_DATA_TYPE_NOT_MATCH                 29561	/*! �������Ͳ�ƥ��*/
#define	UGS_DATA_SIZE_IS_TOO_SMALL_TO_COMPRESS  29562	/*! ������̫С��ѹ��������*/
#define	UGS_INVALID_DATASET_COUNT               29563	/*! ���ݼ������Ƿ�*/
#define	UGS_DATASET_READONLY                    29564	/*! ���ݼ�Ϊֻ��״̬*/
#define	UGS_DATASET_IS_NULL                     29565	/*! ���ݼ�Ϊ��*/
#define	UGS_DATASET_IS_NULL_OR_NOT_IN_SAME_DATASOURCE 29566	/*! ���ݼ�Ϊ�ջ��߲���ͬһ������Դ�����ݼ�*/
#define	UGS_DATASET_IS_NULL_OR_INVALID_THEMEEXPRESSION 29567	/*! ���ݼ�Ϊ�ջ���ר��ͼ���ʽ���Ϸ�*/
#define	UGS_DATASET_IS_NULL_OR_DATASET_ISNOT_VECTOR 29568	/*! ���ݼ�Ϊ�ջ������ݼ�����ʸ�����ݼ�*/
#define	UGS_FAILED_TO_CREATE_DATASET            29569	/*! ���ݼ�����ʧ��*/
#define	UGS_DATASET_ALIAS_UPDATE_FAILED         29570	/*! ���ݼ���������ʧ��*/
#define	UGS_DATASET_NAME_INVALID                29571	/*! ���ݼ����Ʋ��Ϸ�*/
#define	UGS_SAME_DATASET_NAME                   29572	/*! ���ݼ�������ͬ*/
#define	UGS_DATASET_AND_FIELD_SIZE_UNLIKENESS   29573	/*! ���ݼ����ֶ������С�����*/
#define	UGS_INVALID_DATASET_SIZE                29574	/*! ���ݼ���С�Ƿ�*/
#define	UGS_DATASET_ALREADY_ADDED_TO_TOPO       29575	/*! ���ݼ��Ѿ�������Topo*/
#define	UGS_DATASET_FAILED_TO_GET_FIELD_INFO    29576	/*! ���ݼ��õ��ֶ���Ϣʧ��*/
#define	UGS_OPEN_DATASET_FAILED                 29577	/*! ���ݼ���ʧ��*/
#define	UGS_DATASET_POINTER_OR_FIELD_NAME_IS_NULL 29578	/*! ���ݼ�ָ��Ϊ�ջ����ֶ�����Ϊ��*/
#define	UGS_NOT_OPEN_CANNOT_QUERY               29579	/*! ���ݼ�û�д�,���ܽ��в�ѯ*/
#define	UGS_DATASET_NOT_OPEN_OR_READONLY_CANNOT_COPY 29580	/*! ���ݼ�û�д򿪻���ֻ��,���ܸ���*/
#define	UGS_INVALID_DATASET_INDEX               29581	/*! ���ݼ��������Ƿ�*/
#define	UGS_DATASET_TYPE_INVLAID                29582	/*! ���ݼ����Ͳ��Ϸ�*/
#define	UGS_DATASET_IS_NOT_IMAGE                29583	/*! ���ݼ����Ͳ���Image(DEM,Grid)*/
#define	UGS_DATA_INVALID                        29584	/*! ���ݷǷ�*/
#define	UGS_ARRAY_SIZE_IS_ONE                   29585	/*! �����СΪ1*/
#define	UGS_ARRAY_SIZE_IS_NULL                  29586	/*! �����СΪ��*/
#define	UGS_INVALID_ARRAY_SIZE                  29587	/*! �����С�Ƿ�!*/
#define	UGS_FILE_NOT_EXIST                      29588	/*! �ļ�������*/
#define	UGS_FILE_IS_EXIST                       29589	/*! �ļ��Ѿ����ڣ���ȷ��*/
#define	UGS_NEW_ALIAS_IS_EXIST_MODIFY_DATASOURCE_ALIAS_FAILED 29590	/*! �±���%s�Ѿ����ڣ��޸�����Դ����ʧ��*/
#define	UGS_NEWNAME_IS_EXIST_MODIFY_LAYOUT_NAME_FAILED 29591	/*! ������%s�Ѿ����ڣ��޸Ĳ�������ʧ��*/
#define	UGS_SQLPLUS_DATASOURCE_CREATE_FAILED    29592	/*! �½�����Դʧ��*/
#define	UGS_SQLPLUS_CREATE_DATASOURCE_FAILED    29593	/*! �½�����Դʧ��*/
#define	UGS_ODBC_VECTOR_CREATE_FAILED           29594	/*! �½�ʸ�����ݼ�ʧ��*/
#define	UGS_INVALID_DATASET_OPEN_FAILED         29595	/*! ��Ч���ݼ�����ʧ��*/
#define	UGS_INVALID_ENUM                        29596	/*! ��Ч��ö�ٱ���*/
#define	UGS_CANNOT_MOVE_FORWARD                 29597	/*! �޷���ǰ�ƶ��α�*/
#define	UGS_CANNOT_OPEN_MAP                     29598	/*! �޷��򿪵�ͼ*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE             29599	/*! �޷����пռ�ο��任*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE_PLANAR_COORD_SYSTEM_TO_EARTH_COORD_SYSTEM 29600	/*! �޷����пռ�ο��任��-->��������ϵ����ͶӰ����ϵ*/
#define	UGS_BUSLINE_HAS_NO_BUSSTOP              29601	/*! ��վ��ͨ������·*/
#define	UGS_NO_BUSLINE_THROUGH_BUSSTOP          29602	/*! ����·ͨ����վ��*/
#define	UGS_ONLY_SUPPORT_SIMPLE_OBJECT          29603	/*! ��ʱֻ֧�ּ򵥶���*/
#define	UGS_ODBC_UPDATE_RTREE_ITEM_ADD_FAILED   29604	/*! ����R������Ҷ���ʧ��*/
#define	UGS_UPTATE_FAILED                       29605	/*! ���²��ɹ�*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_FAILED     29606	/*! ���¶�̬����ʧ��*/
#define	UGS_ODBC_UPDATE_QTREEINDEX_FAILED       29607	/*! �����Ĳ�������ʧ��*/
#define	UGS_ODBC_UPDATE_LIBTILE_VERSION_FAILED  29608	/*! ����ͼ������ʧ��*/
#define	UGS_SQLPLUS_UPDATE_VECTOR_REGISTER_FAILED 29609	/*! �������ݼ�ע����Ϣʧ��*/
#define	UGS_SQLPLUS_UPDATE_RASTER_REGISTER_FAILED 29610	/*! �������ݼ�ע����Ϣʧ��*/
#define	UGS_NO_BUSSTOP_IN_UPDATE_BUSLINE        29611	/*! ������·��Χ����վ��*/
#define	UGS_ODBC_RECORDSET_UPDATE_FAILED        29612	/*! ���¼�¼��ʧ��*/
#define	UGS_FAILED_TO_SHORTPATH                 29613	/*! ���·������ʧ��*/
#define	UGS_CANNOT_FORMAT_GEOPIE_FOR_TWO_SAME_POINT 29614	/*! ��������ͬ���޷�����GeoPie*/
#define	UGS_AVAILIABLE_POINTS_COUNT             29615	/*! ��Ч��ĸ���*/
#define	UGS_SERVICE_RADIUS_TOO_SMALL            29616	/*! �������뾶̫С*/
#define	UGS_CANNOT_FIND_MATCHED_END_POINT       29617	/*! δ�ҵ�ƥ�����ֹ��*/
#define	UGS_CANNOT_FIND_MATCHED_START_POINT     29618	/*! δ�ҵ�ƥ�����ʼ��*/
#define	UGS_NOT_FIND_UGSTRING                   29619	/*! δ�ҵ��ַ���*/
#define	UGS_FAILED_TO_DRAW_UGPIE                29620	/*! ����Arcʧ��,����UGPie����ʧ��*/
#define	UGS_FAILED_TO_DRAW_POINT_OF_ARC         29621	/*! ����Arcʧ��,��ȡ����Arc�ĵ�ʧ��*/
#define	UGS_CONSTRUCT_DATASET_FAILED            29622	/*! �������ݼ�ʧ��*/
#define	UGS_SEARCH_GRAPHICS_D_UGGRAPHICSMANAGER_FAILED 29623	/*! ����Graphics����Ϊ%d��UGGraphicsManagerʧ��*/
#define	UGS_FAILED_TO_SEARCH                    29624	/*! ����ʧ��*/
#define	UGS_LAYER_SEARCHING_IS_NULL             29625	/*! ����ָ�����ݼ�Ϊ��*/
#define	UGS_SEARCH_RECORDSET                    29626	/*! ���Ҽ�¼��*/
#define	UGS_SEARCH_RECORDSET_IS_NULL            29627	/*! ���Ҽ�¼��Ϊ��*/
#define	UGS_QUERY_IDS_EMPTY                     29628	/*! ��ѯIDΪ��*/
#define	UGS_SEARCH_RECORDSET_NULL               29629	/*! ��ѯ����¼��Ϊ��*/
#define	UGS_SQLPLUS_FILLMAPPING_FAILED          29630	/*! ��ѯʧ��*/
#define	UGS_SQLPLUS_QUERYMETADATAWITHFILTER_FAILED 29631	/*! ��ѯʧ��*/
#define	UGS_ODBC_EXECSTATCOUNT_FAILED           29632	/*! ��ѯʧ��*/
#define	UGS_SQLPLUS_QUERYDTSWITHFIELTER_FAILED  29633	/*! ��ѯʧ��*/
#define	UGS_ODBC_GETIDSBYQUERYDEF_FAILED        29634	/*! ��ѯʧ��*/
#define	UGS_FAILED_TO_QUERY                     29635	/*! ��ѯʧ��*/
#define	UGS_SQLPLUS_QUERY_DT_WITH_BOUNDSSUB_FAILED 29636	/*! ��ѯʧ��*/
#define	UGS_ODBC_QUERY_FIELD_INFO_FAILED        29637	/*! ��ѯ�ֶ���Ϣʧ��*/
#define	UGS_QUERY_FIELD_INFO_FAILED             29638	/*! ��ѯ�ֶ���Ϣʧ��*/
#define	UGS_QUERIED_OBJECT_POINTER_NULL         29639	/*! ��ѯ����ָ��Ϊ��*/
#define	UGS_QUERY_OBJECT_TYPE_INVALID           29640	/*! ��ѯ�������Ͳ��Ϸ�*/
#define	UGS_QUERY_DATASET_POINTER_IS_NULL       29641	/*! ��ѯ���ݼ�ָ��Ϊ��*/
#define	UGS_THE_SEARCH_RECORDSET_IS_NULL        29642	/*! ��ѯ�ļ�¼��Ϊ��*/
#define	UGS_QUERY_OPERATER_INVALID              29643	/*! ��ѯ���Ӳ��Ϸ�*/
#define	UGS_QUERY_RESULT_IS_NULL                29644	/*! ��ѯ���Ϊ��*/
#define	UGS_NETWORK_SEARCH_RECORDSET_IS_NULL    29645	/*! ��ѯ�������ݼ���¼��Ϊ��,��ѯ�������С�ڵ���0*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_NODEDT     29646	/*! ��ѯ��������ݼ�ʧ��*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_LINEDT     29647	/*! ��ѯ���������ݼ�ʧ��*/
#define	UGS_NOEDS_SEARCH_RT_IS_NULL             29648	/*! ��ѯ����ڵ��¼��Ϊ��*/
#define	UGS_QUERY_RECORDSET_COUNT_IS_NULL       29649	/*! ��ѯ��¼������Ϊ��*/
#define	UGS_SEARCH_RT_IS_NULL                   29650	/*! ��ѯ��¼��Ϊ��*/
#define	UGS_QUERING_RECORDSET_OBJECTS_COUNT_IS_ZERO 29651	/*! ��ѯ��¼��������Ϊ��*/
#define	UGS_QUERY_RECORDSET_POINTER_IS_NULL     29652	/*! ��ѯ��¼��ָ��Ϊ��*/
#define	UGS_QUERY_RECORDSET_TYPE_INVALID        29653	/*! ��ѯ��¼�����Ͳ��Ϸ�*/
#define	UGS_SEARCH_RECORDSET_INVALID            29654	/*! ��ѯ��¼�Ƿ�*/
#define	UGS_QUERY_OPTION_INVALID                29655	/*! ��ѯѡ��Ϊ��*/
#define	UGS_QUERY_OPTION_WRONG                  29656	/*! ��ѯѡ���*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_SWAP_STYLE 29657	/*! դ��ֵר��ͼ�������ʧ��*/
#define	UGS_THEMEGRIDUNIQUE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29658	/*! դ��ֵר��ͼ����XML��Ϣʱר��ͼ��ǩ�Ҳ���*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_INSERT_VALUE 29659	/*! դ��ֵר��ͼ����ֵ�Ѿ����ڣ�����ʧ��*/
#define	UGS_THEMEGRIDRUNIQUE_NOT_FOUND_THE_INDEX 29660	/*! դ��ֵר��ͼû���ҵ���Ӧֵ������*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_ADD_VALUE 29661	/*! դ��ֵר��ͼ���ֵ�Ѿ����ڣ�����ʧ��*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_READ_XML 29662	/*! դ��ֵר��ͼ��ȡXML��Ϣʱ�����ȡʧ��*/
#define	UGS_THEMEGRIDUNIQUE_XML_IS_NULL         29663	/*! դ��ֵר��ͼ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_ODBC_RASTER_CACHEBYBLOCK_FAILED     29664	/*! դ��黺��ʧ��*/
#define	UGS_ODBC_RASTER_FAVEBLOCK_FAILED        29665	/*! դ��洢��ʧ��*/
#define	UGS_ODBC_RASTER_SAVEBLOCK_FAILED        29666	/*! դ��洢��ʧ��*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_FAILED_TO_OPEN_RASTER_DATASET 29667	/*! դ�����ݼ���ʧ�ܣ�����դ�����ݼ�ʧ��*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_NO_INTERSECTION 29668	/*! դ�����ݼ��ķ�Χ�͵�ǰ���Ʒ�Χû�н���������դ�����ݼ�ʧ��*/
#define	UGS_THEMEGRIDRANGE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29669	/*! դ��Χר��ͼ�����XML��Ϣʱ�Ҳ���ר��ͼ��ǩ*/
#define	UGS_THEMEGRIDRANGE_SEGMENT_LESSTHAN_TWO 29670	/*! դ��Χר��ͼ�ֶθ���С��2*/
#define	UGS_THEMEGRIDRANGE_NOT_FOUND_THE_INDEX  29671	/*! դ��Χר��ͼû���ҵ���Ӧֵ������*/
#define	UGS_THEMEGRIDRANGE_REMOVEAT_COUNT_LESSTHAN_ONE 29672	/*! դ��Χר��ͼ�Ƴ�ʱ�Ƴ�����С��1*/
#define	UGS_THEMEGRIDRANGE_BOUNDS_VALUE_COUNT_IS_ZERO 29673	/*! դ��Χר��ͼ��Χֵ����Ϊ��*/
#define	UGS_THEMEGRIDRANGE_INVALID_SEGMENT      29674	/*! դ��Χר��ͼ���÷ֶ�ʱ�ֶθ�����Ч*/
#define	UGS_THEMEGRIDRANGE_FAILED_TO_READ_XML   29675	/*! դ��Χר��ͼ��ȡXML��Ϣʱ�����ȡʧ��*/
#define	UGS_THEMEGRIDRANGE_XML_IS_NULL          29676	/*! դ��Χר��ͼ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_THEMELABEL_CANNOT_FIND_LABEL_WHEN_SAVEAS_XML 29677	/*! ��ǩר��ͼ����XML��Ϣʱ�Ҳ�����ǩ*/
#define	UGS_THEMELABEL_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29678	/*! ��ǩר��ͼ����ʱ�Ҳ���ר��ͼ��ǩ*/
#define	UGS_THEMELABEL_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE 29679	/*! ��ǩר��ͼ����ת��˫����ֵʧ��*/
#define	UGS_THEMELABEL_FIELD_INVALID            29680	/*! ��ǩר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_INVALID_INDEX 29681	/*! ��ǩר��ͼ���ҷ����������Ϸ�*/
#define	UGS_THEMELABEL_NOT_FOUND_THE_INDEX      29682	/*! ��ǩר��ͼ�Ҳ�����Ӧֵ������*/
#define	UGS_THEMELABEL_TEXT_HEIGHT_IS_NULL      29683	/*! ��ǩר��ͼ�ı����߶�Ϊ��*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_FAILED_TO_FIND_FIELDVALUE 29684	/*! ��ǩר��ͼ���Ҽ�¼����Ӧ�ֶ�ֵʧ��*/
#define	UGS_THEMELABEL_MAKEALONGLINETEXT_TOO_SHORT_TO_DRAW 29685	/*! ��ǩר��ͼ���߱��ʱ̫�̲�����*/
#define	UGS_THEMELABEL_HITTEST_INVALID_DATASET  29686	/*! ��ǩר��ͼ���ʱ���ݼ����Ϸ�*/
#define	UGS_THEMELABEL_HITTEST_TEXT_HEIGHT_IS_NULL 29687	/*! ��ǩר��ͼ���ʱ�ı����߶�Ϊ��*/
#define	UGS_THEMELABEL_HITTEST_SERACH_FIELD_COUNT_IS_ZERO 29688	/*! ��ǩר��ͼ���ʱ��ѯ�ֶθ���Ϊ��*/
#define	UGS_THEMELABEL_HITTEST_SCALE_IS_ZERO    29689	/*! ��ǩר��ͼ���ʱ���Ʋ���������Ϊ��*/
#define	UGS_THEMELABEL_REMOVEAT_COUNT_LESSTHAN_ONE 29690	/*! ��ǩר��ͼ�Ƴ�����С��1*/
#define	UGS_THEMELABEL_FAILED_TO_GET_RECORDSET_WHEN_EXTREMUM 29691	/*! ��ǩר��ͼ���㼫ֵʱ��ȡ��¼����Ϣʧ��*/
#define	UGS_THEMELABEL_RECORDSET_IS_NULL        29692	/*! ��ǩר��ͼ��¼��Ϊ��*/
#define	UGS_THEMELABEL_RECORDSET_IS_NULL_WHEN_EXTREMUM 29693	/*! ��ǩר��ͼ���ö���ֶ�ʱ���㼫ֵʱ��¼��Ϊ��*/
#define	UGS_THEMELABEL_SEGMENT_LESSTHAN_TWO     29694	/*! ��ǩר��ͼ���ö�����ʱ�ֶθ���С��2*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_SEGEMENT_VALUE_IS_ZERO 29695	/*! ��ǩר��ͼ���ö�����ʱ��ֵΪ��*/
#define	UGS_THEMELABEL_MAKEDEFAULT_STYLE_BOUNDS_LESSTHAN_ZERO 29696	/*! ��ǩר��ͼ���ö�����ʱ��ΧֵС��0*/
#define	UGS_THEMELABEL_CLASSIFY_RECORDSET_IS_NULL 29697	/*! ��ǩר��ͼ���ö�����ʱ����ֶ�ʱ��¼��Ϊ��*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_STYLE_COUNT_INVALID 29698	/*! ��ǩר��ͼ���ö�����ʱ���������Ϸ�*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_STYLE_COUNT_IS_ZERO 29699	/*! ��ǩר��ͼ���ö�����ʱ������Ϊ��*/
#define	UGS_THEMELABEL_SET_DISPLAY_FORMAT_EXCEPTION 29700	/*! ��ǩר��ͼ������ʾ��ʽʱ�����쳣*/
#define	UGS_THEMELABEL_FAILED_TO_READ_XML       29701	/*! ��ǩר��ͼ��ȡXMLʱ�����ȡʧ��*/
#define	UGS_THEMELABEL_FAILED_TO_READ_UNIQUE_TEXT_STYLE 29702	/*! ��ǩר��ͼ��ȡ�����ı����ʱʧ��*/
#define	UGS_THEMELABEL_FAILED_TO_CREATE_GRAPHICS_WHEN_CONVERT_TO_GEO 29703	/*! ��ǩר��ͼת���ζ���ʱ����Graphicsʧ��*/
#define	UGS_THEMELABEL_TEXT_FONT_IS_NULL_WHEN_CONVERT_TO_GEO 29704	/*! ��ǩר��ͼת���ζ���ʱ��������Ϊ��*/
#define	UGS_THEMELABEL_TEXT_WIDTH_OVERRUN_WHEN_CONVERT_TO_GEO 29705	/*! ��ǩר��ͼת���ζ���ʱ�����Ȳ��������С��Χ��*/
#define	UGS_THEMELABEL_DEFAULT_SIZE_IS_ZERO_WHEN_CONVERT_TO_GEO 29706	/*! ��ǩר��ͼת���ζ���ʱĬ�ϴ�СΪ��*/
#define	UGS_FAILED_TO_MARK                      29707	/*! ��ʶʧ��*/
#define	UGS_WRONG_MARK                          29708	/*! ��ʶ����*/
#define	UGS_FAILED_TO_CHECK_GRAPHIC_DYNAMIC_LIB 29709	/*! ���Graphics��̬��ʧ��*/
#define	UGS_CHECKING_AND_CHECKED_DATASET_CANNOT_BE_SAME_DATASET 29710	/*! ������ݼ��ͱ�������ݼ�����Ϊͬһ���ݼ�*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS       29711	/*! ��������ʧ��*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS_FILE  29712	/*! ���������ļ�ʧ��*/
#define	UGS_CANNOT_OPEN_TEMPLATE_DATASET        29713	/*! ģ�����ݼ����ܴ�*/
#define	UGS_TFWEIGHT_AND_FTWEIGHT_ARE_NULL      29714	/*! ����ͷ����ֶ�Ϊ��*/
#define	UGS_IMORTING_THE_SINGLE_BAND_D          29715	/*! ���ڵ��뵥��������(%d)...*/
#define	UGS_IMPROTING_DATAFILE_S                29716	/*! ���ڵ��������ļ���%s ...*/
#define	UGS_IMPORTING_DATAFILE_S                29717	/*! ���ڵ��������ļ���%s ... */
#define	UGS_IMPORTING_THE_D_BAND                29718	/*! ���ڵ���� %d ������...*/
#define	UGS_EXPORTING_DATAFILE_S                29719	/*! ���ڵ��������ļ���%s*/
#define	UGS_OPENING_DATASOURCE                  29720	/*! ���ڴ�����Դ...*/
#define	UGS_IS_EDITING_AND_ALREADY_ADDED        29721	/*! ���ڱ༭���Ѿ�ִ�й���Ӳ���*/
#define	UGS_MAYBE_SUPERMAPDS_ALREADY            29722	/*! ��ǰ�����Ѿ���SuperMap������Դ����ȷ��*/
#define	UGS_THIS_MAPBREADTH_HAS_NODATA          29723	/*! ��ͼ����Χ��û������*/
#define	UGS_THE_ENGINE_NOT_SUPPORT_CREATE_THS_TYPE_DATASET 29724	/*! ��������ʱ��֧���������ݼ��Ĵ���*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_UNION 29725	/*! �����ݼ����Ͳ�֧��Union����*/
#define	UGS_THE_FILE_NAME_IS_NONENTITY          29726	/*! ���ļ���������*/
#define	UGS_THE_BARRIER_EDGE                    29727	/*! �˱�Ϊ�ϰ���*/
#define	UGS_SCALE_LESSTHAN_ZERO_SET_SCALE_FAILED 29728	/*! ������С�ڵ���0�����ñ�����ʧ��*/
#define	UGS_NO_CHANGED                          29729	/*! û�����κ��޸�*/
#define	UGS_NO_GEOMETRY_ELEMENT                 29730	/*! û�м���Ԫ��*/
#define	UGS_NOT_MATCH_THE_NODE                  29731	/*! û��ƥ�䵽��ؽڵ�*/
#define	UGS_NEEDNOT_UPDATE_FOR_NO_CHANGE        29732	/*! û�з����ı䣬����Ҫ����*/
#define	UGS_NONE_LEGAL_CHILD_OBJECT             29733	/*! û�кϷ����Ӷ���*/
#define	UGS_NOT_FIND_THE_ID_IN_SELECTION        29734	/*! û����ѡ�����ҵ���Ӧ��ID*/
#define	UGS_NOT_GET_NODE_INFO                   29735	/*! û�еõ��ڵ���Ϣ*/
#define	UGS_NOT_FIND_INDEX_OPPOSITE_THE_FILED_NAME 29736	/*! û���ҵ�������ֶ�����Ӧ������*/
#define	UGS_LAYERS_NOT_FIND_USEFUL_LAYER_NAME   29737	/*! û���ҵ����õ�ͼ������*/
#define	UGS_DONOT_FIND_UGPJFILE                 29738	/*! û���ҵ�����ο��ļ�*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_NAME 29739	/*! û���ҵ�ָ�����Ƶ�ͼ��*/
#define	UGS_NOT_FIND_THE_TOPO_LAYER             29740	/*! û���ҵ�ָ�����������ݼ�ͼ��*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_INDEX 29741	/*! û���ҵ�ָ��������ͼ��*/
#define	UGS_NOT_FIND_DATA                       29742	/*! û���ҵ�����*/
#define	UGS_NOT_APPOINT_DATASOURCE_TYPE_OR_CANNOT_PARSE_DATASOURCE_TYPE_FROM_URL 29743	/*! û��ָ������Դ���ͻ����޷���URL�н���������Դ����*/
#define	UGS_NONE_TIP_OR_TIP_ERROR               29744	/*! û����ʾ��Ϣ����ʾ��Ϣ����ȷ*/
#define	UGS_NO_ROW_CHANGED                      29745	/*! û�������б��ı�*/
#define	UGS_THE_CORRELATIVE_FIELD_IS_NONENTITY  29746	/*! û����ص��ֶ�����*/
#define	UGS_NO_CORRELATIVE_ARC                  29747	/*! û����صĻ���*/
#define	UGS_NO_SPATIALDATA_CANNOT_COMPUTE_BOUND 29748	/*! û�пռ����ݣ�����ͳ�Ʒ�Χ*/
#define	UGS_NO_SM_AND_NOT_EXPANDOPEN            29749	/*! û��ϵͳ���ҷ���չ��*/
#define	UGS_NO_DIRTY_RECORD                     29750	/*! û��������¼*/
#define	UGS_HAVENOT_READ_ANY_DATA               29751	/*! û�ж�ȡ���κ�����*/
#define	UGS_DONOT_HAVE_PYRAMIDS                 29752	/*! û�н�����*/
#define	UGS_BAND_COUNT_IS_ZERO                  29753	/*! ������Ϊ0*/
#define	UGS_BULID_SPATIALINDEXTILE_FAILED       29754	/*! ע��ʧ��*/
#define	UGS_FAILED_TO_PASTE_FOR_THE_REGEDIT_IS_NONENTITY 29755	/*! ע���ļ������ڣ�ճ��ʧ��*/
#define	UGS_FAILED_TO_REGISTER_VERSION          29756	/*! ע��汾ʧ�ܣ�*/
#define	UGS_REGISTER_TABLE_NOT_EXIST            29757	/*! ע�������*/
#define	UGS_DIRECTION_IS_NULL                   29758	/*! �����ֶ�Ϊ��*/
#define	UGS_DIRECTION_TYPE_IS_NOT_LONG          29759	/*! �����ֶ����Ͳ��ǳ���������*/
#define	UGS_TEST_DEBUG                          29760	/*! ����Debug*/
#define	UGS_SQLPLUS_ADDMETADATADESC_FAILED      29761	/*! ���Ԫ����ʧ��*/
#define	UGS_FAILED_TO_ADD_GEO                   29762	/*! ��Ӽ��ζ���ʧ��*/
#define	UGS_ODBC_CREATEFILED_FAILED             29763	/*! ����ֶ�ʧ��*/
#define	UGS_FAILED_TO_ADD_TOPO                  29764	/*! ����������ݼ�ʧ��*/
#define	UGS_LAYERS_UNSUPPORT_ADDING_DATASET_AS_ATTRIBUTE 29765	/*! ������ݼ�Ϊ���Ա����ͣ��ݲ�֧��*/
#define	UGS_SQLPLUS_ADDTEMPLATEFILE_FAILED      29766	/*! ���ģ���ļ�ʧ��*/
#define	UGS_ODBC_FILL_TABLE_EXTINFO_FAILED      29767	/*! ��Ӽ�¼ʧ��*/
#define	UGS_CANNOT_APPEND_FOR_ORIGINALDATASET_ISNOT_OVERLAP_WITH_TARGETDATASET 29768	/*! Դ���ݼ���Ŀ�����ݼ�û�е��ϣ��޷�׷��*/
#define	UGS_SOURCE_RECORDSET_HASNO_RECORD       29769	/*! Դ��¼��û�м�¼*/
#define	UGS_POINTS_POINTER_IS_NULL              29770	/*! �㴮ָ��Ϊ��*/
#define	UGS_NODE_COUNT_NOT_EQUAL_ARC_COUNT      29771	/*! ��ͻ��θ�����һ��*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_BOUNDS_IS_NULL 29772	/*! ���ܶ�ר��ͼרΪ���ζ���ʱ��ΧΪ��*/
#define	UGS_THEMEDOTDENSITY_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29773	/*! ���ܶ�ר��ͼ����XML��Ϣ�Ҳ���Theme��Ӧ��ǩ*/
#define	UGS_THEMEDOTDENSITY_BASICCLASS_IS_NULL_WEHN_SAVE_XML 29774	/*! ���ܶ�ר��ͼ����XML��Ϣʱ������ϢΪ��*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_BOUNDS_IS_NULL 29775	/*! ���ܶ�ר��ͼ��䷶ΧΪ��*/
#define	UGS_THEMEDOTDENSITY_FIELD_INVALID       29776	/*! ���ܶ�ר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMEDOTDENSITY_INVALID_FIELD       29777	/*! ���ܶ�ר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_POINTER_IS_NULL 29778	/*! ���ܶ�ר��ͼ�����ʱ��ָ��Ϊ��*/
#define	UGS_THEMEDOTDENSITY_DRAW_POINT_VALUE_IS_ZERO 29779	/*! ���ܶ�ר��ͼ���Ƶ�����ֵΪ��*/
#define	UGS_THEMEDOTDENSITY_RECORDSET_IS_NULL   29780	/*! ���ܶ�ר��ͼ��¼��Ϊ��*/
#define	UGS_THEMEDOTDENSITY_XML_BASICCLASS_IS_NULL 29781	/*! ���ܶ�ר��ͼ��ȡXML��Ϣ������ϢΪ��*/
#define	UGS_THEMEDOTDENSITY_XML_IS_NULL         29782	/*! ���ܶ�ר��ͼ��ȡXML��Ϣ�ַ���Ϊ��*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_COUNT_IS_ZERO 29783	/*! ���ܶ�ר��ͼתΪ���ζ�������Ϊ��*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_VALUE_IS_ZERO 29784	/*! ���ܶ�ר��ͼתΪ���ζ��������ֵΪ��*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_POINTER_IS_NULL 29785	/*! ���ܶ�ר��ͼתΪ���ζ����ָ��Ϊ��*/
#define	UGS_NOT_REGION_WHEN_CONVERT_THEMEDOTDENSITY_TO_DATASET 29786	/*! ���ܶ�ר��ͼת���ݼ�ʱ���������ݼ�����*/
#define	UGS_POINT_COUNT_LESSTHAN_ZERO           29787	/*! ��ĸ���С��0*/
#define	UGS_NODE_COUNT_LESSTHAN_TWO             29788	/*! ��ĸ�������2��*/
#define	UGS_FAILED_CONVERT_POINT                29789	/*! ���ת��ʧ��*/
#define	UGS_VERSION_NAME_IS_NULL                29790	/*! �汾����Ϊ��*/
#define	UGS_ODBC_VERSIONDATASET_REFRESH_VERSION_FAILED 29791	/*! �汾���ݼ����°汾ʧ��*/
#define	UGS_VERSIONDT_NOT_SET_VERSION_CANNOT_EDIT 29792	/*! �汾���ݼ�û�����ð汾�����ܱ༭*/
#define	UGS_ODBC_UPDATE_VERSION_FAILED          29793	/*! �汾����ʧ��*/
#define	UGS_FAILED_TO_GENERATE_FILE             29794	/*! ���������ļ�: %s ʧ��*/
#define	UGS_SQLPLUS_UNION_CONFLICS_FAILED       29795	/*! �úϲ��ķ��������ͻʧ��*/
#define	UGS_FAILED_TO_DRAW_IMAGE_FOR_USER_CANCLE 29796	/*! �û�ȡ�����ƣ�����Ӱ��ʧ��*/
#define	UGS_SELECTED_COSTFIELD_INVALID          29797	/*! �û�ѡ��ĺķ��ֶηǷ�*/
#define	UGS_FAILED_TO_FORMAT_ARC                29798	/*! �ɲ������컡��ʧ��*/
#define	UGS_FAILED_TO_APPLY_MEMORY              29799	/*! �����ڴ�ʧ��*/
#define	UGS_AIM_DATASET_IS_NULL                 29800	/*! Ŀ�����ݼ�Ϊ��*/
#define	UGS_ODBC_GETBOUNDSDIRECTLY_FAILED       29801	/*! ֱ�ӻ�ȡ������ʧ��*/
#define	UGS_FAILED_TO_INTERSECTLINE_FOR_PARALLEL_LINE_HAS_NO_INTERSECTION_POINT 29802	/*! ֱ��ƽ�У��޽��㣬�ཻ����ʧ��*/
#define	UGS_ODBC_VECTOR_CREATERTREEINDEX_FAILED 29803	/*! ʸ�����ݼ�����R������ʧ��*/
#define	UGS_ODBC_VECTOR_REGISTEROPTION_FAILED   29804	/*! ʸ�����ݼ�ע��ʧ��*/
#define	UGS_ODBC_VECTOR_UNREGISTEROPTION_FAILED 29805	/*! ʸ�����ݼ�ע��ʧ��*/
#define	UGS_ODBC_VECTOR_GETNEWID_FAILED         29806	/*! ʸ�����ݼ���ȡ�µ�IDʧ��*/
#define	UGS_ODBC_VECTOR_COMPUTEBOUNDS_FAILED    29807	/*! ʸ�����ݼ����㷶Χʧ��*/
#define	UGS_ODBC_VECTOR_APPEND_FAILED           29808	/*! ʸ�����ݼ�׷��ʧ��*/
#define	UGS_CANNOT_FORMAT_REGION_FOR_RECTANGLE_IS_NULL 29809	/*! ����Ϊ�գ��޷�����*/
#define	UGS_RECTANGLE_WIDTH_MUST_MORETHAN_ZERO  29810	/*! ���εĿ�������0*/
#define	UGS_RECTANGLE_HEIGHT_MUST_MORETHAN_ZERO 29811	/*! ���εĸ߱������0*/
#define	UGS_CANNOT_WORK_FOR_RECTANGLE_AREA_IS_NULL 29812	/*! �������Ϊ0�������޷�����*/
#define	UGS_GEOMETRY_ELEMENT_IS_NULL            29813	/*! �ռ���Ԫ��*/
#define	UGS_CHAR_IS_NULL                        29814	/*! ���ַ�!*/
#define	UGS_EMPTY_OBJECT_CANNOT_ADD_TO_DATASET  29815	/*! �ն�������ӵ����ݼ���*/
#define	UGS_INVALID_BUSSTOP_ID                  29816	/*! վ��ID�Ƿ�*/
#define	UGS_BUSSTOP_RECORDSET_IS_NULL           29817	/*! վ���¼��Ϊ��*/
#define	UGS_THEMESYMBOL_FIELD_INVLAID           29818	/*! ����ר��ͼ�ֶβ��Ϸ�*/
#define	UGS_DATASET_ISNOT_CAD_OR_SCALE_IS_ZERO_WHEN_CONVERT_THEME_TO_DATASET 29819	/*! ����תΪ���ݼ�ʱָ�����ݼ�����CAD���ݼ����߻��Ʋ���������Ϊ��*/
#define	UGS_PATH_NO_MATCH_POINTS                29820	/*! ��i+1·�ɵ���ƥ��ĵ�·*/
#define	UGS_ROUTE_NODE_NO_MATCH_ROAD            29821	/*! ��i+1·�ɵ���ƥ��ĵ�·*/
#define	UGS_FIRST_LEVEL_GIRD_MUST_MORETHAN_ZERO_AND_GEOMETRY_MUST_NOT_NULL 29822	/*! ��һ�������С����Ϊ0�Ҽ��ζ�����Ϊ��*/
#define	UGS_THEMEGRADUATE_NOT_SUPPORT_NEGATIVE  29823	/*! �ȼ�����ר��ͼ��֧�ָ�ֵʱ���ָ�ֵ*/
#define	UGS_THEMEGRADUATE_BASICCLASS_IS_NULL_WEHN_SAVE_XML 29824	/*! �ȼ�����ר��ͼ����XML��Ϣʱ������ϢΪ��*/
#define	UGS_THEMEGRADUATE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29825	/*! �ȼ�����ר��ͼ����XML��Ϣʱ�Ҳ���Theme��ǩ*/
#define	UGS_THEMEGRADUATE_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29826	/*! �ȼ�����ר��ͼ����XML��Ϣʱ�Ҳ�����ǩ*/
#define	UGS_THEMEGRADUATE_VALUE_IS_ZERO         29827	/*! �ȼ�����ר��ͼֵΪ��*/
#define	UGS_THEMEGRADUATE_FIELD_INVALID         29828	/*! �ȼ�����ר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMEGRADUATE_FIELD_EXPRESSION_IS_NULL 29829	/*! �ȼ�����ר��ͼ�ֶα��ʽΪ��*/
#define	UGS_THEMEGRADUATE_DEFINE_VALUE_IS_ZERO  29830	/*! �ȼ�����ר��ͼ����ֵΪ��*/
#define	UGS_THEMEGRADUATE_INVALID_GRADUATEMODE  29831	/*! �ȼ�����ר��ͼ�ȼ�����ģʽ���Ϸ�*/
#define	UGS_THEMEGRADUATE_IMPORT_PARAM_VALUE_IS_ZERO 29832	/*! �ȼ�����ר��ͼ������Ŵ�Сʱ�������ֵΪ��*/
#define	UGS_THEMEGRADUATESYMBOL_RECORDSET_IS_NULL 29833	/*! �ȼ�����ר��ͼ��¼��Ϊ��*/
#define	UGS_THEMEGRADUATE_FAILED_TO_READ_XML    29834	/*! �ȼ�����ר��ͼ��ȡXML��Ϣʱ�����ȡʧ��*/
#define	UGS_THEMEGRADUATE_XML_IS_NULL           29835	/*! �ȼ�����ר��ͼ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_THEMEGRADUATE_DEFINE_MAX_VALUE_IS_ZERO 29836	/*! �ȼ�����ר��ͼĬ�����������ֵΪ��*/
#define	UGS_SMID_LESSTHAN_ZERO                  29837	/*! ϵͳIDС����*/
#define	UGS_SYSTEMUSER_FORBID_CREATING_DATASOURCE 29838	/*! ϵͳ�û�������������Դ*/
#define	UGS_INVALID_INDEX_LOCATION              29839	/*! ����λ�÷Ƿ�*/
#define	UGS_INDEX_ANALYZE_FAILED                29840	/*! ��������ʧ��*/
#define	UGS_INDEX_OVERLOP                       29841	/*! ������Խ��*/
#define	UGS_WRONG_INDEX                         29842	/*! ��������*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_EDITDELETED_FAILED 29843	/*! �����ѱ�ɾ�������¶�̬����ʧ��*/
#define	UGS_FAILED_TO_SEARCH_INDEX              29844	/*! ��������ʧ��*/
#define	UGS_INDEXTYPE_INVALID                   29845	/*! ���������Ͳ���*/
#define	UGS_INDEX_ISNOT_IDXRTREE                29846	/*! �������Ͳ���R������*/
#define	UGS_INDEX_TYPE_ISNOT_IDXDYNAMIC         29847	/*! �������Ͳ��Ƕ�̬����*/
#define	UGS_INDEX_ISNOT_IDXQTREE                29848	/*! �������Ͳ����Ĳ�������*/
#define	UGS_INDEX_TYPE_IS_NOT_IDXTILE           29849	/*! �������Ͳ���ͼ������*/
#define	UGS_INVALID_INDEX                       29850	/*! �����Ƿ�*/
#define	UGS_CANNOT_ADD_ATTRIBUTE_TO_TOPO        29851	/*! �����Ա�����ӵ�Topo��*/
#define	UGS_HAS_GAP_BETWEEN_LINE                29852	/*! �߶�֮���м��*/
#define	UGS_LINE_INTERSECT_FAILED               29853	/*! �߶���ʧ��*/
#define	UGS_INVALID_BUSLINE_ID                  29854	/*! ��·ID�Ƿ�*/
#define	UGS_BUSLINE_RECORDSET_IS_NULL           29855	/*! ��·��¼��Ϊ��*/
#define	UGS_ENDPOINT_IS_BARRIERNODE             29856	/*! ��ֹ�ڵ����ϰ���*/
#define	UGS_INVALID_ENDPOINT_M                  29857	/*! �յ�Mֵ��Ч*/
#define	UGS_FAILED_TO_CREATE_RESULTDT_FIELD     29858	/*! ������ݼ��ֶδ���ʧ��*/
#define	UGS_NODE_POINTER_IS_NULL                29859	/*! ���ָ��Ϊ��*/
#define	UGS_DRAW_PARAM_SCALE_IS_ZERO            29860	/*! ���Ʋ���������Ϊ��*/
#define	UGS_MAP_FAILED_TO_DRAW                  29861	/*! ���Ƶ�ͼʧ��*/
#define	UGS_DATASET_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMENONE 29862	/*! ������ר��ͼͼ��ʱ�����ݼ�Ϊ�ջ��߼�¼��Ϊ��*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMELABEL  29863	/*! ���Ʊ�ǩר��ͼʱ���Ʋ���������Ϊ��*/
#define	UGS_TEXT_HEIGHT_IS_ZERO_WHEN_DRAW_THEMELABEL 29864	/*! ���Ʊ�ǩר��ͼʱ�������ַ��߶�Ϊ��*/
#define	UGS_IS_NOT_REGION_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMEDOTDENSITY 29865	/*! ���Ƶ��ܶ�ר��ͼʱ���������ݼ����߼�¼��Ϊ��*/
#define	UGS_INVALID_FIELD_TYPE_WHEN_DRAW_THEMEDOTDENSITY 29866	/*! ���Ƶ��ܶ�ר��ͼʱ�ֶ����Ͳ��Ϸ�*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMEDOTDENSITY 29867	/*! ���Ƶ��ܶ�ר��ͼʱ���Ʋ���������Ϊ��*/
#define	UGS_FAILED_TO_DRAW_FOR_HEIGHT_OR_WIDTH_LESS_THAN_ONE 29868	/*! ���Ƶĸ߶Ȼ��߿��С��1������ʧ��*/
#define	UGS_THEMEGRADUATEDSYMBOL_UNSUPPORTED_CAD 29869	/*! ���Ƶȼ�����ר��ͼʱ���ݾ�ΪCAD���ݼ����ݲ�֧��*/
#define	UGS_DATASET_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMEGRADUATEDSYMBOL 29870	/*! ���Ƶȼ�����ר��ͼʱ���ݼ�����ʸ���Ļ��߼�¼��Ϊ��*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMEGRADUATEDSYMBOL 29871	/*! ���Ƶȼ�����ר��ͼʱ���Ʋ���������Ϊ��*/
#define	UGS_DATASET_IS_NULL_OR_DATASET_ISNOT_VECTOR_WHEN_DRAW_THEMESTYLE 29872	/*! ���Ʒ��ר��ͼʱ���ݼ�����ʸ���Ļ��߼�¼��Ϊ��*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMESTYLE  29873	/*! ���Ʒ��ר��ͼʱ���Ʋ����ı�����Ϊ��*/
#define	UGS_THEMEGRAPH_FORBID_ADDING_LEADERLINE 29874	/*! ͳ��ר��ͼ���������ǣ����*/
#define	UGS_THEMEGRAPH_FAILED_TO_SWAP           29875	/*! ͳ��ר��ͼ����ʧ��*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29876	/*! ͳ��ר��ͼ�����XML��Ϣʱ�Ҳ���Theme��ǩ*/
#define	UGS_THEMEGRAPH_FAILED_TO_SAVEAS_XML     29877	/*! ͳ��ר��ͼ�����XMLʱ���ౣ��ʧ��*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29878	/*! ͳ��ר��ͼ�ɱ���XML��Ϣʱ�Ҳ�����ǩ*/
#define	UGS_THEMEGRAPH_NOT_SUPPORT_NEGATIVE     29879	/*! ͳ��ר��ͼ�ڲ�֧�ָ�ֵ��ѡ���³��ָ�ֵ�ֶΣ������л���*/
#define	UGS_THEMEGRAPH_FIELD_INVALID            29880	/*! ͳ��ר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_GRAPHITEM_WHEN_READING_XML 29881	/*! ͳ��ר��ͼ�ֶζ�ȡXMLʱ�Ҳ���GraphItem��ǩ*/
#define	UGS_THEMEGRAPH_TEXT_HEIGHT_IS_ZERO      29882	/*! ͳ��ר��ͼ�ı����߶�Ϊ��*/
#define	UGS_THEMEGRAPH_HITTEST_DRAWING_POINTER_IS_NULL 29883	/*! ͳ��ר��ͼ����л��Ʋ���ָ��Ϊ��"*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_BIG 29884	/*! ͳ��ר��ͼ����¼���ͼ��̫��*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_SMALL 29885	/*! ͳ��ר��ͼ����¼���ͼ��̫С*/
#define	UGS_THEMEGRAPH_HITTEST_FIELD_COUNT_IS_ZERO 29886	/*! ͳ��ר��ͼ����¼����ֶθ���Ϊ��*/
#define	UGS_THEMEGRAPH_HITTEST_DATASET_IS_NOT_RASTER 29887	/*! ͳ��ר��ͼ����¼������ݼ�����ʸ����*/
#define	UGS_THEMEGRAPH_HITTEST_MAX_IS_ZERO      29888	/*! ͳ��ר��ͼ����¼������ֵΪ��*/
#define	UGS_THEMEGRAPH_HITTEST_SCALE_IS_ZERO    29889	/*! ͳ��ר��ͼ����¼��б�����Ϊ��*/
#define	UGS_THEMEGRAPH_HITTEST_RECORDSET_IS_NULL 29890	/*! ͳ��ר��ͼ����¼��м�¼��Ϊ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_REMOVE         29891	/*! ͳ��ר��ͼ�Ƴ�ʧ��*/
#define	UGS_THEMEGRAPH_FIELD_LESSTHAN_TWO_WHEN_DRAW_3DROSE 29892	/*! ͳ��ר��ͼ������άõ��ʱ�ֶθ���С��2*/
#define	UGS_THEMEGRAPH_TOO_BIG_TO_DRAW          29893	/*! ͳ��ר��ͼ����ʱͼ�����*/
#define	UGS_THEMEGRAPH_TOO_SMALL_TO_DRAW        29894	/*! ͳ��ר��ͼ����ʱͼ���С*/
#define	UGS_THEMEGRAPH_FIELD_MAXVALUE_IS_ZERO_WHEN_DRAW 29895	/*! ͳ��ר��ͼ����ʱ�ֶ����ֵΪ��*/
#define	UGS_THEMEGRAPH_FEILD_COUNT_IS_ZERO_WHEN_EXTREMUM 29896	/*! ͳ��ר��ͼ���㼫ֵʱ�ֶθ���Ϊ��*/
#define	UGS_THEMEGRAPH_RECORDSET_IS_NULL        29897	/*! ͳ��ר��ͼ��¼��Ϊ��*/
#define	UGS_THEMEGRAPH_DEFINE_STYLE_FIELD_COUNT_IS_ZERO 29898	/*! ͳ��ר��ͼ����Ĭ�Ϸ��ʱ�ֶθ���Ϊ��*/
#define	UGS_THEMEGRAPH_READING_XML_STRING_IS_NULL 29899	/*! ͳ��ר��ͼ��ȡXML��Ϣ�ַ���Ϊ��*/
#define	UGS_THEMEGRAPH_FAILED_TO_READ_XML       29900	/*! ͳ��ר��ͼ��ȡXMLʱ�����ȡʧ��*/
#define	UGS_THEMEGRAPH_XML_IS_NULL              29901	/*! ͳ��ר��ͼ��ȡXMLʱ�ַ���Ϊ��*/
#define	UGS_GRAPH_LESSTHAN_SMALLEST_BOUNDS_WHEN_CONVERTTOGEO 29902	/*! ͳ��ר��ͼתΪ���ζ���ʱͼ��С����С����Χ*/
#define	UGS_GRAPH_OVERRUN_WHEN_CONVERTTOGEO     29903	/*! ͳ��ר��ͼתΪ���ζ���ʱͼ�񳬹��������Χ*/
#define	UGS_MAX_IS_ZERO_WHEN_CONVERTTOGEO       29904	/*! ͳ��ר��ͼתΪ���ζ���ʱ���ֵΪ��*/
#define	UGS_DRAW_PARAM_POINTER_IS_NULL_WHEN_CONVERTTOGEO 29905	/*! ͳ��ר��ͼתΪ���ζ���ʱ���Ʋ���ָ��Ϊ��*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_HAVE_NEGAITIVE_VALUE 29906	/*! ͳ��ר��ͼת���ζ���ʱ���ָ�ֵ*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_FIELD_MAXVALUE_IS_NULL 29907	/*! ͳ��ר��ͼת���ζ���ʱ�ֶ����ֵΪ��*/
#define	UGS_THEMEGRAPH_PYRAMIDBAR_FIELD_IS_NULL_OR_ISNOT_EVEN 29908	/*! ͳ��ר��ͼ�����������Ӷθ���Ϊ����߲���ż��*/
#define	UGS_THEMEGRAPH_PYRAMIDPOLY_FIELD_IS_NULL_OR_ISNOT_EVEN 29909	/*! ͳ��ר��ͼ�����������Ӷθ���Ϊ����߲���ż��*/
#define	UGS_ODBC_STATISTIC_FAILED               29910	/*! ͳ��ʧ��*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_UGGRAPHICS_BUFFER_IS_NULL 29911	/*! ����UGGraphicsΪ�գ�ˢ�¶���ʧ��*/
#define	UGS_MEMORY_FILE_S_CREATE_FAILED         29912	/*! �����ļ� %s ����ʧ��*/
#define	UGS_MEMORY_FILE_S_CREATE_SUCCESS        29913	/*! �����ļ�ȫ %s �����ɹ�*/
#define	UGS_MEMORY_FILE_FULLNAME_S              29914	/*! �����ļ�ȫ��: %s*/
#define	UGS_FAILED_TO_CODE                      29915	/*! ����ʧ��*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_SETGEOMETRY_FAILED 29916	/*! �༭�������������ʧ��*/
#define	UGS_FAILED_TO_SAVE_FOR_FAILED_TO_GET_ORIGINAL_OBJECT 29917	/*! �༭�������ڵļ�¼���޷�ȡ��ԭʼ�༭���󣬱���༭����ʧ��*/
#define	UGS_GRID_TYPE_UNCONFORMITY              29918	/*! �������Ͳ���*/
#define	UGS_STRARCID_IS_NULL                    29919	/*! ���绡�δ�СΪ��*/
#define	UGS_INVALID_ARC_INDEX                   29920	/*! ���绡�������Ƿ�*/
#define	UGS_NETWORK_ARCDEMAND_IS_NULL           29921	/*! ���绡�������ֶ�Ϊ��*/
#define	UGS_INVLIAD_ARC                         29922	/*! ���绡�ηǷ�*/
#define	UGS_NETWORK_IS_NULL                     29923	/*! �������ݼ�Ϊ��*/
#define	UGS_INVLAID_INDEX_FOR_NETWORK_IS_NULL   29924	/*! �������ݼ�Ϊ��,�����Ƿ�*/
#define	UGS_NETWORK_IS_NULL_OR_DTTRN_IS_NULL    29925	/*! �������ݼ�Ϊ�ջ���ת������ݼ�Ϊ��*/
#define	UGS_FAILED_TO_OPEN_NETWORK              29926	/*! �������ݼ���ʧ��*/
#define	UGS_NETWORK_NOT_OPEN                    29927	/*! �������ݼ�û�д�*/
#define	UGS_NETWORK_NODEDT_TYPE_ERROR           29928	/*! ��������ݼ����Ͳ���*/
#define	UGS_NODE_IS_NULL                        29929	/*! ����ڵ�Ϊ��*/
#define	UGS_NETWORK_NODE_INDEX_INVALID          29930	/*! ����ڵ������Ƿ�*/
#define	UGS_NETWORK_NODEDEMAND_IS_NULL          29931	/*! ����ڵ������ֶ�Ϊ��*/
#define	UGS_NETWORK_RECORDSET_IS_NULL           29932	/*! �����¼��Ϊ��*/
#define	UGS_DIRTY_DATASET_IS_NULL               29933	/*! �������ݼ�Ϊ��*/
#define	UGS_FAILED_TO_UNDO_FOR_TRACkING_NOT_SUPPORT_UNDO 29934	/*! �Զ�����Ŀǰ��֧�ֻ��ˣ�����ʧ��*/
#define	UGS_FAILED_TO_REDO_FOR_TRACkING_NOT_SUPPORT_REDO 29935	/*! �Զ�����Ŀǰ��֧������������ʧ��*/
#define	UGS_CANNOT_USE_THEMECUSTOM              29936	/*! �Զ���ר��ͼ������*/
#define	UGS_THEMECUSTOM_DATASET_DIMENSION_INVALID 29937	/*! �Զ���ר��ͼ���������ݼ�ά�����Ϸ�*/
#define	UGS_THEMECUSTOM_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29938	/*! �Զ���ר��ͼ����XMLʱ�Ҳ�����Ӧ�ı�ǩ*/
#define	UGS_THEMECUSTOM_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29939	/*! �Զ���ר��ͼ�����XMLʱ�Ҳ���Theme��ǩ*/
#define	UGS_THEMECUSTOM_FAILED_TO_READ_XML      29940	/*! �Զ���ר��ͼ�����ȡXML��Ϣʧ��*/
#define	UGS_THEMECUSTOM_FIELD_TYPE_INVALID      29941	/*! �Զ���ר��ͼ�ֶ����Ͳ��Ϸ�*/
#define	UGS_THEMECUSTOM_FAILED_TO_GET_FIELD_VALUE 29942	/*! �Զ���ר��ͼ��ȡ�ֶ�ֵʧ��*/
#define	UGS_THEMECUSTOM_XML_IS_NULL             29943	/*! �Զ���ר��ͼ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_DEFINE_OPERATER_STRING_IS_NULL_OR_LENGTH_LESSTHAN_EIGHT 29944	/*! �Զ��������ַ���Ϊ�ջ򳤶�С�ڰ˸��ַ�*/
#define	UGS_REGION_NEED_AT_LEAST_THREE_POINTS   29945	/*! ����������ܹ���*/
#define	UGS_GEOLINE_NEED_MORETHAN_TWO_POINTS    29946	/*! ������Ҫ������ܹ���GeoLine*/
#define	UGS_INVALID_NODE_ID                     29947	/*! �ڵ�ID�Ƿ�*/
#define	UGS_WRONG_NODE_COUNT                    29948	/*! �ڵ��������*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE_DISTANCE 29949	/*! �ڵ�����ͷ�����������һ��*/
#define	UGS_NODE_COUNT_LESSTHAN_ONE             29950	/*! �ڵ��������1*/
#define	UGS_NODE_COUNT_INFO_NOT_MATCH           29951	/*! �ڵ���Ϣ������һ��*/
#define	UGS_NODE_TOLERANCE_LESSTHAN_MIN         29952	/*! �ڵ�����С����Сֵ*/
#define	UGS_NODE_POINTER                        29953	/*! �ڵ�ָ��*/
#define	UGS_NODE_POINTER_INVALID                29954	/*! �ڵ�ָ��Ƿ�*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE   29955	/*! �ڵ�ĸ����ͷ������������һ��*/
#define	UGS_NODE_TYPE_IS_NULL                   29956	/*! �ڵ�����Ϊ��*/
#define	UGS_NODE_INDEX_NEGATIVE                 29957	/*! �ڵ�����Ϊ��*/
#define	UGS_NODE_INDEX_TOO_SMALL                29958	/*! �ڵ�����̫С*/
#define	UGS_INVALID_NODE_INDEX                  29959	/*! �ڵ������Ƿ�*/
#define	UGS_INVLID_NODE                         29960	/*! �ڵ�Ƿ�*/
#define	UGS_COSTFIELD_IS_NULL                   29961	/*! �����ֶ�Ϊ��*/
#define	UGS_NOT_SET_COST                        29962	/*! �����ֶ�û������*/
#define	UGS_COST_MARK_NULL                      29963	/*! ���ѱ��Ϊ��*/
#define	UGS_THEMERANGE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29964	/*! ��Χר��ͼ����XML��Ϣʱ�Ҳ���ר��ͼ��ǩ*/
#define	UGS_THEMERANGE_SEGEMENT_COUNT_INVALID   29965	/*! ��Χר��ͼ�ֶθ������Ϸ�*/
#define	UGS_THEMERANGE_CLASSIFY_RECORDSET_IS_NULL 29966	/*! ��Χר��ͼ�ֶ�ʱ��¼��Ϊ��*/
#define	UGS_THEMERANGE_SEGMENT_BOUNDS_LESSTHAN_ZERO 29967	/*! ��Χר��ͼ�ֶη�ΧС��0*/
#define	UGS_THEMERANGE_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE 29968	/*! ��Χר��ͼ����ת��Ϊ˫��������ʧ��*/
#define	UGS_THEMERANGE_FIELD_INVALID            29969	/*! ��Χר��ͼ�ֶβ��Ϸ�*/
#define	UGS_THEMERANGE_NOT_FOUND_THE_INDEX      29970	/*! ��Χר��ͼ�Ҳ�����Ӧֵ������*/
#define	UGS_THEMERANGE_FINDFIELD_INVALID_INDEX  29971	/*! ��Χר��ͼ�����ֶ�ʱ�������Ϸ�*/
#define	UGS_THEMERANGE_FINDTEXTSTYLE_FAILED_TO_GET_FIELDVALUE 29972	/*! ��Χר��ͼ���ҷ��ʱ��ȡ�ֶ�ֵʧ��*/
#define	UGS_THEMERANGE_REMOVEAT_COUNT_LESSTHAN_ONE 29973	/*! ��Χר��ͼ�Ƴ�����С��1*/
#define	UGS_THEMERANGE_FAILED_TO_GET_RECORDSET_WHEN_EXTREMUM 29974	/*! ��Χר��ͼ���㼫ֵʱ��ȡ��¼����Ϣʧ��*/
#define	UGS_THEMERANGE_RECORDSET_IS_NULL_WHEN_EXTREMUM 29975	/*! ��Χר��ͼ���㼫ֵʱ��¼��Ϊ��*/
#define	UGS_THEMERANGE_MAKEDEFAULTCAPTION_BOUNDS_COUNT_IS_ZERO 29976	/*! ��Χר��ͼ����Ĭ�ϱ���ʱ��Χ����Ϊ��*/
#define	UGS_THEMERANGE_MAKEDEFAULTSTYLE_FIELD_COUNT_IS_ZERO 29977	/*! ��Χר��ͼ����Ĭ�Ϸ��ʱ�ֶθ���Ϊ��*/
#define	UGS_THEMERANGE_MAKEDEFAULTSTYLE_FIELD_COUNT_IS_ZERO_BAK 29978	/*! ��Χר��ͼ����Ĭ�Ϸ��ʱ�ֶθ���Ϊ��_BAK*/
#define	UGS_THEMERANGE_FAILED_TO_READ_XML       29979	/*! ��Χר��ͼ��ȡXML��Ϣʱ�����ȡʧ��*/
#define	UGS_THEMERANGE_READING_XML_STRING_IS_NULL 29980	/*! ��Χר��ͼ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_THEMERANGE_MAKEDEFAULT_SEGMENT_COUNT_LESSTHAN_ZERO 29981	/*! ��Χר��ͼĬ�Ϸֶ�ʱ�ֶ���ĿС��2*/
#define	UGS_FAILED_TO_GET_GEOMETRY_POINTS       29982	/*! ��ȡGeometry�㴮ʧ��*/
#define	UGS_ODBC_FETCH_ID_FAILED                29983	/*! ��ȡIDʧ��*/
#define	UGS_GET_OGRLAYER_POINTER_IS_NULL        29984	/*! ��ȡOGRLayerָ��Ϊ��*/
#define	UGS_FAILED_TO_GET_CREATEDATASOURCE_ADDRESS 29985	/*! ��ȡSDX �½�����Դ������ַʧ��*/
#define	UGS_COUNT_NOT_MATCH                     29986	/*! ��ȡ������ƥ��*/
#define	UGS_SQLPLUS_GETMAPPING_FAILED           29987	/*! ��ȡԪ����Ӱ����Ϣʧ��*/
#define	UGS_ODBC_GETLIBTILE_ID_FAILED           29988	/*! ��ȡͼ��IDʧ��*/
#define	UGS_ODBC_FETCH_FOREIGHNTABLE_VALUE_FAILED 29989	/*! ��ȡ��ӱ�ֵʧ��*/
#define	UGS_ODBC_GETIFILEDINFO_FAILED           29990	/*! ��ȡ�ֶ���Ϣʧ��*/
#define	UGS_FAILED_TO_GET_FIELD_INFO            29991	/*! ��ȡ�ֶ���Ϣʧ����*/
#define	UGS_ODBC_GETOBJECTCOUNT_FAILED          29992	/*! ��ȡ������ʧ��*/
#define	UGS_FAILED_TO_ONLAYERSMODIFIED_FOR_THE_WORKSPACE_IS_NULL 29993	/*! ��ȡ�����ռ�Ϊ�գ��޸�ͼ��ʧ��*/
#define	UGS_ODBC_GETWORKSPACEINFO_FAILED        29994	/*! ��ȡ�����ռ���Ϣʧ��*/
#define	UGS_FETCH_DATA_FAILED                   29995	/*! ��ȡ����ʧ��*/
#define	UGS_ODBC_GETALLDBINFO_FAILED            29996	/*! ��ȡ���ݿ�������������ݿ��û���Ϣʧ��*/
#define	UGS_ODBC_GET_DATAVERSION_INFOS_FAILED   29997	/*! ��ȡ���ݰ汾��Ϣʧ��*/
#define	UGS_ODBC_GET_DATASET_UPDATETIME_FAILED  29998	/*! ��ȡ���ݼ�����ʱ��ʧ��*/
#define	UGS_FAILED_TO_GET_DATASET_TYPE          29999	/*! ��ȡ���ݼ�����ʧ��*/
#define	UGS_ODBC_REFRESHMAXGEOSIZE_FAILED       30000	/*! ��ȡ������Ĵ�С*/
#define	UGS_ODBC_GETSYSTABLESELVALUE_FAILED     30001	/*! ��ȡĳЩϵͳ�����ض��ֶε����ֵ*/
#define	UGS_SQLPLUS_GETTEMPLATENAMES_FAILED     30002	/*! ��ȡģ������ʧ��*/
#define	UGS_FAILED_TO_GET_POINTS                30003	/*! ��ȡ�㴮ʧ��*/
#define	UGS_ODBC_REFINE_VERSION_TABLE_IDS_FAILED 30004	/*! ��ȡ�汾���еļ�¼IDʧ��*/
#define	UGS_GOAL_DATASOURCE_POINTER_IS_NULL     30005	/*! ��ȡ��GDAL����Դָ��Ϊ��*/
#define	UGS_OGR_DATASOURCE_POINTER_IS_NULL      30006	/*! ��ȡ��OGR����Դָ��Ϊ��*/
#define	UGS_FAILED_TO_GET_SPATIAL_DATA          30007	/*! ��ȡ�ռ�����ʧ��*/
#define	UGS_FAILED_TO_GET_SPATIAL_POINTS        30008	/*! ��ȡ�ռ�㴮ʧ��*/
#define	UGS_FAILED_GET_GRADE_FIELD              30009	/*! ��ȡ�ȼ��ֶ�ʧ��*/
#define	UGS_UGSCENESTORAGE_GET_INDEX_FAILED_D   30010	/*! ��ȡ����Ϊ%d����ά����ʧ��*/
#define	UGS_GET_INDEX_LAYOUT_FAILED_D           30011	/*! ��ȡ����Ϊ%d�Ĳ���ʧ��*/
#define	UGS_GET_INDEX_PACKAGE_OBJECT_ID_FAILED  30012	/*! ��ȡ�������ڶ���IDʧ��*/
#define	UGS_GET_INDEX_PACKAGE_DATA_FAILED       30013	/*! ��ȡ������������ʧ��*/
#define	UGS_GET_INDEX_PACKAGE_MAX_FAILED        30014	/*! ��ȡ���������ֵʧ��*/
#define	UGS_GET_INDEX_PACKAGE_BOUNDS_FAILED     30015	/*! ��ȡ�������ķ�Χʧ��*/
#define	UGS_FAILED_TO_GET_NODE_ALLOT            30016	/*! ��ȡ�ڵ����ʧ��*/
#define	UGS_COST_IS_NULL                        30017	/*! ��ȡ����Ϊ��*/
#define	UGS_FAILED_TO_GET_COST_FIELD            30018	/*! ��ȡ�����ֶ�ʧ��*/
#define	UGS_ODBC_GETRECORDCOUNT_FAILED          30019	/*! ��ȡ��¼��ʧ��*/
#define	UGS_GET_RECORDSET_IS_NULL               30020	/*! ��ȡ��¼��Ϊ��*/
#define	UGS_FAILED_TO_GET_TRNCOST               30021	/*! ��ȡת�򻨷�ʧ��*/
#define	UGS_FAILED_TO_GET_TRACE_COST            30022	/*! ��ȡ׷�ٻ���ʧ��*/
#define	UGS_ODBC_FETCH_LINKTABLE_DATA_FAILED    30023	/*! ��ȡ���ӱ�����ʧ��*/
#define	UGS_ODBC_GETKEY_FAILED                  30024	/*! ��ȡ��ֵʧ��*/
#define	UGS_FAILED_TO_GET_DMNODE_INFO           30025	/*! ��ȡ��Ҫ��������Ϣʧ��*/
#define	UGS_TABLE_SMMETA_TEMPLATE_IS_EXIST      30026	/*! ���м�����ģ���Ѿ�����*/
#define	UGS_COPIED_GEO_TYPE_DIFFER_WITH_TARGET_GEO 30027	/*! �������ļ��ζ�����Ŀ��������Ͳ�һ��*/
#define	UGS_QUERIED_DATASET_POINTER_NULL        30028	/*! ����ѯ���ݼ�ָ��Ϊ��*/
#define	UGS_QUERIED_RECORDSET_OBJECTS_COUNT_IS_ZERO 30029	/*! ����ѯ��¼��������Ϊ��*/
#define	UGS_QUERIED_RECORDSET_POINTER_NULL      30030	/*! ����ѯ��¼��ָ��Ϊ��*/
#define	UGS_QUERIED_RECORDSET_TYPE_INVALID      30031	/*! ����ѯ��¼�����Ͳ��Ϸ�*/
#define	UGS_FAILED_TO_OPEN_APPENDED_DATASET     30032	/*! ��׷�ӵ����ݼ���ʧ��*/
#define	UGS_IMPORT_FILE_NAME_IS_NULL            30033	/*! Ҫ����������ļ���Ϊ�գ�*/
#define	UGS_ERROR_WHEN_SOLVE_ATABLE_VERSION_CONFILCT 30034	/*! ���A��汾��ͻʱ��������*/
#define	UGS_ERROR_WHEN_SOLVE_DTABLE_VERSION_CONFILCT 30035	/*! ���D��汾��ͻʱ��������*/
#define	UGS_ODBC_CALCULATE_UNIQUEVALUES_FAILED  30036	/*! ���㵥ֵʧ��*/
#define	UGS_ODBC_COMPUTE_BOUNDS_FAILED          30037	/*! ������Ӿ���ʧ��*/
#define	UGS_ODBC_COMPUTERECCOUNT_FAILED         30038	/*! �����¼��ʧ��*/
#define	UGS_RECORDSET_COUNT_IS_ZERO             30039	/*! ��¼������Ϊ0*/
#define	UGS_RECORDSET_IS_EMPTY                  30040	/*! ��¼��Ϊ��*/
#define	UGS_RECORDSET_IS_NULL                   30041	/*! ��¼��Ϊ��*/
#define	UGS_RECORDSET_POINTER_IS_NULL           30042	/*! ��¼��ָ��Ϊ��*/
#define	UGS_RECORDSET_POINT_TO_BOF              30043	/*! ��¼���α��ڿ�ͷ*/
#define	UGS_RECORDSET_POINT_TO_EOF              30044	/*! ��¼���α��ڽ�β*/
#define	UGS_RECORDSET_INDEX_INVALID             30045	/*! ��¼��������Ч*/
#define	UGS_RECORDSET_OUTOF_BOUNDS              30046	/*! ��¼��Խ��*/
#define	UGS_MAP_OR_EQUIPMENT_BOUNDS_IS_NULL     30047	/*! �豸��Χ���ߵ�ͼ��ΧΪ��*/
#define	UGS_SET_LAYER_EDIT_INDEX_MORETHAN_TOTAL_COUNT 30048	/*! ����ͼ��ɱ༭ʱ��ָ��ͼ����������ͼ������*/
#define	UGS_ODBC_SETIFILEDINFO_FAILED           30049	/*! �����ֶ���Ϣʧ��*/
#define	UGS_ODBC_SETFILEDNAME_BY_SIGN_FAILED    30050	/*! �����ֶ����ʧ��*/
#define	UGS_SET_IMPORT_PARAM                    30051	/*! ���õ������*/
#define	UGS_INVALID_DATASET_WHEN_SET_SORTING_FIELD 30052	/*! ���������ֶ���ʾ˳��ʱ���ݼ����Ϸ�*/
#define	UGS_ODBC_SET_DATAOURCEINFO_FAILED       30053	/*! ��������Դ��Ϣʧ��*/
#define	UGS_ODBC_SETBOUNDS_FAILED               30054	/*! �������ݼ���Χʧ��*/
#define	UGS_ODBC_SETMAXGEOSIZE_FAILED           30055	/*! ������󼸺ζ���Ĵ�С*/
#define	UGS_FAILED_TO_SET_SUBACTION_FOR_NOT_SUPPORT_THIS_SUBACTION 30056	/*! ���õ�SubAction:%d��֧��,����SubActionʧ��*/
#define	UGS_GEOMETRY_SETTED_IS_NULL             30057	/*! ���õļ��ζ���Ϊ��*/
#define	UGS_GEOMETRY_SETTED_ORIGINAL_SMID_ISNOT_NEGATIVE_ONE 30058	/*! ���õļ��ζ����ʼ����SmID��Ϊ-1*/
#define	UGS_D_GRAPHICS_NOT_EXIST_SET_FAILED     30059	/*! ��������Ϊ%d��Graphics�����ڣ�����ʧ��*/
#define	UGS_OUTPUT_DATASOURCE_IS_NULL           30060	/*! �����������ԴΪ��*/
#define	UGS_WORD_POINTER_IS_NULL                30061	/*! �ʴ�ָ��Ϊ��*/
#define	UGS_WORD_NUM_IS_NULL                    30062	/*! �������Ϊ��*/
#define	UGS_INVALID_WORD_SIZE                   30063	/*! ���ﴮ��С�Ƿ�*/
#define	UGS_WORD_IS_NULL                        30064	/*! ����Ϊ��*/
#define	UGS_FAILED_TO_DRAW_FOR_LAYER_IS_UNVISIBLE 30065	/*! ��ͼ�㲻�ɼ�������ʧ��*/
#define	UGS_READ_DATASETS_FAILED                30066	/*! ��ȡ���ݼ�ʧ��*/
#define	UGS_READ_INFO_FAILED                    30067	/*! ��ȡ��Ϣʧ��*/
#define	UGS_READ_SDBINFO_FAILED                 30068	/*! ��ȡ�ļ�������Դ��Ϣʧ��*/
#define	UGS_READING_XML_STRING_IS_NULL          30069	/*! ��ȡXML��Ϣʱ�ַ���Ϊ��*/
#define	UGS_LAYERS_CANNOT_FIND_LABEL_WHEN_READING_XML 30070	/*! ��ȡXMLʱͼ���ǩ�Ҳ���*/
#define	UGS_NOT_FIND_LAYER_TAB_WHEN_READ_XML    30071	/*! ��ȡXMLʱ��ͼ���ǩû���ҵ�*/
#define	UGS_NOT_FIND_MAP_LABEL_WHEN_READ_XML    30072	/*! ��ȡXMLʱ��û���ҵ���ͼ��ǩ*/
#define	UGS_NOT_FIND_NAME_LABEL_WHEN_READ_XML   30073	/*! ��ȡXMLʱ��û���ҵ����Ʊ�ǩ*/
#define	UGS_FAILED_TO_READ_ONE_GEOMETRY         30074	/*! ��ȡһ�����ζ���ʧ��*/
#define	UGS_CANNOT_FIND_THE_VERSION_WHEN_READ_BASICCLASS 30075	/*! ��ȡר��ͼ������Ϣʱ�Ҳ�����Ӧ�İ汾*/
#define	UGS_FAILED_TO_READ_DATA                 30076	/*! ��ȡ����ʧ��*/
#define	UGS_FAILED_TO_READ_DATASOURCE_INFO      30077	/*! ��ȡ����Դ��Ϣʧ�ܣ�*/
#define	UGS_FAILED_TO_READ_FIELD_INFO           30078	/*! ��ȡ���ݱ��ֶ���Ϣ����*/
#define	UGS_READ_COLOR_TABLE_FAILED             30079	/*! ��ȡ��ɫ������ʧ��*/
#define	UGS_INVLAID_STARTPOINT_AND_ENDPOINT     30080	/*! ��ʼ�����ֹ��Ƿ�*/
#define	UGS_STARTPOINT_IS_BARRIERNODE           30081	/*! ��ʼ�����ϰ���*/
#define	UGS_INVALID_STARTNODE                   30082	/*! ��ʼ��Ƿ�*/
#define	UGS_INVALID_STARTPOINT_M                30083	/*! ���Mֵ��Ч*/
#define	UGS_STARTPOINT_AND_ENDPOINT_NOT_CONNECTED 30084	/*! �����յ㲻��ͨ*/
#define	UGS_STARTPOINT_AND_ENDPOINT_IS_SAME     30085	/*! �����յ���ͬ*/
#define	UGS_START_POINT_MUST_BE_ZERO            30086	/*! ������Ϊ0*/
#define	UGS_DISTANCE_POINTER_IS_NULL            30087	/*! ����ָ��Ϊ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_CREATE_DATASOURCE 30088	/*! ���ٲ㴴������Դʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DELETE_THE_LABEL_OBJECT 30089	/*! ���ٲ�ɾ����Ӧ��ǩ�Ķ���ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_TO_SEARCH_THE_GEO 30090	/*! ���ٲ���Ҷ�Ӧ���ζ���ʧ��*/
#define	UGS_TRACKINGLAYER_FAILED_FIND_THE_LABEL_INDEX 30091	/*! ���ٲ���Ҷ�Ӧ��ǩ������ʧ��*/
#define	UGS_TRACKINGLAYER_CANNOT_USE_THE_ADDING_GEO 30092	/*! ���ٲ���Ӽ��ζ��󲻿���*/
#define	UGS_TRACKINGLAYER_FAILED_TO_ADD         30093	/*! ���ٲ���Ӷ���ʧ��*/
#define	UGS_TRACKINGLAYER_REMOVE_COUNT_LESSTHAN_ONE 30094	/*! ���ٲ��Ƴ�����С��1*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DRAW        30095	/*! ���ٲ����ʧ��*/
#define	UGS_TRACKINGLAYER_RECORDSET_IS_NULL_WHEN_DRAW 30096	/*! ���ٲ����ʱ��¼��Ϊ��*/
#define	UGS_TRACKINGLAYER_GETTING_THE_INDEX_INVALID 30097	/*! ���ٲ��ȡ��Ӧ������������Ϸ�*/
#define	UGS_TRACKlAYER_RECORDSET_IS_NULL        30098	/*! ���ٲ��¼��Ϊ��*/
#define	UGS_PATH_COUNT_LESSTHAN_ZERO            30099	/*! ·������С��0*/
#define	UGS_FAILED_TO_PATH                      30100	/*! ·������ʧ��*/
#define	UGS_ROUTE_COUNT_LESSTHAN_ZERO           30101	/*! ·�ɸ���С��0*/
#define	UGS_TRN_FIELD_ERROR                     30102	/*! ת����ֶ����ô���*/
#define	UGS_DTTRN_IS_NULL                       30103	/*! ת������ݼ�Ϊ��*/
#define	UGS_OUTPUT_MAP_NAME_IS_NULL             30104	/*! �����ͼ����Ϊ��*/
#define	UGS_TOO_LARGE_RESOLUTION_WHEN_OUTPUT_MAP 30105	/*! �����ͼʱ���ֱ���̫��*/
#define	UGS_FAILED_TO_CREATE_FEAT_DISPLAY_ENGINE_OR_ENGINE_IS_NULL 30106	/*! �����ͼʱ�������ڴ���ʾ����Ϊ�ջ��ߴ���������ʾ����ʧ��*/
#define	UGS_FAILED_TO_CREATE_MEMORY_ENGINE      30107	/*! �����ڴ�����ʧ��*/
#define	UGS_FAILED_TO_CREATE_ALLOT_POINTS_FILE  30108	/*! ����������ļ�ʧ��*/
#define	UGS_FAILED_TO_CREATE_MEMORY_DISPLAY_ENGINE_WHEN_OUTPUT_MAP 30109	/*! �����ͼʱ�������ڴ���ʾ����ʧ��*/
#define	UGS_FAILED_TO_CREATE_FEAT_IAMGE_WHEN_OUTPUT_MAP 30110	/*! �����ͼʱ���������ʵ�ͼ��ʧ��*/
#define	UGS_RASTER_IS_NULL_WHEN_OUTPUT_MAP      30111	/*! �����ͼʱ������դ�����ݼ�Ϊ��*/
#define	UGS_IAMGE_OVERRUN_WHEN_OUTPUT_MAP       30112	/*! �����ͼʱ��ͼ������Ϊ�ջ���ͼ���ʽС��16λ*/
#define	UGS_WIDTH_OVERRUN_WHEN_OUTPUT_MAP       30113	/*! �����ͼʱ����ȴ���32767*/
#define	UGS_INVALID_DATASET_NAME_WHEN_OUTPUT_MAP 30114	/*! �����ͼʱ�����ݼ����ƷǷ�*/
#define	UGS_FAILED_TO_OPEN_FILE_WHEN_OUTPUT_MAP 30115	/*! �����ͼʱ���ļ���ʧ��*/
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_TEN_WHEN_OUTPUT_MAP 30116	/*! �����ͼʱ���߶Ȼ��߿��С��10*/
#define	UGS_OUTPUT_MAP_BOUND_IS_NULL            30117	/*! �����ͼ��ΧΪ��*/
#define	UGS_OUTPUT_BUFFER_HAS_NO_ENOUGH_ROOM    30118	/*! �������û���㹻�Ŀռ�*/
#define	UGS_OUTPUT_TRN                          30119	/*! ���ת���*/
#define	UGS_ODBC_ENHANCE_IDS_FAILED             30120	/*! ����IDʧ��*/
#define	UGS_RETURN_FALSE                        30121	/*! ����false*/
#define	UGS_INVALID_LEVEL_PARAMETER             30122	/*! ��һ����Ĳ�������*/
#define	UGS_DATASET_ATTACH_TOPO                 30123	/*! ������ݼ��Ѿ�������Topo*/
#define	UGS_NODE_IS_BARRIER_NODE                30124	/*! �����һ���ϰ���*/
#define	UGS_VIRTUAL_NODES                       30125	/*! �������ڵ�*/
#define	UGS_NODE_IS_BARRIERNODE                 30126	/*! ����ڵ����ϰ���*/
#define	UGS_THE_NODE_ANALYSIS_FAILED            30127	/*! ����ڵ�ķ���ʧ��*/
#define	UGS_FAILED_TO_OPEN_APPENDING_DATASET    30128	/*! ׷�ӵ����ݼ���ʧ��*/
#define	UGS_APPENDING_DATASET_POINTER_IS_NULL   30129	/*! ׷�ӵ����ݼ�ָ��Ϊ��*/
#define	UGS_DYNAMICINDEX_WILL_FAIL_IN_SQLPLUS   30130	/*! ׷�Ӽ�¼�󣬶�̬������*/
#define	UGS_TRACE_INVALID_STARTNODE_AND_ENDNODE 30131	/*! ׷��ǰ��ڵ�Ƿ�*/
#define	UGS_FAILED_TO_TRACE                     30132	/*! ׷��ʧ��*/
#define	UGS_TRACE_NODE_LESSTHAN_TWO             30133	/*! ׷�ٵ������������*/
#define	UGS_INVALID_TRACEPOINT_INDEX            30134	/*! ׷�ٵ������Ƿ�*/
#define	UGS_TRACE_COST_FAILED_TO_ALLOT_MEMORY   30135	/*! ׷�ٻ����ڴ����ʧ��*/
#define	UGS_LOCATION_COUNT_LESSTHAN_ZERO        30136	/*! ѡַ��������С��0*/
#define	UGS_SELECT_IMAGE_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 30137	/*! ѡ��Imageʧ�ܣ�׼�����ƻ���ʧ��*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_FAILED_TO_SELECT_IMAGE 30138	/*! ѡ��Imageʧ�ܣ�ˢ�¶���ʧ��*/
#define	UGS_DATASET_OR_SELECT_COUNT_IS_MULL     30139	/*! ѡ�����Ϊ��������ݼ�Ϊ��*/
#define	UGS_SELECT_WRONG_ANALYSIS_TYPE          30140	/*! ѡ��������Ͳ���ȷ*/
#define	UGS_SELECT_WRONG_NODE                   30141	/*! ѡ��ģʽ����*/
#define	UGS_SELECTION_DELETE_NONE               30142	/*! ѡ����ɾ������Ϊ��*/
#define	UGS_SELECTION_RECORDSET_POINTER_IS_NULL 30143	/*! ѡ���м�¼��ָ��Ϊ��*/
#define	UGS_OPTION_INVALID                      30144	/*! ѡ��Ƿ�*/
#define	UGS_SQLPLUS_GET_TEMPLATE_BY_NAME_FAILED 30145	/*! ͨ�����ƻ�ģ��ʧ��*/
#define	UGS_ODBC_GETFILEDNAME_BY_SIGN_FAILED    30146	/*! ͨ���ֶ�����ȡ�ֶ�����ʧ��*/
#define	UGS_RESMAPLE_INTERVAL_MUST_MORETHAN_ZERO 30147	/*! �ز�������������0*/
#define	UGS_ODBCDATASETRASTER_TIER_ISAVAILABLEDATASETNAME_FAILED 30148	/*! ���������ݼ����ƷǷ�*/
#define	UGS_MAP_HEIGHT_OR_WIDTH_IS_ZERO_LOCKMAPDRAWBOUNDS_FAILED 30149	/*! ������ͼ��Χ�߶Ȼ��߿��Ϊ0��������ͼ���Ʒ�Χʧ��*/
#define	UG_ERROROBJ_OUTPUT_FORMAT_DEBUG         30150	/*! ������: %ERRORCODE\t ������Ϣ: %ERRORMSG\t �����ļ�: %CODEFILE\t ������: %CODELINE\t �߳�ID: %THREADID*/
#define	UG_ERROROBJ_OUTPUT_FORMAT               30151	/*! ������: %ERRORCODE\t ������Ϣ: %ERRORMSG\t �߳�ID: %THREADID*/
#define	UGS_ODBCCONNECTION_SQLENDTRAN_FAILED    30152	/*! ������ع�ʧ��*/
#define	UGS_DTDMARC_IS_NULL                     30153	/*! ���󻡶����ݼ�Ϊ��*/
#define	UGS_DTDMNODES_IS_NULL                   30154	/*! ��������ݼ�Ϊ��*/
#define	UGS_LAYER_NEEDED_MOVING_OVERRUN         30155	/*! ��Ҫ�ƶ���ͼ�㲻�ڷ�Χ֮��*/
#define	UGS_ONLY_TIN_SUPPORT_THIS_METHOD        30156	/*! ֻ��Tin���ݼ�֧�ִ˷���*/
#define	UGS_INVALID_DYNAMIC_LIB_S               30157	/*! ��̬��Ƿ���*/
#define	UGS_INVALID_PARAM_FOR_RADIUS_SHOULID_MORETHAN_ZERO 30158	/*! �����Ƿ����뾶��ӦС��0*/
#define	UGS_INVALID_PARAM_FOR_POINTS_POINTER_AND_POINTS_NOT_NULL 30159	/*! �����Ƿ����㴮ָ��Ӧ�ǿ��Ҵ���㴮��СӦ����0*/
#define	UGS_FAILED_TO_MERGE_FOR_INVALID_DIM     30160	/*! �ϲ�������������ζ���ά�Ȳ�һ�£��ϲ�ʧ��*/
#define	UGS_INVALID_GML_VERSION                 30161	/*! GML�汾��Ϣ�Ƿ�*/
#define	UGS_INVLAID_TOPO_RULES                  30162	/*! Topo����Ƿ�*/
#define	UGS_INVALID_PIXELFORMAT                 30163	/*! ���ظ�ʽ�Ƿ�*/
#define	UGS_INVALID_GEO                         30164	/*! ���ζ���Ƿ�*/
#define	UGS_INVALID_GEO_FOR_SUBCOUNT_EQUAL_ZERO 30165	/*! ���ζ���Ƿ����Ӷ������Ϊ��*/
#define	UGS_FAILED_TO_PREPROCESS                30166	/*! Ԥ����ʧ��*/
#define	UGS_RECORDSET_POINTER_IS_NULL_WHEN_CONVERT_THEMESTYLE_TO_DATASET 30167	/*! ���ר��ͼת���ݼ�ʱ��¼��ָ��Ϊ��*/
#define	UGS_ODBC_SUPPORT_FUNCTIONS_FAILED       30168	/*! ��������֧�ָ�ODBC����*/
#define	UGS_FAILED_TO_ONREDO_FOR_MOUSE_CLICK_IS_NULL 30169	/*! �������Ϊ0������ʧ��*/
#define	UGS_FAILED_TO_ONUNDO_FOR_MOUSE_CLICK_IS_NULL 30170	/*! �������Ϊ0������ʧ��*/
#define	UGS_BUFFER_ANALYSIS_RADIUS_IS_ZERO      30171	/*! ����뾶Ϊ��*/
#define	UGS_OBJECT_IS_NULL                      30172	/*! ����Ϊ��*/
#define	UGS_UGBUSNETWORK_ATTRIBUTE_TABLE_FIELD_ILLEGAL 30173	/*! ���ص����Ա��ֶβ����Ϲ����������Ա��ֶα�׼*/

#endif
