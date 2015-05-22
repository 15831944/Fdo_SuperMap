#if !defined(UGTYPEDEF_H)
#define UGTYPEDEF_H

 namespace UGC
{
		//! ���ظ�ʽ
		enum PixelFormat {
			IPF_UNKNOWN			= 0,	//! ��δ�趨, �ڲ�ʹ��
				IPF_MONO			= 1,	//! 1λ,��ɫ
				IPF_FBIT			= 4,	//! 4λ,16ɫ
				IPF_BYTE			= 8,	//! 8λ,256ɫ
				IPF_TBYTE			= 16,	//! 16λ,��ɫ
				IPF_RGB				= 24,	//! 24λ,���ɫ
				IPF_RGBA			= 32,	//! 32λ,��ǿ���ɫ
				IPF_TRGB			= 48,	//! 48λ,���ɫ
				IPF_LONGLONG		= 64,	//! 64λ,������
				IPF_LONG			= 320,	//! LONG
				IPF_FLOAT			= 3200,	//! 32λ,������
				IPF_DOUBLE			= 6400	//! 64λ,˫���ȸ�����
		};

		//ɫ�ʿռ��ʽ����.
		typedef enum {
			ICS_RGB = 1,	//��ʾϵͳʹ��.
				ICS_CMY = 2,	//ӡˢϵͳʹ��(Cyan,Magenta,Yellow).
				ICS_YIQ = 4,	//��������ϵͳʹ��(NTSC,Y:Luminance,Chrominance).
				ICS_YUV = 8,	//ŷ�޵���ϵͳʹ��(PAL).
				ICS_YCC = 16	//��YUV����,JPEGʹ��.
		} ImgColorSpace;
		
		//���岻ͬ���ظ�ʽ��λ��.
#define IPF_MONO_BITS 1
#define IPF_FBIT_BITS 4
#define IPF_BYTE_BITS 8
#define IPF_TBYTE_BITS 16
#define IPF_RGB_BITS  24
#define IPF_RGBA_BITS 32
		
		//���岻ͬ���ظ�ʽ����ɫ��.
#define IPF_MONO_COLOR	0x00000001
#define IPF_FBIT_COLOR	0x0000000F
#define IPF_BYTE_COLOR	0x000000FF
#define IPF_TBYTE_COLOR 0x0000FFFF
#define IPF_RGB_COLOR	0x00FFFFFF
#define IPF_RGBA_COLOR	0xFFFFFFFF

		///////////////////////////////////////////////////////////////////////
		//�õ���ByteΪ��λ��DWORD����Ŀ��.
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 
#define WIDTHBYTESBYTE(bits)    (((bits) + 7) / 8 )  
#define WIDTHBYTESWORD(bits)    (((bits) + 15) / 16 * 2)  

}

#endif //UGTYPEDEF_H
