/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_identification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:19 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/08 15:13:38 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int        pieces_identification(char *str)
{
    int k;
    int id;
	int i;
	int id_array[19] = {444, 111, 131, 113, 311, 413, 314, 411, 112, 114, 211,
		144, 431, 134, 441,141, 313, 121, 414}; 

    k = 0;
    id = 0;
    while (*str != '#')
        str++;
    while (*str)
    {
        if (*str == '#')
        {
            id = id * 10 + k;
            k = 0;
        }
		else if (*str == '\n')
			id = id * 10 + 5;
        k++;
        str++;
    }
	i = 0;
	while (id_array[i])
	{
		if (id == id_array[i])
			return (id);
		i++;
	}
    return (0);
}
