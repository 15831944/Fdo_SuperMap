#include "NetworkAnalyst/UGSection.h"
#include "Engine/UGDatasetVector.h"
#include "Base/ugdefs.h"
#include "Geometry/UGGeoLineM.h"

#ifndef UGROUTE_H
#define UGROUTE_H

namespace UGC {

typedef struct tagIndexTemp
{
	UGint nID;
	UGint nIndex;
}NetIndexTemp;

class NETWORKANALYST_API UGRoute 
{
public:
	/*! \brief ȱʡ���캯��
	*/
	UGRoute();
	/*! \brief ʹ�������������ݣ��ߣ����磬�̶��ߣ�������Route
	*	\param pLinearDt �������ݼ�ָ�룻Route�ĸ��ּ��㶼������������ݼ�������
	
	*  \remarks
	*/
	UGRoute(UGDatasetVector* pLinearDt);
	
	/*! \brief �������캯��
	*	\param Route	һ���Ѵ��ڵ�Route���������ݱ����Ƶ�UGRoute��

	*  \remarks
	*/
	UGRoute(const UGRoute& Route);
	
	/*! \brief  ���ظ�ֵ������
	*	\param Route һ���Ѵ��ڵ�Route���������ݱ����Ƶ�UGRoute��

	*  \remarks Route���
	*/
	UGRoute& operator=(const UGRoute& Route);

	/*! \brief ���صȺŲ�����
	*	\param Route һ���Ѵ��ڵ�Route���󣬰�����UGRoute���бȽ��Ƿ����

	*  \remarks Route��ȵ������� \n
		1 RouteID��ͬ \n
		2 ÿһ��Section����ͬ \n
		3 ����Ӧ���������ݼ�ָ����ͬ \n

        m_GeoLineM��Ӱ��Route�������
	*/
	UGbool operator==(const UGRoute& Route)const;	

	/*! \brief ���ز��ȺŲ�����
	*	\param Route ������UGRoute���бȽ��Ƿ����

	*  \remarks �ж�������==������һ��
	*/
	UGbool operator!=(const UGRoute& Route)const;

	/*! \brief ��������
	*	\param 
	
	*  \remarks
	*/
	~UGRoute();

public:
	enum RouteCoordPri
	{
		ArcOder    = 0,  //�������ݴ洢˳��
		UpperLeft  = 1,  //
		UpperRight = 2,
		LowerLeft  = 3,
		LowerRight = 4,
		ExistedPoint=5   //��һ��ָ���������      
	};
	/*!	\brief	����һ��Section \n
	 *	\param sectionNew     ��Section       
	
	 *	\return	�����¼ӵ�Section������

	 *  \remarks	 
	*/
	
	UGint Add(const UGSection& sectionNew);

	void SetSectionSize(UGint nSectoinSize);
	
	/*!	\brief	ɾ��һ��Section \n
	 *	\param nIndex     Section����

	 *  \remarks	 
	*/
	void RemoveSectionAt(UGint nIndex);

	/*!	\brief	ɾ������Section \n
	 *  \remarks	 
	*/
	void RemoveAllSection();

	/*!	\brief	�õ�ָ��������Section \n
	 *	\param nIndex     Section����
	 *	\return	����Section
	 *  \remarks	 
	*/
	UGSection GetSectionAt(UGint nIndex)const;

	/*!	\brief	�õ�ָ��������Section������ \n
	 *	\param nIndex     Section����
	 *	\return	����Section������
	 *  \remarks	 
	*/
	UGSection& GetElementAt(UGint nIndex);

	/*!	\brief	����ָ��������Section \n
	 *	\param nIndex     Section����
	 *  \param Section    Ҫ����Route����Section
	 
	 *  \remarks	 
	*/
	UGbool SetSectionAt(UGint nIndex, UGSection& Sectoin);
	
	/*!	\brief	�õ���ǰRoute��Section��Ŀ \n
	 *	\return	����Section������
	 *  \remarks	 
	*/
	UGint GetSectionCount();

public:
	/*!	\brief	�õ�ָ��������Section \n
	 *	\return	����Route��ID 

	 *  \remarks	 
	*/
    UGint GetRouteID();
	
	
	/*!	\brief	����Route��Ӧ�����������ݼ� \n
	 *	\param	pLinearDt �������ݼ���һ�������磩

	 *  \remarks	 
	*/
	void SetLinearDataset(UGDatasetVector* pLinearDt);
public:

