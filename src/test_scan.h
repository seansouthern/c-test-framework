#define TEST_SCAN_INC

#include "../lib/linkedlist.h"


int strip_extension(LinkedList * in_list, Node * in_node);
LinkedList * strip_extensions(LinkedList * in_filenames);
LinkedList * scan_for_tests(void);
void set_scan_file(FILE * in_file);
FILE * get_scan_file( void );
int print_test_includes(LinkedList * in_list, Node * in_node);
int print_pointer_declarations(LinkedList * in_list, Node * in_node);
void print_test_list_creation( void );
void print_function_sig( void );
void print_function_close( void );
void write_tests_list(LinkedList * in_function_names);


#include "test_scan.c"
