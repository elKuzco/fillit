/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:27:22 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/09 17:40:21 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

ssize_t		read_line(int fd, char **str, int n)
{
	char	buff[n + 1];
	ssize_t	ret;
	char	*tmp;
	char	*tmp2;

	ret = read(fd, buff, n);
	buff[ret] = '\0';
	if (n == 5 && ret == 5)
	{
		tmp = *str;
		if (!(tmp2 = ft_strndup(buff, n)))
			return (0);
		if (ft_strlen(buff) != 5 || !(*str = ft_strjoin(*str, tmp2)))
		{
			free(tmp);
			free(tmp2);
			return (0);
		}
		free(tmp);
		free(tmp2);
	}
	if (!ret)
		return (2);
	return ((ret != 5 && ret != 1) || buff[n - 1] != '\n' ? 0 : 1);
}

int			ft_check_line(char *str)
{
	if (ft_strnb_c(str, '#') != 4)
		return (0);
	while (str && *str)
	{
		if (!ft_strn_is(str, "#.", 4) || str[4] != '\n')
			return (0);
		str += 5;
	}
	return (1);
}

int			check_error_pieces(int fd, t_lst_f **first, int *nb_tetri)
{
	int		i;
	int		ret;
	t_bool	end;
	t_lst_f	*lst;

	end = false;
	while (!end)
	{
		if (!create_lst(first, &lst))
			return (free_list(first));
		i = -1;
		while (++i < 4)
			if (!(ret = read_line(fd, &lst->str, 5)))
				return (free_list(first));
		if (!ft_check_line(lst->str) || !(ret = read_line(fd, NULL, 1))
		|| !(make_id(&lst->str, trim(lst->str))))
			return (free_list(first));
		lst->num = *nb_tetri++;
		if (ret == 2)
			end = true;
	}
	return (1);
}
