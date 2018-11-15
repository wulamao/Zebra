#include "em.h"
#include "em_interface.h"
#include "../lib/c-algorithms/src/queue.h"

EVENT_QUEUE_T* event_queue_create(void)
{
    return queue_new();
}


void* event_queue_pop(EVENT_QUEUE_T eq, unsigned int id)
{
    return queue_pop_head(eq);
}

unsigned int event_queue_push(EVENT_QUEUE_T eq,
        unsigned int type,
        unsigned int priority,
        void  *context,
        char  *str
        )
{
    Event_t* event = malloc(sizeof(Event_t));
    event->type = type;
    event->priority = priority;
    event->str = str;
    queue_push_head(eq, event);
}

unsigned int event_queue_lookup(EVENT_QUEUE_T eq, unsigned int id)
{
    ;
}

void* event_queue_sort(EVENT_QUEUE_T eq, unsigned int id)
{
    ;
}

unsigned int event_queue_traversal(EVENT_QUEUE_T eq)
{
    ;
}

