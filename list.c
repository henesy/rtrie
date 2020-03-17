#include <u.h>
#include <libc.h>
#include "list.h"
#include "util.h"


// Create a new list
List*
list_create(void)
{
	return ecalloc(1, sizeof (List));
}

// Append to the end of a list ;; return node inserted
// O(n) runtime, jfc, just add a tail tracker or prepend
Node*
list_append(List* l, void* d)
{
	if(l == nil)
		return;

	Node* new = ecalloc(1, sizeof(Node));
	new->dat = d;
	new->next = nil;
	Node* n;
	
	// If the list exists, but empty
	if(l->head == nil){
		l->head = new;
		new->next = nil;

		return new;
	}

	// Walk until the end of the list
	for(n = l->head; n->next != nil; n = n->next)
		;
	
	n->next = new;
	new->next = nil;

	return new;
}

// Search → confirm whether a list contains an element ;; return true or false
// O(n) runtime
int
list_contains(List *l, void *tofind, int(*comp)(void *, void *))
{
	Node *n;

	for(n = l->head; n != nil; n = n->next)
		if((*comp)(n->dat, tofind))
			return 1;

	return 0;
}

// Search → return node if found or nil
// O(n) runtime
Node*
list_find(List *l, void *tofind, int(*comp)(void *, void *))
{
	Node *n;

	for(n = l->head; n != nil; n = n->next)
		if((*comp)(n->dat, tofind))
			return n;

	return nil;
}

// Search → delete from a list first match found ;; return the datum stored
// The comparator should return 1 if matched exactly, 0 otherwise
// O(n) runtime
void*
list_remove(List* l, void* tofind, int(*comp)(void *, void *))
{
	void* dat = nil;
	Node* n;
	Node* prev = nil;
	
	// Short-circuit for what would happen anyways
	if(l->head == nil)
		return nil;

	for(n = l->head; n != nil; n = n->next){
		if((*comp)(n->dat, tofind)){
			if(l->head->next == nil){
				// 1 node
				dat = n->dat;
				free(n);
				l->head = nil;

			}else if(n->next == nil){
				// We are the last node
				prev->next = nil;
				dat = n->dat;
				free(n);

			}else{
				// This is probably unsafe?
				prev->next = n->next;
				dat = n->dat;
				free(n);

			}
			return dat;
		}
		prev = n;			
	}

	return dat;
}

// Destroy a list completely, discard any data stored
// Hope this works, mostly untested
// O(n) runtime, I guess
void
list_destroy(List *l)
{
	Node *n;
	List *children;

	// The list isn't allocated
	if(l == nil)
		return;
	
	// There are no nodes allocated, destroy the list container
	if(l->head == nil){
		free(l);
		return;
	}
	
	n = l->head;
	
	free(l);

	if(n->child != nil){
		// Recursively destroy children perpendicularly
		children = list_create();
		children->head = n->child;
		
		list_destroy(children);
		// Note that this frees children
	}
	
	if(n->next != nil){
		// Recursively destroy children laterally
		children = list_create();
		children->head = n->next;
		
		list_destroy(children);
	}
	
	free(n);
	
	return;
}
