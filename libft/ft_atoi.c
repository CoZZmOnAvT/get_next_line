/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:22:28 by pgritsen          #+#    #+#             */
/*   Updated: 2017/11/27 14:50:05 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	long	result;
	int		sign;
	int		it;

	if (*s == 0)
		return (0);
	while (((*s > '\10' && *s <= '\16') || *s == '\40'))
		s++;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	result = 0;
	it = 0;
	while (*s >= '0' && *s <= '9')
		if ((result = (result * 10) + (*s++ - '0')) != 0)
			it++;
		else if ((((it > 19 || result < 0) || (it && !result)) && sign != -1))
			return (-1);
		else if ((((it > 19 || result < 0) || (it && !result)) && sign == -1))
			return (0);
	return ((int)(result *= sign));
}
