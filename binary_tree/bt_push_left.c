#include "btree.h"

t_btree	*bt_push_left(t_btree *tree, t_btree *new)
{
	if (!tree)
		return (new);
	if (!new)
		return (tree);
	tree->left = new;
	new->root = tree;
	return (tree);
}
