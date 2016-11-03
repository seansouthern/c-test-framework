#ifndef TEST_COMMON_INC
#define TEST_COMMON_INC
#endif

#ifndef LINKEDLIST_INC
#include "linkedlist.h"
#endif


#include <stdio.h>


typedef enum TEST_RESULTS {
	PASSED = 0x01,
	FAILED = 0x02,
	COMPILE_ERR = 0x03
} resultcode_t;


void debug_log(resultcode_t TEST_STATE, char * details)
{
	char * test_state;
	switch(TEST_STATE){
		case PASSED:
			test_state = "passed";
			break;
		case FAILED:
			test_state = "FAILED";
			break;
	        case COMPILE_ERR:
			test_state = "FAILED - COMPILE ERR";
			break;
		default:
			test_state = "UNKNOWN TEST_STATE";
		};
	printf("Test %s : %s \n", test_state, details);
	
}


int add_test(LinkedList * test_list, void(*test_func)(void))
{
	list_insert_node(test_list, list_create_node(test_func));
	
	return 0;
}


int run_test( LinkedList * in_list, Node * in_node )
{
	void (*test_func)() = in_node->data;
	test_func();	
	return 0;
}


void run_all_tests( LinkedList * test_list)
{
	traverse(test_list, run_test);
}



int test_assert_pointer_equal(void * actual, void * expected, char * file)
{
	if(actual == expected){
		debug_log(PASSED, file);
		return PASSED;
	}
	else{
		debug_log(FAILED, file);
		return FAILED;
	}
}


int test_assert_pointer_not_equal(void * actual, void * undesired, char * file)
{
	if(actual == undesired){
		debug_log(FAILED, file);
		return FAILED;
	}
	else{
		debug_log(PASSED, file);
		return PASSED;
	}
}


int test_assert_int_equal(void * actual, void * expected, char * file)
{
	int int_actual = *(int*)actual;
	int int_expected = *(int*)expected;
	
	if(int_actual == int_expected){
		debug_log(PASSED, file);
		return PASSED;
	}
	else{
		debug_log(FAILED,file);
		return FAILED;
	}
}
int test_assert_int_not_equal(void * actual, void * expected, char * file)
{
	int int_actual = *(int*)actual;
	int int_expected = *(int*)expected;

	if(int_actual != int_expected){
		debug_log(PASSED, file);
		return PASSED;
	}
	else {
		debug_log(FAILED, file);
		return FAILED;
	}
}
