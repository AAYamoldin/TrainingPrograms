/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:46:16 by sgerard           #+#    #+#             */
/*   Updated: 2020/10/07 17:24:22 by sgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "ft_keys.h"

#define BUF_KEYS 1024 * 32

int			ft_keyboard(char *fn)
{
	char	buf_k[BUF_KEYS + 1];
	int		ret_k;
	int		fd;

	fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		while ((ret_k = read(0, buf_k, BUF_KEYS)))
		{
			write(fd, buf_k, ret_k);
		}
		close(fd);
		return (1);
	}
	return (0);
}
