#ifndef LINKED_LIST_H
#define LIKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_create();
void LinkedList_destroy(LinkedList **L_ref);
int LinkedList_isEmpty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);

// Remove o primeiro nó encontrado
// que possua o valor val
void LinkedList_remove_v1(LinkedList *L, int val);
void LinkedList_remove(LinkedList *L, int val);
void LinkedList_remove_all(LinkedList *L, int val);

#endif  