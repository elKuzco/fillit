/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:36:28 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 18:51:13 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

int		increase_position(t_lst_f *lst, int tab_size)
{
	if (lst->x < tab_size - 1)
	{
		lst->x++;
		return (1);
	}
	else if (lst->y < tab_size - 1)
	{
		lst->x = 0;
		lst->y++;
		return (1);
	}
	return (0);
}

int		increase_map(char ****tab, int *tab_size)
{
	if (tab)
		clear_tab(**tab, *tab_size);
	(*tab_size)++;
	if (!(**tab = create_tab(*tab_size)))
		return (0);
	return (1);
}

int		backtracking(char ***tab, int *tab_size, t_lst_f **lst)
{
	(*lst)->x = 0;
	(*lst)->y = 0;
	if ((*lst)->prev)
	{
		*lst = (*lst)->prev;
		clean_piece(*tab, *lst, *tab_size);
		increase_position(*lst, *tab_size);
		return (1);
	}
	else
	{
		if (!increase_map(&tab, tab_size))
			return (0);
	}
	return (1);
}

void	get_identical(t_lst_f **lst)
{
	(*lst)->x = ((*lst)->twin)->x;
	(*lst)->y = ((*lst)->twin)->y;
}

int		fillit(t_lst_f *lst, char **tab, int tab_size)
{
	t_bool	placeable;

	if (!tab)
		if (!(tab = create_tab(tab_size)))
			return (0);
	while (lst)
	{
		placeable = true;
		if (lst->twin && lst->x == 0 && lst->y == 0)
			get_identical(&lst);
		while (placeable == true && !insert_in_tab(tab, lst, tab_size))
			if (!increase_position(lst, tab_size))
				placeable = false;
		if (placeable == false)
		{
			if (!backtracking(&tab, &tab_size, &lst))
				return (0);
		}
		else
			lst = lst->next;
	}
	print_tab(tab, tab_size);
	clear_tab(tab, tab_size);
	return (1);
}
