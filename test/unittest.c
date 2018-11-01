#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "operation.h"

#define SIZE(v) (sizeof(v) / sizeof(v[0]))

struct Test {
   char name[40];
   void (*func)(void);
};

void test_some_fun() {
    size_r a = 1;
    printf("%d\n", a);
    List list;
    list.size = 10;
    char str[10];
    strncpy(str, "abcdefghijkl", list_size(list));
    printf("%d\n", list.size);
}

void test_additions() {
    printf("%d\n", iaddition(5, 6));
    printf("%f\n", faddition(5, 6.563356));
    printf("%ld\n", laddition(523552345, 67685558));
    printf("%14e\n", daddition(5.5, 6.5653636636363633));
}

void test_closure_it() {
    Closure *add10 = add(10);
    printf("%f\n", add10->call(add10, 5));
}

int change_list(int list[], int *x) {
    int *new_list = list;
    new_list[0] = 1;
    *x = 3;
    return list[0];
}

void test_change_list() {
    int list[1] = {2};
    int x = 1;
    change_list(list, &x);
    printf("list: %d %d\n", list[0], x);
}

void add_tests(CU_pSuite suite, struct Test *tests, int size, int next) {
   if (next < size) {
       CU_add_test(suite, tests[next].name, tests[next].func);
       add_tests(suite, tests, size, next + 1);
   }
}

void run(struct Test *tests, int size){
   CU_initialize_registry();
   CU_pSuite suite = CU_add_suite("closure_test", 0, 0);
   add_tests(suite, tests, size, 0);
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
}

void gather_tests(void (*runme)()) {
   const char *names[] = {"test_some_fun", "test_additions", "test_closure_it", "test_change_list"};
   void *functions[] = {test_some_fun, test_additions, test_closure_it, test_change_list};
   int size = SIZE(names);
   struct Test tests[size];
   for (int i = 0; i < size; ++i) {
      strncpy(tests[i].name, names[i], SIZE(names[i]));
      tests[i].func = functions[i];
   }
   runme(tests, SIZE(tests));
}

int main(void) {
   gather_tests(run);

   return 0;
}

