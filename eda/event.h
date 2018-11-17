

/**
 * define container structure.
 */
typedef struct _Container_t
{
    /* max size */
    unsigned int max_size;
    /* size */
    unsigned int size;

    /* create container */
    void (*create)(void);
    /* delete container */
    void (*destroy)(void* c);
    /* cb register */
    void* (*add)(void* c, void* data);
    /* remove*/
    void* (*rm)(void* c, void* data);
    /* lookup */
    void* (*lookup)(void* c, unsigned int method);
    /* event traversal */
    void* (*traversal)(void* c);
    /* sort */
    void (*sort)(void* c);
} Container_t;


/**
 * define event container structure.
 */
typedef void *EventContainer;

/**
 * define event message type.
 */
typedef enum {
    emsg_no1,
    EMSG_MAX
} Event_message_t;

/**
 * define callback function structure.
 */
typedef struct _Cb_t
{
    /* id */
    unsigned int id;
    /* priority */
    unsigned int priority;
    /* callback function pointer */
    void* (*func)(void *arg, void *context);
} Cb_t;

/**
 * define event structure.
 */
typedef struct _Event_t
{
    /* the address of container where saves call back functions */
    void *cb_head;
    /* pass parameter */
    void *arg;
    /* context */
    void *context;
    /* describe string */
    char *des;
} Event_t;

/**
 * define event pair structure.
 */
typedef struct _Event_pair_t
{
    /* event message type */
    Event_message_t type;
    /* event */
    Event_t event;
} Event_pair_t;

/**
 * define event manager structure.
 */
typedef struct _Event_manager_t
{
    /* create event container */
    EventContainer (*init)(void);
    /* delete event container */
    void (*del)(EventContainer c);
    /* cb register*/
    void* (*reg)(EventContainer c, Cb_t *cb);
    /* cb remove*/
    void* (*rm)(EventContainer c, Cb_t *cb);
    /* event lookup*/
    void* (*lookup)(EventContainer c, unsigned int method);
    /* event traversal*/
    void* (*traversal)(EventContainer c);

} Event_manager_t;


