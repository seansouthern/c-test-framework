#ifndef TEST_COMMON_INC
#include "../framework/test_common.h"
#endif

#ifndef APPLICATION_INC
#include "../../core/application.h"
#endif

void test_create_iteration()
{
        Application * test_app = application_init();
	Project * test_project = application_create_project(test_app, "", "");
	
	
	application_destructor(test_app);
	
	


}
