#include "test_common.h"
#include "result.h"


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

