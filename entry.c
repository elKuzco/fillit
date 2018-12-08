/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:27:22 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/08 15:19:36 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

ssize_t		read_line(int fd, char **str, int n)
{
	char	buff[n];
	ssize_t	ret;
	char 	*tmp;
	char	*tmp2;
	
	ret = read(fd, buff, n);
	buff[ret] = '\0';
	if (!ret)
		return (2);
	if ((ret != 5 && ret != 1) || (ret && buff[n - 1] != '\n'))
		return (0);
	if (n == 5)
	{
		tmp = *str;
		if (!(tmp2 = ft_strndup(buff, n - 1)))
			return (0);
		if (ft_strlen(buff) != 5 || !(*str = ft_strjoin(*str, tmp2))) 
			{
				free(tmp);
				free(tmp2);
				return(0);
			}
		free(tmp);
		free(tmp2);
	}
	return (1);
}

int		ft_check_line(char *str)
{
	char	*ptr;
	int		nb_sharp;

	nb_sharp = 0;
	ptr = str;
	while (ptr && *ptr)
	{
		if (*ptr != '#' && *ptr != '.')
			return (0);
		if (*ptr == '#')
			nb_sharp++;
		ptr++;
	}
	return (nb_sharp == 4 ? 1 : 0);
}

int		check_error_pieces(int fd)
{
	int		i;
	int		nb_tetri;
	int		ret;
	t_bool 	end;
	t_lst_f	*first;
	t_lst_f	*lst;
	int		id;

	end = false;
	first = NULL;
	nb_tetri = 0;
	while (!end)
	{
		i = 0;
		if (!create_lst(&first, &lst))
			return (free_list(&first));
		while (i < 4)
		{
			if (!(ret = read_line(fd, &lst->str, 5)))
				return (free_list(&first));
			i++;
		}
		nb_tetri++;
		if (!ft_check_line(lst->str) || !(ret = read_line(fd, NULL, 1)) || !(lst->id = pieces_identification(lst->str)))
			return (free_list(&first));
		//ft_putnbr(lst->id);
		//ft_putchar('\n');
		if (ret == 2)
			end = true;
	}
	free_list(&first);
	return (1);
}
