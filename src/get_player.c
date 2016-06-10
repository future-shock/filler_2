/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 12:21:31 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/09 18:18:46 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
	
static int	find_player(char const *big, char const *little)
{
	int	i;
	int	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
				return (1);
			i++;
			j++;
		}
		i = i - j; //This might just be redudant.
		i++;
	}
	return (-1);
}
	
int get_player(char *line, t_data *data)
{
	if (find_player(line, "p1") > 0)
	{
		data->pl_one.pl_num = 1;
		data->pl_one.pl_sign = 'O';
		return (1);
	}
	if (find_player(line, "p2") > 0)
	{
		data->pl_two.pl_num = 2;
		data->pl_two.pl_sign = 'X';
		return (1);
	}
	return (0);
}
