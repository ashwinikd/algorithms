/**
 * @file list.c
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 25 May 2014
 *
 * Implementation of linked list
 */

#include <stdio.h>
#include "list.h"

void list_init(IntegerLinkedList *list) {
    list->head = NULL;
}

void list_insert(IntegerLinkedList *list, IntegerListNode *node) {
    node->next = list->head;
    node->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = node;
    }
    list->head = node;
}

void list_delete(IntegerLinkedList *list, IntegerListNode *node) {
    if (node->prev == NULL) {
        list->head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}

IntegerListNode* list_search(IntegerLinkedList *list, int key) {
    IntegerListNode *current = list->head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
