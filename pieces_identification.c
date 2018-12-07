/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_identification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:19 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/07 17:16:50 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*pieces_identification(char *str, int *tab)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '#')
		i++;
	while (str[i])
	{
		if (str[i] == '#')
		{
			tab[j] = k;
			j++;
			k = 0;
		}
		k++;
		i++;
	}
	return (tab);
}