	/*!	\brief	��һ��Section����һ���̶��߶���
	 *	\param	rcpRoutePri		ȷ������Sections�����ȷ���ȱʡΪUpperLeft
	 
	 *  \param  strFieldMeasure �������ݼ��д洢Measureֵ���ֶ�.�������ΪEmpty,������
	                            ����section��m_dFromMeasure,m_dToMeasure�����߱�
	 *	\param  bIsSetBlank		����û��ָ��Measure�Ľڵ㣬�Ƿ�������̶�Ϊ�ա�
	                            ȱʡΪFALSE;Ҳ����˵���û��ָ��Measure,��������̶� 
	 *	\param 	dStartMeasure   ��ʼ�߱�
	 *	\param 	rcpRoutePri     ������ʼ�������˳��
	 *	\param 	bIsSetBlank	    �Ƿ��δָ���߱�Ŀ��Ƶ���߱�����Ϊ��
	 *	\param	bIsGapEnabled	�Ƿ�����·���м����ȱʡΪTRUE,���������м��
	 *	\param 	pPointRef		��rcpRoutePri = ExistedPoint������һ��ָ�������ʱ��ָ���������
	 *  \param  dTolerance		�߶�����.С�����޵��߶��Զ�����һ����

	 *  \return �����ɹ�����TRUE;���κδ����쳣����FALSE.
	 *  \remarks ������������õĸ�������ֵ�ᱻUGRoute��¼�������ٴε��ú���ʱ��ֻ����ò���������
	             GetGeoLineM���������ܹ��Զ������ϴ��趨�Ĳ������� 
	 */
	 UGbool GetGeoLineM(UGGeoLineM& geoLineM,
					 const UGString& strFieldMeasure,
					 UGdouble dStartMeasure = 0.0,
					 RouteCoordPri rcpRoutePri = ArcOder,
					 UGbool bIsSetBlank = FALSE,
					 UGbool bIsGapEnabled = TRUE,
					 UGPoint2D* pPointRef = NULL,
					 UGdouble dTolerance = EP);
	

	/*! \brief  ʹ��ȱʡ��������̶���
	 *	\return ���ؿ̶��ߵ�ָ��
	 *  \remarks
	 */
	UGbool GetGeoLineM(UGGeoLineM& geoLineM);

    /*  \brief  ��һ����¼������һ��LineM������һ���߰��ղ���Ҫ�����ʽ���һ��LineM
	 *	\param	pRecordset      �ߣ��������ݼ����Σ�LineM��¼��
	 *	\param	geoLineM        ������
	 *	\param	rcpRoutePri		ȷ������Sections�����ȷ���ȱʡΪUpperLeft
	 
	 *  \param  strFieldMeasure �������ݼ��д洢Measureֵ���ֶΡ��������Ϊempty�����ճ��������߱� 
	 *	\param  bIsSetBlank		����û��ָ��Measure�Ľڵ㣬�Ƿ�������̶�Ϊ�ա�
	                            ȱʡΪFALSE;Ҳ����˵���û��ָ��Measure,��������̶� 
	 *	\param 	dStartMeasure   ��ʼ�߱�
	 *	\param 	rcpRoutePri     ������ʼ�������˳��
	 *	\param 	bIsSetBlank	    �Ƿ��δָ���߱�Ŀ��Ƶ���߱�����Ϊ��
	 *	\param	bIsGapEnabled	�Ƿ�����·���м����ȱʡΪTRUE,���������м��
	 *	\param 	pPointRef		��rcpRoutePri = ExistedPoint������һ��ָ�������ʱ��ָ���������
	 *  \param  dTolerance		�߶�����.С�����޵��߶��Զ�����һ����

	 *  \return �����ɹ�����TRUE;���κδ����쳣����FALSE.
	 *  \remarks 
	*/
	UGbool GetGeoLineM(UGRecordset* pRecordset,
					 UGGeoLineM& geoLineM,	
					 const UGString& strFieldMeasure = (""),
					 UGdouble dStartMeasure = 0.0,
					 RouteCoordPri rcpRoutePri = ArcOder,
					 UGbool bIsSetBlank = FALSE,
					 UGbool bIsGapEnabled = TRUE,
					 UGPoint2D* pPointRef = NULL,
					 UGdouble dTolerance = EP);

	/*! \brief �ڲ�Measure
	 *  \param nFromIndex   ��ʼSection����
	 *  \param nToIndex     ��ֹSection����
	 *  \return 
	 *  \remark
	*/
    UGbool InerpolateMeasure(UGuint nFromIndex,UGuint nToIndex);  

