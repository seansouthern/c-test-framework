#ifndef TEST_COMMON_INC
#include "../framework/test_common.h"
#endif

#ifndef APPLICATION_INC
#include "../../core/application.h"
#endif

void test_application_init( void )
{
	Application * test_app = application_init();
	test_assert_pointer_not_equal(test_app, NULL, __FILE__);
	application_destructor(test_app);
        
}
