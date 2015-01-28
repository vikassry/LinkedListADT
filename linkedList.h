typedef struct node Node;
typedef Node* node_ptr;
typedef struct linkedList LinkedList;
typedef LinkedList* list_ptr;

typedef char* string;

struct node {
	void *data;
	node_ptr next;
};

struct linkedList{
	node_ptr head;
	node_ptr tail;
	int count;
};

LinkedList createList(void);
Node *create_node(void *data);