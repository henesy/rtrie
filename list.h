/* List Architecture */

typedef struct Node Node;
typedef struct List List;

struct Node {
	Node*	next;	// Next node laterally
	void*	dat;	// Datum stored in this node
	Node*	child;	// Next node perpendicularly 
};

struct List {
	Node*	head;	// Head of the list, laterally
};

// Create a new list
List*	list_create(void);

// Append to a list
void	list_append(List*, void*);

// Search → delete from a list ;; return datum stored
// The comparator should return 1 if matched exactly, 0 otherwise
void*	list_remove(List*, void*, int(*comp)(void *, void *));
