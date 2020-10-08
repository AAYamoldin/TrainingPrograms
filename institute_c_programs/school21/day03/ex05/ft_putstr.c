/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:35:55 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/06 21:46:20 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int smeschenie;

	smeschenie = 0;
	while (str[smeschenie] != '\0')
	{
		ft_putchar(str[smeschenie]);
		++smeschenie;
	}
}
