#include "linked_list.h"
#include "mytime.h"

#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("%s <Nº Elementos da lista>\n", argv[0]);
        exit(-1);
    }

    int n_elements = atoi(argv[1]);

    LinkedList *L = LinkedList_create();

    printf("n, time(ms)\n");

    for (int n = 0; n < n_elements; n++) {
        timer _tic = tic();
        LinkedList_add_last(L, n);
        timer _tac = tac();

        printf("%d, %fms\n", n, comptime(_tic, _tac));
    }
    
    return 0;
}