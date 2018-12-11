/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:46:59 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/11 20:20:34 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

extern size_t g_tab_size;

void	print_tab(char **tab)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < g_tab_size)
	{
		while (x < g_tab_size)
		{
			ft_putchar(tab[x][y]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}