#include <stdio.h>
#include "worker.h"

int main(int argc, char ** argv)
{

	test_t test1 = test_constructor("name", "path", time(NULL));
	test_t test2 = test_constructor("name2", "path2", time(NULL));
       	test_t test3 = test_constructor("name3", "path3", time(NULL));
	
	printf("Running test workers...\n");
	run_test(test1);
	run_test(test2);
	run_test(test3);
        
	printf("Finished!\n");

	return 0;
}
