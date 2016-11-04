#ifndef SUITE_INC
#define SUITE_INC

#include "../lib/linkedlist.h"
#include "test.h"


typedef struct Suite {

char * name;
LinkedList * tests;

} suite_t;


int add_test(suite_t in_suite, test_t in_test);
int remove_test(suite_t in_suite, test_t in_test);




#endif //SUITE_INC defined
