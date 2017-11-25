/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:58:11 by pgritsen          #+#    #+#             */
/*   Updated: 2017/11/25 13:14:28 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	advanced(char *f1, char *f2, char *f3)
{
	int		fd1, fd2, fd3;
	int		tmp;
	char	*line;

	if ((fd1 = open(f1, O_RDONLY)) == -1)
		return ;
	if ((fd2 = open(f2, O_RDONLY)) == -1)
		return ;
	if ((fd3 = open(f3, O_RDONLY)) == -1)
		return ;

	tmp = get_next_line(fd1, &line);
	printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
	tmp = get_next_line(fd2, &line);
	printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
	tmp = get_next_line(fd1, &line);
	printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
	tmp = get_next_line(fd3, &line);
	printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
	while (get_next_line(fd1, &line) > 0)
		printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
}

void	basic(char *filename)
{
	int		fd;
	int		tmp;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return ;
	while ((tmp = get_next_line(fd, &line)) > 0)
		printf("FUNC RES - |%d|, STRING - |%s|\n", tmp, line);
}

void	custom()
{
	char	*line;

	while (get_next_line(0, &line) > 0)
		printf("%s\n", line);
}

/*
**	Pass 1 parameter to program to test basic functions of get_next_lien,
**	Or 3 - to make advanced test.
**	Zero params will cause infinite standart input test
*/

int		main(int ac, char **av)
{
	if (ac == 1)
		custom();
	else if (ac == 2)
		basic(av[1]);
	else if (ac == 4)
		advanced(av[1], av[2], av[3]);
	return (0);
}
