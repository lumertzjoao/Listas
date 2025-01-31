#ifndef LIST_H
#define LIST_H

typedef struct _doubly_node DoublyNode, Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

Node *Node_create(int val);

List *List_create();
void List_destroy(List **L_ref);
int List_isEmpty(const List *L);
void List_add_first(List *L, int val);
void List_add_last(List *L, int val);
void List_print(const List *L);
void List_inverted_print(const List *L);

void List_remove(List *L, int val);

#endif