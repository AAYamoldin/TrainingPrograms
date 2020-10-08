/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:45:29 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/12 20:00:53 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		how_many_symbols(int num, char **str);
char	*in_string(int argc, char **argv, char *a);

char	*ft_concat_params(int argc, char **argv)
{
	char *a;

	a = (char*)malloc(how_many_symbols(argc, argv) * sizeof(char));
	if (NULL == a)
		return (NULL);
	if (argc == 1)
	{
		a[0] = '\0';
		return (a);
	}
	return (in_string(argc, argv, a));
}

char	*in_string(int argc, char **argv, char *a)
{
	int i;
	int j;
	int str_l;

	i = 1;
	str_l = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			a[str_l] = argv[i][j];
			j++;
			str_l++;
		}
		i++;
		if (i != argc)
			a[str_l++] = '\n';
	}
	return (a);
}

int		how_many_symbols(int num, char **str)
{
	int total;
	int i;
	int j;

	total = 0;
	i = 1;
	while (i < num)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}
