#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#define log(test_description) int log = printf("\t  ==>%s\n\n", test_description)


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
	assert((*list.tail).next == NULL);
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

// void test_get_first_element_gives_NULL_when_the_Linked_List_is_empty(){
// 	LinkedList list = createList();
// 	assertEqual(*(int*)get_first_element(list), (int)0);
// }

// void test_get_last_element_gives_NULL_when_the_Linked_List_is_empty(){
// 	LinkedList list = createList();
// 	assertEqual(*(int*)get_last_element(list), (int)0);
// }

void test_get_first_element_gives_first_element_from_the_Linked_List(){
	string str1 = "vikas", str2 = "vikky";
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	
	assert(*(string*)get_first_element(list) == "vikas");
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
	
	assert(*(string*)get_last_element(list) == "vikky");
	assert(areEqual(*(list.tail), *node2) == 1);
	assert((int)(list.tail) == (int)node2);
}


void test_createList_001() {
	log("create list creates a blank list");
	LinkedList list = createList(),tmp = {0,0,0};
	assertEqual((int)list.head,(int)tmp.head);
	assertEqual(list.count,tmp.count);
	assertEqual((int)list.tail,(int)tmp.tail);
}

void test_create_node_001() {
	log("create_node creates a node with given integer");
	int c = 9;
	Node *intNode = create_node(&c);
	assertEqual(*(int *)((*intNode).data),9);
	assert((*intNode).next == 0);
}

void test_create_node_002() {
	log("create_node creates a node with given character");
	char c = 'A';
	Node *intNode = create_node(&c);
	assertEqual(*(char *)((*intNode).data),'A');
	assert((*intNode).next == 0);
}

void test_create_node_003() {
	log("create_node creates a node with given string");
	string c = "Prasenjit";
	Node *intNode = create_node(&c);
	assert(*(string*)((*intNode).data) == "Prasenjit");
	assert((*intNode).next == 0);
}

void test_create_node_004() {
	log("create_node creates a node with given float");
	float c = 19.2;
	Node *intNode = create_node(&c);
	assertEqual(*(float *)((*intNode).data), (float)19.2);
	assert((*intNode).next == 0);
}

void test_create_node_005() {
	log("create_node creates a node with given double");
	double c = 19.2;
	Node *intNode = create_node(&c);
	assert(*(double *)((*intNode).data) == 19.2);
	assert((*intNode).next == 0);
}

void test_create_node_006() {
	log("create_node creates a node with given longint");
	long int c = 2147483647;
	Node *intNode = create_node(&c);
	assert(*(long int *)((*intNode).data) == 2147483647);
	assert((*intNode).next == 0);
}

void test_create_node_007() {
	log("create_node creates a node with given signed char");
	signed char c = 127;
	Node *intNode = create_node(&c);
	assert(*(signed char *)((*intNode).data) == 127);
	assert((*intNode).next == 0);
}

void test_create_node_008() {
	log("create_node creates a node with given unsigned char");
	unsigned char c = 255;
	Node *intNode = create_node(&c);
	assert(*(unsigned char *)((*intNode).data) == 255);
	assert((*intNode).next == 0);
}

void test_add_to_list_001() {
	log("adds an integer data element to the empty linklist");
	int c = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	assert(*(int *)(*(list.head)).data == 9);
}

void test_add_to_list_002() {
	log("adds an integer data element to the existing linklist");
	int c = 9,d = 10;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(int *)(*(list.head)).data == 9);
	assert(*(int *)(*(list.tail)).data == 10);
}

void test_add_to_list_003() {
	log("adds an integer data element to the empty character linklist");
	char c = 'A';
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(char *)(*(list.head)).data == 'A');
}

void test_add_to_list_004() {
	log("adds a character data element to the existing character linklist");
	char c = 'A',d = 'B';
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(char *)(*(list.head)).data == 'A');
	assert(*(char *)(*(list.tail)).data == 'B');
}

void test_add_to_list_005() {
	log("adds a string data element to the empty linklist for strings");
	string c = "Prasenjit";
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(string *)(*(list.head)).data == "Prasenjit");
	assert(*(string *)(*(list.tail)).data == "Prasenjit");
}

void test_add_to_list_006() {
	log("adds a string data element to the existing linklist for string");
	string c = "Prasenjit",d = "Chakraborty";
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(string *)(*(list.head)).data == "Prasenjit");
	assert(*(string *)(*(list.tail)).data == "Chakraborty"); /*Checkpoint*/
}

void test_add_to_list_007() {
	log("adds a float data element to the empty linklist for floats");
	float c = 72.3;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(float *)(*(list.head)).data == (float)72.3);
	assert(*(float *)(*(list.tail)).data == (float)72.3);
}

void test_add_to_list_008() {
	log("adds a float data element to the existing float linklist");
	float c = 72.3,d = 65.3;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(float *)(*(list.head)).data == (float)72.3);
	assertEqual(*(float *)(*(list.tail)).data, (float)65.3);
}

void test_add_to_list_009() {
	log("adds a long int data element to the empty linklist for long ints");
	long int c = 2147483647;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(long int *)(*(list.head)).data == 2147483647);
	assert(*(long int *)(*(list.tail)).data == 2147483647);
}

void test_add_to_list_010() {
	log("adds a long int data element to the existing long int linklist");
	long int c = 2147483647,d = 2147483646;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(long int *)(*(list.head)).data == 2147483647);
	assert(*(long int *)(*(list.tail)).data == 2147483646);
}

void test_add_to_list_0011() {
	log("adds a double data element to the empty linklist for doubles");
	double c = 21.1;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(double *)(*(list.head)).data == 21.1);
	assert(*(double *)(*(list.tail)).data == 21.1);
}

void test_add_to_list_012() {
	log("adds a double data element to the existing double linklist");
	double c = 21.1,d = 21.2;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(double *)(*(list.head)).data == 21.1);
	assert(*(double *)(*(list.tail)).data == 21.2);
}

void test_get_first_element_001() {
	log("gives the first element of the link list");
	int c = 9,*res;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	res = get_first_element(list);
	assert(*res == 9);
}

void test_get_last_element_001() {
	log("gives the first element of the link list if there is only one element");
	int c = 9,*res;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	res = get_last_element(list);
	assertEqual(*res, 9);
}

void add(void* data) {
	*(int*)data += 1;
}

void test_traverse_001() {
	log("traverse through a int node and increases each element by one");
	int c = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	traverse(list,add);
	assert(*(int*)(*(list.head)).data == 10);
}