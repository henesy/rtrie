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
