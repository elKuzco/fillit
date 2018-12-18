/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:39:51 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 18:50:58 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

char	**create_tab(int tab_size)
{
	int			row;
	int			column;
	char		**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (tab_size))))
		return (0);
	row = 0;
	column = -1;
	while (row < tab_size)
	{
		if (!(tab[row] = (char*)malloc(sizeof(char) * tab_size)))
		{
			while (--row)
				free(tab[row]);
			free(tab);
			return (0);
		}
		while (column++ < tab_size)
			tab[row][column] = '.';
		column = -1;
		row++;
	}
	return (tab);
}

int		check_place(int x, int y, char **tab, char c)
{
	if (tab[x][y] == '.')
	{
		tab[x][y] = c;
		return (1);
	}
	return (0);
}

void	clear_tab(char **tab, int tab_size)
{
	int y;

	y = 0;
	while (y < tab_size)
	{
		if (tab[y])
			free(tab[y]);
		y++;
	}
	if (tab)
		free(tab);
}

int		clean_piece(char **tab, t_lst_f *lst, int tab_size)
{
	int i;
	int tab_y;

	i = 0;
	tab_y = 0;
	while (i < 4)
	{
		if (i > 0 && lst->str[i - 1] >= lst->str[i])
			tab_y++;
		if (lst->x + lst->str[i] - '0' >= tab_size
		|| lst->y + tab_y >= tab_size
		|| tab[lst->x + lst->str[i] - '0'][lst->y + tab_y] != lst->num)
			return (0);
		tab[lst->x + lst->str[i] - '0'][lst->y + tab_y] = '.';
		i++;
	}
	return (0);
}

int		insert_in_tab(char **tab, t_lst_f *lst, int tab_size)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < 4)
	{
		if (i > 0 && lst->str[i - 1] >= lst->str[i])
			y++;
		if (lst->x + lst->str[i] - '0' >= tab_size
		|| lst->y + y >= tab_size
		|| !check_place(lst->x + lst->str[i] - '0', lst->y + y, tab, lst->num))
			return (clean_piece(tab, lst, tab_size));
		i++;
	}
	return (1);
}
