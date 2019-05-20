/************************ (C) COPYLEFT 2018 Merafour *************************

* File Name          : mem_malloc.h
* Author             : Merafour
* Last Modified Date : 01/10/2019
* Description        : dynamic memory allocation library.
********************************************************************************
* https://merafour.blog.163.com
* merafour@163.com
* https://github.com/merafour
******************************************************************************/
#ifndef _MALLOC_H_
#define _MALLOC_H_

#ifdef __cplusplus
extern "C"
{
#endif
	
#include <stdint.h>
#ifndef NULL
#define NULL 0
#endif

/**
 * ���η�������ڴ�����
 * 8bit: 2^8-1=255; 16bit: 2^16-1=65535; 32bit: 2^32-1, MCUû����ô���ڴ�,���ø�����
 * ����: 8bit ��� 16bit �ڴ��ɽ�ʡһ��,���ڴ��������������� 255ʱ�ɽ�ʡ�ڴ�,����ڵ�Ƭ��������
 * �ڴ����������: size >> MEM_BLOCK_WIDTH
 * ͬʱ��Ҫע�� MEM_BLOCK_WIDTH Խ�󼴵����ڴ��Խ��(2^MEM_BLOCK_WIDTH), �ڶ�̬�ڴ����������˷�Խ��,
 * ��Ϊ������ÿ�ζ�����ĸոպ�, �����ڵ�Ƭ����Ϊ�˼����ڴ��˷��������Ҫ���������С�ڴ����� MAX_BLOCK_SIZE �� MEM_BLOCK_WIDTH.
 * ͬʱ����ͨ�� mem_perused �����۲��ڴ�ʹ��������������ֵ.
 */
#define MAX_BLOCK_SIZE_8bit     0x01
#define MAX_BLOCK_SIZE_16bit    0x02
#define MAX_BLOCK_SIZE_32bit    0x04
#define MAX_BLOCK_SIZE   MAX_BLOCK_SIZE_8bit   

/**
 * �ڴ����, �ڴ���С(2^MEM_BLOCK_WIDTH), ��λ�ֽ�.���ڼӿ��ڴ����ʱ�������ٶ�
 */
#define MEM_BLOCK_WIDTH			4                               
/**
 * �������ڴ� 2K
 */
#define MEM_MAX_SIZE			(2*1024)  						

extern uint8_t mem_perused(void);					            /* �ڴ�ʹ���� */
extern void  mem_free(void *ptr);  				                /* �ڴ��ͷ� */
extern void* mem_malloc(const uint32_t size);				    /* �ڴ���� */
extern void* mem_realloc(void *ptr, const uint32_t size);	    /* ���·����ڴ� */

#ifdef __cplusplus
}
#endif

#endif // _MALLOC_H_

