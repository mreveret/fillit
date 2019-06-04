/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:35:30 by machoffa          #+#    #+#             */
/*   Updated: 2019/05/30 17:40:05 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		final_check(char **tab, int i, int j, int m)
{
	int l;

	l = 0;
	if (i - 1 >= 0 && tab[i - 1][j] && tab[i - 1][j] == '#')
		l++;
	if (tab[i] && tab[i][j - 1] && tab[i][j - 1] == '#')
		l++;
	if (tab[i] && tab[i][j + 1] && tab[i][j + 1] == '#')
		l++;
	if (tab[i + 1] && tab[i + 1][j] && tab[i + 1][j] == '#')
		l++;
	if (l == 0)
		return (0);
	if (l < 2 && (m == 2))
		return (0);
	if (l < 2 && m == 3)
		return (0);
	if (l < 2 && m == 4)
		return (0);
	return (1);
}

int		pos_final_check(char *str, char ***tab, int k)
{
	int		i;
	int		j;
	int		m;
	int		l;

	l = 0;
	m = 0;
	i = -1;
	tab[k] = ft_strsplit(str, '\n');
	while (tab[k][++i] && (j = -1))
		while (tab[k][i][++j])
			if (tab[k][i][j] == '#')
			{
				m++;
				if (m == 1 && !(final_check(tab[k], i, j, m)))
					return (0);
				if (m == 2 && !(final_check(tab[k], i, j, m)))
					l = 1;
				if (m == 3 && l == 1 && !(final_check(tab[k], i, j, m)))
					l = 2;
				if (m == 4 && l == 2 && !final_check(tab[k], i, j, m))
					return (0);
			}
	return (1);
}

int		ft_check_tetri(char *str, char ***tab, int k)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '#')
			j++;
	if (j != 4)
		return (0);
	if (!(pos_final_check(str, tab, k)))
		return (0);
	return (1);
}

int		globalcheck2(char *buff, int j)
{
	int		i;

	i = 0;
	while (buff[i] && (buff[i] == '.' || buff[i] == '#'))
		i++;
	if (i != 4)
		return (-1);
	if (buff[i] == '\n' || buff[i] == '\0')
	{
		if (buff[i] != '\n' && j != 4)
			return (-1);
	}
	return (1);
}

int		globalcheck(int fd, char ***tab, int k)
{
	int		ret;
	int		j;
	char	buff[BUFF_SIZE + 1];
	char	*str;

	j = 0;
	str = NULL;
	if (!(str))
		str = ft_strnew(0);
	while (j < 4 && (ret = read(fd, buff, 5)) > 0)
	{
		buff[ret] = '\0';
		if (globalcheck2(buff, j) == -1)
			return (-1);
		j++;
		str = ft_strjoin_free(str, buff, 1);
		str[ft_strlen(str)] = '\0';
	}
	if (ret == 0)
		return (0);
	if (ft_check_tetri(str, tab, k) == 0)
		return (-1);
	ft_strdel(&str);
	return (1);
}
