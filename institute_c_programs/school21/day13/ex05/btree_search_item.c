/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:32:24 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/02 21:25:04 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void*, void *))
{
	if (!root || !data_ref)
		return (NULL);
	if (root->left)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (root->right)
		return (btree_search_item(root->right, data_ref, cmpf));
}
