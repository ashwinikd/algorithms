/**
 * @file queue.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Implementation of queue
 */

#include <stdlib.h>
#include "queue.h"


/**
 * queue_init - initializes the queue with given capacity
 * the size is set to 0 and head is set to -1.
 */
void queue_init(IntegerQueue *queue, int capacity) {
    queue->capacity = capacity;
    queue->size = 0;
    queue->head = 0;
    queue->keys = malloc(sizeof(int) * capacity);
}

/**
 * queue_destroy - frees the memory consumed by the key store
 * of this queue. Resets the size and capacity to zero and sets
 * the head of queue to 0.
 */
void queue_destroy(IntegerQueue *queue) {
    queue->capacity = 0;
    queue->size = 0;
    queue->head = 0;
    free(queue->keys);
}

/**
 * queue_enqueue - tries to queue the key in the given queue. Returns
 * QUEUE_OPN_OK if successfull or QUEUE_OVERFLOW otherwise.
 */
int queue_enqueue(IntegerQueue *queue, int key) {
    if (queue->size >= queue->capacity) {
        return QUEUE_OVERFLOW;
    }
    int i = (queue->size + queue->head) % queue->capacity;
    queue->keys[i] = key;
    queue->size++;
    return QUEUE_OPN_OK;
}

/**
 * queue_dequeue - tries to dequeue and element from the head
 * of the queue and stores it in value. Returns QUEUE_OPN_OK
 * if successful or QUEUE_UNDERFLOW otherwise.
 */
int queue_dequeue(IntegerQueue *queue, int *value) {
    if (queue->size <= 0) {
        return QUEUE_UNDERFLOW;
    }
    *value = queue->keys[queue->head];
    queue->head++;
    queue->head = queue->head % queue->capacity;
    queue->size--;
    return QUEUE_OPN_OK;
}