	/*! \brief ����Measure
	 *  \param nExtropolateStyle   ���Ʒ�ʽ
	 *  \param nFromIndex   ��ʼSection����
	 *  \param nToIndex     ��ֹSection����
	 *  \return 
	 *  \remark
	*/
	//UGbool ExtrapolateMeasure(UGuint nFromIndex,UGuint nToIndex = 0,UGGeoLineM::SmHowToComputeMeasure nExtropolateStyle = UGGeoLineM::SmExtropolateBefore); 
	
	
	/*! \brief �̶�ƽ��
	 *  \param dOffset   ƽ����
	 *  \return 
	 *  \remark
	*/
	void OffsetMeasure(UGdouble dOffset);	  

	/*! \brief �Ӿ���õ��̶�
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGdouble GetMAtDistance(UGdouble dDistance );
	
	/*! \brief ���ݾ������ÿ̶�
	 *  \param 
	 *  \return
	 *  \remark
	*/
	void SetMAsDistance();  

	
	/*! \brief  �ӿ̶ȵõ�����
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGdouble GetDistanceAtM(UGdouble dMeasure);
	
	/*! \brief �ӿ̶ȵõ�����
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGPoint2D GetCoordinateAtM(UGdouble dMeasure);

	
	/*! \brief �ӿ̶ȵõ�����
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool GetSubCurveAtM(UGGeoLine& GeoLine,UGdouble dFromMeasure,UGdouble dToMeasure );  

	/*! \brief �����޿̶�λ�ô��Ŀ̶�ֵ
	 *  \param 
	 *  \return
	 *  \remark
	*/
	void CaculateNoM();     

	/*! \brief ��ָ��λ�ò���̶�ֵ
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool InsertMAtDistance(UGdouble dDistance,UGdouble dMeasure); 

	/*! \brief 	��ת�̶�
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool ReversMOrder();      

	/*! \brief ���ֶΡ����ȸ��¿̶�
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool UpdataBy();  

	/*! \brief ���ֶΡ��������±�ע�̶�
	 *  \param 
	 *  \return
	 *  \remark
	*/
	UGbool CalibrateBy();

	

//	ConvertToNetWork();

//	Calibrate();
//	Measure();
	
	
//	CreateFromNetWork();
	
	UGbool Split();

private:
	/*! \brief ���ݾ��������İٷֱȵõ��������
	 *	\param pLine  ��ָ�� ������һ���Ǽ��� ���򷵻ص�����Ϊ(0,0)
	 *  \param dPos   ���������İٷֱ�.��60,��ʾ�ٷ�֮60
	 *  \param pIndex �ߵ����ͽ����֮�䣬�����������һ���߿��Ƶ�������.
	 *  \return ���ؽ��������
	 *  \remark
	 */
	UGPoint2D GetXYAtPos(UGGeoLine* pLine, UGdouble dPos, UGint* pIndex  = NULL);

	/*! \brief �õ�����ĳ��������ļ��ζ���
	 *	\param arrGeometryID ���ζ����ID
	 *  \param arrGeometry   ���ζ���ָ�� 
	 *  \param pntRef        �ο���
	 *  \param bAscending    ���ζ�������Ͳο������ΪTRUE,�յ�Ͳο������ΪFALSE 
	 *  \return ���ؼ��ζ����������е�������
	 *  \remarks ����ֻ��������ζ���������յ㣬Ȼ�������Щ��Ͳο���ľ��������
	 */
	UGint GetNearestGeometry(const UGArray<UGint>& arrGeometryID, 
		                    const UGArray<UGGeometry*>& arrGeometry, 
							const UGPoint2D& pntRef,UGbool& bAscending);
	/*! \brief  ��һ��̶����о�ο�������Ķ���
	 *	\param arrPointsM  �̶�������
	 *  \param pntRef      �ο�������
	 *  \return  ��������Ŀ̶����������е�������
	 *  \remarks  ���ζ�������Ͳο���ľ������������Ϊ���ζ���Ͳο������
	 */
	UGint GetNearestGeometry(const UGArray<UGPoint3D*>& arrPointsM,
							const UGPoint2D& pntRef);

	/*! \brief  �������ȴ���õ���Ҫ�Ĳο���
	 *	\param  pRecordset ��¼��
	 *  \param  rcpPri     ���ȴ���
	 *  \return ���زο�������
	 *  \remarks ����pRecordset���ڵ����ݼ�����ο��㡣UpperLeft�������Ͻǣ���������
	            ���pRecordsetΪNULL,���m_pDtLinear����
	 */
    UGPoint2D GetRefPoint(UGRecordset* pRecordset,RouteCoordPri rcpPri);

