#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

char    **create_tab(int g_tab_size)
{
    int 		row;
    int			column;
    char		**tab;

    if (!(tab =(char**)malloc(sizeof(char*) * (g_tab_size))))
      return (0);
    row = 0;
    column = 0;
    while (row < g_tab_size)
    {
		if (!(tab[row] = (char*)malloc(sizeof(char) * g_tab_size)))
		{
			while (--row)
				free(tab[row]);
			free(tab);
			return (0);
		}
	    while (column < g_tab_size)
	    {
	        tab[row][column] = '.';
	        column++;
	    }
	    column = 0;
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

void    clear_tab(char **tab, int g_tab_size)
{
	int y;
	y = 0;
	while (y < g_tab_size)
	{
		if (tab[y])
			free(tab[y]);
		y++;
	}
	if (tab)
		free(tab);
}

int		clean_piece(char **tab, t_lst_f *lst, int g_tab_size)
{
	int i;
	int tab_y;

	i = 0;
	tab_y = 0;
	while (lst->str[i])
	{
		if (i > 0 && lst->str[i - 1] >= lst->str[i])
			tab_y++;
		if (lst->x + lst->str[i] - '0' >= g_tab_size
		|| lst->y + tab_y >= g_tab_size
		|| tab[lst->x + lst->str[i] - '0'][lst->y + tab_y] != lst->num)
			return (0);
		tab[lst->x + lst->str[i] - '0'][lst->y + tab_y] = '.';
		i++;
	}
	return (0);
}

int  insert_in_tab(char **tab, t_lst_f *lst, int g_tab_size)
{
	int	i;
	int	tab_y;

	i = 0;
	tab_y = 0;
	while (lst->str[i])
	{
		if (i > 0 && lst->str[i - 1] >= lst->str[i])
			tab_y++;
		if (lst->x + lst->str[i] - '0' >= g_tab_size
		|| lst->y + tab_y >= g_tab_size
		|| !check_place(lst->x + lst->str[i] - '0', lst->y + tab_y, tab, lst->num))
			return (clean_piece(tab, lst, g_tab_size));
		i++;
	}
	return (1);
}
/*
int fillit (t_lst_f *lst, char **tab, int g_tab_size)
{
	if (!tab)
		if(!(tab = create_tab(g_tab_size)))
			return (0);
	if (!lst)
	{
		print_tab(tab, g_tab_size);
		clear_tab(tab, g_tab_size);
		return true;
	}
	while(lst->x < g_tab_size && lst->y < g_tab_size)
	{
		if (insert_in_tab(tab, lst, g_tab_size))
			return(fillit(lst->next, tab, g_tab_size));
		if (lst->x < g_tab_size - 1)
			lst->x += 1;
		else if (lst->y < g_tab_size - 1)
		{
			lst->x = 0;
			lst->y++;
		}
	}
	if(lst->prev == NULL)
	{
		g_tab_size++;
		return(fillit(lst, tab, g_tab_size));
		
	}
	return(false);
}
*/

int	fillit(t_lst_f *lst, char **tab, int g_tab_size)
{
	t_bool	placeable;

	if (!tab)
		if(!(tab = create_tab(g_tab_size)))
			return (0);
	placeable = true;
	while (lst && placeable == true)
	{
		while (placeable == true && !insert_in_tab(tab, lst, g_tab_size))
		{
			if (lst->x < g_tab_size - 1)
				lst->x += 1;
			else if (lst->y < g_tab_size - 1)
			{
				lst->x = 0;
				lst->y++;
			}
			else
				placeable = false;
		}
		if (placeable == false)
		{
			lst->x = 0;
			lst->y = 0;
			if (lst->prev)
			{
				lst = lst->prev;
				clean_piece(tab, lst, g_tab_size);
				if (lst->x < g_tab_size - 1)
					lst->x++;
				else if (lst->y < g_tab_size - 1)
				{
						lst->x = 0;
						lst->y++;
				}
				placeable = true;
			}
			else
			{
				if (tab)
					clear_tab(tab, g_tab_size);
				g_tab_size++;
				if (!(tab = create_tab(g_tab_size)))
					return(0);
				fillit(lst, tab, g_tab_size);
			}
		}
		else if (placeable == true)
			lst = lst->next;
	}
	if (placeable == true && tab)
	{
		print_tab(tab, g_tab_size);
		clear_tab(tab, g_tab_size);
	}
	return (1);
}