#ifndef BTREE_H
# define BTREE_H

# include <stdlib.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_btree	*root;
	void			*ptr;
}	t_btree;

t_btree	*bt_create(void *ptr);

t_btree	*bt_push_root_r(t_btree *tree, t_btree *new);
t_btree	*bt_push_root_l(t_btree *tree, t_btree *new);

t_btree	*bt_push_right(t_btree *tree, t_btree *new);
t_btree	*bt_push_left(t_btree *tree, t_btree *new);

t_btree	*bt_join(t_btree *left, t_btree *root, t_btree *right);

void	bt_clear(t_btree **tree, void (*del)(void *));

#endif
