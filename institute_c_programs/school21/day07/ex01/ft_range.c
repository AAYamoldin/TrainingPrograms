/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:46:13 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/11 17:42:30 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *a;
	int i;

	if (min >= max)
		return (NULL);
	i = 0;
	a = (int *)malloc((max - min) * sizeof(int));
	if (a == NULL)
		return (NULL);
	while (max - min)
	{
		a[i] = min;
		min++;
		i++;
	}
	return (a);
}
