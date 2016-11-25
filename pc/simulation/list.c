#include <stdio.h>
#include <mem.h>

void list_init( list_head_t *list ){
    (*list) = (list_head_t)mem_alloc( sizeof(list_node_t) );
	(*list)->next = NULL;
}

void list_append( list_head_t list, list_node_t *node ){
	if( list==NULL || node==NULL ){ return; }

	list_node_t *p = list;
	while( p && p->next!=NULL ){
		p = p->next;
	}

	p->next = node;
	node->next = NULL;
}

void list_destroy( list_head_t *list ){
	if( list==NULL || *list==NULL ){ return; }

	list_node_t *p = *list;
	list_node_t *p_next = NULL;
	*list = NULL;

	while( p ){
		p_next = p->next;
		free( p );
		p = p_next;
	}
}

void list_foreach( list_head_t list, void(fun)(list_node_t*) ){
	if( list==NULL || fun==NULL ){ return; 
	}
	list_node_t *p = list->next;
	while( p ){
		fun( p );
		p = p->next;
	}
}

void list_sort( list_head_t list, int (cmp)(list_node_t *,list_node_t*) ){
	/* 插入排序 */
	list_node_t *p = NULL;
	list_node_t *q = NULL;
	list_node_t *pre = list->next;
	
	while( pre ){
		p = pre->next;
		if( p == NULL ){ break; }

		/* 将p有序插入到链表中 */
		q = list;
		while( q != p ){
			if( cmp(p,q->next) ){
				pre->next = p->next;
				p->next = q->next;
				q->next = p;
				break;
			}
			q = q->next;
		}
		pre = pre->next;
	}
}

list_node_t *list_next( list_node_t *node ){
	return node->next;
}
