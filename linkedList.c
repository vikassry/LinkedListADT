#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


void print_list(LinkedList list){
	node_ptr walker = list.head;
	int i=0; 
	while(walker != NULL){
		printf("Node%d-> %f \n", ++i, *(double*)(*walker).data);
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
	if(item == NULL)
		return 0;
	if((*list).head == NULL)
		(*list).head = item;
	else
		(*(*list).tail).next = item;
	(*list).tail = item;
	(*(*list).tail).next = NULL;
	(*list).count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return (list.head == NULL) ? NULL : (*list.head).data;
}

void *get_last_element(LinkedList list){
	return (list.head == NULL) ? NULL : (*list.tail).data;
}

void traverse(LinkedList list, void (*fun)(void *data)){
	node_ptr walker;
	for (walker = list.head; walker !=NULL; walker = (*walker).next)
		fun((*walker).data);
}

void *getElementAt(LinkedList list, int index){
	int idx = 0;  node_ptr walker;
	for(walker = list.head; walker !=NULL; walker = (*walker).next){
		if(idx == index)  return (*walker).data;
		idx += 1;
	}
	return NULL;
}

int indexOf(LinkedList list, void *item){
	int idx = 0;  node_ptr walker;
	for(walker = list.head; walker !=NULL; walker = (*walker).next){
		if((*walker).data == item) 	return idx;
		idx++;
	}
	return -1;	
}

void *deleteElementAt(LinkedList *list, int index){
	int idx = 0;  node_ptr walker; void *item = calloc(1,sizeof((*(*(*list).head).data)));
	if(index == 0){
		walker = (*list).head;
		(*list).head = (*walker).next;
		(*list).count -= 1;
		return (*walker).data;
	}
	if(index == (*list).count-1){
		item = (*(*list).tail).data;
		for(walker = (*list).head; walker !=NULL; walker = (*walker).next){
			if(idx == (*list).count-2){
				(*list).tail = walker;
				(*(*list).tail).next = NULL;
				(*list).count -= 1;
				return item;
			} idx++;
		}
	}
	for(walker = (*list).head; walker !=NULL; walker = (*walker).next){
		if(idx == index-1){
			item = (*(*walker).next).data;
			(*walker).next = (*(*walker).next).next;
			(*list).count -= 1;
			return item;
		} 
		idx += 1;
	}
 	return NULL;
}

int asArray(LinkedList list , void **array){
	// char **arr = (char**)array;
	int index = 0;  node_ptr walker;
	for(walker = list.head; walker !=NULL; walker = (*walker).next){
		// ((char*)*array)[index] = (char*)((*walker).data);
		array[index] = (*walker).data;
		index += 1;
	}
	// *array == (void**)arr;
	return index;
}