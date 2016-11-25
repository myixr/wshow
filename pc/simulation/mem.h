#ifndef _H_MEM_
#define _H_MEM_

#include <stdint.h>

void *mem_alloc( int size );
void mem_copy( void *dest, const void *src, int size );

#endif
