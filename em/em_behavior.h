


EVENT_QUEUE_T* event_queue_create(void);

void* event_queue_pop(EVENT_QUEUE_T eq, unsigned int id);

unsigned int event_queue_push(EVENT_QUEUE_T eq,
        unsigned int type,
        unsigned int priority,
        void  *context,
        char  *str
        );

unsigned int event_queue_lookup(EVENT_QUEUE_T eq, unsigned int id);

void* event_queue_sort(EVENT_QUEUE_T eq, unsigned int id);

unsigned int event_queue_traversal(EVENT_QUEUE_T eq);
