/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 12:26:29 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/11 18:47:15 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_bf_content(t_data *data, char *line)
{
	static int		i;

	if (data->bfield.bf_content == NULL)
		data->bfield.bf_content = (char **)malloc(sizeof(char *) 
				* data->bfield.height + 1);
	while (((*line >= '0') && (*line <= '9')) || (*line == ' '))
		line++;
		//Capture player chars here.
		data->bfield.bf_content[i] = ft_strdup(line);
		line = line + ft_strlen(line - 4);
		printf("string: %s\n", data->bfield.bf_content[i]);
	i++;

	//printf("string: %s\n", data->bfield.bf_content[i]);
	return (0);
}

static int		start_of_bf_content(char *s)
{
	if (ft_isdigit(*s) && ft_isdigit(*(s + 1)) && ft_isdigit(*(s + 2)) 
				&& (*(s + 3) == ' '))
	{
		return (1);
	}
	else
		return (0);
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
	i = -1;
	while (get_next_line(from, &line) == 1 && *line != '<')
	{
		i++;
		if (!player_true)
			player_true = get_player(line, &data);
		if (!mapinfo_true)
			mapinfo_true = get_mapinfo(line, &data);
		if (!pieceinfo_true)
			pieceinfo_true = get_pieceinfo(line, &data);
		if (start_of_bf_content(line))
		{	
			get_bf_content(&data, line);
			printf("This is the content: %s\n", data.bfield.bf_content[i]);
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
