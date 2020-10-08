/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:49:40 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/10 17:01:48 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int lol;

	i = 1;
	while (i <= argc)
	{
		if (argv[i] == '\0')
			return (0);
		lol = 0;
		while (argv[i][lol] != '\0')
		{
			ft_putchar(argv[i][lol]);
			lol++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
