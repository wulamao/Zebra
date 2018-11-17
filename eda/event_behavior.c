
#include "event.h"
#include "queue.h"

/* create event container */
void* eq_init(void)
{
    return queue_new();
}

/* delete event container */
void eq_del(void* c)
{
    queue_free((Queue *)c);
}
/* cb register*/
void* event_reg(void* c, Event_pair_t *ev)
{
    queue_push_head((Queue *)c, ev);
}

/* cb remove*/
void* event_rm(void* c, Event_pair_t *ev)
{
    return queue_pop_head((Queue *)c);
}
/* event lookup*/
void* event_lookup(void* c, unsigned int method)
{
    return 0;
}
/* event traversal*/
void* event_traversal(void* c)
{
    return 0;
}

