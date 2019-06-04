/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_backtracking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:50:53 by machoffa          #+#    #+#             */
/*   Updated: 2019/05/30 17:13:48 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**clean_map(int count, char **map)
{
	int		i;
	int		j;

	i = 0;
	if (map)
	free_tab(map);
	if (!(map = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		j = 0;
		if (!(map[i] = (char *)malloc(sizeof(char) * (count + 1))))
			return (NULL);
		while (j < count)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

int		started_size(int k)
{
	int		count;

	count = 1;
	while (count * count < k)
		count++;
	if ((count * count) == k)
		return (count);
	else
		return (started_size(k + 1));
}

int		check_spaces(char **map, char **tab, int i, int j)
{
	int		a;
	int		b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		if (!map[i + a])
			return (0);
		while (tab[a][b])
		{
			if (!map[i + a][j + b])
				return (0);
			if (tab[a][b] != '.' && map[i + a][j + b] != '.')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	put_tetri(char **map, char **tab, int i, int j)
{
	int a;
	int b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			if (tab[a][b] != '.')
				map[i + a][j + b] = tab[a][b];
			b++;
		}
		a++;
	}
}

void	rm_tetri(char **map, char **tab, int i, int j)
{
	int a;
	int b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			if (tab[a][b] != '.')
				map[i + a][j + b] = '.';
			b++;
		}
		a++;
	}
}
