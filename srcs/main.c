/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/05 17:48:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetri_test(unsigned short *tab, int nb) // DEBUGG FT
{
	int	i;
	i = 0;
	while (i < nb)
	{
		printf("\telem %d: %d\n", i + 1, tab[i]);
		++i;
	}
}

int		main(int argc, char **argv)
{
	(void)argv;
	int		nb_tetri;
	int		map_min_size;
	unsigned short	*tab_tetri;
	unsigned char	*map;

	nb_tetri = 0;
	tab_tetri = NULL;
	map = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if ((nb_tetri = issamplevalid(argv[1])) == -1)
			write(1, "error\n", 6);
		else
		{
			printf("> Number of tetriminos: %d\n", nb_tetri);
			map_min_size = ft_mapminsize(nb_tetri);
			printf("MAP MIN SIZE %d\n", map_min_size);
			tab_tetri = ft_stock_tetri(nb_tetri, argv[1]);
			print_tetri_test(tab_tetri, nb_tetri);
			write(1, "\n", 1);
			map = ft_mapsize(map_min_size);
			map[0] = 0b10001000;
			map[1] = 0b10001000;
			write(1, "\n>      MAP     <\n\t", 19); // DEBUGG
			ft_printmap(map, map_min_size);
			write(1, "\n", 1);
			write(1, "\n", 1);
		}
	
	free(map);
	free(tab_tetri);
	}
	return (0);
}
