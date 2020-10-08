/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 12:50:24 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 18:14:47 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if ((nb == 0) && (power == 0))
		return (0);
	if (power < 0)
		return (0);
	if (0 == power)
		return (1);
	return (nb * ft_recursive_power(nb, (power - 1)));
}
