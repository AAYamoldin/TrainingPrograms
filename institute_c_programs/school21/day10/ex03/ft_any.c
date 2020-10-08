/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:57:59 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/28 20:04:14 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char *))
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
