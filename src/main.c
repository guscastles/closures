#include <stdio.h>
#include <string.h>
#include "operation.h"

void some_fun() {
    size_r a = 1;
    printf("%d\n", a);
    List list;
    list.size = 10;
    char str[10];
    strncpy(str, "abcdefghijkl", list_size(list));
    printf("%d\n", list.size);
}

void additions() {
    printf("%d\n", iaddition(5, 6));
    printf("%f\n", faddition(5, 6.563356));
    printf("%ld\n", laddition(523552345, 67685558));
    printf("%14e\n", daddition(5.5, 6.5653636636363633));
}

void closure_it() {
    Closure *add10 = add(10);
    printf("%f\n", add10->call(add10, 5));
}

int change_list(int list[], int *x) {
    int *new_list = list;
    new_list[0] = 1;
    *x = 3;
    return list[0];
}

int main(void){
    int list[1] = {2};
    int x = 1;
    change_list(list, &x);
    printf("list: %d %d\n", list[0], x);
    some_fun();
    additions();
    closure_it();
    return 0;
}
