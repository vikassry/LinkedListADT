#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#define log(test_description) int log = printf(" => %s\n\n", test_description)
typedef struct student{
	int age;
	string name;
} Student;

void test_createList_creates_an_empty_list_with_head_and_tail_initialized_to_NULL_and_count_as_0(){
	LinkedList list = createList();
	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.count == 0);
}

void test_create_node_creates_a_node_with_int_data_and_next_pointing_to_NULL(){
	int x = 2;
	node_ptr node = create_node(&x);
	assertEqual(*(int*)(*node).data, 2);
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_unsigned_int_data_and_next_pointing_to_NULL(){
	unsigned int x = 52;
	node_ptr node = create_node(&x);
	assertEqual(*(unsigned int*)(*node).data,52);
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

void test_create_node_creates_a_node_with_unsigned_char_data_and_next_pointing_to_NULL(){
	unsigned char ch = 'v';
	node_ptr node = create_node(&ch);
	assert(*(unsigned char*)(*node).data == 'v');
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_signed_char_data_and_next_pointing_to_NULL(){
	signed char ch = 'V';
	node_ptr node = create_node(&ch);
	assert(*(signed char*)(*node).data == 'V');
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_short_data_and_next_pointing_to_NULL(){
	short x = -52;
	node_ptr node = create_node(&x);
	assertEqual(*(short*)(*node).data,-52);
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_unsigned_short_data_and_next_pointing_to_NULL(){
	unsigned short x = 52;
	node_ptr node = create_node(&x);
	assertEqual(*(unsigned short*)(*node).data,52);
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

void test_create_node_creates_a_node_with_long_data_and_next_pointing_to_NULL(){
	long f = -2147483648;
	node_ptr node = create_node(&f);
	assert(*(long*)(*node).data == -2147483648);
	assert((*node).next == NULL);
	free(node);
}

void test_create_node_creates_a_node_with_unsigned_long_data_and_next_pointing_to_NULL(){
	unsigned long f = 4294967295;
	node_ptr node = create_node(&f);
	assert(*(unsigned long*)(*node).data == 4294967295);
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


void test_create_node_creates_a_node_with_structure_data_and_next_pointing_to_NULL(){
	Student s1 = {12,"vikas"};
	node_ptr node = create_node(&s1);
	assert((Student*)(*node).data == &s1);
	assert((*node).next == NULL);
	free(node);
}

int areEqual(Node n1, Node n2){
	return (memcmp(n1.data, n2.data, sizeof(n1.data))==0);
}

void test_areEqual_return_0_when_two_Nodes_are_not_equal(){
	string a = "hiii", b="byee", *result;
	LinkedList list = createList();
	Node *node1, *node2;
	node1 = create_node(&a);
	node2 = create_node(&b);
	assertEqual(areEqual(*node1, *node2), 0);
	free(node1); free(node2);
}

void test_areEqual_return_1_when_two_Nodes_are_equal(){
	string a = "hiii", b = "hiii", *result;
	LinkedList list = createList();
	Node *node1, *node2;
	node1 = create_node(&a);
	node2 = create_node(&b);
	assertEqual(areEqual(*node1, *node2), 1);
	free(node1); free(node2);
}

void test_areEqual_return_1_when_two_double_Nodes_are_equal(){
	double a = 4.3, b = 4.1, c=4.3;
	LinkedList list = createList();
	Node *node1, *node2, *node3;
	node1 = create_node(&a);
	node2 = create_node(&b);
	node3 = create_node(&c);
	assertEqual(areEqual(*node1, *node2), 0);
	assertEqual(areEqual(*node1, *node3), 1);
	free(node1); free(node2); free(node3);
}


void test_add_to_list_adds_given_string_node_to_its_head_and_tail_when_list_is_empty(){
	string f = "vikas";
	node_ptr node = create_node(&f);
	LinkedList list = createList();
	assert(list.tail == NULL);
	assert(list.head == NULL);
	
	assert(add_to_list(&list, node) == 1);
	assert(list.head == node);
	assert(list.tail == node);
	assertEqual(areEqual(*list.head, *node), 1);
	assertEqual(areEqual(*list.tail, *node), 1);
	assert((*list.tail).next == NULL);
	assert(node->next == NULL);
	free(node);
}

void test_add_to_list_adds_given_int_node_to_its_head_and_tail_when_list_is_empty(){
	int a = 4;
	node_ptr node = create_node(&a);
	LinkedList list = createList();
	assert(list.tail == NULL);
	assert(list.head == NULL);
	
	assert(add_to_list(&list, node) == 1);
	assert(list.head == node);
	assert(list.tail == node);
	assertEqual(areEqual(*list.head, *node), 1);
	assertEqual(areEqual(*list.tail, *node), 1);
	assert((*list.tail).next == NULL);
	free(node);
}

void test_add_to_list_adds_given_double_node_to_its_head_and_tail_when_list_is_empty(){
	double a = 4;
	node_ptr node = create_node(&a);
	LinkedList list = createList();
	assert(list.tail == NULL);
	assert(list.head == NULL);
	
	assert(add_to_list(&list, node) == 1);
	assert(list.head == node);
	assert(list.tail == node);
	assertEqual(areEqual(*list.head, *node), 1);
	assertEqual(areEqual(*list.tail, *node), 1);
	assert((*list.tail).next == NULL);
	free(node);
}

	
void test_add_to_list_adds_given_node_to_tail_when_list_is_not_empty_and_returns_1(){
	string str1 = "vikas", str2 = "vikky"; int num = 4;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	node_ptr node3 = create_node(&num);
	assert(list.count == 0);
	assert(add_to_list(&list, node1) == 1);
	assert(list.head == node1);
	assert(list.tail == node1);
	assert(list.count == 1);

	add_to_list(&list, node2); 
	assert(list.count == 2);
	assert(list.head == node1);
	assert(list.tail == node2);	

	assert(add_to_list(&list, node3) == 1);
	assert(list.count == 3);

	assert(list.head== node1);
	assert(list.tail == node3);
	free(node1); free(node2); free(node3);
}

void test_add_to_list_adds_given_int_node_to_tail_when_list_is_not_empty_and_returns_1(){
	int str1 = 4, str2 = 5; int num = 6;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	node_ptr node3 = create_node(&num);
	assert(list.count == 0);
	assert(add_to_list(&list, node1) == 1);
	assert(list.head == node1);
	assert(list.tail == node1);
	assert(list.count == 1);

	add_to_list(&list, node2); 
	assert(list.count == 2);
	assert(list.head == node1);
	assert(list.tail == node2);	

	assert(add_to_list(&list, node3) == 1);
	assert(list.count == 3);

	assert(list.head== node1);
	assert(list.tail == node3);
	assert(*(int*)(list.head->data) == 4);
	assert(*(int*)(list.tail->data) == 6);
	free(node1); free(node2); free(node3);
}

void test_add_to_list_adds_given_double_node_to_tail_when_list_is_not_empty_and_returns_1(){
	double str1 = 4.3, str2 = 5.5; double num = 6.7;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	node_ptr node3 = create_node(&num);
	assert(list.count == 0);
	assert(add_to_list(&list, node1) == 1);
	assert(list.head == node1);
	assert(list.tail == node1);
	assert(list.count == 1);

	add_to_list(&list, node2); 
	assert(list.count == 2);
	assert(list.head == node1);
	assert(list.tail == node2);	
	assert(*(double*)(list.tail->data) == 5.5);

	assert(add_to_list(&list, node3) == 1);
	assert(list.count == 3);

	assert(list.head== node1);
	assert(list.head->next == node2);
	assert(list.tail->next == NULL);
	assert(list.head== node1);
	assert(list.tail == node3);
	assert(*(double*)(list.head->data) == 4.3);
	assert(*(double*)(list.tail->data) == 6.7);
	free(node1); free(node2); free(node3);
}


void test_add_to_list_adds_given_node_makes_it_tail_and_tail_pointing_to_NULL_when_list_is_not_empty_and_returns_1(){
	int str1 = 12, str2 = 13, result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	result = add_to_list(&list, node1);
	assert(result == 1);
	result = add_to_list(&list, node2);
	
	assertEqual(areEqual(*(list.head), *node1), 1);
	assertEqual(areEqual(*(list.tail), *node2), 1);
	assert((*list.head).next == node2);
	assert((*list.tail).next == NULL);
	assert((*node2).next == NULL);
	free(node1); free(node2); 
}


void test_add_to_list_adds_given_float_node_makes_it_tail_when_list_is_not_empty_and_returns_1(){
	float num1 = 12.5, num2 = 1.3, result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	result = add_to_list(&list, node1);
	assert(result == 1);
	result = add_to_list(&list, node2);
	
	assertEqual(areEqual(*(list.head), *node1), 1);
	assertEqual(areEqual(*(list.tail), *node2), 1);
	assert((*list.head).next == node2);
	assert((*list.tail).next == NULL);
	assert((*node2).next == NULL);
	free(node1); free(node2); 
}


void test_add_to_list_adds_given_char_node_makes_it_tail_when_list_is_not_empty_and_returns_1(){
	char num1 = 'a', num2 = 'b', num3 = 'c', result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	node_ptr node3 = create_node(&num3);

	result = add_to_list(&list, node1);
	assert(result == 1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	
	assertEqual(areEqual(*(list.head), *node1), 1);
	assertEqual(areEqual(*list.head->next, *node2), 1);
	assertEqual(areEqual(*(list.tail), *node3), 1);
	assert((*list.head).next == node2);
	assert((*list.tail).next == NULL);
	assert(*(char*)(*list.tail).data == 'c');
	free(node1); free(node2); 
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
	free(node); free(node2); 
}

void test_get_first_element_gives_NULL_when_the_Linked_List_is_empty(){
	LinkedList list = createList();
	assert(get_first_element(list) == NULL);
}

void test_get_first_element_gives_first_element_from_the_Linked_List(){
	string str1 = "vikas", str2 = "vikky", *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = get_first_element(list);
	
	assert(*result == "vikas");
	assert(result == list.head->data);
	assert(*result == *(string*)list.head->data);
	free(node1); free(node2);
}

void test_get_first_element_gives_first_element_from_the_int_Linked_List(){
	int num1 = 234343, num2 = 4534535, *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = get_first_element(list);
	
	assert(*result == 234343);
	assert(result == list.head->data);
	assert(*result == *(int*)list.head->data);
	free(node1); free(node2);
}

void test_get_first_element_gives_first_element_from_the_float_Linked_List(){
	float num1 = 234.343, num2 = 4534.535, *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = get_first_element(list);
	
	assert(*result == (float)234.343);
	assert(result == list.head->data);
	assert(*result == *(float*)list.head->data);
	free(node1); free(node2);
}


void test_get_last_element_gives_NULL_when_the_Linked_List_is_empty(){
	LinkedList list = createList();
	assert(get_last_element(list) == NULL);
}

void test_get_last_element_gives_last_element_from_the_string_Linked_List(){
	string str1 = "vikas", str2 = "vikky", *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&str1);
	node_ptr node2 = create_node(&str2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	
	result = get_last_element(list);
	assert(*result == "vikky");
	assert(*(string*)list.tail->data == *result);
	free(node1); free(node2);
}

void test_get_last_element_gives_last_element_from_the_char_Linked_List(){
	char ch1 = 'v', ch2 = 'K', *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&ch1);
	node_ptr node2 = create_node(&ch2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	
	result = get_last_element(list);
	assert(*result == 'K');
	assert(*(char*)list.tail->data == *result);
	free(node1); free(node2);
}

void test_get_last_element_gives_last_element_from_the_double_Linked_List(){
	double num1 = 4543.34, num2 =343.5 , *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	
	result = get_last_element(list);
	assert(*result == 343.5);
	assert(*(double*)list.tail->data == *result);
	free(node1); free(node2);
}

void test_get_last_element_gives_last_element_from_the_unsigned_long_Linked_List(){
	unsigned long num1 = 4243343333, num2 = 3432342242 , *result;
	LinkedList list = createList();
	node_ptr node1 = create_node(&num1);
	node_ptr node2 = create_node(&num2);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	
	result = get_last_element(list);
	assert(*result == 3432342242);
	assert(*(unsigned long*)list.tail->data == *result);
	free(node1); free(node2);
}


void test_createList_001() {
	log("create list creates a blank list");
	LinkedList list = createList(),tmp = {0,0,0};
	assertEqual((int)list.head,(int)tmp.head);
	assertEqual(list.count,tmp.count);
	assertEqual((int)list.tail,(int)tmp.tail);
}


void test_create_node_007() {
	log("create_node creates a node with given signed char");
	signed char c = 127;
	Node *intNode = create_node(&c);
	assert(*(signed char *)((*intNode).data) == 127);
	assert((*intNode).next == 0);
	free(intNode);
}

void test_create_node_008() {
	log("create_node creates a node with given unsigned char");
	unsigned char c = 255;
	Node *intNode = create_node(&c);
	assert(*(unsigned char *)((*intNode).data) == 255);
	assert((*intNode).next == 0);
	free(intNode);
}

void test_add_to_list_001() {
	log("adds an integer data element to the empty linklist");
	int c = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	assert(*(int *)(*(list.head)).data == 9);
	free(intNode);
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
	free(node1); free(node2); 
}

void test_add_to_list_005() {
	log("adds a string data element to the empty linklist for strings");
	string c = "Prasenjit";
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(string *)(*(list.head)).data == "Prasenjit");
	assert(*(string *)(*(list.tail)).data == "Prasenjit");
	free(charNode);
}

void test_add_to_list_009() {
	log("adds a long int data element to the empty linklist for long ints");
	long int c = 2147483647;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(long int *)(*(list.head)).data == 2147483647);
	assert(*(long int *)(*(list.tail)).data == 2147483647);
	free(charNode);
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
	free(charNode);
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
	free(node1); free(node2); 
}

void test_get_last_element_001() {
	log("gives the first element of the link list if there is only one element");
	int c = 9,*res;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	res = get_last_element(list);
	assertEqual(*res, 9);
	free(intNode);
}

void add(void* data) {
	*(int*)data += 1;
}

void test_traverse_traverse_through_a_int_node_and_increases_each_element_by_one(){
	int a = 9, b=10;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	
	traverse(list,add);
	
	assert(*(int*)(*(list.head)).data == 10);
	assert(*(int*)(*(list.tail)).data == 11);
	free(node1); free(node2); 
}

void subtract(void* data) {
	*(float*)data -= 1;
}

void test_traverse_traverse_through_a_float_node_and_increases_each_element_by_one(){
	float a = 9.4, b=10.5;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	
	traverse(list,subtract);
	
	assert(*(float*)(*(list.head)).data == (float)8.4);
	assert(*(float*)(*(list.tail)).data == 9.5);
	free(node1); free(node2); 
}

void increment(void *item){
	*(double*)item += 1;
}
void test_traverse_traverse_through_a_double_node_and_increases_each_element_by_one(){
	double a = 9.4, b=10.5;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	
	traverse(list,increment);
	
	assert(*(double*)(*(list.head)).data == 10.4);
	assert(*(double*)(*(list.tail)).data == 11.5);
	free(node1); free(node2); 
}

void toUpper(void *item){
	*(char*)item = *(char*)item - 32;
}
void test_traverse_traverse_through_a_char_node_and_increases_each_element_by_one(){
	char a = 'a', b='b';
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	
	traverse(list, toUpper);
	
	assert(*(char*)(*(list.head)).data == 'A');
	assert(*(char*)(*(list.tail)).data == 'B');
	free(node1); free(node2); 
}

void test_getElementAt_returns_element_at_given_index_for_int_Node(){
	int a = 9, b=10, c=11, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	result = getElementAt(list, 1);
	assertEqual(*(int*)result, 10);
	free(node1); free(node2); free(node3);
}

void test_getElementAt_returns_NULL_when_negative_index_is_given_for_int_Node(){
	int a = 9, b=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = (int*)getElementAt(list, -9);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_int_Node(){
	int a = 9, b=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = (int*)getElementAt(list, 23);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_element_at_given_index_for_float_Node(){
	float a = 9.3, b=10.4, c=11.6, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	result = getElementAt(list, 1);
	assertEqual(*result, (float)10.4);
	free(node1); free(node2); free(node3);
}

void test_getElementAt_returns_NULL_when_negative_index_is_given_for_float_Node(){
	float a = 9, b=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, -9);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_float_Node(){
	float a = 9, b=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 23);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_element_at_given_index_for_double_Node(){
	double a = 9.3, b=10.4, c=11.6, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	result = getElementAt(list, 1);
	assertEqual(*(double*)result, (double)10.4);
	free(node1); free(node2); free(node3);
}

void test_getElementAt_returns_NULL_when_negative_index_is_given_for_double_Node(){
	double a = 9.5, b=10.7, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, -9);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_double_Node(){
	double a = 9.0, b=10.8, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 23);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_element_at_given_index_for_char_Node(){
	char a = 'a', b='b', c='c', *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	result = getElementAt(list, 1);
	assertEqual(*result, 'b');
	free(node1); free(node2); free(node3);
}

void test_getElementAt_returns_NULL_when_negative_index_is_given_for_char_Node(){
	char a = 'c', b='b', *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, -9);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_char_Node(){
	char a = 'c', b='b', *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 23);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_element_at_given_index_for_string_Node(){
	string a = "hiii", b="byee", c="go to hell !", *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	result = getElementAt(list, 1);
	assert(*result == "byee");
	free(node1); free(node2); free(node3);
}

void test_getElementAt_returns_NULL_when_negative_index_is_given_for_string_Node(){
	string a = "hiii", b="byee", c="go to hell !", *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, -9);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_getElementAt_returns_NULL_when_index_is_greater_then_no_of_nodes_for_string_Node(){
	string a = "hiii", b="byee", c="go to hell !", *result;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 23);
	assert(result == NULL);
	free(node1); free(node2); 
}

void test_indexOf_returns_the_first_index_of_given_string_data_reference_(){
	string a = "hiii", b="byee", c="go to hell !", *result;
	LinkedList list = createList();
	Node *node1 = create_node(&b);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&b);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(indexOf(list, &a) == -1);
	assert(indexOf(list, &b) == 0);
	assert(indexOf(list, &c) == -1);
	free(node1); free(node2); free(node3);
}

void test_indexOf_returns_minus_1_of_when_given_string_is_not_in_the_list(){
	string a = "hiii", b="byee", c="viias";
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(indexOf(list, &c) == -1);
	free(node1); free(node2); 
}


void test_indexOf_returns_the_first_index_of_given_int_data_reference(){
	int a = 12, b = 34, c = 4;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(indexOf(list, &a) == 0);
	assert(indexOf(list, &c) == 2);
	assert(indexOf(list, &b) == 1);
	free(node1); free(node2); free(node3);
}

void test_indexOf_returns_minus_1_of_when_given_integer_is_not_in_the_list(){
	int a = 12, b = 34, c = 4;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(indexOf(list, &c) == -1);
	free(node1); free(node2); 
}

void test_indexOf_returns_the_first_index_of_given_float_data_reference(){
	float a = 12.4, b = 3.4, c = 4.8;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(indexOf(list, &a) == 0);
	assert(indexOf(list, &c) == 2);
	assert(indexOf(list, &b) == 1);
	free(node1); free(node2); free(node3);
}

void test_indexOf_returns_minus_1_of_when_given_floating_value_is_not_in_the_list(){
	float a = 12.2, b = 3.4, c = 4.6;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(indexOf(list, &c) == -1);
	free(node1); free(node2); 
}


void test_indexOf_returns_the_first_index_of_given_character_data_reference(){
	char a = 'v', b = 'i', c = 'k';
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(indexOf(list, &a) == 0);
	assert(indexOf(list, &c) == 2);
	assert(indexOf(list, &b) == 1);
	free(node1); free(node2); free(node3);
}

void test_indexOf_returns_minus_1_of_when_given_charing_value_is_not_in_the_list(){
	char a = 'v', b = 'i';
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	add_to_list(&list,node1);

	assert(indexOf(list, &b) == -1);
	free(node1); 
}


void test_indexOf_returns_the_index_of_given_double_data_reference(){
	double a = 12.4, b = 3.4, c = 4.8;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &a), 0);
	assertEqual(indexOf(list, &b), 1);
	assertEqual(indexOf(list, &c), 2);
	free(node1); free(node2); free(node3);
}

void test_indexOf_returns_minus_1_of_when_given_double_value_is_not_in_the_list(){
	double a = 12.2, b = 3.4, c = 14.6;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list, node1);
	add_to_list(&list, node2);

	assertEqual(indexOf(list, &c), -1);
	free(node1); free(node2); 
}


void test_deleteElementAt_deletes_the_element_at_given_index_and_returns_the_deleted_data_reference(){
	double a = 12.4, b = 3.4, c = 4.8;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(indexOf(list, &b) == 1);
	assert(indexOf(list, &c) == 2);
	assert(list.count == 3);
	assert((*node1).next == node2);
	assert((*node2).next == node3);
	assert((*node3).next == NULL);
	assert(*(double*)deleteElementAt(&list, 1) == 3.4);
	
	assert(indexOf(list, &b) == -1);
	assert(indexOf(list, &c) == 1);
	assert(areEqual(*list.head, *node1)== 1);
	assert(areEqual(*list.tail, *node3)== 1);
	assert(list.count == 2);
	assert((*node1).next == node3);
	// assert((*node2).next == node3);
	assert((*node3).next == NULL);
	free(node1); free(node2); free(node3);
}

void test_deleteElementAt_deletes_the_tail_and_makes_tails_previous_element_as_tail_of_the_given_list(){
	double a = 12.4, b = 3.4, c = 4.8, d = 22.2;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	assert(list.count == 4);
	assert(indexOf(list, &d)==3);
	assert(indexOf(list, &c)==2);
	assert((*node3).next == node4);
	assert(areEqual(*list.tail, *node4) == 1);
	assert(*(double*)deleteElementAt(&list, 3) == 22.2);
	
	assert(areEqual(*list.head, *node1)	== 1);
	assert(areEqual(*list.tail, *node3) == 1);
	assert(list.count == 3);
	assert(indexOf(list, &d) == -1);
	assert(indexOf(list, &c) == 2);
	assert((*node3).next == NULL);
	free(node1); free(node2); free(node3); free(node4);
}

void test_deleteElementAt_deletes_the_head_and_makes_heads_next_element_as_head_of_the_given_list(){
	double a = 12.4, b = 3.4, c = 4.8, d = 22.2;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	assert(areEqual(*list.head, *node1)	== 1);
	assert(areEqual(*list.head, *node1)	== 1);
	assert(list.count == 4);
	assert(indexOf(list, &d) == 3);
	assert(indexOf(list, &a) == 0);
	assert((*node1).next ==  node2);
	assert(*(double*)deleteElementAt(&list, 0) == 12.4);

	assert(list.count == 3);
	assert(indexOf(list, &d) == 2);
	assert(indexOf(list, &a) == -1);
	assert(areEqual(*list.head, *node2)	== 1);
	assert(areEqual(*list.tail, *node4)== 1);
	// assert((*node1).next ==  node2);
	free(node1); free(node2); free(node3); free(node4);
}

void test_deleteElementAt_returns_NULL_when_negative_index_is_givwn_to_delete(){
	double a = 12.4, b = 3.4;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(areEqual(*list.head, *node1)	== 1);
	assert(areEqual(*list.head, *node1)	== 1);
	assert((double*)deleteElementAt(&list, -3) == NULL);

	free(node1); free(node2);
}

void test_deleteElementAt_returns_NULL_when_given_index_is_greater_than_list_count_to_delete(){
	double a = 12.4, b = 3.4;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(areEqual(*list.head, *node1)	== 1);
	assert(areEqual(*list.head, *node1)	== 1);
	assert(list.count == 2);
	assert((double*)deleteElementAt(&list, 3) == NULL);
	free(node1); free(node2);
}

void test_asArray_populates_int_Array_with_int_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	int a = 4, b = 5, c = 6;
	int **array = (int**)malloc(sizeof(int*)*3);
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(asArray(list, (void**)array) == 3);
	assert(array[0] == &a);
	assert(array[1] == &b);
	assert(array[2] == &c);

	assert(*(int*)(array[0]) == 4);
	assertEqual(*(int*)(array[1]), 5);
	assert(*(int*)(array[2]) == 6);
	free(array);
}

void test_asArray_does_not_populates_int_Array_and_returns_0_when_list_is_empty(){
	int **array = (int**)malloc(sizeof(int*)*3);
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
}

void test_asArray_populates_int_Array_with_float_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	float a = 4.5, b = 5.25, c = 6.5, d = 7.75;
	float **array = (float**)malloc(sizeof(float*)*4);
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	assert(asArray(list, (void**)array) == 4);
	assert(array[0] == &a);
	assert(array[1] == &b);
	assert(array[2] == &c);
	assert(array[3] == &d);

	assert(*(float*)(array[0]) == 4.5);
	assert(*(float*)(array[1]) == 5.25);
	assert(*(float*)(array[2]) == 6.5);
	assert(*(float*)(array[3]) == 7.75);
	free(array);
}

void test_asArray_does_not_populates_float_Array_and_returns_0_when_list_is_empty(){
	float **array = (float**)malloc(sizeof(float*));
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
}

void test_asArray_populates_int_Array_with_char_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	char a = 'x', b = 'y';
	char **array = (char**)calloc(2,sizeof(char*));
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(asArray(list, (void**)array) == 2);
	assert(array[0] == &a);
	assert(array[1] == &b);

	assert(*(char*)(array[0]) == 'x');
	assert(*(char*)(array[1]) == 'y');
	free(array);
}

