/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:24:46 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 20:24:45 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPCALC_H
# define FT_MAPCALC_H

# include "ft_mapcfg.h"

int		**matrix_init(char **mapc, t_mcfg *mapcfg);

void	matrix_calc(int **mapi, t_mcfg *mapcfg);

void	matrix_print(char **mapc, t_mcfg *mapcfg);

#endif
