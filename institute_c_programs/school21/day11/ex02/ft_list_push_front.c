/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:02:26 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/29 17:22:24 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *p;
	t_list *tmp;

	p = *begin_list;
	tmp = ft_create_elem(data);
	if (p != NULL)
		tmp->next = p;
	else
		*begin_list = tmp;
}
