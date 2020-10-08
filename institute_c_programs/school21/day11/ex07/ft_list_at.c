/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:56:48 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/30 10:54:47 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*p;
	unsigned int	index;

	if (begin_list == NULL)
		return (NULL);
	p = begin_list;
	index = 0;
	while (p != NULL)
	{
		if (nbr == index)
			return (p);
		p = p->next;
		index++;
	}
	return (NULL);
}
