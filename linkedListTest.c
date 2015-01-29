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
	free(node);
}

void test_create_node_creates_a_node_with_char_data_and_next_pointing_to_NULL(){
	char ch = 'v';
	node_ptr node = create_node(&ch);
	assert(*(char*)(*node).data == 'v');
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_float_data_and_next_pointing_to_NULL(){
	float f = 5.2;
	node_ptr node = create_node(&f);
	assert(*(float*)(*node).data == (float)5.2);
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_double_data_and_next_pointing_to_NULL(){
	double f = 5.2;
	node_ptr node = create_node(&f);
	assert(*(double*)(*node).data == 5.2);
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_string_data_and_next_pointing_to_NULL(){
	string f = "vikas";
	node_ptr node = create_node(&f);
	assert(*(string*)(*node).data == "vikas");
	assert((*node).next == NULL);
	free(node);
}


int areEqual(Node au1, Node au2){
	return (memcmp(au1.data, au2.data, sizeof(au1.data))==0) ? 1 : 0;
}

void test_add_to_list_adds_given_node_to_its_head_and_tail_when_list_is_empty(){
	string f = "vikas";
	node_ptr node = create_node(&f);
	LinkedList list = createList();
	add_to_list(&list, node);
	assertEqual(areEqual(*(list.head), *node), 1);
	assertEqual(areEqual(*(list.tail), *node), 1);
	// assertEqual(areEqual((Node)((*list.tail).next) , NULL), 1);
	free(node);
}
	
void test_add_to_list_adds_given_node_and_returns_1(){
	string str1 = "vikas", str2 = "vikky";
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	assert(list.count == 0);
	assert(add_to_list(&list, node1) == 1);
	assert(list.count == 1);
	add_to_list(&list, node2);
	assert(list.count == 2);
	assert(add_to_list(&list, node1) == 1);
	assert(list.count == 3);
	free(node1); free(node2);
}

void test_add_to_list_adds_given_node_makes_it_tail_when_list_is_not_empty(){
	int str1 = 12, str2 = 13;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(areEqual(*(list.head), *node1), 1);
	assertEqual(areEqual(*(list.tail), *node2), 1);
	free(node1);  free(node2); 
}

void test_add_to_list_adds_node_to_linked_list_and_add_resets_head_tail_and_count_for_int_node() {
	int data = 20;
	char data2 = 'A';
	Node* node = create_node((void*)&data);
	Node* node2 = create_node((void*)&data);
	LinkedList list = createList();

	assertEqual(add_to_list(&list,node), 1);
	assertEqual(list.count,1);
	assertEqual((int)node,(int)list.head);
	assertEqual((int)node,(int)list.tail);
	assertEqual((int)((Node*)list.tail)->next,0);

	assertEqual(add_to_list(&list,node2),1);
	assertEqual(list.count,2);
	assertEqual((int)node,(int)list.head);
	assertEqual((int)node2,(int)list.tail);
	assertEqual((int)((Node*)list.tail)->next,0);
	free(node);  free(node2); 
}

void test_get_first_element_gives_NULL_when_the_Linked_List_is_empty(){
	LinkedList list = createList();
	assert(list.head == 0);
}

void test_get_last_element_gives_NULL_when_the_Linked_List_is_empty(){
	LinkedList list = createList();
	assert(list.tail == NULL);
}

void test_get_first_element_gives_first_element_from_the_Linked_List(){
	string str1 = "vikas", str2 = "vikky";
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assert(areEqual(*(list.head), *node1) == 1);
	assert((int)(list.head) == (int)node1);
}

void test_get_last_element_gives_last_element_from_the_Linked_List(){
	string str1 = "vikas", str2 = "vikky";
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assert(areEqual(*(list.tail), *node2) == 1);
	assert((int)(list.tail) == (int)node2);
}


