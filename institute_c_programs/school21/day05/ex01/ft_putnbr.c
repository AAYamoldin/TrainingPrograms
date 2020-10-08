/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:53:17 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/09 13:03:35 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int number;

	if (nb == -2147483648)
	{
		nb = -214748364;
		ft_putnbr(nb);
		ft_putchar('8');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		number = -nb;
		ft_putnbr(number);
	}
	else
	{
		if (nb < 10)
			return (ft_putchar(nb + '0'));
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}
