/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:06:23 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:49 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

int		create_lst(t_lst_f **first, t_lst_f **lst)
{
	if (*first)
	{
		if (!((*lst)->next = (t_lst_f*)malloc(sizeof(t_lst_f))))
			return (0);
		((*lst)->next)->prev = *lst;
		(*lst) = (*lst)->next;
	}
	else
	{
		if (!(*lst = (t_lst_f*)malloc(sizeof(t_lst_f))))
			return (0);
		(*lst)->prev = NULL;
		*first = *lst;
	}
	(*lst)->str = NULL;
	(*lst)->next = NULL;
	(*lst)->x = 0;
	(*lst)->y = 0;
	(*lst)->twin = NULL;
	if (!((*lst)->str = ft_strnew(0)))
		return (0);
	return (1);
}

int		free_list(t_lst_f **first)
{
	t_lst_f *tmp;

	while (first && *first)
	{
		tmp = (*first)->next;
		if ((*first)->str)
			free((*first)->str);
		free(*first);
		*first = tmp;
	}
	return (0);
}
