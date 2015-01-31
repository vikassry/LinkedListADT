#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0,test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_unsigned_int_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_unsigned_char_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_signed_char_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_short_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_unsigned_short_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_long_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_unsigned_long_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_structure_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_intArray_data_and_next_pointing_to_NULL,test_create_node_creates_a_node_with_stringArray_data_and_next_pointing_to_NULL,test_areEqual_return_0_when_two_Nodes_are_not_equal,test_areEqual_return_1_when_two_Nodes_are_equal,test_areEqual_return_1_when_two_double_Nodes_are_equal,test_areEqual_return_1_when_two_string_Nodes_are_equal,test_add_to_list_adds_given_string_node_to_its_head_and_tail_when_list_is_empty,test_add_to_list_adds_given_int_node_to_its_head_and_tail_when_list_is_empty,test_add_to_list_adds_given_double_node_to_its_head_and_tail_when_list_is_empty,test_add_to_list_adds_given_node_to_tail_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_int_node_to_tail_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_double_node_to_tail_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_strings_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_float_node_makes_it_tail_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_given_char_node_makes_it_tail_when_list_is_not_empty_and_returns_1,test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node,test_get_first_element_gives_NULL_when_the_Linked_List_is_empty,test_get_first_element_gives_first_element_from_the_Linked_List,test_get_first_element_gives_first_element_from_the_int_Linked_List,test_get_first_element_gives_first_element_from_the_float_Linked_List,test_get_first_element_gives_first_element_from_the_stringArray_Linked_List,test_get_last_element_gives_NULL_when_the_Linked_List_is_empty,test_get_last_element_gives_last_element_from_the_string_Linked_List,test_get_last_element_gives_last_element_from_the_char_Linked_List,test_get_last_element_gives_last_element_from_the_double_Linked_List,test_get_last_element_gives_last_element_from_the_unsigned_long_Linked_List,test_createList_001,test_create_node_007,test_create_node_008,test_add_to_list_001,test_add_to_list_004,test_add_to_list_005,test_add_to_list_009,test_add_to_list_010,test_add_to_list_0011,test_add_to_list_012,test_get_last_element_001,test_traverse_traverse_through_a_int_node_and_increases_each_element_by_one,test_traverse_traverse_through_a_float_node_and_increases_each_element_by_one,test_traverse_traverse_through_a_double_node_and_increases_each_element_by_one,test_traverse_traverse_through_a_char_node_and_increases_each_element_by_one,test_getElementAt_returns_element_at_given_index_for_int_Node,test_getElementAt_returns_NULL_when_negative_index_is_given_for_int_Node,test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_int_Node,test_getElementAt_returns_element_at_given_index_for_float_Node,test_getElementAt_returns_NULL_when_negative_index_is_given_for_float_Node,test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_float_Node,test_getElementAt_returns_element_at_given_index_for_double_Node,test_getElementAt_returns_NULL_when_negative_index_is_given_for_double_Node,test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_double_Node,test_getElementAt_returns_element_at_given_index_for_char_Node,test_getElementAt_returns_NULL_when_negative_index_is_given_for_char_Node,test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_char_Node,test_getElementAt_returns_element_at_given_index_for_string_Node,test_getElementAt_returns_NULL_when_negative_index_is_given_for_string_Node,test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_string_Node,test_indexOf_returns_the_first_index_of_given_string_data_reference_,test_indexOf_returns_minus_1_of_when_given_string_is_not_in_the_list,test_indexOf_returns_the_first_index_of_given_int_data_reference,test_indexOf_returns_minus_1_of_when_given_integer_is_not_in_the_list,test_indexOf_returns_the_first_index_of_given_float_data_reference,test_indexOf_returns_minus_1_of_when_given_floating_value_is_not_in_the_list,test_indexOf_returns_the_first_index_of_given_character_data_reference,test_indexOf_returns_minus_1_of_when_given_charing_value_is_not_in_the_list,test_indexOf_returns_the_index_of_given_double_data_reference,test_indexOf_returns_minus_1_of_when_given_double_value_is_not_in_the_list,test_deleteElementAt_deletes_the_element_at_given_index_and_returns_the_deleted_data_reference,test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_list,test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_stringArray_list,test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_list,test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete,test_deleteElementAt_returns_NULL_when_given_index_is_greater_than_list_count_to_delete,test_deleteElementAt_empties_list_when_there_was_only_1_node_and_makes_head_tail_NULL,test_deleteElement_returns_NULL_when_list_is_empty,test_deleteElementAt_deletes_the_string_element_at_given_index_and_returns_the_deleted_data_reference,test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_float_list,test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_char_list,test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete_in_int_list,test_deleteElementAt_float_list_returns_NULL_when_given_index_is_greater_than_list_count_to_delete,test_deleteElementAt_empties_int_list_when_there_was_only_1_node_and_makes_head_tail_NULL,test_deleteElementAt_deletes_the_intArray_element_at_given_index_and_returns_the_deleted_data_reference,test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_floatArray_list,test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_charArray_list,test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_string_Array_list,test_asArray_populates_int_Array_with_int_Nodes_data_and_returns_number_of_elements_added_to_the_array,test_asArray_does_not_populates_int_Array_and_returns_0_when_list_is_empty,test_asArray_populates_int_Array_with_float_Nodes_data_and_returns_number_of_elements_added_to_the_array,test_asArray_does_not_populates_float_Array_and_returns_0_when_list_is_empty,test_asArray_populates_int_Array_with_char_Nodes_data_and_returns_number_of_elements_added_to_the_array,test_asArray_does_not_populates_char_Array_and_returns_0_when_list_is_empty,test_asArray_populates_int_Array_with_double_Nodes_data_and_returns_number_of_elements_added_to_the_array,test_asArray_does_not_populates_double_Array_and_returns_0_when_list_is_empty,test_asArray_populates_int_Array_with_string_Nodes_data_and_returns_number_of_elements_added_to_the_array,test_asArray_does_not_populates_string_Array_and_returns_0_when_list_is_empty,test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list,test_filter_filters_the_long_int_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_int_list,test_filter_filters_the_unsigned_int_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_unsigned_int_list,test_filter_returns_NULL_when_empty_list_is_passed_to_filter,test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes,test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list,test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list,test_filter_filters_the_long_double_list_and_returns_new_list_of_even_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_double_list,test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list,test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings,test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list;
Test test[] = {"test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0",test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0,"test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_unsigned_int_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_unsigned_int_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_unsigned_char_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_unsigned_char_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_signed_char_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_signed_char_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_short_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_short_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_unsigned_short_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_unsigned_short_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_long_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_long_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_unsigned_long_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_unsigned_long_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_structure_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_structure_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_intArray_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_intArray_data_and_next_pointing_to_NULL,"test_create_node_creates_a_node_with_stringArray_data_and_next_pointing_to_NULL",test_create_node_creates_a_node_with_stringArray_data_and_next_pointing_to_NULL,"test_areEqual_return_0_when_two_Nodes_are_not_equal",test_areEqual_return_0_when_two_Nodes_are_not_equal,"test_areEqual_return_1_when_two_Nodes_are_equal",test_areEqual_return_1_when_two_Nodes_are_equal,"test_areEqual_return_1_when_two_double_Nodes_are_equal",test_areEqual_return_1_when_two_double_Nodes_are_equal,"test_areEqual_return_1_when_two_string_Nodes_are_equal",test_areEqual_return_1_when_two_string_Nodes_are_equal,"test_add_to_list_adds_given_string_node_to_its_head_and_tail_when_list_is_empty",test_add_to_list_adds_given_string_node_to_its_head_and_tail_when_list_is_empty,"test_add_to_list_adds_given_int_node_to_its_head_and_tail_when_list_is_empty",test_add_to_list_adds_given_int_node_to_its_head_and_tail_when_list_is_empty,"test_add_to_list_adds_given_double_node_to_its_head_and_tail_when_list_is_empty",test_add_to_list_adds_given_double_node_to_its_head_and_tail_when_list_is_empty,"test_add_to_list_adds_given_node_to_tail_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_node_to_tail_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_int_node_to_tail_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_int_node_to_tail_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_double_node_to_tail_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_double_node_to_tail_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_strings_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_strings_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_float_node_makes_it_tail_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_float_node_makes_it_tail_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_given_char_node_makes_it_tail_when_list_is_not_empty_and_returns_1",test_add_to_list_adds_given_char_node_makes_it_tail_when_list_is_not_empty_and_returns_1,"test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node",test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node,"test_get_first_element_gives_NULL_when_the_Linked_List_is_empty",test_get_first_element_gives_NULL_when_the_Linked_List_is_empty,"test_get_first_element_gives_first_element_from_the_Linked_List",test_get_first_element_gives_first_element_from_the_Linked_List,"test_get_first_element_gives_first_element_from_the_int_Linked_List",test_get_first_element_gives_first_element_from_the_int_Linked_List,"test_get_first_element_gives_first_element_from_the_float_Linked_List",test_get_first_element_gives_first_element_from_the_float_Linked_List,"test_get_first_element_gives_first_element_from_the_stringArray_Linked_List",test_get_first_element_gives_first_element_from_the_stringArray_Linked_List,"test_get_last_element_gives_NULL_when_the_Linked_List_is_empty",test_get_last_element_gives_NULL_when_the_Linked_List_is_empty,"test_get_last_element_gives_last_element_from_the_string_Linked_List",test_get_last_element_gives_last_element_from_the_string_Linked_List,"test_get_last_element_gives_last_element_from_the_char_Linked_List",test_get_last_element_gives_last_element_from_the_char_Linked_List,"test_get_last_element_gives_last_element_from_the_double_Linked_List",test_get_last_element_gives_last_element_from_the_double_Linked_List,"test_get_last_element_gives_last_element_from_the_unsigned_long_Linked_List",test_get_last_element_gives_last_element_from_the_unsigned_long_Linked_List,"test_createList_001",test_createList_001,"test_create_node_007",test_create_node_007,"test_create_node_008",test_create_node_008,"test_add_to_list_001",test_add_to_list_001,"test_add_to_list_004",test_add_to_list_004,"test_add_to_list_005",test_add_to_list_005,"test_add_to_list_009",test_add_to_list_009,"test_add_to_list_010",test_add_to_list_010,"test_add_to_list_0011",test_add_to_list_0011,"test_add_to_list_012",test_add_to_list_012,"test_get_last_element_001",test_get_last_element_001,"test_traverse_traverse_through_a_int_node_and_increases_each_element_by_one",test_traverse_traverse_through_a_int_node_and_increases_each_element_by_one,"test_traverse_traverse_through_a_float_node_and_increases_each_element_by_one",test_traverse_traverse_through_a_float_node_and_increases_each_element_by_one,"test_traverse_traverse_through_a_double_node_and_increases_each_element_by_one",test_traverse_traverse_through_a_double_node_and_increases_each_element_by_one,"test_traverse_traverse_through_a_char_node_and_increases_each_element_by_one",test_traverse_traverse_through_a_char_node_and_increases_each_element_by_one,"test_getElementAt_returns_element_at_given_index_for_int_Node",test_getElementAt_returns_element_at_given_index_for_int_Node,"test_getElementAt_returns_NULL_when_negative_index_is_given_for_int_Node",test_getElementAt_returns_NULL_when_negative_index_is_given_for_int_Node,"test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_int_Node",test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_int_Node,"test_getElementAt_returns_element_at_given_index_for_float_Node",test_getElementAt_returns_element_at_given_index_for_float_Node,"test_getElementAt_returns_NULL_when_negative_index_is_given_for_float_Node",test_getElementAt_returns_NULL_when_negative_index_is_given_for_float_Node,"test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_float_Node",test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_float_Node,"test_getElementAt_returns_element_at_given_index_for_double_Node",test_getElementAt_returns_element_at_given_index_for_double_Node,"test_getElementAt_returns_NULL_when_negative_index_is_given_for_double_Node",test_getElementAt_returns_NULL_when_negative_index_is_given_for_double_Node,"test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_double_Node",test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_double_Node,"test_getElementAt_returns_element_at_given_index_for_char_Node",test_getElementAt_returns_element_at_given_index_for_char_Node,"test_getElementAt_returns_NULL_when_negative_index_is_given_for_char_Node",test_getElementAt_returns_NULL_when_negative_index_is_given_for_char_Node,"test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_char_Node",test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_char_Node,"test_getElementAt_returns_element_at_given_index_for_string_Node",test_getElementAt_returns_element_at_given_index_for_string_Node,"test_getElementAt_returns_NULL_when_negative_index_is_given_for_string_Node",test_getElementAt_returns_NULL_when_negative_index_is_given_for_string_Node,"test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_string_Node",test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_string_Node,"test_indexOf_returns_the_first_index_of_given_string_data_reference_",test_indexOf_returns_the_first_index_of_given_string_data_reference_,"test_indexOf_returns_minus_1_of_when_given_string_is_not_in_the_list",test_indexOf_returns_minus_1_of_when_given_string_is_not_in_the_list,"test_indexOf_returns_the_first_index_of_given_int_data_reference",test_indexOf_returns_the_first_index_of_given_int_data_reference,"test_indexOf_returns_minus_1_of_when_given_integer_is_not_in_the_list",test_indexOf_returns_minus_1_of_when_given_integer_is_not_in_the_list,"test_indexOf_returns_the_first_index_of_given_float_data_reference",test_indexOf_returns_the_first_index_of_given_float_data_reference,"test_indexOf_returns_minus_1_of_when_given_floating_value_is_not_in_the_list",test_indexOf_returns_minus_1_of_when_given_floating_value_is_not_in_the_list,"test_indexOf_returns_the_first_index_of_given_character_data_reference",test_indexOf_returns_the_first_index_of_given_character_data_reference,"test_indexOf_returns_minus_1_of_when_given_charing_value_is_not_in_the_list",test_indexOf_returns_minus_1_of_when_given_charing_value_is_not_in_the_list,"test_indexOf_returns_the_index_of_given_double_data_reference",test_indexOf_returns_the_index_of_given_double_data_reference,"test_indexOf_returns_minus_1_of_when_given_double_value_is_not_in_the_list",test_indexOf_returns_minus_1_of_when_given_double_value_is_not_in_the_list,"test_deleteElementAt_deletes_the_element_at_given_index_and_returns_the_deleted_data_reference",test_deleteElementAt_deletes_the_element_at_given_index_and_returns_the_deleted_data_reference,"test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_list",test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_list,"test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_stringArray_list",test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_stringArray_list,"test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_list",test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_list,"test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete",test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete,"test_deleteElementAt_returns_NULL_when_given_index_is_greater_than_list_count_to_delete",test_deleteElementAt_returns_NULL_when_given_index_is_greater_than_list_count_to_delete,"test_deleteElementAt_empties_list_when_there_was_only_1_node_and_makes_head_tail_NULL",test_deleteElementAt_empties_list_when_there_was_only_1_node_and_makes_head_tail_NULL,"test_deleteElement_returns_NULL_when_list_is_empty",test_deleteElement_returns_NULL_when_list_is_empty,"test_deleteElementAt_deletes_the_string_element_at_given_index_and_returns_the_deleted_data_reference",test_deleteElementAt_deletes_the_string_element_at_given_index_and_returns_the_deleted_data_reference,"test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_float_list",test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_float_list,"test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_char_list",test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_char_list,"test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete_in_int_list",test_deleteElementAt_returns_NULL_when_negative_index_is_given_to_delete_in_int_list,"test_deleteElementAt_float_list_returns_NULL_when_given_index_is_greater_than_list_count_to_delete",test_deleteElementAt_float_list_returns_NULL_when_given_index_is_greater_than_list_count_to_delete,"test_deleteElementAt_empties_int_list_when_there_was_only_1_node_and_makes_head_tail_NULL",test_deleteElementAt_empties_int_list_when_there_was_only_1_node_and_makes_head_tail_NULL,"test_deleteElementAt_deletes_the_intArray_element_at_given_index_and_returns_the_deleted_data_reference",test_deleteElementAt_deletes_the_intArray_element_at_given_index_and_returns_the_deleted_data_reference,"test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_floatArray_list",test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_floatArray_list,"test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_charArray_list",test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_charArray_list,"test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_string_Array_list",test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_string_Array_list,"test_asArray_populates_int_Array_with_int_Nodes_data_and_returns_number_of_elements_added_to_the_array",test_asArray_populates_int_Array_with_int_Nodes_data_and_returns_number_of_elements_added_to_the_array,"test_asArray_does_not_populates_int_Array_and_returns_0_when_list_is_empty",test_asArray_does_not_populates_int_Array_and_returns_0_when_list_is_empty,"test_asArray_populates_int_Array_with_float_Nodes_data_and_returns_number_of_elements_added_to_the_array",test_asArray_populates_int_Array_with_float_Nodes_data_and_returns_number_of_elements_added_to_the_array,"test_asArray_does_not_populates_float_Array_and_returns_0_when_list_is_empty",test_asArray_does_not_populates_float_Array_and_returns_0_when_list_is_empty,"test_asArray_populates_int_Array_with_char_Nodes_data_and_returns_number_of_elements_added_to_the_array",test_asArray_populates_int_Array_with_char_Nodes_data_and_returns_number_of_elements_added_to_the_array,"test_asArray_does_not_populates_char_Array_and_returns_0_when_list_is_empty",test_asArray_does_not_populates_char_Array_and_returns_0_when_list_is_empty,"test_asArray_populates_int_Array_with_double_Nodes_data_and_returns_number_of_elements_added_to_the_array",test_asArray_populates_int_Array_with_double_Nodes_data_and_returns_number_of_elements_added_to_the_array,"test_asArray_does_not_populates_double_Array_and_returns_0_when_list_is_empty",test_asArray_does_not_populates_double_Array_and_returns_0_when_list_is_empty,"test_asArray_populates_int_Array_with_string_Nodes_data_and_returns_number_of_elements_added_to_the_array",test_asArray_populates_int_Array_with_string_Nodes_data_and_returns_number_of_elements_added_to_the_array,"test_asArray_does_not_populates_string_Array_and_returns_0_when_list_is_empty",test_asArray_does_not_populates_string_Array_and_returns_0_when_list_is_empty,"test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list,"test_filter_filters_the_long_int_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_long_int_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_int_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_int_list,"test_filter_filters_the_unsigned_int_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_unsigned_int_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_unsigned_int_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_unsigned_int_list,"test_filter_returns_NULL_when_empty_list_is_passed_to_filter",test_filter_returns_NULL_when_empty_list_is_passed_to_filter,"test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes,"test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list",test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list,"test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list,"test_filter_filters_the_long_double_list_and_returns_new_list_of_even_nodes",test_filter_filters_the_long_double_list_and_returns_new_list_of_even_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_double_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_double_list,"test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes",test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list,"test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings",test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings,"test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list",test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list};
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