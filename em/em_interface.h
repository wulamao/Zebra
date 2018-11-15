#include "../lib/c-algorithms/src/queue.h"

/**
 * A null @ref EventValue.
 */

#define EVENT_NULL ((void *) 0)

/**
 * 数据结构接口.
 */

#define EVENT_QUEUE_T Queue *

/**
 *
 */

//

/* 接口类型定义 */
typedef EVENT_QUEUE_T* (*em_create_func_t)(void);
typedef unsigned int (*em_register_func_t)(EVENT_QUEUE_T eq,
        unsigned int type,
        unsigned int priority,
        void  *context,
        char  *str
        );
typedef void* (*em_remove_func_t)(EVENT_QUEUE_T eq, unsigned int id);
typedef void* (*em_lookup_func_t)(EVENT_QUEUE_T eq, unsigned int id);
typedef unsigned int (*em_sort_func_t)(EVENT_QUEUE_T eq, unsigned int direction);
typedef unsigned int (*em_traversal_func_t)(EVENT_QUEUE_T eq);

typedef struct _EM_INTERFACE_t
{
    /* 事件管理结构初始化 */
    em_create_func_t     init;
    /* 事件注册 */
    em_register_func_t   reg;
    /* 事件移除 */
    em_remove_func_t     rm;
    /* 事件查找 */
    em_lookup_func_t     lookup;
    /* 事件队列排序 */
    em_sort_func_t       sort;
    /* 事件队列遍历 */
    em_traversal_func_t  traversal;
} EM_INTERFACE_t; /* 事件管理接口结构体 */
