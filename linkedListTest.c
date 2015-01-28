#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


void test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0(){
	LinkedList list = createList();
	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.count == 0);
}

void test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL(){
	int x = 5;
	node_ptr node = create_node(&x);
	assertEqual(*(int*)(*node).data,5);
	assert((*node).next == NULL);
}

void test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL(){
	char ch = 'v';
	node_ptr node = create_node(&ch);
	assert(*(char*)(*node).data == 'v');
	assert((*node).next == NULL);
}

void test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL(){
	float f = 5.2;
	node_ptr node = create_node(&f);
	assert(*(float*)(*node).data == (float)5.2);
	assert((*node).next == NULL);
}

void test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL(){
	double f = 5.2;
	node_ptr node = create_node(&f);
	assert(*(double*)(*node).data == 5.2);
	assert((*node).next == NULL);
}

void test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL(){
	string f = "vikas";
	node_ptr node = create_node(&f);
	assert(*(string*)(*node).data == "vikas");
	assert((*node).next == NULL);
}
