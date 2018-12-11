/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:46:04 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/11 13:14:05 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int	g_tab_size;

char    **create_tab(int x, int y)
{
    int    row;
    int    column;
    char **tab;
    
    if (!(tab =(char **)malloc(sizeof(char *) * (y + 1))))
      return (0);
    row = 0;
    column = 0;
    while(row < y + 1)
    {
      if (!(tab[row] = (char *)malloc(sizeof(char) * x + 1)))
          return (0);
    while(column < x + 1)
    {
        if (column == x || (row == y))
          tab[row][column] = '-';
        else 
          tab[row][column] = '0';
        column++;
    }
    column = 0;
    row++;
    }
    return (tab);
}

int		check_place(int x, int y, char **tab, char c)
{
	printf("####### CHECK PLACE #########\n");
	if (tab[y][x] == '0')
	{
		tab[y][x] = c;
		return (1);
	}
	return (0);
}

void    clear_tab(char **tab, int y)
{
    int i;
    
    i = 0;
    while (i < y + 1)
    {
		printf("####### CLEAR TAB #########\n");
        free(tab[i]);
        i++;
    }
    free(tab);
    return ;
}
/* Fonction pour remplir le tableau avec une piece, 
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
int		clean_piece(char **tab, int x, int y, t_lst_f *lst)
{
	int i;
	int tab_y;

	printf("####### CLEAN PIECE #########\n");
	i = 0;
	tab_y = y;
	while (lst->str[i])
	{
		if (i > 0 && (lst->str[i - 1]) >= lst->str[i])
			tab_y++;
		if (tab[tab_y][x + lst->str[i] - '0'] != lst->num) // 
			break;
		tab[tab_y][x + lst->str[i] - '0'] = '0';
		i++;
	}
	return (0);
}

int  insert_in_tab(char **tab, int x, int y, t_lst_f *lst)
{
	int i;
	int tab_y;

	printf("####### INSERT TAB #########\n");
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
	return (1);
}

int	fillit(t_lst_f *first, int nb_tetri)
{
	char **tab;
	
	tab = create_tab(8, 8);
	insert_in_tab(tab, 0, 4, first);
	insert_in_tab(tab, 0, 3, first->next);
	print_tab(tab);
	//clear_tab(tab, nb_tetri);
	//	return (0);
	return (1);
}
