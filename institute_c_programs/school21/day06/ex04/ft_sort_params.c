/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:00:45 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/10 23:21:33 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		my_strcmp(char *s1, char *s2);
char	**sort(int total, char **s2);
void	writing(int argc, char **str);

int		main(int argc, char **argv)
{
	char **str;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		while (*argv[1] != '\0')
		{
			ft_putchar(*argv[1]);
			ft_putchar('\n');
			return (0);
		}
	}
	str = sort((argc - 2), argv);
	writing(argc, str);
	return (0);
}

void	writing(int argc, char **str)
{
	int i;
	int j;

	i = 1;
	while (i <= (argc - 1))
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			ft_putchar(str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

char	**sort(int total, char **str)
{
	int i;
	int is_perestanovka;
	char*tmp;

	i = 1;
	is_perestanovka = 1;
	while (is_perestanovka)
	{
		is_perestanovka = 0;
		if ((my_strcmp(str[i], str[i + 1]) > 0) && (i <= total))
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			is_perestanovka = 1;
			i = 1;
		}
		else if (i++ < total)
		{
			is_perestanovka = 1;
		}
		else
			break ;
	}
	return (str);
}

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
