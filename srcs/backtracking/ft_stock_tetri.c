/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:12:48 by aquan             #+#    #+#             */
/*   Updated: 2018/12/03 14:38:55 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../../includes/fillit.h"

unsigned short	*ft_stock_tetri(int nb, int fd)
{
	unsigned short *map;
	int i;

	if (!(map = (unsigned short*)malloc(sizeof(*map) * nb)))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		fd = open(argv[1], O_RDONLY);
		read(fd, buf, BUFF_SIZE);
		map[i] = ft_block_to_tetri(buf);
		++i;
		close(fd);
	}
	return (map);
}

