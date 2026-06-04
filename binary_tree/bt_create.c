#include "btree.h"

t_btree	*bt_create(void *ptr)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	*node = (t_btree){0};
	node->ptr = ptr;
	return (node);
}
