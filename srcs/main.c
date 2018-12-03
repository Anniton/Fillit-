/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/03 16:22:40 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetri_test(unsigned short *tab, int nb) // DEBUGG FT
{
	int	i;
	i = 0;
	while (i < nb)
	{
		printf("elem %d: %d\n", i + 1, tab[i]);
		++i;
	}
}

int		main(int argc, char **argv)
{
	(void)argv;
	int		nb_tetri;
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
			printf("nb of tetri: %d\n", nb_tetri);
			write(1, "Sotckage tetriminos ==> \n", 25); // backtracking algo
			tab_tetri = ft_stock_tetri(nb_tetri, argv[1]);
			print_tetri_test(tab_tetri, nb_tetri);
			map = ft_mapsize(nb_tetri);
			map[0] = 0b00000000;
			map[1] = 0b00000001;
			map[2] = 0b10000000;
			printf("map 0 : %d\n", map[0]);
			printf("map 1 : %d\n", map[1]);
			printf("map 2 : %d\n", map[2]);
		}
	
	free(map);
	free(tab_tetri);
	}
	return (0);
}
