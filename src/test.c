

test_t test_constructor(char * in_name, char * in_path, time_t in_last_time_ran)
{

	test_t out_test;
	out_test.name = in_name;
	out_test.path = in_path;
	out_test.last_time_ran = in_last_time_ran;
	return out_test;
}
