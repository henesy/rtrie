#include <u.h>
#include <libc.h>
#include "rtrie.h"
#include "util.h"

/* A utf-8 rune-oriented trie */

// Create a new trie
Trie*
trie_create(void)
{
	return ecalloc(1, sizeof (Trie));
}
