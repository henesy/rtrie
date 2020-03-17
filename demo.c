#include <u.h>
#include <libc.h>
#include "rtrie.h"
#include "util.h"

// Demo usage of rtrie
void
main(int, char*[])
{
	/* List */
	
	print("### List\n");
	
	List *l;
	Node *n;
	Rune *r;
	uint *str = L"Те сакам";
	
	l = list_create();
	
	list_append(l, &str[0]);
	list_append(l, &str[5]);
	list_append(l, &str[1]);
	
	for(n = l->head; n != nil; n = n->next)
		print("→ %C\n", * ((Rune*) n->dat));
	
	assert(l->head != nil);
	assert(l->head->next != nil);
	assert(l->head->next->next != nil);
	assert(l->head->next->next->next == nil);
	
	r = list_remove(l, &str[5], runecomp);
	
	print("← %C\n", *r);

	r = list_remove(l, &str[1], runecomp);
	
	print("← %C\n", *r);
	
	r = list_remove(l, &str[0], runecomp);
	
	print("← %C\n", *r);
	
	assert(l->head == nil);
	
	free(l);

	/* Trie */
	
	print("### Trie\n");

	Trie *t;
	
	t = trie_create();
	
	trie_insert(t, str);
	
	free(t);
	
	/* Done */
	
	print("### Done\n");

	exits(nil);
}
