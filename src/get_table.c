/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:18:09 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/07 10:20:09 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_table	get_table(int fd, int *len, int *width)
{
	char	*str;
	t_grid  ret;
	int 	fd;

	str = (char *)malloc(sizeof(char) * 10000000);
	printf("moose\nbollocks\n");
	read(0, (void *)str, 10000000);
	fd = open("debug.log", O_WRONLY, O_APPEND);	
	get_next_line(0, &str);
	write(fd, str, strlen(str));	
	close(fd);	
	printf("str: %s\n", str);
	return (ret);
}
