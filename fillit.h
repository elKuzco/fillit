/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/06 16:23:25 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT__H
# define FILLIT__H

typedef struct	s_fillit
{
	char			*str;
	struct s_fillit	*next;

}				t_lst_f;

int check_error_pieces(int fd);
int ft_check_line(char *line, int *sharp);
int	create_lst(t_lst_f **lst, t_lst_f**first);
int free_list(t_lst_f **first, char **line);

#endif
