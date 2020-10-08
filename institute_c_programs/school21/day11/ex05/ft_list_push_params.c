/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:47:34 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/29 20:25:22 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*tmp;
	t_list	*spisok;

	spisok = NULL;
	if (1 == ac)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		tmp = ft_create_elem(av[i++]);
		tmp->next = spisok;
		spisok = tmp;
	}
	return (spisok);
}
