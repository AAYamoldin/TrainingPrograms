/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcfg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:34:10 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 17:39:37 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPCFG_H
# define FT_MAPCFG_H

typedef struct	s_mcfg
{
	int			w;
	int			h;
	char		e;
	char		o;
	char		f;
	int			max_x;
	int			max_y;
	int			max;
	char		**mapc;
}				t_mcfg;

#endif
