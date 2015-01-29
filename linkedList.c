#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


void print_list(LinkedList list){
	node_ptr walker = list.head;
	int i=0; 
	while(walker != NULL){
		printf("Node%d-> %d \n", ++i, *(int*)(*walker).data);
		walker = walker->next;
	}
	printf("Total Nodes: %d\n",list.count);
}


LinkedList createList(){
	return (LinkedList){NULL, NULL, 0};
}

Node *create_node(void *data){
	node_ptr node = calloc(1, sizeof(Node));
	(*node).data = data;
	(*node).next = NULL;
	return node;
}

int add_to_list(LinkedList *list, Node *item){
	if((*list).head == NULL)
		(*list).head = item;
	else
		(*(*list).tail).next = item;
	(*list).tail = item;
	(*item).next = NULL;
	(*list).count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return (*(list.head)).data;
}

void *get_last_element(LinkedList list){
	return (*(list.tail)).data;
}

void traverse(LinkedList list, void (*fun)(void *data)){
	while(list.head != NULL){
		fun((*list.head).data);
		list.head = (*list.head).next;
	}
}