#ifndef __KERNEL_MEMORY_H
#define __KERNEL_MEMORY_H
#include "stdint.h"
#include "bitmap.h"


/* 内存池标记,用于判断用哪个内存池 */
enum pool_flags {
   PF_KERNEL = 1,    // 内核内存池
   PF_USER = 2	     // 用户内存池
};

#define	 PG_P_1	  1	// 页表项或页目录项存在属性位
#define	 PG_P_0	  0	// 页表项或页目录项存在属性位
#define	 PG_RW_R  0	// R/W 属性位值, 读/执行
#define	 PG_RW_W  2	// R/W 属性位值, 读/写/执行
#define	 PG_US_S  0	// U/S 属性位值, 系统级
#define	 PG_US_U  4	// U/S 属性位值, 用户级

/* 用于虚拟地址管理 */
//用位图来记录虚拟地址的分配情况
//虚拟地址是绝对不能重复的
struct virtual_addr {
/* 虚拟地址用到的位图结构，用于记录哪些虚拟地址被占用了。以页为单位。*/
   struct bitmap virtual_addr_bitmap;
/* 管理的虚拟地址 */
   uint32_t virtual_addr_start;
};
void mem_init(void);

#endif