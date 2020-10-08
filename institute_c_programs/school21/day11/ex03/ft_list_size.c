/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:49:13 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/29 17:01:24 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*p;
	int		i;

	p = begin_list;
	i = 0;
	if (p != NULL)
	{
		while (p != NULL)
		{
			p = p->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
