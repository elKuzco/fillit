/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:14 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 18:28:34 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

int        rounded(double nb)
{
	if((nb - (int)nb) == 0)
		return(nb);
	nb++;
	return(nb);
}

int		initial_map_size(int nb)
{
	ft_sqrt(nb);
	return(rounded(nb));
}

int		main(int ac, char **av)
{
	int			fd;
	int			nb_tetri;
	t_lst_f		*first;
	char 		**tab;
	int			g_tab_size;

	g_tab_size = 0;
	fd = -1;
	first = NULL; 
	nb_tetri = 0;
	tab = NULL;
	if (ac != 2)
		ft_putendl("usage: ./fillit Valid_Tetriminos_File");
	else if ((fd = open(av[1], O_RDONLY)) == -1
	|| !(check_entry(fd, &first, &nb_tetri)))
		ft_putendl("error");
	else
	{
		g_tab_size = rounded(2 * ft_sqrt(nb_tetri));
		printf("%i\n", g_tab_size);
		if (!fillit(first, tab, g_tab_size))
			ft_putendl("error");
		free_list(&first);
	}
	close(fd);
	return (0);
}
