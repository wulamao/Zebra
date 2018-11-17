#ifndef EM_H
#define EM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Event_t
{
    /* 事件类型 */
    unsigned int type;
    /* 事件序号 */
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

typedef struct _Event_t Event_t;
typedef void *Event;

/**
 * Add a event to the head of a queue.
 *
 * @param queue      The queue.
 * @param data       The value to add.
 * @return           Non-zero if the value was added successfully, or zero
 *                   if it was not possible to allocate the memory for the
 *                   new entry.
 */




#ifdef __cplusplus
}
#endif

#endif /* #ifndef EM_H */
