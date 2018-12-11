/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:46:04 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/11 21:14:09 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft/libft.h"

extern size_t g_tab_size;

char    **create_tab(void)
{
    size_t    row;
    size_t    column;
    char **tab;
    
    if (!(tab =(char **)malloc(sizeof(char *) * (g_tab_size))))
      return (0);
    row = 0;
    column = 0;
    while(row < g_tab_size)
    {
	      if (!(tab[row] = (char *)malloc(sizeof(char) * g_tab_size)))
	          return (0);
	    while(column < g_tab_size)
	    {
	        tab[row][column] = '.';
	        column++;
			
	    }
	    column = 0;
	    row++;
    }
    return (tab);
}
int		check_place(size_t x, size_t y, char **tab, char c)
{
	printf("x : %zu  | y : %zu |tab = %zu \n", x, y, 	g_tab_size);
	if (x < g_tab_size && y < g_tab_size && tab[x][y] == '.')
	{
		printf("on pose le #\n");
		tab[x][y] = c;
		return (1);
	}
	return (0);
}

void    clear_tab(char **tab)
{
    /*size_t y;
	    y = 0;
	    while (y < g_tab_size)
	    {
			//if (tab[y])
	        	//free(tab[y]);
	        y++;
	    }
	    if (tab)
			free(tab);*/
}

int		clean_piece(char **tab, size_t x, size_t y, t_lst_f *lst)
{
	int i;
	size_t tab_y;
	i = 0;
	tab_y = y;
	while (lst->str[i])
	{
		if (i > 0 && (lst->str[i - 1]) >= lst->str[i])
			tab_y++;
		if ((x + lst->str[i] - '0') >= g_tab_size || tab_y >= g_tab_size
		|| tab[x + lst->str[i] - '0'][tab_y] != lst->num) // 
			break;
		tab[x + lst->str[i] - '0'][tab_y] = '.';
		i++;
	}
	return (0);
}

int  insert_in_tab(char **tab, size_t x, size_t y, t_lst_f *lst)
{
	int i;
	size_t	tab_y;

	i = 0;
	tab_y = y;
	while (lst->str[i])
	{
		if (i > 0 && lst->str[i - 1] >= lst->str[i])
			tab_y++;
		if (!check_place((x + lst->str[i] - '0'), tab_y, tab, lst->num))
			return (clean_piece(tab, x, y, lst));
		i++;
	}
	lst->x = x;
	lst->y = y;
	return (1);
}

int	fillit(t_lst_f *lst, char **tab)
{
	t_bool	placeable;

	if (!tab)
		if(!(tab = create_tab()))
			return (0);
	while (lst)
	{
		placeable = true;// Placeable toujours vrai dans la condition
		while (placeable == true && !insert_in_tab(tab, lst->x, lst->y, lst))
		{
			if (g_tab_size > 6)
				printf(" #BEFORE#\n tab %zu:| x :%zu | y :%zu | lst = %c \n", g_tab_size, lst->x, lst->y, lst->num);
			if (lst->x < g_tab_size - 1)
				lst->x++;
			else if (lst->y < g_tab_size - 1)
			{
				lst->y++;
				lst->x = 0;
			}
			else
			{
				placeable = false;
				if (g_tab_size > 6)
					printf(" #star#\ntab %zu:| x : %zu | y :%zu | lst = %c \n", g_tab_size, lst->x, lst->y, lst->num);
			}
		}
		if (placeable == false)
		{		
			lst->x = 0;
			lst->y = 0;
			if (lst->prev)
			{
				lst = lst->prev;
				clean_piece(tab, lst->x, lst->y, lst);
				if (lst->x < g_tab_size - 1)
					lst->x++;
				else if (lst->y++ < g_tab_size - 1)
					lst->x = 0;
			}
			else
			{
				//if (tab)
					//clear_tab(tab);
				g_tab_size++;
				if (!(tab = create_tab()))
					return(0);
			}
			fillit(lst, tab);
			lst = NULL;
		}
		else
			lst = lst->next;
	}
	if (placeable)
	{
		if (tab)
		{
			print_tab(tab);
			//clear_tab(tab);
		}
		
	}
	return (1);
}



/* 















Fonction pour remplir le tableau avec une piece, 
il reste a modifier le code pour 
- qu'elle accepte les listes chaines
- qu'elle verifie l'emplacement
- qu'elle puisse effacer ce qui a ete inscrit avant

int  insert_in_tab(char **tab, int x, int y, t_lst_f *lst)
{
  int tab_x;
  int tab_y;
  int i;
  
  i = 0;
  tab_x = 0;
  tab_y = 0;
  while (lst->str[i])
  {
    if (i < 1)
    {
      tab_x = lst->str[i] - '0';
      if (!check_place(x + tab_x, y, tab, lst->num))
	  	return (clean_piece(tab, x, y, lst));
      tab[y][x + tab_x] = 'A';
    }
    else
    {
      if(lst->str[i] <= lst->str[i - 1])
        tab_y++;
    tab_x = lst->str[i] - '0';
    if (!check_place(x + tab_x, y + tab_y, tab, lst->num))
  		return (clean_piece(tab, x, y, lst)); 
    tab[y + tab_y][x + tab_x] = 'A';
    }
    i++;
  }
  return (1);
}
*/
