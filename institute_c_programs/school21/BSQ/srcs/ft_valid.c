/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:34:59 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 20:43:27 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mapcfg.h"
#include "ft_valid.h"

int		valid_map(char *fn, t_mcfg *mapcfg)
{
	int		f_str_len;
	
	f_str_len = take_first_string_len(fn);
	if (!f_valid(take_first_str(fn, f_str_len), f_str_len, mapcfg))
		return (0);
	take_map_as_array(take_map_as_str(fn), mapcfg);
	valid_map_array(mapcfg);
	return (mapcfg->h != 0 ? 1 : 0);
}
