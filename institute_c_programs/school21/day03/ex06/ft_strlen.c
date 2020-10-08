/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:02:25 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/06 22:10:20 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int smeschenie;

	smeschenie = 0;
	while (str[smeschenie] != '\0')
	{
		smeschenie++;
	}
	return (smeschenie);
}
