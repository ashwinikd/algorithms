/**
 * @file stack.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Implementation of stack
 */

#ifndef __AKD_ALGO_STACK_H__
#define __AKD_ALGO_STACK_H__

#define STACK_OPN_OK 0
#define STACK_UNDERFLOW 1
#define STACK_OVERFLOW 2

/**
 * Stack - data structure for stack.
 */
typedef struct {
    int *keys;     // store for keys
    int top;       // current stack top
    int capacity;  // capacity of stack
} IntegerStack;

/**
 * stack_init - initializes the stack with given capacity.
 * This will empty the stack and reset the top to -1.
 */
void stack_init(IntegerStack *stack, int capacity);

/**
 * stack_destroy - frees all memory used by this stack and
 * sets the top pointer to -1 and capacity to 0.
 */
void stack_destroy(IntegerStack *stack);

/**
 * stack_push - tries to push the key onto the stack. Returns
 * STACK_OPN_OK if successfull or STACK_OVERFLOW otherwise.
 */
int stack_push(IntegerStack *stack, int key);

/**
 * stack_pop - tries to pop the key from top of this stack and
 * puts it in value. Returns STACK_OPN_OK if successful or 
 * STACK_UNDERFLOW otherwise
 */
int stack_pop(IntegerStack *stack, int *value);

#endif
