#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0,test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL,test_add_to_list_adds_given_node_to_its_head_and_tail_when_list_is_empty,test_add_to_list_adds_given_node_and_returns_1,test_add_to_list_adds_given_node_makes_it_tail_when_list_is_not_empty,test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node,test_get_first_element_gives_first_element_from_the_Linked_List,test_get_last_element_gives_last_element_from_the_Linked_List,test_createList_001,test_create_node_001,test_create_node_002,test_create_node_003,test_create_node_004,test_create_node_005,test_create_node_006,test_create_node_007,test_create_node_008,test_add_to_list_001,test_add_to_list_002,test_add_to_list_003,test_add_to_list_004,test_add_to_list_005,test_add_to_list_006,test_add_to_list_007,test_add_to_list_008,test_add_to_list_009,test_add_to_list_010,test_add_to_list_0011,test_add_to_list_012,test_get_first_element_001,test_get_last_element_001,test_traverse_001;
Test test[] = {"test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0",test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0,"test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL,"test_add_to_list_adds_given_node_to_its_head_and_tail_when_list_is_empty",test_add_to_list_adds_given_node_to_its_head_and_tail_when_list_is_empty,"test_add_to_list_adds_given_node_and_returns_1",test_add_to_list_adds_given_node_and_returns_1,"test_add_to_list_adds_given_node_makes_it_tail_when_list_is_not_empty",test_add_to_list_adds_given_node_makes_it_tail_when_list_is_not_empty,"test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node",test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node,"test_get_first_element_gives_first_element_from_the_Linked_List",test_get_first_element_gives_first_element_from_the_Linked_List,"test_get_last_element_gives_last_element_from_the_Linked_List",test_get_last_element_gives_last_element_from_the_Linked_List,"test_createList_001",test_createList_001,"test_create_node_001",test_create_node_001,"test_create_node_002",test_create_node_002,"test_create_node_003",test_create_node_003,"test_create_node_004",test_create_node_004,"test_create_node_005",test_create_node_005,"test_create_node_006",test_create_node_006,"test_create_node_007",test_create_node_007,"test_create_node_008",test_create_node_008,"test_add_to_list_001",test_add_to_list_001,"test_add_to_list_002",test_add_to_list_002,"test_add_to_list_003",test_add_to_list_003,"test_add_to_list_004",test_add_to_list_004,"test_add_to_list_005",test_add_to_list_005,"test_add_to_list_006",test_add_to_list_006,"test_add_to_list_007",test_add_to_list_007,"test_add_to_list_008",test_add_to_list_008,"test_add_to_list_009",test_add_to_list_009,"test_add_to_list_010",test_add_to_list_010,"test_add_to_list_0011",test_add_to_list_0011,"test_add_to_list_012",test_add_to_list_012,"test_get_first_element_001",test_get_first_element_001,"test_get_last_element_001",test_get_last_element_001,"test_traverse_001",test_traverse_001};
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