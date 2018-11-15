#include "em.h"
#include "em_behavior.h"

typedef struct _Event_t
{
    /* 事件类型 */
    unsigned int id;
    /* 事件优先序号 */
    unsigned int priority;
    /* 回调函数结构 */
    void  **cache_addr;
    /* 传递参数 */
    void  *arg;
    /* 暂时保留 */
    void  *context;
    /* 相关描述 */
    char  *str;
} Event_t; /*事件节点结构定义*/


typedef struct _Event_management_t
{
    /* 事件管理结构初始化 */
    void  *init;
    /* 事件注册 */
    void  *reg;
    /* 事件移除 */
    void  *rm;
    /* 事件查找 */
    void  *lookup;
    /* 事件队列排序 */
    void  *sort;
    /* 事件队列遍历 */
    void  *traversal;
} Event_management_t; /* 事件管理接口结构体 */


Event_management_t MCU_EM =
{
    .init      = ((void *) event_queue_create),
    .reg       = ((void *) event_queue_push),
    .rm        = ((void *) event_queue_pop),
    .lookup    = ((void *) event_queue_lookup),
    .sort      = ((void *) event_queue_sort),
    .traversal = ((void *) event_queue_traversal),
} /* 事件管理结构实体 */
