#define WORKER_INC
#ifndef TEST_COMMON_INC
#include "test_common.h"
#endif

typedef struct Result{
	resultcode_t result_code;
	char * test_name;
        
} result_t;



result_t * compile_test(char * source_name);
result_t * execute_test(char * bin_name);
