/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:09:10 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 21:48:38 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_valid.h"

void		take_map_as_array(char *str, t_mcfg *mapcfg)
{
	int		i;
	int		row;
	int		col;
	char	**map;
	
	map = (char **)malloc(sizeof(char*) * 8000000);
	i = 0;
	row = 0;
	col = 0;
	mapcfg->w = strlenn(str);
	map[row] = (char *)malloc(sizeof(char) * 8000000);
	while(str[i] != '\0')
	{
		if (str[i] == '\n' && str[i+1] != '\0')
		{
			if (mapcfg->w != col)
			{
				mapcfg->h = 0;
				return ;
			}
			map[++row] = (char *)malloc(sizeof(char) * 8000000);
			col = 0;
			i++;
		}
		else
			map[row][col++] = str[i++];
	}
	mapcfg->mapc = map;
	if (mapcfg->h != (row + 1))
	{
		mapcfg->h = 0;
		return ;
	}
	mapcfg->h = row + 1;
	free(map);
}

void		valid_map_array(t_mcfg *mapcfg)
{
	int row;
	int col;
	char **map;
	
	row = -1;
	col = -1;
	if (mapcfg->h == 0)
		return ;
	map = mapcfg->mapc;
	while(++row < mapcfg->h)
	{
		while (++col < mapcfg->w)
		{
			if(map[row][col] != mapcfg->e && map[row][col] != mapcfg->o
					&& map[row][col] != '\n')
			{
				mapcfg->h = 0;
				return ;
			}
		}
		col = -1;
	}
}
