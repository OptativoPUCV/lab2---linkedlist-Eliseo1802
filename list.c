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
  List *lista = (List *)malloc(sizeof(List));
  if (lista == NULL)
    exit(EXIT_FAILURE);
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}

void *firstList(List *lista) {
  if (lista == NULL || lista->head == NULL)
    return NULL;
  lista->current = lista->head;
  return lista->current->data;
}

void * nextList(List * lista) {
  if (lista == NULL || lista->current == NULL || lista->current->next == NULL)
    return NULL;
  lista->current = lista->current->next;
  return lista->current->data;
}

void *lastList(List *lista) {
  if (lista == NULL || lista->tail == NULL)
    return NULL;
  lista->current = lista->tail;
  return lista->current->data;
}

void *prevList(List *list) {
  if (list == NULL || list->current == NULL || list->current->prev == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for node.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->prev = NULL;
    node->next = list->head;
    if (list->head == NULL) {
        list->tail = node;
    } else {
        list->head->prev = node;
    }
    list->head = node;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
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