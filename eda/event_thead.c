#include "pt.h"
#include "event.h"
#include "event_behavior.h"

#include "queue.h"

void test_cb(void *arg, void *context)
{
    printf(" I'm cb ~");
}

/**
 * event manager entity.
 */
Event_manager_t EManager =
{
    .init      = eq_init,
    .del       = eq_del,
    .push      = eq_push,
    .pop       = eq_pop,
    .lookup    = eq_lookup,
    .iterator  = eq_iterator,
};

/**
 * cb manager entity.
 */
Cb_manager_t CBManager =
{
    .create     = eq_init,
    .destroy    = eq_del,
    .push       = eq_push,
    .pop        = eq_pop,
    .lookup     = eq_lookup,
    .iterator   = eq_iterator,
    .sort       = 0,
};

/**
 * event entity.
 */
Event_pair_t event1 =
{
    .type = emsg_no1,
    .event = {
        .cb_head = 0,
        .arg = 1,
        .context = 2,
        .des = "test notify message!"
    }
};

Cb_t cb1 = {
    .id = 3,
    .priority = 4,
    .func = test_cb,
};

int event_thread(struct pt *pt)
{
    PT_BEGIN(pt);

    event1.event.cb_head = CBManager.create();
    /* 回调函数注册 */
    CBManager.push(event1.event.cb_head, &cb1);

    /* event container pointer. */
    EventContainer event_queue = EManager.init();
    EManager.push(event_queue, &event1);

    printf(" event_queue address is %#x \n", event_queue);
    printf(" event1.event.head address is %#x \n", event1.event.cb_head);


    while(1)
    {
        Event_pair_t* ev = (Event_pair_t *)EManager.pop(event_queue);
        Cb_t* cbx = (Cb_t *)CBManager.pop(ev->event.cb_head);

        cbx->func(1,1);

        /* Wait until the other protothread has set its flag. */
        PT_WAIT_UNTIL(pt, 0 != 0);
        printf(" ==== \n");
    }

    PT_END(pt);
}

