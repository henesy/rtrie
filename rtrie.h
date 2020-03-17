#include "list.h"

/* A utf-8 rune-oriented trie */

typedef struct Trie Trie;

// Represents a rune-oriented trie
struct Trie {
	List*	root;		// The top level of the trie
};

// Create a new trie
Trie*	trie_create(void);

// Insert a utf-8 string into the trie
void	trie_insert(Trie*, uint*);
