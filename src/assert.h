#ifndef ASSERT_INC
#define ASSERT_INC


int test_assert_pointer_equal(void * actual, void * expected, char * file);
int test_assert_pointer_not_equal(void * actual, void * undesired, char * file);
int test_assert_int_equal(void * actual, void * expected, char * file);
int test_assert_int_not_equal(void * actual, void * expected, char * file);





#include "assert.c"

#endif // ASSERT_INC defined