void test_asArray_does_not_populates_char_Array_and_returns_0_when_list_is_empty(){
	char **array = (char**)malloc(sizeof(char*));
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
}

void test_asArray_populates_int_Array_with_double_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	double a = 4.5, b = 5.25, c = 6.5;
	double **array = (double**)malloc(sizeof(double*)*4);
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assert(asArray(list, (void**)array) == 3);
	assert(array[0] == &a);
	assert(array[1] == &b);
	assert(array[2] == &c);

	assert(*(double*)(array[0]) == 4.5);
	assert(*(double*)(array[1]) == 5.25);
	assert(*(double*)(array[2]) == 6.5);
	free(array);
}

void test_asArray_does_not_populates_double_Array_and_returns_0_when_list_is_empty(){
	double **array = (double**)malloc(sizeof(double*));
	LinkedList list = createList();
	assert(asArray(list, (void**)array) == 0);
	free(array);
}

void test_asArray_populates_int_Array_with_string_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	string a = "wx", b = "yz";
	string **array = (string**)calloc(2,sizeof(string*));
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(asArray(list, (void**)array) == 2);
	assert(array[0] == &a);
	assert(array[1] == &b);

	assert(*(string*)(array[0]) == "wx");
	assert(*(string*)(array[1]) == "yz");
	free(array);
}

