/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:14 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/06 16:40:23 by qlouisia         ###   ########.fr       */
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
	int fd;

	fd = -1;
	if (ac != 2)
	 	ft_putendl("usage: ./fillit Valid_Detriminos_File");
	else if ((fd = open(av[1], O_RDONLY)) == -1 || !check_error_pieces(fd))
		ft_putendl("error");
	while(1);
	return (0);
}
