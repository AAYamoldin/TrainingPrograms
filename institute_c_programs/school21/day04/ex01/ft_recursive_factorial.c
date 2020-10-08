/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:30:23 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/07 15:06:35 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (0 == nb)
		return (1);
	if ((nb > 12) || (nb < 0))
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
