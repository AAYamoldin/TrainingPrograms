/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:08:10 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 17:30:00 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb > 12)
		return (0);
	if (0 == nb)
		result = 1;
	if (nb > 0)
	{
		while (nb >= 1)
		{
			result = result * nb;
			--nb;
		}
	}
	if (nb < 0)
		result = 0;
	return (result);
}
