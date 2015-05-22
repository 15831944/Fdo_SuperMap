/**  \file UG3DWindowTypes.h
   \brief   �����봰�������������
   \auothor malq
   \attetion ���ǿ�ƽ̨����
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/

#ifndef UG3DWINDOWTYPES_H
#define  UG3DWINDOWTYPES_H

//! \brief ����window��������
#ifdef WIN32
#include <WINDOWS.H>

namespace UGC
{
	typedef HDC Display3D;                     //����window�豸���
	typedef HWND Window;                       //����window���ھ��
	typedef HGLRC GLContext;                   //����OpenGL�����ľ��
	typedef PIXELFORMATDESCRIPTOR VisualInfo;  //���ظ�ʽ����
	typedef HFONT Font3D;
}
#endif

//! \brief �����window����������
#ifndef WIN32
#include <X11/Xlib.h>
#include <GL/glx.h>  
namespace UGC
{
	typedef ::Display* Display3D;              //�����豸���
	typedef ::Window   Window;                 //���崰�ھ��
	typedef GLXContext GLContext;              //����OpenGL�����ľ��
	typedef XVisualInfo* VisualInfo;           //����������ʽ
}
#endif

#endif
