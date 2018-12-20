/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/20 12:59:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	*ft_mapgenerator(void)
{
	unsigned int	*map;

	if (!(map = (unsigned int*)ft_memalloc(sizeof(unsigned int) * ROW_NB)))
		return (NULL);
	return (map);
}

static char			ft_mapminsize(unsigned char nb_tetri)
{
	unsigned short	nb_bits;
	unsigned char	i;

	nb_bits = nb_tetri * 4;
	i = 4;
	while (nb_bits > i * i)
	{
		++i;
		if (nb_bits == i * i)
			return (i);
	}
	return (i);
}

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

static char			tetri_feeder(t_lst **tab, unsigned int *map, unsigned char nb_tetri, char map_nb)
{
	static int	n = 0;
	int res;

	res = 0;
	while (n < nb_tetri)
	{
		printf("tetri n %d\n", n);
		printf("map size %d\n", (int)map_nb);
//		printf("tetri x %d\n", (int)(*tab)[(int)n].x);
//		printf("tetri y %d\n", (int)(*tab)[(int)n].y);
//		printf("tetri width %d\n", (int)(*tab)[(int)n].width);
//		printf("tetri height %d\n", (int)(*tab)[(int)n].height);
//		printf("tetri [0]value %d\n", (*tab)[(int)n].tetri[0]);
//		printf("tetri [1]value %d\n", (*tab)[(int)n].tetri[1]);
//		printf("tetri [2]value %d\n", (*tab)[(int)n].tetri[2]);
//		printf("tetri [3]value %d\n", (*tab)[(int)n].tetri[3]);
		res = (int)ft_position_y(tab, map, n, map_nb);
		printf("retour: %d\n", res);
//		printf("tetri new x %d\n", (int)(*tab)[(int)n].x);
//		printf("tetri new y %d\n\n", (int)(*tab)[(int)n].y);
	printBits(sizeof(map[0]), &map[0]);
	printBits(sizeof(map[1]), &map[1]);
	printBits(sizeof(map[2]), &map[2]);
	printBits(sizeof(map[3]), &map[3]);
	printBits(sizeof(map[4]), &map[4]);
	printBits(sizeof(map[5]), &map[5]);
	printBits(sizeof(map[6]), &map[6]);
	printBits(sizeof(map[7]), &map[7]);
	printBits(sizeof(map[8]), &map[8]);
	printBits(sizeof(map[9]), &map[9]);
	printBits(sizeof(map[10]), &map[10]);
	printBits(sizeof(map[11]), &map[11]);
	printBits(sizeof(map[12]), &map[12]);
	printBits(sizeof(map[13]), &map[13]);
	printBits(sizeof(map[14]), &map[14]);
	printBits(sizeof(map[15]), &map[15]);
	printf("\n");
		if (res)
		{
			--n;
			printf("--n !!!! new n: %d\n", n);
			if (n == -1)
			{
				printf("should before increase\n");
				n = 0;
				return (1);
			}
			else
			{
				ft_placerm(map, (*tab)[(int)n].tetri, (*tab)[(int)n].x);
					printf("DEP\n x: %d\n", (int)(*tab)[(int)n].x);
					printf("->\n x lim: %d\n", ROW_NB - map_nb);
					printf("\n");
				if ((*tab)[(int)n].x > ROW_NB - map_nb)
				{
//					printf("DEP\n x: %d\n", (int)(*tab)[(int)n].x);
//					printf("->\n x lim: %d\n", ROW_NB - (*tab)[(int)n].width);
					(*tab)[(int)n].x -= 1;
					return (tetri_feeder(tab, map, nb_tetri, map_nb));
				}
				else if ((*tab)[(int)n].y < map_nb - (*tab)[(int)n].height)
				{
					(*tab)[(int)n].y += 1;
					(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
					return (tetri_feeder(tab, map, nb_tetri, map_nb));
				}
				else
				{
					printf("WTF\n");
					return (1);
				}
			}
		}
		else
		{
			++n;
	//		printf("next tetri n %d\n", n);
		}
	}
	return (0);
}

void				backtracking(t_lst **tab, unsigned char nb_tetri)
{
	unsigned int	*map;
	char			map_nb;
	char			test = 0;
	char			n;

	n = 0;
	map = ft_mapgenerator();
	map_nb = ft_mapminsize(nb_tetri);
	while ((test = tetri_feeder(tab, map, nb_tetri, map_nb)) && map_nb < ROW_NB)
	{
		n = -1;
		while (++n < nb_tetri)
		{
			(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
			(*tab)[(int)n].y = 0;
		}
		free(map);
		map = ft_mapgenerator();
		++map_nb;
		printf("MAP++\n");
	}
	printf("map final size: %d\n", (int)map_nb);
	printf("0 OK, 1 KO: %d\n", (int)test);
	printBits(sizeof(map[0]), &map[0]);
	printBits(sizeof(map[1]), &map[1]);
	printBits(sizeof(map[2]), &map[2]);
	printBits(sizeof(map[3]), &map[3]);
	printBits(sizeof(map[4]), &map[4]);
	printBits(sizeof(map[5]), &map[5]);
	printBits(sizeof(map[6]), &map[6]);
	printBits(sizeof(map[7]), &map[7]);
	printBits(sizeof(map[8]), &map[8]);
	printBits(sizeof(map[9]), &map[9]);
	printBits(sizeof(map[10]), &map[10]);
	printBits(sizeof(map[11]), &map[11]);
	printBits(sizeof(map[12]), &map[12]);
	printBits(sizeof(map[13]), &map[13]);
	printBits(sizeof(map[14]), &map[14]);
	printBits(sizeof(map[15]), &map[15]);
	printBits(sizeof(map[16]), &map[16]);
	printBits(sizeof(map[17]), &map[17]);
	printBits(sizeof(map[18]), &map[18]);
	printBits(sizeof(map[19]), &map[19]);
	printBits(sizeof(map[20]), &map[20]);
	printBits(sizeof(map[21]), &map[21]);
	printBits(sizeof(map[22]), &map[22]);
	printBits(sizeof(map[23]), &map[23]);
	printBits(sizeof(map[24]), &map[24]);
	printBits(sizeof(map[25]), &map[25]);
	printBits(sizeof(map[26]), &map[26]);
	printBits(sizeof(map[27]), &map[27]);
	printBits(sizeof(map[28]), &map[28]);
	printBits(sizeof(map[29]), &map[29]);
	printBits(sizeof(map[30]), &map[30]);
	printBits(sizeof(map[31]), &map[31]);
	printf("\n");
	free(map);
	free(*tab);
}
