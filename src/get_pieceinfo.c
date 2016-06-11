/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieceinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:26:14 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/11 16:37:29 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_piece(char const *big, char const *little)
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

int get_pieceinfo(char *line, t_data *data)
{	
	if (find_piece(line, "Piece ") > 0)
	{
		data->piece.height = 0;
		data->piece.width = 0;
		while (*line)
		{
			if (*line >= '0' && *line <= '9')
			{
				if (data->piece.height == 0)
					data->piece.height = ft_atoi(line);
				else
					data->piece.width = ft_atoi(line);
				line++;
			}
			line++;
		}
		return (1);
	}
	return (0);
}
