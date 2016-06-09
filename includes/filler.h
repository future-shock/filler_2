/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:20:30 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/09 17:46:28 by arnovan-         ###   ########.fr       */
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

typedef struct	s_data
{
	char		pl_sign;
	int			pl_num;


	int			x;
	int			y;		
	
	int			width;
	int			len;
	void		**data;
	
}				t_data;

int				get_next_line(const int fd, char **line);
void			load_data(int from, int to);
int 			get_player(char *line);

#endif
