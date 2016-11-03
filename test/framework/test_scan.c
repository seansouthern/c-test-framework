#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "linkedlist.h"

#define SCAN_FILE_PATH "./src/test/framework/scanned_tests.h"

FILE * scan_file;
LinkedList * test_list;


int strip_extension(LinkedList * in_list, Node * in_node)
{	
	// Strip file extensions from the node's filename data to get the function name
	char * temp_string = calloc(255, sizeof(char));
        char * node_string = (char * ) in_node->data;
	strncpy(temp_string, node_string, 255);
	
	if(strtok(temp_string, ".") != '\0'){
		in_node->data = temp_string;
	}
        return 0;
}

LinkedList * strip_extensions(LinkedList * filenames)
{
	LinkedList * stripped_names = filenames;
	traverse(filenames, strip_extension);
	return stripped_names;
}

LinkedList * scan_for_tests( void )
{
	LinkedList * valid_files = list_create();
        struct dirent **namelist;
        
	int n = scandir( "./src/test/tests/", &namelist, NULL, alphasort);
	
	if (n < 0){
		perror("scandir");
	      	list_destroy(valid_files, list_delete_node);
		
	}
	else {
		while (n--) {
			if(strlen(namelist[n]->d_name) > 2){	
				if(isalpha(namelist[n]->d_name[0])){
					int z  = 0;
					char term = namelist[n]->d_name[z];
					while( term != '\0'){
						z++;
						term = namelist[n]->d_name[z];
					}
					if((namelist[n]->d_name[z-1] == 'c' || namelist[n]->d_name[z-1] == 'h') && namelist[n]->d_name[z-2] =='.'){
						list_insert_node(valid_files, list_create_node(namelist[n]->d_name));
					}
				}
			}
			free(namelist[n]);
		}
		free(namelist);
	}
	LinkedList * function_names = strip_extensions(valid_files);

	return function_names;
}



void set_scan_file(FILE * in_file)
{
	scan_file = in_file;
}

FILE * get_scan_file()
{
	return scan_file;
}

int print_test_includes(LinkedList * in_list, Node * in_node)
{
	char * function_name = (char*)in_node->data;

	fprintf(get_scan_file(), "#include \"../tests/%s.c\"\n", function_name);
	return 0;
}

int print_pointer_declarations(LinkedList *in_list, Node * in_node)
{
	char * function_name =  in_node->data;
	fprintf(get_scan_file(), "void (*p_%s)(void) = %s;\n", function_name, function_name );
	fprintf(get_scan_file(), "list_insert_node(final_test_list, list_create_node(p_%s));\n", function_name);
	return 0;
}

void print_test_list_creation()
{
	fprintf(get_scan_file(), "LinkedList * final_test_list = list_create();\n");
}

void print_function_sig()
{
	fprintf(get_scan_file(), "LinkedList * initialize_generated_tests()\n{\n");
}

void print_function_close()
{
	fprintf(get_scan_file(),"return final_test_list;\n");
	fprintf(get_scan_file(), "}");
}

void write_tests_list(LinkedList * in_function_names)
{
	set_scan_file(fopen(SCAN_FILE_PATH, "w"));	
	if(get_scan_file() != NULL){
		fprintf(get_scan_file(), "#ifndef SCANNED_TESTS_H\n#define SCANNED_TESTS_H\n#endif\n");
		fprintf(get_scan_file(), "#ifndef LINKEDLIST_INC\n#include \"linkedlist.h\"\n#endif\n");
		traverse(in_function_names, print_test_includes);

		print_function_sig();
		print_test_list_creation();
		traverse(in_function_names, print_pointer_declarations);
		print_function_close();
		fclose(get_scan_file());
        
	}
	else
	{
		printf("Scan file's not there\n");
	}
	list_destroy(in_function_names, list_delete_node);
}
