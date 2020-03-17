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
	int i;
	Node* new = ecalloc(1, sizeof(Node));
	new->dat = p;
	new->next = nil;
	Node* n = l->head;
	
	if(l->size == 0){
		l->head = new;
		new->next = nil;
		l->size++;
		return;
	}

	for(i = 0; i < l->size; i++){
		if(i != l->size-1)
			n = n->next;
	}
	
	n->next = new;
	new->next = nil;
	l->size++;
	return;
	
}

// Search → delete from a list ;; return the datum stored
// O(n) runtime
void*
list_remove(List* l, void* tofind, int(*comp)(void *, void *))
{
	int i;
	void* dat = nil;
	Node* n = l->head;
	Node* prev = nil;
	
	if(l->size == 0){
		return dat;
	}

	for(i = 0; i < l->size; i++){
		if((*comp)(n->dat, tofind)){
			if(l->size == 1){
				// 1 node
				dat = n->dat;
				free(n);
				l->head = nil;
			}else if(i == 0){
				// 0 nodes
				l->head = n->next;
				dat = n->dat;
				free(n);
			}else if(i == l->size-1){
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
			l->size--;
			return dat;
		}
		
		prev = n;
		if(i != l->size-1)
			n = n->next;
			
	}
	return dat;
}