void test_asArray_does_not_populates_string_Array_and_returns_0_when_list_is_empty(){
	string **array = (string**)malloc(sizeof(string*));
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
}

int isEven(void *item){
	return (*(int*)item % 2 == 0);
}

void test_filter_filters_the_int_list_and_returns_new_list_of_even_nodes(){
	int a = 4, b = 5, c = 6, d = 7;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);
	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 2);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node3);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &c);

	free(node1); free(node2); free(node3); free(node4);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_int_list(){
	int a = 3, b = 5, c = 9;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

void test_filter_filters_the_long_int_list_and_returns_new_list_of_even_nodes(){
	long int a = 3434232214, b = 545444543, c = 666666666, d = 454544537;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);
	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 2);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node3);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &c);

	free(node1); free(node2); free(node3); free(node4);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_int_list(){
	long int a = 3434232213, b = 545444543, c = 666666667;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}



void test_filter_filters_the_unsigned_int_list_and_returns_new_list_of_even_nodes(){
	unsigned int a = 4, b = 5, c = 6, d = 7;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);
	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 2);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node3);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &c);

	free(node1); free(node2); free(node3); free(node4);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_unsigned_int_list(){
	unsigned int a = 3, b = 5, c = 9;
	LinkedList list = createList();
	list_ptr filtered_list;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	filtered_list = filter(list, isEven);
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}


