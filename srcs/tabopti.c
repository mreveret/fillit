/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabopti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:48 by machoffa          #+#    #+#             */
/*   Updated: 2019/05/30 11:46:02 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count_word(char *s, char c)
{
	int i;
	int j;

	i = 0;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (1);
		i++;
	}
	return (0);
}

char	**tab_opti(char ***tab, int k)
{
	int		i;
	int		l;
	char	**opti;

	opti = (char**)malloc(sizeof(char*) * 5);
	i = 0;
	l = 0;
	while (tab[k][i])
	{
		if (count_word(tab[k][i], '.') == 0)
			i++;
		else
		{
			opti[l] = ft_strdup(tab[k][i]);
			i++;
			l++;
		}
	}
	cp_tab(opti,tab[k]);
	free_tab(opti);
	return (tab[k]);
}

char	**tab_opti2(char ***tab, int k)
{
	int i;
	int j;

	i = 0;
	while (tab[k][i])
	{
		j = 0;
		while (tab[k][i][j])
		{
			if (tab[k][i][j] == '#')
				tab[k][i][j] = 'A' + k;
			j++;
		}
		i++;
	}
	return (tab[k]);
}

char	**tab_opti4(char ***tab, int k)
{
	int j;
	int l;

	j = ft_strlen(tab[k][0]) - 1;
	l = 0;
	while (tab[k][0][j] == '.' && tab[k][1][j] == '.' && tab[k][2][j] == '.'
			&& tab[k][3][j] == '.')
	{
		l++;
		j--;
	}
	j = ft_strlen(tab[k][0]);
	if (l > 0)
	{
		tab[k][0][j - l] = '\0';
		tab[k][1][j - l] = '\0';
		tab[k][2][j - l] = '\0';
		tab[k][3][j - l] = '\0';
	}
	return (tab[k]);
}

char	**tab_opti3(char ***tab, int k)
{
	int j;
	int l;

	j = 0;
	l = 0;
	while (tab[k][0][j] == '.' && tab[k][1][j] == '.' && tab[k][2][j] == '.'
			&& tab[k][3][j] == '.')
	{
		l++;
		j++;
	}
	tab[k][0] = ft_strsub(tab[k][0], l, ft_strlen(tab[k][0]));
	tab[k][1] = ft_strsub(tab[k][1], l, ft_strlen(tab[k][1]));
	tab[k][2] = ft_strsub(tab[k][2], l, ft_strlen(tab[k][2]));
	tab[k][3] = ft_strsub(tab[k][3], l, ft_strlen(tab[k][3]));
	tab[k] = tab_opti4(tab, k);
	return (tab[k]);
}
