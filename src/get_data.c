/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 12:26:29 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/11 16:32:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_bf_content(t_data *data, char *line)
{
	static int		i;
	static int		j;


	while (*(line + 3 + i) != '\0')
	{
		j = 0;
		while (*(line + 3 + j) != '\n')
		{
			(*(char **)data->bfield.bf_content)[j] = *(line + 3 + j);
			j++;
		}
		i++;
	}
	return (0);
}

static int		start_of_bf_content(char *s)
{
	return (ft_isdigit(*s) && ft_isdigit(*(s + 1) && ft_isdigit(*(s + 2))));
}



static int		get_stream(int from, int to)
{
	char			*line;
	int				i;
	static int		player_true;
	static int		mapinfo_true;
	static int		pieceinfo_true;
	t_data			data;
	
	line = NULL;
	i = 0;
	while (get_next_line(from, &line) == 1 && *line != '<')
	{
		i++;
		if (!player_true)
			player_true = get_player(line, &data);
		if (!mapinfo_true)
			mapinfo_true = get_mapinfo(line, &data);;
		if (!pieceinfo_true)
			pieceinfo_true = get_pieceinfo(line, &data);

		if (start_of_bf_content(line))
		{	
			get_bf_content(&data, line);
			printf("This is the content: %s", *((char **)data.bfield.bf_content));
		}
		write(to, line, ft_strlen(line));
		write(to, "\n", 1);
	}
	data.bfield.width = i + 1; 
	return (0);
}

void	load_data(int from, int to)
{
	to = open("debug.log", O_WRONLY | O_CREAT | O_APPEND, 0666);
	get_stream(from, to);
	
}

int		main(void) 
{
	static int		to;
	static int		from;

	load_data(from, to);
	close(from);
	return 0;
}
