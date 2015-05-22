/* 
	\file UGAngle.h
	\brief �Ƕ��ࡣ
	\author malq,zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_)
#define AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC 
{

//! \brief �Ƕ��ࡣ
class SCENE_API UGAngle  
{

public:
	
	//! \brief ���캯����
	UGAngle();	
	
	//! \brief ����������
	virtual ~UGAngle();	

	//! \brief ���ظ�ֵ���㡣
	//! \param value �Ƕȶ���
	void operator =(UGAngle value);
	
	//! \brief ���ظ�ֵ���㡣
	//! \param value ����
	void operator =(UGdouble value);
	
	//! \brief ���ص������㡣
	//! \param obj �Ⱥ��ұ߽Ƕȶ���[in]��
	//! \return trueΪ��ȣ�falseΪ����ȡ�
	UGbool operator ==(const UGAngle& obj)const;	
	
	//! \brief ���ز�������㡣
	//! \param obj ���Ⱥ��ұ߽Ƕȶ���[in]��
	//! \return trueΪ��ȣ�falseΪ����ȡ�
	UGbool operator !=(const UGAngle& obj)const;	
	
	//! \brief ����С�����㡣
	//! \param obj С�ں��ұ߽Ƕȶ���[in]��
	//! \return trueΪС�ڣ�falseΪ��С�ڡ�	
	UGbool operator <(const UGAngle& obj)const;

	//! \brief ���ش������㡣
	//! \param obj ���ڷ����ұ߽Ƕȶ���[in]��
	//! \return trueΪ���ڣ�falseΪ�����ڡ�
	UGbool operator >(const UGAngle& obj)const;	

	//! \brief ����������㡣
	//! \param obj �Ӻ��ұ߽Ƕȶ���[in]��
	//! \return ��Ӻ�Ƕȶ���
	UGAngle operator +(const UGAngle& obj)const;	
	
	//! \brief ���ؼӵ����㡣
	//! \param obj �ӵȺ��ұ߽Ƕȶ���[in]��
	void operator +=(const UGAngle& obj);  	
	
	//! \brief ���ؼ������㡣
	//! \param obj �����ұ߽Ƕȶ���[in]��
	//! \return �����Ƕȶ���
	UGAngle operator -(const UGAngle& obj)const;	
	
	//! \brief ���س˷����㡣
	//! \param dTimes ����[in]��
	//! \return ��˺�Ƕȶ���
	UGAngle operator *(UGReal  dTimes)const;
	
	//! \brief ���س������㡣
	//! \param dDivisor ����[in]��
	//! \return �����Ƕȶ���
	UGAngle operator /(UGReal  dDivisor)const;	

	//! \brief ��ȡ�Ƕȡ�
	//! \return �Ƕȡ�
	UGReal GetDegrees() const;	
	
	//! \brief ���û��ȡ�
	//! \param dRadian ����[in]��
	void SetRadian(UGReal dRadian);	
	
	//! \brief ��ȡ���ȡ�
	//! \return ���ȡ�
	UGReal GetRadian() const;	
	
	//! \brief ����ת���ɽǶȶ���
	//! \param dRadians ����[in]��
	//! \return �Ƕȶ���
	static UGAngle FromRadians(UGReal dRadians);	
	
	//! \brief �Ƕ�ת���ɽǶȶ���
	//! \param dDegrees �Ƕ�[in]��
	//! \return �Ƕȶ���
	static UGAngle FromDegrees(UGReal dDegrees);	
	
	//! \brief �ж��Ƿ�Ϊ�Ϸ�ʵ����
	//! \return trueΪ�Ϸ���falseΪ�Ƿ���
	UGbool IsNaN()const;	
	
	//! \brief ����ת����-PI��PI��Χ��
	void NormalizeLon();
	//! \brief ����ת����-PI��PI��Χ��
	void NormalizeLat();
	//! \brief ����ת����0��2*PI��Χ��
	void Normalize();

	//! \biref ���ð뾶��������
	void SetRadianRatio(UGdouble ratio);

	//! \brief �㳣����
	const static UGAngle ZERO;

	//! \brief �Ƿ�������
	const static UGAngle NaN;

private:
	
	//! \brief ���ȡ�
	UGReal m_dRadian;
};

}
#endif // !defined(AFX_UGANGLE_H__5C430A40_48C7_4E22_8AF1_2860A95001EF__INCLUDED_)
