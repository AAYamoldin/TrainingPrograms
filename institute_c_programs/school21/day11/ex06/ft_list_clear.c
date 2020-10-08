/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:27:03 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/29 20:50:29 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *next_elem;

	if (begin_list == NULL)
		return (NULL);
	tmp = *begin_list;
	next_elem = tmp->next;
	while (next_elem != NULL)
	{
		free(tmp);
		tmp = next_elem;
		next_elem = next_elem->next;
	}
	return (next_elem);
}
