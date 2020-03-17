/* Supporting routines for data structures */

// Calloc with sysfatal on an error
extern void*	ecalloc(ulong, ulong);

// Comparator for runes in a List ;; returns true if runes match exactly
extern int		runecomp(void*, void*);
