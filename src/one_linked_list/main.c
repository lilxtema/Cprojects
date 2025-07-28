#include <ranlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "OneLinkedList/OneLinkedList.h"
#include "test/test.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    printf("\033[2J\033[H");  // очистка экрана
    if (argc < 2) {
        test_init_and_push_front();
        test_insert_erase();
        sort_test();
        merge_test();
        reverse_test();
    } else {
        run_single_test(argv[1]);
    }

    return 0;
}
