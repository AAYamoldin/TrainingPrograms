/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:19:39 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/29 14:51:29 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *p;
	t_list *tmp;

	p = *begin_list;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		tmp = ft_create_elem(data);
		p->next = tmp;
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
	p = *begin_list;
}
