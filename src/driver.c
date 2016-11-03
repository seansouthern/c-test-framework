#ifndef SCANNED_TESTS_H
#include "scanned_tests.h"
#endif

#ifndef TEST_COMMON_INC
#include "test_common.h"
#endif



int main (int argc, char ** argv)
{
	char b = getchar();
        
	printf("Going to run all tests...\n");
	run_all_tests(initialize_generated_tests());
	printf("Finished running all tests!\n");

	char c = getchar();
	

	return 0;
}

