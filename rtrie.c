#include <u.h>
#include <libc.h>
#include "rtrie.h"
#include "util.h"

/* A utf-8 rune-oriented trie */

// Comparator for runes in a list
int	runecomp(void*, void*);

// Create and return a new trie
Trie*
trie_create(void)
{
	return ecalloc(1, sizeof (Trie));
}

// Insert a utf-8 string into the trie 
void
trie_insert(Trie *t, uint *characters)
{
	Rune *runes;
	int i;
	long len;
	List *l;
	
	l = t->root;
	
	runes = runesmprint("%S", characters);
	
	len = runestrlen(runes);
	
	//fprint(2, "Len: %ld\nStr: %S\n", len, runes);
	
	// For each rune
	for(i = 0; i < len; i++){
		// Check if the rune is in the list, laterally
		
		// If not present, push the rune in to the lateral list
		
		// Descend perpendicularly
	}
	
	free(runes);
}
