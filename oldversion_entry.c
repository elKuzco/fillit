/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldversion_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:27:22 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/07 17:23:09 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;
	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
		free(s1);
		return (tmp);
}
/*
char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*str;
	size_t		size;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(s1) && (s2))
		return (ft_strdup(s2));
	if (!(s2) && (s1))
		return (ft_strdup(s1));
	if (!(s1) && !(s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
	}
	*str = '\0';
	free(s1);
	free(s2);
	return (str - size);
}*/
ssize_t		read_line(int fd, char **str, int n)
{
	char	buff[n];
	ssize_t	ret;
	char	*tmp;

	ret = read(fd, buff, n);
	buff[ret] = '\0';
	if (!ret)
		return (2);
	if ((ret != 5 && ret != 1) || (ret && buff[n - 1] != '\n') ||
	(n == 5 && (ft_strlen(buff) != 5 || (!(tmp = ft_strndup(buff, n - 1))
	|| !(*str = ft_strjoinfree(*str, tmp))))))
		return (0);
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
	int		ret;
	t_bool	end;
	t_lst_f	*first;
	t_lst_f	*lst;

	end = false;
	first = NULL;
	while (!end)
	{
		i = -1;
		if (!create_lst(&first, &lst))
			return (free_list(&first));
		while (i++ < 4)
			if (!(ret = read_line(fd, &lst->str, 5)))
				return (free_list(&first));
		if (!ft_check_line(lst->str) || !(ret = read_line(fd, NULL, 1)))
			return (free_list(&first));
		if (ret == 2)
			end = true;
	}
	free_list(&first);
	return (1);
}
