/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:31:43 by mjennine          #+#    #+#             */
/*   Updated: 2020/09/28 18:57:18 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *array;

	i = 0;
	array = (int*)malloc(length * sizeof(int));
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
