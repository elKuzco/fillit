/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_identification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:19 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/09 17:35:33 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

/*int		endofpieces(char *str)
{
	int nb_sharp;
	int i;

	i = 0;
	nb_sharp = 0;
	while (nb_sharp < 4)
	{
		if (str[i] == '#')
		nb_sharp++;
		i++;
	}
	return (i);
}

char	**first_sharp(char **str)
{
	char	*ptr;

	ptr = *str;
	*str = ft_strchr(*str, '#');
	while (**str != '\n' && ptr != *str)
		(*str)--;
	if (**str == '\n')
		(*str)++;
	return (str);
}*/

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
	if (current < jump)
		jump = current;
	return (jump);
}

int		make_id(char **str, int jump)
{
	char    *tmp;
	char    *id;
	int     i;
	int     j;

	if (!(id = (char*)malloc(sizeof(char) * 5)))
		return (0);
	tmp = *str;
	j = 0;
	i = 0;
	*str += jump;
	while (**str)
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
	id[j] = '\0';
	*str = id;
	free(tmp);
	return (1);
}