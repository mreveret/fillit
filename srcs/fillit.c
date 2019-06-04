/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:37:33 by machoffa          #+#    #+#             */
/*   Updated: 2019/05/30 17:21:02 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		backtracking(char **map, char ***tab, int k)
{
	int		i;
	int		j;

	i = 0;
	if (tab[k] == 0)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_spaces(map, tab[k], i, j) == 1)
			{
				put_tetri(map, tab[k], i, j);
				if (backtracking(map, tab, k + 1) == 1)
					return (1);
				rm_tetri(map, tab[k], i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	solver(char ***tab, int k)
{
	char	**map;
	int		map_size;

	map = NULL;
	map_size = started_size(k * 4);
	map = clean_map(map_size, map);
	while (!backtracking(map, tab, 0))
	{
		map_size++;
		free_tab(map);
		map = clean_map(map_size, map);
	}
	ft_print_words_tables(map);
	free_tab(map);
}

void	fillit2(char ***tab, int k)
{
	int		l;

	l = 0;
	while (l < k)
	{
		tab[l] = tab_opti3(tab, l);
		tab[l] = tab_opti2(tab, l);
		tab[l] = tab_opti(tab, l);
		l++;
	}
	solver(tab, k);
	return ;
}

void	fillit(int fd, char ***tab)
{
	int		k;
	int		ret;
	int		ret2;
	char	tmp[2];

	k = 0;
	while ((ret2 = globalcheck(fd, tab, k)) == 1)
	{
		ret = read(fd, tmp, 1);
		tmp[1] = '\0';
		k++;
	}
	tab[k] = 0;
	if (ret == 1 || ret2 == -1 || k > 26 || !tab[0])
	{
		ft_putstr("error\n");
		return ;
	}
	fillit2(tab, k);
	return ;
}
