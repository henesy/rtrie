/* List Architecture */

typedef struct Node Node;
typedef struct List List;

struct Node {
	Node*	next;	// Next node laterally ;; for perpendicular lists, travels perpendicularly
	void*	dat;	// Datum stored in this node
	Node*	child;	// Next node perpendicularly ;; not used by perpendicular lists
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

// Destroy a list completely, discard any data stored
void	list_destroy(List *l);
