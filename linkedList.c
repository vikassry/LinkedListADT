#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList createList(){
	return (LinkedList){NULL, NULL, 0};
}

Node *create_node(void *data){
	node_ptr node = calloc(1, sizeof(Node));
	(*node).data = data;
	(*node).next = NULL;
	return node;
}
