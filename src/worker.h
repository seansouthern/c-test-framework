#ifndef WORKER_INC
#define WORKER_INC

#include "test.h"
#include "result.h"



result_t * compile_test(test_t in_test, char * source_name);
result_t * execute_test(test_t in_test, char * bin_path);



#include "worker.c"

#endif // WORKER_INC defined
