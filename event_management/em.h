#ifndef EM_H
#define EM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A event queue.
 */

typedef struct _Event Event;


/**
 * A null @ref EventValue.
 */

#define EVENT_NULL ((void *) 0)



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
