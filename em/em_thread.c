
#include "em_interface.h"
#include "em_behavior.h"

#include "../lib/pt-1.4/pt.h"

#include "stdio.h"
#include "em.h"

EM_INTERFACE_t em_entity =
{
    .init      = event_queue_create,
    .reg       = event_queue_push,
    .rm        = event_queue_pop,
    .lookup    = event_queue_lookup,
    .sort      = event_queue_sort,
    .traversal = event_queue_traversal,
}; /* 事件管理结构实体 */

EVENT_QUEUE_T* event_queue;

int
em_thread(struct pt *pt)
{
    PT_BEGIN(pt);

    event_queue = em_entity.init();
    printf(" ### %d\n",event_queue);
    event_queue_push(event_queue,1,1,0,"hhhha");
    event_queue_push(event_queue,2,1,0,"ssss");
    event_queue_push(event_queue,3,1,0,"123123");
    event_queue_push(event_queue,4,1,0,"hhhvzcvha");

    Event_t* e = (Event_t*)event_queue_pop(event_queue, 0);
    printf(" ### %s\n",e->str);
    while(1)
    {
        /* Wait until the other protothread has set its flag. */
        PT_WAIT_UNTIL(pt, 0 != 0);
        em_entity.traversal(event_queue);

    }

    PT_END(pt);
}

