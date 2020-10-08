/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:51:53 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 20:26:40 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_fun.h"
#include "ft_mapcfg.h"
#include "ft_mapcalc.h"

int		ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

void	matrix_setmax(t_mcfg *mapcfg, int m, int x, int y)
{
	mapcfg->max = m;
	mapcfg->max_x = x;
	mapcfg->max_y = y;
}

int		**matrix_init(char **mapc, t_mcfg *mapcfg)
{
	int **mapi;
	int r;
	int c;

	mapi = NULL;
	r = 0;
	mapi = (int **)malloc(sizeof(int *) * (mapcfg->h + 1));
	while (r < (mapcfg->h + 1) && mapi)
	{
		c = 0;
		mapi[r] = (int*)malloc(sizeof(int) * (mapcfg->w + 1));
		if (mapi[r])
		{
			if (r == 0)
				while (c < (mapcfg->w + 1))
					mapi[r][c++] = 0;
			else
			{
				mapi[r][c++] = 0;
				while (c < (mapcfg->w + 1))
				{
					if (mapc[r - 1][c - 1] == mapcfg->e)
						mapi[r][c] = 1;
					if (mapc[r - 1][c - 1] == mapcfg->o)
						mapi[r][c] = 0;
					c++;
				}
			}
			r++;
		}
		else
			mapi = NULL;
	}
	return (mapi);
}

void	matrix_calc(int **mapi, t_mcfg *mapcfg)
{
	int r;
	int c;
	int m;

	r = 1;
	mapcfg->max = 0;
	while (r <= mapcfg->h)
	{
		c = 1;
		while (c <= mapcfg->w)
		{
			if (mapi[r][c] == 1)
			{
				m = ft_min(mapi[r][c - 1], mapi[r - 1][c]);
				mapi[r][c] = 1 + ft_min(mapi[r - 1][c - 1], m);
			}
			if (mapi[r][c] > mapcfg->max)
				matrix_setmax(mapcfg, mapi[r][c], c - 1, r - 1);
			c++;
		}
		r++;
	}
}

void	matrix_print(char **mapc, t_mcfg *mapcfg)
{
	int c;
	int r;
	int c0;
	int r0;
	int	l;

	c = 0;
	r = 0;
	l = mapcfg->max;
	c0 = mapcfg->max_x - l;
	r0 = mapcfg->max_y - l;
	while (r < (mapcfg->h))
	{
		while (c < (mapcfg->w))
		{
			if (c > c0 && c <= c0 + l && r > r0 && r <= r0 + l)
				ft_putchar(mapcfg->f);
			else
				ft_putchar(mapc[r][c]);
			c++;
		}
		c = 0;
		r++;
		ft_putchar('\n');
	}
}
