/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:20:30 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/11 12:51:22 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define P1		O
# define P2		X

typedef struct	s_player
{
	char		pl_sign;
	int			pl_num;
	int			x;
	int			y;	
}				t_player;

typedef struct	s_battle_field
{
	int			width;
	int			len;
	void		**bf_content;
}				t_bfield;

typedef struct	s_data
{
	t_bfield	bfield;
	t_player	pl_one;
	t_player	pl_two;	
}				t_data;

int				get_next_line(const int fd, char **line);
void			load_data(int from, int to);
int 			get_player(char *line, t_data *data);

#endif
