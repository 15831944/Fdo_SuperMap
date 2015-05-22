#ifndef UGCOMPRESS_H
#define UGCOMPRESS_H
#include "ugdefs.h"

namespace UGC {

//! \brief ѹ���㷨�ࡣ
//! \remarks Ŀǰ���ṩZip��ѹ���ͽ�ѹ����
class BASE_API UGCompress  
{
public:
	//! \brief Zip ѹ������
	/** \details ����C++����淶,Ŀ�Ĳ�����ǰ,Դ�����ں�,�ʶ���Sm30�в�����λ�ú�����������Ӧ�ĸĶ�
	ѹ�����ݲ���˵��
	void *pvDestBuffer: Ŀ���ڴ����� ,dwDestLen: Ŀ���ڴ������С
	const void *pvSrcBuffer: Դ����; UGuint dwSrcLen:Դ���ݳ���
	
	  Ŀ���ڴ�������Ҫ���ȿ��٣�����Ҫ�� dwSrcLen * 1% + 12,	����ѹ����
	  �ڴ�Ĵ�С��ı䣬dwDestLen �����ı��Ĵ�С;
	  pvSrcBuffer��pvDestBuffer������ͬ
	  ����UGint nLevel ����ȡ1��9֮�������.
	  nLevelԽС��ѹ���������õ��ڴ����٣�����ѹ���ٶ�����ѹ���ʵ�;
	  nLevelԽ��ѹ���������õ��ڴ���࣬����ѹ���ٶȿ죬ѹ���ʸ�;
	  
		compress returns Z_OK if success, Z_MEM_ERROR if there was not enough
		memory, Z_BUF_ERROR if there was not enough room in the output buffer,
		Z_STREAM_ERROR if the level parameter is invalid.
		compress2 (dest, dwDesLen, source, dwDesLen, level)
	*/
	static UGbool Zip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen, UGint nLevel=8);
	
	//! \brief UnZip��ѹ������
	/** \details ����C++����淶,Ŀ�Ĳ�����ǰ,Դ�����ں�,�ʶ���Sm30�в�����λ�ú�����������Ӧ�ĸĶ�
	��ѹ�����ݲ���˵��
	void *pvDestBuffer: Ŀ���ڴ����� ,dwDestLen: Ŀ���ڴ������С
	const void *pvSrcBuffer: Դ����; UGuint dwSrcLen:Դ���ݳ���
	
	  Ŀ���ڴ�������Ҫ���ȿ��٣�����Ҫ�� dwSrcLen * 101% + 12,���н�ѹ����
	  �ڴ�Ĵ�С��ı䣬dwDestLen�����ı��Ĵ�С;
	  pvSrcBuffer��pvDestBuffer������ͬ
	  Decompress returns Z_OK if success, Z_MEM_ERROR if there was not
	  enough memory, Z_BUF_ERROR if there was not enough room in the output
	  buffer, or Z_DATA_ERROR if the input data was corrupted.
	*/
	static UGbool UnZip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen);

};

}

#endif

