/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:16:02 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/02 21:14:50 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		*root = btree_create_node(item);
	else if (cmpf((*root)->item, item) > 0)
		(*root)->left = btree_insert_data(&((*root)->left), item, cmpf);
	else
		(*root)->right = btree_insert_data(&((*root)->right), item, cmpf);
	return ;
}
