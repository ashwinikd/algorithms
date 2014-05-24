/**
 * @file stack.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Implementation of stack
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * stack_init - initializes the stack with given capacity.
 * This will empty the stack and reset the top to -1.
 */
void stack_init(IntegerStack *stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->keys = malloc(sizeof(int) * capacity);
}

/**
 * stack_destroy - frees all memory used by this stack and
 * sets the top pointer to -1.
 */
void stack_destroy(IntegerStack *stack) {
    stack->top = -1;
    stack->capacity = 0;
    free(stack->keys);
}

/**
 * stack_push - tries to push the key onto the stack. Returns
 * STACK_OPN_OK if successfull or STACK_OVERFLOW otherwise.
 */
int stack_push(IntegerStack *stack, int key) {
    if (stack->top >= stack->capacity - 1) {
        return STACK_OVERFLOW;
    }
    stack->top += 1;
    stack->keys[stack->top] = key;
    return STACK_OPN_OK;
}

/**
 * stack_pop - tries to pop the key from top of this stack and
 * puts it in value. Returns STACK_OPN_OK if successful or
 * STACK_UNDERFLOW otherwise
 */
int stack_pop(IntegerStack *stack, int *value) {
    if (stack->top < 0) {
        return STACK_UNDERFLOW;
    }
    printf("Stack element: %d\n", stack->keys[stack->top]);
    *value = stack->keys[stack->top];
    stack->top--;
    return STACK_OPN_OK;
}
