#ifndef UGENGDEFS_H
#define UGENGDEFS_H

#include "Base/ugdefs.h"
#include "Geometry/UGGeoRegion.h"
namespace UGC
{

	
#define UGMAXONCEGEOSIZE	20971520
#define UGMAXROOTLEAFSIZE   1258496

#define UGRTREEEDITED		5
	
/* zengzm: ugdefs������, �����ע�͵��� 	
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : "
*/	

//===================================================================================================================
//{{ͼ���ֶζ��� 
//===================================================================================================================
//		����				�ֶ���				����			˵��		���õ�ͼ������
//...................................................................................................................
#define LF_OBJ_ID		"SmID"			// (dbLong)			�ڲ����	(All)
#define LF_USER_ID		"SmUserID"		// (dbLong)			�û����	(All)
#define LF_TREE_INDEX	"SmKey"			// (dbLong)			�Ĳ�������	ALL Geometry Dataset.   
#define LF_LT_KEY		"SmLTKey"		// (dbLong)			��������	All Geometry Dataset.
#define LF_RB_KEY		"SmRBKey"		// (dbLong)			��������	All Geometry Dataset.
#define LF_GEO_POS		"SmGeoPos"		// (dbLong)			Geometry��λ��	All Geometry Dataset.
#define LF_GEOMETRY		"SmGeometry"	// (dbLongBinary)	��������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GEO_TYPE		"SmGeoType"		// (dbSingle)		���������	ltCAD ,because geometry data can't distinguish type of itself
#define LF_SDRI_W		"SmSdriW"		// (dbDouble)		��С������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_N		"SmSdriN"		// (dbDouble)		��С������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_E		"SmSdriE"		// (dbDouble)		��������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_S		"SmSdriS"		// (dbDouble)		���������	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GRANULE		"SmGranule"		//(dbDouble)		���������  ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_CHECKED_USER_ID	"SmCheckedUserID"	//(dbLong)	��¼�û�ID	(ALL)
#define LF_EDIT_STATE	"SmEditState"	//(dbInteger)		�༭״̬	(ALL)
#define LF_SDRI_T		"SmSdriT"		// (dbDouble)		��С�߳�	ltTin
#define LF_SDRI_B		"SmSdriB"		// (dbDouble)		���߳�	ltTin
#define LF_SDRI_I		"SmSdriI"		// (dbDouble)		��С����	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_NODE_ID		"SmNodeID"		// (dbLong)			�ڵ��ţ�	ltNetwork,��ǰĬ��ʹ��SmID,���ڵ�������һ���ֶ�
#define LF_FNODE		"SmFNode"		// (dbLong)			��ʼ�ڵ�	ltNetwork
#define LF_TNODE		"SmTNode"		// (dbLong)			��ֹ�ڵ�	ltNetwork
#define LF_RESISTANCE_A	"SmResistanceA"	// (dbDouble)		����������	ltNetwork
#define LF_RESISTANCE_B	"SmResistanceB"	// (dbDouble)		����������	ltNetwork
#define LF_X			"SmX"			// (dbDouble)		��������	ltPoint & ltPoint3D
#define LF_Y			"SmY"			// (dbDouble)		���������	ltPoint & ltPoint3D
#define LF_Z			"SmZ"			// (dbDouble)		��ĸ߳�	ltPoint3D
#define LF_LENGTH		"SmLength"		// (dbDouble)		����		ltLine& Network
#define LF_AREA			"SmArea"		// (dbDouble)		���		ltRegion
#define LF_PERIMETER	"SmPerimeter"	// (dbDouble)		�ܳ�		ltRegion 
#define LF_ASPECT		"SmAspect"		// (dbDouble)		����		ltTin
#define LF_SLOPE		"SmSlope"		// (dbDouble)		�¶�		ltTin
#define LF_TOPO_ERROR	"SmTopoError"	// (dbLong)			���˴���	ltNetwork, ltLine
#define LIB_SMID		"SmLibTileID"

#define LF_CONJOINT_POINTS		"SmConjointPoints"	// (dbLongBinary)			TIN�ڵ���ٽ��㼯��	ltPointGL
#define	LF_POINT_COLOR			"SmPointColor"		//TIN�ڵ����ɫ����ֵ��ʾ��Ч

//{{ route���ݼ�����Section����ֶ�
#define LF_ROUTE_ID				"SmRouteID"
#define LF_USER_ROUTE_ID		"SmUserRouteID"

#define LF_SECTION_ARC			"SmEdgeID"
#define LF_SECTION_FROM_MEASURE "SmFromMeasure"	
#define LF_SECTION_TO_MEASURE	"SmToMeasure"	
#define LF_SECTION_FROM_POS		"SmFromPos"		
#define LF_SECTION_TO_POS		"SmToPos"		

//}}

//{{
#define LF_MATCH_ERROR "SmMatchError" // ʹ��CSmDataSource::UpdateFromLcaPnts()����
                                          // �ӱ�־��ƥ���������ݵ��������ݼ�ʱ���棩��
                                          // ��¼��ƥ�����Ŀ��
                                             
//}}

//{{
#define LF_TOPO_LPOLY  "SmTopoLPolygon"
#define LF_TOPO_RPOLY  "SmTopoRPolygon"

//}}
//					0	- �޴���
//					1	- ��ʼ�ڵ������ڵ�
//					2	- ��ֹ�ڵ������ڵ�
//					3	- �����ڵ㶼�����ڵ�
//					����- �����춨��...)

/*
#define LF_RASTER_LEVEL		"SmRLevel"		// (dbLong)			դ��ֱ���			ltRaster
#define LF_RASTER_INDEX_X		"SmRIndexX"		// (dbLong)			դ���X����(�к�)	ltRaster
#define LF_RASTER_INDEX_Y		"SmRIndexY"		// (dbLong)			դ���Y����(�к�)	ltRaster

#define LF_SYMBOL_STYLE			"SmSStyle"
#define LF_SYMBOL_SIZE			"SmSSize"
#define LF_SYMBOL_ROTATION		"SmSRotation"
#define LF_SYMBOL_TEXT			"SmSText"

#define LF_PEN_STYLE			"SmPStyle"
#define LF_PEN_WIDTH			"SmPWidth"
#define LF_PEN_COLOR			"SmPColor"

#define LF_BRUSH_STYLE			"SmBStyle"
#define LF_BRUSH_FRONT_COLOR	"SmBFColor"
#define LF_BRUSH_BACK_COLOR		"SmBBColor"
 */

//===================================================================================================================
//}}ͼ���ֶζ���
//===================================================================================================================

#if PACKAGE_TYPE==PACKAGE_UGC


//˵��������һЩ����������Ҫʹ�õ�ϵͳ�������

//===============================================================================
//			����					����						˵��		
//................................................................................
#define		TN_REGISTER_TABLE		"SmRegister"			//���ݿ���ʸ�����ݼ���ע���������ʸ�����ݼ�����Ϣ	
#define		TN_IMGREGISTER_TABLE	"SmImgRegister"			//���ݿ���Ӱ�����ݼ���ע���������Ӱ�����ݼ�����Ϣ	
#define     TN_DATASOURCE_INFO		"SmDataSourceInfo"		//����Դ��Ϣ��
#define		TN_META_ELEM_TABLE		"SmMetaElementTable"	//����Դ�д������Ԫ���ݵı�
#define		TN_USERS				"SmUsers"				//��ų������û�
#define		TN_TABLE_FIELDINFO		"SmFieldInfo"			//����ֶ���ص���Ϣ���������Format��



//˵��������һЩ����������Ҫʹ�õĴ洢������.

//===============================================================================
//			����					����						˵��		
//................................................................................
#define		SP_CREATE_USER			"smsp_CreateUser"		//�����û��Ĵ洢����
#define		SP_CREATE_DATASET		"smsp_CreateDataset"	//�������ݼ��Ĵ洢����
#define		SP_DELETE_DATASET		"smsp_DeleteDataset"	//ɾ�����ݼ��Ĵ洢����
#define		SP_SET_BOUNDS			"smsp_SetBounds"		//�������ݼ���Χ�洢����
#define		SP_COPY_DATASET			"smsp_CopyDataset"		//���ظ������ݼ��Ĵ洢����
#define		SP_CREATE_DATABASE		"smsp_CreateDatabase"	//�����µ�����Դ�Ĵ洢����

//SmRegister���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		RF_ID				"SmDatasetID"		//(dbLong)		//Dataset ID
#define		RF_DATASET_NAME		"SmDatasetName"		//(dbText)		//Dataset Name
#define		RF_TABLE_NAME		"SmTableName"		//(dbText)		//Geomey and Properties Table Name
#define		RF_INDEX_TABLE_NAME	"SmIndexTableName"	//(dbText)		//Index Table Name
#define		RF_SUB_TABLE_NAME	"SmSubTableName"	//(dbText)		//Sub Table name
#define		RF_IS_SUB			"SmIsSub"			//(dbChar)		//Is/Not sub table
#define		RF_DATASET_TYPE		"SmDatasetType"		//(dbInteger)	//Dataset's type
#define		RF_RECORD_COUNT		"SmRecordCount"		//(dbInteger)	//Object count in dataset.
#define		RF_INDEX_LEVEL		"SmIndexLevel"		//(dbInteger)	//Index level of the dataset.
#define		RF_LEFT				"SmLeft"			//(dbLong)		//Dataset Bounds' Left
#define		RF_RIGHT			"SmRight"			//(dbLong)		//Dataset Bounds' Right
#define		RF_TOP				"SmTop"				//(dbLong)		//Dataset Bounds' Top
#define		RF_BOTTOM			"SmBottom"			//(dbLong)		//Dataset Bounds' Bottom
#define		RF_MAXZ				"SmMaxZ"			//(dbDouble)	//Max Z Value of Dataset
#define		RF_MINZ				"SmMinZ"			//(dbDouble)	//Min Z Value fo Dataset
#define		RF_GRID_SIZE		"SMGRIDSIZE"		//(dbDouble)	//Grid Size fo Dataset, Used for Index.
#define		RF_USER_ID			"SmUserID"			//(dbInteger)	//Long transaction user id.
#define		RF_DT_VERSION		"SmDtVersion"		//(dbInteger)	//Data updated version.
#define		RF_OPTION			"SmOption"			//(dbInteger)	//Option of the dataset.
#define		RF_ENC_TYPE			"SmEncType"			//(dbInteger)	//Spatial data encoded type.
#define		RF_DESCRIPTION		"SmDescription"		//(dbText)		//Description of the dataset.
#define		RF_THUMB			"SmThumb"			//(dbLongBinary)//Thumb of the dataset.
#define		RF_TOLERANCE_FUZZY	"SmToleranceFuzzy"	//(dbDouble)	//Fuzzy tolerance of the dataset.
#define		RF_TOLERANCE_DANGLE	"SmToleranceDangle"	//(dbDouble)	//Dangle tolerance of the dataset.
#define		RF_TOLERANCE_NODESNAP "SmToleranceNodeSnap"	//(dbDouble)//NodeSnap tolerance of the dataset.
#define		RF_TOLERANCE_SMALL_POLYGON	"SmToleranceSmallPolygon"	//(dbDouble)	//Small polygon tolerance of the dataset
#define		RF_TOLERANCE_GRAIN	"SmToleranceGrain"	//(dbDouble)	//Grain tolerance of the dataset.
#define		RF_LASTUPDATE		"SmLastUpdate"		//(dbDate)		//The lastupdate time of the dataset.
#define		RF_MAX_GEOMETRY_SIZE	"SmMaxGeometrySize"	//(dbDouble)//The max geometry size of the dataset.
#define		RF_ONCE_FETCH_COUNT	"SmOnceFetchCount"	//(dbInteger)	//Once fetch count from server.
#define		RF_OPTIMIZE_COUNT	"SmOptimizeCount"	//(dbInteger)	//Optimize parameter of the dataset.
#define		RF_OPTIMIZE_RATIO	"SmOptimizeRatio"	//(dbFloat)		//Optimize parameter of the dataset.
//...........................................................................................

//SmImgRegister���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
//#define		RF_ID					"SmDatasetID"		//(dbLong)		//Dataset ID
//#define		RF_DATASET_NAME			"SmDatasetName"		//(dbText)		//Dataset Name
//#define		RF_TABLE_NAME			"SmTableName"		//(dbText)		//Geomey and Properties Table Name
//#define		RF_DATASET_TYPE			"SmDatasetType"		//(dbInteger)	//Dataset's type
//#define		RF_OPTION				"SmOption"			//(dbInteger)	//Option of the dataset.
#define		RF_PIXEL_FORMAT				"SmPixelFormat"		//(dbInteger)	//Pixel format of the raster.
#define		RF_WIDTH					"SmWidth"			//(dbInteger)	//Width(pixels) of the raster.
#define		RF_HEIGHT					"SmHeight"			//(dbInteger)	//Height(pixels) of the raster.
#define		RF_E_BLOCK_SIZE				"SmeBlockSize"		//(dbInteger)	//e block size of the raster.
#define		RF_MAX_BLOCK_SIZE			"SmMaxBlockSize"	//(dbInteger)	//Max block size of the raster.
//#define		RF_MAXZ					"SmMaxZ"			//(dbDouble)	//Max Z Value of Dataset
//#define		RF_MINZ					"SmMinZ"			//(dbDouble)	//Min Z Value of Dataset
#define		RF_PYRAMID					"SmPyramid"			//(dbText)		//Parymid table name of the raster.
#define		RF_PYRAMID_LEVEL			"SmPyramidLevel"	//(dbInteger)	//Parymid level of the dataset.
#define		RF_BLOCK_SIZE				"SmBlockSizes"		//(dbInteger)	//Block size of the raster.
#define		RF_PALETTE					"SmPalette"			//(dbLongBinary)//Palette of the raster.
#define		RF_GEO_LEFT					"SmGeoLeft"			//(dbDouble)	//Dataset Bounds' Left
#define		RF_GEO_RIGHT				"SmGeoRight"		//(dbDouble)	//Dataset Bounds' Right
#define		RF_GEO_TOP					"SmGeoTop"			//(dbDouble)	//Dataset Bounds' Top
#define		RF_GEO_BOTTOM				"SmGeoBottom"		//(dbDouble)	//Dataset Bounds' Bottom
#define		RF_CLIP_REGION				"SmClipRegion"		//(dbLongBinary)//Clip region of raster.
#define		RF_TOLERANCE_SMALLPOLYGON	"SmToleranceSmallPolygon" 
//...........................................................................................


//SmDataSourceInfo���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		DF_VERSION			"SmVersion"			//dbLong		����Դ�汾��
#define		DF_FLAG				"SmFlag"			//dbLong		����Դ��־
#define		DF_COORDSYS			"SmCoordSys"		//dbLong		����ϵ
#define		DF_COORDUNIT		"SmCoordUnit"		//dbLong		���굥λ
#define		DF_DISTANCEUNIT		"SmDistanceUnit"	//dbLong		���ȵ�λ
#define		DF_PROJECTINFO		"SmProjectInfo"		//dbLongBinary	//ͶӰϵ����
#define		DF_DSDESCRIPTION	"SmDsDescription" 
//...........................................................................................

//SmFieldInfo���е��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		SMF_FIELD_ID		"SmID"				//dbInteger		�ֶ�ID
#define		SMF_TABLE_NAME		"SmTableName"		//dbText		���ݱ���
#define		SMF_DATASET_ID		"SmDatasetID"		//dbLong		���ݼ���ID
#define		SMF_FIELD_NAME		"SmFieldName"		//dbText		�ֶ���
#define		SMF_FIELD_CAPTION	"SmFieldCaption"	//dbText		�ֶα���
#define		SMF_FIELD_TYPE		"SmFieldType"		//dbLong		�ֶε�����
#define		SMF_FIELD_FORMAT	"SmFieldFormat"		//dbText		�ֶ���ʾ��ʽ
#define		SMF_FIELD_SIGN		"SmFieldSign"		//dbLong		�ֶα�ʶ����NodeID,FNode,TNode,EdgeID,RouteID��
#define		SMF_FIELD_SIZE		"SmFieldSize"		//dbLong		�ֶγ���
#define		SMF_FIELD_DOMAIN	"SmFieldDomain"		//dbText		�ֶ�ֵ��
#define		SMF_FIELD_UPDATABLE	"SmFieldUpdatable"	//dbBoolean		�ֶ�ֵ�Ƿ���޸�
//...........................................................................................

//ʱ�����ݿ���Ҫʹ�õ��ֶ�=======================================================================
//			����				�ֶ���					����			˵��	
//...........................................................................................
#define		SEQ_START			"SmSequenceStart"	//dbDate		��ʼʱ���
#define		SEQ_END				"SmSequenceEnd"		//dbDate		����ʱ���
#define		SEQ_STATE			"SmSequenceState"	//dbBoolean		ʱ��״̬
#define		SEQ_ORG_ID			"SmSequenceOrgID"	//dbLong		ʱ��༭����ԭʼ��SMID
//...........................................................................................

enum DatasetState
{
	dsCheckedOut	= 0x00000001,
	dsLocked		= 0x00000002		
};

enum LongTransState
{
	ltsAdded		= 0x00000001,
	ltsModified		= 0x00000002,
	ltsDeleted		= 0x00000004
};

enum SpatialQueryOption
{
	SQInner			= 0x00000001,
	SQMaybe			= 0x00000002,
	SQOuter			= 0x00000004
};

struct UG_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
};

struct UG_CAD_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
	UGuint nType;
};

struct UG_SUPER_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
	UGuint nType;
	UGuint dwX;
	UGuint dwY;
	UGdouble dZ;
};

struct UG_META_ELEMENT
{
	UGint nOID;
	UGint nLevel;
	UGint nParent;
	UGint nChild;
	UGint nPrevID;
	UGint nNextID;
	UGString strName;
	UGString strValue;

	UG_META_ELEMENT()
	{
		nOID = 0;
		nLevel = 0;
		nParent = 0;
		nChild = 0;
		nPrevID = 0;
		nNextID = 0;
		strName = "";
		strValue = "";
	}
};

struct UG_DATASET_TIER_NAME
{
	UGString strDataset;
	int nTileID;
	UG_DATASET_TIER_NAME()
	{
		strDataset = "";
		nTileID    = -1;
	}
};

#endif // end declare ugc sdk
}
#endif
