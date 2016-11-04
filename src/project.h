#ifndef PROJECT_INC
#define PROJECT_INC

#include "../lib/linkedlist.h"
#include "suite.h"


typedef struct Project {
	char * name;
	LinkedList * suites;

}  project_t;


int add_suite(project_t in_project, suite_t in_suite);
int remove_suite(project_t in_project, suite_t in_suite);




#endif // PROJECT_INC defined
