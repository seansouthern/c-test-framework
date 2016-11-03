#ifndef TEST_COMMON_INC
#include "../framework/test_common.h"
#endif

#ifndef APPLICATION_INC
#include "../../core/application.h"
#endif

void test_application_create_project( void )
{
        Application * test_app = application_init();
	Project * test_proj = application_create_project(test_app, "", "");
	test_assert_pointer_not_equal(test_proj, NULL, __FILE__);
	application_destroy_all_projects(test_app);
}
