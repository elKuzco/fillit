/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:27:22 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/06 17:03:50 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

ssize_t		read_line(int fd, char **line, int n)
{
	char	buff[n];
	ssize_t	ret;

	ret = read(fd, buff, n);
	if (!ret)
		return (2);
	if ((ret != 5 && ret != 1) || (ret && buff[n - 1] != '\n')) //&& buff[n - 1] != '\0'))
		return (0);
	*line = ft_strndup(buff, n - 1);
	return (1);
}

int		ft_check_line(char *line, int *sharp)
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
	int		i;
	int		ret;
	char	*line;
	char	*tmp;
	int		nb_sharp;
	t_bool 	end;
	t_lst_f	*first;
	t_lst_f	*lst;

	end = false;
	while (!end)
	{
		first = NULL;
		nb_sharp = 0;
		i = 0;
		if (!first)
		{
			if (!create_lst(&first, &lst))
				return (free_list(&first, &line));
		}
		else	
			if (!create_lst(&first, &lst->next))
				return (free_list(&first, &line));
		while (i < 4)
		{
			if (!(ret = read_line(fd, &line, 5)) || !(ft_check_line(line, &nb_sharp)))
				return (free_list(&first, &line));
			tmp = lst->str;
			lst->str = ft_strjoin(lst->str, line);
			free(line);
			line = NULL;
			free(tmp);
			i++;
		}
		if (nb_sharp != 4 || !(ret = read_line(fd, &line, 1)))
			return (free_list(&first, &line));
		if (ret == 2)
		{
			if (line)
			{
				free(line);
				line = NULL;
			}
			end = true;
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	ft_putendl(first->str);
	ft_putendl(lst->str);
	free_list(&first, &line);
	return (1);
}
