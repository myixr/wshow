#include <stdlib.h>
#include <string.h>
#include "mem.h"


void *mem_alloc( int size ){
    return malloc( size );
}

void mem_copy( void *dest, const void *src, int size ){
    memcpy( dest, src, size );
}
