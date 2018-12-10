/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/10 12:05:13 by qlouisia         ###   ########.fr       */
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

}				t_lst_f;

int				check_error_pieces(int fd, t_lst_f **first, int *nb_tetri);
int				ft_check_line(char *str);
int				create_lst(t_lst_f **lst, t_lst_f**first);
int				free_list(t_lst_f **first);
int				pieces_identification(char *str);
int				make_id(char **str, int jump);
int				trim(char *str);
ssize_t			read_line(int fd, char **str, int n);
int				compare_id(char *str);

#endif
