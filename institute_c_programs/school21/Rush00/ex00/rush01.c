/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 20:29:56 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/08 21:00:04 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	risovanie(int x, int y, int st_x, int st_y);

void	rush(int x, int y)
{
	int st_x;
	int st_y;

	if (x <= 0 || y <= 0)
		return ;
	st_x = 1;
	st_y = 1;
	risovanie(x, y, st_x, st_y);
}

void	risovanie(int x, int y, int st_x, int st_y)
{
	while (st_y <= y)
	{
		while (st_x <= x)
		{
			if ((st_x == 1 && st_y == 1) || (st_y == y && st_x == x))
				ft_putchar('/');
			else if ((st_y == 1 && st_x == x) || (st_y == y && st_x == 1))
				ft_putchar('\\');
			else if ((st_y == 1 || st_y == y) && (st_x != 1 || st_x != x))
				ft_putchar('*');
			else if ((st_x == 1 || st_x == x) && (st_y != 1 || st_y != y))
				ft_putchar('*');
			else
				ft_putchar(' ');
			st_x++;
		}
		ft_putchar('\n');
		st_x = 1;
		st_y++;
	}
}
