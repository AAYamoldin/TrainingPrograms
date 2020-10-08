/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:30:55 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 21:49:22 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_valid.h"

int		strlenn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		take_first_string_len(char *fn)
{
	int		str_len;
	int		fd;
	char	*first_str;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		return (0);
	first_str = (char *)malloc(sizeof(char) * 8000000);
	read(fd, first_str, 4095);
	str_len = strlenn(first_str);
	free(first_str);
	return (str_len);
}

char	*take_first_str(char *fn, int str_len)
{
	char	*first_str;
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		return (NULL);
	first_str = (char *)malloc(sizeof(char) * str_len);
	read(fd, first_str, str_len);
	return (first_str);
}
