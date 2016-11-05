#ifndef TEST_INC
#define TEST_INC


#include <time.h>
#include "result.h"

typedef struct Test {

	char * name;
	char * path;
	time_t last_time_ran;

} test_t;


test_t test_constructor(char * name, char * path, time_t last_time_ran);
result_t dispatch_worker(test_t in_test);




#include "test.c"

#endif // TEST_INC defined

