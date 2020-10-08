/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinforap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:24:24 by rinforap          #+#    #+#             */
/*   Updated: 2020/03/08 22:08:05 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		body(int x, int y)
{
	int t;

	t = 0;
	if (y - 2 > 0)
	{
		ft_putchar('B');
		while (t < x - 2)
		{
			ft_putchar(' ');
			t++;
		}
		if (x > 1)
			ft_putchar('B');
		ft_putchar('\n');
		body(x, y - 1);
	}
	return (0);
}

void	header(int x)
{
	int t;

	t = 0;
	ft_putchar('A');
	while (t < x - 2)
	{
		ft_putchar('B');
		t++;
	}
	if (x > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	footer(int x)
{
	int t;

	t = 0;
	ft_putchar('C');
	while (t < x - 2)
	{
		ft_putchar('B');
		t++;
	}
	if (x > 1)
		ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	if (x == 1 && y == 1)
		ft_putchar('A');
	else
	{
		if (x > 1 && y == 1)
		{
			header(x);
		}
	}
	if (x == 1 && y > 1)
	{
		header(x);
		body(x, y);
		footer(x);
	}
	if (x > 1 && y > 1)
	{
		header(x);
		body(x, y);
		footer(x);
	}
}
