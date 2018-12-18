/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_identification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:19 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 18:45:55 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include "fillit.h"

int		trim(char *str)
{
	int		current;
	int		jump;
	t_bool	sharp;
	char	*tmp;

	sharp = false;
	jump = 4;
	current = 0;
	tmp = ft_strrchr(str, '#');
	while (str != tmp)
	{
		if (*str != '\n' && *str != '#' && !sharp)
			current++;
		else if (*str == '#')
			sharp = true;
		else if (*str == '\n')
		{
			if (current < jump)
				jump = current;
			current = 0;
			sharp = false;
		}
		str++;
	}
	return (current < jump ? jump = current : jump);
}

t_lst_f	*have_identical(t_lst_f **lst)
{
	t_lst_f	*tmp;

	tmp = *lst;
	if (tmp->prev)
	{
		tmp = tmp->prev;
		while (tmp)
		{
			if (!(ft_strcmp((*lst)->str, tmp->str)))
				return (tmp);
			tmp = tmp->prev;
		}
	}
	return (NULL);
}

char	*make_id(char **str, int jump)
{
	char	*tmp;
	char	*id;
	int		i;
	int		j;

	tmp = *str;
	if (!(id = (char*)malloc(sizeof(char) * 4)))
		return (NULL);
	j = 0;
	i = 0;
	*str += jump;
	while (j < 4)
	{
		if (**str == '#')
			id[j++] = i + '0';
		i++;
		if (**str == '\n')
		{
			i = 0;
			*str += jump;
		}
		(*str)++;
	}
	free(tmp);
	return (id);
}

int		verif_id(char *id)
{
	int i;

	i = 1;
	while (i < 4)
	{
		if (id[i] - 1 > id[i - 1])
			return (0);
		i++;
	}
	return (1);
}