void test_filter_returns_NULL_when_empty_list_is_passed_to_filter(){
	LinkedList list = createList();
	assert(filter(list, isEven) == NULL);
}


int isGreaterThan10(void *item){
	return (*(float*)item > 10);
}

void test_filter_filters_the_float_list_and_returns_new_list_of_even_nodes(){
	float a = 4.4, b = 5.33, c = 16.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isGreaterThan10;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assert((*filtered_list).count == 1);
 	assert(filtered_list->head == node3);
	assert(filtered_list->tail == node3);
	assert(filtered_list->head->data == &c);
	assert(filtered_list->tail->data == &c);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

void test_filter__returns_empty_list_with_0_count_when_no_match_is_found_in_the_float_list(){
	float a = 4.4, b = 5.33, c = 6.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isGreaterThan10;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}


int isLessThan10(void *item){
	return (*(double*)item < 10);
}

void test_filter_filters_the_double_list_and_returns_new_list_of_even_nodes(){
	double a = 9.9, b = 10, c = 16.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isLessThan10;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 1);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node1);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &a);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_double_list(){
	double a = 14.4, b = 25.33, c = 64.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isLessThan10;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

int isLessThan(void *item){
	return (*(long double*)item < 10);
}


void test_filter_filters_the_long_double_list_and_returns_new_list_of_even_nodes(){
	long double a = 9.9, b = 10, c = 16.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isLessThan;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 1);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node1);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &a);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_long_double_list(){
	long double a = 14.4, b = 25.33, c = 64.8;
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isLessThan;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}


