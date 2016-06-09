/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:20:08 by simzam            #+#    #+#             */
/*   Updated: 2016/06/09 18:18:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_stream(int from, int to)
{
	char			*line;
	int				i;
	static int		player_true;
	
	line = NULL;
	i = 0;
	while (get_next_line(from, &line) == 1 && *line != '<')
	{
		i++;
		if (!player_true)
		{
			player_true = get_player(line);
		}
		write(to, line, ft_strlen(line));
		write(to, "\n", 1);
	}
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
