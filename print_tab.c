/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:46:59 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/11 13:15:27 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	print_tab(char **tab)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (tab[j][0] != '-')
	{
		while (tab[j][i] != '-')
			{
				ft_putchar(tab[j][i]);
				i++;
			}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	
}