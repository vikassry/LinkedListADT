#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list,test_filter_returns_NULL_when_empty_list_is_passed_to_filter,test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes,test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list,test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list,test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list,test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list;
Test test[] = {"test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list,"test_filter_returns_NULL_when_empty_list_is_passed_to_filter",test_filter_returns_NULL_when_empty_list_is_passed_to_filter,"test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes,"test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list",test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list,"test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list,"test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes",test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list,"test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings",test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list};
char testFileName[] = {"linkedListTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}