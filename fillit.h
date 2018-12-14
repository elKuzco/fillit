/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/14 18:08:21 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
typedef struct	s_fillit
{
	char			*str;
	struct s_fillit	*next;
	struct s_fillit	*prev;
	char			num;
	int			x;
	int			y;

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
void			print_tab(char **tab, int g_tab_size);
char    		**create_tab(int g_tab_size);
int				fillit(t_lst_f *lst, char **tab, int g_tab_size);
void    		clear_tab(char **tab, int g_tab_size);

#endif
