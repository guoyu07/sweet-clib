#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*
 * list elements
 */
typedef struct ListElmt_ {
	void				*data;
	struct	ListElmt_	*next;
} ListElmt;

/**
 * lists
 **/
typedef struct List_ {
	int			size;
	int			(*match)(const void *key1, const void *key2);
	void		(*destroy)(void *data);

	ListElmt	*head;
	ListElmt	*tail;
} List;

/**
  * sweet list key value
  **/
typedef struct SweetListKv_ {
	char *key;
	char *value;
} SweetListKv;

/**
 *
 * public Interface
 *
 **/
void list_init(List *list, void (destroy)(void *data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_is_head(list, element)	((element) == (list)->head ? 1 : 0)

#define list_is_tail(element)	((element)->next == NULL ? 1 : 0)

#define list_data(element)	((element)->data)

#define list_next(elements)	((element)->next)

#endif
