/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:54:41 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 20:01:36 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_fun.h"
#include "ft_mapcfg.h"
#include "ft_mapinit.h"


int			matrix_read_cfg_w(char *fn, t_mcfg *mapcfg)
{
	int		fd;
	int		ret;
	char	buf[2];
	int		cx;

	cx = 0;
	fd = open(fn, O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (*buf == '\n')
			ret = 0;
	}
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (*buf == mapcfg->e || *buf == mapcfg->o)
			cx++;
		else if (*buf == '\n')
			ret = 0;
	}
	close(fd);
	return (cx);
}

void	matrix_seteof(t_mcfg *mapcfg, char e, char o, char f)
{
	mapcfg->e = e;
	mapcfg->o = o;
	mapcfg->f = f;
}

t_mcfg		*matrix_read_cfg(char *fn)
{
	int		fd;
	int		ret;
	char	buf[1024 + 1];
	int		i;
	t_mcfg	*mapcfg;

	mapcfg = NULL;
	fd = open(fn, O_RDONLY);
	mapcfg = (t_mcfg *)malloc(sizeof(t_mcfg));
	if (mapcfg)
	{
		ret = read(fd, buf, 1024);
		if (ret)
		{
			mapcfg->h = my_atoi(buf);
			i = 0;
			while (buf[i] >= '0' && buf[i] <= '9')
				i++; //123132321map
			matrix_seteof(mapcfg, buf[i + 0], buf[i + 1], buf[i + 2]);
		}
		close(fd);
		mapcfg->w = matrix_read_cfg_w(fn, mapcfg);
	}
	close(fd);
	return (mapcfg);
}

char		**matrix_read_map(char *fn, t_mcfg *mapcfg)
{
	int		fd;
	int		ret;
	char	*buf;
	int		r;
	char	**mapc;

	buf = (char *)malloc(sizeof(char) * (mapcfg->w + 2));
	mapc = (char **)malloc(sizeof(char *) * mapcfg->h);
	fd = open(fn, O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (*buf == '\n')
			ret = 0;
	}
	ret = 1;
	r = 0;
	while (r < mapcfg->h)
	{
		mapc[r] = (char *)malloc(sizeof(char) * mapcfg->w);
		ret = read(fd, buf, mapcfg->w + 1);
		ft_strncpy(mapc[r], buf, mapcfg->w); // CHEAT !!!
		r++;
	}
	close(fd);
	free(buf);
	return (mapc);
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
