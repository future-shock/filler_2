/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 14:54:28 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/11 16:25:45 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_plateau(char const *big, char const *little)
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
		i++;
	}
	return (-1);

}

int get_mapinfo(char *line, t_data *data)
{	
	if (find_plateau(line, "Plateau ") > 0)
	{
		data->bfield.height = 0;
		data->bfield.width = 0;
		while (*line)
		{
			if (*line >= '0' && *line <= '9')
			{
				if (data->bfield.height == 0)
					data->bfield.height = ft_atoi(line);
				else
					data->bfield.width = ft_atoi(line);
				line++;
			}
			line++;
		}
	}
	return (0);
}
