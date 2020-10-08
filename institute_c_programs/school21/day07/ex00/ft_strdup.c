/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:04:23 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/12 21:03:16 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i;
	char*a;
	int dop;

	dop = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	a = (char *)malloc((i + 1) * sizeof(char));
	if (NULL == a)
		return (NULL);
	if (i == 0)
	{
		a[0] = '\0';
		return (a);
	}
	while (dop <= i)
	{
		a[dop] = src[dop];
		dop++;
	}
	return (a);
}
