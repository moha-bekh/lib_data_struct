/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:26:47 by mbekheir          #+#    #+#             */
/*   Updated: 2024/08/31 16:02:54 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	bt_clear(t_btree **tree, void (*del)(void *))
{
	if (!tree || !*tree)
		return ;
	bt_clear(&(*tree)->left, del);
	bt_clear(&(*tree)->right, del);
	if (del && (*tree)->ptr)
		del((*tree)->ptr);
	free(*tree);
	*tree = NULL;
}
