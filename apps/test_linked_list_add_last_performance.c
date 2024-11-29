#include "linked_list.h"
#include "mytime.h"

#include <stdio.h>

int main(void) {
    LinkedList *L_slow = LinkedList_create();
    timer _tic, _tac;

    _tic = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last_slow(L_slow, i);
    }
    _tac = tac();
    printf("Performance add_last_slow: %.2fms\n", comptime(_tic, _tac));
    
    LinkedList *L_fast = LinkedList_create();

    _tic = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last(L_fast, i);
    }
    _tac = tac();
    printf("Performance add_last: %.2fms\n", comptime(_tic, _tac));

    return 0;
}