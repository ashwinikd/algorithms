/**
 * @file list.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 25 May 2014
 *
 * Implementation of linked list
 */

#ifndef algo_list_h
#define algo_list_h

typedef struct IntegerListNode {
    int key;
    struct IntegerListNode *next;
    struct IntegerListNode *prev;
} IntegerListNode;

typedef struct {
    IntegerListNode *head;
} IntegerLinkedList;

void list_init(IntegerLinkedList *list);

void list_insert(IntegerLinkedList *list, IntegerListNode *node);

void list_delete(IntegerLinkedList *list, IntegerListNode *node);

IntegerListNode* list_search(IntegerLinkedList *list, int key);

#endif
