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

// Append to the end of a list
// O(n) runtime, jfc, just add a tail tracker or prepend
void
list_append(List* l, void* p)
{
	if(l == nil)
		return;

	Node* new = ecalloc(1, sizeof(Node));
	new->dat = p;
	new->next = nil;
	Node* n = l->head;
	
	if(l->head == nil){
		l->head = new;
		new->next = nil;
		return;
	}

	for(n = l->head; n->next != nil; n = n->next)
		;
	
	n->next = new;
	new->next = nil;
	return;
	
}

// Search → delete from a list ;; return the datum stored
// The comparator should return 1 if matched exactly, 0 otherwise
// O(n) runtime
void*
list_remove(List* l, void* tofind, int(*comp)(void *, void *))
{
	void* dat = nil;
	Node* n;
	Node* prev = nil;

	if(l->head == nil){
		return nil;
	}

	for(n = l->head; n != nil; n = n->next){
		if((*comp)(n->dat, tofind)){
			if(l->head->next == nil){
				// 1 node
				dat = n->dat;
				free(n);
				l->head = nil;
			}else if(l->head == nil){
				// 0 nodes
				l->head = n->next;
				dat = n->dat;
				free(n);
			}else if(n->next == nil){
				// We are the last node
				prev->next = nil;
				dat = n->dat;
				free(n);
			}else{
				// this is probably unsafe
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