	/*! \brief  ��һ����ͨ��(�����Ǹ�����)ת�ɿ̶���
	 *	\param  pGeoLine      ��ͨ��ָ��
	 *  \param  pPointM       ���ָ�롣Ӧ�ñ��������ͷ�
	 *  \param  nPointsMCount �̶��߿��Ƶ���Ŀ
	 *  \param  dStartMeasure ��ʼ�̶�
	 *  \param  dMeasure      �߿̶�ֵ
	 *  \param  bIsGapEnabled ������ж���Ӷ����Ƿ�������
	 *  \param  bAscending    �������������㣬ΪTRUE;���յ�����ΪFALSE
	 *  \param  dTolerance    ������������
	 *  \return ���ؿ̶��߿��Ƶ����Ŀ
	 *  \remarks ������ж���Ӷ������Ӷ��󲢲�����������ֻ������һ���򵥵Ŀ̶���
	            �������£�
	            1.���������(bIsGapEnabled == TRUE):��Ѱ���Щ�Ӷ������ӳ�һ���ߡ�
				  �����ϣ������Ч����Ӧ�ðѶ����ɢ�ɶ���򵥶���Ȼ����
                2.�����������(bIsGapEnabled != TRUE):ֻ����β�����Ķ�����룬
				  ���ڵ�һ��������� 
	 */
	UGint ConvertLineToM(UGGeoLine* pGeoLine, 
						UGPoint3D* pPointM,UGint nPointsMCount, 
						UGdouble dStartMeasure = 0.0,UGdouble dMeasure = -1.0,
						UGbool bIsGapEnabled = TRUE, UGbool bAscending = TRUE, 
						UGdouble dTolerance = EP);	
	
	/*! \brief  ����ľ����Ƿ���������
	 *	\param  pnt1
	 *  \param  pnt2
	 *	\param  dTolerance
	 *  \return 
	 *  \remarks             
	 */	
	UGbool IsPointsInTolerance(const UGPoint2D& pnt1,const UGPoint2D& pnt2,UGdouble dTolerance);

	/*! \brief  ��sectionת��һ��̶���
	 *	\param  arrPointsM  
	 *  \param  arrPointsMCount
	 *	\param  strFieldMeasure 
	 *	\param  dStartMeasure
	 *  \return 
	 *  \remarks ���strFieldMeasureΪ�գ���ʹ��section��FromM��ToM������Measure��
	            ���򣬸��������ݼ�strFieldMeasure�ֶκ�dStartMeasure������Measure��
	 */	
	UGbool SectionToPointsM(UGArray<UGPoint3D*>& arrPointsM,
						  UGArray<UGint>& arrPointsMCount,
						  const UGString& strFieldMeasure, 
						  UGdouble dStartMeasure = 0.0);
	
	UGString BuildQueryFilter(UGArray<UGuint> &arrKeys,const UGString strFieldName);
	
private:
	
	UGDatasetVector* m_pDtLinear;/// ���������ݼ�
	
	void q_Sort(UGSection *pData, UGint nCount);
	UGint FindIndex(UGint nArcID,UGSection* pSection,UGint nCount);

	UGint FindIndex(UGint nArcID,NetIndexTemp* pNetIndex,UGint nCount);
	

private:
	/*! \brief Section���� 
	 */
	UGArray<UGSection> m_Route; 
	
	/*! \brief Route ID
	*/
	UGint m_nRouteID;
	
	/*! \brief �̶��߶���
	*/
	UGGeoLineM m_GeoLineM;

	/*! \brief �Ƿ���Ҫ���¹����̶��ߡ���m_Route�����仯ʱΪ�档
	*/
	UGbool m_bIsNeedRebuild;

	/*! \brief �洢�̶���Ϣ���ֶ�
	*/
	UGString m_strFieldMeasure;

	/*! \brief ��ʼ�߱�
	*/
	UGdouble m_dStartMeasure;
	/*! \brief �����߶�ʱ�����ȴ���
	*/
    RouteCoordPri m_rcpRoutePri;

	/*! \brief ����û�п̶�ֵ�Ľڵ��Ƿ����ÿ̶�Ϊ��
	*/
    UGbool m_bIsSetBlank ;

	/*! \brief �Ƿ�����̶����м��
	*/
    UGbool m_bIsGapEnabled;

	/*! \brief �������ӵ����
	 *	
	 */
	UGPoint2D* m_pntRef; 
	
	/*! \brief �����߶ε����ޣ�����߶εļ��С�����ޣ�������һ����
	*/
    UGdouble m_dTolerance;
};

}

#endif
