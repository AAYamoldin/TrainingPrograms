/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:22:09 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 21:10:48 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int delitel;

	if ((nb == 1) || (nb == 0))
		return (0);
	if (nb % 2 == 0)
		return (0);
	delitel = 3;
	while (delitel <= nb / 2)
	{
		if (nb % delitel == 0)
			return (0);
		delitel = delitel + 2;
	}
	return (1);
}
