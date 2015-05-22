
/** \file	 SuperMapFilterStringBuffer.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#include "SuperMap.h"


#define D_FILTER_MEM_BLOCK_ALLOC_SIZE    256

SuperMapFilterStringBuffer::SuperMapFilterStringBuffer(void)
{
	m_pFilterText =  NULL;
	m_BuffSize = 0;
	m_FirstBuffIndex = 0;
	m_NextBuffIndex = 0;  
}

SuperMapFilterStringBuffer::~SuperMapFilterStringBuffer(void)
{
	if( m_pFilterText )
	{
        delete []m_pFilterText;
	}
}

void SuperMapFilterStringBuffer::ClearBuffer(void)
{
  if( m_pFilterText )
  {
    delete []m_pFilterText;
  }
        
  m_pFilterText =  NULL;
  m_BuffSize = 0;
  m_FirstBuffIndex = 0;
  m_NextBuffIndex = 0;          
}

const char* SuperMapFilterStringBuffer::GetString() 
{ 
  if( !m_pFilterText )
  {
	  return NULL;
  }
  
  return &m_pFilterText[m_FirstBuffIndex]; 
}


// ȷ�����������㹻�Ŀռ������Ҫ��ӵ��ַ���
void SuperMapFilterStringBuffer::ReallocBuffer( size_t  Size, bool bAtEnd )
{
    size_t extraSize;

    if( bAtEnd && (m_NextBuffIndex + Size) < m_BuffSize )
	{
        return;
	}

    if( !bAtEnd && Size < m_FirstBuffIndex )
	{
        return;
	}
    extraSize = Size * 2; // ����Ԥ������ԣ���������ÿ�ζ�Ҫ���øú���

    if( m_pFilterText == NULL )
    {
        m_BuffSize = ( extraSize < D_FILTER_MEM_BLOCK_ALLOC_SIZE )?D_FILTER_MEM_BLOCK_ALLOC_SIZE:extraSize;
        m_pFilterText = new char[m_BuffSize];
        if( m_pFilterText == NULL )
		{
			throw FdoException::Create (NlsMsgGet (SUPERMAP_OUT_OF_MEMORY_ERROR, "Memory Error"));
		}
        m_FirstBuffIndex = m_NextBuffIndex = m_BuffSize/2;
        m_pFilterText[m_NextBuffIndex] = '\0';
    }
    else
    {
        m_BuffSize += (( extraSize < D_FILTER_MEM_BLOCK_ALLOC_SIZE )?D_FILTER_MEM_BLOCK_ALLOC_SIZE:extraSize);
        char  *tmp = new char[m_BuffSize];
        if( tmp == NULL )
		{
            throw FdoException::Create (NlsMsgGet (SUPERMAP_OUT_OF_MEMORY_ERROR, "Memory Error"));
		}
        size_t currentSize = strlen( &m_pFilterText[m_FirstBuffIndex] );
        strncpy( &tmp[(m_BuffSize-currentSize)/2], &m_pFilterText[m_FirstBuffIndex], currentSize );
        m_FirstBuffIndex = (m_BuffSize-currentSize)/2;
        m_NextBuffIndex = m_FirstBuffIndex + currentSize;
        tmp[m_NextBuffIndex] = '\0';

        delete[] m_pFilterText;
        m_pFilterText = tmp;
    }
}

// �ӻ�������ĩβ����ַ���
void SuperMapFilterStringBuffer::AppendString(const char *Str)
{
  size_t slen = strlen( Str ); 
  ReallocBuffer( slen + 1, true );
  strcpy( &m_pFilterText[m_NextBuffIndex], Str );
  m_NextBuffIndex += slen;
}

// �ӻ�������ǰ������ַ���
void SuperMapFilterStringBuffer::PrependString(const char *Str)
{
  size_t slen = strlen( Str ); 
  ReallocBuffer( slen + 1, false );
  m_FirstBuffIndex -= slen;
  strncpy(&m_pFilterText[m_FirstBuffIndex], Str, slen );    
}