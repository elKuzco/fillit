/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:06:23 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/07 15:13:37 by qlouisia         ###   ########.fr       */
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
		if (!(*lst = (t_lst_f*)malloc(sizeof(t_lst_f))))
			return(0);
		(*lst)->str = NULL;
		(*lst)->next = NULL;
		if (!((*lst)->str = ft_strnew(0)))
			return (0);
		*first = *lst;
	}
	else
	{
		if (!((*lst)->next = (t_lst_f*)malloc(sizeof(t_lst_f))))
			return (0);
		*lst = (*lst)->next;
		(*lst)->str = NULL;
		(*lst)->next = NULL;
		if (!((*lst)->str = ft_strnew(0)))
			return(0);
	}
	return (1);
}

int	free_list(t_lst_f **first) 
{
	t_lst_f *tmp;
	
	while(first && *first)
	{
		tmp = (*first)->next;
		if ((*first)->str)
			free((*first)->str);
		if (*first)
			free(*first);
		*first = tmp;
	}
	return (0);
}
