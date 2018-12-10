/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:14 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/10 21:16:52 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			nb_tetri;
	t_lst_f		*first;

	fd = -1;
	first = NULL; 
	nb_tetri = 0;
	if (ac != 2)
		ft_putendl("usage: ./fillit Valid_Tetriminos_File");
	else if ((fd = open(av[1], O_RDONLY)) == -1
	|| !(check_entry(fd, &first, &nb_tetri)))
		ft_putendl("error");
	fillit(first, nb_tetri);
	return (0);
}
