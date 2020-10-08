/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:24:46 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 18:45:58 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "ft_mapcfg.h"

int		matrix_read_cfg_w(char *fn, t_mcfg *mapcfg);

t_mcfg	*matrix_read_cfg(char *fn);

char	**matrix_read_map(char *fn, t_mcfg *mapcfg);

int		**matrix_init(char **mapc, t_mcfg *mapcfg)

void	matrix_calc(int **mapi, t_mcfg *mapcfg);

void	matrix_print(char **mapc, t_mcfg *mapcfg);

#endif
