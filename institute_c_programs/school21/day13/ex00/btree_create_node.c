/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:49:27 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/02 20:22:26 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tmp;

	tmp = (t_btree*)malloc(sizeof(t_btree));
	if (tmp)
	{
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->item = item;
	}
	return (tmp);
}
