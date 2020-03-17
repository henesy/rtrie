#include <u.h>
#include <libc.h>
#include "rtrie.h"
#include "util.h"

/* A utf-8 rune-oriented trie */

// Create and return a new trie
Trie*
trie_create(void)
{
	return ecalloc(1, sizeof (Trie));
}

// Insert a utf-8 string into the trie 
void
trie_insert(Trie *t, uint *runes)
{
	int i;
	long len;
	List *l;
	Node *n;
	
	l = t->root;
	
	len = runestrlen(runes);

	// For each rune
	for(i = 0; i < len; i++){
		// Check if the rune is in the list, laterally
		// If not present, push the rune in to the lateral list
		
		// Descend perpendicularly
	}
}
