#include <u.h>
#include <libc.h>
#include "util.h"

void*
ecalloc(ulong num, ulong elem)
{
	void*	p;
	p = calloc(num, elem);
	
	if(p == nil)
		sysfatal("err: calloc failed - %r");	
	
	return p;
}

// Comparator for runes in a List ;; returns true if runes match exactly
int
runecomp(void *a₀, void *b₀)
{
	if(a₀ == nil || b₀ == nil)
		return 0;

	Rune *a₁ = (Rune*) a₀, *b₁ = (Rune*) b₀;
	
	if(*a₁ == *b₁)
		return 1;
	
	return 0;
}
