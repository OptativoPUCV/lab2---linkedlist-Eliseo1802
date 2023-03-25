#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List *createList(void) {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL)
    exit(EXIT_FAILURE);
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void *firstList(List *list) {
  if (list == NULL || list->head == NULL)
    return NULL;
  list->current = list->head;
  return list->current->data;
}

void * nextList(List * list) {
  if (list == NULL || list->current == NULL || list->current->next == NULL)
    return NULL;
  list->current = list->current->next;
  return list->current->data;
}

void *lastList(List *list) {
  if (list == NULL || list->tail == NULL)
    return NULL;
  list->current = list->tail;
  return list->current->data;
}

void *prevList(List *list) {
  if (list == NULL || list->current == NULL || list->current->prev == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
    exit(EXIT_FAILURE);
  node->data = data;
  node->prev = NULL;
  node->next = list->head;
  if (list->head == NULL)
    list->tail = node;
  else
    list->head->prev = node;
  list->head = node;
}

void pushBack(List *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for node.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}