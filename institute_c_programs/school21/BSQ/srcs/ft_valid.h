/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:37:10 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 20:54:39 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALID_H
# define FT_VALID_H

#include "ft_mapcfg.h"

int		strlenn(char *str);

int 	take_first_string_len(char *fn);

char	*take_first_str(char *fn, int str_len);

int		f_valid(char *str, int f_len, t_mcfg *mapcfg);

char	*take_map_as_str(char *fn);

void	take_map_as_array(char *str, t_mcfg *mapcfg);

void	valid_map_array(t_mcfg *mapcfg);

int		valid_map(char *fn, t_mcfg *mapcfg);

#endif
