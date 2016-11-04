#include "test_scan.h"


int main(int argc, char** argv)
{

	write_tests_list(scan_for_tests());
	printf("Tests scanned.\n");
	
	return 0;

}
