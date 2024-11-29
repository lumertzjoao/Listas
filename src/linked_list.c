#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode 
{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list 
{
    SNode *begin;
    SNode *end;
} LinkedList;
 
SNode *SNode_create(int val) {
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode -> val = val;
    snode -> next = NULL;

    return snode;
}

LinkedList *LinkedList_create()
{
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L -> begin = NULL;
    L -> end = NULL;

    return L;
}

void LinkedList_destroy(LinkedList **L_ref) {
    puts("LinkedList_destroy");
    LinkedList *L = *L_ref;

    SNode *p = L -> begin;
    SNode *aux = NULL;

    while(p != NULL) {
        aux = p;
        p = p -> next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

int LinkedList_isEmpty(const LinkedList *L) {
    return (L -> begin == NULL && L -> end == NULL);
}

// void LinkedList_add_first(LinkedList *L, int val) {
//     SNode *p = SNode_create(val);
//     p -> next = L -> begin;
//     L -> begin = p;
// }

void LinkedList_add_first(LinkedList *L, int val) {
    SNode *p = SNode_create(val);
    p -> next = L -> begin;
    
    if (LinkedList_isEmpty(L)) L -> end = p;

    L -> begin = p;

    printf("L -> end: %d\n", L -> end -> val);
}

void LinkedList_add_last_slow(LinkedList *L, int val) {
    SNode *q = SNode_create(val);
    if (!LinkedList_isEmpty(L)) {
        SNode *p = L -> begin;
        while(p -> next != NULL) {
            p = p -> next;
        }
        p -> next = q;
    }
    else L -> begin = q; // Se a lista estiver vazia;
}

void LinkedList_add_last(LinkedList *L, int val) {
    SNode *q = SNode_create(val);
    if (!LinkedList_isEmpty(L)) {
        L -> end = L -> end -> next = q;
        // L -> end -> next = q;
        // L -> end = L -> end -> next;
    } else L -> begin = L -> end = q;
}

void LinkedList_print(const LinkedList *L) {
    SNode *p = L -> begin;

    printf("L -> ");

    while (p != NULL) {
        printf("%d -> ", p -> val);
        p = p -> next;
    }
    printf("NULL\n");

    if (L -> end == NULL) printf("L -> end = NULL\n");
    else printf("L -> end = %d\n", L -> end -> val);
    puts("");
}

void LinkedList_remove_v1(LinkedList *L, int val) {
    if (!LinkedList_isEmpty(L)) {
        // Caso 1 - o elemento está na cabeça da lista
        if (L -> begin -> val == val) {
            SNode *pos = L -> begin;

            // A lista possui apenas um nó
            // e este nó será removido
            if (L -> begin == L -> end) L -> end = NULL;

            L -> begin = pos -> next;
            free(pos);
        }
        // Caso 2 - o elemento está no meio da lista
        else {
            SNode *prev = L -> begin;
            SNode *pos = L -> begin -> next;

            while (pos != NULL && pos -> val != val) {
                prev = pos;
                pos = pos -> next;
            }

            // um nó de valor val foi encontrado e
            // é apontado pelo ponteiro pos
            if (pos != NULL) {
                prev -> next = pos -> next;

                // se o elemento a ser removido é
                // o último nó da lista
                //
                // Caso 3 - Removendo o último nó da lista
                if (pos -> next == NULL) L -> end = prev;
                free(pos);
            }
        }
    }
}

void LinkedList_remove(LinkedList *L, int val) {
    if (!LinkedList_isEmpty(L)) {
        SNode *prev = NULL;
        SNode *pos = L -> begin;

        while (pos != NULL && pos -> val != val) {
            prev = pos;
            pos = pos -> next;
        }
        
        if (pos != NULL) {
            if (L -> end == pos) L -> end = prev;
            if (L -> begin == pos) L -> begin = L -> begin -> next;
            else prev -> next = pos -> next;
         
            free(pos);
        }
    }
}

void LinkedList_remove_all(LinkedList *L, int val) {
    if (!LinkedList_isEmpty(L)) {
        SNode *pos = L -> begin;
        SNode *prev = NULL;

        while (pos != NULL) {
            if (pos -> val == val) {
                SNode *aux = pos;

                if (L -> end == pos) L -> end = prev;
                if (L -> begin == pos) L -> begin = pos -> next;
                else prev -> next = pos -> next;

                pos = pos -> next;

                free(aux);
            } else {
                prev = pos;
                pos = pos -> next;
            }
        }
    }
}