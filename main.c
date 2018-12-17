/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:14 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/17 16:08:41 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int		nb_tetri;
	t_lst_f		*first;
	char 		**tab;
	int			g_tab_size;

	g_tab_size = 2;
	fd = -1;
	first = NULL; 
	nb_tetri = 0;
	tab = NULL;
	if (ac != 2)
		ft_putendl("usage: ./fillit Valid_Tetriminos_File");
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putendl("error");
	else if (!(check_entry(fd, &first, &nb_tetri))
	|| !fillit(first, tab, g_tab_size))
	{
		ft_putendl("error");
		close(fd);
	}
	return (0);
}
