#ifndef TEST_COMMON_INC
#define TEST_COMMON_INC

#include <stdio.h>
#include "result.h"


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

/*
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

*/

#endif // TEST_COMMON_INC defined
