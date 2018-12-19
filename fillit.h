/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/19 13:27:18 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "libft/libft.h"

typedef struct	s_fillit
{
	char			*str;
	struct s_fillit	*next;
	struct s_fillit	*prev;
	char			num;
	int				x;
	int				y;
	struct s_fillit	*twin;
}				t_lst_f;

int				check_entry(int fd, t_lst_f **first, int *nb_tetri);
int				check_piece(char *str);
int				create_lst(t_lst_f **lst, t_lst_f**first);
int				free_list(t_lst_f **first);
int				pieces_identification(char *str);
char			*make_id(char **str, int jump);
int				trim(char *str);
int				read_line(int fd, char **str, int n);
int				compare_id(char *str);
int				verif_id(char *id);
void			print_tab(char **tab, int tab_size);
char			**create_tab(int tab_size);
int				fillit(t_lst_f *lst, char **tab, int tab_size);
void			clear_tab(char **tab, int tab_size);
int				increase_position(t_lst_f *lst, int tab_size);
int				insert_in_tab(char **tab, t_lst_f *lst, int tab_size);
int				clean_piece(char **tab, t_lst_f *lst, int tab_size);
t_lst_f			*have_identical(t_lst_f **lst);
int				initial_map_size(int nb);

#endif
