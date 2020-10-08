/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:41:56 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/06 20:57:55 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int celaya_chast;
	int ostatok;

	celaya_chast = a / b;
	ostatok = a % b;
	div = &celaya_chast;
	mod = &ostatok;
}
