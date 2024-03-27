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
/*Programe la función `List* createList()`, la cual retorna el puntero del tipo de dato `List` con sus valores inicializados en NULL.*/
List * createList() {
  List* lista = (List*) malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}
/*La primera retorna el dato del primer nodo de la lista (`head`) y actualiza el current para que apunte a ese nodo. */
void * firstList(List * list) {
  if(!list->head) return NULL;
  list->current = list->head;
  return(list->head->data);
}

/*La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.*/
void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL)
    
    return NULL;
  list->current = list->current->next;
  return list->current->data;
}

/*La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. */
void * lastList(List * list) {
  if(!list->tail) return NULL;
  list->current = list->tail;
  return(list->tail->data);
}

/*La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.*/
void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

/*Programe la función `void pushFront(List * list, void * data)`, la cual agrega un dato al comienzo de la lista. 
  > Puede utilizar la función `Node* createNode(void * data)` la cual crea, incializa y retorna un nodo con el dato correspondiente. */
void pushFront(List * list, void * data) {
  Node* nuevo = createNode(data);
  if(!list->head){
    list->head = nuevo;
    list->tail = nuevo;
  }
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