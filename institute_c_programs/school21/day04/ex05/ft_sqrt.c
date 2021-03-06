/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:32:17 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 20:32:00 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int a;

	a = 0;
	if (nb == 1)
		return (1);
	if (nb == 4)
		return (2);
	while (a <= nb / 3)
	{
		if ((nb - a * a) == 0)
			return (a);
		a++;
	}
	return (0);
}
