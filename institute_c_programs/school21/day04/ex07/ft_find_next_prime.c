/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:33:59 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 22:42:19 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int delitel;
	int bili;

	bili = 2;
	while (--bili)
	{
		if ((nb == 1) || (nb == 0))
			return (nb);
		if (nb % 2 == 0)
			nb++;
		else
		{
			delitel = 3;
			while (delitel <= nb / 2)
			{
				if (nb % delitel == 0)
					bili = 2;
				delitel = delitel + 2;
			}
		}
		nb++;
	}
	return (nb - 1);
}
