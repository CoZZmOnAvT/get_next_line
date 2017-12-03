/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:58:11 by pgritsen          #+#    #+#             */
/*   Updated: 2017/12/03 16:31:54 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		advanced(char *f1, char *f2, char *f3)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		tmp;
	char	*line;

	if ((fd1 = open(f1, O_RDONLY)) == -1)
		return (-1);
	if ((fd2 = open(f2, O_RDONLY)) == -1)
		return (-1);
	if ((fd3 = open(f3, O_RDONLY)) == -1)
		return (-1);
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
	return (0);
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

int		custom(void)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
		printf("%s\n", line);
	return (0);
}

void	error_handling(void)
{
	char	*line;

	printf("ERROR HANDLING:\n");
	printf("DESC - |%d|, FUNC RES - |%d|, STRING - |%s|\n", -4,
		get_next_line(-4, &line), line);
	printf("DESC - |%d|, FUNC RES - |%d|, STRING - |%s|\n", 14,
		get_next_line(14, &line), line);
}

/*
**	Pass 1 parameter to program to test basic functions of get_next_lien,
**	Or 3 - to make advanced test.
**	Zero params will cause infinite standart input test
*/

int		main(int ac, char **av)
{
	if (ac == 1)
		return (custom());
	if (ac == 2)
		basic(av[1]);
	else if (ac == 4)
		return (advanced(av[1], av[2], av[3]));
	printf("\n\n");
	error_handling();
	return (0);
}
