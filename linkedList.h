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

void print_list(LinkedList);
LinkedList createList(void);
Node *create_node(void *data);
int add_to_list(LinkedList*, Node*);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);