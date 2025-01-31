#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _doubly_node 
{
    int val;
    struct _doubly_node *prev;
    struct _doubly_node *next;
} DoublyNode, Node;

typedef struct _doubly_linked_list
{
    Node *begin;
    Node *end;
    size_t size;
} DoublyLinkedList, List;

Node *Node_create(int val) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node -> prev = NULL;
    node -> next = NULL;
    node -> val = val;

    return node;
}

List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L -> begin = NULL;
    L -> end = NULL;
    L -> size = 0;

    return L;
}

void List_destroy(List **L_ref) {
    List *L = *L_ref;
    Node *p = L -> begin;

    while (p != NULL) {
        Node *aux = p;
        p = p->next;
        free(aux);
    }

    free(L);

    *L_ref = NULL;
}

int List_isEmpty(const List *L) {
    return L -> size == 0;
}

void List_add_first(List *L, int val) {
    Node *p = Node_create(val);
    p -> next = L -> begin;

    if (!List_isEmpty(L)) L -> begin -> prev = p;
    else L -> end = p;

    L -> begin = p;
    L -> size++;
}

void List_add_last(List *L, int val) {
    Node *p = Node_create(val);
    p -> prev = L -> end;

    if (!List_isEmpty(L)) L -> end -> next = p;
    else L -> begin = p;
    
    L -> end = p;
    L -> size++;
}

void List_print(const List *L) {
    Node *p = L -> begin;

    printf("L -> ");

    while (p != NULL) {
        printf("%d -> ", p -> val);
        p = p -> next;
    }
    printf("NULL\n");

    if (L -> end == NULL) printf("L -> end = NULL\n");
    else printf("L -> end = %d\n", L -> end -> val);

    printf("Size: %u\n", L -> size);
    puts("");
}

void List_inverted_print(const List *L) {
    Node *p = L -> end;

    printf("L -> end -> ");

    while (p != NULL) {
        printf("%d -> ", p -> val);
        p = p -> prev;
    }
    printf("NULL\n");

    if (L -> end == NULL) printf("L -> begin = NULL\n");
    else printf("L -> begin = %d\n", L -> begin -> val);

    printf("Size: %u\n", L -> size);
    puts("");
}

void List_remove(List *L, int val) {
    if (!List_isEmpty(L)) {
        Node *p = L->begin;

        // caso 1: o elemento está na cabeça da lista;
        if (L -> begin -> val == val) {
            L -> begin = p -> next;
            // A lista possui apenas um único elemento;
            if (p == L -> end) L -> end = NULL;
            else L -> begin -> prev = NULL;
            free(p);
            L -> size--;
        } 
        // Caso 2: O elemento está no meio da lista;
        // Caso 3: O elemento está no final da lista;
        else {
            p = p -> next;
            while (p != NULL) {
                if (p -> val == val) {
                    p -> prev -> next = p -> next;
                    // Caso 3
                    if (L -> end == p) L -> end = p -> prev;
                    // caso 2
                    else p -> next -> prev = p -> prev;

                    free(p);
                    p = NULL;
                    L -> size--;
                } else p = p -> next;
            }
        }
    }
}