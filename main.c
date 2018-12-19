/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:14 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/19 13:28:02 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

int			main(int ac, char **av)
{
	int			fd;
	int			nb_tetri;
	int			tab_size;
	t_lst_f		*first;
	char		**tab;

	fd = -1;
	nb_tetri = 0;
	first = NULL;
	tab = NULL;
	if (ac != 2)
		ft_putendl("usage: ./fillit Valid_Tetriminos_File");
	else if ((fd = open(av[1], O_RDONLY)) == -1
	|| !(check_entry(fd, &first, &nb_tetri)))
		ft_putendl("error");
	else
	{
		tab_size = initial_map_size(nb_tetri);
		if (!fillit(first, tab, tab_size))
			ft_putendl("error");
	}
	close(fd);
	return (free_list(&first));
}