int isCapital(void *item){
	return (*(char*)item >=65 && *(char*)item<=90);
}

void test_filter_filters_the_char_list_and_returns_new_list_of_capital_nodes(){
	char a = 'a', b = 'B', c = 'V';
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isCapital;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 2);
 	assert(filtered_list->head == node2);
	assert(filtered_list->tail == node3);
	assert(filtered_list->head->data == &b);
	assert(filtered_list->tail->data == &c);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_char_list(){
	char a = 'a', b = 'b', c = 'c';
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isCapital;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}


int isEmptyString(void *item){
	return (strlen(*(string*)item) == 0);
}

void test_filter_filters_the_string_list_and_returns_new_list_of_empty_strings(){
	string a = "", b = "", c = "Gdfd", d = "";
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isEmptyString;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	Node *node4 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 3);
 	assert(filtered_list->head == node1);
	assert(filtered_list->tail == node4);
	assert(filtered_list->head->data == &a);
	assert(filtered_list->tail->data == &d);

	free(node1); free(node2); free(node3); free(node4);
	free(filtered_list);
}

void test_filter_returns_empty_list_with_0_count_when_no_match_is_found_in_the_string_list(){
	string a = "fffffffff", b = "sda", c = "eee";
	LinkedList list = createList();
	list_ptr filtered_list;
	int_void predicate = isEmptyString;
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	filtered_list = filter(list, predicate);
	
	assertEqual((*filtered_list).count, 0);
 	assert(filtered_list->head == NULL);
	assert(filtered_list->tail == NULL);

	free(node1); free(node2); free(node3);
	free(filtered_list);
}
