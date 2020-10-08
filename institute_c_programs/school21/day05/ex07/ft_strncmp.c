/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:08:25 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/09 23:38:51 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && *s1 != '\0'
			&& *s2 != '\0' && i < n)
	{
		i++;
	}
	if (n == i)
		return (s1[i - 1] - s2[i - 1]);
	return (s1[i] - s2[i]);
}
