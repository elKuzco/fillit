/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:06:23 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/06 17:01:49 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

int		create_lst(t_lst_f **first, t_lst_f **lst)
{
	if (!*first)
	{
		if (!(*lst = (t_lst_f*)malloc(sizeof(t_lst_f))) || !((*lst)->str = ft_strnew(0)))
			return(0);
		*first = *lst;
	}
	else
		if (!((*lst)->next = (t_lst_f*)malloc(sizeof(t_lst_f))) || !(((*lst)->next)->str = ft_strnew(0)))
			return(0);
	(*lst)->next = NULL;
	return (1);
}

int	free_list(t_lst_f **first, char **line) 
{
	t_lst_f *tmp;
	
	if (*line)
		free(*line);
	while(*first)
	{
		tmp = (*first)->next;
		free((*first)->str);
		free(*first);
		*first = tmp;
	}
	return (0);
}
