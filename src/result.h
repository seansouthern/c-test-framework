#ifndef RESULT_INC
#define RESULT_INC

#include <time.h>

typedef enum TEST_RESULTS {
	PASSED = 0x01,
	FAILED = 0x02,
	COMPILE_ERR = 0x03,
	RUNTIME_ERR = 0x04
} resultcode_t;

typedef struct Result{
	resultcode_t RESULT_CODE;
	time_t last_time_ran;
} result_t;











#endif // RESULT_INC defined
