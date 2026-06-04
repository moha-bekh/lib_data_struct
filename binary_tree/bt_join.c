#include "btree.h"

t_btree	*bt_join(t_btree *left, t_btree *root, t_btree *right)
{
	if (!root)
		return (NULL);
	root->left = left;
	root->right = right;
	if (left)
		left->root = root;
	if (right)
		right->root = root;
	return (root);
}
