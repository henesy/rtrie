/* List (Queue) Architecture */

typedef struct Node Node;
typedef struct List List;

struct Node {
	Node*	next;
	void*	dat;
};

struct List {
	Node*	head;
	int		size;
};

// Create a new list
List*	list_create(void);

// Append to a list
void	list_append(List*, void*);

// Search → delete from a list ;; return datum stored
void*	list_remove(List*, void*, int(*comp)(void *, void *));
