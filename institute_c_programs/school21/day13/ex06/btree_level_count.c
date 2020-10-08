/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:43:07 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/02 22:00:51 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int i_left;
	int i_right;

	i_left = 0;
	i_right = 0;
	if (root != NULL)
	{
		i_left = btree_level_count(root->left);
		i_right = btree_level_count(root->right);
	}
	return (i_left > i_right ? i_left + 1 : i_right + 1);
}
