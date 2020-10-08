/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:12:51 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/12 21:20:46 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		how_many_words(char *line);
char	**taking_word(int i, int k, char **a, char *str);
int		yslovie_proverki_slova(int i, char *str);
int		in_word(int i, char *str);

char	**ft_split_whitespaces(char *str)
{
	char**a;
	int i;
	int k;

	i = 0;
	k = 0;
	a = (char**)malloc((how_many_words(str) + 1) * sizeof(char*));
	if (NULL == a)
		return (NULL);
	return (taking_word(i, k, a, str));
}

int		in_word(int i, char *str)
{
	int symbols;

	symbols = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		i++;
		symbols++;
	}
	return (symbols);
}

int		yslovie_proverki_slova(int i, char *str)
{
	if ((i == 0) && ((str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
				&& (str[i + 1] != '\n' && str[i + 1] != '\n'
					&& str[i + 1] != '\t')))
		return (1);
	else if ((str[i - 1] == ' ' || str[i - 1] == '\n'
				|| str[i - 1] == '\t')
			&& (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
		return (1);
	else
		return (0);
}

char	**taking_word(int i, int k, char **a, char *str)
{
	int j;

	while (str[i] != '\0')
	{
		if (yslovie_proverki_slova(i, str))
		{
			a[k] = (char*)malloc((in_word(i, str) + 1) * sizeof(char));
			if (NULL == a[k])
				return (NULL);
			j = 0;
			while (str[i] != ' ' && str[i] != '\n'
					&& str[i] != '\t' && str[i] != '\0')
			{
				a[k][j++] = str[i++];
			}
			a[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	a[k] = (char*)malloc(2 * sizeof(char));
	a[k][0] = '0';
	return (a);
}

int		how_many_words(char *line)
{
	int total;
	int i;

	i = 0;
	total = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (yslovie_proverki_slova(i, line))
			total++;
		i++;
	}
	return (total);
}
