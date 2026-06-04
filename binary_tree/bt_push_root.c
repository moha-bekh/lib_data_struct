#include "btree.h"

t_btree	*bt_push_root_r(t_btree *tree, t_btree *new)
{
	if (!tree)
		return (new);
	if (!new)
		return (tree);
	new->right = tree;
	tree->root = new;
	return (new);
}

t_btree	*bt_push_root_l(t_btree *tree, t_btree *new)
{
	if (!tree)
		return (new);
	if (!new)
		return (tree);
	new->left = tree;
	tree->root = new;
	return (new);
}
