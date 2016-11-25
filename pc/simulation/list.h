#ifndef _H_LIST_
#define _H_LIST_

#include <stdio.h>
#include <math.h>

#define offsetof( type, member ) ((size_t) &((type *)0)->member )  
#define ELEM_OF_NODE(type,member,ptr) ((type*)( (char*)ptr-offsetof(type,member) ))

typedef struct ListNode{
    struct ListNode *next;
} list_node_t;
typedef struct ListNode *list_head_t;

#ifdef __cplusplus
extern "C"{
#endif

void list_init( list_head_t *list );
void list_append( list_head_t list, list_node_t *node );
void list_destroy( list_head_t *list );
void list_foreach( list_head_t list, void(fun)(list_node_t*) );
void list_sort( list_head_t list, int (cmp)(list_node_t *,list_node_t*) );
list_node_t *list_next( list_node_t *node );

#ifdef __cplusplus
}
#endif

#endif
