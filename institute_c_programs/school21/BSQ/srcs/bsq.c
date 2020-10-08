/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:08:16 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 21:10:31 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "ft_fun.h"
#include "ft_keys.h"
#include "ft_mapcfg.h"
//include "ft_mapinit.h"
#include "ft_valid.h"
#include "ft_mapcalc.h"


#define BUF_SIZE 1024

/*** TEST CHEAT ***/
void	test_printcfg(t_mcfg *mapcfg)
{
	printf("%i - width\n", mapcfg->w);
	printf("%i - height\n", mapcfg->h);
	printf("%c - empty\n", mapcfg->e);
	printf("%c - obstacle\n", mapcfg->o);
	printf("%c - full\n", mapcfg->f);
}

/*** TEST CHEAT ***/
void	test_mapc(char **mapc, t_mcfg *mapcfg)
{
	int	c;
	int	r;

	r = 0;
	while (r < mapcfg->h)
	{
		c = 0;
		while (c <  mapcfg->w)
			printf("%c", mapc[r][c++]);
		printf("\n");
		r++;
	}
	printf("---\n");
}

/*** TEST CHEAT ***/
void	test_mapi(int **mapi, t_mcfg *mapcfg)
{
	int	c;
	int	r;

	r = 0;
	while (r <= mapcfg->h)
	{
		c = 0;
		while (c <= mapcfg->w)
			printf("%i", mapi[r][c++]);
		printf("\n");
		r++;
	}
}

//-----------------------------------------------
int		f_valid(char *str, int f_len, t_mcfg *mapcfg)
{
	char *num;
	int i;

	if (f_len < 4)
		return (0);
	if ((str[f_len - 1] == str[f_len - 2]) || (str[f_len - 1] == str[f_len - 3]) || (str[f_len - 2] == str[f_len - 3]))
		return (0);
	if ((str[f_len - 1] < 32 || str[f_len - 1] > 126)
			|| (str[f_len - 2] < 32 || str[f_len - 2] > 126)
			|| (str[f_len - 3] < 32 || str[f_len - 3] > 126))
		return (0);
	num = (char *)malloc(sizeof(char) * (f_len));
	i = -1;
	while (++i < f_len - 3)
		num[i] = str[i];
	if (ft_atoi(num) <= 0)
		return (0);
	mapcfg->h = ft_atoi(num);
	mapcfg->e = str[f_len - 3];
	mapcfg->o = str[f_len - 2];
	mapcfg->f = str[f_len - 1];
	free(num);
	return (1);
}

//------------------------------------------------
char		*take_map_as_str(char *fn)
{
	char	*buf;
	int		fd;
	int		flag;
	ssize_t	read_bytes;

	buf	= (char *)malloc(sizeof(char) * 8000000);
	fd = open(fn, O_RDONLY);
	if (fd != -1)
	{
		flag = 1;
		while(flag && (read(fd, buf, 1)))
			if (*buf == '\n')
				flag = 0;
		while((read_bytes = read(fd, buf, 8000000)) > 0)
			buf[read_bytes] = '\0';
		return (buf);
		free(buf);
	}
	return (NULL);
}
//-----------------------------------------------

//----------------------------------------------

void	matrix_bsq(t_mcfg *mapcfg)
{
	//t_mcfg	*mapcfg;
	//char	**mapc;
	int		**mapi;

	//printf("read cfg...\n");
	//mapcfg = matrix_read_cfg(fn);
	//printf("print cfg...\n");
	//test_printcfg(mapcfg);
	//printf("read map...\n");
	//mapc = matrix_read_map(fn, mapcfg);
	//printf("init map...\n");
	mapi = matrix_init(mapcfg->mapc, mapcfg);
	//printf("calc map...\n");
	matrix_calc(mapi, mapcfg);
	//printf("print bsq...\n");
	matrix_print(mapcfg->mapc, mapcfg);
	//printf("done\n");
	//free(mapcfg);
	//free(mapcfg->mapc);
	//free(mapi);
}

int	main(int argc, char **args)
{
	int		ac;
	char	*fn;
	t_mcfg	mapcfg;

	if (argc == 1)
	{
		fn = "tmp/bsqmap.tmp";
		ft_keyboard(fn);
		if (valid_map(fn, &mapcfg))
			matrix_bsq(&mapcfg);
		else
			ft_putstr("map error\n");
	}
	else
	{
		ac = 1;
		while(ac < argc)
		{
			if (valid_map(args[ac], &mapcfg))
				matrix_bsq(&mapcfg);
			else
				ft_putstr("map error\n");
			ac++;
			if (ac < argc)
				ft_putstr("\n");
		}
	}
	return (0);
}
