

/* create event container */
extern void* eq_init(void);
/* delete event container */
extern void eq_del(void *c);
/* cb register*/
extern void* event_reg(void *c, Event_pair_t *ev);
/* cb remove*/
extern void* event_rm(void *c, Event_pair_t *ev);
/* event lookup*/
extern void* event_lookup(void *c, unsigned int method);
/* event traversal*/
extern void* event_traversal(void *c);

