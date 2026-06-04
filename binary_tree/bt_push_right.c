#include "btree.h"

t_btree	*bt_push_right(t_btree *tree, t_btree *new)
{
	if (!tree)
		return (new);
	if (!new)
		return (tree);
	tree->right = new;
	new->root = tree;
	return (tree);
}
