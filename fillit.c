/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:27:22 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/05 18:04:02 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int		ft_check_line(char *line, int *sharp)
{
	char *ptr;

	ptr = line;
	if (ft_strlen(line) != 4)
		return (0);
	while (*ptr)
	{
		if (*ptr != '#' && *ptr != '.')
			return (0);
		if (*ptr == '#')
			*sharp = *sharp + 1;
		ptr++;
	}
	return (1);
}

int		check_error_pieces(int fd)
{
	int i;
	int ret;
	char *line;
	int nb_sharp;
	t_bool end;

	end = false;
	while (!end)
	{
		nb_sharp = 0;
		i = 0;
		while (i < 4)
		{
			if ((ret = get_next_line(fd, &line) <= 0) || !(ft_check_line(line, &nb_sharp)))
			{
				if (ret == -1)
					ft_putendl("Mallocs error");
				return (0);
			}
			i++;
		}
		if ((nb_sharp != 4) || (ret = get_next_line(fd, &line) && *line))
		{
			if (ret == -1)
				ft_putendl("Mallocs error");
			return (0);
		}
		if (!ret)
			end = true;
	}
	return (1);
}
