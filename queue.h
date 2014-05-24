/**
 * @file queue.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Implementation of queue
 */

#ifndef __AKD_ALGO_QUEUE_H__
#define __AKD_ALGO_QUEUE_H__

#define QUEUE_OPN_OK 0
#define QUEUE_UNDERFLOW 1
#define QUEUE_OVERFLOW 2

/**
 * IntegerQueue - queue data structure
 */
typedef struct {
    int *keys;    // key store of this queue
    int size;     // number of elements stored
    int head;     // head of the queue
    int capacity; // capacity of the queue
} IntegerQueue;

/**
 * queue_init - initializes the queue with given capacity
 * the size is set to 0 and head is set to 0.
 */
void queue_init(IntegerQueue *queue, int capacity);

/**
 * queue_destroy - frees the memory consumed by the key store
 * of this queue. Resets the size and capacity to 0 and sets
 * the head of queue to 0.
 */
void queue_destroy(IntegerQueue *queue);

/**
 * queue_enqueue - tries to queue the key in the given queue. Returns
 * QUEUE_OPN_OK if successfull or QUEUE_OVERFLOW otherwise.
 */
int queue_enqueue(IntegerQueue *queue, int key);

/**
 * queue_dequeue - tries to dequeue and element from the head
 * of the queue and stores it in value. Returns QUEUE_OPN_OK
 * if successful or QUEUE_UNDERFLOW otherwise.
 */
int queue_dequeue(IntegerQueue *queue, int *value);

#endif
