/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 12:08:31 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 23:09:37 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if ((power == 0) && (nb == 0))
		return (0);
	if (power == 0)
		return (1);
	if (power < 0)
		result = 0;
	while (power >= 1)
	{
		result = result * nb;
		--power;
	}
	return (result);
}
