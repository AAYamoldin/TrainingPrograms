/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:43:52 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/11 19:43:21 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int*));
	if (NULL == arr)
		return (0);
	i = 0;
	while (max - min)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (i);
}
