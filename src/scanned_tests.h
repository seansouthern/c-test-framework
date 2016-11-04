#ifndef SCANNED_TESTS_H
#define SCANNED_TESTS_H
#endif
#ifndef LINKEDLIST_INC
#include "../lib/linkedlist.h"
#endif
#include "../tests/test_application_create_project.c"
#include "../tests/test_application_init.c"
#include "../tests/test_board_create_card.c"
#include "../tests/test_broker_handle_request.c"
#include "../tests/test_create_iteration.c"
#include "../tests/test_project_create_board.c"
LinkedList * initialize_generated_tests()
{
LinkedList * final_test_list = list_create();
void (*p_test_application_create_project)(void) = test_application_create_project;
list_insert_node(final_test_list, list_create_node(p_test_application_create_project));
void (*p_test_application_init)(void) = test_application_init;
list_insert_node(final_test_list, list_create_node(p_test_application_init));
void (*p_test_board_create_card)(void) = test_board_create_card;
list_insert_node(final_test_list, list_create_node(p_test_board_create_card));
void (*p_test_broker_handle_request)(void) = test_broker_handle_request;
list_insert_node(final_test_list, list_create_node(p_test_broker_handle_request));
void (*p_test_create_iteration)(void) = test_create_iteration;
list_insert_node(final_test_list, list_create_node(p_test_create_iteration));
void (*p_test_project_create_board)(void) = test_project_create_board;
list_insert_node(final_test_list, list_create_node(p_test_project_create_board));
return final_test_list;
}