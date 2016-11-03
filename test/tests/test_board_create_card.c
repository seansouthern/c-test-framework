#ifndef TEST_COMMON_INC
#include "../framework/test_common.h"
#endif

#ifndef APPLICATION_INC
#include "../../core/application.h"
#endif


void test_board_create_card()
{
	Application * my_app = application_init();
	Project * test_proj = application_create_project(my_app, "Test Project", "A test project.");
	Board * test_board = project_create_board(test_proj);
	Card * test_card = board_create_card(test_board);
	test_assert_pointer_not_equal(test_card, NULL, __FILE__);
	application_destructor(my_app);

}
