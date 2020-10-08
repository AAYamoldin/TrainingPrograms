/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:42:29 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/08 16:41:43 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	risovanie(int x, int y, int s_col, int s_str);

void	rush(int x, int y)
{
	int s_col;
	int s_str;

	s_col = 1;
	s_str = 1;
	risovanie(x, y, s_col, s_str);
}

void	risovanie(int x, int y, int s_col, int s_str)
{
	if (x <= 0 || y <= 0)
		return ;
	while (s_str <= y)
	{
		while (s_col <= x)
		{
			if ((s_col == 1) && (s_str == 1 || s_str == y))
				ft_putchar('A');
			else if ((s_col == x) && (s_str == 1 || s_str == y))
				ft_putchar('C');
			else if ((s_col != 1 || s_col != x) && s_str == 1)
				ft_putchar('B');
			else if ((s_col != 1 || s_col != x) && s_str == y)
				ft_putchar('B');
			else if ((s_col == 1 || s_col == x) && (s_str != 1 || s_str != y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			s_col++;
		}
		ft_putchar('\n');
		s_col = 1;
		s_str++;
	}
}
