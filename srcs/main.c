/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:53:50 by machoffa          #+#    #+#             */
/*   Updated: 2019/05/30 11:52:15 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**tab[27];

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	fillit(fd, tab);
	close(fd);
	return (0);
}
