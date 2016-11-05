#include <stdio.h>
#include "worker.h"

int main(int argc, char ** argv)
{

	test_t test1 = test_constructor("Application init", "./tests/test_application_init.c", time(NULL));
	test_t test2 = test_constructor("Board create card", "./tests/test_board_create_card.c", time(NULL));
       	test_t test3 = test_constructor("Project create board", "./tests/test_project_create_board.c", time(NULL));
	
	printf("Running test workers...\n");
	run_test(test1);
	run_test(test2);
	run_test(test3);
        
	printf("Finished!\n");

	return 0;
}
