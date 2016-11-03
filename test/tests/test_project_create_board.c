#ifndef TEST_COMMON_INC
#include "../framework/test_common.h"
#endif

#ifndef APPLICATION_INC
#include "../../core/application.h"
#endif



void test_project_create_board()
{
	Application * my_app = application_init();
	Project * my_proj = application_create_project(my_app, "Test Project", "A test project.");
	Board * my_board= project_create_board(my_proj);
	test_assert_pointer_not_equal(my_board, NULL, __FILE__);
	application_destructor(my_app);
}
