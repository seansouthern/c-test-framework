#ifndef WORKER_INC
#define WORKER_INC

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include "test.h"
#include "result.h"
#include "test_common.h"


result_t * run_test(test_t in_test);
result_t * compile_test(test_t in_test);
result_t * execute_test(test_t in_test);


result_t * run_test(test_t in_test)
{
	int pipe_fd[2];
	pid_t compiler_pid;
	pid_t execute_pid;
	result_t * compile_result = calloc(1, sizeof(result_t));
	result_t * execute_result = calloc(1, sizeof(result_t));
	result_t * end_result = calloc(1, sizeof(result_t));
	
	if(pipe(pipe_fd)==-1) {
		debug_log(FAILED, "ERROR: Problem with worker pipe");
		exit(EXIT_FAILURE);
	}

	/* Fork a new process to try compiling */
	compiler_pid = fork();
	if(compiler_pid == -1) {   // Fork failed, exit
		debug_log(FAILED, "ERROR: unable to fork the compile worker process");
		exit(EXIT_FAILURE);
	}
	else if(compiler_pid==0) { // We are the compile worker, compile test
		close(pipe_fd[0]); // Close read end of pipe

		compile_result = compile_test(in_test);
		if(compile_result->RESULT_CODE == PASSED){
			write(pipe_fd[1], compile_result, sizeof(result_t));

			/* Compile Successful, now fork a new process to try executing */
			execute_pid = fork();
			if(execute_pid == -1) {   // Fork failed, exit
				debug_log(FAILED, "ERROR: unable to fork the execute worker process");
				exit(EXIT_FAILURE);
			}
			else if (execute_pid == 0){ //We are the execute worker, run test
				execute_result = execute_test(in_test);
				if(execute_result->RESULT_CODE == PASSED){ 
					write(pipe_fd[1], execute_result, sizeof(result_t));
				}
				else{ // Runtime failed
					execute_result->RESULT_CODE = RUNTIME_ERR;
					write(pipe_fd[1], execute_result, sizeof(result_t));
				}
			}
			else{ // We are the execute parent, read results and return
				//read(pipe_fd[0], execute_result, sizeof(result_t));
			}
			
		}
		else{ // Compile failed
			compile_result->RESULT_CODE = COMPILE_ERR;
			write(pipe_fd[1], compile_result, sizeof(result_t));
		}
		close(pipe_fd[1]);
	}
	else{ // We are the compile parent, read results
		close(pipe_fd[1]); // Close write end of pipe
		wait(NULL);   // Wait for workers to finish
		read(pipe_fd[0], end_result, sizeof(result_t));
		close(pipe_fd[0]);
		return end_result;
	}
	
	return end_result;
}


result_t * compile_test(test_t in_test)
{
	result_t * result = calloc(1, sizeof(result_t));
	result->RESULT_CODE = PASSED;
	result->last_time_ran = time(NULL);
	printf("compiled!\n");
	return result;
}

result_t * execute_test(test_t in_test)
{
	result_t * result = calloc(1, sizeof(result_t));
	result->RESULT_CODE = PASSED;
	result->last_time_ran = time(NULL);
	printf("executed!\n");
	return result;
}





#include "worker.c"

#endif // WORKER_INC defined
