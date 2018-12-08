/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_identification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:19 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/08 16:31:21 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int        pieces_identification(char *str)
{
    int k;
    int id;
	int i;
	int id_array[19] = {555, 111, 141, 114, 411, 514, 415, 511, 113, 115, 
		311, 155, 541, 145, 551, 151, 414, 131, 515};
		
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
    return (0); // 0
}
