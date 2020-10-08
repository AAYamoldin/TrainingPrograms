/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:25:13 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/28 22:32:49 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int pos;
	int neg;

	i = 0;
	pos = 0;
	neg = 0;
	if (length < 3 && length >= 0)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			pos++;
		else if (f(tab[i], tab[i + 1]) == 0)
		{
			pos++;
			neg++;
		}
		else
			neg++;
		i++;
	}
	if (neg == length - 1 || pos == length - 1)
		return (1);
	return (0);
}
